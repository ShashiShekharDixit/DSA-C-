#include<iostream>
using namespace std;
// int factorial(int n) {
//     if(n==0)
//      return 1;

    // int small = factorial(n-1);
    // int big = 2 * small;
    // return big;

    // or we also do it like this

//     return n * factorial(n-1);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int ans = factorial(n);
//     cout<<ans<<endl;
//     return 0;
// }
// *******************************************************Power*******************************************
// int power(int n) {
//     if(n==0)
//     return 1;
//     int small = power(n-1);
//     int big = 2 * small;
//     return big;
    // return 2 * power(n-1);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int ans = power(n);
//     cout<<ans<<endl;
//     return 0;
// }
// ************************************************************Print counting tail recursion******************************************************
/// @brief 
/// @param n 
// void printing (int n){
//     if (n==0){
//     return ;
//     }
//     cout<<n<<endl;
//     printing(n-1);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     printing(n);
//     return 0;
// }
// ************************************head recursion countng*********************************************************
// void printing (int n){
//     if (n==0){
//     return ;
//     }
//     printing(n-1);
//     cout<<n<<endl;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     cout<<endl;
//     printing(n);
//     return 0;
// }
// ************************************************Recursion code***************************************************************
// void reachhome(int dest, int src){
//     cout<<"Source " << src <<" Destination " << dest <<endl;
//     if (src == dest){
//         cout<<" reached ";
//         return ;
//     }
//     src++;
//     reachhome(dest,src);
// }
// int main()
// {
//     int dest = 10;
//     int src = 1;
//     cout<<endl;
//     reachhome(dest,src);
//     return 0;
// }
// *******************************************************Fibonnacci Series**********************************************************
// void Fibo(int n){
//     if(n==0)
//     return 0;
//     if(n==1)
//     return 1;
//     int ans = fibo(n-1) + fibo(n-2);
//     return ans;
// }
// ***********************************************************climb stairs**********************************************************
// int stair(int n)
// {
//     if(n==1 || n==2)
//     return n;
//     int way1 = stair(n-1);
//     int way2= stair(n-2);
//     int res=way1+way2;
//     return res;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int result= stair(n);
//     cout<<"No of ways= "<<result;
//     return 0;
// }
// ****************************************************************Say Digit*************************************************************
// void sayDigit (int n, string arr[]) {
//     if(n == 0)
//     return ;
//     int digit =n % 10;
//     n=n/10;
//     sayDigit(n, arr);
//     cout<< arr[digit] << " ";
// }
// int main()
// {
//     string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
//     int n;
//     cin>>n;
//     cout <<endl <<endl <<endl;
//     sayDigit(n, arr);
//     cout << endl <<endl <<endl;
//     return 0;
// }
// ************************************************************************Array**************************************************************
// bool isSorted(int arr[],int size)
// {
//     if(size == 0 || size == 1)
//     {
//         return true;
//     }
//     if(arr[0] > arr[1])
//         return false;
//     else 
//     {
//         bool remainingPart = isSorted(arr + 1,size - 1 );
//         return remainingPart;
//     }
// }
// int main()
// {
//     int arr[5] = {2,5,6,7,9};
//     int size = 5;
//     bool ans = isSorted(arr,size);
//     if(ans){
//         cout<<"Array is Sorted " <<endl;
//     }
//     else{
//         cout<<"Array is not Sorted " <<endl;
//     }
//     return 0;
// }
// ***************************************************************************Sum********************************************************
// int getSum(int arr[], int size)
// {
//     if(size == 0){
//         return 0;
//     }
//     if(size == 1){
//         return arr[0];
//     }
//     int remainingPart = getSum(arr+1, size-1);
//     int sum = arr[0] + remainingPart;
//     return sum;
// }
// int main()
// {
//     int arr[5] = {2,6,4,5,7};
//     int size = 5;
//     int sum = getSum(arr, size);
//     cout<<"Sum is " << sum <<endl;
//     return 0;
// }
// *************************************************************************Linear Search*********************************************
// void print(int arr[], int n) {
//     cout<<"Size of array is " << n <<endl;
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout<<endl;
// }
// bool LinearSearch (int arr[], int size, int key){
//     print(arr,size);
//     if(size == 0)
//     return false;

//     if(arr[0] == key){
//     return true;
//     }

//     else {
//     bool remainingPart = LinearSearch(arr+1,size-1, key);
//     return remainingPart;
//     }

