#include <bits/stdc++.h>
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
using namespace std;

vector<int>graph[105];
bool visit[105];
stack<int>st;

void dfs(int source){

	visit[source]=true;
	for(auto to: graph[source]){
		if(!visit[to])dfs(to);
	}

	st.push(source);
}


int main(){
	//READ;
	//WRITE;
	int n;
	int test=0;
	while(cin>>n){
		for(int i=0;i<=105;i++)graph[i].clear();

		memset(visit,false, sizeof(visit));


		map<string,int>mp;
		map<int,string>mp2;
		int countt=0;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			mp[s]=i+1,mp2[i+1]=s;
		}
		int m;
		cin>>m;
		while(m--){
			string s,s1;
			cin>>s>>s1;
			graph[mp[s1]].push_back(mp[s]);
		}
		for(int i=1;i<=n;i++){
			if(!visit[i]){
				dfs(i);
			}
		}
		vector<int>v1;
		while(!st.empty()){
			int x=st.top();
			st.pop();
			v1.push_back(x);
		}
		printf("Case #%d: Dilbert should drink beverages in this order: ",++test );
		cout<<mp2[v1[v1.size()-1]];
		for(int i=v1.size()-2; i>=0 ;i--){
			cout<<" "<<mp2[v1[i]];
		}
		cout<<"."<<endl<<endl;
	}
}