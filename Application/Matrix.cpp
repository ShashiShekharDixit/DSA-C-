#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
// *****************************************************************Spiral Print**************************************************************
// #define R 4
// #define C 4
// void spiralPrint(int m, int n, int a[R][C])
// {
//     int i, k = 0, l = 0;
//     while (k <=m-l && l < n) {
//         for (i = l; i < n; ++i) {
//             cout << a[k][i] << " ";
//         }
//         k++;
//         for (i = k; i < m; ++i) {
//             cout << a[i][n - 1] << " ";
//         }
//         n--;
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 cout<<a[m - 1][i] << " ";
//             }
//             m--;
//         }
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 cout << a[i][l] << " ";
//             }
//             l++;
//         }
//     }
// } 
// int main()
// {
//     int a[R][C] = {{ 1, 2, 3, 4 },
//                    { 5, 6, 7, 8 },
//                    { 9, 10, 11, 12 },
//                    { 13, 14, 15, 16 }};
//     spiralPrint(R , C , a );
//     return  0 ;
// }
// *********************************************************************Traversal of Matrix********************************************************
// #define Row 5
// #define Col 4
// int minu(int a, int b)
// {
//     return (a < b) ? a : b;
// }
// int min(int a, int b, int c)
// {
//     return minu(minu(a, b), c);
// }
// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }
// void diagonalOrder(int matrix[][Col])
// {
//     for(int line = 1;
//     line <= (Row + Col - 1);
//     line++)
//     {
//         int start_col = max(0, line - Row);
//         int count = min(line, (Col - start_col), Row);
//         for(int j =0; j < count; j++)
//         cout << setw(5) << matrix[minu(Row, line) - j - 1][start_col + j];
//         cout << "\n";
//     }
// }
// void printMatrix(int matrix[Row][Col])
// {
//     for(int i =0; i < Row; i++)
//     {
//         for(int j =0; j < Col; j++)
//         cout << setw(5) << matrix[i][j];
//         cout << "\n";
//    }
// }
// int main()
// {
//     int M[Row][Col] = {{ 1, 2, 3, 4 },
//                        { 5, 6, 7, 8 },
//                        { 9, 10, 11, 12 },
//                        { 13, 14, 15, 16 },
//                        { 17, 18, 19, 20 }};
//     cout<<"Given Matrix is : "<<endl;
//     printMatrix(M);
//     cout<<" \nDiagonal printing of matirx is : " <<endl;
//     diagonalOrder(M);
//     return 0;
// }
// ***********************************************************Set Matrix Zeroes*************************************************************
// void SetMatrixZeroes(vector<vector<int> >& arr)
// {
//    int n =arr.size(), m = arr[0].size();
//    vector<int> row(n, 0), col(m, 0);
//    for (int i =0; i < arr.size(); i++) {
//     for (int j=0 ; j < arr[0].size(); ++j){
//         if (arr[i][j] == 0) {
//             row[i] = 1;
//             col[j] = 1;
//         }
//    }
// }
// for (int i =0; i < arr.size(); i++) {
//     for (int j =0; j < arr[0].size(); j++) {
//         if (row[i] || col[j])
//         arr[i][j] = 0;
//     }
// }
// }
// int main()
// {
//     vector<vector<int> > arr = {{ 0, 1, 2, 0 },
//     { 3, 4, 5, 2 },
//     { 1, 3, 1, 5 }};
//     SetMatrixZeroes(arr);
//     for(int i =0; i < arr.size(); i++){
//     for (int j =0; j < arr[0].size(); j++) {
//         cout << arr[i][j] << " ";
//     }
//     cout << endl;
//     }
//     return 0;
// }
// ********************************************************************Rotate image*************************************************************
// void rotateMatrix(vector<vector<int> >& mat)
// {
//     int n = mat.size();
//     int m = mat[0].size();
//     vector<vector<int> > new_mat(m, vector<int>(n));
//     for (int i = 0; i < n; i++) {
//         for (int j =0; j < m; j++) {
//             new_mat[j][n - i - 1] = mat[i][j];
//         }
//     }
//     mat = new_mat;
// }
// void displayMatrix(vector<vector<int> >& mat)
// {
//     int n = mat.size();
//     int m = mat[0].size();
//     for (int i =0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << mat[i][j] << " ";
//         }
//         cout <<endl;
//     }
//     cout << endl;
// }
// int main()
// {
//     vector<vector<int> >mat {
//         { 1, 2, 3, 4 },
//         { 5, 6, 7, 8 },
//         { 9, 10, 11, 12 }};
//     rotateMatrix(mat);
//     displayMatrix(mat);
//     return 0;
// }
// ******************************************************************replace "O" by "X"*************************************************************
// #define M 6
// #define N 6
// void floodfillUtil(char mat[][N], int x, int y, char prevV, char newV)
// {
//     if (x < 0 || x >= M || y < 0 || y >= N)
//     return;
//     if (mat[x][y] != prevV)
//     return;
//     mat[x][y] = newV;
//     floodfillUtil(mat, x+1, y, prevV, newV);
//     floodfillUtil(mat, x-1, y, prevV, newV);
//     floodfillUtil(mat, x, y+1, prevV, newV);
//     floodfillUtil(mat, x, y-1, prevV, newV);
// }
// int replaceSurrounded(char mat[][N])
// {
//     for (int i =0; i<M; i++)
//     for(int j =0; j<N; j++)
//     if(mat[i][j] == 'O')
//     mat[i][j] = '-';

