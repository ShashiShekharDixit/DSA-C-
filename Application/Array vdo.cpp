#include<bits/stdc++.h>
using namespace std;
// **********************************************Functions*********************************************
// void hey()
// {
//   cout<<"Hello World";
// }
 
// int main()
// {
//     hey();
//     return 0;
// }
// ****************************************************************************************************
// void Number(int num1, float num2)
// {
//     cout<<" The integer number is "<< num1 <<endl;
//     cout<<" the decimal number is "<<num2 <<endl;
// }
// int main()
// {
//      int a = 2;
//      float b = 2.5;
//      Number(a,b);
//      return 0;
// }
// ****************************************************************************************************
// {
//      int power (int a, int b)
//      {
//         int ans = 1;
//         for(i=1;i<=b;i++)
//         {
//             ans = ans * a;
//         }
//         return ans;
//      }
// }
// int main()
// {
//     int a,b;
//     cin>>a>>b;

//     int answer = power(a,b);
//     cout<<"Answer is "<< answer << endl;
//     return 0;
// }
// *************************************************************************************************
// int factorial(int n)
// {
//      int fact = 1;
//      for(int i=1; i<=n; i++)
//      {
//         fact = fact * i;
//      }
//      return fact;
// }
// int nCr(int n, int r)
// {
//     int num = factorial(n);
//     int denom = factorial(r) * factorial(n-r);
//     return num/denom;
// }
// int main()
// {
//     int n,r;
//     cin>>n>>r;
//     cout<<"Answer is " <<nCr(n, r)<<endl;
// }
// ****************************************************************************************************
// int add(int a, int b)
// {
//     return (a + b);
// }
// int main()
// {
//      int sum;
//      sum = add (13 ,79);
//      cout<<"13 + 79 = "<<sum << endl;
//      return 0;
// }
// ****************************************************************************************************
// {
//      double number,squareroot;
//      number = 25;
//      squareroot = sqrt(number);
//      cout<<" Square root of " << number << " = " <<squareroot;
//      return 0;
// }
// ****************************************************************************************************
// int max(int num1,int num2);
// int main()
// {
//     int a=100,b=200;
//     int ret;
//     ret = max(a,b);
//     cout<<"Max value is " << ret <<endl;
//     return 0;
// }
// int max(int num1, int num2)
// {
//     int result;
//     if(num1 > num2)
//     result = num1;
//     else
//     result = num2;
//     return result;
// }
// ****************************************************************************************************
// int sum(int a, int b = 20)
// {
//     int result;
//     result = a + b;
//     return (result); 
// }
// int main()
// {
// int a= 100,b=200;
// int result;
// result = sum(a,b);
// cout<<" Total value is :" << result <<endl;
// result = sum(a);
// cout<<"Total value is :" <<result <<endl;
// return 0;
// }
// ****************************************************************************************************
// bool isPrime(int n)
// {
//     for( int i = 2; i<n; i++)
//     {
//         if(n%i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     if(isPrime(n))
//     {
//         cout<<" is a prime no."<<endl;
//     }
//     else{
//         cout<<" is not a prime no."<<endl;
//     }
// }
// *****************************************Passbyvalue/Callbyvalue************************************
// void dummy(int n)
// {
//     n++;
//     cout<<" n is " <<n <<endl;
// }
// int main()
// {
//      int n;
//      cin>>n;

//      dummy(n);
//      cout<<"The number is " <<n <<endl;
//      return 0;
// }
// **********************************************Array*************************************************
// void printArray(int arr[], int size)
// {
//     cout<<" printing the array "<< endl;
//     for(int i=0;i<size;i++)
//     {
//         cout<<arr[i] <<" "; 
//     }
//     cout<<"printing done " << endl;
// }
// int main()
// {
//      int number[15];
//      cout<<"Value at 14 index "<< number[14] <<endl;
//      int second[3] = {5,7,11};
//      cout<<" Value at 2 index "<< second[2] <<endl;
//      int third[15] = {2,7};
//      //int n = 15;
//      printArray(third,15);
//      int fourth[20] = {0};
//      //int n = 10;
//      printArray(fourth,20);
//      int fifth[10] = {1};
//      //int n = 10;
//      printArray(fifth,10);
//     // int fourthsize = sizeof(fourth)/sizeof(int);  *line no.361 aur 362 yeh pure array ki size nikalne k liye hota hai*
//     //cout<<" Size of fourth is " <<fourthsize <<endl;
//      cout <<endl <<"Everything is Fine " <<endl;
// }
// *************************************************Maximum and Minimum*****************************************************
// int getMax(int num[], int n)
// {
//     int max = INT_MIN;

