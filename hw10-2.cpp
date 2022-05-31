#include <iostream>
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
			low[u]=min(low[u],low[v]);                //當u的子孫可到達的深度小於u可到達的，更改low[u] 
			if(parent[u]==-1&&child>1){               //若u是DFS樹的root，且擁有兩個以上的小孩，u為關節點 
				ans[u].second++;
			}
			if(parent[u]!=-1 &&low[v]>=depth[u]){    //若u不是root，但其孩子(v)無法繞過u接觸u的祖先，u為關節點 
				ans[u].second++;
			}
		}
		//若v已經走過，代表v是u的祖先，若v不是u的parent(parent沒有更新的必要)，則表示有一條可走v到祖先的路 
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
	int *low=new int[city];      //low[u]為u與其子孫中能到達的最小深度 
	int *depth=new int[city];   //depth[u]為u在DFS樹中的深度 
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

//https://hackmd.io/n6grE8l2QnmRx2zqfPFu2g
