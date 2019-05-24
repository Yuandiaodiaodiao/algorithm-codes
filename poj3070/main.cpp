#include <iostream>
#include <cstring>
using namespace std;
const int N=2;
int n=2;
#define ull unsigned long long
ull m=100000;
ull memsize=sizeof(ull)*(N+1)*(N+1);
void add(ull ans[][N+1],ull a[][N+1],ull b[][N+1]);
void pows(ull ans[][N+1],ull a[N+1][N+1],ull mi);
void mul(ull ans[][N+1], ull a[N+1][N+1],ull b[N+1][N+1]);
void pows(ull ans[][N+1],ull a[][N+1],ull mi) {
    ull temp2[N+1][N+1];
    memcpy(temp2,a,memsize);
    memset(ans,0,memsize);
    for(ull i=1; i<=n; ++i) {
        ans[i][i]=1;
    }
    ull temp1[N+1][N+1];
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
void mul(ull ans[][N+1], ull a[N+1][N+1],ull b[N+1][N+1]) {
    memset(ans,0,memsize);
    for(ull i=1; i<=n; i++)
        for(ull j=1; j<=n; j++)
            for(ull k=1; k<=n; k++){
                ans[i][j]+=a[i][k]*b[k][j];
                ans[i][j]%=m;
            }
}

void add(ull ans[][N+1],ull a[N+1][N+1],ull b[N+1][N+1]) {
    for(ull y=1; y<=n; ++y) {
        for(ull x=1; x<=n; ++x) {
            ans[y][x]=a[y][x]+b[y][x];
            ans[y][x]%=m;
        }
    }
}
int main() {
ull x;
while(cin>>x&&x!=-1){
    ull arr[3][3];
    arr[1][1]=1;
    arr[1][2]=1;
    arr[2][1]=1;
    arr[2][2]=0;
    ull ans[3][3];
    pows(ans,arr,x);
    ull a=ans[1][2];
    a%=10000;
    cout<<a<<endl;
}

    return 0;
}