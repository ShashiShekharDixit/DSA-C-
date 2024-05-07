// **************************************************************potd on 20/09
vector <int> rotate (int n, int d)
{
vector<int>ans;
d=d%16;
int bits[16];
int i, j;
for(int i =0; i <16; i++) {
bits[i] = n%2;
n/=2;
}
int sum = 1;
int left = 0, right = 0; 
for(i=(16-d)%16,j=0;j<16;j++,i=(i+1)%16) {
    if(bits[i] == 1){
        left = left + sum;
    }
    sum = sum * 2;
}
sum = 1;
for(i=d,j=0;j<16;j++, i =(i+1)%16) {
    if(bits[i] == 1) {
        right = right + sum;
    }    
    sum = sum*2;
}
ans.push_back(left);
ans.push_back(right);

return ans;
}
// ***************************************************************potd on 22/09
class Solution
{
    public:
    int searchFirst(int arr[], int start, int end, int x){
        int ans = -1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(arr[mid] == x) {
                ans = mid;
                end = mid-1;
            }else if(arr[mid] < x) {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }
        return ans;
    }
    int searchLast(int arr[], int start, int end, int x){
        int ans = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(arr[mid] == x) {
                ans = mid;
                start = mid + 1;
            }else if(arr[mid] < x) {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        vector<int>ans;
        int first = searchFirst(arr,0,n-1,x);
        int last = searchLast(arr,0,n-1,x);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// **********************************************************Potd of 23/09
class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
      if(n == 1) {
          return 1;
      }
      long long sum = 0;
      for(int i =0; i < n; i++){
          sum += a[i];
      }
      long long leftSum = 0;
      long long rightSum;
      for(int i = 1; i < n; i++) {
          leftSum += a[i-1];
          rightSum = sum - a[i] - leftSum;
          if(leftSum == rightSum) {
              return i+1;
          }
      }
      return -1;
    }
};
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// ************************************************************Merge sort on doubly linked lists
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
class Solution {
  public:
    struct Node *sortDoubly(struct Node *head) {
        vector<int> num;
        struct Node *temp = head;
        while(temp != NULL){
            num.push_back(temp -> data);
            temp = temp -> next;
        }
        sort(num.begin(), num.end());
        
        temp = head;
        int ind = 0;
        while(temp){
            temp -> data = num[ind++];
            temp = temp -> next;
        }
        return head;
    }
};
void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}
// ******************************************************************************Delete Middle Linked List
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        Node* slow = head;
        Node* fast = head -> next;
        Node* prev = NULL;
        while(fast != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
            if(fast!=NULL){
                fast = fast -> next;
            }
        }
        Node* temp = slow -> next;
        prev -> next = temp;
        slow -> next = NULL;
        delete slow;
        return head;
    }
};
// *********************************************************************************Remove every Kth Node
class Solution {
    public:
    Node* deleteK(Node *head,int K){
      if(head==NULL or K == 1){
          return NULL;
      }
      Node* temp1 = head;
      Node* temp2 = head;
      int p = K - 1;
      int k = K - 1;
      while(temp1){
          if(k > 0){
              temp2 = temp1;
              k--;
          }
          else {
              k = p;
              temp2 -> next = temp1 -> next;
          }
          temp1 = temp1 -> next;
      }
      return head;
    }
};
// *********************************************************Add two numbers represented by Linked list
class Solution
{
    public:  
    Node* func(Node* num1, Node* num2, int c){
        if(!num1 and !num2) return new Node(c); 
        int sum = (num1 ? num1->data : 0) + (num2 ? num2->data : 0) + c;
        Node* nn = new Node(sum % 10); 
        nn->next = func((num1 ? num1->next : num1), (num2 ? num2->next : num2), sum / 10);
        return nn;
    }
    
    Node* rev(Node* head){
        Node* tmp = NULL, *prev = NULL, *curr = head;
        while(curr) tmp = curr->next, curr->next = prev, prev = curr, curr = tmp;
        return prev;
    }
    Node* rz(Node* head){
        while(head and head->data == 0) head = head->next;
        return head == NULL ? new Node(0) : head;
    }
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2){   
        return rz(rev(func(rev(rz(num1)), rev(rz(num2)), 0))); 
    }
};
// ********************************************************Arrange the vowels and constants
class Solution {
  public:
    bool is_vowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
        return false;
    }
    struct Node* arrangeCV(Node* head) {
        Node* vowels = new Node('#');
        Node* cons = new Node('#');
        Node* tail = vowels;
        Node* temp = cons;
        while(head){
            if(is_vowel(head -> data)){
                tail -> next = new Node(head -> data);
                tail = tail -> next;
            }
            else {
                temp -> next = new Node(head -> data);
                temp = temp ->  next;
            }
            head = head -> next;
        }
        if(tail)
        tail -> next = cons -> next;
        if(tail)
        return vowels -> next;
        return cons -> next;
    }
};
// ***********************************************************Serilize and deserialize a binary tree
class Solution
{
    void inorder(Node *root, vector<int> &store){
        if(root == NULL)
            return;
            
        inorder(root->left, store);
        store.push_back(root->data);
        inorder(root->right, store);
    }
    
