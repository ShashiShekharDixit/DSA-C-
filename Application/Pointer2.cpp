#include<iostream>
using namespace std;
// void print(int *p)
// {
//     cout << *p << endl;
// }

// void update(int *p)
// {
//     *p = *p + 1;
// }
// int getSum(int *arr, int n)
// {
//     cout << sizeof(arr) <<endl;
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     return sum;
// }

//      Double functions

// void update(int **p2)
// {
//     // p2 = p2 + 1;
//     // *p2 = *p2 + 1;
//     **p2 = **p2 + 1;
// }
// int main() {
//     int arr[6] = { 1, 2, 3, 4, 5, 8};
//     cout << "Sum is : "<<getSum(arr+3, 3)<<endl;
    // int num = 5;
    // double num = 5;
    // int *ptr = &num;
    // double d = 4.5;
    // double *p2 = &d;
    // cout << " Print the value of num:  "<<num<<endl;
    // cout << " Print the Address of num:  "<<&num<<endl;
    // cout << " Print the Address of ptr:  "<<ptr<<endl;
    // cout << " Print the value of ptr:  "<<*ptr<<endl;
    // cout << " Print the Address of p2:  "<<p2<<endl;
    // cout << " Print the value of p2:  "<<*p2<<endl;
    // cout << " size of p2 : "<<sizeof(p2)<<endl;
    // cout << " size of num : "<<sizeof(num)<<endl;
    // int i = 5;
    // int *pt = 0;
    // pt = &i;
    // cout << pt << endl;
    // cout << *pt << endl;
    // cout<<"Before : " <<num<<endl;
    // (*ptr)++;
    // cout <<"After : " <<num<<endl;
    
    // Copying a pointer
    // int *q = ptr;
    // cout << ptr <<"-" << q <<endl;
    // cout << *ptr <<"-" << *q << endl;

    // Increament of pointer Address
    // int *t = &num;
    // *t = *t + 1;
    // cout << *t <<endl;
    // cout << " Before : " <<t <<endl;
    // t = t + 1;
    // cout << " After : " <<t <<endl;

    // double *t = &num;
    // *t = *t + 1;
    // cout << *t <<endl;
    // cout << " Before : " <<t <<endl;
    // t = t + 1;
    // cout << " After : " <<t <<endl;

    // int arr[10] = {0};
    // cout << " First address of an array : "<<arr<<endl;
    // cout << arr[0] <<endl;
    // cout << "First address of an array : "<<&arr[0]<<endl;

    // Value of any particular Address
    // int arr[10] = {23, 41, 35, 67};
    // int i = 3;
    // cout << i[arr] << endl;
    
    // Size of any variable
    // int temp[10] ={1,2};
    // cout << sizeof(temp)<<endl;
    // cout << "1st : "<<sizeof(*temp)<<endl;
    // cout << "2nd : "<<sizeof(&temp)<<endl;

    // int *ptr = &temp[0];
    // cout << sizeof(ptr) <<endl;
    // cout << sizeof(*ptr) <<endl;
    // cout << sizeof(&ptr) <<endl;

    // int a[20] = {1, 2, 3, 4};
    // cout << &a[0] <<endl;
    // cout << &a <<endl;
    // cout << a <<endl;

    // int *p = &a[0];
    // cout << p <<endl;
    // cout << *p <<endl;
    // cout <<&p <<endl;

    // int arr[10];
    // int *ptr = &arr[0];
    // cout << ptr <<endl;
    // ptr = ptr + 1;
    // cout << ptr <<endl;

    // Functions in pointer
    // int value = 5;
    // int *p = &value;

    // print(p);
    // cout << "Before : " << *p << endl;
    // update(p);
    // cout << "After : " << *p << endl;





    //   Double Pointer 
    // int i = 5;
    // int* p = &i;
    // int** p2 = &p;
    // cout << " printing p " << p << endl;
    // cout <<  *p2  << endl;
    // cout << i << endl;
    // cout << *p << endl;
    // cout << **p2 << endl; 
    // cout << &i << endl;
    // cout << p << endl;
    // cout << *p2 << endl;
//     int i =5;
//     int* p = &i;
//     int** p2 = &p;
//     cout << " Before : " << i << endl;
//     cout << " Before : " << p << endl;
//     cout << " Before : " << p2 <<endl;
//     update(p2);
//     cout << " After : " << i << endl;
//     cout << " After : " << p << endl;
//     cout << " After : " << p2 << endl;
//     return 0;
// }

// Global Varubale
// int score = 15;
// void a(int& i) {
//     cout << score <<" in a "<<endl;
//     char ch = 'a';
//     cout << i << endl;
// }
// void b(int& i) {
//     cout << score  << " in b " << endl;
//     cout << i << endl;
// }
// int main()
// {
//     cout << score << " in main " << endl;
//     int i = 5;
//     a(i);
//     b(i);
//     return 0;
// }

// Inline Function
// inline int getMax(int& a, int& b) {
//     return (a>b) ? a : b ;
// }
// int main()
// {
//     int a = 1, b = 2;
//     int ans = 0;
//     ans = getMax(a,b);
//     cout << ans << endl;
//     a = a + 3;
//     b = b + 1;
//     ans = getMax(a,b);
//     cout << ans << endl;
//     return 0;
// }

// Default Argument
// void print(int arr[], int n, int start = 0)
// {
//     for ( int i = start; i < n; i++) {
//         cout << arr[i] << endl;
//     }
// }
// int main()
// {
//     int arr[5] = {1,3,5,7,9};
//     int size = 5;
//     print(arr, size);
//     cout <<endl;
//     print (arr, size, 2);
//     return 0;
// }