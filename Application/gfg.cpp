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
// ***************************************************************************trail of ones(03/06)
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        if( n == 1 || n == 0)
        return 0;
        if(n == 2)
        return 1;
        int mod = 1e9+7;
        int sum = 1;
        int t1 = 0;
        int t2 = 1;
        for(int i = 3; i <= n; i++)
        {
            int t = t1 + t2;
            t1 = t2;
            t2 = t % mod;
            sum = ((sum * 2 % mod) + t%mod) % mod;
        }
        return sum % mod;
    }
};
// ************************************************************************Binary Rrepresentation of next Number(04/06)
string binaryNextNumber(string s) {
        int n = s.length();
        int countOne = 0;
        int idxZero = -1;
        for(int i=0;i<n;++i){
            if(s[i] == '1') {
                ++countOne;
            } else {
                idxZero = i;
            }
        }
        string ans = "";
        if(countOne == n) {
            ans += "1";
            for(int i=0;i<n;++i) {
                ans += "0";
            }
        } else {
            s[idxZero] = '1';
            for(int i=idxZero+1;i<n;++i) {
                s[i] = '0';
            }
            int i = 0;
            while(s[i] == '0') ++i;
            for(int j=i;j<n;++j) {
                ans += s[j];
            }
        }
        return ans;
    }
