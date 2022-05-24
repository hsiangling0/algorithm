#include <iostream>
#include <queue>
using namespace std;
struct record{
	int x;
	int y;
	int t;
};

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int rangex,rangey;
	cin>>rangex>>rangey;
	int initx,inity,tox,toy,endx,endy,time;
	queue<struct record> road;
	cin>>initx>>inity>>endx>>endy;
	initx--;inity--;endx--;endy--;
	struct record r;
	r.t=0;
	r.x=initx;r.y=inity;
	road.push(r);
	bool mark[1000][1000];
	bool map[1000][1000];
	for(int i=0;i<rangex;i++){
		for(int j=0;j<rangey;j++){
			cin>>map[i][j];
			mark[i][j]=false;
		}
	}
	mark[initx][inity]=true;
	if(initx==endx && inity==endy){
		cout<<"0"<<endl;
		exit(0);
	}
	while(!road.empty()){
		r=road.front();
		initx=r.x;
		inity=r.y;
		time=r.t;
		road.pop();
		for(int dir=1;dir<5;dir++){
			switch(dir){
				case 1: tox=initx; toy=inity+1;break;
				case 2: tox=initx+1; toy=inity; break;
				case 3: tox=initx; toy=inity-1; break;
				case 4: tox=initx-1;toy=inity;break;
			}
			if(tox<0 ||tox>=rangex ||toy<0 ||toy>=rangey){
				continue;
			}
			if(tox==endx &&toy==endy){
				++time;
				cout<<time<<endl;
				exit(0);
			}
			else if(map[tox][toy] && !mark[tox][toy]){
				mark[tox][toy]=true;
				r.t=time+1;r.x=tox;r.y=toy;
				road.push(r);
			}
		}
	}
	cout<<"-1"<<endl;
	
}
/*input
5 5
3 5 5 4
0 1 0 0 1
0 1 1 1 1
0 0 1 1 1
1 1 0 1 0
0 1 1 1 1

*/
/*output
3
*/
//https://hackmd.io/U__vE_IPSv2cF5Eqw-vaug