    public:
    vector<int> serialize(Node *root) 
    {
        vector<int> str;
        inorder(root, str);
        return str;
    }
    
    Node * deSerialize(vector<int> &A)
    {
        int n = A.size();
        Node *root = new Node(A[0]);
        
        for(int i=1; i<n; i+=2){
            Node *newRoot = new Node(A[i]);
            newRoot->left = root;
            if(i+1 < n){
                newRoot->right = new Node(A[i+1]);
            }
            root = newRoot;
        }
        return root;
    }

};
// ******************************************************************Kth distance from root
class Solution
{
    public:
    vector<int> Kdistance(struct Node *root, int k)
    {
      queue<struct Node*> nodes;
      vector<int> data;
      nodes.push(root);
      while(!nodes.empty()){
          if(k == 0){
              while(!nodes.empty()){
                  struct Node* node = nodes.front();
                  nodes.pop();
                  data.push_back(node -> data);
              }
              break;
          }
          else {
              int size = nodes.size();
              while(size--){
                  struct Node* node = nodes.front();
                  nodes.pop();
                  if(node -> left)
                  nodes.push(node -> left);
                  if(node -> right)
                  nodes.push(node -> right);
              }
              k--;
          }
      }
      return data;
    }
};
// ******************************************************(Contruct Binary Tree from Inorder and Postorder)
class Solution
{
    public:

   Node *f(int post[],int poststart,int postend,int in[],int instart,
    int inend,unordered_map<int,int>&mp)
    {
        if (poststart>postend or instart>inend) return NULL;
        
        Node *root=new Node(post[postend]);
        int element=mp[root->data];
        int nelements=element-instart;
        root->left=f(post,poststart,poststart+nelements-1,
        in,instart,element-1,mp);
        root->right=f(post,poststart+nelements,postend-1,in
        ,element+1,inend,mp);
        
        return root;
    }
    
    Node *buildTree(int in[], int post[], int n) {        
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        return f(post,0,n-1,in,0,n-1,mp);
    }
};
// ********************************************************(Vertical Sum)
class Solution{
  public:
  int mn, mx;
  vector<int> ans;
  void calc(Node* root, int level){
      if(!root) return;
      mn = min(mn, level);
      mx = max(mx, level);
      calc(root -> left, level - 1);
      calc(root -> right, level + 1);
  }
  void calculate(Node* root, int level){
      if(!root) return;
      ans[abs(mn) + level] += root -> data;
      calculate(root -> left, level - 1);
      calculate(root -> right, level + 1);
  }
    vector <int> verticalSum(Node *root) {
        mn = 0;
        mx = 0;
        calc(root, 0);
        ans.resize(mx - mn + 1, 0);
        calculate(root, 0);
        return ans;
    }
};
// ***********************************************************06/05
vector<int> noSibling(Node* node)
{
   queue<Node*> q;
   vector<int> ans;
   if(node == NULL){
       return ans;
    }
   q.push(node);
   while(q.empty() == false){
       Node* curr = q.front();
       q.pop();
       if(curr->left != NULL){
           if(curr->right == NULL){
               ans.push_back(curr->left->data);
           }
           q.push(curr->left);
       }
       if(curr->right != NULL){
           if(curr->left == NULL){
               ans.push_back(curr->right->data);
           }
           q.push(curr->right);
       }
   }
   if(ans.size() == 0){
       return {-1};
   }
   else{
       sort(ans.begin(), ans.end());
       return ans;
   }
}
// ***********************************************************07/05
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
   
    while(!q.empty())
    {
        Node * cur = q.front();
        q.pop();
        ans.push_back(cur->data);
        if(cur->right!=nullptr)
        {
            q.push(cur->right);
        }
        if(cur->left!=nullptr)
        {
            q.push(cur->left);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}