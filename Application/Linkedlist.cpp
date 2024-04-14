#include<bits/stdc++.h>
using namespace std;
// *****************************************************Linked list
// class Node {
//     public:
//     int data;
//     Node* next;

// // Constructor
//     Node (int data) {
//     this->data = data;
//     this->next = NULL;
//    }
// };

// int main() {
//     Node* node1 = new Node(10);
//     cout << node1 -> data <<endl; 
//     cout << node1 -> next <<endl; 
//     return 0;
// }
// **************************************************Singly Linked list
// class Node {
//     public:
//     int data;
//     Node* next;

// // Constructor
//     Node (int data) {
//     this->data = data;
//     this->next = NULL;
//    }

// //    destructor
//    ~Node() {
//     int value = this -> data;
//     if(this-> next != NULL) {
//         delete next;
//         this->next = NULL;
//     } 
//     cout << " Memory is free for node with data " <<value <<endl;
//    }
// };

// void insertathead(Node* &head, int d)
// {
//     Node* temp = new Node(d);
//     temp->next= head ;
//     head = temp;
// }

// void insertattail(Node* &tail, int d)
// {
//     Node* temp = new Node(d);
//     tail -> next = temp;
//     tail = temp;
// }

// void print(Node* &head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<endl;
// }

// void insertatposition(Node* &tail, Node* &head, int position, int d)
// {
//     if (position == 1) {
//      insertathead(head, d);
//      return;
//     }

//     Node* temp = head;
//     int cnt = 1;

//     while(cnt < position-1) {
//         temp = temp -> next;
//         cnt++;
//     }
    
//     if(temp -> next == NULL){
//         insertattail(tail,d);
//         return;
//     }

//     Node* nodetoinsert = new Node(d);
//     nodetoinsert -> next = temp -> next;
//     temp -> next = nodetoinsert;
// }

// void deleteNode(int position, Node* & head) {
//     if(position == 1) {
//         Node* temp = head;
//         head = head -> next;
//         temp -> next = NULL;
//         delete temp;
//     }
//     else 
//     {
//         Node* curr = head;
//         Node* prev = NULL;

//         int cnt = 1;
//         while(cnt < position) {
//             prev = curr;
//             curr = curr -> next;
//             cnt++;
//         }

//         prev -> next = curr -> next;
//         curr -> next = NULL;
//         delete curr;
//     }
// }

// int main() {
//     Node* node1 = new Node(10);
//     // cout << node1 -> data <<endl; 
//     // cout << node1 -> next <<endl; 
//     Node* head = node1;
//     Node* tail = node1;
//     print(head);
//     insertattail(tail ,12 );
//     print(head);
//     insertattail(tail ,15 );
//     print(head);
//     insertatposition(tail,head,2,22);
//     print(head);
//     cout <<"head : "<<head -> data <<endl;
//     cout <<"tail : "<<tail -> data <<endl;
//     deleteNode(3, head);
//     print(head);
//     return 0;
// }
// ********************************************************Doubly Linked List*****************************
// class Node {
//     public:
//     int data;
//     Node* prev;
//     Node* next;

// // constructor
//     Node(int d) {
//         this -> data = d;
//         this -> prev = NULL;
//         this -> next = NULL;
//     }

// // destructor
//     ~Node() {
//         int val = this -> data;
//         if(next != NULL) {
//             delete next;
//             next = NULL;
//         }
//         cout << " memory free for node with data "<< val << endl;
//     }
// };

// // Traversing a linked list

// void print(Node* head) {
//     Node* temp = head;

//     while(temp != NULL) {
//         cout << temp -> data  << " ";
//         temp = temp -> next;
//     } 
//     cout <<endl;
// }

// // gives Length of Linked list
// int getLength(Node* head) {
//     int len = 0;
//      Node* temp = head;

//     while(temp != NULL) {
//         len++;
//         temp = temp -> next;
//     } 
//       return len;
// }

// void insertAtHead(Node* &tail, Node* &head, int d) {
//     // Empty list
//     if(head == NULL) {
//         Node* temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else {
//     Node* temp = new Node(d);
//     temp -> next = head;
//     head -> prev = temp;
//     head = temp;
//     }
// }

// void insertAtTail(Node* &tail, Node* &head, int d){
//     if(tail == NULL) {
//      Node* temp = new Node(d);
//      tail = temp;
//      head = temp;
//     }
//     else {
//     Node* temp = new Node(d);
//     tail -> next = temp;
//     temp -> prev = tail;
//     tail = temp;
//    }
// }

// void insertAtPosition(Node* &tail, Node* &head, int position, int d) 
//     {
//         // insert at Start
//     if (position == 1) {
//      insertAtHead(tail,head, d);
//      return;
//     }

//     Node* temp = head;
//     int cnt = 1;

