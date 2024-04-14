// *************************************************Reverse Linked List
#include<bits/stdc++.h>
using namespace std;
// struct Node {
//     int data;
//     struct Node* next;
//     Node(int data)
//     {
//      this -> data = data;
//      next = NULL;
//     }
// };
// struct LinkedList {
//     Node* head;
//     LinkedList() {
//         head = NULL;
//     }
//     void reverse()
//     {
//         Node* current = head;
//         Node* prev = NULL, *next = NULL;
//         while(current != NULL) {
//          next = current -> next;
//          current -> next = prev;
//          prev = current;
//          current = next;
//         }
//         head = prev;
//     }
//     void print()
//     {
//         struct Node* temp = head;
//         while (temp != NULL) {
//             cout << temp -> data << " ";
//             temp = temp -> next;
//         }
//     }
//     void push(int data)
//     {
//         Node* temp = new Node(data);
//         temp -> next = head;
//         head = temp;
//     }
// };
// int main()
// {
//     LinkedList ll;
//     ll.push(20);
//     ll.push(45);
//     ll.push(15);
//     ll.push(85);
//     cout <<"Given linked list \n";
//     ll.print();
//     ll.reverse();
//     cout <<" \nReversed linked list \n";
//     ll.print();
//     return 0;
// }
// *******************************************************Cycle in Linked List
// struct Node {
//     int data;
//     struct Node* next;
// };
// void push(struct Node** head_ref, int new_data)
// {
//     struct Node* new_node = new Node;
//     new_node -> data = new_data;
//     new_node -> next = (*head_ref);
//     (*head_ref) = new_node;
// }
// bool detectLoop(struct Node* h)
// {
//     unordered_set<Node*> s;
//     while(h != NULL) {
//         if(s.find(h) != s.end())
//         return true;
//         s.insert(h);
//         h = h -> next;
//     }
//     return false;
// }
// int main()
// {
//     struct Node* head = NULL;
//     push(&head, 20);
//     push(&head, 4);
//     push(&head, 15);
//     push(&head, 10);
//     head -> next -> next -> next = head;
//     if(detectLoop(head))
//     cout <<" Loop found ";
//     else
//     cout <<" No Loop ";
//     return 0;
// }
// ***************************************************Merge sorted
// void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
// {
//     int i = 0, j = 0, k = 0;
//     while(i < n1) {
//         arr3[k++] = arr1[i++];
//     }
//     while(j < n2) {
//         arr3[k++] = arr2[j++];
//     }
//     sort(arr3, arr3+n1+n2);
// }
// int main()
// {
//     int arr1[] = {1,3,5,7};
//     int n1 = sizeof(arr1)/sizeof(arr1[0]);
//     int arr2[] = {2,4,6,8};
//     int n2 = sizeof(arr2)/ sizeof(arr2[0]);
//     int arr3[n1+n2];
//     mergeArrays(arr1, arr2, n1, n2, arr3);
//     cout << " Array after merging " <<endl;
//     for (int i =0; i < n1 + n2; i++)
//     cout << arr3[i] << " ";
//     return 0;
// }
// *************************************************************Delete a node without head pointer
// struct Node {
//     int data;
//     struct Node* next;
// };
// void deleteNodeWithoutHead(struct Node* pos)
// {
//     if(pos == NULL)
//     return;
//     else {
//         if(pos -> next == NULL) {
//             printf("This is last node, require head, can't " " be freed\n");
//             return;
//         }
//         struct Node* temp = pos -> next;
//         pos -> data = pos -> next -> data;
//         pos -> next = pos -> next -> next;
//         free(temp);
//     }
// }
// void print(Node* head) {
//     Node* temp = head;
//     while(temp) {
//         cout << temp -> data << " -> ";
//         temp = temp -> next;
//     } 
//     cout << " NULL ";
// }
// void push(struct Node** head_ref, int new_data)
// {
//     struct Node* new_node = new Node();
//     new_node-> data = new_data;
//     new_node -> next = (*head_ref);
//     (*head_ref) = new_node;
// }
// int main()
// {
//     struct Node* head = NULL;
//     push(&head, 20);
//     push(&head, 4);
//     push(&head, 15);
//     push(&head, 35);
//     cout << " Initial Linked lIst: \n";
//     print(head);
//     cout << endl <<endl;
//     Node* del = head -> next;
//     deleteNodeWithoutHead(del);
//     cout <<" Final Linked list after deletion of 15: \n";
//     print(head);
//     return 0;
// }
// *******************************************************Sort a linked list of 0s, 1s and 2s
// class Node {
//     public :
//     int data;
//     Node* next;
// };
// void sortList(Node *head)
// {
//     int count[3] = {0, 0, 0};
//     Node *ptr = head;
//     while (ptr != NULL)
//     {
//         count[ptr -> data] += 1;
//         ptr = ptr -> next;
//     }
//     int i = 0;
//     ptr = head;
//     while (ptr != NULL)
//     {
//         if(count[i] == 0)
//         ++i;
//         else{
//           ptr -> data = i;
//           --count[i];
//           ptr = ptr -> next;
//         }
//     }
// }
// void push (Node** head_ref, int new_data)
// {
//     Node* new_node = new Node();
//     new_node -> data = new_data;
//     new_node -> next = (*head_ref);
//     (*head_ref) = new_node; 
// }
// void printList(Node *node)
// {
//     while (node != NULL)
//     {
//         cout << node -> data << " ";
//         node = node -> next;
//     }
//     cout << endl;
// }
// int main()
// {
//     Node *head = NULL;
//     push(&head, 0);
//     push(&head, 1);
//     push(&head, 0);
//     push(&head, 2);
//     push(&head, 1);
//     push(&head, 1);
//     push(&head, 2);
//     push(&head, 1);
//     push(&head, 2);

