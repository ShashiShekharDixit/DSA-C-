#include <vector>
#include <climits>

using namespace std;

class Triplet {
public:
    int minSum;
    int secondMinSum;
    int minSumIndex;

    Triplet(int minSum, int secondMinSum, int minSumIndex) : minSum(minSum), secondMinSum(secondMinSum), minSumIndex(minSumIndex) {}
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        return minFallingPathSumHelper(0, grid).minSum;
    }

    Triplet minFallingPathSumHelper(int row, vector<vector<int>>& grid) {
        if (row == grid.size()) {
            return Triplet(0, 0, 0);
        }

        Triplet nextRowTriplet = minFallingPathSumHelper(row + 1, grid);
        Triplet currentTriplet(INT_MAX, INT_MAX, -1);

        for (int col = 0; col < grid[0].size(); col++) {
            int value = grid[row][col] + ((col != nextRowTriplet.minSumIndex) ? nextRowTriplet.minSum : nextRowTriplet.secondMinSum);
            if (value <= currentTriplet.minSum) {
                currentTriplet.secondMinSum = currentTriplet.minSum;
                currentTriplet.minSum = value;
                currentTriplet.minSumIndex = col;
            } else if (value < currentTriplet.secondMinSum) {
                currentTriplet.secondMinSum = value;
            }
        }

        return currentTriplet;
    }
};
// ****************************************************************27/04
class Solution 
{
public:
    int method(int i1,int i2, string ring, string key,int m,int n, vector<vector<int>>&dp)
    {
        if(i2==n)
          return 0;
        if(dp[i1][i2]!=-1)
          return dp[i1][i2];
        int ans = INT_MAX;
        for(int i=0;i<m;i++)
        {
            if(ring[i]==key[i2])
            {
                int count = min(abs(i1-i),m-abs(i1-i));
                ans = min(ans, count + method(i, i2+1, ring, key, m, n,dp));
            }
        }
        return dp[i1][i2]=ans;
    }
    int findRotateSteps(string ring, string key)
    {
        int i1=0,i2=0;
        int n = key.size();
        int m = ring.size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return method(i1,i2,ring, key,m,n,dp)+n;
    }
};
// *******************************************************************28/04(Sum of deistances in Tree)
class Solution {
public:
    void dfs(vector<int> adj[], int n, int node, int prev, vector<int> &height, vector<int> &subtree){
        subtree[node]++;
        for(auto &ele:adj[node]){
            if(ele!=prev){
                height[ele] = 1 + height[node];
                dfs(adj,n, ele, node, height, subtree);
                subtree[node] += subtree[ele];
            }
        }
    }
    void rec(vector<int> adj[], int n, int node, int prev, vector<int> &subtree, vector<int> &dp){
        for(auto &ele:adj[node]){
            if(ele!=prev){
                dp[ele] = dp[node] - subtree[ele] + (n - subtree[ele]);
                rec(adj, n, ele, node, subtree, dp);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &ele:edges){
            int u = ele[0], v = ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> height(n,0), subtree(n,0);
        vector<int> dp(n,0);
        dfs(adj,n,0,-1,height,subtree);
        for(int i = 0; i < n; i++) dp[0] += height[i];
        rec(adj,n,0,-1,subtree,dp);
        return dp;
    }
};
// *************************************************************29/04(Minimum Number of Operations to Make Array XOR Equal to K)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;
        for(int n : nums){
            finalXor = finalXor ^ n;
        }
        int count = 0;
        while(k || finalXor) {
            if((k % 2) != (finalXor % 2)) {
                count++;
            }
            k /= 2;
            finalXor /= 2;
        }
        return count;
    }
};
// **************************************************************30/04(Number of wonderful Substring)
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024, 0);
        long long result = 0;
        int prefixXor = 0;
        count[prefixXor] = 1;
        
        for(char ch : word) {
            int charIndex = ch - 'a';
            prefixXor ^= 1 <<charIndex;
            result += count[prefixXor];
            for(int i = 0; i < 10; i++){
                result += count[prefixXor ^ (1 << i)];
            }
            count[prefixXor]++;
        }
        return result;
    }
};
// *****************************************************************01/05(Reverse prefix of words)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.find(ch);
        if(j != -1){
            reverse(word.begin(), word.begin() + j + 1);
        }
        return word;
    }
};
// *****************************************************************02/05(Largest Positive integer that exits with its negative)
class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > 0 && std::binary_search(nums.begin(), nums.end(), -nums[i])) {
                return nums[i];
            }
        }
        return -1;  
    }
};
// ******************************************************************03/05(Comapare Number version)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int n1 = version1.size(), n2 = version2.size();
        int x1 = 0, x2 = 0;
        for(int i = 0, j = 0; i < n1 || j < n2; i++, j++){
            while(i < n1 && version1[i] != '.'){
                x1 = 10 * x1 + (version1[i++]-'0');
            }
            while(j < n2 && version2[j] != '.'){
                x2 = 10 * x2 + (version2[j++]-'0');
            }
          if(x1 < x2) return -1;
          else if(x1 > x2) return 1;
          x1 = 0;
          x2 = 0;
        }
        return 0;
    }
};
// ********************************************************************04/05(Boat to save People)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int x = 0;
        for(int l = 0, r = people.size() - 1; l <= r; r--){
            x++;
            if(people[l]<=limit-people[r])
            l++;
        }
        return x;
    }
};
// ******************************************************************05/05(Delete Node in a linked list)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
// ********************************************************************06/05(Print All Node that don't have siblings)
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
// **************************************************************07/05(Double a number represented by a Linked List)
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* reversedList = reverseList(head);
        int carry = 0;
        ListNode* current = reversedList, *previous = nullptr;

        while (current != nullptr) {
            int newValue = current->val * 2 + carry;
            current->val = newValue % 10;
            if (newValue > 9) {
                carry = 1;
            } else {
                carry = 0;
            }
            previous = current;
            current = current->next;
        }

        if (carry != 0) {
            ListNode* extraNode = new ListNode(carry);
            previous->next = extraNode;
        }

        ListNode* result = reverseList(reversedList);

        return result;
    }

    ListNode* reverseList(ListNode* node) {
        ListNode* previous = nullptr, *current = node, *nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        return previous;
    }
};
// **************************************************************08/05(Relative Rank)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, string> rankMapping;
        for (int i = 0; i < sortedScore.size(); i++) {
            if (i < 3) {
                rankMapping[sortedScore[i]] = medals[i];
            } else {
                rankMapping[sortedScore[i]] = to_string(i + 1);
            }
        }
        vector<string> result;
        for (int s : score) {
            result.push_back(rankMapping[s]);
        }
        return result;
    }
};
// ****************************************************************09/05(Maximize Happiness of Selected Childrens)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(begin(happiness),end(happiness), greater<int>());
        int i = 0;
        long long res = 0;
        while(k--){
            happiness[i] = max(happiness[i] - i, 0);
            res += happiness[i++];
        }
        return res;
    }
};
// ********************************************************************10/05(Kth smallest prime factor)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1, mid;
        vector<int> res;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] >= arr[j] * mid) {
                    ++j;
                }
                total += n - j;
                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j;
                }
            }
            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }
            if (total > k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return res;
    }
};
// *********************************************************************11/05(Minimum Cost to hire a Kth worker)
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<pair<double, int>> ratio;
        int n = quality.size();
        for (int i = 0; i < n; ++i) {
                ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
            }
        sort(begin(ratio), end(ratio));
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double maxRate = 0.0;
        for (int i = 0; i < k; ++i) {
            qualitySum += quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            maxHeap.push(quality[ratio[i].second]);
        }
        double res = maxRate * qualitySum;
        for (int i = k; i < n; ++i) {
            maxRate = max(maxRate, ratio[i].first);
            qualitySum -= maxHeap.top(); 
            maxHeap.pop();

            qualitySum += quality[ratio[i].second];
            maxHeap.push(quality[ratio[i].second]);
            res = min(res, maxRate * qualitySum);
        }
        return res;
    }
};
// **********************************************************************12/05(Largest vocal value in a Matrix)
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for(int i = 1; i < n - 1; ++i){
            for(int j = 1; j < n - 1; ++j){
                int temp = 0;
                for(int k = i - 1; k <= i + 1; ++k){
                    for(int l = j - 1; l <= j + 1; ++l){
                        temp = max(temp, grid[k][l]);
                    }
                }
                res[i - 1][j - 1] = temp;
            }
        }
        return res;
    }
};
// ************************************************************************13/05(Score after flipping Matrix)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = grid.size(), m = grid[0].size();
        int res = (1 << (m - 1)) * n;
        for(int j = 1; j < m; ++j) {
            int val = 1 << (m - 1 - j);
            int set = 0;
            for(int i = 0; i < n; ++i) {
                if(grid[i][j] == grid[i][0]) {
                    set++;
                }
            }
            res += max(set, n - set) * val;
        }
        return res;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// *************************************************************************14/05(Path with maximum Gold)