//     while(cnt < position-1) {
//         temp = temp -> next;
//         cnt++;
//     }
    
//     // inserting at Last Position
//     if(temp -> next == NULL){
//         insertAtTail(tail,head,d);
//         return;
//     }

//     // creating a node for d
//     Node* nodetoinsert = new Node(d);
//     nodetoinsert -> next = temp -> next;
//     temp -> next -> prev = nodetoinsert;
//     temp -> next = nodetoinsert;
//     nodetoinsert -> prev = temp;
// }

// void deleteNode(int position, Node* & head) {
//     // deleting first and start node
//     if(position == 1) {
//         Node* temp = head;
//         temp->next->prev = head;
//         head = temp -> next;
//         temp -> next = NULL;
//         delete temp;
//     }
//     else 
//     {
//         // deleting any middle or last node
//         Node* curr = head;
//         Node* prev = NULL;

//         int cnt = 1;
//         while(cnt < position) {
//             prev = curr;
//             curr = curr -> next;
//             cnt++;
//         }

//         curr-> prev = NULL;
//         prev -> next = curr -> next;
//         curr -> next = NULL;
//         delete curr;
//     }
// }

// int main()
// {
//    Node* head = NULL;
//    Node* tail = NULL;
//    print(head);
// //    cout <<getLength(head) <<endl;
//    insertAtHead(tail,head, 11);
//    print(head);
//    cout << "head " << head -> data <<endl;
//    cout << "tail " << tail -> data <<endl;
//    insertAtHead(tail,head, 13);
//    print(head);
//    cout << "head " << head -> data <<endl;
//    cout << "tail " << tail -> data <<endl;
//    insertAtHead(tail,head, 8);
//    print(head);
//    cout << "head " << head -> data <<endl;
//    cout << "tail " << tail -> data <<endl;
//    insertAtTail(tail,head, 25);
//    print(head);
//    cout << "head " << head -> data <<endl;
//    cout << "tail " << tail -> data <<endl;
//    insertAtPosition(tail, head, 2, 100);
//    print(head);
//    cout << "head " << head -> data <<endl;
//    cout << "tail " << tail -> data <<endl;
//    insertAtPosition(tail, head, 1, 101);
//    print(head);
//    cout << "head " << head -> data <<endl;
//    cout << "tail " << tail -> data <<endl;
//    insertAtPosition(tail, head, 7, 102);
//    print(head);
//    cout << "head " << head -> data <<endl;
//    cout << "tail " << tail -> data <<endl;
//    deleteNode(7, head);
//    print(head);
//    cout << "head " << head -> data <<endl;
//    cout << "tail " << tail -> data <<endl;
//    return  0 ;
// }
// ******************************************************Circular Linked list********************
class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for note with data " << value << endl;
    }
};

void insertNode(Node* &tail, int element, int d) {
    if(tail == NULL){
     Node* newNode = new Node(d);
     tail = newNode;
     newNode-> next = newNode;
    }
    else {
        Node* curr = tail;
        while (curr -> data != element) {
            curr = curr -> next;
        }

        // element found -> curr is representing element node 
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void print(Node* tail) {
    Node* temp = tail;
    if(tail == NULL) {
        cout << " List is Empty " <<endl;
        return;
    }
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
        }
        while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value) {
    // empty list
    if(tail == NULL)
    {
        cout << " List is empty, please check again " <<endl;
        return;
    }
    else {
        Node* prev = tail;
        Node* curr = prev -> next;

        while (curr -> data != value)
        {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        // 1 Node Linked List

        if(curr == prev) {
            tail = NULL;
        }
        // >=2 Node Linked list
        else if(tail == curr) {
            tail = prev;
        }
        curr-> next = NULL;
        delete curr;
        
    }
}

bool isCircularlist(Node* head){
    if(head == NULL){
        return true;
    }
    Node* temp = head -> next;
    while(temp != NULL && temp != head) {
        temp = temp -> next;
    }
    if(temp == head){
        return true;
    }
    return false;
}

Node* floydcycleloop(Node* head){
    if (head == NULL)
    return NULL;
    // Find the meeting point in two pointers method.
    Node* slow = head;
    Node* fast = head;
    while( slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if(fast!=NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast)
        {
            cout <<" present is " << slow -> data <<endl;
            return slow;
        }
    }
    return NULL;
}

Node* getstartingNode(Node* head)
{
    if(head == NULL)
    return NULL;

    Node* intersection = floydcycleloop(head);
    Node* slow = head; 
    while(slow != intersection)
    {
     slow = slow -> next;
     intersection = intersection -> next;
    }
    return slow; 
}

Node* removeLoop(Node* head)
{
    if(head == NULL){
        return;
    }
    Node* startofloop = getstartingNode(head);
    Node* temp = startofloop;
    while(temp -> next != startofloop){
        temp = temp -> next;
    }
    temp -> next = NULL;
}

Node* UniqueSortedList(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr != NULL){
        if((curr -> next != NULL) curr -> data == curr -> next -> data) {
           Node* next_next = curr -> next -> next;
           Node* nodetodelete = curr -> next;
           delete(nodetodelete);
           curr -> next = next_next;
        }
        else (
            curr = curr -> next;
        )
    }
    return head;
}

Node* rotate(Node* head, int k)
{
        Node* curr = head;
        Node* forw = NULL;
        Node* last = NULL;
        while(curr!=NULL){
            last = curr;
            curr = curr->next;
        }
        curr = head;
        while(k--){
            last -> next = curr;
            forw = curr -> next;
            curr -> next = NULL;
            curr = forw;
            last = last -> next;
        }
        head = curr;
        return head;
}

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
       if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr != NULL){
        if((curr -> next != NULL) && curr -> data == curr -> next -> data) {
           Node* next_next = curr -> next -> next;
           Node* nodetodelete = curr -> next;
           delete(nodetodelete);
           curr -> next = next_next;
        }
        else {
            curr = curr -> next;
        }
    }
    return head;
    }
};

