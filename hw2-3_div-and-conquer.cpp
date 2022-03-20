#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct point{
	int x;
	int y;
	int time;
};
bool compare(const point&a,const point&b){
	if(a.x!=b.x){
		return a.x<b.x;
	}
	else return a.y<b.y;
}
void conq(int,int,int,vector<point> &ans,vector<int> &result);
void div(int left, int right,vector<point> &ans,vector<int> &result){
	if(left<right){
		int middle=(right+left)/2;
		div(left,middle,ans,result);
		div(middle+1,right,ans,result);
		conq(left,middle,right,ans,result);
	}
}
void conq(int left,int middle,int right,vector<point> &ans,vector<int> &result){
	vector<point> front;
	vector<point> end;
	front.insert(front.begin(),ans.begin()+left,ans.begin()+middle+1);
	end.insert(end.begin(),ans.begin()+middle+1,ans.begin()+right+1);
	vector<point> ::iterator it1;it1=front.begin();
	vector<point> ::iterator it2;it2=end.begin();
	int newindex=left;
	int count=0;
	while(it1!=front.end() && it2!=end.end()){
		if(it1->y<=it2->y){
			++count;
			ans[newindex++]=*it1;
			it1++;
		}
		else{
			result[it2->time]+=count;
			ans[newindex++]=*it2;
			it2++;
		}
		
	}
	for(;it1!=front.end();it1++){
		ans[newindex++]=*it1;
		
	}
	
	for(;it2!=end.end();it2++){
		ans[newindex++]=*it2;
		result[it2->time]+=count;
	
	}
	
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount;
	cin>>amount;
	int x,y;
	vector<struct point> ans; 
	vector<int> result; 
	struct point points;
	for(int i=0;i<amount;i++){
		cin>>x>>y;
		points.x=x;
		points.y=y;
		points.time=i;
		ans.push_back(points);
		result.push_back(0);
	}
	sort(ans.begin(),ans.end(),compare);
	div(0,amount-1,ans,result);
	vector<int> ::iterator it;
	for(it=result.begin();it!=result.end();it++){
		cout<<*it<<" ";
	}

}

//https://hackmd.io/gVs5B6VVQFasyjLyrJq5dw