//     for(int i =0; i < M; i++)
//     if (mat[i][0] == '-')
//     floodfillUtil(mat, i, 0, '-', 'O');

//     for(int i = 0; i < M; i++)
//     if (mat[i][N-1] == '-')
//     floodfillUtil(mat, i, N-1, '-', 'O');

//     for(int i = 0; i < N; i++)
//     if (mat[0][i] == '-')
//     floodfillUtil(mat, 0, i, '-', 'O');

//     for(int i = 0; i < N; i++)
//     if (mat[M-1][i] == '-')
//     floodfillUtil(mat, i, M-1, '-', 'O');

//     for (int i =0; i<M; i++)
//     for (int j =0; j < N; j++)
//     if(mat[i][j] == '-')
//     mat[i][j] = 'X';
// }
// int main()
// {
//     char mat[][N] ={{'X', 'O', 'X', 'O', 'X', 'X' },
//                     {'X', 'O', 'X', 'X', 'O', 'X' },
//                     {'X', 'X', 'X', 'O', 'X', 'X' },
//                     {'O', 'X', 'X', 'X', 'X', 'X' },
//                     {'X', 'X', 'X', 'O', 'X', 'O' },
//                     {'O', 'O', 'X', 'O', 'O', 'O' },};
//     replaceSurrounded(mat);
//     for(int i =0; i<M; i++)
//     {
//       for (int j =0; j<N; j++)
//       cout << mat[i][j] << " ";
//       cout <<endl;
//     }
//     return 0;
// }
// ******************************************************************Common element in all row***********************************************
// #define M 4
// #define N 5
// int findCommon(int mat[M][N])
// {
//     int column[M];
//     int min_row;
//     int i;
//     for (i =0; i< M; i++)
//     column[i] = N - 1;
//     min_row = 0;
//     while (column[min_row] >= 0) {
//         for (i =0; i < M; i++) {
//             if (mat[i][column[i]] < mat[min_row][column[min_row]])
//             min_row = i;
//         }
//         int eq_count = 0;
//         for (i = 0; i < M; i++) {
//             if(mat[i][column[i]] > mat[min_row][column[min_row]]) {
//                 if (column[i] == 0)
//                 return -1;
//                 column[i] -= 1;
//             }
//             else
//             eq_count++;
//         }
//         if (eq_count == M)
//         return mat[min_row][column[min_row]];
//     }
//     return -1;
// }
// int main()
// {
//     int mat[M][N] = {{ 1, 2, 3, 4, 5 },
//                      { 2, 4, 5, 8, 10 },
//                      { 3, 5, 7, 9, 11 },
//                      { 1, 3, 5, 7, 9 }};
//     int result = findCommon(mat);
//     if (result == -1)
//     cout << " No coomon element ";
//     else
//     cout<< "The common elements are "<< result ;
//     return  0;
// }
// **********************************************Create matrix with alternating rectangle of O annd X****************************************
// void fillOX(int m ,int n)
// {
//     int i, k = 0, l = 0;
//     int r = m, c = n;
//     char a[m][n];
//     char x = 'X';
//     while (k < m && l < n)
//     {
//         for (i = l; i < n; ++i)
//         a[k][i] = x;
//         k++;
//         for(i = k; i < m; ++i)
//         a[i][n - 1] = x;
//         n--;
//         if (k < m)
//         {
//             for (i = n - 1; i >= l; --i)
//             a[m - 1][i] = x;
//             m--;
//         }
//         if(l < n)
//         {
//             for (i = m - 1; i >= k; --i)
//             a[i][l] = x;
//             l++;
//         }
//         x = (x == 'O')? 'X': 'O';
//     }
//     for (i = 0; i < r; i++)
//     {
//         for(int j = 0; j < c; j++)
//         cout << " "<<a[i][j];
//         cout << "\n";
//     }
// }
// int main()
// {
//     puts("Output for m =5, n = 6");
//     fillOX(5, 6);
//     puts("Output for m =4, n = 5");
//     fillOX(4, 5);
//     return 0;
// }
// ************************************************************Search element in 2d array*****************************************************
// vector<int> findAns(vector<vector<int> > arr, int target)
// {
//     int row = 0;
//     int col = arr[row].size() - 1;
//     while (row < arr.size() && col >= 0) {
//         if (arr[row][col] == target) {
//             return { row , col };
//         }
//         if (arr[row][col] < target) {
//             row++;
//         }
//         else {
//             col--;
//         }    
//     }
//     return { -1, -1 };
// }
// int main()
// {
//     vector<vector<int> > arr = {{1, 2, 3, 4 },
//                                 {5, 6, 7, 8 },
//                                 {9, 10, 11, 12 }};
//     vector<int> ans = findAns(arr, 6);
//     cout << "Element found at index: [";
//     for (int i = 0; i < ans.size(); i++){
//         if (i == ans.size() - 1)
//         cout << ans[i];
//         else
//         cout << ans[i] << ", ";
//     }
//     cout << "]";
// }
// ***************************************************************Median in a row wise sorted matrix***********************************************
// double find_median(vector<vector<int>> matrix) {
//     vector<int> arr;
//     for (int i =0; i < matrix.size(); i++) {
//         for (int j=0 ; j <matrix[0].size(); j++ ) {
//             arr.push_back(matrix[i][j]);
//         }
//     }
//     sort(arr.begin(), arr.end());
//     int mid = arr.size() / 2;
//     double median;
//     if (arr.size() % 2 == 0) {
//         median = (arr[mid - 1] + arr[mid]) / 2.0;
//     }
//     else {
//         median = arr[mid];
//     }
//     return median;
// }
// int main()
// {
//     vector<vector<int>> matrix1 = {{1, 3, 5},
//                                     {2, 6, 9},
//                                     {3, 6, 9}};
//     double median1 = find_median(matrix1);
//     cout << " Median of Matrix1: " << median1 <<endl;
//     vector<vector<int>> matrix2 = {{1, 3, 5},
//                                     {2, 5, 6},
//                                     {7, 8, 9}};
//     double median2 = find_median(matrix2);
//     cout << " Median of Matrix2: " << median2 <<endl;
//     return 0;
// }
// ****************************************************************Row with max 1's************************************************************
// #define R 4
// #define C 4
// int rowWithMax1s(bool mat[R][C]) {
//     int rowIndex = -1;
//     int maxCount = 0;
//     for(int i =0; i < R; i++){
//         int count = 0;
//         for(int j = 0; j < C; j++ ) {
//             if(mat[i][j] == 1){
//                 count++;
//             }
//         }
//         if(count > maxCount) {
//             maxCount = count;
//             rowIndex = i;
//         }
//     }
//     return rowIndex;
// }
// int main()
// {
//     bool mat[R][C] = {{ 0, 0, 0, 1},
//                       { 0, 1, 1, 1},
//                       { 1, 1, 1, 1},
//                       { 0, 0, 0, 0}};
//     cout<<"Index of row with maximum 1s is " <<rowWithMax1s(mat);
//     return 0;
// }
// **************************************************************Specific pair in Matrix******************************************************
// #define N 5
// int findMaxValue(int mat[][N])
// {
//     int maxValue = INT_MIN;
//     for(int a = 0; a < N - 1; a++)
//     for(int b = 0; b < N - 1; b++)
//     for (int d = a + 1; d < N; d++)
//     for (int e = b + 1; e < N; e++)
//     if (maxValue < (mat[d][e] - mat[a][b]))
//     maxValue = mat[d][e] - mat[a][b];
//     return maxValue;
// }
// int main()
// {
//     int mat[N][N] = {{ 1, 2, -1, -4, -20 },
//                      { -8, -3, 4, 2, 1 },
//                      { 3, 8, 6, 1, 3 },
//                      { -4, -1, 1, 7, -6 },
//                      { 0, -4, 10, -5, 1 }};
//     cout << "Maximum Value is " << findMaxValue(mat);
//     return 0;
// }
// ************************************************Kth smallest element in a row and column wise sorted***************************************
// int kthSmallest(int arr[][4], int n, int k)
// {
//     priority_queue<int, vector<int>, greater<int> >pq;
//     for (int i =0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             pq.push(arr[i][j]);
//         }
//     }
//     int c = 0;
//     while(!pq.empty()) {
//         int temp = pq.top();
//         pq.pop();
//         c++;
//         if(c == k)
//         return temp;
//     }
//     return -1;
// }
// int main()
// {
//     int mat[4][4] = {{ 10, 20, 30, 40 },
//                      { 15, 25, 35, 45 },
//                      { 25, 29, 37, 48 },
//                      { 32, 33, 39, 50 }};
//     int res = kthSmallest(mat, 4, 16);
//     cout << "7th smallest element is " <<res <<endl;
//     return 0;
// }
// ****************************************************************Maximum size rectangle*********************************************************
// #define R 4
// #define C 4
// int maxHist(int row[])
// {
//     stack<int> result;
//     int top_val;
//     int max_area = 0;
//     int area = 0;
//     int i = 0;
//     while (i < C)
//     {
//         if (result.empty() || row[result.top()] <= row[i])
//         result.push(i++);
//         else
//         {
//             top_val = row[result.top()];
//             result.pop();
//             area = top_val * i;
//             if (!result.empty())
//             area = top_val * (i - result.top() - 1);
//             max_area = max(area, max_area);
//         }
//     }
//     while (!result.empty()) {
//         top_val = row[result.top()];
//         result.pop();
//         area = top_val * i;
//         if (!result.empty())
//         area = top_val * (i - result.top() - 1);
//         max_area = max(area, max_area);
//     }
//     return max_area;
// }
// int maxRectangle(int A[][C])
// {
//     int result = maxHist(A[0]);
//     for (int i = 1; i< R; i++) {
//         for (int j =0; j < C; j++)
//         if (A[i][j])
//         A[i][j] += A[i - 1][j];
//         result = max(result, maxHist(A[i]));
//     }
//     return result;
// }
// int main()
// {
//     int A[][C] = {{ 0, 1, 1, 0 },
//                   { 1, 1, 1, 1 },
//                   { 1, 1, 1, 1 },
//                   { 1, 1, 0, 0 }};
//     cout << "Area of maximum rectangle is " << maxRectangle(A);
//     return 0;
// }