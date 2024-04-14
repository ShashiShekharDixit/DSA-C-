// ****************************************Permute two arrays such that sum of every pair is greater to k*************************
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
// bool isPossible(int a[], int b[], int n, int k)
// {
//     sort(a, a + n);
//     sort(b, b + n, greater<int>());
//     for (int i =0; i < n; i++)
//     if (a[i] + b[i] < k)
//     return false;
//     return true;
// }
// int main()
// {
//     int a[] = { 2, 1, 3 };
//     int b[] = { 7, 8, 9 };
//     int k = 10;
//     int n = sizeof(a) / sizeof(a[0]);
//     isPossible(a, b, n, k) ? cout << " Yes " : cout << "No";
//     return 0;
// }
// ******************************************************************Counting sort**************************************************************
// #define Range 255
// void countSort(char arr[])
// {
//     char output[strlen(arr)];
//     int count[Range + 1], i;
//     memset(count, 0, sizeof(count));
//     for (i = 0; arr[i]; ++i)
//     ++count[arr[i]];
//     for (i = 1; i <= Range; ++i)
//     count[i] += count[i - 1];
//     for ( i = 0; arr[i]; ++i) {
//         output[count[arr[i]] - 1] = arr[i];
//         --count[arr[i]];
//     }
//     for (i = 0; arr[i]; ++i)
//     arr[i] = output[i];
// }
// int main()
// {
//     char arr[] = "geeksforgeeks";
//     countSort(arr);
//     cout << "Sorted character array is : " << arr;
//     return 0;
// }
// ******************************************************Find common element in 3 arrays*******************************************************
// void FindIntersection(int arr1[], int arr2[], int temp[], int m, int n, int& k)
// {
//     int i = 0, j = 0;
//     while(i < m && j < n) {
//         if(arr1[i] < arr2[j]){
//         i++;
//     }
//     else if (arr2[j] < arr1[i])
//     {
//         j++;
//     }
//     else {
//         temp[k] = arr1[i];
//         i++;
//         j++;
//         k++;
//     }
//   }
// }
// int main()
// {
//     int arr1[] = { 1, 5, 10, 20, 40, 80 };
//     int arr2[] = { 6, 7, 20, 80, 100 };
//     int arr3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);
//     int n3 = sizeof(arr3) / sizeof(arr3[0]);
//     int temp[200000];
//     int ans[200000];
//     int k = 0;
//     FindIntersection(arr1, arr2, temp, n1, n2, k);
//     int tempSize = k;
//     k = 0;
//     FindIntersection(arr3, temp, ans, n3, tempSize, k);
//     cout << " Common element present in arrays are : \n";
//     for (int i = 0; i < k; i++)
//     {
//         cout<<ans[i] << " "; 
//     }
//     cout<< endl;
//     return 0;
// }
// ***********************************************Searching in an array where adjacent differ by at most k*************************************
// int search(int arr[], int n, int x, int k)
// {
//     int i = 0;
//     while(i < n)
//     {
//         if (arr[i] == x)
//         return i;
//         i = i + max(1, abs(arr[i] - x)/k);
//     } 
//     cout << " number in not present! ";
//     return -1;
// }
// int main()
// {
//     int arr[] = { 2, 4, 5, 7, 7, 6 };
//     int x = 6;
//     int k = 2;
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout << " Element " << x << " is present at index " << search(arr, n, x, k);
//     return 0;
// }
// ******************************************************Ceiling in a sorted array*************************************************************
// int ceilSearch(int arr[], int low, int high, int x)
// {
//     int i;
//     if(x <= arr[low])
//     return low;
//     for(i = low; i < high; i++)
//     {
//         if(arr[i] == x)
//         return i;
//         if(arr[i] < x && arr[i+1] >= x)
//         return i + 1;
//     }
//     return -1;
// }
// int main()
// {
//     int arr[] = { 1, 2, 8, 10, 10, 12, 19 };
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int x = 3;
//     int index = ceilSearch(arr, 0, n-1, x);
//     if (index == -1)
//     cout << " Ceiling of " << x << " doesn't exist in array ";
//     else
//     {
//         cout << " Ceiling of " << x << " is " << arr[index];
//     }
//     return 0;
// }
// ****************************************************Find a pair with the given difference***************************************************
// void findPair(int arr[], int n, int diff) {
//     for (int i=0; i<n; i++) {
//       for (int j =0; j < n; j++){
//         if(i == j)
//         continue;

