#include <iostream>
#include <stack>
using namespace std;
struct record{
	int x;
	int y;
	int d;
};

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int rangex,rangey;
	cin>>rangex>>rangey;
	int initx,inity,tox,toy,endx,endy,dir;
	stack<struct record> road;
	cin>>initx>>inity>>endx>>endy;
	initx--;inity--;endx--;endy--;
	struct record r;
	r.d=1;
	r.x=initx;r.y=inity;
	road.push(r);
	bool mark[300][300];
	mark[initx][inity]=true;
	bool map[300][300];
	for(int i=0;i<rangex;i++){
		for(int j=0;j<rangey;j++){
			cin>>map[i][j];
			mark[i][j]=false;
		}
	}
	if(initx==endx && inity==endy){
		cout<<"Success!"<<endl;
		exit(0);
	}
	while(!road.empty()){
		r=road.top();
		initx=r.x;
		inity=r.y;
		dir=r.d;
		road.pop();
		while(dir<5){
			switch(dir){
				case 1: tox=initx; toy=inity+1;break;
				case 2: tox=initx+1; toy=inity; break;
				case 3: tox=initx; toy=inity-1; break;
				case 4: tox=initx-1;toy=inity;break;
			}
			if(tox<0 ||tox>=rangex ||toy<0 ||toy>=rangey){
				dir++;
				continue;
			}
			if(tox==endx &&toy==endy){
				cout<<"Success!"<<endl;
				exit(0);
			}
			else if(map[tox][toy] && !mark[tox][toy]){
				mark[tox][toy]=true;
				r.d=dir+1;r.x=initx;r.y=inity;
				initx=tox;inity=toy;dir=1;
				road.push(r);
			}
			else dir++;
		}
	}
	cout<<"Fail!"<<endl;
	
}
