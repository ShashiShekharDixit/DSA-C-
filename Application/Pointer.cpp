#include<bits/stdc++.h>
using namespace std;
int getSum(int *arr) {
    int sum =0;
    for(int i =0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    } 
    int ans = getSum(arr, n);
    cout << " Answer is : " <<ans <<endl;
    return 0;
}
// int main()
// {
//     int n;
//     cin>>n;
//     int** arr= new int*[n];
//     for(int i =0; i<n; i++)
//     {
//         arr[i] = new int [n];
//     } 
//     for(int i =0; i<n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin>> arr[i][j];
//         }
//     } 
//     cout<<endl;
//     for(int i =0; i < n; i++){
//     for(int j =0; j< n; j++) {
//         cout << arr[i][j] << " ";;
//     }
//       cout <<endl;
//     }
//     for (int i =0; i,n; i++)
//     {
//         delete[] arr[i];
//     }
//     delete []arr;
// }