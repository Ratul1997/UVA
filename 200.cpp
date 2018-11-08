#include<bits/stdc++.h>
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
using namespace std;
vector<int>graph[50005],order;
bool exists[30],visit[30];

bool dfs(int source){
	visit[source]=true;

	
	for(auto to : graph[source]){
		if(!visit[to])dfs(to);
	}
	order.push_back(source);
}

int main(){
	//READ;
	//WRITE;

	string s1,s2;
	while(cin>>s1){
		memset(visit,false, sizeof(visit));
		memset(exists,false, sizeof(exists));
		for(int i=0;i<=50005;i++)graph[i].clear();

		int kk=0;
	    string check=s1;
	    set<char> st(s1.begin(), s1.end());

		while(cin>>s2 && s2!="#"){
		//cout<<s1<<" "<<s2<<endl;
			kk++;
			st.insert(s2.begin(), s2.end());
	    
			for(int i=0;i< s1.size() and i< s2.size() ;i++){
				if(s1[i]!=s2[i]){
					exists[s1[i]-'A']=true;
					exists[s2[i]-'A']=true;
					graph[s1[i]-'A'].push_back(s2[i]-'A');
					break;
				}
			}
			s1=s2;
		}
		if(st.size()==1){
			string sss(st.begin(),st.end());
			cout<<sss<<endl;
			continue;
		}
		
	/*for(int i=0;i<26;i++){
		cout<<char(i+'A')<<" -> ";
		for(auto child: graph[i]){
			cout<<char(child+'A')<<" ";
		}
		cout<<endl;
	}*/
		for(int i=0;i<26;i++){
			if(!visit[i] && exists[i])dfs(i);
		}

		for(int i= order.size()-1 ;i>=0;i--){
			cout<<char(order[i]+'A');
		}
		cout<<endl;

		s1.clear();
		s2.clear();
		order.clear();
	}
}