#include <iostream>
#include <vector>
using namespace std;

void findMax(vector<int> &test,int amount){
	int max=test[1];
	int from=1;
	int end=1;
	vector<pair<int,int>> ans;
	ans.push_back({0,1});
	for(int i=1;i<=amount;i++){
		if(ans[i-1].first<0){
			ans.push_back({test[i],i});
		}
		else{
			ans.push_back({ans[i-1].first+test[i],ans[i-1].second});
		}
		if(ans[i].first>max){
			max=ans[i].first;
			from=ans[i].second;
			end=i;
		}
	}
	cout<<max<<" "<<from<<" "<<end<<endl;
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

/*input
7
0 6 -1 1 -6 7 -5
*/
/*output
7 1 6
*/
