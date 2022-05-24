#include <iostream>
#include <vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

void findMax(vector<int> &test,int amount){
	vector<int> right,left;
	int sum=test[1];
	int maxsum=test[1];
	left.push_back(0);
	left.push_back(test[1]);
	int ans=INT_MIN;
	for(int i=2;i<amount;i++){
		if(sum<0){
			sum=test[i];
		}
		else{
			sum+=test[i];
		}
		if(sum>maxsum){
			maxsum=sum;
		}
		left.push_back(maxsum);
	}
	right.push_back(0);
	right.push_back(test[amount]);
	sum=test[amount];maxsum=test[amount];
	for(int i=amount-1;i>1;i--){
		if(sum<0){
			sum=test[i];
		}
		else{
			sum+=test[i];
		}
		if(sum>maxsum){
			maxsum=sum;
		}
		right.push_back(maxsum);
	}
	for(int i=1;i<amount;i++){
		ans=max(ans,left[i]+right[amount-i]);
	}
	cout<<ans<<endl;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount,hard;
	vector<int> test;
	cin>>amount;
	test.push_back(0);
	while(cin>>hard){
		test.push_back(hard);
	}
	findMax(test,amount);
}


