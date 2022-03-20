#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

void DUP (stack<set<string>> &ans){
	if(!ans.empty()){
		set<string> top=ans.top();
		ans.push(top);
	}
}

void UNION(stack<set<string>> &ans){
	if(!ans.empty()){
		set<string> a=ans.top();
		ans.pop();
		if(!ans.empty()){
			set<string> b=ans.top();
			ans.pop();
			set<string> c;
			set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
			ans.push(c);
			return;
		}
		ans.push(a);
	}
}

void INTERSECT(stack<set<string>> &ans){
	if(!ans.empty()){
		set<string> a=ans.top();
		ans.pop();
		if(!ans.empty()){
			set<string> b=ans.top();
			ans.pop();
			set<string> c;
			set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
			ans.push(c);
			return;
		}
		ans.push(a);
	}
}

void ADD(stack<set<string>> &ans){
	if(!ans.empty()){
		set<string> a=ans.top();
		ans.pop();
		if(!ans.empty()){
			set<string> b=ans.top();
			ans.pop();
			set<string> ::iterator it;
			string change="{";
			for(it=a.begin();it!=a.end();it++){
				if(it!=a.begin()){
					change+=",";
				}
				change+=*it;
			}
			change+="}";
			b.insert(change);
			ans.push(b);
			return;
		}
		ans.push(a);
	}
}
void PRINT(stack<set<string>> &ans){
	cout<<ans.top().size()<<endl;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long command;
	cin >> command;
	stack<set<string>> ans;
	while(command>0){
		command--;
		string operation;
		cin >>operation;
		if(operation=="PUSH"){
			ans.push({});
		}
		else if(operation=="DUP"){
			DUP(ans);
		}
		else if(operation=="UNION"){
			UNION(ans);
		}
		else if(operation=="INTERSECT"){
			INTERSECT(ans);
		}
		else{
			ADD(ans);
		}
		PRINT(ans);
		
	}
}

//complete question and solving way
//https://hackmd.io/VTBuZASlSZW2JiLv3bzQkQ 