// ***************************************************************************Swapping pair make sum equal(05/06)
class Solution {
  public:
    int findSwapValues(int a[], int n, int b[], int m){
        int suma=0,sumb=0;
        for(int i=0; i<n; i++){
            suma+=a[i];
        }
        for(int i=0; i<m; i++){
            sumb+=b[i];
        }
        if((suma-sumb)%2!=0){
            return -1;
        }
        unordered_set<int> setb;
        for(int i=0; i<m; i++){
            setb.insert(b[i]);
        }
        int target=(suma-sumb)/2;
        for (int i = 0; i < n; i++) {
            if (setb.find(a[i]-target)!=setb.end()) {
                return 1;
            }
        }
        return -1;        
    }
};
// *****************************************************************************Max Sum in the configuration(06/06)
class solution {
public:
  long long max_sum(int a[], int n) {
            long long s1 = 0;
            long long ts = 0;
            
            for (int i = 0; i < n; i++) {
                s1 += (long long)i * a[i];  
                ts += (long long)a[i];      
            }
            
            long long maxi = s1;
            
            
            for (int i = n - 1; i >= 1; i--) {
                s1 = s1 + ts - (long long)n * a[i];  
                if (maxi < s1) {
                    maxi = s1;
                }
            }
            
            return maxi;
        }
}
// ****************************************************************************Maximum occured Integer(07/06)
class Solution {
  public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int>v(maxx + 2);
        for(int i = 0; i < n; i++){
            v[l[i]]++;
            v[r[i]+1]--;
        }
        for(int i = 1; i <= maxx; i++){
            v[i] = v[i] + v[i - 1];
        }
        return max_element(v.begin(), v.end()) - v.begin();
    }
};
// *****************************************************************************Index of an extra element(08/06)
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mid < n - 1 && arr1[mid] == arr2[mid]){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }
};
// **************************************************************************Convert Array into Zig Zag fashion(09/06)
class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        for(int i = 0; i < n - 1; i++){
            if(i & 1){
                if(arr[i] < arr[ i + 1]){
                    swap(arr[i], arr[ i + 1]);
                }
            }
            else{
                if(arr[i] > arr[ i + 1]){
                    swap(arr[i], arr[i + 1]);
                }
            }
        }
    }
};
// ***************************************************************************Nuts and Bolts(10/06)
class solution {
    public:
    void matchPairs(char nuts[], char bolts[], int n){
        sort(nuts, nuts+n);
        sort(bolts, bolts+n);
    }
}
// ******************************************************************************Maximum Tip Calculator(11/06)
class Solution {
  public:
    using ll = long long;
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        ll ans = 0, sum = 0;
        int my = n - min(x, n), c = 0;
        priority_queue<int> pq;
        for(auto a : arr)
        sum += a;
        for(int i = 0; i < n; i++){
            pq.push(brr[i] - arr[i]);
        }
        while(c < my){
            sum += pq.top();
            pq.pop();
            c++;
        }
        while(c <= y){
            ans = max(ans, sum);
            sum += pq.top();
            pq.pop();
            c++;
        }
        return ans;
    }
};
// *********************************************************************Count NUmbers Containing 4(12/06)
class Solution {
  public:
    int countNumberswith4(int n) {
        int count = 0;
        for(int i = 1; i <= n; ++i){
            if(hasDigit4(i)){
                ++count;
            }
        }
        return count;
    }
    private:
    bool hasDigit4(int num){
        while(num > 0){
            if(num % 10 == 4){
                return true;
            }
            num /= 10;
        }
        return false;
    }
};
// *************************************************************************Padovan Sequence(13/06)
class Solution {
    public:
    int padovanSequence(int n){
    if(n<=2) return 1;
       int n_1=1, n_2=1, n_3=1, ans;
       int mod=1e9+7;
       for(int i=0;i<n-2;i++){
           ans=(n_2+n_3)%mod;
           
           n_3=n_2;
           n_2=n_1;
           n_1=ans;
       }
       return ans;
    }
};
// ****************************************************************************ArmStrong Number(14/06)
class Solution {
  public:
    string armstrongNumber(int n){
        int original = n;
        int d1 = n % 10;
        n /= 10;
        int d2 = n % 10;
        n /= 10;
        int d3 = n % 10;
        int sumofcubes = (d1 * d1 * d1) + (d2 * d2 * d2) + (d3 * d3 * d3);
        if(sumofcubes == original){
            return "Yes";
        }else {
            return "No";
        }
    }
};
// **************************************************************************Mobile Numberic Keypad(15/06)
class Solution {
   public:
    long long dfs(int i,vector<vector<int>>&adj,int n,vector<vector<long long>>&dp){
      if(n==0){
          return 1;
      }
      if(n<0){
          return 0;
      }
      if(dp[i][n]!=-1){
          return dp[i][n];
      }
      long long ans=0;
      for(auto it:adj[i]){
          ans+=dfs(it,adj,n-1,dp);
      }
      return dp[i][n]=ans;
      
  }
    long long getCount(int n) {
        vector<vector<int>>adj(10,vector<int>());
        adj[0] = {0, 8};
        adj[1] = {1, 2, 4};
        adj[2] = {2, 1, 3, 5};
        adj[3] = {3, 2, 6};
        adj[4] = {4, 1, 5, 7};
        adj[5] = {5, 2, 4, 6, 8};
        adj[6] = {6, 3, 5, 9};
        adj[7] = {7, 4, 8};
        adj[8] = {8, 5, 7, 9, 0};
        adj[9] = {9, 6, 8};
        
        long long ans=0;
        vector<vector<long long>>dp(10,vector<long long>(n+1,-1));
        
        for(int i=0;i<10;i++){
            ans+=dfs(i,adj,n-1,dp);
        }
        return ans;
    }
};
// **************************************************************************Prime Path with Target Sum(16/06)
class Solution {
  public:
   bool isprime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
        vector<int> getPrimes(int n) {
        vector<int> a(2, -1);  
        for (int i = 2; i <= n / 2; i++) {
            if (isprime(i) && isprime(n - i)) {
                a[0] = i;
                a[1] = n - i;
                return a;
            }
        }
        return a;
    }
};
// **************************************************************************Check if Two Line Segment intersect(17/06)
class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        double m1=double(q1[1]-p1[1])/double(q1[0]-p1[0]);
        double m2=double(q2[1]-p2[1])/double(q2[0]-p2[0]);
        if(m1==m2)  return "false";
        
        bool c1=false,c2=false,c3=false,c4=false;
        if(p2[1]-p1[1]-m1*(p2[0]-p1[0])>0) c1=true;
        if(q2[1]-p1[1]-m1*(q2[0]-p1[0])>0) c2=true;
        if(p1[1]-p2[1]-m2*(p1[0]-p2[0])>0) c3=true;
        if(q1[1]-p2[1]-m2*(q1[0]-p2[0])>0) c4=true;
        
        if((c1 && c2) || (!c1 && !c2)|| (c3 && c4) || (!c3 && !c4))   return "false";
        return "true";
    }
};
// ****************************************************************************Number of Rectangle in a Circle(18/06)
class Solution {
  public:
    int rectanglesInCircle(int r) {
        int count = 0;
        for(int i = 1; i < 2 * r; i++){
            for(int j = 1; j < 2 * r; j++){
                if(i*i+j*j <= 4*r*r){
                    count++;
                }
            }
        }
        return count;
    }
};
// ***************************************************************************Find Maximum Volume of a Cuboid(19/06)
class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        double l=(perimeter-sqrt(pow(perimeter,2)-(24*area)))/12;
        double h=((perimeter/4)-2*l);
        return l*l*h;
    }
};
// ***************************************************************************Integral points of Triangle(20/06)
class Solution {
public:
    long long int gcd(long long int a, long long int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    long long int InternalCount(long long int p[], long long int q[], long long int r[]) {
        long long int area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));
        long long int bpq = gcd(abs(p[0] - q[0]), abs(p[1] - q[1]));
        long long int bqr = gcd(abs(q[0] - r[0]), abs(q[1] - r[1]));
        long long int brp = gcd(abs(r[0] - p[0]), abs(r[1] - p[1]));
        long long int boundaryPoints = bpq + bqr + brp;
        long long int A = area / 2;
        long long int interiorPoints = A - (boundaryPoints / 2) + 1;
        return interiorPoints;
    }
};
// *****************************************************************************Compare two Fraction(21/06)
class Solution {
  public:
    string compareFrac(string str) {
      int a,b,c,d;
       a=b=c=d=0;
       regex re("([0-9]+)\\/([0-9]+), ([0-9]+)\\/([0-9]+)",
       regex_constants :: ECMAScript);
       smatch sm;
       if(regex_search(str,sm,re)){
           a=stoi(sm[1]);
           b=stoi(sm[2]);
           
           c=stoi(sm[3]);
           d=stoi(sm[4]);
       }
       string ans="";
       if(a*d>b*c){
           ans+=to_string(a);
           ans+="/";
           ans+=to_string(b);
       }
       else if(a*d<b*c){
           ans+=to_string(c);
           ans+="/";
           ans+=to_string(d);
       }
       else{
           ans="equal";
       }
       return ans;
    }
};
// *********************************************************************************Extract the NUmber of String(22/06)
class Solution {
  public:
    long long ExtractNumber(string sentence) {
        long long res = -1;
        int i = 0;
        string temp = "";
        bool flag = 0;
        for(int i = 0; i < sentence.length(); i++){
            if(!isdigit(sentence[i])) {
                temp = "";
                continue;
            }
            while(isdigit(sentence[i])){
                if(i >= sentence.length()) break;
                if(sentence[i] == '9'){
                    flag = 1;
                }
                temp += sentence[i];
                i++;
            }
            if(temp == "" || flag == 1){
                flag = 0;
                temp = "";
                continue;
            }
            long long num = stoll(temp);
            res = max(res, num);
            temp = "";
        }
        return res;
    }
};
// ***********************************************************************************print Bracket Number(23/06)
class Solution {
  public:
    vector<int> bracketNumbers(string str) {
        stack<int> parenthesis;
        vector<int> ans;
        int p = 1;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '('){
                parenthesis.push(p);
                ans.push_back(p);
                ++p;
            }else if(str[i] == ')'){
                if(parenthesis.empty()){
                    ans.push_back(p);
                    ++p;
                }else {
                    ans.push_back(parenthesis.top());
                    parenthesis.pop();
                }
            }
        }
        return ans;
    }
};
// *******************************************************************************Summared Matrix(24/06)
class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        if(q < 2) return 0;
        long long l = 2;
        long long r = n * 2;
        if(q > r) return 0;
        return min (abs(q - l), abs(q - r)) + 1;
    }
};
// **********************************************************************************Left Rotate Matrix K times(25/06)
class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        vector<vector<int>> ans = mat;
        int row = mat.size(), col = mat[0].size();
         k = k % col;
         if(k > 0)
         {
             while(k--)
             {
                 for(int i = 0; i < row; i++)
                 {
                     int a = ans[i][0];
                     ans[i].erase(ans[i].begin());
                     ans[i].push_back(a);
                 }
             }
         }
         return ans;
    }
};
// ********************************************************************************Coverage of All Zeros in a Binary Matrix(26/06)
class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        vector<int>row = {-1, 1, 0, 0};
        vector<int>col = {0, 0, -1, 1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    for(int x = 0; x < 4; x++){
                        int nrow = i + row[x], ncol = j + col[x];
                        if(nrow >= 0 && nrow<n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == 1){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// ********************************************************************************Toeplitz Matrix(27/06)
class Solution {
    public:
    bool isToepliz(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if( mat[i][j]!=mat[i - 1][j - 1]){
                return false;
            }
        }
    }
    return true;
  }
}
// ***********************************************************************************The Palindrome Pattern(28/06)
class Solution {
    public:
string pattern(vector<vector<int>> &arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            while(l<=r && arr[i][l]==arr[i][r]){
                l++;r--;
            }
            if(l>r)return to_string(i)+" R";
        }
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            while(l<=r && arr[l][i]==arr[r][i]){
                l++;r--;
            }
            if(l>r)return to_string(i)+" C";
        }
        return "-1";
    }
}
// ***************************************************************************************Identical Linked List(29/06)
bool areIdentical(struct Node *head1, struct Node *head2) {
    while(head1 && head2)
    {
        if(head1 -> data != head2 -> data)
        return false;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    if(head1 || head2)
    return false;
    return true;
}
// *************************************************************************************Delete node the Doubly Linked List(30/06)
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if( x == 1){
            head -> next -> prev = NULL;
            return head -> next;
        }
        Node *p = head;
        while(x -- != 1) p = p -> next;
        if(!p -> next) p -> prev -> next = NULL;
        else p -> prev -> next = p -> next, p -> next -> prev = p -> prev;
        return head;
    }
};
// **************************************************************************************Make Binary Tree from Linked List(01/07)
void convert(Node *head, TreeNode *&root) {
    if( head == nullptr) {
        root = nullptr;
        return;
    }
    root = new TreeNode(head -> data);
    queue<TreeNode*> q;
    q.push(root);
    head = head -> next;
    while(head){
        TreeNode* current = q.front();
        q.pop();
        current -> left = new TreeNode(head -> data);
        q.push(current -> left);
        head = head -> next;
        if(head == nullptr) break;
        current -> right = new TreeNode(head -> data);
        q.push(current -> right);
        head = head -> next;
    }
}
// ***********************************************************************************Linked List a string form a Palindrome(02/07)
class Solution {
  public:
    bool compute(Node* head) {
        string s = "";
        Node* curr = head;
        while(curr !=NULL){
            s += curr -> data;
            curr = curr -> next;
        }
        int i = 0, j = s.size()-1;
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}; 
// **********************************************************************************Remove all Occurence of duplicate in a Linked List(03/07)
class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        map<int, int> m;
        Node* run = head;
        while(run) {
            m[run -> data]++;
            run = run -> next;
        }
        Node* dummy = new Node(0);
        dummy -> next = nullptr;
        Node* temp = dummy;
        for(const auto& pair : m){
            if( pair.second == 1){
                Node* newNode = new Node(pair.first);
                temp -> next = newNode;
                temp = newNode;
            }
        }
        return dummy -> next;
    }
};
// ***************************************************************************************Duplicate SubTrees(04/07)
unordered_map<string,int> m;
vector<Node*> ans;
string solve(Node* root){
    if(!root) return "$";
    string s = "";
    s = s + to_string(root->data);
    s = s + "#";
    s = s + solve(root->left);
    s = s + "#";
    s = s + solve(root->right);
    s = s + "#";
    m[s]++;
    if(m[s]==2) ans.push_back(root);
    return s;
}
vector<Node*> printAllDups(Node* root)
{
    m.clear();
    ans.clear();
    
    solve(root);
    return ans;
}
// ******************************************************************************************Vertical Width of a Binary Tree(05/07)
class Solution {
  public:
    int verticalWidth(Node* root) {
        if(root == NULL) return 0;
        int mini = 1e9 + 7;
        int maxi = -1e9 + 7;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int x = it.second;
            mini = min(mini, x);
            maxi = max(maxi, x);
            if(node -> left) {
                q.push({node -> left, x - 1});
            }
            if(node -> right){
                q.push({node -> right, x + 1});
            }
        }
        return abs(mini) + abs(maxi) + 1;
    }
}; 
// **************************************************************************************Populate Inorder Successor for all Nodes(06/07)
class Solution {
  public:
    vector<Node *> populateNext(Node *root) {
        if(!root)
            return {NULL, NULL};
        vector<Node *> l = populateNext(root->left);
        vector<Node *> r = populateNext(root->right);
        if(l[1])
            l[1]->next = root;
        if(r[0])
            root->next = r[0];
        return {l[0] ? l[0] : root, r[1] ? r[1] : root};
    }
};
// ****************************************************************************************Ancestors in Binary Tree(07/07)
class Solution {
  public:
    vector<int>ans;
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int>left;
        vector<int>right;
        if(root -> data == target){
            reverse(ans.begin(),ans.end());
            return ans;
        }
        ans.push_back(root -> data);
        if(root -> left){
            left = Ancestors(root -> left, target);
        }
        if(root -> right){
            right = Ancestors(root -> right, target);
        }
        ans.pop_back();
        return left.size() > right.size()?left:right;
    }
};
// *********************************************************************************************Search in Rotated Sorted Array(08/07)
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == key)
            {
                return mid;
            }
            if(arr[low] <= arr[mid]){
                if(arr[low] <= key && key < arr[mid])
                {
                    high = mid - 1;
                }
                else 
                {
                    low = mid + 1;
                }
            }
            else {
                if(arr[mid] < key && key <= arr[high])
                {
                    low = mid + 1;
                }
                else 
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
// ******************************************************************************************Closest Three Sum(09/07)
class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = INT_MAX;
        int res;
        int anssum;
        for(int i = 0; i < n; i++){
            int l = i + 1;
            int h = n - 1;
            while(l < h){
                int sum = arr[i] + arr[l] + arr[h];
                if(sum > target){
                    h--;
                }
                else if(sum < target){
                    l++;
                }
                else {
                    return sum;
                }
                res = abs(sum - target);
                if(res < ans){
                    ans = res;
                    anssum = sum;
                }
                if(res == ans){
                    anssum = max(anssum,sum);
                }
            }
        }
        return anssum;
    }
};
// *************************************************************************************Largest Square formed in a matrix(10/07)
class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int ans = 0; 
        for(int i = 0; i < n; i++) ans = max(ans, mat[i][0]);
        for(int j = 0; j < m; j++) ans = max(ans, mat[0][j]);
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][j] == 0) continue;
                int num = min({mat[i - 1][j], mat[i][j - 1], mat[i - 1][j - 1]});
                mat[i][j] = num + 1;
                ans = max(ans, mat[i][j]);
            }
        }
        return ans;
    }
};
// ******************************************************************************************Maximum Connected Group(11/07)
class Solution {
  public:
    int x[4]= {0,0,1,-1};
    int y[4]= {1,-1,0,0};
    void dfs(int i, int j, int c, int &temp, int n, int m, vector<vector<int>> &v, vector<vector<int>> &vis, vector<vector<int>> &mp) {
        if(i<0 || i==n || j<0 || j==m || !v[i][j] || vis[i][j]) return;
        vis[i][j]=1;
        temp++;
        mp[i][j]=c;
        for(int k=0;k<4;k++) {
            dfs(i+x[k], j+y[k], c, temp, n, m, v, vis, mp);
        }
    }
    
