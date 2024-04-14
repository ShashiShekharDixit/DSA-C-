// ****************************************************************Minimum and Maximum**********************************************
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// struct Pair{
//     int min;
//     int max;
// };
// Pair getMinMax(int arr[], int n)
// {
//     Pair minmax;
//     std::sort(arr, arr + n);
//     minmax.min = arr[0];
//     minmax.max = arr[n - 1];
//     return minmax;
// }
// int main()
// {
//     int arr[] = { 1000, 56, 78, 4, 66, 89};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);
//     Pair minmax = getMinMax(arr, arr_size);
//     std::cout<<"Minimum element is : " << minmax.min <<std::endl;
//     std::cout<<"Maximum element is : " << minmax.max <<std::endl;
//     return 0;
// }
// **********************************************************Reverser the Array*****************************************************
// void reverseArray(int arr[], int start, int end)
// {
//     if(start >= end)
//     return;
//     int temp = arr[start];
//     arr[start] = arr[end];
//     arr[end] = temp;
//     reverseArray(arr, start + 1, end - 1);
// }
// void printArray(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     cout<<arr[i] << " ";
//     cout <<endl;
// }
// int main()
// {
//     int arr[] = {1,3,45,5,7,8};
//     cout<<"Before Reversing array is" <<endl;
//     printArray(arr, 6);
//     reverseArray(arr, 0, 5);
//     cout<<"Reversed array is" <<endl;
//     printArray(arr, 6);
//     return 0;
// }
// **********************************************************Maximum subarray********************************************************
// int main()
// {
//     int n,i,j,k;
//     cin>>n;
//     int a[n];
//     for(i=0;i<n;i++)
//     cin>>a[i];
//     int sum, msum;
//     for(i=0;i<n;i++)
//     {
//         if(i==0)
//         {
//             sum = a[i];
//             msum =sum;
//         }
//         else{
//             sum=max(sum+a[i],a[i]);
//             msum=max(sum,msum);
//         }
//     }
//     cout<<msum<<endl;
//     return 0;
// }
// **************************************************************Contain Duplicate*****************************************************
// bool containsDuplicate(int arr[], int size)
// {
//     bool flag = false;
//     for(int i =0; i<size; i++)
//     {
//         for(int j =i+1; j<size; j++)
//         {
//             if(arr[i]==arr[j])
//             {
//                 flag = true;
//             }
//         }
//     }
//     if(flag==true)
//     {
//         return true;
//     }
//     else
//     {
//      return false;
//     }
// }
// int main()
// {
//     int arr[]={34,49,56,21,46};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     if(containsDuplicate(arr,size))
//     {
//         cout<<"The array Contains Duplicates" <<endl;
//     }
//     else
//     {
//         cout<<"The Array doesn't conatins duplicate" <<endl;
//     }
//     return 0;
// }
// ***********************************************Binary Search***************************************************************************
// int binarySearch(int arr[], int size, int key)
// {
//     int start = 0;
//     int end = size-1;
//     int mid = (start + end)/2;
//     //if int value is (2^31-1) then we use [start + (end-start)/2]
//     while(start <= end)
//     {
//       if(arr[mid] == key)
//       {
//         return mid;
//       }
//       if(key > arr[mid])
//       {
//         start = mid + 1;
//       }
//       else{
//         end = mid - 1;
//       }
//       mid = (start + end)/2;
//     //same as line no 8  
//     }
//     return -1;
// }
// int main()
// {
//      int even[6] = {3,6,7,8,12,13};
//      int odd[5] = {2,14,15,17,19};
//      int evenIndex = binarySearch(even, 6, 27);
//      cout<<"Index of 27 is "<<evenIndex <<endl;
//      int oddIndex = binarySearch(odd, 5, 37);
//      cout<<"Index of 37 is "<<oddIndex <<endl;
//      return 0;
// }
// *****************************************************************Distribution Problem************************************************
// int findMinDiff(int arr[], int n, int m)
// {
//     if (m == 0 || n == 0)
//     return 0;
//     sort(arr, arr + n);
//     if (n < m)
//     return -1;
//     int min_diff = INT_MAX;

