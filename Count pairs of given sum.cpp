/* Given two linked list of size N1 and N2 respectively of distinct elements, 
your task is to complete the function countPairs(), which returns the count 
of all pairs from both lists whose sum is equal to the given value X.
Note: The 2 numbers of a pair should be parts of different lists. */


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}

class Solution{
  public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        Node *temp1 = head1;
        Node *temp2 = head2;
        int count = 0;
        unordered_set<int> s;
        while(temp1!=NULL){
            s.insert(temp1->data);
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            if(s.find(x-(temp2->data))!=s.end()){
                count++;
            }
            temp2 = temp2->next;
        }
        return count;
        
        // while(temp1 != NULL){
        //     while(temp2 != NULL){
        //         int sum = temp1->data + temp2->data;
        //         cout<<sum<<" ";
        //         if(sum == x){
        //             count=count+1;
        //         }
        //         cout<<count<<endl;
        //         temp2 = temp2->next;
        //     }
        //     temp1 = temp1->next;
        // }
        // return count;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
} 