class Solution {
public:
    vector<int> row = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int maxGold = 0;
    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m){
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;
        int curr = grid[x][y];
        grid[x][y] = 0;
        int localMaxGold = curr;
        for(int i = 0; i < 4; i++){
            int newX = x + row[i];
            int newY = y + coll[i];
            localMaxGold = max(localMaxGold, curr + dfs(grid, newX, newY, n, m));
        }
        grid[x][y] = curr;
        return localMaxGold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
     int n = grid.size(), m = grid[0].size();
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != 0){
                maxGold = max(maxGold, dfs(grid, i, j, n, m));
            }
        }
     }   
     return maxGold;
    }
};
// ***********************************************************15/05(Find the safest in a Grid)
class Solution {
public:
    vector<int> roww = {0,0,-1,1};
    vector<int> coll = {-1,1,0,0};
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& score,int n) {
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j]) {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            int s = score[x][y];
            for(int i =0; i < 4; i++){
                int newX = x + roww[i];
                int newY = y + coll[i];
                if(newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s) { 
                    score[newX][newY] = 1 + s;
                    q.push({newX, newY});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return 0;
        vector<vector<int>> score(n,vector<int>(n,INT_MAX));
        bfs(grid, score, n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({score[0][0], {0,0}});
        while(!pq.empty()){
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();
            if(temp.first == n - 1 && temp.second == n - 1) return safe;
            vis[temp.first][temp.second] = true;
            for(int i = 0; i < 4; i++) {
                int newX = temp.first + roww[i];
                int newY = temp.second + coll[i];
                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]){
                    int s = min(safe, score[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }
        return -1;
    }
};
// ********************************************************************16/05(Evaluate Boolean Binary Tree)
class Solution {
public:
    bool helper(TreeNode* root) {
        if(root -> val == 0 || root -> val == 1) {
            return root -> val == 1;
        } else if(root -> val == 2) {
            return helper(root -> left) || helper(root -> right);
        } else if(root -> val == 3) {
            return helper(root -> left) && helper(root -> right);
        } 
        return false;
    }
    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};
// *********************************************************************17/05(Delete Leaves with a given value)
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return nullptr;
        root -> left = removeLeafNodes(root -> left, target);
        root -> right = removeLeafNodes(root -> right, target);
        if(!root -> left && !root -> right && root -> val == target)
        return nullptr;
        return root;
    }
};
// ***********************************************************************18/05(Distribute coin in binary Tree)
class Solution {
public:
    int moves = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left_excess = dfs(node->left);
        int right_excess = dfs(node->right);
        moves += abs(left_excess) + abs(right_excess);
        return node->val + left_excess + right_excess - 1;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};
// ***********************************************************************19/05(Find the Maximum Sum of Node value)
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long totalSum = 0;
        int count = 0;
        int positiveMin = INT_MAX;
        int negativeMax = INT_MIN;
        for(int nodeValue : nums){
            int nodeValAfterOperation = nodeValue ^ k;
            totalSum += nodeValue;
            int netChange = nodeValAfterOperation - nodeValue;
            if(netChange > 0){
                positiveMin = min(positiveMin, netChange);
                totalSum += netChange;
                count += 1;
            } else {
                negativeMax = max(negativeMax, netChange);
            }
        }
        if(count % 2 == 0){
            return totalSum;
        }
        return max(totalSum - positiveMin, totalSum + negativeMax);
    }
};
// *************************************************************************20/05(Sum of All subsets XOR totals)
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sumTotal = 0;
        for(int num : nums){
            sumTotal |= num;
        }
        return sumTotal << (nums.size() - 1);
    }
};
// *************************************************************************21/05(Subsets)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result){
        result.push_back(path);
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};
// *****************************************************************************22/05(Palindrome Partition)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        for (int end = start + 1; end <= s.length(); ++end) {
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
                backtrack(s, end, path, result);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};
