#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;

    node *next;

    node(){
        next=NULL;
    }
}*root;


void insertNode(int data)
{
    if(root == NULL){
        root = new node;
        root->info = data;
    }
    else{
        node *cur = root;

        while(cur->next!=NULL)
            cur = cur->next;

        cur->next=new node;
        cur->next->info = data;
    }
}

void deleteNode()
{
    if(root == NULL)
        cout<<"UnderFlow"<<endl;
    else root = root->next;
}

void findElement(int x)
{
    node *cur = root;

    if(cur==NULL)
        printf("List is Empty\n");
    int ok = 1;
    while(cur!=NULL){
        if(cur->info==x){
            ok = 0;
            cout<<"Element Exist"<<endl;
        }
        cur = cur->next;
    }
    if(ok) cout<<"Element not exist in this list"<<endl;
}

int main()
{
    int c,x;

    root = NULL;

    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Find Element\n");

    while(1){
        printf("Select Required Operation..: ");
        scanf("%d",&c);
        if(c==1){
            cout<<"Enter data: "<<endl;
            cin>>x;
            insertNode(x);
        }
        else if(c==2)
            deleteNode();
        else if(c==3){
            cin>>x;
            findElement(x);
        }
        else return 0;
    }
}
