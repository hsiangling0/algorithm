#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
using namespace std;

struct homework{
	int score;
	int cost;
	int end;
};
bool compare(const homework &a,const homework &b){
	return a.end<b.end;
}

void findMax(vector<struct homework> &time,int amount){
	int timeMax=time[time.size()-1].end;
	int ans[2][timeMax+1];
	int timeLimit;
	for(int i=0;i<=amount;i++){
		timeLimit=time[i].end;
		for(int j=0;j<=timeLimit;j++){
			if(i==0||j==0){
				ans[i%2][j]=0;
			}
			else if(time[i].cost>j)ans[i%2][j]=ans[(i-1)%2][j];
			else{
				ans[i%2][j]=max(ans[(i-1)%2][j],time[i].score+ans[(i-1)%2][j-time[i].cost]);
			}
		}
		for(int j=timeLimit+1;j<=timeMax;j++){
			ans[i%2][j]=ans[i%2][timeLimit];
		}
		
	}
	cout<<ans[amount%2][timeLimit]<<endl;
	
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int amount,s,due,c;
	cin>>amount;
	vector<struct homework> time;
	struct homework h;
	h.score=0;h.cost=0;h.end=0;
	time.push_back(h);
	while(cin>>s>>due>>c){
		h.score=s;
		h.cost=c;
		h.end=due;
		time.push_back(h);
	}
	sort(time.begin(),time.end(),compare);
	findMax(time,amount);
}

/*input
6
20 2000 400
10 1000 500
10 3000 1000
30 1300 400
20 2000 700
10 1000 100
*/

/*output
90
*/
