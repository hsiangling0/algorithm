#include <iostream>
#include <queue>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int,int>&a,const pair<int,int> &b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second>b.second;
}

void dfs(int u,bool visit[],int depth[], int low[],int parent[], int curdepth,vector<pair<int,int>> &ans,vector<int> connect[]){
	visit[u]=true;
	int child=0;
	depth[u]=low[u]=curdepth;
	vector<int> ::iterator it;
	for(it=connect[u].begin();it!=connect[u].end();it++){
		int v=*it;
		if(!visit[v]){
			parent[v]=u;
			child++;
			dfs(v,visit,depth,low,parent,curdepth+1,ans,connect);
			low[u]=min(low[u],low[v]);                //��u���l�]�i��F���`�פp��u�i��F���A���low[u] 
			if(parent[u]==-1&&child>1){               //�Yu�ODFS��root�A�B�֦���ӥH�W���p�ġAu�����`�I 
				ans[u].second++;
			}
			if(parent[u]!=-1 &&low[v]>=depth[u]){    //�Yu���Oroot�A����Ĥl(v)�L�k¶�Lu��Ĳu�������Au�����`�I 
				ans[u].second++;
			}
		}
		//�Yv�w�g���L�A�N��v�Ou�������A�Yv���Ou��parent(parent�S����s�����n)�A�h��ܦ��@���i��v�쯪������ 
		else if(parent[u]!=v){     
			low[u]=min(low[u],depth[v]);
		}
	}
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int city,bomb,from,to;
	cin>>city>>bomb;
	cin>>from>>to;
	vector<int> connect[city];
	vector<pair<int,int>> ans; 
	bool *visit=new bool[city];
	int *parent=new int[city]; 
	int *low=new int[city];      //low[u]��u�P��l�]�����F���̤p�`�� 
	int *depth=new int[city];   //depth[u]��u�bDFS�𤤪��`�� 
	for(int i=0;i<city;i++){
		ans.push_back({i,1});
		visit[i]=false;
		parent[i]=-1;
	}
	while(from!=-1 && to!=-1){
		connect[from].push_back(to);
		connect[to].push_back(from);
		cin>>from>>to;
	}
	for(int i=0;i<city;i++){
		if(!visit[i]){
			dfs(i,visit,depth,low,parent,0,ans,connect);
		} 
	} 
	sort(ans.begin(),ans.end(),compare);
	vector<pair<int,int>> ::iterator it=ans.begin();
	for(int i=0;i<bomb;i++){
		cout<<(*it).first<<" "<<(*it).second<<endl;
		it++; 
	}
} 

/*input
8 4
0 4
1 2
2 3
2 4
3 5
3 6
3 7
6 7
-1 -1
*/

/*output
2 3
3 3
4 2
0 1
*/
