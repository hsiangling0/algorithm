#include <iostream>
#include <map>
using namespace std;

void SET(map<long,long> &time,map<long,pair<long,long>> &value,long &limit,long &curr){
	long a,b;
	cin>>a>>b;
	time[curr]=a;
	if(value.find(a)!=value.end()){
		time.erase(value[a].second);
	}
	else if(time.size()>limit){
		map<long,long> :: iterator it;
		it=time.begin();
		value.erase((*it).second);
		time.erase((*it).first);
	}
	value[a]={b,curr};
	
}

void GET(map<long,long> &time,map<long,pair<long,long>> &value,long &curr){
	long a;
	cin>>a;
	if(value.find(a)!=value.end()){
		cout<<value[a].first<<endl;
		time.erase(value[a].second);
		time[curr]=a;
		value[a].second=curr;
	}
	else{
		cout<<-1<<endl;
		curr--;
	}
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long limit,command;
	cin>>limit>>command;
	map<long,long> time;
	map<long,pair<long,long>> value;
	long curr=1;
	while(command>0){
		command--;
		string operation;
		cin>>operation;
		if(operation=="set"){
			SET(time,value,limit,curr);
		}
		else{
			GET(time,value,curr);
		}
		cin.get();
		curr++;
	}
}

/*input
10 10
get 4
set 4 4
set 2 1
get 4
get 5
set 2 3
set 2 2
get 3
set 4 3
get 2 */

/*output
-1
4
-1
-1
2 */

