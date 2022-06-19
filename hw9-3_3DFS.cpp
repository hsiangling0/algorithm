#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void deleteAmount(vector<int> route[],int start,bool visit[],bool del[],int parent[]){
	visit[start]=true;
	vector<int> ::iterator it; 
	for(it=route[start].begin();it!=route[start].end();it++){
		if(!visit[*it]){
			parent[*it]=start;
			deleteAmount(route,*it,visit,del,parent);
		}       
	}
	if(!del[start]){
		del[parent[start]]=false;
	}
}

void longest(vector<int> route[],int start,bool visit[],int length[],int &L){
	visit[start]=true;
	vector<int> ::iterator it; 
	for(it=route[start].begin();it!=route[start].end();it++){
		if(!visit[*it]){
			++L;
			length[*it]=L;
			longest(route,*it,visit,length,L);
		}       
	}
	--L;
	
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int city,bomb,from,to,site;
	cin>>city>>bomb;
	vector<int> route[city+1];
	for(int i=0;i<city-1;i++){
		cin>>from>>to;
		route[from-1].push_back(to-1);
		route[to-1].push_back(from-1);
	}
	vector<int> bombSite;
	int length=city-1;
	bool* visit=new bool[city];
	bool* del=new bool[city];
	int* parent=new int[city];
	int* path=new int[city];
	for(int i=0;i<city;i++){
		visit[i]=false;
		del[i]=true;
		parent[i]=i;
		path[i]=0;
	}
	for(int i=0;i<bomb;i++){
		cin>>site;
		bombSite.push_back(site-1);
		del[site-1]=false;
	}
	if(bomb==1){
		cout<<site<<endl;
		cout<<"870000"<<endl;
		return 0;
	}
	sort(bombSite.begin(),bombSite.end());
	deleteAmount(route,bombSite[0],visit,del,parent);
	for(int i=0;i<city;i++){
		if(del[i])length--;
		visit[i]=false;
	} 
	int L=0;
	longest(route,bombSite[0],visit,path,L);
	int V,V2,max=0;
	for(int i=0;i<city;i++){
		if(!del[i] &&path[i]>max){
			max=path[i];
			V=i;
		}
		visit[i]=false;
		path[i]=0;
	}
	L=0;
	longest(route,V,visit,path,L);
	max=0;
	for(int i=0;i<city;i++){
		if(!del[i]&&path[i]>max){
			max=path[i];
			V2=i;
		}
	}
	long long ans=(long long)((2*length-max))*1000+(long long)(bombSite.size())*870000;
	if(V>V2)cout<<V2+1<<endl;
	else cout<<V+1<<endl;
	cout<<ans<<endl;
}

/*input
7 4
3 7
3 1
4 1
7 2
5 7
1 6
2 7 4 1
*/
/*output
2
3484000
*/
//https://hackmd.io/s3hqsHjsSFaNVX3jThi60Q