// ************************************************************************23/05(The Number of Beautiful Subsets)
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
// ***************************************************************************24/05(Maximum score words formed by letters)
class Solution {
public:
    int a[26], b[26], ans = 0;
    void solve(int idx, vector<string>& words, vector<int>& score){
        if(idx == words.size()) {
            int sc = 0;
            for(int i = 0; i < 26; i++){
                if(b[i] > a[i]) return;
                sc += score[i] * b[i];
            }
            ans = max(ans, sc);
            return;
        }
        solve(idx + 1, words, score);
        for(auto i : words[idx]) b[i - 'a']++;
        solve(idx + 1, words, score);
        for(auto i : words[idx]) b[i - 'a']--;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(auto i : letters) a[i - 'a']++;
        solve(0, words, score);
        return ans;
    }
};
// ****************************************************************************25/05(Word Break II)
class Solution {
public:
    vector<string> ans;
    void solve(int i, string &sentence, string &givenString, unordered_map<string, bool> &doesExist) {
        if (i >= givenString.size()) {
            ans.push_back(sentence);
            return;
        }
        for (int j = i + 1; j <= i + 10  &&  j <= givenString.size(); j++) {
            string word = givenString.substr(i, j - i);
            if (doesExist.find(word) != doesExist.end()) {
                if (sentence.size() == 0) {
                    sentence = word;
                } else {
                    sentence += " " + word;
                }
                solve(j, sentence, givenString, doesExist);
                int x = 0;
                while (x < word.size()) {
                    x++;
                    sentence.pop_back();
                }

                if (sentence.size() > 0) {
                    sentence.pop_back();
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string sentence = "";
        unordered_map<string, bool> doesExist;
        for (auto x: wordDict) {
            doesExist[x] = true;
        }

        ans.clear();
        solve(0, sentence, s, doesExist);
        return ans;
    }
};
// **************************************************************************26/05(Students Attendance)
class Solution {
public:
    const long long mod=1e9+7;
    int checkRecord(int n) {
        int dp[2][2][3]={0};
        fill(&dp[0][0][0], &dp[0][0][0]+6, 1);
        for(int i=1; i<=n; i++){
            for(int j=0; j<=1; j++){
                for(int k=0; k<=2; k++){
                    long long ans=dp[(i-1)&1][j][0];
                    ans+=(k<2?dp[(i-1)&1][j][k+1]:0);
                    ans+=(j==0?dp[(i-1)&1][j+1][0]:0);
                    dp[i&1][j][k]=ans%mod;
                }
            }
        }
        return dp[n&1][0][0];
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// ****************************************************************27/05(Special Array with X Elements Greater than equal to X)
class Solution {
public:
    int n;
    inline int f(int x, vector<int>& nums){
        int i=lower_bound(nums.begin(), nums.end(), x)-nums.begin();
        return n-i;
    }
    inline int g(int x, vector<int>& nums){
        return f(x, nums)-x;
    }
    int specialArray(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(), nums.end());
        int l=0, r=n, m;
        while (l <= r) {
            m = (l+r) / 2;
            int gm = g(m, nums);
            if (gm == 0) return m;
            else if (gm > 0) l = m+1;
            else r = m-1;
        }
        return -1;  
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// ********************************************************************28/05(Get Equal substring within Budget)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start = 0;
        int current_cost = 0;
        int max_length = 0;
        for (int end = 0; end < n; ++end) {
            current_cost += abs(s[end] - t[end]);
            while (current_cost > maxCost) {
                current_cost -= abs(s[start] - t[start]);
                ++start;
            }
            max_length = max(max_length, end - start + 1);
        }
        return max_length;
    }
};
// *********************************************************************29/05(Number of Steps to Reduce a Number in Binary Representation to One)
class Solution {
public:
    int numSteps(string& s) {
        int n=s.size(), div=n-1, add1=0, carry=0, cnt1=0;
        for(int i=n-1; i>0; i--){
            while(i>0 && (s[i]-'0'+carry)&1){
                carry|=s[i]=='1';
                cnt1++;
                i--;
            }
            add1+=cnt1;
            cnt1=0;
            carry|=s[i]=='1';
        }
        return div+add1+carry;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// *****************************************************************30/05(Count Triplets That Can Form Two Arrays of Equal XOR)
class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefix[i] == prefix[k + 1]) {
                    count += (k - i);
                }
            }
        }

        return count;
    }
};
// ******************************************************************31/05(Single Number III)
class Solution {
public:
    static vector<int> singleNumber(vector<int>& nums) {
        int XOR=accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        int i=0;
        while (((XOR >> i) & 1) == 0)
            i++;
        int A=0, B=0;
        for(int x: nums){
            if (((x >> i) & 1) == 0)
                A^=x;
            else
                B^=x; 
        }
        return {A, B};
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// *******************************************************************01/06(Score of a String)
class Solution {
public:
    int scoreOfString(string& s) {
        int n=s.size();
        int ans=0;
        for(int i=1; i<n; i++)
            ans+=abs(s[i]-s[i-1]);
        return ans;        
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
// ***********************************************************************02/06(Reverse String)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
// **************************************************************************03/06(Append Character to string to make subsequence)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_index = 0, t_index = 0;
        int s_length = s.length(), t_length = t.length();
    
        while (s_index < s_length && t_index < t_length) {
            if (s[s_index] == t[t_index]) {
                t_index++;
            }
            s_index++;
        }
    
        return t_length - t_index;
    }
};
// *******************************************************************04/06(Longest Palindrome)
class Solution {
public:
    int longestPalindrome(const std::string& s) {
        std::unordered_set<char> charSet;
        int length = 0;
        for (char c : s) {
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                length += 2;
            } else {
                charSet.insert(c);
            }
        }
        if (!charSet.empty()) {
            length += 1;
        }
        return length;
    }
};
// **********************************************************************05/06(Find Common Character)
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> last = count(words[0]);
        for (int i = 1; i < words.size(); i++) {
            last = intersection(last, count(words[i]));
        }
        
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (last[i] > 0) {
                result.push_back(string(1, 'a' + i));
                last[i]--;
            }
        }
        
