#include <bits/stdc++.h>
#define READ freopen("input.txt","r",stdin)
using namespace std;
int value[1005], weight[1005];
int dp[1005][35];

//bottomup approach
int knapsack(int w, int n){


	for(int i=0; i<=n; i++){
		for(int j=0; j<=w; j++){
			if(i==0 or j==0)continue;

			if( j- weight[i-1]>=0) dp[i][j]=max(dp[i-1][j], dp[i-1][j- weight[i-1]] + value[i-1]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

int main(){
	//READ;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		for(int i=0;i<n;i++){
			cin>>value[i]>>weight[i];
		}
		int g;
		cin>>g;
		int s=0;
		while(g--){

			memset(dp,0, sizeof(dp));
			int w;
			cin>>w;
			s+=knapsack(w,n);
		}
		cout<<s<<endl;
	}
}