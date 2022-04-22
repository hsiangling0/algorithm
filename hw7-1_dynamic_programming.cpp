#include <iostream>
#include <vector>
using namespace std;

void findMin(vector<int> &input, int amount,int sum){
	int halfSum=sum/2+1;
	vector<bool> all,temp;
	for(int i=0;i<halfSum;i++){
		all.push_back(false);
		temp.push_back(false);
	}
	all[0]=true;
	for(int i=0;i<amount;i++){
		for(int j=0;j+input[i]<halfSum;j++){
			if(all[j])temp[j+input[i]]=true;
		}
		for(int j=0;j<halfSum;j++){
			if(temp[j]){
				all[j]=true;
				temp[j]=false;
			}
		}
	}
	for(int i=halfSum-1;i>=0;i--){
		if(all[i]){
			cout<<sum-2*i<<endl;
			return;
		}
	}
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount,number,sum=0;
	cin>>amount;
	vector<int> input;
	while(cin>>number){
		input.push_back(number);
		sum+=number;
	}
	findMin(input,amount,sum);
}


/*input
6
4 5 10 4 7 1
*/

/*output
1
*/

//https://hackmd.io/cLJP6VmdRgONP3UX1mD5wQ?view
