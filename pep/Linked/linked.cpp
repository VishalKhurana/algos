#include<iostream>
using namespace std;
class LL
{
public:
LL()
{

}

class node
{
    public:
    int data;
    node*next=NULL;
    node(int data)
    {
        this->data=data;
    }
};
node*head=NULL;
node*tail=NULL;
   void addFirst(int data)
   {
       node*first=new node(data);
       if(head==NULL)
       {
           head=first;
           tail=first;
       }
       else
       {
        //    node*temp=head;
           first->next=head;
           head=first;
       }
       
   }
   int size(node*head_)
   {
       int size_=0;
       node*temp=head_;
       while(temp!=NULL)
       {
           temp=temp->next;
           size_++;
       }
       return size_;
   }
   void addLast(int data)
   {
       node*tail_=new node(data);
      if(tail==NULL)
      {
          head=tail_;
          tail=tail_;
      }
      else
      {
        tail->next=tail_;
        tail=tail->next;
      }
      
   }

};

int main()
{
LL l1;
l1.addFirst(65);
cout<<l1.tail->data;
l1.addLast(80);
cout<<l1.tail->data;
cout<<l1.head ->data;

//   n->addFirst(new node(67));
//   cout<<head->size(head);


}