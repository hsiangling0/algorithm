#include <iostream>
#include <vector>
using namespace std;

void findMax(vector<int> &value,vector<int> &cost,int amount, int timeLimit){
	int ans[2][timeLimit+1];
	for(int i=0;i<=amount;i++){
		for(int j=0;j<=timeLimit;j++){
			if(i==0||j==0){
				ans[i%2][j]=0;
			}
			else if(cost[i]>j)ans[i%2][j]=ans[(i-1)%2][j];
			else{
				ans[i%2][j]=max(ans[(i-1)%2][j],value[i]+ans[(i-1)%2][j-cost[i]]);
			}
		}
	}
	cout<<ans[amount%2][timeLimit]<<endl;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount,timeLimit,value,cost;
	cin>>amount>>timeLimit;
	vector<int> Val;
	vector<int> Cost;
	Val.push_back(0);
	Cost.push_back(0);
	while(cin>>value>>cost){
		Val.push_back(value);
		Cost.push_back(cost);
	}
	findMax(Val,Cost,amount,timeLimit);
}

/*input
3 1440
30 500
30 600
40 1000
*/
/*output
60
*/
//https://hackmd.io/btapepKyRO2gzmXy3TaMaA