        return result;
    }
private:
    vector<int> count(const string& str) {
        vector<int> frequency(26, 0);
        for (char c : str) {
            frequency[c - 'a']++;
        }
        return frequency;
    }
    
    vector<int> intersection(const vector<int>& a, const vector<int>& b) {
        vector<int> t(26, 0);
        for (int i = 0; i < 26; i++) {
            t[i] = min(a[i], b[i]);
        }
        return t;
    }
};
// *************************************************************************06/06(Hand of Straight)
class Solution {
public:
    bool findSuccessors(vector<int>& hand, int groupSize, int i, int n){
        int next = hand[i] + 1;
        hand[i] = -1;
        int count = 1;
        i += 1;
        while(i < n && count < groupSize){
            if(hand[i] == next){
                next = hand[i] + 1;
                hand[i] = -1;
                count++;
            }
            i++;
        }
        return count == groupSize;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       int n = hand.size();
       if(n % groupSize != 0) return false;
       std::sort(hand.begin(), hand.end());
       for(int i = 0; i < n; i++){
        if(hand[i] >= 0){
            if(!findSuccessors(hand, groupSize, i, n)) return false;
        }
       } 
       return true;
    }
};
// **************************************************************************07/06(Replaced words)
class Trie {
public:
    Trie* children[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};
class Solution {
public:
    Trie* root;

