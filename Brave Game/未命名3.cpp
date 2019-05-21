#include<iostream>
#include<cstring>
using namespace std;
const int N=32;
int n;
int k;
int m;
int memsize;
int E[N+1][N+1];
void add(int ans[][N+1],int a[][N+1],int b[][N+1]);
void pows(int ans[][N+1],int a[N+1][N+1],int mi);
void mul(int ans[][N+1], int a[N+1][N+1],int b[N+1][N+1]);
void dfs(int ans[][N+1], int lev,int mat[][N+1]) {
	if(lev==1){
	memcpy(ans,mat,memsize);
	return;
	}
	if(lev%2==0) {
		int temp0[N+1][N+1];
		pows(temp0,mat,lev/2);
		add(temp0,E,temp0);
		int temp2[N+1][N+1];
		dfs(temp2,lev/2,mat);
		mul(ans,temp0,temp2);
	} else {
		int temp0[N+1][N+1];
		pows(temp0,mat,lev);
		int temp1[N+1][N+1];
		dfs(temp1,lev-1,mat);
		add(ans,temp0,temp1);
	}
}

void pows(int ans[][N+1],int a[][N+1],int mi) {
	int temp2[N+1][N+1];
	memcpy(temp2,a,memsize);
	memset(ans,0,memsize);
	for(int i=1; i<=n; ++i) {
		ans[i][i]=1;
	}
	int temp1[N+1][N+1];
	while(mi) {
		if(mi&1) {
			mul(temp1,ans,temp2);
			memcpy(ans,temp1,memsize);
		}
		mul(temp1,temp2,temp2);
		memcpy(temp2,temp1,memsize);
		mi>>=1;
	}
}
void mul(int ans[][N+1], int a[N+1][N+1],int b[N+1][N+1]) {
	memset(ans,0,memsize);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++){
				ans[i][j]+=a[i][k]*b[k][j];
				ans[i][j]%=m;
			}
}

void add(int ans[][N+1],int a[N+1][N+1],int b[N+1][N+1]) {
	for(int y=1; y<=n; ++y) {
		for(int x=1; x<=n; ++x) {
			ans[y][x]=a[y][x]+b[y][x];
			ans[y][x]%=m;
		}
	}
}
int main() {

	cin>>n>>k>>m;
	
	memsize=sizeof(int)*(N+1)*(N+1);
	for(int a=1; a<=n; ++a) {
		E[a][a]=1;
	}

	int matrix[N+1][N+1];
	for(int y=1; y<=n; ++y) {
		for(int x=1; x<=n; ++x) {
			cin>>matrix[y][x];
			matrix[y][x]%=m;
		}
	}
	int ans[N+1][N+1];
	dfs(ans,k,matrix);
	
	for(int y=1; y<=n; ++y) {
		for(int x=1; x<=n; ++x) {
			cout<<ans[y][x]<<" ";
		}
		cout<<endl;
	}




	return 0;
}
