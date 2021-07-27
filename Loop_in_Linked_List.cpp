// Given a linked list of N nodes. 
// The task is to check if the linked list has a loop. 
// Linked list can contain self loop.




//Solution

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


 // } Driver Code Ends
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    
    // bool detectLoop(Node* head)
    // {
        // unordered_set<Node *> s;
        // Node *temp = head;
        // while(temp->next != NULL){
        //     if(s.find(temp->next) != s.end()){
        //         s.insert(temp);
        //     }
        //     else
        //         return true;
        // }
        // return false;
        
        // 
        
        bool detectLoop(Node* head)
        {
            bool answer = false;
            Node *slow = head;
            Node *fast = head;
            
            while(fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                
                if(slow == fast)
                {
                    answer = true;
                    break;
                }
            }
            return answer;
        }
        
    
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}
  // } Driver Code Ends
