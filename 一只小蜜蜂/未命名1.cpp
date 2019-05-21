#include<iostream>
using namespace std;
long long fibb[100];
int main(){
fibb[0]=1;
fibb[1]=1;
for(int a=2;a<=55;++a){
fibb[a]=fibb[a-1]+fibb[a-2];
}
int n;
cin>>n;
for(int ac=1;ac<=n;++ac){
int a,b;
cin>>a>>b;
cout<<fibb[b-a]<<endl;
}


return 0;} 
