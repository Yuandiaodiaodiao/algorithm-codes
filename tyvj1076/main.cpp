#include<iostream>
using namespace std;
int ang[30][30];
bool can[30][30][105];
int main(){
    int n;
    cin>>n;
    for(int a=1;a<=n;++a){
        for(int b=1;b<=a;++b){
            cin>>ang[a][b];
        }
    }
    for(int a=1;a<=n;++a)can[n][a][ang[n][a]%100]=true;
    for(int a=n-1;a>=1;--a){
        for(int b=1;b<=a;++b){
            for(int c=0;c<=99;++c){
                can[a+1][b][c]?can[a][b][(c+ang[a][b])%100]=true:0;
                can[a+1][b+1][c]?can[a][b][(c+ang[a][b])%100]=true:0;
            }
        }
    }
    int maxn=0;
    for(int a=0;a<=99;++a){
        can[1][1][a]?maxn=a:0;
    }
    cout<<maxn<<endl;
    return 0;
}