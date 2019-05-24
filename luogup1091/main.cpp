#include <iostream>
#include<algorithm>

using namespace std;
int arr[105];
int dp1[105];
int dp2[105];
int main() {
    int n;
    cin>>n;
    for (int a = 1; a <= n; ++a) {
        cin >> arr[a];
    }
    for(int a=1;a<=n;++a){
        dp1[a]=1;
        for(int b=1;b<=a-1;++b){
            if(arr[a]>arr[b])dp1[a]=max(dp1[a],dp1[b]+1);
        }
    }
    for(int a=n;a>=1;--a){
        dp2[a]=1;
        for(int b=n;b>=a+1;--b){
            if(arr[a]>arr[b])dp2[a]=max(dp2[a],dp2[b]+1);
        }
    }


    int ans=0;
    for(int a=1;a<=n;++a)ans=max(ans,dp1[a]+dp2[a]-1);
    cout<<n-ans<<endl;
    return 0;
}



