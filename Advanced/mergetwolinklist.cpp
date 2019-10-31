#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
     
     node(int d){
         data = d;
         next = NULL;
     }

};

void insertattail(node*&head,int data){
    if(head == NULL){
        head = new node(data);
    }
    else{
        node*temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        node*n = new node(data);
        temp->next = n;
    }
}

node * merge(node*a,node*b){
    if(a==NULL){
        return b;
    }
   if(b==NULL){
       return a;
   }
   node*c;
   if(a->data < b->data){
       c=a;
       c->next = merge(a->next,b);
   }
   else{
       c=b;
       c->next = merge(a,b->next);
   }
   return c;
}


void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
   
   int t;
   cin>>t;
   while(t--){
       node*head = NULL;
       node*head1 = NULL;
      int n;
      cin>>n;
      while(n--){
         
          int data;
          cin>>data;
          insertattail(head,data);
      }
     // print(head);
      //cout<<endl;
     
   
         int m;
      cin>>m;
      while(m--){
          
          int data;
          cin>>data;
         
          insertattail(head1,data);
      }
      //print(head1);
      //cout<<endl;
   
   node*head3;
   head3 = merge(head,head1);
   print(head3);
   cout<<endl;

}
return 0;
}
