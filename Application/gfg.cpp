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