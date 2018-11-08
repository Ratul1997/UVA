#include <bits/stdc++.h>

#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
using namespace std;

int mat[55][55],scent[55][55];
char directions[] = {'N', 'E', 'S', 'W'};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};


int main(){
	//READ;
	//WRITE;
	int n,m;

		int x,y;
		char c;
	cin>>n>>m;
	while(cin>>x>>y>>c){


		
		string s;
		cin>>s;
		
		int direction=0;
		for(int i=0;i<4;i++){
			if(c==directions[i])direction=i;
		}

		bool flag=false;

		//cout<<direction<<endl;

		for(int i=0;i<s.size();i++){
			if(s[i]=='L'){
				direction=(direction+3)%4;
			}
			else if(s[i] == 'R'){
				direction=(direction+1)%4;
			}
			else{
				if(x+ dx[direction] == -1 || x+ dx[direction] ==n+1 || y+dy[direction] ==-1|| y+dy[direction] == m+1){
					if(!scent[y][x]){

					scent[y][x]=flag=true;
					break;
				}
				}
				else {
					x+=dx[direction];
					y+=dy[direction];
				}
			}
		}
		cout<<x<<" "<<y<<" "<<directions[direction]<<(flag? " LOST":"")<<endl;
	}
}