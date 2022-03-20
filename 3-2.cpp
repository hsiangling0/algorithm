#include <iostream>
#include <vector>
using namespace std;

void adjust(vector<int> &ans,int i,int f){
	int min=ans[i];
	int j=2*i;
	while(1){
		if(j<f){
			j=ans[j]>ans[j+1]?j+1:j;
		}
		if(min<=ans[j])break;
		else{
			ans[j/2]=ans[j];
			j=j*2;
			if(j>f)break;
		}
	}
	ans[j/2]=min;
}
void print(vector<int> &ans);
void heap(vector<int> &ans,int amount){
	for(int i=amount/2;i>=1;i--){
		adjust(ans,i,amount);
	}
	
}
void print(vector<int> &ans){
	vector<int> ::iterator it;
	for(it=ans.begin()+1;it!=ans.end();it++){
		cout<<*it<<" ";
	}
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount;
	int num;
	vector<int> ans;
	ans.push_back(0);
	cin>>amount;
	for(int i=0;i<amount;i++){
		cin>>num;
		ans.push_back(num);
	}
	heap(ans,amount);
	print(ans);
}
