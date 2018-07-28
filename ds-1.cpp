#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#define mx 100000
using namespace std;
int siz;

int *arr = (int*) malloc(siz * sizeof(int));

char s[87678];
void view()
{
    int i;
    cout<<"The array is: ";
    for(i=1; i<=siz; i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<"\n";
}

void newelement()
{
    int item, pos, i,*s,j;
    cout<<"The item needed to be inserted: ";
     int p=0;
    char str1[564];
    memset(str1,0,sizeof(str1));
        //cin>>str;
    scanf("%s",str1);
    for(j=0;j<strlen(str1);j++){
        if(str1[j]<='9' && str1[j]>='0'){
            p=p*10+str1[j]-'0';
        }
        else {
            cout<<"it is a character, please insert integer\n";
            p=0;
            newelement();
            break;
        }
    }
    if(p!=0){
    item=p;
    cout<<"Enter position of ITEM: ";
    }
    cin>>pos;
    for(i=siz; i>=pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=item;
    s=&siz;
    //size=&size+1;
    *s=*s+1;
    view();
}
void search()
{
    int item,loc=0,i=1;
    cout<<"Enter an ITEM to be searched: ";
    cin>>item;
    for(i=1; i<=siz; i++)
    {
        if(arr[i]==item)
        {
            loc=i;
            cout<<item<<" is found in location "<<loc;
        }
    }
    if(loc==0)
    {
        cout<<"ITEM not found";
    }
}
void del()
{
    int x=siz;
    int item,loc=0,i=1,j,ok=0;
    cout<<"Enter an ITEM to be deleted: ";
    cin>>item;
    for(i=1; i<=siz; i++)
    {
        if(ok==1 && i!=1)
        {
            i--;
            ok=0;
        }
        if(arr[i]==item)
        {
            loc=i;
            for(j=loc; j<=siz-1; j++)
            {
                arr[j]=arr[j+1];
            }
            siz--;
            ok=1;
        }
    }
    if(loc==0)
    {
        cout<<"ITEM not found";
    }
    else
    {
        view();
    }
}
void asort()
{
    int i,j,swap;
    for (i=1; i<=siz-1; i++)
    {
        for (j=1; j<=siz-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }

    cout<<"Sorted list in ascending order:\n";

    view();
}

void dsort()
{
    int i,ptr,swap;
    for (i=1; i<=siz-1; i++)
    {
        for (ptr=1; ptr<=siz-i; ptr++)
        {
            if (arr[ptr]<arr[ptr+1])
            {
                swap=arr[ptr];
                arr[ptr]=arr[ptr+1];
                arr[ptr+1]=swap;
            }
        }
    }

    cout<<"Sorted list in descending order:\n";

    view();
}

void mem()
{
    int p,i,index,ad,loc;
    p=*arr+1;
    cout<<"Enter the index (N.B. index 1 means first element): ";
    cin>>index;
    index--;
    if(index>siz)
    {
        cout<<"Index should be from 0 to size-1. So, your given index is invalid.";
    }
    else
    {
        ad=p+sizeof(int)*index;
        cout<<"The "<<index+1<<"th element is allocated in location "<<ad;
    }
}
void option_fun();
void more()
{
    int more;
    cout<<"Do you want to do perform more job? if YES, enter 1; otherwise enter 0: ";
    cin>>more;
    if(more==1)
    {
        system("cls");
        option_fun();
    }
    else
        exit;
}
void option_fun()
{
    int option;
    cout<<"Enter your choice:\n1. view\n2. insert\n3. search\n4. Delete\n5. ascending sorting\n6. Descending sorting\n7. memory allocation\n";
    while(cin>>option && option!=0)
    {
        if(option==1)
        {
            view();
            more();
        }
        else if(option==2)
        {
            newelement();
            more();
        }
        else if(option==3)
        {
            search();
            more();
        }
        else if(option==4)
        {
            del();
            more();
        }
        else if(option==5)
        {
            asort();
            more();
        }
        else if(option==6)
        {
            dsort();
            more();
        }
        else if(option==7)
        {
            mem();
            more();
        }
    }
}

int main()
{
    int i,decision,num=0;
    cout<<"Size of the  array: ";
    yo:
    {
        gets(s);
        for(i=0; i<strlen(s); i++)
        {
            if(s[i]<='9' && s[i]>='0')
            {
                num=num*10+s[i]-'0';
            }
            else
            {
                cout<<"it is not a integer, please insert integer\n";
                goto yo;
            }
        }
        siz=num;
    }
    int j;
    cout<<"Elements of the array are: ";
    for(i=1; i<=siz; i++)
    {
        int p=0;
        char str[564];
        memset(str,0,sizeof(str));
       // cin>>str;
        scanf("%s",str);
        for(j=0;j<strlen(str);j++){
            if(str[j]<='9' && str[j]>='0'){
                p=p*10+str[j]-'0';
            }
            else {
                cout<<"it is a character, please insert integer\n";
            }
        }
        arr[i]=p;
    }
    cout<<"Dear user, you can do some jobs with your array.. if you want to see the job menu, enter 1. otherwise enter 0\n";
    cin>>decision;
    if(decision==1)
    {
        option_fun();
    }
    else
        exit;
}