    Solution() {
        root = new Trie();
    }
    void insert(string word) {
        Trie* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }
    string search(string word) {
        Trie* node = root;
        string result;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return word;
            }
            result += c;
            if (node->children[i]->isEnd) {
                return result;
            }
            node = node->children[i];
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += search(word);
        }
        return result;
    }
};
// ****************************************************************************08/06(Continuous subarray Sum)
#include <vector>
class Solution {
public:
    bool checkSubarraySum(std::vector<int>& numbers, int divisor) {
        ios::sync_with_stdio(false); 
        cin.tie(0); 
        cout.tie(0);
        int currentSum = numbers[0];
        int length = numbers.size();
        int index, tempSum;
        for (int i = 1; i < length; i++) {
            if (numbers[i] == numbers[i - 1] && numbers[i] == 0) {
                return true;
            }
            currentSum += numbers[i];
            if (currentSum % divisor == 0) {
                return true;
            }
            index = 0;
            tempSum = currentSum;   
            while ((i - index) > 1 && tempSum >= divisor) {
                tempSum -= numbers[index++];
                
                if (tempSum % divisor == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
// **************************************************************************09/06(Subarrays Sum divisible by K)
class Solution {
public:
    static int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod_k(k, 0);
        int prefix=0;
        mod_k[0]=1;

        for(int x: nums){
            prefix=(prefix+x)%k;
            prefix+=((prefix<0)?k:0);
            mod_k[prefix]++;
        }
        return accumulate(mod_k.begin(), mod_k.end(), 0, [](int sum, int x){
            return sum+x*(x-1)/2;
        });
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
// **************************************************************************10/06(Height Checker)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v(heights);
        sort(v.begin(), v.end());
        int count = 0;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != v[i])
            count++;
        }
        return count;
    }
};
// ******************************************************************************11/06(Relative Array sort)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(), n2=arr2.size();
        int a2i[1001];

        fill(a2i, end(a2i), n2);
        for(int i=0; i<n2; i++)
            a2i[arr2[i]]=i;

        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if (a2i[x]==a2i[y]) return x<y;
            return a2i[x]<a2i[y];
        });
        return arr1;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
