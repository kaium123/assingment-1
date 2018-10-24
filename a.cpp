
#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
int a[mx],i,j,n;
string s;
char ch;
map<char,int>mc;
map<int,int>mi;
//map<string,int>ms;
int main()
{
    int mn=INT_MAX;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=1;i<n;i++){
        int x=a[i]-a[i-1];
        mn=min(mn,x);
    }
    int sum=0;
    for(i=1;i<n;i++){
        sum+=(a[i]-a[i-1])-1;
    }
    cout<<sum<<endl;
    //cout<<mn<<endl;
}