//     for(int i=0; i<n; i++)
//     {
//         if(num[i] > max)
//         {
//             max = num[i];
//         }
//     }
//     return max;
// }
// int getMin(int num[], int n)
// {
//     int min = INT_MAX;

//     for(int i=0; i<n; i++)
//     {
//         if(num[i] < min)
//         {
//             min = num[i];
//         }
//     }
//     return min;
// }
// int main()
// {
//     int size;
//     cin>>size;

//     int num[100];

//     for(int i = 0; i<=size; i++)
//     {
//         cin>>num[i];
//     }
//     cout<<" Maximum value is " << getMax(num, size) <<endl;
//     cout<<" Minimum value is " << getMin(num, size) <<endl;
//     return 0;
// }
// ********************************************************Above program can be written like this also**********
// int getMax(int num[], int n)
// {
//     int maxi = INT_MIN;

//     for(int i=0; i<n; i++)
//     {
//         maxi = max(maxi, num[i]);
//         /*if(num[i] > max)
//         {
//             max = num[i];
//         }*/
//     }
//     return maxi;
// }
// int getMin(int num[], int n)
// {
//     int mini = INT_MAX;

//     for(int i=0; i<n; i++)
//     {
//         mini = min(mini, num[i]);
//         //if(num[i] < min)
//         //{
//         //    min = num[i];
//         //}
//     }
//     return mini;
// }
// int main()
// {
//     int size;
//     cin>>size;

//     int num[100];

//     for(int i = 0; i<=size; i++)
//     {
//         cin>>num[i];
//     }
//     cout<<" Maximum value is " << getMax(num, size) <<endl;
//     cout<<" Minimum value is " << getMin(num, size) <<endl;
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
// **************************************************reverse**************************************************************
// void reverse(int arr[], int n)
// {
//     int start = 0;
//     int end = n-1;
//     while(start<=end)
//     {
//         swap(arr[start],arr[end]);
//         start++;
//         end--;
//     }
// }
// void printArray(int arr[],int n)
// {
//     for(int i=0 ; i<n; i++)
//     {
//         cout<< arr[i] <<" ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int arr[6]={2,4,-5,8,6,7};
//     int brr[5]={5,8,6,9,-2};

//     reverse(arr, 6);
//     reverse(brr, 5);

//     printArray(arr, 6);
//     printArray(brr, 5);

