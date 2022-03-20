#include <iostream>
#include <vector>
using namespace std;
void print(bool record[],vector<int> num,int amount){
	for(int i=0;i<amount;i++){
		if(record[i]){
			cout<<num[i]<<" ";
		}
	}
	cout<<endl;
}

bool check(bool record[],int amount){
	for(int i=amount-6;i<amount;i++){
		if(!record[i]){
			return false;
		}
	}
	return true;
}
void com(vector<int> &num,int amount){
	bool *record=new bool[amount]();
	for(int i=0;i<amount;i++){
		if(i>5){
			record[i]=false;
		}
		else{
			record[i]=true;
		}
	}
	int rot=5;
	print(record,num,amount);
	while(!check(record,amount)){
		for(int i=amount-1;i>0;i--){
			if(!record[i]&&record[i-1]){
				record[i]=true;
				record[i-1]=false;
				int temp=i+1;
				for(int j=i+1;j<amount;j++){
					if(record[j]){
						record[j]=false;
						record[temp++]=true;
					}
				}
				print(record,num,amount);
				break;
			}	
		}
	}
	delete[] record;
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount,fix;
	cin>>amount;
	vector<int> num;
	int pick;
	for(int i=0;i<amount;i++){
		cin>>pick;
		num.push_back(pick);
	}
	
	com(num,amount);
}

//https://hackmd.io/87TU9cdPR_qBgv3Zr0RuIw?view 
