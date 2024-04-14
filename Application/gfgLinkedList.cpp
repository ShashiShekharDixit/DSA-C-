#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 
// struct Node {
//     int data;
//     Node* next;
    
//     Node(int x){
//         data = x;
//         next = NULL;
//     }
    
// }; 
class Solution{
    public:
    int getMiddle(Node *head)
    {
        Node* slow = head;
        Node* fast = head;
        int i = 0;
        while(fast!= NULL && fast -> next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};
int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }       
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}
// **************************************
    struct Node* reverseList(struct Node *head)
    {
        if (head == NULL || head -> next == NULL){
            return NULL;
        }
        
        Node* prev = NULL;
        Node* curr = head;
        Node* farward = NULL;
        
        while(curr != NULL)
        {
            farward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = farward;
        }
        return prev;
    }
// *************************************************7/10
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
       
        struct Node *temp = head, *first = head,*second = head;
        int s = 0;
        while(second->next != NULL)
        {
            first = second->next;
            second->next = first->next;
            first->next = second;
            if(s == 0)
              head = first;
            if(s != 0)
            {
                temp->next = first;
                temp = second;
            }
            second = second->next;
            first = second;
            if(second == NULL)
            break;
            s = 1;
        }
            return head;
        
    }
};
// ********************************************************Middle Linked List
Node* insertInMiddle(Node* head, int x)
{
    Node *slow = head , *fast=head;
    Node *temp = new Node(x);
    if(head == NULL) return temp;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = slow->next;
    slow->next = temp;
    return head;
}
// **************************************************Reverse a string by k group
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head == NULL){
            return NULL;
        }
        node *prev = NULL;
        node *curr = head;
        node *next = NULL;
        int count = 0;
        
        while( curr != NULL && count < k)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next != NULL)
        {
            head -> next = reverse(next, k);
        }
        
        return prev;
    }
};
// *****************************************************Doubly reverse Linked List
Node* reverseDLL(Node * head)
{
    //Your code here
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* curr = head;
    Node* back = NULL;
    Node* forward = NULL;
    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = curr->prev;
        curr->prev = forward;
        back = curr;
        curr = forward;
    }
    return back;
}
// ****************************************************************09/10
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
         return solve(node);
    }
    
    int solve(struct Node* root){
        if(root==NULL)  return 0;
        return max(1 + solve(root->right),1 + solve(root->left));
    }
};