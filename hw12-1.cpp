#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void relax(int from,int to,int length,vector<int> &weight,vector<int> &pass){
	if(weight[to]>weight[from]+length){
		weight[to]=weight[from]+length;
		pass[to]=from;
	}
}

bool compare(const int &a,const int &b){
	return a>b;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int student;
	cin>>student;
	vector<pair<int,int>> time[student];
	int amount;
	for(int i=1;i<student;i++){
		for(int j=0;j<i;j++){
			cin>>amount;
			time[j].push_back({i,amount});
			time[i].push_back({j,amount});
		}
	}
	vector<int> weight;
	vector<int> pass;
	for(int i=0;i<student;i++){
		weight.push_back(INT_MAX);
		pass.push_back(-1);
	}
	weight[0]=0;
	for(int i=0;i<student-1;i++){
		for(int j=0;j<student;j++){
			vector<pair<int,int>> ::iterator it;
			for(it=time[j].begin();it!=time[j].end();it++){
				relax(j,(*it).first,(*it).second,weight,pass);
			}
		}	
	}
	sort(weight.begin(),weight.end(),compare);
	cout<<weight[0]<<endl;
}
