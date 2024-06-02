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
// ************************************************************08/05
class Solution {
     private:
    void findingPaths(Node *root, vector<vector<int>> &paths, vector<int> &path){
        if(root == NULL)
            return;
        
        path.push_back(root->data);
        
        if(root->left == NULL && root->right == NULL)
            paths.push_back(path);
            
        findingPaths(root->left, paths, path);
        findingPaths(root->right, paths, path);
        
        path.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
    vector<vector<int>> paths;
        vector<int> path;
        
        findingPaths(root, paths, path);
        
        return paths;
    }
};
// **************************************************************09/05
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution obj;
        bool ans = obj.divisorGame(n);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// *****************************************************************10/05
class Solution{
public:
    vector<vector<int>> ans;
    void solve(vector<int>& arr, int index, vector<int>& path, long long sum, int k)
    {
        if(sum >= k){
            if(sum == k)
            ans.push_back(path);
            return;
        }
        if(index >= arr.size())
        {
          return;            
        }
        path.push_back(arr[index]);
        solve(arr, index + 1, path, sum + arr[index], k);
        path.pop_back();
        while(index + 1 < arr.size() && arr[index] == arr[index + 1])
        index++;
        solve(arr, index + 1, path, sum, k);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(), arr.end());
        vector<int> path;
        long long sum = 0;
        solve(arr, 0, path, sum, k);
        return ans;
    }
};
// *******************************************************************11/05(Juggler Sequence)
class Solution {
  public:
    vector<long long> ans;
    map<long long, long long>mp;
    int recur(long long x){
        if(x <= 1) return 0;
        if(mp[x] != 0) return mp[x];
        mp[x] = 1;
        if(x % 2 == 0){
            x = sqrt(x);
            ans.push_back(x);
            return recur(x);
        }
        if(x % 2 == 1){
            x = x * sqrt(x);
            ans.push_back(x);
            return recur(x);
        }
    }
    vector<long long> jugglerSequence(long long n) {
        // code here
        ans.push_back(n);
        int dummy = recur(n);
        return ans;
    }
};
// ********************************************************************12/05(Minimum steps to destination)
class Solution {
  public:
    int minSteps(int d) {
        // code here
        int sum = 0, steps = 0, i = 0;
        while(sum < d){
            sum += steps;
            steps++;
        }
        while((sum-d)%2 == 1){
            sum += steps;
            steps++;
        }
        return steps-1;
    }
};
// ***********************************************************************13/05(Number of good components)
class Solution {
  public:
    void dfs (unordered_map<int,vector<int>>&adj, int i, vector<int>&vis, vector<int>&temp)
    {
        temp.push_back(i);
        vis[i]++;
        
        for (auto it:adj[i])
        {
            if (!vis[it])
                dfs(adj,it,vis,temp);
        }
    }
    int find(int v,unordered_map<int,vector<int>>&adj){
     vector<int>vis(v+1,0);
        int ans = 0;
        for (int i=1; i<=v; i++)
        {
            if (!vis[i])
            {
                vector <int> temp;
                dfs(adj,i,vis, temp);
                bool flag = true;
                for (int i=0; i<temp.size(); i++)
                {
                    if (adj[temp[i]].size()<temp.size()-1)
                    {
                        flag = false;
                        break;
                    }
                }       
                if (flag)
                    ans++;
            }
        }
        return ans;
}
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return find(v,adj);
    }
};
// *************************************************************************14/05(Path with Maximum Efforts)
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        int mini = INT_MAX;
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        vector<vector<int>> visited(rows, vector<int>(columns, 0));
        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            int maxi = temp[0];
            int r = temp[1];
            int c = temp[2];
            if(r == rows-1 and c== columns-1)
                return maxi;
            if(visited[r][c])
                continue;
            visited[r][c] =1;
            for(int i=0;i<4;i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 and nr<rows and nc>=0 and nc<columns  && !visited[nr][nc])
                {
                    int t = abs(heights[r][c] - heights[nr][nc]);
                    t = max(t,maxi);
                    pq.push({t,nr,nc});
                }
            }
        }
        return 0;
    }
};
// **********************************************************15/05(Account Merge)
class DisjointSet{
    public:
	    vector<int> rank,parent;
	    DisjointSet(int n){
	        rank.resize(n+1,0);
	        parent.resize(n+1);
	        for(int i=0;i<=n;i++)parent[i]=i;
	    }
	    int findUpar(int node){
	        if(node==parent[node])return node;
	        return parent[node]=findUpar(parent[node]);
	    }
	    void Unionbyrank(int u,int v){
	        int u_v=findUpar(u);
	        int u_u=findUpar(v);
	        if(u_v==u_u)return;
	        if(rank[u_v]>rank[u_u])parent[u_u]=u_v;
	        else if(rank[u_v]<rank[u_u])parent[u_v]=u_u;
	        else{
	            parent[u_v]=u_u;
	            rank[u_u]++;
	        }
	    }
	};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int  n=accounts.size();
        unordered_map<string,int> helper;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(helper.find(mail)==helper.end())helper[mail]=i;
                else ds.Unionbyrank(i,helper[mail]);
                
            }
        }
        vector<vector<string>> ans;
        vector<string> merged[n];
        for(auto it:helper){
            string mail=it.first;
            int node=ds.findUpar(it.second);
            merged[node].push_back(mail);
        }
        for(int i=0;i<n;i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// ***************************************************************16/05(Divisibility Tree)
class Solution {
    int components  = 0 ; 
    int  dfs( int src, vector<bool>&visited, vector< int> graph[]  )
    {
         visited[ src] = true;
         int count = 1 ;
         for ( auto adj  : graph [ src ] )
         {
            if ( visited[ adj]==  true )
                continue;
            int res = dfs( adj , visited, graph  );
            if( res %2 == 0 )
            {
                components ++;
            }
            else 
            {
                count += res ;
            }
         }
         return count;
    }
public:
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        vector< int > graph[ n +1 ];
        for ( auto it: edges )
        {
            graph[it[0]].push_back( it[1]);
            graph[it[1]].push_back ( it[0]);
        }
        vector< bool>visited( n + 1 , false ) ;
        dfs ( 1 , visited, graph );
        return components;
    }
};
// ****************************************************************17/05(Find Pair Given Difference)
class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
            for (int i = 0; i < n; ++i) {
            int find = arr[i] - x;
            if (binary_search(arr.begin(), arr.end(), find)) {
                if (find == arr[i] && x == 0) {
                    int lb = lower_bound(arr.begin(), arr.end(), find) - arr.begin();
                    if (lb != i) return 1;
                } else {
                    return 1;
                }
            }
        }
        return -1;
    }
};
// *****************************************************************18/05(Find the highest Number)
class Solution() {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        for(int i = 1; i < a.size() - 1; i++){
            if(a[i] > a[i + 1] && a[i] > a[i - 1]){
                return a[i];
            }
        }
        return max(a[0], a[a.size() - 1]);
    }
};
// ********************************************************************19/05(Find the Closest One)
class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    {
        int x=lower_bound(arr, arr+n, k)-arr;
        
