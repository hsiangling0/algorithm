#include <iostream>
#include <queue>
#include <array>
#include<cstring>
using namespace std;
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int place,line,from,to,dir,now,time1=1,time2=1;
	cin>>place>>line;
	bool airplane[1001][1001];
	queue<int> re;
	bool visit[1001];
	while(place!=0 &&line!=0){
		for(int i=0;i<line;i++){
			cin>>from>>to>>dir;
			airplane[from][to]=true;
			if(dir==2)airplane[to][from]=true;
		}
		visit[1]=true;
		for(int i=2;i<=place;i++){    //先從點1做BFS 
			if(airplane[1][i]){
				re.push(i);
				visit[i]=true;
				time1++;
			}
		}
		while(!re.empty()){
			now=re.front();
			re.pop();
			for(int i=1;i<=place;i++){
				if(airplane[now][i] && !visit[i]){
					re.push(i);
					visit[i]=true;
					time1++;
				}
			}
		}
		memset(visit,0,sizeof(visit));	
		if(time1!=place){               //確認從點1是否可走到所有點 
			cout<<"0"<<endl;
			cin>>place>>line;
			memset(airplane,0,sizeof(airplane));
			time1=1;
			continue;
		}	
		visit[1]=true;
		for(int i=2;i<=place;i++){    //從點1在相反圖做BFS(相反圖代表路線方向顛倒) ，若可以則代表從其他點都可以走到1 
			if(airplane[i][1]){
				re.push(i);
				visit[i]=true;
				time2++;
			}
		}
		while(!re.empty()){
			now=re.front();
			re.pop();
			for(int i=1;i<=place;i++){
				if(airplane[i][now] && !visit[i]){
					re.push(i);
					visit[i]=true;
					time2++;
				}
			}
		}
		if(time2==place){     //確認是否仍可以走到所有點 
			cout<<"1"<<endl;
		}
		else{
			cout<<"0"<<endl;
		}
		memset(visit,0,sizeof(visit));
		memset(airplane,0,sizeof(airplane));	
		cin>>place>>line;
		time1=1;time2=1;	
	}
	
}

/*input
4 4
1 2 1
2 3 1
3 4 1
4 1 2
4 4
1 2 2
2 4 1
3 4 2
1 3 1
0 0
*/

/*output
1
0
*/

