#include <bits/stdc++.h>
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout);
using namespace std;

vector<int>graph[305];

bool visit[305];
int color[305];

int k;
void dfs(int source){

	visit[source] = true;

	for(auto to: graph[source]){

		if(!visit[to] ){
			color[to]= color[source]==1 ? 0:1;
			visit[to]= true;
			dfs(to);
		}
		else if(color[to] == color[source]){k=1;return;}
	}
}


int main(){
	//READ;
	//WRITE;

	int vertex;
	while(cin>>vertex && vertex!=0){
		int u,v;
		for(int i=0;i<=305;i++)graph[i].clear();

		memset(visit, false, sizeof(visit));

		memset(color, false, sizeof(color));
		k=0;
		while(cin>>u>>v && u!=0 && v!=0){
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		dfs(1);

		if(k==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}