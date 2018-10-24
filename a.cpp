
#include<bits/stdc++.h>
using namespace std;
int n,i,j,ar,b;
int main()
{


    char s[24];

    int a[34];
    int k=0;
    cin>>n>>ar>>b;
    int x=n/2;
    int m=min(ar,b);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    if(n%2==0) {
        x--;
        for(i=0,j=n-1;i<=x;i++,j--){
            if(a[i]==1 && a[j]==1){
                continue;
            }
            if(a[i]==2 && a[j]==1){
                a[i]=1;
                sum+=b;
            }
            if(a[i]==1 && a[j]==2){
                a[j]=1;
                sum+=b;
            }
            if(a[i]==0 && a[j]==2){
                a[j]=0;
                sum+=ar;
            }
            if(a[i]==2 && a[j]==0){
                a[i]=0;
                sum+=ar;
            }
            if(a[i]==2 && a[j]==2){
                if(ar<b) {
                    a[i]=0;
                    a[j]=0;
                }
                else{
                    a[i]=1;
                    a[j]=1;
                }
                sum+=2*m;
            }
        }
    }
    else {
        for(i=0,j=n-1;i<x;i++,j--){
            if(a[i]==1 && a[j]==1){
                continue;
            }
            if(a[i]==2 && a[j]==1){
                a[i]=1;
                sum+=b;
            }
            if(a[i]==1 && a[j]==2){
                a[j]=1;
                sum+=b;
            }
            if(a[i]==0 && a[j]==2){
                a[j]=0;
                sum+=ar;
            }
            if(a[i]==2 && a[j]==0){
                a[i]=0;
                sum+=ar;
            }
            if(a[i]==2 && a[j]==2){
                if(ar<b) {
                    a[i]=0;
                    a[j]=0;
                }
                else{
                    a[i]=1;
                    a[j]=1;
                }
                sum+=2*m;
            }
        }
        if(a[x]==2) sum+=m;
    }
    int ok=0;
    for(i=0,j=n-1;i<n;i++,j--){
        if(a[i]!=a[j]){
            ok=1;
            break;
        }
    }
    if(n==1 && a[0]==2) cout<<m<<endl;
    else if((n==1) && (a[0]==0 || a[0]==1)) cout<<"0"<<endl;
    else if(ok==1) cout<<"-1"<<endl;
    else
    //cout<<endl;
    cout<<sum<<endl;
}