// }
// int main()
// {
//     int arr[5] ={2,5,4,7,8};
//     int size = 5;
//     int key = 0;
//     bool ans = LinearSearch(arr, size, key);
//     if(ans){
//         cout<<"Present " <<endl;
//     }
//     else{
//         cout<<"Absent " <<endl;
//     }
// }
// *******************************************************************Binary Search****************************************************
// void print (int arr[], int size, int e)
// {
//     for(int i=size; i<=e; i++){
//         cout<<arr[i] << " ";
//     }cout <<endl;
// }
// bool BinarySearch(int arr[],int size, int e, int key) {
//     cout <<endl;
//     print (arr, size,e);
//     if(size>e)
//     return false;
//     int mid = size + (e-size)/2;
//     cout<<"value of arr mid is " << arr[mid] <<endl;
//     if(arr[mid] == key)
//     return true;
//     if(arr[mid] < key) {
//         return BinarySearch(arr, mid+1, e, key);
//     }
//     else {
//         return BinarySearch(arr, size, mid-1, key);
//     }
// }
// int main() {
//     int arr[6] = {2,4,6,8,10,12};
//     int size = 6;
//     int key = 12;
//     cout<<"Present or not "<< BinarySearch(arr, 0, size-1, key) <<endl;
//     return 0;
// }
// ******************************************************************Reverse string***************************************************
// void reverse(string &str, int i, int j )
// {
//     cout<<"call received for " <<str <<endl;
//     if(i>j)
//     return ;
//     swap(str[i], str[j]);
//     i++;
//     j--;
//     reverse(str, i, j);
// }
// int main()
// {
//     string name = " abcde ";
//     cout<<endl;
//     reverse(name, 0, name.length()-1 );
//     cout<<endl;
//     cout<< name <<endl;
//     return 0;
// }
// *******************************************************************Palindrome********************************************************
// bool checkPalindrome(string str, int i, int j) {
//     if(i>j)
//     return true;
//     if(str[i] != str[j])
//     return false;
//     else{
//         return checkPalindrome(str, i+1, j-1);
//     }
// }
// int main()
// {
//     string name = " nitin ";
//     cout<<endl;
//     bool isPalindrome = checkPalindrome(name, 0, name.length()-1 );
//     if(isPalindrome){
//         cout<<"Its a Palindrome" <<endl;
//     }
//     else {
//         cout<<"Its Not a Palindrome" <<endl;
//     }
//     return 0;
// }
// ***********************************************************************Calculating Power*********************************************
// int power(int a, int b) {
//     if(b == 0)
//     return 1;
//     if(b == 1)
//     return a;
//     int ans = power(a, b/2);
//     if(b%2 == 0) {
//         return ans * ans;
//     }
//     else {
//         return a * ans * ans;
//     }
// }
// int main()
// {
//     int a, b;
//     cin>> a >> b;
//     int ans = power(a,b);
//     cout<<"Answer is "<< ans <<endl;
//     return 0;
// }
// ******************************************************************Bubble Sort********************************************************
// void sortarray(int arr[], int n) {
//     if(n == 0 || n == 1) {
//         return ;
//     }
//     for(int i = 0; i<n; i++){
//         if(arr[i] > arr[i+1]){
//             swap(arr[i], arr[i+1]);
//         }
//     }
//     sortarray(arr, n-1);
// }
// int main()
// {
//     int arr[5] = {2,4,6,1,0};
//     sortarray(arr,5);
//     for(int i=0; i<5; i++){
//       cout<<arr[i] <<" ";
//     }
//     return 0;
// }
// **********************************************************************Merge Sort*************************************************
// void merge(int *arr,int s, int e){
//     int mid = (s+e)/2;
//     int len1 = mid - s + 1;
//     int len2 = e - mid;
//     int *first = new int[len1];
//     int *second = new int[len2];
//     int mainArrayIndex = s;
//     for(int i=0; i<len1; i++) {
//         first[i] = arr[mainArrayIndex++];
//     }
//     mainArrayIndex = mid+1;
//     for(int i=0; i<len2; i++) {
//         second[i] = arr[mainArrayIndex++];
//     }
//     int index1 = 0;
//     int index2 = 0;
//     mainArrayIndex = s;
//     while(index1 < len1 && index2 < len2) {
//      if(first[index1] < second[index2]) {
//         arr[mainArrayIndex++] = first[index1++];
//      }
//      else{
//         arr[mainArrayIndex++] = second[index2++];
//      }
//     }
//     while(index1 < len1) {
//         arr[mainArrayIndex++] = first[index1++];
//     }
//     while(index2 < len2) {
//         arr[mainArrayIndex++] = second[index2++];
//     }
// delete[]first;
// delete[]second;
// }

// void mergeSort(int *arr, int s, int e) {
//     if(s >= e){
//         return;
//     }
//     int mid = (s+e)/2;
//     mergeSort(arr, s, mid);
//     mergeSort(arr, mid+1, e);
//     merge(arr, s, e);
// }

// int main ()
// {
//     int arr[5] = {4,5,6,3,2};
//     int n=5;
//     mergeSort(arr, 0, n-1);
//     for(int i=0;i<n;i++){
//     cout<<arr[i] << " ";
//     }cout<<endl;
//     return 0;
// }
// ****************************************************************Quick sort**********************************************
// int partition(int arr[], int s, int e) {
//     int pivot = arr[s];
//     int cnt = 0;
//     for(int i = s+1; i<=e; i++) {
//         if(arr[i] <=pivot) {
//             cnt++;
//         }
//     }
//     int pivotIndex = s + cnt;
//     swap(arr[pivotIndex], arr[s]);
//     int i = s, j = e;
//     while ((i < pivotIndex && j > pivotIndex))
//     {
//         while(arr[i] < pivot)
//         {
//             i++;
//         }
//         while(arr[j] > pivot) {
//             j--;
//         }
//         if(i < pivotIndex && j > pivotIndex) {
//             swap(arr[i++], arr[j--]);
//         }
//     }
//     return pivotIndex;   
// }
// void quickSort(int arr[], int s, int e) {
//     if(s >= e)
//     return ;
//     int p = partition(arr, s, e);
//     quickSort(arr, s, p-1);
//     quickSort(arr, p+1, e);
// }
// int main()
// {
//     int arr[5] = {6,8,3,7,10};
//     int n = 5;
//     quickSort(arr, 0, n-1);
//     for(int i=0; i<n; i++)
//     {
//         cout<<arr[i] << " ";
//     }cout<<endl;
//     return 0;
// }