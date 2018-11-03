#include <bits/stdc++.h>

#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)

using namespace std;

struct graph
{
	int u,v;
	long long w;
	
};

vector<graph>vet;
vector<int>pr;
int find(int r)
{
	return (pr[r] == r) ? r : find(pr[r]);
}

bool cmp(graph a, graph b){
	return a.w<b.w;
}

long long mst(int n){
	pr.resize(n+2,0);
	for(int i=1;i<=n;i++)pr[i]=i;

	sort(vet.begin(), vet.end(), cmp);

	int countt=0;
	long long s=0;

	for(int i=0 ;i <vet.size() ;i++){
		int u= find(vet[i].u);
		int v= find(vet[i].v);
		if(u!=v){
			pr[u]=v;
			countt++;
			s+=vet[i].w;
			if(countt==n-1)break;
		}
	}
	return s;
}


int main(){
	//READ;
	//WRITE;
	int test;
	cin>>test;

	while(test--){
		int n,m;
		cin>>n>>m;

		map<string,int>mp;
		int countt=0;
		while(m--){
			int w;
			string s1,s2;
			cin>>s1>>s2>>w;
			if(!mp[s1])mp[s1]=++countt;
			if(!mp[s2])mp[s2]=++countt;

			graph node;
			node.u=mp[s1];
			node.v=mp[s2];
			node.w=w;
			vet.push_back(node);
		}
		cout<<mst(n)<<endl;
		mp.clear();
		vet.clear();
		pr.clear();
		if(test!=0)cout<<endl;
	}
}