        if(x!=0 && (x==n || k-arr[x-1]<arr[x]-k))
        return arr[x-1];
        
        return arr[x];
    }
};
// **********************************************************************20/05(Mudular Exponential for a large number)
class Solution{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    if(n == 0) return 1;
		    long long int result = 1;
		    while(n > 0){
		        if(n % 2 == 1){
		            result = (result * x) % M;
		        }
		        x = (x * x) % M;
		        n /= 2;
		    }
		    return result;
		}
}
// **************************************************************************21/05(K closest Element)
class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int id1 = findCrossOver(arr, 0, n - 1, x);
        int id2 = id1 + 1;
        if (arr[id1] == x) id1--;
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            if (id1 >= 0 && id2 < n) {
                int val1 = x - arr[id1], val2 = arr[id2] - x;
                if (val1 < val2) {
                    ans[i] = arr[id1];
                    id1--;
                } else {
                    ans[i] = arr[id2];
                    id2++;
                }
            } else if (id1 >= 0) { 
                ans[i] = arr[id1];
                id1--;
            } else { 
                ans[i] = arr[id2];
                id2++;
            }
        }
        return ans;
    }
private:
    int findCrossOver(vector<int>& arr, int low, int high, int x) {
        if (arr[high] <= x) {
            return high;
        }
        if (arr[low] > x) {
            return low;
        }
        int mid = (low + high) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        } 
        else if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, high, x);
        }
        return findCrossOver(arr, low, mid - 1, x);
    }
};
// ****************************************************************************22/05(Minimize Max Distance to Gas Station)
class Solution {
public:
{
        int n = stations.size();
        double l = 0, r = 1e8;
        double ans;
        auto check = [&](double mid) -> bool {
            int cnt = 0;
            for (int i = 0; i < n - 1; i++) {
                double dist = stations[i + 1] - stations[i];
                cnt += ceil(dist / mid)-1;
            }
            return cnt <= k;
        };
        while(r-l > 1e-6)
        {
            double mid = (l+r)/2;
            if(check(mid))
            {
                ans = mid;
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return ans;
    }
};
// ***********************************************************************Kth Palindrome(23/05)
class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        vector<int> curr(n + 1, 0), ahead(n + 1, 0);
        for(int x = n - 1; x >= 0; x--){
            for(int y = n - 1; y >= 0; y--)
            curr[y] = max({ahead[y],curr[y + 1], (str[x]==str[n - y - 1])?1 + ahead[y + 1]:0});
            ahead = curr;
        }
        return n - curr[0] <= k;
    }
};
// ***************************************************************************Partition with Given Difference(24/05)
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        count = 0;
        explore(nums, k, 0);
        return count -1;
    }
    private:
    int count;
    unordered_map<int, int> visited;
    void explore(vector<int>& nums, int k, int index){
        if(index == nums.size()){
            count++;
            return;
        }
        int num = nums[index];
        if(visited.find(num - k) == visited.end() && visited.find(num + k) == visited.end()) {
            visited[num]++;
            explore(nums, k, index + 1);
            visited[num]--;
            if(visited[num] == 0){
                visited.erase(num);
            }
        }
        explore(nums, k, index + 1);
    }
};
// ***************************************************************************You ans Yours Books(25/05)
class Solution {
  public:
    long long max_Books(int arr[], int n, int k) {
        long long sum = 0;
        long long maxsum = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i]<= k)
            {
                sum = sum + arr[i];
            }
            else if(arr[i]>k)
            {
                sum = 0;
            }
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
}; 
// **********************************************************************Minimum Cost to make two string Identical(26/05)
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        int n = x.size(), m = y.size();
        vector<int>prev(m + 1, 0), curr(m + 1, 0);
        for(int i = 1; i <= m; i++){
            prev[i] = costY*i;
        }
        for(int i = 0; i < n; i++){
            curr[0] = ((i + 1)*costX);
            for(int j = 0; j < m; j++){
                if(x[i]==y[j]){
                    curr[j + 1]= prev[j];
                }
                else {
                    curr[j + 1]= min(costX + prev[j + 1], costY + curr[j]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
// ***********************************************************************Longest Subsequence I(27/05)
class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        function<int(int, int)> rec = [&](int i, int p) -> int {
            if(i == n) return 0;
            if(p != -1 && dp[i][p] != -1) return dp[i][p];
            int tk = 0, nt = rec(i + 1, p);
            if(p == -1 || abs(a[i] - a[p]) == 1) tk = 1 + rec(i + 1, i);
            if(p == -1) return max(tk, nt);
            return dp[i][p] = max(tk, nt);
        };
        return rec(0, -1);
    }
};
// ***********************************************************************Minimum cost to fill given weight in a bag(28/05)
class Solution {
  public:
  int help(int n, int w, vector<int> &cost, vector<int>&dp){
      if(w == 0) return 0;
      if(dp[w]!=-1) return dp[w];
      int ans = INT_MAX;
      for(int i = 1; i <= min(n, w); i++)
      {
          ans = min(ans, help(n, w - i, cost, dp)+cost[i-1]);
      }
      return dp[w] = ans;
  }
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<int>dp(w+1, -1);
        int ans = help(n,w,cost,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
// ********************************************************************Geek ans its Game of Coins(29/05)
class Solution {
  public:
    int solve(int n, int x, int y, vector<int> &dp)
    {
        if(n <= 1)
        return n;
        if(dp[n] != -1)
        return dp[n];
        int ans = 1;
        if(n >= x)
        ans &= solve(n - x, x, y, dp);
        if(n >= y)
        ans &= solve(n - y, x, y, dp);
        ans &= solve(n - 1, x, y, dp);
        return dp[n] = ans ^ 1;
    }
    int findWinner(int n, int x, int y) {
        vector<int> dp(n + 1, -1);
        return solve(n, x, y, dp);
    }
};
// ***********************************************************************String Sequence(30/05)
const int mod=1e9+7;
class Solution {
    public:
    int solve(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        if(ind2<0){
            return 1;
        }
        if(ind1<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2]%mod;
        }
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]=(solve(ind1-1,ind2-1,s1,s2,dp)%mod+solve(ind1-1,ind2,s1,s2,dp)%mod)%mod;
        }
        return dp[ind1][ind2]=solve(ind1-1,ind2,s1,s2,dp)%mod;
    }
    
    int countWays(string &s1, string &s2) {
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s1,s2,dp)%mod;
    }
};
// *******************************************************************Swap two nibbles in a byte(31/05)
class Solution {
  public:
    int swapNibbles(int n) {
        int a = n&15;
        int b = n&240;
        b = b >> 4;
        a = a << 4;
        return a + b;
    }
};
// *********************************************************************Odd Even Problem(01/06)
class Solution {
  public:
    string oddEven(string s) {
        vector<int> freq(26, 0);
        for(auto &c: s)
        freq[c-'a']++;
        int ans = 0;
        for(int i = 1; i <= 26; i++)
        {
            if(freq[i - 1] == 0)
            continue;
            if((i%2) ^ (freq[i - 1]% 2) == 0)
            ans++;
        }
        if(ans % 2 != 0) return "ODD";
        return "EVEN";
    }
};
// **************************************************************************Construct list using given q XOR queries(02/06)
class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        int n=queries.size();
        int last=-1;
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1){
                last=i;
            }
        }
        if(last==-1){
            for(int i=0;i<n;i++){
                ans.push_back(queries[i][1]);
            }
            ans.push_back(0);
        }
        else{
            for(int i=last+1;i<n;i++){
              if(queries[i][0]==0)
                ans.push_back(queries[i][1]);
            }
            int xori=0;
            for(int i=last;i>=0;i--){
                if(queries[i][0]==1)
                 xori=xori^queries[i][1];
                else{
                    queries[i][1]=queries[i][1]^xori;
                }
            }
            for(int i=0;i<=last;i++){
                if(queries[i][0]==0)
                 ans.push_back(queries[i][1]);
            }
            ans.push_back(xori);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};