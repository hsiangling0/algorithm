#include <iostream>
#include <vector>
using namespace std;
void mergesort(vector<long>&num,long,long,long);
void mergediv(vector<long> &num,long head,long tail){
	if(head<tail){
		long middle=(head+tail)/2;
		mergediv(num,head,middle);
		mergediv(num,middle+1,tail);
		mergesort(num,head,middle,tail);
	}
}

long ans=0;
void mergesort(vector<long> &num, long head,long middle,long tail){
	long lenA=middle-head+1;
	long lenB=tail-middle;
	vector<long> len_A,len_B;
	vector<long> ::iterator it;it=num.begin();
	len_A.insert(len_A.begin(),num.begin()+head,it+middle+1);
	len_B.insert(len_B.begin(),it+middle+1,it+tail+1);
	long indexA=0;
	long newindex=head;
	vector<long> ::iterator it1;it1=len_A.begin();
	vector<long> ::iterator it2;it2=len_B.begin();
	while(it2!=len_B.end() && it1!=len_A.end()){
		if(*it1>*it2){
			num[newindex]=*it2;
			it2++;
			ans=(ans+lenA-indexA)%524287;
			
		}
		else{
			num[newindex]=*it1;
			it1++;
			indexA++;
		}
		newindex++;
	}
	for(;it1!=len_A.end();it1++){
		num[newindex]=*it1;
		newindex++;
		
	}
	
	for(;it2!=len_B.end();it2++){
		num[newindex]=*it2;
		newindex++;
	}
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long amount,input;
	cin>>amount;
	vector<long> number;
	for(long i=0;i<amount;i++){
		cin>>input;
		number.push_back(input);
	}
	mergediv(number,0,amount-1);
	cout<<ans;
}