//     cout << " Linked List before Sorting\n ";
//     printList(head);
//     sortList(head);
//     cout << " Linked List after Sorting \n";
//     printList(head);
//     return 0;
// }
// **************************************************Multiply two numbers represented by linked lists
// struct Node
// {
//     int data;
//     struct Node* next;
// };
// struct Node *newNode(int data)
// {
//     struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
//     new_node -> data = data;
//     new_node -> next = NULL;
//     return new_node;
// }
// void push(struct Node** head_ref, int new_data)
// {
//     struct Node* new_node = newNode(new_data);
//     new_node->next = (*head_ref);
//     (*head_ref) = new_node;
// }
// long long multiplyTwoLists (Node* first, Node* second)
// {
//     long long N = 1000000007;
//     long long num1 = 0, num2 = 0;
//     while (first || second)
//     {
//         if(first){
//             num1 = ((num1)*10)%N + first -> data;
//             first = first -> next;    
//         }
//         if(second)
//         {
//             num2 = ((num2)*10)%N + second -> data;
//             second = second -> next;
//         }
//     }
//     return ((num1 % N)*(num2%N))%N;
// }
// void printList(struct Node *node)
// {
//     while(node != NULL)
//     {
//         cout << node -> data;
//         if(node -> next)
//         cout << "->";
//         node = node -> next;
//     }
//     cout << "\n";
// }
// int main()
// {
//     struct Node* first = NULL;
//     struct Node* second = NULL;
//     push(&first, 6);
//     push(&first, 4);
//     push(&first, 9);
//     printf("First List is: ");
//     printList(first);
//     push (&second ,5 );
//     push (&second ,3 ) ;
//     printf("Second List is: ");
//     printList(second);
//     cout << " Result is : ";
//     cout << multiplyTwoLists(first, second);
//     return 0;
// }
// *********************************************Remove Nth node from the end of the linked list
// struct Node {
//     int data;
//     struct Node* next;
//     Node(int value)
//     {
//      this -> data = value;
//      this -> next = NULL;
//     }
// };
// int length(Node* head)
// {
//     Node* temp = head;
//     int count = 0;
//     while(temp != NULL) {
//         count++;
//         temp = temp -> next;
//     }
//     return count;
// }
// void printList(Node* head)
// {
//     Node* ptr = head;
//     while (ptr!=NULL){
//      cout << ptr -> data <<" ";
//      ptr = ptr -> next;
//     }
//     cout << endl;
// }
// Node* removenthNodeFromend(Node* head, int n)
// {
//     int Length = length(head);
//     int nodefromBeginning = Length - n + 1;
//     Node* prev = NULL;
//     Node* temp = head;
//     for (int i =1; i < nodefromBeginning; i++)
//     {
//         prev = temp;
//         temp = temp -> next;
//     }
//     if(prev == NULL) {
//         head = head -> next;
//         return head;
//     }
//     else {
//         prev -> next = prev -> next -> next;
//         return head;
//     }
// }
// int main()
// {
//     Node* head = new Node(1);
//     head -> next = new Node(2);
//     head -> next-> next = new Node(3);
//     head -> next -> next -> next = new Node (4);
//     head -> next -> next -> next -> next = new Node(5);
//     cout <<" Linked List before Deletion: " <<endl;
//     printList(head);
//     head = removenthNodeFromend(head, 4);
//     cout <<" Linked List after Deletion: " <<endl;
//     printList(head);
//     return 0;
// }
********************************************