//     for (int i = 0; i + m - 1 < n; i++) {
//         int diff = arr[i + m - 1] - arr[i];
//     if (diff < min_diff)
//     min_diff = diff;
//     }
//     return min_diff;
// }
// int main()
// {
//     int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};
//     int m = 5;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Minimum difference is " <<findMinDiff(arr, n, m);
//     return 0;
// }
// *******************************************************************Search in sorted rotated array*************************************
// bool solve(vector<int> arr, int left, int right, int key) {
//     if (left > right) {
//         return false;
//     }
//     int mid = (left + right)/2;
//     if (arr[mid] == key) {
//         return true;
//     }
//     if (arr[left] <= arr[mid]) {
//         if (key >= arr[left] && key <= arr[mid]) {
//             return solve(arr, left, mid-1, key);
//         }
//         return solve(arr, mid+1, right, key);
//     }
//     if (key >= arr[mid] && key <= arr[right])
//     return solve(arr, mid+1, right, key);
//     return solve(arr, left, mid-1, key);
// }
// int main()
// {
//     vector<int> arr = {4,5,6,7,0,1,2};
//     int key = 3;
//     if(solve(arr, 0, arr.size()-1, key)) 
//     cout<<key<<" is present";
//     else
//     cout<<key<<" is not present";
//     return 0;
// }
// **************************************************************Next Permutation********************************************************
// void reverse(std::vector<int>& nums, int start, int end) {
//     while (start < end) {
//         std::swap(nums[start], nums[end]);
//         start++;
//         end--;
//     }
// }
// void nextPermutation(std::vector<int>& nums) {
//     int n = nums.size();
//     int i = n - 2;
//     while (i >= 0 && nums[i] >= nums[i+1]) {
//         i++;
//     }
//     if (i >= 0) {
//         int j = n - 1;
//         while (j >= 0 && nums[j] <= nums[i]) {
//             j--;
//         }
//         std::swap(nums[i], nums[j]);
//     }
//     reverse(nums, i+1, n-1);
// } 
// int main()
// {
//     std::vector<int> nums = {1, 2, 3};
//     nextPermutation(nums);
//     for (int num : nums) {
//         std::cout << num << " ";
//     }
//     return 0;
// }
// *********************************************************Buy and Sell Stock************************************************************
// int maxProfit(int prices[], int n)
// {
//     int buy = prices[0], max_profit = 0;
//     for (int i = 1 ; i < n; i++){
//         if (buy > prices[i])
//         buy = prices[i];
//         else if (prices[i] - buy > max_profit)
//         max_profit = prices[i] - buy;
//     }
//     return max_profit;
// }
// int main()
// {
//     int prices[] = { 7, 1, 5, 6, 4 };
//     int n = sizeof(prices) / sizeof(prices[0]);
//     int max_profit = maxProfit(prices, n);
//     cout<< max_profit <<endl;
//     return 0;
// }
// *************************************************************Repeat amd Missing Number Array********************************************
// void printTwoElements(int arr[], int n)
// {
//     int temp[n] = {};
//     int repeatingNumber = -1;
//     int missingNumber = -1;
//     for (int i = 0; i < n; i++){
//         temp[arr[i]-1]++;
//         if (temp[arr[i] - 1] > 1) {
//             repeatingNumber = arr[i]; 
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (temp[i] == 0) {
//             missingNumber = i + 1;
//             break;
//         }
//     }
//     cout << " The repeating number is " << repeatingNumber<<"."<<endl;
//     cout << " The missing number is " << missingNumber<<"."<<endl;
// }
// int main()
// {
//     int arr[] = { 7, 3, 4, 5, 5, 6, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printTwoElements(arr, n);
//     return 0;
// }
// **************************************************************Trapping Rain Water*****************************************************
// int maxWater(int arr[], int n)
// {
//     int res = 0;
//     for (int i =1; i < n - 1; i++) {
//         int left = arr[i];
//         for (int j = 0; j < i; j++)
//         left = max(left, arr[j]);
//         int right = arr[i];
//         for (int j = i + 1; j < n; j++)
//         right = max(right, arr[j]);
//         res = res + (min(left, right) - arr[i]);
//     }
//     return res;
// }
// int main()
// {
//     int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << maxWater(arr, n);
//     return 0;
// }
// ********************************************************************Product of Array except self************************************
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
//     left[0] = 1;
//     right[n - 1] = 1;
//     for (i = 1; i < n; i++)
//     left[i] = arr[i - 1] * left[i - 1];
//     for(j = n - 2; j >= 0; j--)
//     right[j] = arr[j + 1] * right[j + 1];
//     for(i = 0; i < n; i++)
//     prod[i] = left[i] * right[i];
//     for(i = 0; i < n; i++)
//     cout <<prod[i] << " ";
//     return;
// }
// int main()
// {
//     int arr[] = { 10, 3, 5, 6, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << " The product array is: \n";
//     productArray(arr, n);
// }
// *****************************************************************Maximum Product Subarray************************************************
// int maxSubarrayProduct(int arr[], int n)
// {
//     int result = arr[0];
//     for (int i = 0; i < n; i++) {
//         int mul = arr[i];
//         for (int j = i + 1; j < n; j++) {
//             result = max(result, mul);
//             mul *= arr[j];
//         }
//         result = max(result, mul);
//     }
//     return result;
// }        
// int main()
// {
//     int arr[] = { 2, 3, -2, 4 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << " Maximum Sub arrsy product is " << maxSubarrayProduct(arr, n);
//     return 0;
// }
// **************************************************Find minimum element in a sorted and rotated array**********************************
// int findMin(int arr[], int n)
// {
//     int min_element = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] < min_element){
//             min_element = arr[i];
//         }
//     }
//     return min_element;
// }
// int main()
// {
//     int arr[] = { 4, 5, 6, 7, 0, 1, 2};
//     int N = sizeof(arr, N) / sizeof(arr[0]);
//     cout << findMin(arr, N) << endl;
//     return 0;
// }
// ********************************************Find if there is pair with a given sum in rotated sorted array*****************************
// bool pairInSortedrotated(int arr[], int n, int x)
// {
//     int i;
//     for (i = 0; i < n - 1; i++)
//     if (arr[i] > arr[i + 1])
//     break;
//     int l = (i + 1) % n;
//     int r = i;
//     while (l != r) {
//         if (arr[l] + arr[r] == x)
//         return true;
//         if (arr[l] + arr[r] < x)
//         l = (l + 1) % n;
//         else
//         r = (n + r - 1) % n;
//     }
//     return false;
// }
// int main()
// {
//     int arr[] = { 11, 15, 6, 8, 9, 10 };
//     int x = 16;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     if (pairInSortedrotated(arr, n, x))
//     cout << "true";
//     else
//     cout<<"false";
//     return 0;
// }
// ***************************************************Find triplet that sum to a given value************************************************
// bool find3numbers(int a[], int arr_size, int sum)
// {
//     for (int i =0; i< arr_size - 2; i++)
//     {
//         for (int j = i + 1; j < arr_size - 1; j++)
//         {
//             for (int k = j + 1; k < arr_size; k++)
//             {
//                 if (a[i] + a[j] + a[k] == sum)
//                 {
//                     cout << "Triplet is " <<a[i] << ", " <<a[j] << ", " << a[k];
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }
// int main()
// {
//     int a[] = { 1, 4, 45, 6, 10, 8 };
//     int sum = 22;
//     int arr_size = sizeof(a) / sizeof(a[0]);
//     find3numbers(a, arr_size, sum);
//     return 0;
// }
// ****************************************************************Max Water contain*******************************************************
// int maxarea(int a[], int len)
// {
//     int l = 0;
//     int r = len - 1;
//     int area = 0;
//     while (l < r)
//     {
//         area = max(area, min(a[l], a[r]) * (r - l));
//         if (a[l] < a[r])
//         l += 1;
//         else 
//         r -= 1;
//     }
//     return area;
// }
// int main()
// {
//     int a[] = {1, 5, 4, 3};
//     int b[] = {3, 1, 2, 4, 5};
//     int len1 = sizeof(a) / sizeof(a[0]);
//     cout<<maxarea(a, len1);
//     int len2 = sizeof(b) / sizeof(b[0]);
//     cout<<endl<<maxarea(b, len2);
// }
// ***********************************************************kth smallest element*********************************************************
// int kthSmallest(int arr[], int n, int k)
// {
//     sort(arr, arr + n);
//     return arr[k - 1];
// }
// int main()
// {
//     int arr[] = {12, 3, 5, 7, 19 };
//     int n = sizeof(arr) / sizeof(arr[0]), k = 2;
//     cout <<"kth smallest element is "<<kthSmallest(arr, n, k);
//     return 0;
// }
// **************************************************Longest subarray with sum divisible by k********************************************
// int longestsubarrbyk(int arr[], int N, int k)
// {
//     int max1 = 0;
//     for(int i =0; i<N; i++)
//     {
//         int sum1 = 0;
//         for(int j=i; j<N; j++)
//         {
//             sum1+=arr[j];
//             if(sum1 % k == 0)
//             {
//                 max1 = max(max1 , j - i + 1);
//             }
//         }
//     }
//     return max1;
// }
// int main()
// {
//     int arr[] = { 2, 7, 6, 1, 4, 5 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int k = 3;
//     cout<<"Length = " << longestsubarrbyk(arr, n, k);
//     return 0;
// }
// *****************************************Sort an array of 0's 1's 2's ******************************************
// void sort012(int a[], int arr_size)
// {
//     int lo = 0;
//     int hi = arr_size - 1;
//     int mid;
//     while (mid <= hi) {
//         switch(a[mid]) {
//             case 0:
//             swap(a[lo++], a[mid++]);
//             break;
//             case 1:
//             mid++;
//             break;
//             case 2:
//             swap(a[mid], a[hi--]);
//             break;
//         }
//     }
// } 
// void printArray(int arr[], int arr_size)
// {
//     for (int i =0; i < arr_size; i++)
//     cout<<arr[i] << " ";
// }
// int main()
// {
//     int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     sort012(arr, n);
//     printArray(arr, n);
//     return 0;
// }
// ****************************************************************Negative to Positive*******************************************************
// void rearrange(int arr[], int n)
// {
//     int j = 0;
//     for (int i =0; i < n; i++) {
//         if (arr[i] < 0) {                                //order of element is not important here
//             if (i != j)
//             swap(arr[i], arr[j]);
//             j++;
//         }
//     }
// }
// void printArray(int arr[], int n)
// {
//     for (int i =0; i< n; i++)
//     cout<<arr[i]<<" ";
// }
// int main()
// {
//     int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     rearrange(arr, n);
//     printArray(arr, n);
//     return 0;
// }
// **************************************************************Union of Array************************************************************
// void printUnion(int arr1[], int arr2[], int m, int n)
// {
//     int i = 0, j = 0;
//     while(i < m && j < n) {
//         if (arr1[i] < arr2[j])
//         cout<<arr1[i++] << " ";
//         else if (arr2[j] < arr1[i])
//         cout << arr2[j++] << " ";
//         else {
//             cout << arr2[j++] << " ";
//             i++;
//         }
//     }
//     while (i < m)
//     cout << arr1[i++] << " ";
//     while (j < n)
//     cout << arr2[j++] << " ";
// }
// int main()
// {
//     int arr1[] = { 1, 2, 4, 5, 6 };
//     int arr2[] = { 2, 3, 5, 7 };
//     int m = sizeof(arr1) / sizeof(arr1[0]);
//     int n = sizeof(arr2) / sizeof(arr2[0]);
//     printUnion(arr1, arr2, m ,n);
//     return 0;
// }
// *************************************************************Cyclically rotate an array*********************************************
// void rotate(int arr[], int n)
// {
//     int last_el = arr[n - 1];
//     for (int i = n - 1; i > 0; i--) {
//         arr[i] = arr[i - 1];
//     }
//     arr[0] = last_el;
// }
// int main()
// {
//     int arr[] = { 1, 2, 3, 4, 5 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Given array is \n";
//     for (int i =0; i < n; i++)
//     cout << arr[i] << " ";
//     rotate(arr, n);
//     cout << "\nRotated array is\n";
//     for (int i = 0; i < n; i++)
//     cout<< arr[i] << " ";
//     return 0;
// }
// *************************************************************Kadane's Algorithm******************************************
// int maxSubArraySum(int a[], int size)
// {
//     int max_so_far = INT_MIN, max_ending_here = 0;
//     for (int i =0; i < size; i++) {
//         max_ending_here = max_ending_here + a[i];
//         if (max_so_far < max_ending_here) max_so_far = max_ending_here;
//         if (max_ending_here < 0) max_ending_here = 0;
//     }
//     return max_so_far;
// }
// int main()
// {
//     int a[] = { 1, 2, 3, -2, 5};
//     int n = sizeof(a) / sizeof(a[0]);
//     int max_sum = maxSubArraySum(a, n);
//     cout << " Maximum contigous sum is " << max_sum;
//     return 0;
// }
// *****************************************************************Minimize the maximum diff th height**************************************
// int getMindiff(int arr[], int n, int k)
// {
//     sort(arr, arr + n);
//     int ans = arr[n - 1] - arr[0];
//     int tempmin, tempmax;
//     tempmin = arr[0];
//     tempmax = arr[n - 1];
//     for (int i = 1; i < n; i++) {
//         if (arr[i] - k < 0)
//         continue;
//         tempmin = min(arr[0] + k, arr[i] - k);
//         tempmax = max(arr[i - 1] + k, arr[n - 1] - k);
//         ans = min(ans, tempmax - tempmin);
//     }
//     return ans;
// }
// int main()
// {
//     int k = 6, n = 6;
//     int arr[n] = { 7, 4, 8, 8, 8, 9 };
//     int ans = getMindiff(arr, n, k);
//     cout<<ans;
// }
// *********************************************************************Minimum no of Jump**************************************************
// int minJumps(int arr[], int l, int h)
// {
//     if (h == l)
//     return 0;
//     if(arr[l] == 0)
//     return INT_MAX;
//     int min = INT_MAX;
//     for (int i = l + 1; i <= h && i <=l + arr[l]; i++){
//         int jumps = minJumps(arr, i, h);
//         if (jumps != INT_MAX && jumps +  1 < min)
//         min = jumps + 1;
//     }
//     return min;
// }
// int main()
// {
//     int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << " Minimum number of jumps to ";
//     cout << " reach the end is " << minJumps(arr, 0, n-1);
//     return 0;
// }
// ***************************************************************Merging two sorted array*********************************************
// void merge(int ar1[], int ar2[], int m, int n)
// {
//     for (int i = n - 1; i >= 0; i--)
//     {
//         int j, last = ar1[m - 1];
//         for (j = m - 2; j >= 0 && ar1[j] > ar2[i]; j--)
//         ar1[j + 1] = ar1[j];
//         if (last > ar2[i]) {
//             ar1[j + 1] = ar2[i];
//             ar2[i] = last;
//         }
//     }
// }
// int main()
// {
//     int ar1[] = { 1, 5, 9, 10, 15, 20 };
//     int ar2[] = { 2, 3, 8, 13 };
//     int m = sizeof(ar1) / sizeof(ar1[0]);
//     int n = sizeof(ar2) / sizeof(ar2[0]);
//     merge(ar1, ar2, m, n);
//     cout << " After Merging \nFirst Array: ";
//     for (int i = 0; i < m; i++)
//     cout << ar1[i] << " ";
//     cout << " \nSecond Array: ";
//     for (int i = 0; i < n; i++)
//     cout << ar2[i] << " ";
//     return 0;
// }
// ****************************************************************Inversion count in array******************************************************
// int getInvCount(int arr[], int n)
// {
//     int inv_count = 0;
//     for (int i =0; i < n - 1; i++)
//     for (int j = i + 1; j < n; j++)
//     if (arr[i] > arr[j])
//     inv_count++;
//     return inv_count;
// }
// int main()
// {
//     int arr[] = { 2, 3, 4, 5, 6 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Number of inversion are "<<getInvCount(arr, n);
//     return 0;
// }
// **********************************************************Count Pair with given sum******************************************************
// int getpairscount(int arr[], int n, int k)
// {
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     for (int j = i + 1; j < n; j++)
//     if(arr[i] + arr[j] == k)
//     count++;
//     return count;
// }
// int main()
// {
//     int arr[] = { 1, 5, 7, -1 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int k = 6;
//     cout << "Count of pairs is " <<getpairscount(arr, n, k);
//     return 0;
// }
// ************************************************************Common element in 3 sorted array******************************************** 
// void FindIntersection(int arr1[], int arr2[], int temp[], int m, int n, int& k)
// {
//     int i = 0, j = 0;
//     while (i < m && j < n) {
//         if (arr1[i] < arr2[j]) {
//             i++;
//         }
//         else if (arr2[j] < arr1[i]) {
//             j++;
//         }
//         else {
//             temp[k] = arr1[i];
//             i++;
//             j++;
//             k++;
//         }
//     }
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
//     cout << "Common elements present in arrays are : \n";
//     for (int i =0; i < k; i++) {
//         cout << ans[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }
// ********************************Rearrange array in alternating from positive to negative with 0(1) extra space****************************
// void rightrotate(int arr[], int n, int outofplace, int cur)
// {
//     char tmp = arr[cur];
//     for (int i = cur; i > outofplace; i--)
//     arr[i] = arr[i - 1];
//     arr[outofplace] = tmp;
// }
// void rearrange(int arr[], int n)
// {
//     int outofplace = -1;
//     for (int index = 0; index < n; index++) {
//         if (outofplace >= 0) {
//             if (((arr[index] >= 0) && (arr[outofplace] < 0)) || ((arr[index] < 0) && (arr[outofplace] >= 0)))
//             {
//                 rightrotate(arr, n, outofplace, index);
//                 if (index - outofplace >= 2)
//                 outofplace = outofplace >= 2;
//                 else
//                 outofplace = -1;
//             }
//         }
//         if (outofplace == -1) {
//             if (((arr[index] >= 0) && (!(index & 0x01))) || ((arr[index] < 0) && (index & 0x01))) 
//             {
//                 outofplace = index;
//             }
//         }
//     }
// }
// void printArray(int arr[], int n)
// {
//     for (int i =0; i < n; i++)
//     cout << arr[i] << " ";
//     cout <<endl;
// }
// int main()
// {
//     int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Given array is \n";
//     printArray(arr, n);
//     rearrange(arr, n);
//     cout << "Rearranged array is \n";
//     printArray(arr, n);
//     return 0;
// }
// ******************************************************Linear Search************************************************
// bool search(int arr[], int size, int key)
// {
//     for(int i =0; i<size; i++)
//     {
//         if(arr[i] == key)
//         {
//             return 1;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     int arr[5] = {1,8,6,-5,3};
//     int key;
//     cout<<" Enter the element to search for "<<endl;
//     cin>>key;
//     bool found = search(arr, 5,key);
//     if(found)
//     {
//         cout<<"Key is present "<<endl;
//     }
//     else{
//         cout<<"Key is absent "<<endl;
//     }
//     return 0;
// }
// *****************************************************Subarray with 0 sum**********************
// bool subarrayexists(int arr[], int n)
// {
//     for (int i = 0; i< n; i++)
//     {
//         int sum = arr[i];
//         if (sum == 0)
//         return true;
//         for (int j = i + 1; j < n; j++) {
//             sum += arr[j];
//             if (sum == 0)
//             return true;
//         }
//     }
//     return false;
// }
// int main()
// {
//     int arr[] = { 4, 2, -3, 1, 6 };
//     int N = sizeof(arr) / sizeof(arr[0]);
//     if (subarrayexists(arr, N))
//     cout << "Found a subarray with 0 sum";
//     else
//     cout << " No such sub array exists!";
//     return 0;
// }
// *******************************************************Factorial of large no.********************************************
// #define MAX 500
// int multiply(int x, int res[], int res_size);
// void factorial(int n)
// {
//     int res[MAX];
//     res[0] = 1;
//     int res_size = 1;
//     for (int x = 2; x <= n; x++)
//     res_size = multiply(x, res, res_size);
//     cout << "Factorial of given number is \n";
//     for (int i = res_size - 1; i >= 0; i--)
//     cout << res[i];
// }
// int multiply(int x, int res[], int res_size)
// {
//     int carry = 0;
//     for (int i =0; i < res_size; i++) {
//         int prod = res[i] * x + carry;
//         res[i] = prod % 10;
//         carry = prod / 10;
//     }
//     while (carry) {
//         res[res_size] = carry % 10;
//         carry = carry / 10;
//         res_size++;
//     }
//     return res_size;
// }
// int main()
// {
//     factorial(5);
//     return 0;
// }
// **********************************************************Maximum product subarray***************************
// int maxSubarrayProduct(int arr[], int n)
// {
// int result = arr[0];
// for (int i =0; i< n; i++) {
//     int mul = arr[i];
//     for (int j =i + 1; j < n; j++)
//     {
//         result = max(result, mul);
//         mul *= arr[j];
//     }
//     result = max(result, mul);
//   }
//   return result;
// }
// int main()
// {
//     int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << " Maximum Sub array product is " << maxSubarrayProduct(arr, n);
//     return 0;
// }
// *******************************************************Longest Consecutive Subsequence**************************
// int findLongestConseqSubseq(int arr[], int n)
// {
//     int ans = 0, count = 0;
//     sort(arr, arr + n);
//     vector<int> v;
//     v.push_back(arr[0]);
//     for(int i =1; i < n; i++) {
//         if (arr[i] != arr[i - 1])
//         v.push_back(arr[i]);
//     }
//     for (int i =0; i < v.size(); i++){
//     if (i > 0 && v[i] == v[i - 1] + 1)
//     count++;
//     else
//     count = 1;
//     ans = max(ans, count);
//     }
//     return ans;
// }
// int main()
// {
//     int arr[] = { 1, 2, 2, 3};
//     int n = sizeof arr/ sizeof arr[0];
//     cout << " Length of the Longest contiguous subsequence  is "<<findLongestConseqSubseq(arr, n);
//     return 0;
// }
// **************************Given array of size n and a number k, find all element that appear more then n/k times***********************
// void morethanNbyK(int arr[], int n, int k)
// {
//     int x = n/k;
//     unordered_map<int, int> freq;
//     for(int i =0; i < n; i++)
//     {
//         freq[arr[i]]++;
//     }
//     for (auto i : freq){
//         if (i.second > x){
//             cout <<i.first << endl;
//         }
//     }
// }
// int main()
// {
//    int arr[] = { 3, 1, 2, 2, 1, 2, 3, 3};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int k = 4;
//    morethanNbyK(arr, n, k);
//    return 0;
// }
// ***********************************Maximum Profit by buying and selling a share at most twice*************************************
// int maxProfit(int price[], int n)
// {
//     int* profit = new int[n];
//     for (int i =0; i < n; i++)
//     profit[i] = 0;
//     int max_price = price[n - 1];
//     for (int i = n - 2; i >= 0; i--) {
//     if (price[i] > max_price)
//     max_price = price[i];
//     profit[i] = max(profit[i + 1], max_price - price[i]);
//     }
//     int min_price = price[0];
//     for (int i = 1; i < n; i++) {
//         if (price[i] < min_price)
//         min_price = price[i];
//         profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
//     }
//     int result = profit[n - 1];
//     delete[] profit;
//     return result;
// }
// int main()
// {
//     int price[] = { 2, 30, 15, 10, 8, 25, 80 };
//     int n = sizeof(price) / sizeof(price[0]);
//     cout << "Maximum Profit = " << maxProfit(price, n);
//     return 0; 
// }
// *****************************************************Smallest subarray with sum greatest than a given value***************************
// int smallestSubWithSum(int arr[], int n, int x)
// {
//     int min_len = n + 1;
//     for (int start = 0; start<n; start++)
//     {
//         int curr_sum = arr[start];
//         if (curr_sum > x) return 1;
//         for (int end=start+1; end<n; end++)
//         {
//             curr_sum += arr[end];
//             if (curr_sum > x && (end - start + 1) < min_len)
//             min_len = (end - start + 1);
//         }
//     }
//     return min_len;
// }
// int main()
// {
//     int arr1[] = { 1, 4, 45, 6, 10, 19 };
//     int x = 51;
//     int n1 = sizeof(arr1)/sizeof(arr1[0]);
//     int res1 = smallestSubWithSum(arr1, n1, x);
//     (res1 == n1+1)? cout << "Not Possible\n":
//     cout << res1 << endl;
//     int arr2[] = { 1, 10, 5, 2, 7};
//     int n2 = sizeof(arr2)/sizeof(arr2[0]);
//     x = 9;
//     int res2 = smallestSubWithSum(arr2, n2, x);
//     (res2 == n2 + 1)? cout << " Not Possible\n":
//     cout << res2 <<endl;
//     int arr3[] = { 1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
//     int n3 = sizeof(arr3)/sizeof(arr3[0]);
//     x = 280;
//     int res3 = smallestSubWithSum(arr3, n3, x);
//     (res3 == n3 + 1)? cout << " Not Possible\n":
//     cout << res3 <<endl;
// }
// *********************************************Three way partition***********************************************
// void threeWayPartition(int arr[], int n, int lowVal, int highVal)
// {
//     int start = 0, end = n - 1;
//     for (int i = 0; i <= end;) {
//         if (arr[i] < lowVal){
//             if (i == start){
//                 start++;
//                 i++;
//             }
//             else
//             swap(arr[i++], arr[start++]);
//         }
//         else if (arr[i] > highVal)
//         swap(arr[i], arr[end--]);
//         else
//         i++;
//     }
// }
// int main()
// {
//     int arr[] ={ 1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     threeWayPartition(arr, n, 10, 20);
//     cout<<"Modified array \n";
//     for (int i = 0; i < n; i++)
//     cout << arr[i] << " ";
// }
// **************************************************Minimum swap and k together********************************************************
// int minSwap(int *arr, int n, int k){
//     int count= 0;
//     for(int i =0; i< n; ++i)
//     if (arr[i] <= k)
//     ++count;
//     int bad = 0;
//     for (int i =0; i< count; ++i)
//     if (arr[i] > k)
//     ++bad;
//     int ans = bad;
//     for (int i =0, j = count; j < n; ++i, ++j){
//         if (arr[i] > k)
//         --bad;
//         if (arr[j] > k)
//         ++bad;
//         ans = min(ans, bad);
//     }
//     return ans;
// }
// int main()
// {
//     int arr[] = {2, 1, 5, 6, 3};
//     int n = sizeof(arr)/ sizeof(arr[0]);
//     int k = 3;
//     cout << minSwap(arr, n, k) << "\n";
//     int arr1[] = {2, 7, 9, 5, 8, 7, 4};
//     n = sizeof(arr1) / sizeof(arr1[0]);
//     k = 5;
//     cout <<minSwap(arr1, n , k);
//     return 0;
// }
// *********************************************************************Palindromic Array***********************************************
// bool isPalindromic(int N)
// {
//     string str = "" + N;
//     int len = str.length();
//     for (int i =0; i < len / 2; i++){
//         if (str[i] != str[len - 1 - i])
//         return false;
//     }
//     return true;
// }
// bool isPalindromicArray(int arr[], int n)
// {
//     for (int i = 0; i < n; i++){
//         bool ans = isPalindromic(arr[i]);
//         if(ans == false)
//         return false;
//     }
//     return true;
// }
// int main()
// {
//     int arr[] = { 111, 222, 333, 444, 555};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     bool res = isPalindromicArray(arr, n);
//     if (res == true)
//     cout<<"Array is a Palindromic Array\n";
//     else
//     cout <<"Array is not a Palindrome Array \n ";
// }

