#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*next=NULL;
    node(int data)
    {
       this->data=data;
    }

    node()
    {

    }


};

int main()
{
    node*head=new node(1);
    node*m=head;
    int n=5;
    while(n>0)
    {
        int val;
        cin>>val;
        node*t=new node(val);
        m->next=t;
        m=t;
        n--;
        
    }
    // while(head!=NULL)
    // {
    //     cout<<head->data<<"->";
    //     head=head->next;
    // }
     node*prev=NULL;
     node*NEXT=NULL;
     node*curr=head;
     while(curr!=NULL)
     {
         NEXT=curr->next;
         curr->next=prev;
         prev=curr;
         curr=NEXT;
     }
     head=prev;
  
   while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }

    

}