//     return 0;
// }
// **********************************************Swapping Alternate*********************************************************
// void SwapAlternate(int arr[], int size)
// {
//     for(int i=0; i<size; i+=2)
//     {
//         if(i+1 < size)
//         {
//             swap(arr[i], arr[i+1]);
//         }
//     }
// }
// void printArray(int arr[],int n)
// {
//     for(int i=0 ; i<n; i++)
//     {
//         cout<< arr[i] <<" ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int arr[6]={2,4,-5,8,6,7};
//     int brr[5]={5,8,6,9,-2};
//     SwapAlternate(arr,6);
//     SwapAlternate(brr,5);
//     printArray(arr, 6);
//     printArray(brr, 5);

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
// **********************************First and Last occurence**************************************
// int firstOcc(int arr[], int size, int key)
// {
//     int start = 0;
//     int end = size-1;
//     int ans = -1;
//     int mid = start + (end-start)/2;
//     //if int value is (2^31-1) then we use [start + (end-start)/2]
//     while(start <= end)
//     {
//       if(arr[mid] == key)
//       {
//         ans = mid;
//         end = mid -1;
//       }
//       if(key > arr[mid])
//       {
//         start = mid + 1;
//       }
//       else{
//         end = mid - 1;
//       }
//       mid = start + (end-start)/2;
//     //same as line no 8  
//     }
//     return ans;
// }
// int lastOcc(int arr[], int size, int key)
// {
//     int start = 0;
//     int end = size-1;
//     int ans = -1;
//     int mid = start + (end-start)/2;
//     //if int value is (2^31-1) then we use [start + (end-start)/2]
//     while(start <= end)
//     {
//       if(arr[mid] == key)
//       {
//         ans = mid;
//         start = mid +1;
//       }
//       if(key > arr[mid])
//       {
//         start = mid + 1;
//       }
//       else{
//         end = mid - 1;
//       }
//       mid = start + (end-start)/2;
//     //same as line no 8  
//     }
//     return ans;
// }
// //if we have to find total no of occurence then formula is [(last index - first index) + 1]
// int main()
// {
// int even[7] = {1,2,8,9,3,3,5};
// cout<<"First Occurence of 3 in Index" <<firstOcc(even,7,3) <<endl;
// cout<<"Last Occurence of 3 in Index" <<lastOcc(even,7,3) <<endl;
// return 0;
// }
// ***************************************************Last and first Occurence by vector*****************************************
// class Solution
// {
//     public:
//     int searchFirst(int arr[], int start, int end, int x){
//         int ans = -1;
//         while(start<=end) {
//             int mid = start + (end-start)/2;
//             if(arr[mid] == x) {
//                 ans = mid;
//                 end = mid-1;
//             }else if(arr[mid] < x) {
//                 start = mid + 1;
//             }else {
//                 end = mid - 1;
//             }
//         }
//         return ans;
//     }
//     int searchLast(int arr[], int start, int end, int x){
//         int ans = -1;
//         while(start <= end) {
//             int mid = start + (end-start)/2;
//             if(arr[mid] == x) {
//                 ans = mid;
//                 start = mid + 1;
//             }else if(arr[mid] < x) {
//                 start = mid + 1;
//             }else {
//                 end = mid - 1;
//             }
//         }
//         return ans;
//     }
//     vector<int> find(int arr[], int n , int x )
//     {
//         vector<int>ans;
//         int first = searchFirst(arr,0,n-1,x);
//         int last = searchLast(arr,0,n-1,x);
//         ans.push_back(first);
//         ans.push_back(last);
//         return ans;
//     }
// };
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,x;
//         cin>>n>>x;
//         int arr[n],i;
//         for(i=0;i<n;i++)
//         cin>>arr[i];
//         vector<int> ans;
//         Solution ob;
//         ans=ob.find(arr,n,x);
//         cout<<ans[0]<<" "<<ans[1]<<endl;
//     }
//     return 0;
// }
// ***************************************************Pivot******************************************************
// int getPivot(int arr[], int n)
// {
//     int s= 0;
//     int e= n-1;
//     int mid= s+(e-s)/2;

//     while(s<e)
//     {
//         if(arr[mid] >= arr[0])
//         {
//              s= mid+1;
//         }
//         else{
//             e=mid;
//         }
//         mid= s + (e-s)/2;
//     }
//     return s;
// }
 
//  int main()
//  {
//     int arr[5] ={3,12,8,10,17};

//     cout<<" Pivot is " << getPivot(arr, 5) <<endl;     

