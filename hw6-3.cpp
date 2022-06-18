#include <iostream>
#include <vector>
#include <string>
using namespace std;

int transTimes(vector<int> s[],string t){
	int time=1;
	bool find=false;
	int pre=-1;
	int word;
	int m,r,u;
	for(int i=0;i<t.length();i++){
		word=t[i]-97;
		if(s[word].empty())return -1;
		else{
			u=s[word].size();
			u--;
			r=0;
			while(r<=u){
				m=(r+u)/2;
				if(pre<s[word][m]){
					if(m!=0 &&pre<s[word][m-1]){
						u=m-1;
					}
					else{
						pre=s[word][m];
						find=true;
						break;
					}
					
				}
				else r=m+1;
			}
			if(!find){
				pre=s[word][0];
				time++;
			}
			find=false;
		}
	}
	return time;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string String,tString;
	int data;
	int ans;
	cin>>data;
	while(data>0){
		vector<int> sString[26];
		data--;
		cin.get();
		cin>>String>>tString;
		for(int i=0;i<String.length();i++){
			char a=String[i];
			int index=a-97;
			sString[index].push_back(i);
		}
		ans=transTimes(sString,tString);
		cout<<ans<<endl;
	}
}

/*input
3(test amount) 
aabce (s string) 
ace (t string)
abacaba
aax
ty
yyt
*/
/*output
1
-1
3
*/