// ************************************************************************12/06(Sort Colours)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3]={0};
        for(int x: nums)
            freq[x]++;
        int n=nums.size(), count=0;
        for(int x=0; x<3; x++){
            fill(nums.begin()+count, nums.begin()+count+freq[x], x);
            count+=freq[x];
        }
        
    }
};
// *****************************************************************************13/06(Minimum Number of Moves to Seat Everyone)
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
       sort(seats.begin(), seats.end());
       sort(students.begin(), students.end());
        int moves = 0;
        for( int i=0; i<seats.size(); i++)
            moves += abs(seats[i] - students[i]);
        
        return moves;
    }
};
// *****************************************************************************14/06(Minimum Increament of Make Array Unique)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i - 1]){
                ans += nums[ i - 1] - nums[i]+1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }
};
// ******************************************************************************15/06(IPO)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,vector<int>& capital) 
    {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        std::sort(projects.begin(), projects.end());
        std::priority_queue<int> maxHeap;
        int i = 0;
        for (int j = 0; j < k; ++j) {
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            if (maxHeap.empty()) {
                break;
            }
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};
// *******************************************************************************16/06(Patching Pair)
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int result = 0;
        size_t i = 0;
        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                result++;
            }
        }
        return result;
    }
};
// *******************************************************************************17/06(Sum of Square Number)
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int divisor = 2; divisor * divisor <= c; divisor++){
            if( c % divisor == 0){
                int exponentCount = 0;
                while(c % divisor == 0){
                    exponentCount++;
                    c /= divisor;
                }
                if(divisor % 4 == 3 && exponentCount % 2 != 0){
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
};
// ***********************************************************************************18/06(Most Profit Assigning work)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxDifficulty = *max_element(difficulty.begin(), difficulty.end());
        vector<int> maxProfitUpToDifficulty(maxDifficulty + 1, 0);
        for (int i = 0; i < difficulty.size(); ++i) {
            maxProfitUpToDifficulty[difficulty[i]] = max(maxProfitUpToDifficulty[difficulty[i]], profit[i]);
        }
        for (int i = 1; i <= maxDifficulty; ++i) {
            maxProfitUpToDifficulty[i] = max(maxProfitUpToDifficulty[i], maxProfitUpToDifficulty[i - 1]);
        }
        int totalProfit = 0;
        for (int ability : worker) {
            if (ability > maxDifficulty) {
                totalProfit += maxProfitUpToDifficulty[maxDifficulty];
            } else {
                totalProfit += maxProfitUpToDifficulty[ability];
            }
        }
        return totalProfit;
    }
};
// *************************************************************************************19/06(Minimum Number of Days to Make m Bouquets)
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int low = 1, high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }
            if (count == k) {
                total++;
                i--;
            }
            if (total >= m) {
                return true;
            }
        }
        return false;
    }
};
// ******************************************************************************************20/06(Magnetic Force Between Two balls)
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
       sort(position.begin(), position.end());
       int lo = 1;
       int hi = (position.back() - position[0]) / (m - 1);
       int ans = 1;
       while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(canWePlace(position, mid, m)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
       } 
       return ans;
    }
    private:
    bool canWePlace(const vector<int>& arr, int dist, int balls){
        int countBalls = 1;
        int lastPlaced = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = arr[i];
            }
            if(countBalls >= balls){
                return true;
            }
        }
        return false;
    }
};
// *****************************************************************************************21/06(Grumpy Bookstor Owner)
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initialSatisfaction = 0;
        int maxExtraSatisfaction = 0;
        int currentWindowSatisfaction = 0;
        
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                initialSatisfaction += customers[i];
            } else if (i < minutes) {
                currentWindowSatisfaction += customers[i];
            }
        }
        
        maxExtraSatisfaction = currentWindowSatisfaction;
        
        for (int i = minutes; i < customers.size(); ++i) {
            currentWindowSatisfaction += customers[i] * grumpy[i];
            currentWindowSatisfaction -= customers[i - minutes] * grumpy[i - minutes];
            maxExtraSatisfaction = max(maxExtraSatisfaction, currentWindowSatisfaction);
        }
        
        return initialSatisfaction + maxExtraSatisfaction;   
    }
};
// ***************************************************************************************22/06(Count Number of Nice Subarray)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for(int v : nums){
            t += v & 1;
            if(t - k >= 0){
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
};
// *************************************************************23/06(Longest Continuous SubarrayWith Absolute Diff Less Than or Equal to limit)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> increase;
        deque<int> decrease;
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (!increase.empty() && nums[right] < increase.back()) {
                increase.pop_back();
            }
            increase.push_back(nums[right]);
            while (!decrease.empty() && nums[right] > decrease.back()) {
                decrease.pop_back();
            }
            decrease.push_back(nums[right]);
            while (decrease.front() - increase.front() > limit) {
                if (nums[left] == decrease.front()) {
                    decrease.pop_front();
                }
                if (nums[left] == increase.front()) {
                    increase.pop_front();
                }
                ++left;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};