//  } 
//  *******************************************************FCFS***************************************************************************
//  int main()
// {
//     int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
//     cout<<"Enter the total number of processes(maximum 20):";
//     cin>>n;
//     cout<<"nEnter Process Burst Time";
//     for(i=0;i<n;i++)
//     {
//         cout<<"P["<<i+1<<"]:";
//         cin>>bt[i];
//     }
//     wt[0]=0;
//     for(i=i;i<n;i++)
//     {
//         wt[i]=0;
//         for(j=0;j<i;j++)
//         wt[i]+=bt[j];
//     }
//     cout<<"nProcesstBurst TimetWaiting TimeTurnaround Time";
//     for(i=0;i<n;i++)
//     {
//         tat[i]=bt[i]+wt[i];
//         avwt+wt[i];
//         avtat+=tat[i];
//         cout<<"nP["<<i+1<<"]"<<"tt"<<bt[i]<<"tt"<<wt[i]<<"tt"<<tat[i];
//     }
//     avwt/=i;
//     avtat/=i;
//     cout<<"nnAverage Waiting Time:"<<avwt;
//     cout<<"nAverage Turnaround Time:"<<avtat;
//     return 0;
// }
// *******************************************************************Square root*********************************************************
// double floorSqrt(int x)
// {
//     if (x == 0 || x == 1)
//         return x;
//     int i = 1, result = 1;
//     while (result <= x) {
//         i++;
//         result = i * i;
//     }
//     return i - 1;
// }
// int main()
// {
//     double x;
//     cin>>x;
//     cout << floorSqrt(x) << endl;
//     return 0;
// }
// *******************************************************************bubble sort**************************************************************
// void bubbleSort(int arr[], int n)
// {
// 	int i, j;
// 	for (i = 0; i < n - 1; i++)
// 		for (j = 0; j < n - i - 1; j++)
// 			if (arr[j] > arr[j + 1])
// 				swap(arr[j], arr[j + 1]);
// }
// void printArray(int arr[], int size)
// {
// 	int i;
// 	for (i = 0; i < size; i++)
// 		cout << arr[i] << " ";
// 	cout << endl;
// }
// int main()
// {
// 	int arr[] = { 5, 1, 4, 2, 8};
// 	int N = sizeof(arr) / sizeof(arr[0]);
// 	bubbleSort(arr, N);
// 	cout << "Sorted array: \n";
// 	printArray(arr, N);
// 	return 0;
// }
// ***********************************************************************Length of the string***********************************************
// int getLength(char name[])
// {
//     int count = 0;
//     for(int i = 0; name[i] != '\0'; i++) {
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     char name[20];
//     cout<<"Enter your name ";
//     cin>>name;
//     // name[2] = '\0';
//     cout<<"My name is "<<name<<endl;
//     cout << "Length: "<<getLength(name) <<endl;
//     return 0;
// }
//*********************************************************************reverse a string******************************************************
// void reverse(char name[], int n){
//     int s = 0;
//     int e = n - 1;
//     while (s<e)
//     {
//         swap(name[s++], name[e--]);
//     }
// }
// int getLength(char name[])
// {
//     int count = 0;
//     for(int i = 0; name[i] != '\0'; i++) {
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     char name[20];
//     cout<<"Enter your name ";
//     cin>>name;
//     // name[2] = '\0';
//     cout<<"Your name is "<<name<<endl;
//     cout<<name<<endl;
//     int len = getLength(name);
//     cout << "Length: "<<len<<endl;
//     reverse(name, len);
//     cout<<"Your name is ";
//     cout<<name;
//     return 0;
// }
// *******************************************************Greatest Common Divisor***************************************************************
// int gcd(int a, int b)
// {
//     if(a == 0)
//     return b;

//     if(b == 0)
//     return a;

//     while(a != b)
//     {
//         if(a>b)
//         {
//             a = a - b;
//         }
//         else{
//             b = b - a;
//         }
//     }
//     return a;
// }
// int main()
// {
//     int a, b;
//     cout << "Enter the two values a b "<<endl;
//     cin>>a>>b;

//     int ans = gcd(a,b);
//     cout<<"The value of " << a << " & " << b << " is :" <<ans <<endl;
// }
// ****************************************************************Minimum Number of pages to allocate*****************************************
// bool isPossible(int arr[], int n, int m, int curr_min)
// {
//     int studentsRequired = 1;
//     int curr_sum = 0;
//     for (int i = 0; i < n; i++){
//         if(arr[i] > curr_min)
//         return false;