    void fun(int i, int j, int n, int m, int &ans, vector<vector<int>> &mp, unordered_map<int, int> &mpp) {
        int temp=0;
        set<int> s;
        for(int k=0;k<4;k++) {
            if(i+x[k]<0 || i+x[k]==n || j+y[k]<0 || j+y[k]==m || mp[i+x[k]][j+y[k]]==-1) continue;
            s.insert(mp[i+x[k]][j+y[k]]);
        }
        for(auto it : s) {
            temp+=mpp[it];
        }
        ans=max(ans, 1+ temp);
    }
    
    int MaxConnection(vector<vector<int>>& v) {
        int n=v.size(), m=v[0].size(), ans=0;
        vector<vector<int>> vis(n, vector<int> (m, 0)), mp(n, vector<int> (m, -1));
        unordered_map<int, int> mpp;
        
        int c=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] && !vis[i][j]) {
                    int temp=0;
                    dfs(i, j, c, temp, n, m, v, vis, mp);
                    mpp[c]=temp;
                    c++;
                }
            }
        }
        for(auto it : mpp) ans=max(ans, it.second);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!v[i][j]) fun(i, j, n, m, ans, mp, mpp);
            }
        }
        return ans;
    }
};
// ************************************************************************************Roof To Leaf Path Sum(12/07)
class Solution {
  public:
 bool solve(Node* root, int target, int sum) {
    if (!root) return false;
    sum += root->data;
    if (!root->left && !root->right) {
        return sum == target;
    }
    return solve(root->left, target, sum) || solve(root->right, target, sum);
}
    bool hasPathSum(Node *root, int target) {
       return solve(root , target ,0);
    }
};
// ****************************************************************************************Shortest path in weighted undirected graph(13/07)
class Solution {
public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(auto&it:edges){
            int u=it[0];
            int v=it[1];
            int weight=it[2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        vector<int>visited(V+1,0);
        vector<int>dist(V+1,INT_MAX);
        dist[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
        pq.push({0,1});
        vector<int>parent(V+1,-1);
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            if(!visited[node]){
                visited[node]=true;
                for(auto v:adj[node]){
                    int nbr=v.first;
                    int weight=v.second;
                    if(dist[nbr]>dist[node]+weight){
                        dist[nbr]=dist[node]+weight;
                        pq.push({dist[nbr],nbr});
                        parent[nbr]=node;
                    }
                }
            }
        }
        if(parent[V]==-1)return {-1};
        vector<int>path;
        int t=V;
        while(t!=-1){
         path.push_back(t);
         t=parent[t];
        }
        path.push_back(dist[V]);
        reverse(path.begin(),path.end());
        return path;
    }
};
// *************************************************************************************Segregate 0 & 1(14/07)
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        while(j > i){
            if(arr[i] == 1 && arr[j] == 0){
                swap(arr[j], arr[i]);
                i++;
                j--;
            }
            else if (arr[i] == 1 && arr[j] == 1){
                j--;
            }
            else if(arr[i] == 0 && arr[j] == 0){
                i++;
            } 
            else {
                i++;
                j--;
            }
        }
    }
};
// ***************************************************************************************Smallest Number(15/07)
class Solution {
  public:
        int sum(int n){
            int s = 0;
            while(n){
                s += n%10;
                n/=10;
            }
            return s;
        }
        string smallestNumber(int s, int d){
         for(int i = pow(10, d-1);
         i<=pow(10, d) -1; i++){
             if(sum(i) == s) return to_string(i);
         }   
         return "-1";
        }
};
// ****************************************************************************************Remaining String(16/07)
class Solution {
  public:
    string printString(string s, char ch, int count) {
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ch)
            count--;
            if(count == 0){
                ans = s.substr( i + 1);
                break;
            }
        }
        return ans;
    }
};
// **************************************************************************************Construct Binary tree from Parent Array(17/07)
class Solution {
  public:
    Node *createTree(vector<int> parent) {
        unordered_map<int,Node*> nodes;
        for(int i = 0; i < parent.size(); i++){
            nodes[i] = new Node(i);
        }
        int rootval = -1;
        for(int i = 0; i < parent.size(); i++){
            int Par = parent[i];
            int Child = i;
            if(Par == -1){
                rootval = i;
                continue;
            }
            if(nodes[Par] -> left == nullptr){
                nodes[Par] -> left = nodes[Child];
            } else {
                nodes[Par] -> right = nodes[Child];
            }
        }
        return nodes[rootval];
    }
};
// ****************************************************************************************Longest Alernative Subsequence(18/07)
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        if(arr.size() == 1)
        return 1;
        if(arr.size() == 2)
        {
            if(arr[0] == arr[1])
            return 1;
            return 2;
        }
        int ans = 1;
        int pre = arr[0];
        for(int i = 1; i < arr.size()-1; i++)
        {
            if(arr[i] > arr[i + 1] && arr[i] > pre)
            ans++, pre = arr[i];
            else if(arr[i] < pre && arr[i] < arr[i + 1])
            ans++, pre=arr[i];
        }
        return ans + 1;
    }
};
// *******************************************************************************************Count Smaller Element(19/07)
class Solution 
{
  public:
    vector<int> seg;
    void update(int i, int j, int l, int h)
    {
        if(j < l || j > h)
            return;
        seg[i]++;
        if(l == h)
            return;   
        int mid = (l+h)>>1;
        update(2*i + 1, j, l, mid);
        update(2*i + 2, j, mid+1, h);
    }
    int query(int i, int j, int l, int h)
    {
        if(h < j)
            return 0;
    
        if(l >= j)
            return seg[i];
        int mid = (l+h)>>1;
        return query(2*i+1, j, l, mid) +
        query(2*i+2, j, mid+1, h);
    }
    vector<int> constructLowerArray(vector<int> &arr) 
    {
        int n = arr.size();
        seg.resize(4*n);
        vector<int> ans(n);
        vector<vector<int>> temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back({arr[i], i});
        }
            sort(temp.begin(), temp.end());
        
