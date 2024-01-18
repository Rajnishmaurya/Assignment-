#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

struct Node *head = NULL;

Node* removeduplicate(Node *head)
{
    if(head==NULL)
    return NULL;
    
    if(head->next==NULL)
    return head;

    Node *prev=head;
    Node *curr=head->next;

    while(curr)
    {
        if(prev->data!=curr->data)
        {
            Node *temp=curr->next;
            prev->next=curr;
            prev=curr;
            curr=temp;
            // prev -> next = NULL;
        }
        else{
            curr=curr->next;
        }
    }
    if(prev->next != NULL)
        prev -> next = NULL;
    return head;
}

void display(Node *head)
{
    if(head==NULL)
    {
        cout<<"No element is present in the linked list"<<endl;
    }
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void reverse(Node *head,int k)
{
    if(head==NULL)
    return ;

    Node *curr=head;
    Node *next=NULL;
    Node *prev=NULL;

    int count=0;
    Node *temp=NULL;
    while(curr!=NULL && count<k)
    {

        next=curr->next;
        curr->next=prev;
        prev=curr;
        if(count==0)
        {
            temp=prev;
        }
        curr=next;
        count++;
    }
    display(prev);
    if(next!=NULL)
    {
        // temp->next=prev;
        reverse(next,k);
    }

    return ;
}

Node *insert(Node *head,int x)
{
    if(head==NULL)
    {
        Node *temp= new Node(x);
        head = temp;
        return head;
    }
    else
    {
        Node *prev=NULL;
        Node *temp=head;
        Node *make_node=new Node(x);
        
        while(temp!= NULL && temp->data < x){
            prev = temp;
            temp = temp->next;
        }
        // first largest element
        if(temp == NULL){
            prev -> next = make_node;
        }
        else if(temp != NULL && prev != NULL){
            prev -> next = make_node;
            make_node -> next = temp;
        }
        else if(temp != NULL && prev == NULL){
            make_node -> next = head;
            head = make_node;
        }
    }    
   return head;
}

int main()
{
   int n,k;
   cout<<"Enter the value of n: ";
   cin>>n;

   int A[n];
   cout<<"Enter the 'n' element:";
   for(int i=0;i<n;i++)
   {
    cin>>A[i];
   }

for(int i=0;i<n;i++)
{
   head=insert(head,A[i]);
}   
cout<<"Results after sorting the elements of a lined list: ";
display(head);
cout<<endl;
 head=removeduplicate(head);
 cout<<"After removal of duplicates: ";
 display(head);
 cout<<endl;
 cout<<"Enter the value of k for reversing the linked list in a size of k: ";
 cin>>k;
 cout<<"After reversal of a linked list in a group of size k:"<<endl;
 reverse(head,k);

}