// ***************************************************************************24/06(Minimum NUmber of K Consecutive Bit Flip)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipped = 0;
        int res = 0;
        vector<int> isFlipped(n, 0);
        for(int i = 0; i < n; ++i){
            if(i >= k) {
                flipped ^= isFlipped[ i - k];
            }
            if( flipped == nums[i]) {
                if( i + k > n){
                    return -1;
                }
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};
// ******************************************************************************25/06(Binary Search Tree to Greater sum tree)
class Solution {
private:
    int sum = 0;
    void traverse(TreeNode* root){
        if(root) {
            traverse(root -> right);
            sum += root -> val;
            root -> val = sum;
            traverse(root -> left);
        }
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};
// ********************************************************************************26/06(Balance a Binary Search Tree)
class Solution {
public:
    vector<TreeNode*> sortedArr;
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return sortedArrayToBST(0, sortedArr.size() - 1);
    }
    void inorderTraverse(TreeNode* root) {
        if (root == NULL) return;
        inorderTraverse(root->left);
        sortedArr.push_back(root);
        inorderTraverse(root->right);
    }
    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = sortedArr[mid];
        root->left = sortedArrayToBST(start, mid - 1);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};
// ***********************************************************************************27/06(Find Cneter of Star Graph)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};
// **********************************************************************************28/06(Maximum Total Importance of Roads)
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0); 
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        vector<int> cities(n);
        for (int i = 0; i < n; i++) {
            cities[i] = i;
        }
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        long long totalImportance = 0;
        for (int i = 0; i < n; i++) {
            totalImportance += (long long)(n - i) * degree[cities[i]];
        }
        return totalImportance;
    }
};
// *********************************************************************************29/06(All Ancestor of a Node in a Directed Acyclic Graph)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        for (int i = 0; i < n; ++i) {
            vector<bool> visit(n, false);
            dfs(graph, i, i, res, visit);
        }
        
        for (int i = 0; i < n; ++i) {
            sort(res[i].begin(), res[i].end());
        }
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& graph, int parent, int curr, vector<vector<int>>& res, vector<bool>& visit) {
        visit[curr] = true;
        for (int dest : graph[curr]) {
            if (!visit[dest]) {
                res[dest].push_back(parent);
                dfs(graph, parent, dest, res, visit);
            }
        }
    }
};
// *******************************************************************************30/06(Remove Max Number of Edges to Keep Graph Fully Traversable)
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        class UnionFind {
        public:
            vector<int> parent, size;
            int components;
            UnionFind(int n) {
                components = n;
                parent.resize(n + 1);
                size.resize(n + 1, 1);
                for (int i = 0; i <= n; ++i) {
                    parent[i] = i;
                }
            }
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }
            bool unite(int x, int y) {
                int rootX = find(x), rootY = find(y);
                if (rootX == rootY) return false;
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components--;
                return true;
            }
            bool isConnected() {
                return components == 1;
            }
        };
        UnionFind alice(n), bob(n);
        int edgesRequired = 0;        
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - edgesRequired;
        }      
        return -1;
    }
};
// ********************************************************************************01/07(Three Consecutive Odds)
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