        for(int i=0;i<n;i++)
        {
            ans[temp[i][1]] = query(0, temp[i][1], 0, n-1);
            update(0,temp[i][1],0,n-1);
        }
            return ans;
    }
};
// *******************************************************************************************RemovalHalfNode(20/07)
class Solution {
  public:
    void solve(Node* &root){
        if(root){
             solve(root->left); 
            solve(root->right); 
            
            if(root->left != NULL && root->right == NULL||root->left == NULL && root->right != NULL){
             root = root->left?root->left:root->right; 
            }
        }
    }
    Node *RemoveHalfNodes(Node *root) {
        solve(root); 
        
        return root ; 
    }
};
// **************************************************************************************Maximum product subset of an Array(21/07)
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        long long mod = 1e9+7;
        int flag = 0;
        long long prod = 1, mini = INT_MIN;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                flag = 1;
                continue;
            }
            if(arr[i] > 0){
                prod = ((prod)%mod * arr[i])%mod;
            }
            else if(arr[i] < 0){
                prod = ((prod) %mod * arr[i]) % mod;
                mini = max((long long) arr[i], mini);
            }
        }
        if(prod < 0){
            prod = prod / mini;
        }
        if(prod == 1 && flag == 1) return 0;
        return prod;
    }
}; 
// *****************************************************************************************Largest BST(22/07)
class Solution{
    public:
    int countNodes(Node* node)
    {
        if(node == NULL) return 0;
        return 1 + countNodes(node -> left) + countNodes(node -> right);
    }
    bool isBST(Node* node, int min, int max)
    {
        if(node == NULL) return true;
        if(node -> data < min || node -> data > max) return false;
        return isBST(node -> left, min, node -> data - 1) && isBST(node -> right, node -> data + 1, max);
    }
    int largestBst(Node *root)
    {
    	if(isBST(root, INT_MIN, INT_MAX)) return countNodes(root);
    	int left = largestBst(root -> left);
    	int right = largestBst(root -> right);
    	return max(left, right);
    }
};
// ******************************************************************************************Merge Two BSt's(23/07)
class Solution {
  public:
    void inorder(Node *root, vector<int> &arr){
        if(!root)
        return;
        inorder(root -> left, arr);
        arr.push_back(root -> data);
        inorder(root -> right, arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> arr;
        inorder(root1, arr);
        inorder(root2, arr);
        sort(arr.begin(), arr.end());
        return arr;
    }
};
// *******************************************************************************************Check BST(24/07)
class Solution
{
    public:
    Node* prevv = NULL;
    bool isBST(Node* root) 
    {
        if(root == NULL){
            return true;
        }
        if(isBST(root->left)== false){
            return false;
        }
        if(prevv!= NULL && root-> data<=prevv-> data){
            return false;
        }
        prevv = root;
        return isBST(root-> right);
    }
};
// **********************************************************************************************Array To BST(25/07)
class Solution {
  public:
    Node* solve(vector<int> &nums, int s, int e){
        if(s > e){
            return NULL;
        }
        int mid = (s + e) / 2;
        Node* curr = new Node(nums[mid]);
        curr -> left = solve(nums,s, mid - 1);
        curr -> right = solve(nums, mid + 1, e);
        return curr;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        return solve(nums, s, e);
    }
};
// ***********************************************************************************************K-Pangram(26/07)
class Solution {
  public:
    bool kPangram(string str, int k) {
        unordered_map<char, int>cnt;
        for(char c : str) if(isalpha(c)) cnt[c]++;
        int req = 26 - cnt.size(), changable = 0;
        for(auto i : cnt) changable += i.second - 1;
        return k >= req && changable >= req;
    }
};
// ****************************************************************************************************Form a Palindrome(27/07)
class Solution() {
public:
    int CountMin(string str)
{
        vector<vector<int>> dp(501,vector<int>(501,-1));
        int n=str.size();
        int lp =lps(str,n-1,0,n,dp);
        return n -lp;
    }
    int lps(string &str,int i,int j,int n,vector<vector<int>> &dp){
        if(i == -1 || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int tk =0,skp =0;
        if(str[i] == str[j]){
            tk =1 + lps(str,i -1,j +1,n,dp);
        }
        skp =max(lps(str,i -1,j,n,dp),lps(str,i,j +1,n,dp));
        return dp[i][j] =max(tk,skp);
    }
};
// **********************************************************************************************Remove Duplicate(28/07)
class Solution {
  public:
    string removeDups(string str) {
        string ans = "";
        int cnt[26] = {0};
        for(int i = 0; i < str.size(); i++) {
            if(cnt[str[i] - 'a'] == 0) ans += str[i];
            cnt[str[i] - 'a']++;
        }
        return ans;
    }
};
// ************************************************************************************************Row with Max 1's(29/07)
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int currColumn = arr[0].size() - 1, currRow = 0, ans = -1;
        while(currColumn >= 0 and currRow < arr.size()){
            while(currColumn >= 0 and arr[currRow][currColumn] == 1){
                ans = currRow;
                currColumn--;
            }
            if(currColumn < 0){
                return currRow;
            }
            else {
                currRow++;
            }
        }
        return ans;
    }
};
// **************************************************************************************Rat in a Maze I(30/07)
class Solution {
  public:
    void solve(vector<vector<int>>&mat , vector<string>&ans , string s , int n , int m ,int i , int j,
    vector<vector<int>>&vis){
        if ( i < 0 || j < 0 || i == n || j == m || mat[i][j] == 0 || vis[i][j] == 1) return;
        if (i == n-1 and j == m-1) {ans.push_back(s);return;}
        vis[i][j] = 1;
        solve(mat,ans,s+"R",n,m,i,j+1,vis);
        solve(mat,ans,s+"D",n,m,i+1,j,vis);
        solve(mat,ans,s+"L",n,m,i,j-1,vis);
        solve(mat,ans,s+"U",n,m,i-1,j,vis);
        vis[i][j] = 0;
        return;        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        string s = "";
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        solve(mat,ans,s,n,m,0,0,vis);
        sort(ans.begin(),ans.end());
        return ans;      
    }
};
// **************************************************************************************Longest Common Prefix of String(31/07)
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        string ans = arr[0];
        for(int i = 0; i < arr.size(); i++){
            string temp = "";
            for(int j = 0; j < min(arr[i].size(), ans.size()); j++){
                if(arr[i][j] == ans[j]) temp += ans[j];
                else break;
            }
            ans = temp;
        }
        if(ans.size() != 0) return ans;
        else return "-1";
    }
};
// *****************************************************************************************Spirally Traversing in a Matrix(01/08)
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
// ***********************************************************************************************Edit Distance(02/08)
class Solution {
  public:
    int ans(string &str1,string&str2,int n,int m,vector<vector<int>>&v)
    {
        if(n==-1)
        return m+1;
        if(m==-1)
        return n+1;
        if(v[n][m]!=INT_MAX)
        return v[n][m];
        if(str1[n]==str2[m])
        {
            return v[n][m]=min(v[n][m],ans(str1,str2,n-1,m-1,v));
        }
        v[n][m]=min(v[n][m],1+ans(str1,str2,n-1,m-1,v));
        v[n][m]=min(v[n][m],1+ans(str1,str2,n-1,m,v));
        v[n][m]=min(v[n][m],1+ans(str1,str2,n,m-1,v));
        return v[n][m];
        
    }
    int editDistance(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>>v(n,vector<int>(m,INT_MAX));
        return ans(str1,str2,n-1,m-1,v);
    }
};
// *************************************************************************************The Celebrity Problem(03/08)
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    v[i].first++;
                    v[j].second++;
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(v[i].first==0 && v[i].second==n-1) ans=i;
        }
        return ans;
    }
};
// ****************************************************************************************N meeting in one Room(04/08)
class Solution {
  public:
    int maxMeetings(int n, int start[], int end[]) {
        int count=1;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int last=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second>last){
                count++;
                last=v[i].first;
            }
        }
    return count;
    }
};
// *******************************************************************************************Bottom View Of binary Tree(05/08)
class Solution {
public:
  vector <int> bottomView(Node *root) {
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level]=node->data;
            if(node->left)q.push({node->left,level-1});
            if(node->right)q.push({node->right,level+1});
        }
        vector<int>ans;
        for(auto it:mp)ans.push_back(it.second);
        return ans;
    }
};
// *******************************************************************************Validate in IP Address(06/08)
class Solution {
  public:
    int isValid(string str) {
        int n = str.size();
        int dot = 0;
        string tmp = "";
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '.')
            {
                dot++;
                if(tmp.empty() || (tmp[0] == '0' && tmp.size() > 1))
                {
                    return false;
                }
                int num = stoi(tmp);
                if(num < 0 || num > 255)
                {
                   return false; 
                }
                tmp = "";
            }
             else {
                 tmp += str[i];
             }
        }
        if(dot != 3)
        return false;
        if(tmp.empty() || (tmp[0] == '0' && tmp.size() > 1))
        return false;
        int num = stoi(tmp);
        if(num < 0 || num > 255)
        return false;
        return true;
    }
};
// **************************************************************************************Kth element of two Arrays(07/08)
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2){
        int i=0,j=0;
        int n1=arr1.size(),n2=arr2.size();
        vector<int> arr;
        while(i<n1 && j<n2){
            if(arr1[i]>=arr2[j]){
                arr.push_back(arr2[j++]);
            }
            else {
                arr.push_back(arr1[i++]);
            }
        }
        while(i<n1){
             arr.push_back(arr1[i++]);
        }
        while(j<n2){
             arr.push_back(arr2[j++]);
        }
        return arr[k-1];
    }  
};
// *********************************************************************************Sum Tree(08/08)
class Solution {
  public:
    int ans(Node* root){
        if(root == NULL){
            return 0;
        } else {
            int left = ans(root -> left);
            int right = ans(root -> right);
            return left + right + root -> data;
        }
    }
    bool isSumTree(Node* root) {
        if(root -> left == NULL && root -> right == NULL) return true;
        int sum = ans(root);
        if(sum - root -> data == root -> data) return true;
        return false;
    }
};
// ***********************************************************************************Maximize Array Value After Rearrangement(09/08)
class Solution {
  public:
    int Maximize(vector<int> arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long long result = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            result = (result + (long long) arr[i] * i) % mod;
        }
        return result;
    }
};
// ************************************************************************************Rotate a Linked List(10/08)
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        vector<int>vec;
        Node* curr = head;
        while(curr != NULL){
            vec.push_back(curr -> data);
            curr = curr -> next;
        }
        reverse(vec.begin(), vec.begin() + k);
        reverse(vec.begin() + k, vec.end());
        reverse(vec.begin(), vec.end());
        curr = head;
        for(int i = 0; i < vec.size(); i++){
            curr -> data = vec[i];
            curr = curr -> next;
        }
        return head;
    }
};