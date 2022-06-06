#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
#include <cstdlib> 
using namespace std;
struct road{
	int v1;
	int v2;
	int length;
};
struct site{
	int x;
	int y;
};

bool compare(const road &a,const road &b){
	return a.length<b.length;
}

int find(int* parent,int u){       
	while(parent[u]>=0){
		u=parent[u];
	}
	return u;
}

void mergeset(int* parent,int rfrom,int rto){
	if(parent[rfrom]<=parent[rto]){
		parent[rfrom]+=parent[rto];
		parent[rto]=rfrom;
	}
	else{
		parent[rto]+=parent[rfrom];
		parent[rfrom]=rto;
	}
}

void Kruskal(vector<struct road> &edge,int V){
	int from,to,selected=0;
	int rfrom,rto;
	long ans=0;
	int parent[V];
	memset(parent,-1,V*sizeof(int));
	vector<struct road> ::iterator it;
	for(it=edge.begin();it<edge.end();it++){
		from=it->v1;
		to=it->v2;
		rfrom=find(parent,from);
		rto=find(parent,to);
		if(rfrom!=rto){
			ans+=it->length;
			selected++;
			mergeset(parent,rfrom,rto);
		}
		if(selected>=V-1){
			break;
		}	
	}
	cout<<ans<<endl;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V;
	vector<struct site>vertice;
	vector<struct road> edge;
	cin>>V;
	struct site s;
	struct road r;
	int w;
	for(int i=0;i<V;i++){
		cin>>s.x>>s.y;
		vertice.push_back(s);
	}
	for(int i=0;i<V;i++){
		for(int j=i+1;j<V;j++){
			w=abs(vertice[i].x-vertice[j].x)+abs(vertice[i].y-vertice[j].y);
			r.length=w;
			r.v1=i;
			r.v2=j;
			edge.push_back(r);
		}
	}
	sort(edge.begin(),edge.end(),compare);
	Kruskal(edge,V);
}
