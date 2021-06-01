/*
Given two lists sorted in increasing order, create a new list representing
the intersection of the two lists. The new list should be made with its own
memory — the original lists should not be changed.
*/
  
  
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

void insert(Node **start, int x){
    Node *p = new Node(x);
    Node *temp = *start;
    if(*start == NULL){
        *start = p;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *start = NULL;
    Node *temp = start;
    Node *p;
    Node *temp1, *temp2;
    temp1 = head1;
    temp2 = head2;
    while(temp1!=NULL){
        if(temp2 == NULL){
            temp2 = head2;
            temp1 = temp1->next;
        }
        else{
            if(temp1->data == temp2->data){
                    insert(&start, temp1->data);
                    temp1 = temp1->next;
                }
            else{
                temp2 = temp2->next;
            }
        }
    }
    return start;
}