//********************************************************sorted linked list of 0's 1's 2'nd
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int countzero = 0;
        int countone = 0;
        int counttwo = 0;
        
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp -> data == 0)
            {
                countzero++;
            }
            else if(temp -> data == 1)
            {
                countone++;
            }
            else if(temp -> data == 2)
            {
                counttwo++;
            }
            temp = temp -> next;
        }
         temp = head;
         while(temp != NULL){
             if(countzero != 0)
             {
                temp -> data = 0;
                countzero--;
             }
             else if(countone != 0)
             {
                 temp -> data = 1;
                 countone--;
             }
             else if(counttwo != 0)
             {
                 temp -> data = 2;
                 counttwo--;
             }
             temp = temp -> next;
         }
        return head;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    // insertNode(tail, 7, 9);
    // print(tail);
    // insertNode(tail, 5, 6);
    // print(tail);
    // insertNode(tail, 9, 10);
    // print(tail);
    // insertNode(tail, 3, 4);
    // print(tail);
    // deleteNode(tail, 3);
    // print(tail);
    // if(isCircularlist(tail))
    // {
    //     cout <<" list is circular " <<endl;
    // }
    // else{
    //     cout <<" list is not circular " <<endl;
    // }
    remove(head);
    print(head);
    if(floydcycleloop(head)!=NULL)
    {
        cout <<" cycle is present " <<endl;
    }
    else{
        cout <<" cycle is not " <<endl;
    }
    Node* loop = getstartingNode(head);
    cout<<" staring at " << loop -> data <<endl;
    return 0;
}
// *******************************************************************Palindrome
class solution {
    private:
    Node* getMid(Node* head)
    {
        Node* slow = head;
        Node* fast = fast -> next;
        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    Node* reverse(Node* head){
        Node* curr = head;
        Node* next = NULL;
        Node* prev = NULL;
        while(curr != NULL)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    public:
    bool palindrome(Node *head){
        if (head == NULL || head->next==NULL )
        return true;
        Node* middle = getMid(head);
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        Node* head1 = head;
        Node* head2 = middle -> next;
        while(head2 != NULL)
        {
            if(head1 -> data != head2 -> data)
            {
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        temp = middle -> next;
        middle -> next = reverse(temp);
        return true;
    }
}
// ***********************************************************Clone a linked list with next and random pointer
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        unordered_map<Node*, Node*> hashMap;
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->data);
            hashMap[temp] = newNode;
            temp = temp->next;
        }
        Node* t = head;
        while(t){
            Node* node = hashMap[t];
            node->next = (t->next != NULL) ? hashMap[t->next] : NULL;
            node->arb = (t->arb != NULL) ? hashMap[t->arb] : NULL;
            t = t->next;
        }
        return hashMap[head];
    }

};
void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}
void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool validation(Node *head, Node *res) {
    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }
    if (len1 != len2) return false;
    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}
int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!correction
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* findMid(Node* &head) {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    Node* mergesort(Node* right, Node* left){
        if (left == NULL){
            return right;
        }
        if (right == NULL) {
            return left;
        }
        Node* ans = new Node(-1);
        Node* temp = ans;
        while(right != NULL && left != NULL)
        {
            if(left -> data < right -> data){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else {
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }
        while(left != NULL){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        while(right != NULL){
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
        ans = ans -> next;
        return ans;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        Node* mid = findMid(head);
        Node* left = head;
        Node* right = mid -> next;
        mid -> next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        Node* result = mergeSort(left, right);
        return result; 
    }
};