//          if((arr[j] - arr[i]) == diff) {
//             cout << " Pair Found: (" << arr[i] << "," << arr[j] << ")";
//             return;
//          }
//        }
//     }
//     cout << " No such pair ";
// }
// int main()
// {
//     int arr[] ={ 1, 8, 30, 40, 100 };
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int diff = -60;
//     findPair(arr, n, diff);
//     return 0;
// }
// ************************************************************Majority Element***************************************************************
// void findMajority(int arr[], int n)
// {
//     int maxCount = 0;
//     int index = -1;
//     for (int i = 0; i < n; i++) {
//         int count = 0;
//         for (int j =0; j < n; j++) {
//             if (arr[i] == arr[j])
//             count++;
//         }
//         if (count > maxCount){
//             maxCount = count;
//             index = i;
//         }
//     }
//     if (maxCount > n / 2)
//     cout << arr[index] << endl;
//     else
//     cout << " No Majority Element " << endl;
// }
// int main()
// {
//     int arr[] = { 1, 1, 2, 1, 3, 5, 1 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     findMajority(arr, n);
//     return 0;
// }
// ****************************************************Count triplet with sum smaller than a given value******************************************
// int countTriplets(int arr[], int n, int sum)
// {
//     int ans = 0;
//     for (int i =0; i < n - 2; i++){
//         for (int j =i + 1; j < n - 1; j++) {
//             for (int k = j + 1; k < n; k++)
//             if (arr[i] + arr[j] + arr[k] < sum)
//             ans++;
//         }
//     }
//     return ans;
// }
// int main()
// {
//    int arr[] = { 5, 1, 3, 4, 7 };
//    int n = sizeof arr / sizeof arr[0];
//    int sum = 12;
//    cout << countTriplets(arr, n, sum) << endl;
//    return 0;
// }
// **********************************************Maximum sum such that no two elements are adjacent************************************************
// int rec(vector<int>& nums, int idx, vector<int>& dp)
// {
//     if (idx >= nums.size())
//     return 0;
//     if (dp[idx] != -1)
//     return dp[idx];
//     return dp[idx] = max(rec(nums, idx + 1, dp), nums[idx] + rec(nums, idx + 2, dp));
// }
// int findMaxSum(vector<int>& nums, int N)
// {
//     vector<int> dp(N + 1, -1);
//     return rec(nums, 0, dp);
// }
// int main()
// {
//     vector<int> arr = { 5, 5, 10, 100, 10, 5 };
//     int N = arr.size();
//     cout << findMaxSum(arr, N) << endl;
//     return 0;
// }
// ****************************************************Merge two  sorted arrays with 0(1) extra space*******************************************
// void merge(int ar1[], int ar2[], int m, int n)
// {
//     for(int i = n - 1; i >= 0; i--) {
//         int j, last = ar1[m - 1];
//         for(j = m - 2; j >= 0 && ar1[j] > ar2[i]; j--)
//         ar1[j + 1] = ar1[j];
//         if(last > ar2[i]) {
//             ar1[j + 1] = ar2[i];
//             ar2[i] = last;
//         }
//     }
// }
// int main()
// {
//     int ar1[] = { 1, 5, 9, 10, 15, 20 };
//     int ar2[] ={ 2, 3, 8, 13 };
//     int m = sizeof(ar1) / sizeof(ar1[0]);
//     int n = sizeof(ar2) / sizeof(ar2[0]);
//     merge(ar1, ar2, m, n);
//     cout << " After Merging \nFirst Arrays: ";
//     for (int i =0; i < m; i++)
//     cout<<ar1[i]<<" ";
//     cout << "\nSecond Array : ";
//     for (int i = 0; i < n; i++)
//     cout << ar2[i] << " ";
//     return 0;
// }
// *************************************************************Count Inversion*****************************************************************
// int getInvCount (int arr[], int n)
// {
//     int inv_count = 0;
//     for (int i = 0; i < n - 1; i++)
//     for (int j = i + 1; j < n; j++)
//     if (arr[i] > arr[j])
//     inv_count++;
//     return inv_count;
// }
// int main()
// {
//     int arr[] = { 1, 20, 6, 4, 5 };
//     int n = sizeof(arr)/ sizeof(arr[0]);
//     cout << "Number of inversions are " << getInvCount(arr, n);
//     return 0;
// }
// **************************************Find duplicate in 0(n) time and 0(1) extra space******************************************************
// int main ()
// {
//     int numRay[] ={ 0, 4, 3, 2, 7, 8, 2, 3, 1 };
//     int arr_size = sizeof(numRay) / sizeof(numRay[0]);
//     for (int i =0; i < arr_size; i++)
//     {
//         numRay[numRay[i] % arr_size] = numRay[numRay[i] % arr_size] + arr_size;
//     }
//     cout << " The repeating elements are : " << endl;
//     for (int i = 0; i < arr_size; i++){
//         if(numRay[i] >= arr_size * 2) {
//             cout << i << " " << endl;
//         }
//     }
//     return 0;
// }
// *****************************************************************Radix Sort**********************************************************
// int getMax(int arr[], int n)
// {
//     int mx = arr[0];
//     for (int i=1; i < n; i++)
//     if (arr[i] > mx)
//     mx = arr[i];
//     return mx;
// }
// void countSort(int arr[], int n, int exp)
// {
//     int output[n];
//     int i, count[10] = {0};
//     for (i = 0; i <n; i++)
//     count[(arr[i] / exp) % 10]++;
//     for (i = 1; i < 10; i++)
//     count[i] += count[i - 1];
//     for (i = n - 1; i >= 0; i--) {
//         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//         count[(arr[i] / exp) % 10]--;
//     }
//     for ( i = 0; i < n; i++)
//     arr[i] = output[i];
// }
// void radixsort(int arr[], int n)
// {
//     int m = getMax(arr, n);
//     for (int exp = 1; m / exp > 0; exp += 10)
//     countSort(arr, n, exp);
// }
// void print(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     cout << arr[i] << " ";
// }
// int main()
// {
//     int arr[] = { 543, 986, 217, 765, 329 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     radixsort(arr, n);
//     print(arr, n);
//     return 0;
// }
// ********************************************************Product of Array except itself******************************************************
// void productArray(int arr[], int n)
// {
//     if (n == 1) {
//         cout << 0;
//         return;
//     }
//     int* left = new int[sizeof(int) * n];
//     int* right = new int[sizeof(int) * n];
//     int* prod = new int[sizeof(int) * n];
//     int i, j;
//     left[0]= 1;
//     right[n - 1] = 1;
//     for (i = 1; i < n; i++)
//     left[i] = arr[i - 1] * left[i - 1];
//     for (j = n - 2; j >= 0; j--)
//     right[j] = arr[j + 1] * right[j + 1];
//     for( i = 0; i < n; i++)
//     prod[i] = left[i] * right[i];
//     for(i = 0; i < n; i++)
//     cout << prod[i] << " ";
//     return;
// }
// int main()
// {
//     int arr[] = { 10, 3, 5, 6, 2 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "The Product array is : \n";
//     productArray(arr, n);
// }
// **************************************************Make all array elements equal with minimum cost********************************************
// int computeCost(int arr[], int N, int X)
// {
//     int cost = 0;
//     for ( int i =0; i < N; i++)
//     cost += abs(arr[i] - X);
//     return cost ;
// }
// int minCostToMakeElementEqual(int arr[], int N)
// {
//     int low, high;
//     low = high = arr[0];
//     for (int i =0; i < N; i++)
//     {
//         if (low > arr[i])
//         low = arr[i];
//         if (high < arr[i])
//         high = arr[i];
//     }
//     while ((high - low) > 2) {
//         int mid1 = low + (high - low) / 3;
//         int mid2 = high -(high - low) / 3;
//         int cost1 = computeCost(arr, N, mid1);
//         int cost2 = computeCost(arr, N, mid2);
//         if (cost1 < cost2)
//         high = mid2;
//         else
//         low = mid1;
//     }
//     return computeCost(arr, N, (low + high) / 2);
// }
// int main()
// {
//     int arr[] = { 1, 100, 101 };
//     int N = sizeof(arr) / sizeof(int);
//     cout << minCostToMakeElementEqual(arr, N);
//     return 0;
// }
// ************************************************Check if reversing a sub array make the array sorted******************************************
// bool checkRaverse(int arr[], int n)
// {
//     int temp[n];
//     for (int i = 0; i < n; i++)
//     temp[i] = arr[i];
//     sort(temp, temp + n);
//     int front;
//     for (front = 0; front < n; front++)
//     if (temp[front] != arr[front])
//     break;
//     int back;
//     for (back = n - 1; back >= 0; back--)
//     if (temp[back] != arr[back])
//     break;
//     if (front >= back)
//     return true;
//     do {
//         front++;
//         if (arr[front - 1] < arr[front])
//         return false;
//     }while (front != back);
//     {
//         return true;
//     }
// }
// int main()
// {
//     int arr[] = { 1, 2, 5, 4, 3 };
//     int n = sizeof(arr)/sizeof(arr[0]);
//     checkRaverse(arr, n)? (cout << " Yes " << endl):
//     cout << " No " << endl;
//     return  0 ;
// }
// *****************************************************Find four element that sum to a given value(4Sum)****************************************
// class PairSum {
//     public:
//     int first;
//     int sec;
//     int sum;
// };
// int compare(const void* a, const void* b)
// {
//     return ((*(PairSum*)a).sum - (*(PairSum*)b).sum);
// }
// bool noCommon(PairSum a, PairSum b)
// {
//     if (a.first == b.first || a.first == b.sec || a.sec == b.first || a.sec == b.sec)
//     return false;
//     return true;
// }
// void findFourElements(int arr[], int n, int X)
// {
//     int i, j;
//     int size = (n * (n - 1)) / 2;
//     PairSum aux[size];
//     int k = 0;
//     for ( i = 0; i < n - 1; i++) {
//         for ( j = i + 1; j < n; j++)
//         {
//             aux[k].sum = arr[i] + arr[j];
//             aux[k].first = i;
//             aux[k].sec = j;
//             k++;
//         }
//     }
//     qsort(aux, size, sizeof(aux[0]), compare);
//     i = 0;
//     j = size - 1;
//     while ( i < size && j >= 0) {
//         if ((aux[i].sum + aux[j].sum == X) && noCommon(aux[i], aux[j])) {
//             cout << arr[aux[i].first] << ", " << arr[aux[i].sec] << ", " << arr[aux[j].first] << ". " << arr[aux[j].sec] << endl;
//             return;
//         }
//         else if (aux[i].sum + aux[j].sum < X)
//         i++;
//         else
//         j--;
//     }
// }
// int main()
// {
//     int arr[] = { 10, 20, 30, 40, 1, 2 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int X = 91;
//     findFourElements(arr, n, X);
//     return 0;
// }
//  **************************************************Median of Two Sorted Arrays of Different Sizes*******************************************
// int Solution(int arr[], int n)
// {
//     if ( n % 2 == 0) {
//         int z = n / 2;
//         int e = arr[z];
//         int q = arr[z - 1];
//         int ans = (e + q) / 2;
//         return ans;
//     }
//     else
//     {
//         int z = round(n / 2);
//         return arr[z];
//     }
// }
// int main()
// {
//     int arr1[] = { -5, 3, 6, 12, 15 };
//     int arr2[] = { -12, -10, -6, -3, 4, 10 };
//     int i = sizeof(arr1) / sizeof(arr1[0]);
//     int j = sizeof(arr2) / sizeof(arr2[0]);
//     int arr3[i + j];
//     int l = i + j;
//     for (int k = 0; k < i; k++) {
//         arr3[k] = arr1[k];
//     }
//     int a = 0;
//     for (int k = i; k < l; k++) {
//         arr3[k] = arr2[a++];
//     }
//     sort(arr3, arr3 + l);
//     cout << "The median is: " << Solution(arr3, l);
// }
// *******************************************************Median in a stream of Integers********************************************************
// int binarySearch(float arr[], float item, int low, int high)
// {
//     if (low >= high) {
//         return (item > arr[low]) ? (low + 1) : low;
//     }
//     int mid = (low + high) / 2;
//     if (item == arr[mid])
//     return mid + 1;
//     if (item > arr[mid])
//     return binarySearch(arr, item, mid + 1, high);
//     return binarySearch(arr, item, low, mid - 1);
// }
// void printMedian(float arr[], int n)
// {
//     int i, j, pos;
//     float num;
//     int count = 1;
//     cout << " Median after reading 1" << " element is  : " << arr[0] << "\n";
//     for (i = 1; i < n; i++) {
//         float median;
//         j = i - 1;
//         num = arr[i];
//         pos = binarySearch(arr, num, 0, j);
//         while (j >= pos) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = num;
//         count++;
//         if (count % 2 != 0){
//         median = arr[count / 2];
//         }
//         else {
//             median = (arr[(count / 2) - 1] + arr[count / 2])/2; 
//         }
//         cout << " Median after reading " << i + 1  << "elements is : " << median << "\n";
//     }
// }
// int main()
// {
//     float arr[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printMedian(arr, n);
//     return 0;
// }
// *******************************************************Print all subarrays with 0 sum*******************************************************
// vector<pair<int, int> > findSubArrays(int arr[], int n)
// {
//     vector<pair<int, int> > output;
//     for (int i =0; i < n; i++){
//         int prefix = 0;
//         for (int j = i; j < n; j++) {
//             prefix += arr[j];
//             if (prefix == 0)
//             output.push_back({ i, j });
//         }
//     }
//     return output;
// }
// void print(vector<pair<int, int> > output)
// {
//     for (auto it = output.begin(); it != output.end(); it++)
//     cout << "Subarray found from Index " << it->first << " to " << it->second<< endl;
// }
// int main()
// {
//     int arr[] = { 6, 3, -1, -3, 4, -2, 4, 6, -12, -7 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     vector<pair<int, int> > output = findSubArrays(arr, n);
//     if (output.size() == 0) {
//         cout << " No subarray exists ";
//     }
//     else {
//         print(output);
//     }
//     return 0;
// }
// *************************************************Minimum Number of swaps required to sort an array********************************************
// int minSwaps(int arr[], int n)
// {
//     pair<int , int> arrPos[n];
//     for (int i =0; i < n; i++) {
//         arrPos[i].first = arr[i];
//         arrPos[i].second = i;
//     }
//     sort(arrPos, arrPos + n);
//     vector<bool> vis(n, false);
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (vis[i] || arrPos[i].second == i)
//         continue;
//         int cycle_size = 0;
//         int j = i;
//         while (!vis[j])
//         {
//             vis[j] = 1;
//             j = arrPos[j].second;
//             cycle_size++;
//         }
//         if (cycle_size > 0) {
//             ans += (cycle_size - 1);
//         }
//     }
//     return ans;
// }
// int main()
// {
//     int arr[] = { 1, 5, 4, 3, 2 };
//     int n = ( sizeof(arr) / sizeof(int));
//     cout << minSwaps(arr, n);
//     return 0;
// }
// ***********************************************************First and Last Occurence**********************************************************
// void findFirstAndLast(int arr[], int n, int x)
// {
//     int first = -1, last = -1;
//     for(int i =0; i < n; i++) {
//         if (x != arr[i])
//         continue;
//         if (first == -1)
//         first = i;
//         last = i;
//     }
//     if (first != -1)
//     cout << "First Occurence = " << first <<"\nLast Occurence = " << last;
//     else
//     cout << "Not Found";
// }
// int main()
// {
//     int arr[] ={ 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
//     int n = sizeof(arr) / sizeof(int);
//     int x = 8;
//     findFirstAndLast(arr, n, x);
//     return 0;
// }
// ***************************************************value equal to index***********************************************************
// int binarySearch(int arr[], int low, int high)
// {
//     if (high >= low) {
//         int mid = low +(high - low) / 2;
//         if(mid == arr[mid])
//         return mid;
//         int res = -1;
//         if (mid + 1 <= arr[high])
//         res = binarySearch(arr, (mid + 1), high);
//         if (res != -1)
//         return res;
//         if (mid - 1 >= arr[low])
//         return binarySearch(arr, low, (mid - 1));
//     }
//     return -1;
// }
// int main()
// {
//     int arr[10] = { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout << "Fixed Point is " << binarySearch(arr, 0, n -1);
//     return 0;
// }
// *****************************************************Search an element in a sorted and rotated Array*****************************************
// int binarySearch(int arr[], int low, int high, int key)
// {
//     if (high < low)
//     return -1;
//     int mid = (low + high) / 2;
//     if (key == arr[mid])
//     return mid;
//     if (key > arr[mid])
//     return binarySearch(arr, (mid + 1), high, key);
//     return binarySearch(arr, low, (mid - 1), key);
// }
// int findPivot(int arr[], int low, int high)
// {
//     if (high < low)
//     return -1;
//     if (high == low)
//     return low;
//     int mid = (low + high) / 2;
//     if (mid < high && arr[mid] > arr[mid + 1])
//     return mid;
//     if (mid > low && arr[mid] < arr[mid - 1])
//     return (mid - 1);
//     if (arr[low] >= arr[mid])
//     return findPivot(arr, low, mid - 1);
//     return findPivot(arr, mid + 1, high);
// }
// int pivotedBinarySearch(int arr[], int n, int key)
// {
//     int pivot = findPivot(arr, 0, n - 1);
//     if(pivot == -1)
//     return binarySearch(arr, 0, n - 1, key);
//     if (arr[pivot] == key)
//     return pivot;
//     if (arr[0] <= key)
//     return binarySearch(arr, 0, pivot-1 , key );
//     return binarySearch(arr, pivot + 1,n - 1, key);
// }
// int main()
// {
//     int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
//     int n = sizeof(arr1) / sizeof(arr1[0]);
//     int key = 3;
//     cout << " Index of the element is : " << pivotedBinarySearch(arr1, n, key);
//     return 0;
// }
// **************************************************************Count Square***************************************************************
// int countNumbers(int N)
// {
//     return int(sqrt(N)) - 1;
// }
// int main()
// {
//     int N = 36;
//     cout << countNumbers(N);
//     return 0;
// }
***************************************************