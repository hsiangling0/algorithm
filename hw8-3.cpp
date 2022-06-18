#include <iostream>
#include <vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

void findMax(vector<int> &q,int amount){
	vector<int> dpRight,dpLift;
	vector<int> vRight,vLift;
	int Rlength=1;
	int Llength=1;
	dpLift.push_back(1);
	dpRight.push_back(1);
	vLift.push_back(q[0]);
	vRight.push_back(q[amount-1]);
	for(int i=1;i<amount;i++){
		if(q[i]>vLift.back()){
			++Llength;
			dpLift.push_back(Llength);
			vLift.push_back(q[i]);
		}
		else{
			auto it=lower_bound(vLift.begin(),vLift.end(),q[i]);
			*it=q[i];
			dpLift.push_back((int)(it-vLift.begin()+1));
		}
		
		if(q[amount-1-i]>vRight.back()){
			++Rlength;
			dpRight.push_back(Rlength);
			vRight.push_back(q[amount-1-i]);
		}
		else{
			auto itr=lower_bound(vRight.begin(),vRight.end(),q[amount-1-i]);
			*itr=q[amount-1-i];
			dpRight.push_back((int)(itr-vRight.begin()+1));
		}
		
	}
	int ans=0;
	for(int i=0;i<amount;i++){
		ans=max(ans,dpLift[i]+dpRight[amount-1-i]);
	}
	ans=amount-ans+1;
	cout<<ans<<endl;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount,hard;
	cin>>amount;
	vector<int> question;
	for(int i=0;i<amount;i++){
		cin>>hard;
		question.push_back(hard);
	}
	findMax(question,amount);
}