//write a program in c++ of palindromic array?
// bool is_palindrome(vector<int> arr) {
//   for (int i = 0; i < arr.size() / 2; i++) {
//     if (arr[i] != arr[arr.size() - i - 1]) {
//       return false;
//     }
//   }
//   return true;
// }

// int main() {
//   vector<int> arr = {111, 222, 333, 444, 555};
//   cout << is_palindrome(arr) << endl;  // Output: true

//   arr = {111, 222, 333, 444, 555};
//   cout << is_palindrome(arr) << endl;  // Output: false
// 
//   return 0;
// }
// ********************************************************************find the Median*********************************************************
// int cmpfunc(const void* a, const void* b)
// {
//     return (*(int*)a-*(int*)b);
// }
// double findMedian(int a[], int n)
// {
//     qsort(a, n, sizeof(int), cmpfunc);
//     if (n % 2 != 0)
//     return (double)a[n / 2];
//     return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
// }
// int main()
// {
//     int a[] = { 1, 3, 4, 2, 7, 5, 8, 6 };
//     int N = sizeof(a) / sizeof(a[0]);
//     cout<<"Median = \n" <<findMedian(a, N);
//     return 0;
// }
// *********************************************************Median of 2 sorted array*********************************************8
// int Solution(int arr[], int n)
// {
//     if (n % 2 == 0){
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
//     int arr2[] = {-12, -10, -6, -3, 4, 10};
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
//     sort(arr3, arr3 + 1);
//     cout<<"Median = " <<Solution(arr3, l);
// }


// write a program median of two sorted arrays of different sizes in c++?
// double findMedian(vector<int> &arr1, vector<int> &arr2) {
//   vector<int> merged(arr1.size() + arr2.size());

//   int i = 0, j = 0, k = 0;
//   while (i < arr1.size() && j < arr2.size()) {
//     if (arr1[i] < arr2[j]) {
//       merged[k++] = arr1[i++];
//     } else {
//       merged[k++] = arr2[j++];
//     }
//   }

//   while (i < arr1.size()) {
//     merged[k++] = arr1[i++];
//   }

//   while (j < arr2.size()) {
//     merged[k++] = arr2[j++];
//   }

//   double median;
//   if (merged.size() % 2 == 0) {
//     median = (double)(merged[merged.size() / 2] + merged[merged.size() / 2 - 1]) / 2;
//   } else {
//     median = (double)merged[merged.size() / 2];
//   }

//   return median;
// }

// int main() {
//   vector<int> arr1 = {-5, 3, 6, 12, 15 };
//   vector<int> arr2 = {-12, -10, -6, -3, 4, 10 };

//   double median = findMedian(arr1, arr2);

//   cout << "Median of the two sorted arrays: " << median << endl;

//   return 0;
// }
// *************************