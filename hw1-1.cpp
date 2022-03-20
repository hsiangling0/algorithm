#include <iostream>
#include <vector>
using namespace std;

void move(vector<int> ans[], int site[],int num){
	int location=site[num];
	int endnum=ans[location].back();
	while(num!=endnum){
		site[endnum]=endnum;
		ans[endnum].push_back(endnum);
		ans[location].pop_back();
		endnum=ans[location].back();
	}
}
void AtoB(vector<int> ans[],int site[],int a,int b){
	int alocation=site[a];
	int blocation=site[b];
	if(a==ans[alocation].back()){
		ans[alocation].pop_back();
		ans[blocation].push_back(a);
		site[a]=site[b];
		return;
	}
	vector<int> ::iterator it;it=ans[alocation].end()-1;
	while(1){
		if(*it==a){
			ans[blocation].insert(ans[blocation].end(),it,ans[alocation].end());
			ans[alocation].erase(it,ans[alocation].end());
			site[a]=site[b];
			return;
		}
		site[*it]=site[b];
		it--;
	}
}

void Print(vector<int> ans[],int block){
	for(int i=1;i<=block;i++){
		cout<<i<<": ";
		if(ans[i].empty()){
			cout<<endl;
			continue;
		}
		vector<int> ::iterator it;
		for(it=ans[i].begin();it!=ans[i].end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int block;
	long command;
	cin >>block>>command;
	vector<int> ans[block+1];
	int site[block+1];
	for(int i=1;i<=block;i++){
		ans[i].push_back(i);
		site[i]=i;
	}
	string method,method2;
	int a,b;
	while(command>0){
		command--;
		cin.get();
		cin>>method>>a>>method2>>b;
		if(site[a]==site[b])continue;
		if(method=="move"){
			move(ans,site,a);
		}
		if(method2=="onto"){
			move(ans,site,b);
		}
		AtoB(ans,site,a,b);
	}
	Print(ans,block);
}


/*input
10 8
pile 1 onto 1
pile 8 over 6
move 3 onto 5
move 8 over 8
move 4 onto 9
pile 10 over 10
move 9 onto 2
pile 3 onto 7
*/ 
/*output
1: 1
2: 2 9
3:
4: 4
5: 5
6: 6 8
7: 7 3
8:
9:
10: 10
*/
