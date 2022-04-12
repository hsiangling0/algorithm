#include <iostream>

using namespace std;

struct stones{
	char stone;
	int width;
};

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int times,amount,length;
	cin>>times;
	while(times>0){
		times--;
		cin>>amount>>length;
		int highest=0;
		struct stones stoneP,stoneQ,stoneR;
		char s;
		int w,gap=0;
		stoneQ.stone='b';
		stoneQ.width=0;
//		stoneP.width=0;
//		stoneP.stone='b';
		for(int i=0;i<=amount;i++){
			if(i<amount){
				cin.get();
				cin>>s>>w;
				stoneR.stone=s;
				stoneR.width=w;
			}
			else{
				stoneR.stone='b';
				stoneR.width=length;
			}
			if(stoneR.stone=='b'){
				if(stoneQ.stone=='b'){
					gap=stoneR.width-stoneQ.width;
				}
				else gap=stoneR.width-stoneP.width;
			}
			else{
				if(stoneQ.stone=='s'){
					gap=stoneR.width-stoneP.width;
				}
			}
			highest=gap>highest?gap:highest;
			stoneP=stoneQ;
			stoneQ=stoneR;
		}
		cout<<highest<<endl;
	}
}

/*INPUT
3
1 10
b 5
1 10
s 5
2 10
b 3 s 6
*/
/*OUTPUT
5
10
7
*/ 

//https://hackmd.io/fM0fQhrnRnGXaItoEoDTOQ?view
