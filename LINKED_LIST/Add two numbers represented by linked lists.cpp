#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node * reverse(struct Node *head)
    {
        if(head==0) return head;
        
        Node *prev=NULL;
        Node *curr=head;
      
        while(curr!=NULL)
        {
            Node *nextptr=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nextptr;
        }
        
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(first==0)return second;
        if(second==0)return first;
        
        first=reverse(first);
        second=reverse(second);
        
        Node *sum=new Node(-1);
        
        Node *p3=sum;
        
        int carry=0;
        
        while(first!=0 || second!=0)
        {
            
            int x=(first ? first->data : 0)
            + (second ? second->data : 0)+carry;
            
            carry=x/10;
            x=x%10;
            
            p3->next=new Node(x);
            p3=p3->next;
            
            if(first)
                first=first->next;
            if(second)
                second=second->next;
        }
        
       
        //if not 0 make another node for carry
        if(carry!=0)
             p3->next=new Node(carry);
        
       // p3->next->next=NULL;
       
        
        sum->next=reverse(sum->next);
        
        return sum->next;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
