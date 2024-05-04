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