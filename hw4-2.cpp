#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map <char,int> input;
	char in;
	while(cin>>in){
		input[in]--;
		
	}
	multiset <pair<int,char>> out;
	map<char,int>::iterator it;
	for (it=input.begin();it!=input.end();it++) {
       out.insert({it->second,it->first});
    }
	multiset<pair<int,char>> ::iterator iter;
	for(iter=out.begin();iter!=out.end();iter++){
		cout<<string(-(iter->first),iter->second); 
	}
}

/*input
tree
*/

/*output
eert
*/
