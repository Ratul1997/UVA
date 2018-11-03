#include <bits/stdc++.h>
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
using namespace std;

vector<int>graph[205];
int visit[205];
int color[205];



int bfs(int source){

	queue<int>q;
	q.push(source);
	color[source]=0;
	int total=0,one_color=0;

	while(!q.empty()){
		int from=q.front();
		q.pop();
		total++;

		if(color[from]==0)one_color++;

		for(auto to : graph[from]){

			if(color[to] == -1){
				color[to]= color[from]==0? 1:0;
				q.push(to);
			}
			else if(color[to] == color[from])return -1;
		}
	}
	if(total==1)return 1;
	return min(one_color,total-one_color);
}

int main(){
	//READ;
	//WRITE;
	int test;
	cin>>test;
	while(test--){
		int v,e;
		cin>>v>>e;
		for(int i=0;i<=205;i++)graph[i].clear();

		memset(visit, false, sizeof(visit));

		memset(color, -1, sizeof(color));
		for(int i=0;i<e;i++){
			int u,v2;
			cin>>u>>v2;
			graph[u].push_back(v2);
			graph[v2].push_back(u);
		}

		int countt=0;
		bool flag=false;
		for(int i=0;i<v ; i++){
			if(color[i]==-1){
				
				int needed= bfs(i);
				if(needed==-1){flag=true;break;}
				else countt+=needed;
			}
		}
		if(flag)cout<<-1<<endl;
		else cout<<countt<<endl;
	}
}