//         if (curr_sum + arr[i] > curr_min){
//             studentsRequired++;
//             curr_sum = arr[i];
//             if (studentsRequired > m)
//             return false;
//     }
//     else
//     curr_sum += arr[i];
//   }
//   return true;
// }
// int findPages (int arr[], int n, int m)
// {
//     long long sum = 0;
//     if (n < m)
//     return -1;
//     int mx = INT_MIN;
//     for (int i =0; i < n; i++)
//     {
//         sum += arr[i];
//         mx = max(mx, arr[i]);
//     }
//     int start = mx, end = sum;
//     int result = INT_MAX;
//     while (start <= end){
//         int mid = (start + end) / 2;
//         if (isPossible(arr , n,m,mid)){
//             result = mid;
//             end = mid - 1;
//         }
//         else
//         start = mid + 1; 
//     }
//     return result;
// }
// int main()
// {
//     int arr[] = { 12, 34, 67, 90 };
//     int n = sizeof arr / sizeof arr[0];
//     int m = 2;
//     cout << " Minimum number of pages = "<<findPages(arr, n, m) << endl;
//     return 0; 
// }
// ******************************************************Painter's Partition Problem*********************************************************
// int sum(int arr[], int from, int to)
// {
//     int total = 0;
//     for (int i = from; i <= to; i++)
//     total += arr[i];
//     return total;
// }
// int partition(int arr[], int n, int k)
// {
//     if (k == 1)
//     return sum(arr, 0, n-1);
//     if (n == 1)
//     return arr[0];
//     int best = INT_MAX;
//     for (int i =1; i <= n; i++)
//     best = min(best, max(partition(arr, i, k - 1), sum(arr, i, n - 1)));
//     return best;
// }
// int main()
// {
//     int arr[] = { 10, 20, 60, 50, 30, 40};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int k = 3;
//     cout << partition(arr, n, k)<<endl;
//     return 0;
// }
// ******************************************************************Merge sorted array************************************************************
// void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
// {
//     int i = 0, j = 0, k = 0;
//     while (i < n1)
//     {
//         arr3[k++] = arr1[i++];
//     }
//     while (j < n2)
//     {
//         arr3[k++] = arr2[j++];
//     }
//     sort(arr3, arr3+n1+n2);
// }
// int main()
// {
//     int arr1[] = {1, 3, 5, 7};
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);
//     int arr2[] = {2, 4, 6, 8};
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);
//     int arr3[n1+n2];
//     mergeArrays(arr1, arr2, n1, n2, arr3);
//     cout << " Array after merging " <<endl;
//     for (int i = 0; i < n1 + n2; i++)
//     cout << arr3[i] << " ";
//     return 0;
// }
// ******************************************************************Moves Zeroes****************************************************************
// void move_zeroes(vector<int>& m)
// {
//     int count = 0;
//     int length = m.size();
//     for (int i =0; i < length; i++) {
//         if (m[i] == 0) {
//             count++;
//             m.erase(m.begin() + i);
//             i--;
//             length--;
//         }
//     }
//     for (int i = 0; i < count; i++) {
//         m.push_back(0);
//     }
//     cout<<"After Shifting Zeroes : "<<endl;
//     for (int i =0; i < m.size(); i++){
//         cout <<m[i] <<" ";
//     }
// }
// int main()
// {
//     vector<int> m{ 5, 6, 0, 4, 6, 0, 9, 0, 8 };
//     move_zeroes(m);
//     return 0;
// }
// ***************************************************************Selection Sort**********************************************************
// void selectionSort(int arr[], int n){
//     int i, j, min_idx;
//     for (i =0; i< n - 1; i++)
//     {
//         min_idx = i;
//         for (j = i + 1; j < n; j++) {
//             if (arr[j] < arr[min_idx])
//             min_idx = j;
//         }
//         if (min_idx != i)
//         swap(arr[min_idx], arr[i]);
//     }
// }
// void printArray(int arr[], int size)
// {
//     int i;
//     for (i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//         cout <<endl;
//     }
// }
// int main()
// {
//     int arr[] = { 64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     selectionSort(arr, n);
//     cout << "Sorted array:  \n";
//     printArray(arr, n);
//     return 0; 
// }
// ******************************************************************Insertion Sort**************************************************************
// void InsertionSort(int arr[], int n)
// {
//     int i, key, j;
//     for(i = 1; i < n; i++) {
//         key = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }
// void printArray(int arr[], int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     cout << arr[i] << " ";
//     cout << endl;
// }
// ************************************************************Check if array is sorted and rotated*********************************************
// void checkifsortrotated(int arr[], int n)
// {
//     int minEle = INT_MAX;
//     int maxEle = INT_MIN;
//     int minIndex = -1;
//     for (int i =0; i < n; i++) {
//         if (arr[i] < minEle) {
//             minEle=arr[i];
//             minIndex = i;
//         }
//     } 
//     int flag1 = 1;
//     for (int i = 1; i < minIndex; i++) {
//         if (arr[i] < arr[i - 1]) {
//             flag1 = 0;
//             break;
//         }
//     }
//     int flag2 = 1;
//     for (int i = minIndex + 1; i < n; i++) {
//         if (arr[i] < arr[i - 1]) {
//             flag2 = 0;
//             break;
//         }
//     }
//     if (flag1 && flag2 && (arr[n - 1] < arr[0]))
//     cout << "Yes";
//     else
//     cout <<"No";
// }
// int main()
// {
//     int arr[] = { 3, 4, 5, 1, 2 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     checkifsortrotated(arr, n);
//     return 0;
// }
// **************************************************************Linear search in 2d array*******************************************************
// vector<int> findAns(vector<vector<int> > arr, int target)
// {
//     int row = 0;
//     int col = arr[row].size() - 1;
//     while (row < arr.size() && col >= 0) 
//     {
//         if (arr[row][col] == target) {
//             return { row, col};
//         }
//         if (arr[row][col] < target) {
//             row++;
//         }
//         else
//         {
//             col--;
//         }
//     }
//     return { -1, -1 };
// }
// int main()
// {
//     vector<vector<int> > arr = { { 1, 2, 3, 4 },
//                                  { 5, 6, 7, 8 },
//                                  { 9, 10, 11, 12 }};
//     vector<int> ans = findAns(arr, 12);
//     cout << " Element found at Index: [";
//     for (int i = 0; i < ans.size(); i++){
//         if(i == ans.size() -  1)
//         cout << ans[i];
//         else
//         cout<<ans[i]<<" , ";
//     }
//     cout << "]";
// }
// ***************************************************************Row and Column wise sum****************************************************
// #define m 4
// #define n 4
// void row_sum(int arr[m][n])
// {
//     int i,j,sum = 0;
//     cout << "\nFinding Sum of each row: \n\n";
//     for(i = 0; i < m; ++i){
//         for(j = 0; j < n; ++j){
//             sum = sum + arr[i][j];
//         }
//         cout <<"Sum of the row "<<i << " = "<<sum<<endl;
//         sum = 0;
//     }
// } 
// void column_sum(int arr[m][n])
// {
//     int i,j,sum = 0;
//     cout <<" \nFinding Sum of each column:\n\n";
//     for(i = 0; i < m; ++i){
//         for (j = 0; j < n; ++j) {
//             sum = sum + arr[j][i];
//         }
//         cout <<"Sum of the column "<<i << " = "<<sum<<endl;
//         sum = 0;
//     } 
// }
// int main()
// {
//     int i,j;
//     int arr[m][n];
//     int x = 1;
//     for(i =0; i< m; i++)
//     for(j = 0; j < n; j++)
//     arr[i][j] = x++;
//     row_sum(arr);
//     column_sum(arr);
//     return 0;
// }
// ***************************************************************Largest row sum Problem********************************************************
// #define N 5
// pair<int, int> colMaxSum(int mat[N][N])
// {
//     int idx = -1;
//     int maxSum = INT_MIN;
//     for(int i = 0; i < N; i++){
//         int sum = 0;
//         for(int j = 0; j < N; j++) {
//             sum += mat[i][j];
//         }
//         if (sum > maxSum){
//             maxSum = sum;
//             idx = i;
//         }
//     }
//     pair<int, int> res;
//     res = make_pair(idx, maxSum);
//     return res;
// }
// int main()
// {
//     int mat[N][N] = {{ 1, 2, 3, 4, 5 }, { 5, 3, 1, 4, 2 }, { 5, 6, 7, 8, 9 }, { 0, 6, 3, 4, 12 }, { 9, 7, 12, 4, 3 }};
//     pair<int, int> ans = colMaxSum(mat);
//     cout << "Row " << ans.first + 1 << " has max sum " << ans.second;
//     return 0;
// }
// *****************************************************************Wave Form***************************************************************
// #define R 5
// #define C 4 
// void WavePrint(int m, int n, int arr[R][C])
// {
//     for (int j =0; j < n; j++)
//     {
//         if (j % 2 == 0) {
//             for(int i = 0; i < m; i++) {
//                 cout << arr[i][j] << " ";
//             }
//         }
//         else {
//             for (int i = m - 1; i >= 0; i--) {
//                 cout << arr[i][j] << " ";
//             }
//         }
//     }
// }
// int main ()
// {
//     int arr[R][C] = {{ 1, 2, 3, 4 },
//                      { 5, 6, 7, 8 },
//                      { 9, 10, 11, 12 },
//                      { 13, 14, 15, 16 },
//                      { 17, 18, 19, 20 }};
//     WavePrint(R, C, arr);
//     return 0;
// }