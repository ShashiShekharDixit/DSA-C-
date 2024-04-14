// Rat in a maze
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
// #define N 4
// bool solveMazeUtil(int maze[N][N],  int x, int y, int sol[N][N]);
// void printSolution(int sol[N][N])
// {
//     for (int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++)
//         cout<<" "<<sol[i][j]<<" ";
//         cout<<endl;
//     }
// }
// bool isSafe(int maze[N][N], int x, int y)
// {
//     if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
//     return true;
//     return false;
// }
// bool solveMaze(int maze[N][N])
// {
//     int sol[N][N] = { {0, 0, 0, 0},
//                       {0, 0, 0, 0},
//                       {0, 0, 0, 0},
//                       {0, 0, 0, 0} };
//     if (solveMazeUtil(maze, 0, 0, sol) == false) {
//         cout<<"Solution doesn't exist";
//         return false;
//     }
//     printSolution(sol);
//     return true;
// }
// bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
// {
//     if (x == N - 1 && y == N -1 && maze[x][y] == 1) {
//         sol[x][y] = 1;
//         return true;
//     }
//     if (isSafe(maze, x, y) == true) {
//         if (sol[x][y] == 1)
//         return false;
//         sol[x][y] = 1;
//         if (solveMazeUtil(maze, x + 1, y, sol) == true)
//         return true;
//         if (solveMazeUtil(maze, x - 1, y, sol) == true)
//         return true;
//         if (solveMazeUtil(maze, x, y + 1, sol) == true)
//         return true;
//         if (solveMazeUtil(maze, x, y - 1, sol) == true)
//         return true;
//         sol[x][y] = 0;
//         return false;
//     }
//     return false;
// }
// int main ()
// {
//     int maze[N][N] = { {1, 0, 0, 0},
//                        {1, 1, 0, 1},
//                        {0, 1, 0, 0},
//                        {1, 1, 1, 1}};
//     solveMaze(maze);
//     return 0;
// }
// *******************************************************************Combinational Sum*****************************************
// void findNumbers(vector<int>& ar, int sum,vector<vector<int> >& res, vector<int>& r,int i)
// {
//     if (sum == 0) {
//         res.push_back(r);
//         return;
//     }
//     while (i < ar.size() && sum - ar[i] >= 0) {
//         r.push_back(ar[i]);
//         findNumbers(ar, sum - ar[i], res, r, i);
//         i++;
//         r.pop_back();
//     }
// }
//     vector<vector<int> > combinationSum(vector<int>& ar, int sum)
// {
//     sort(ar.begin(), ar.end());
//     ar.erase(unique(ar.begin(), ar.end()), ar.end());
//     vector<int> r;
//     vector<vector<int> > res;
//     findNumbers(ar, sum, res, r, 0);
//     return res;
// }
// int main()
// {
//     vector<int> ar;
//     ar.push_back(2);
//     ar.push_back(4);
//     ar.push_back(6);
//     ar.push_back(8);
//     int n = ar.size();
//     int sum = 8;
//     vector<vector<int> > res = combinationSum(ar, sum);
//     if (res.size() == 0) {
//         cout<<"Empty";
//         return 0;
//     }
//     for (int i = 0; i < res.size(); i++) {
//         if (res[i].size() > 0) {
//             cout<<" ( ";
//             for (int j = 0; j < res[i].size(); j++)
//             cout << res[i][j] << " ";
//             cout << " ) ";
//         }
//     }
//     return 0;
// }
// **********************************************************Crossword Puzzle******************************************************
// (line no. 118)
// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> crosswordPuzzle(vector<string> crossword, string words) {
//     return;
// }
// string ltrim(const string &str) {
//     string s(str);
//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(),not1(ptr_fun<int, int>(isspace)))
//     );
//     return s;
// }
// string rtrim(const string &str) {
//     string s(str);
//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),s.end());
//         return s;
// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));
//     vector<string> crossword(10);
//     for (int i = 0; i < 10; i++) {
//         string crossword_item;
//         getline(cin, crossword_item);
//         crossword[i] = crossword_item;
//     }
//     string words;
//     getline(cin, words);
//     vector<string> result = crosswordPuzzle(crossword, words);
//     for(size_t i = 0; i < result.size(); i++) {
//         fout << result[i];
//         if(i != result.size() -1)
//         {
//         fout << "\n";
//         }
//     }
//     fout << "\n";
//     fout.close();
//     return 0;
// }
// **********************************************Longest Possible Route in a Matrix with Hurdles***********************************
// #define R 3
// #define C 10
// struct Pair {
//     bool found;
//     int value;
// };
// Pair findLongestPathUtil(int mat[R][C], int i, int j, int x, int y, bool visited[R][C])
// {
//     if (i == x && j == y) {
//         Pair p = { true, 0 };
//         return p;
//     }
//     if (i < 0 || i >= R || j < 0 || j >= C || mat[i][j] == 0 || visited[i][j]) {
//         Pair p = { false, INT_MAX};
//         return p;
//     }
//     visited[i][j] = true;
//     int res = INT_MIN;
//     Pair sol = findLongestPathUtil(mat, i, j - 1, x, y, visited);
//     if (sol.found)
//     res = max(res, sol.value);
//     sol = findLongestPathUtil(mat, i, j + 1, x, y, visited);
//     if(sol.found)
//     res = max(res, sol.value);
//     sol = findLongestPathUtil(mat, i - 1, j, x, y, visited);
//     if (sol.found)
//     res = max(res, sol.value);
//     sol = findLongestPathUtil(mat, i + 1, j, x, y, visited);
//     if (sol.found)
//     res = max(res, sol.value);
//     visited[i][j] = false;
//     if (res != INT_MIN) {
//         Pair p = { true, 1 + res };
//         return p;
//     }
//     else {
//         Pair p = {false, INT_MAX };
//         return p;
//     }
// }
// void findLongestPath(int mat[R][C], int i, int j, int x, int y)
// {
//     bool visited[R][C];
//     memset(visited, false, sizeof visited);
//     Pair p = findLongestPathUtil(mat, i, j, x, y, visited);
//     if (p.found){
//     cout<< "Length of longest possible route is " << p.value;
//     }
//     else{
//         cout<< "Destination not reachable from given " "source";
//     }
// }
// int main()
// {
//     int mat[R][C] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//                       {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
//                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
//     findLongestPath(mat, 0, 0, 1, 7);
//     return 0;
// }
// *********************************************Printing  all solution in N-Queen Problem*************************************
// vector<vector<int> > result;
// bool isSafe(vector<vector<int> > board, int row, int col)
// {
//     int i, j;
//     int N = board.size();
//     for (i = 0; i < col; i++)
//     if (board[row][i])
//     return false;
//     for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
//     if(board[i][j])
//     return false;
//     for (i = row, j = col; j >= 0 && i < N; i++, j--)
//     if (board[i][j])
//     return false;
//     return true;
// }
// bool solveNQUtil(vector<vector<int> >& board, int col)
// {
//     int N = board.size();
//     if (col == N) {
//         vector<int> v;
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++){
//                 if (board[i][j] == 1)
//                 v.push_back(j + 1);
//             }
//         }
//         result.push_back(v);
//         return true;
//     }
//     bool res = false;
//     for (int i = 0; i < N; i++) {
//         if (isSafe(board, i, col)) {
//             board[i][col] = 1;
//             res = solveNQUtil(board, col + 1) || res;
//             board[i][col] = 0;
//         }
//     }
//     return res;
// }
// vector<vector<int> > nQueen(int n)
// {
//     result.clear();
//     vector<vector<int> > board(n, vector<int>(n, 0));
//     if (solveNQUtil(board, 0) == false) {
//         return {};
//     }
//     sort(result.begin(), result.end());
//     return result;
// }
// int main()
// {
//     int n = 4;
//     vector<vector<int> > v = nQueen(n);
//     for (auto ar : v) {
//         cout<<"[";
//         for (auto it : ar)
//         cout << it << " ";
//         cout << "]";
//     }
//     return 0;
// }
// *************************************************Suduko Solution***************************************************
// #define N 9
// int Grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
//                   {5, 2, 0, 0, 0, 0, 0, 0, 0},
//                   {0, 8, 7, 0, 0, 0, 0, 3, 1},
//                   {0, 0, 3, 0, 1, 0, 0, 8, 0},
//                   {9, 0, 0, 8, 6, 3, 0, 0, 5},
//                   {0, 5, 0, 0, 9, 0, 6, 0, 0},
//                   {1, 3, 0, 0, 0, 0, 2, 5, 0},
//                   {0, 0, 0, 0, 0, 0, 0, 7, 4},
//                   {0, 0, 5, 2, 0, 6, 3, 0, 0}
// };
// bool isPresentInCol(int col, int num){
//     for (int row = 0; row < N; row++)
//     if (Grid[row][col] == num)
//     return true;
//     return false;
// }
// bool isPresentInRow(int row, int num) {
//     for (int col = 0; col < N; col++)
//     if (Grid[row][col] == num)
//     return true;
//     return false;
// }
// bool isPresentInBox(int boxStartRow, int boxStartCol, int num) {
//     for (int row = 0; row < 3; row++)
//     for (int col = 0; col < 3; col++)
//     if (Grid[row+boxStartRow][col+boxStartCol] == num)
//     return true;
//     return false;
// }
// void SudokuGrid() {
//     for (int row = 0; row < N; row++){
//         for (int col = 0; col < N; col++){
//             if(col == 3 || col == 6)
//             cout<< " | ";
//             cout<< Grid[row][col] << " ";
//         }
//         if(row == 2 || row == 5) {
//             cout<<endl;
//             for(int i = 0; i<N; i++)
//             cout<< " --- ";
//         }
//         cout<<endl;
//     }
// }
// bool findEmptyPlace(int &row, int &col) {
//     for (row = 0; row < N; row++)
//     for (col = 0; col < N; col++)
//     if (Grid[row][col] == 0)
//     return true;
//     return false;
// }
// bool isValidPlace(int row, int col, int num){
//     return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3, col - col%3, num);
// }
// bool solveSudoku(){
//     int row, col;
//     if(!findEmptyPlace(row, col))
//     return true;
//     for (int num = 1; num <= 9; num++){
//         if (isValidPlace(row, col, num)){
//             Grid[row][col] = num;
//             if (solveSudoku())
//             return true;
//             Grid[row][col] = 0;
//         }
//     }
//     return false;
// }
// int main ()
// {
//     if (solveSudoku() == true){
//     SudokuGrid();
//     }
//     else
//     {
//     cout<<" No Solution Exists ";
//     }
// }
// ***********************************************Parition Equal Subset Sum***********************************************
// bool isSubsetSum(int arr[], int n, int sum)
// {
//     if (sum == 0)
//     return true;
//     if (n == 0 && sum != 0)
//     return false;
//     if (arr[n - 1] > sum)
//     return isSubsetSum(arr, n - 1, sum);
//     return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
// }
// bool findPartition(int arr[], int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     sum += arr[i];
//     if (sum % 2 != 0)
//     return false;
//     return isSubsetSum(arr, n, sum / 2);
// }
// int main()
// {
//     int arr[] = { 3, 1, 5, 9, 12 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     if (findPartition(arr,  n) == true){
//     cout<< "Can be divided into two subsets " "of equal sum";
//     }
//     else{
//     cout<< "Cannot be divided into two subsets" " of equal sum";
//     }
//     return 0;
// }
// ******************************************************M-coloring Problem****************************************************
// #define V 4
// void printSolution(int color[]);
// bool isSafe(int v, bool graph[V][V], int color[], int c)
// {
//     for (int i = 0; i < V; i++)
//             if (graph[v][i] && c == color[i])
//                 return false;

//     return true;
// }
// bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
// {
//     if (v == V)
//     return true;
//     for (int c = 1; c <= m; c++) {
//         if (isSafe(v, graph, color, c)) {
//             color[v] = c;
//             if (graphColoringUtil(graph, m, color, v + 1) == true)
//             return true;
//             color[v] = 0;
//         }
//     }
//     return false;
// }
// bool graphColoring(bool graph[V][V], int m)
// {
//     int color[V];
//     for (int i = 0; i < V; i++)
//     color[i] = 0;
//     if (graphColoringUtil(graph, m, color, 0) == false) {
//         cout<< "Solution does nnot exist";
//         return false;
//     }
//     printSolution(color);
//     return true;
// }
// void printSolution(int color[])
// {
//     cout << "Solution Exists:" << " Following are the assigned colors" <<"\n";
//     for (int i = 0; i < V; i++)
//     cout<< "  " << color[i] << " ";
//     cout << "\n";
// }
// int main()
// {
//     bool graph[V][V] = {{0, 1, 1, 1},
//                         {1, 0, 1, 0},
//                         {1, 1, 0, 1},
//                         {1, 0, 1, 0}};
//     int m = 3;
//     graphColoring(graph, m);
//     return 0;
// }
// ****************************************************Knight Tour**********************************************************
// # define N 8
// int solveKnighttourUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);
// int isSafe(int x, int y, int sol[N][N])
// {
//     return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
// }
// void printSolution(int sol[N][N])
// {
//     for (int x = 0; x < N; x++)
//     {
//         for (int y = 0; y < N; y++)
//         cout<<" " << setw(2) << sol[x][y] << " ";
//         cout<<endl;
//     }
// }
// int solveKnightour()
// {
//     int sol[N][N];
//     for (int x = 0; x < N; x++)
//     for (int y = 0; y < N; y++)
//     sol[x][y] = -1;
//     int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2 };
//     int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1 };
//     sol[0][0] = 0;
//     if (solveKnighttourUtil(0, 0, 1, sol, xMove, yMove) == 0) {
//         cout<< " Solution does not exist";
//         return 0;
//     }
//     else
//     printSolution(sol);
//     return 1;
// }
// int solveKnighttourUtil(int x, int y, int movei, int sol[N][N], int xMove[8], int yMove[8])
// {
//     int k, next_x, next_y;
//     if(movei == N * N)
//     return 1;
//     for (k = 0; k < 8; k++) {
//         next_x = x + xMove[k];
//         next_y = y + yMove[k];
//         if (isSafe(next_x, next_y, sol)) {
//             sol[next_x][next_y] = movei;
//             if (solveKnighttourUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
//             return 1;
//             else
//             sol[next_x][next_y] = -1;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     solveKnightour();
//     return 0;
// }
// ******************************************************Sudoku***********************************************************
// #define N 9
// void print(int arr[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         cout<< arr[i][j] << " ";
//         cout<<endl;
//     }
// }
// bool isSafe(int grid[N][N], int row, int col, int num)
// {
//     for (int x = 0; x <= 8; x++)
//     if (grid[row][x] == num)
//     return false;
//     for (int x = 0; x <= 8; x++)
//     if (grid[x][col] == num)
//     return false;

//     int startRow = row - row % 3, startCol = col - col % 3;

//     for (int i = 0; i < 3; i++)
//     for (int j = 0; j < 3; j++)
//     if (grid[i + startRow][j + startCol] == num)
//     return false;
//     return true;
// }
// bool solveSudoku(int grid[N][N], int row, int col)
// {
//     if (row == N - 1 && col == N)
//     return true;

//     if (col == N){
//         row++;
//         col = 0;
//     }
//     if(grid[row][col] > 0)
//     return solveSudoku(grid, row, col + 1);
//     for (int num = 1; num <= N; num++)
//     {
//         if (isSafe(grid, row, col, num))
//         {
//             grid[row][col] = num;
//             if (solveSudoku(grid, row, col + 1))
//             return true;
//         }
//         grid[row][col] = 0;
//     }
//     return false;
// }
// int main()
// {
//     int grid[N][N] = {{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
//                       { 5, 2, 0, 0, 0, 0, 0, 0 ,0 },
//                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
//                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
//                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
//                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
//                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
//                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
//                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};
// if (solveSudoku(grid, 0, 0))
// print (grid);
// else
// cout<<" No solution exists " <<endl;
// return 0;
// }
// *****************************************Remove invalid Parathesis**********************************************
// bool isParenthesis(char c)
// {
//     return ((c == '(') || (c == ')'));
// }
// bool isValidString(string str)
// {
//     int cnt = 0;
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (str[i] == '(')
//         cnt++;
//         else if (str[i] == ')')
//         cnt--;
//         if (cnt < 0)
//         return false;
//     }
//     return (cnt == 0);
// }
// void removeInvalidParenthesis(string str)
// {
//     if (str.empty())
//     return ;

//     unordered_set<string> visit;
//     queue<string> q;
//     string temp;
//     bool level;

//     q.push(str);
//     visit.insert(str);
//     while ( !q.empty())
//     {
//         str = q.front();  q.pop();
//         if (isValidString(str))
//         {
//             cout <<str <<endl;
//             level = true;
//         }
//         if (level)
//         continue;
//         for (int i = 0; i < str.length(); i++)
//         {
//             if ( !isParenthesis(str[i]))
//             continue;

//             temp = str.substr(0, i) + str.substr(i + 1);
//             if (visit.find(temp) == visit.end())
//             {
//                 q.push(temp);
//                 visit.insert(temp);
//             }
//         }
//     }
// }
// int main()
// {
//     string expression = " ()())()";
//     removeInvalidParenthesis(expression);

//     expression = "()v)";
//     removeInvalidParenthesis(expression);
//     return 0;
// }
// ***************************************************Word Breaking in sentence***********************************************
// int dictionaryContains(string &word)
// {
//     string dictionary[] ={"i","want","the","you","that","need","you","because"};
//     int n = sizeof(dictionary)/sizeof(dictionary[0]);
//     for (int i = 0; i < n; i++)
//     if (dictionary[i].compare(word) == 0)
//     return true;
//     return false;
// }
// void wordBreakUtil(string str, int size, string result);
// void wordBreak(string str)
// {
//     wordBreakUtil(str, str.size(), "");
// }
// void wordBreakUtil(string str, int n, string result)
// {
//     for (int i =1; i<=n; i++)
//     {
//         string prefix = str.substr(0, i);
//         if (dictionaryContains(prefix))
//         {
//             if (i == n)
//             {
//                 result += prefix;
//                 cout<<result <<endl;
//                 return;
//             }
//             wordBreakUtil(str.substr(i, n-i), n-i, result + prefix + " ");
//         }
//     }
// }
// int main()
// {
//     cout<<" First test:\n";
//     wordBreak("iwantyoubecauseineedyou");

//     cout<<"\nSecond Test:\n";
//     wordBreak("iwantthatbecauseineed");
//     return 0;
// }
// **********************************All Palindromic Partitions of a string using bit manipulation******************************
// class Mainhoon {
//     public:
//     vector<vector<string> > ans;
//     bool checkPalindrome(vector<string> currPartition)
//     {
//         for (auto s : currPartition) {
//             int n = s.size();
//             int i = 0, j = n -1;
//             while (i < j) {
//                 if (s[i] != s[j])
//                 return false;
//                 i++;
//                 j--;
//             }
//         }
//         return true;
//     }
//     void generatePartition(string& s, string& bitString)
//     {
//         vector<string> currPartition;
//         string substring;
//         substring.push_back(s[0]);
//         for (int i = 0; i < bitString.size(); i++){
//             if (bitString[i] == '0') {
//                 substring.push_back(s[i + 1]);
//             }
//             else {
//                 currPartition.push_back(substring);
//                 substring.clear();
//                 substring.push_back(s[i + 1]);
//             }
//         }
//         currPartition.push_back(substring);
//         if (checkPalindrome(currPartition)) {
//             ans.push_back(currPartition);
//         }
//     }
//     void bitManipulation(string& s, string& bitString)
//     {
//         if (bitString.size() == s.size() -1) {
//             generatePartition(s, bitString);
//             return;
//         }
//         bitString.push_back('1');
//         bitManipulation(s, bitString);
//         bitString.pop_back();
//         bitString.push_back('0');
//         bitManipulation(s, bitString);
//         bitString.pop_back();
//     }
//     vector<vector<string> > Partition(string s)
//     {
//         string bitString;
//         bitManipulation(s, bitString);
//         return ans;
//     }
// };
// int main ()
// {
//     Mainhoon ob;
//     vector<vector<string> > ans;
//     string s = "hoon";
//     ans = ob.Partition(s);
//     for (auto& v : ans) {
//         for (auto& it : v) {
//             cout<< it <<" ";
//         }
//         cout<< "\n";
//     }
//     return 0;
// }
// *************************************Find shortest safe route in a path with Landmines********************************************
// #define R 12
// #define C 10
// struct Key{
//     int x, y;
//     Key(int i, int j){ x =i; y=j;};
// };
// int rowNum[] = { -1, 0, 0, 1};
// int colNum[] = { 0, -1, 1, 0};
// bool isValid(int x, int y)
// {
//     if (x < R && y < C && x >= 0 && y >= 0)
//     return true;
//     return false;
// }
// void findShortestPath(int mat[R][C]) {
//     int i, j;
//     for (i = 0; i < R; i++)
//     {
//         for (j = 0; j < C; j++)
//         {
//             if (mat[i][j] == 0)
//             {
//                 for (int k = 0; k < 4; k++)
//                 if (isValid(i + rowNum[k], j + colNum[k]))
//                 mat[i + rowNum[k]][j + colNum[k]] = -1;
//             }
//         }
//     }
//     for (i = 0; i < R; i++)
//     {
//         for (j = 0; j < C; j++)
//         {
//             if (mat[i][j] == -1)
//             mat[i][j] = 0;
//         }
//     }
//     int  dist[R][C];
//     for(i=0; i< R; i++){
//         for(j=0; j<C; j++)
//         dist[i][j] = -1;
//     }
//     queue<Key> q;
//     for(i=0; i<R; i++)
//     {
//         if(mat[i][0] == 1){
//             q.push(Key(i,0));
//             dist[i][0] = 0;
//         }
//     }
//     while(!q.empty()) {
//         Key k = q.front();
//         q.pop();
//         int d = dist[k.x][k.y];
//         int x = k.x;
//         int y = k.y;
//         for (int k = 0; k < 4; k++) {
//             int xp = x + rowNum[k];
//             int yp = y + colNum[k];
//             if(isValid(xp,yp) && dist[xp][yp] == -1 && mat[xp][yp] == 1){
//                 dist[xp][yp] = d+1;
//                 q.push(Key(xp,yp));
//             }
//         }
//     }
//     int ans = INT_MAX;
//     for(i = 0; i< R; i++){
//         if(mat[i][C-1] == 1 && dist[i][C-1] != -1) {
//             ans = min(ans,dist[i][C-1]);
//         }
//     }
//     if(ans == INT_MAX)
//     cout<< "Not possible\n";
//     else
//     cout<<"Length of shortest safe route is " <<ans <<endl;
// }
// int main()
// {
//     int mat[R][C] =
//     {{1,1,1,1,1,1,1,1,1,1},
//      {1,0,1,1,1,1,1,1,1,1},
//      {1,1,1,0,1,1,1,1,1,1},
//      {1,1,1,1,0,1,1,1,1,1},
//      {1,1,1,1,1,1,1,1,1,1},
//      {1,1,1,1,1,1,0,1,1,1},
//      {1,0,1,1,1,1,1,1,0,1},
//      {1,1,1,1,1,1,1,1,1,1},
//      {1,1,1,1,1,1,1,1,1,1},
//      {0,1,1,1,1,0,1,1,1,1},
//      {1,1,1,1,1,1,1,1,1,1},
//      {1,1,1,0,1,1,1,1,1,1}
//     };
//     findShortestPath(mat);
// }
// ****************************************Partition of a set into K subsets with equal sum******************************************
// bool isKPartitionPossibleRec(int arr[], int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx)
// {
//     if (subsetSum[curIdx] == subset)
//     {
//         if (curIdx == K - 2)
//             return true;
//         return isKPartitionPossibleRec(arr, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
//     }
//     for (int i = limitIdx; i >= 0; i++)
//     {
//         if (taken[i])
//             continue;
//         int tmp = subsetSum[curIdx] + arr[i];
//         if (tmp <= subset)
//         {
//             taken[i] = true;
//             subsetSum[curIdx] += arr[i];
//             bool nxt = isKPartitionPossibleRec(arr, subsetSum, taken, subset, K, N, curIdx, i - 1);
//             taken[i] = false;
//             subsetSum[curIdx] -= arr[i];
//             if (nxt)
//             return true;
//         }
//     }
//     return false;
// }
// bool isKPartitionPossible(int arr[], int N, int K)
// {
//     if (K == 1)
//         return true;

//     if (N < K)
//         return false;

//     int sum = 0;
//     for (int i = 0; i < N; i++)
//         sum += arr[i];
//     if (sum % K != 0)
//         return false;
//     int subset = sum / K;

//     int subsetSum[K];
//     bool taken[N];
//     for (int i = 0; i < K; i++)
//         subsetSum[i] = 0;
//     for (int i = 0; i < N; i++)
//         taken[i] = false;
//     subsetSum[0] = arr[N - 1];
//     taken[N - 1] = true;
//     return isKPartitionPossibleRec(arr, subsetSum, taken, subset, K, N, 0, N - 1);
// }
// int main()
// {
//     int arr[] = {2, 1, 4, 5, 3, 3};
//     int N = sizeof(arr) / sizeof(arr[0]);
//     int K = 3;
//     if (isKPartitionPossible(arr, N, K))
//         cout << "Partition into equal sum is possible.\n";
//     else
//         cout << "Partition into equal sum is not possible.\n";
// }
// **********************************************Hamiltonian Cycle***************************************************
// #define V 5
// void printSolution(int path[]);
// bool isSafe(int v, bool graph[V][V], int path[], int pos)
// {
//     if (graph [path[pos - 1]] [ v ] == 0)
//     return false;
//     for (int i = 0; i < pos; i++)
//     if (path[i] == v)
//     return false;
//     return true;
// }
// bool hamCycleUtil(bool graph[V][V], int path[], int pos)
// {
//     if (pos == V)
//     {
//         if (graph[path[pos - 1]][path[0]] == 1)
//         return true;
//         else
//         return false;
//     }
//     for (int v = 1; v < V; v++)
//     {
//         if (isSafe(v, graph, path, pos))
//         {
//             path[pos] = v;
//             if (hamCycleUtil (graph, path, pos + 1) == true)
//             return true;
//             path[pos] = -1;
//         }
//     }
//     return false;
// }
// bool hamCycle(bool graph[V][V])
// {
//     int *path = new int[V];
//     for (int i = 0; i < V; i++)
//     path[i] = -1;
//     path[0] = 0;
//     if (hamCycleUtil(graph, path, 1) == false )
//     {
//         cout<<"\nSolution does not exist";
//         return false;
//     }
//     printSolution(path);
//     return true;
// }
// void printSolution(int path[])
// {
//     cout<<"solution Exists:" <<"Following is one Hamiltonian Cycle \n";
//     for (int i = 0; i < V; i++)
//     cout<<path[i] << " ";
//     cout<<path[0] << " ";
//     cout<<endl;
// }
// int main()
// {
//     bool graph1[V][V] ={{0, 1, 0, 1, 0},
//                         {1, 0, 1, 1, 1},
//                         {0, 1, 0, 0, 1},
//                         {1, 1, 0, 0, 1},
//                         {0, 1, 1, 1, 0}
//     };
//     hamCycle(graph1);
//     bool graph2[V][V] = {{0, 1, 0, 1, 0},
//                          {1, 0, 1, 1, 1},
//                          {0, 1, 0, 0, 1},
//                          {1, 1, 0, 0, 0},
//                          {0, 1, 1, 0, 0}
//     };
//     hamCycle(graph2);
//     return 0;
// }
// *******************************************************Tug-of-War************************************************************
// void TOWUtil(int* arr, int n, bool* curr_elements, int no_of_selected_elements, bool* soln, int* min_diff, int sum, int curr_sum, int curr_position)
// {
//     if (curr_position == n)
//     return;
//     if ((n/2 - no_of_selected_elements) > (n - curr_position))
//     return;
//     TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln, min_diff, sum, curr_sum, curr_position+1);
//     no_of_selected_elements++;
//     curr_sum = curr_sum + arr[curr_position];
//     curr_elements[curr_position] = true;
//     if (no_of_selected_elements == n/2)
//     {
//         if (abs(sum/2 - curr_sum) < *min_diff)
//         {
//             *min_diff = abs(sum/2 - curr_sum);
//             for (int i = 0; i<n; i++)
//             soln[i] = curr_elements[i];
//         }
//     }
//     else
//     {
//     TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln, min_diff, sum, curr_sum, curr_position+1);
//     }
//     curr_elements[curr_position] = false;
// }
// void tugofWar(int *arr, int n)
// {
//     bool* curr_elements = new bool[n];
//     bool* soln = new bool[n];
//     int min_diff = INT_MAX;
//     int sum = 0;
//     for (int i =0; i<n; i++)
//     {
//         sum += arr[i];
//         curr_elements[i] = soln[i] = false;
//     }
//     TOWUtil(arr, n, curr_elements, 0, soln, &min_diff, sum, 0, 0);
//     cout<<"The first subset is: ";
//     for (int i =0; i<n; i++)
//     {
//         if (soln[i] == true)
//         cout<<arr[i] << " ";
//     }
//     cout << "\nThe second subset is: ";
//     for (int i =0; i<n; i++)
//     {
//         if (soln[i] == false)
//         cout<<arr[i] <<" ";
//     }
// }
// int main()
// {
//     int arr[] = {23,45,-34, 12, 0, 98, -99, 4, 189, -1, 4};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     tugofWar(arr, n);
//     return 0;    
// }
// ***************************************************Maximum possible number by doing at most k swaps****************************************
// void findMaximumNum(string str, int k, string& max)
// {
//     if (k == 0)
//     return;
//     int n = str.length();
//     for(int i =0; i<n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (str[i] < str[j]) {
//                 swap(str[i], str [j]);
//                 if (str.compare(max) > 0)
//                 max = str;
//                 findMaximumNum(str, k - 1, max);
//                 swap(str[i], str[j]);
//             }
//         }
//     }
// }
// int main()
// {
//     string str = "129814999";
//     int k = 4;
//     string max = str;
//     findMaximumNum(str, k, max);
//     cout<<max<<endl;
//     return 0;
// }
// ***************************************************find paths from corner cell to middle cell in maze**************************************
// #define N 9
// bool isValid(set<pair<int, int> > visited, pair<int, int> pt)
// {
//     return (pt.first >= 0) && (pt.first < N) && (pt.second >= 0) && (pt.second < N) && (visited.find(pt) == visited.end());
// }
// void printPath(list<pair<int, int> > path)
// {
//     for (auto it = path.begin(); it != path.end(); it++)
//     cout<< "(" << it->first << ","<< it ->second << ") -> ";
//     cout<<"MID" <<endl <<endl;
// }
// int row[] = {-1, 1, 0, 0};
// int col[] = {0, 0, -1, 1};
// int _row[] = {0, 0, N-1, N-1};
// int _col[] = {0, N-1, 0, N-1};
// void findPathInMazeUtil(int maze[N][N],list<pair<int, int> > &path, set<pair<int, int> > &visited, pair<int, int> &curr)
// {
//     if (curr.first == N / 2 && curr.second == N / 2)
//     {
//         printPath(path);
//         return;
//     }
//     for (int i = 0; i < 4; ++i)
//     {
//         int n = maze[curr.first][curr.second];
//         int x = curr.first + row[i]*n;
//         int y = curr.second + col[i]*n;
//         pair<int, int> next = make_pair(x, y);
//         if (isValid(visited, next))
//         {
//             visited.insert(next);
//             path.push_back(next);
//             findPathInMazeUtil(maze, path, visited, next);
//             path.pop_back();
//             visited.erase(next);
//         }
//     }
// }
// void findPathInMaze(int maze[N][N])
// {
//     list<pair<int, int> >path;
//     set<pair<int, int> > visited;
//     for(int i = 0; i < 4; ++i)
//     {
//         int x = _row[i];
//         int y = _col[i];
//         pair<int, int> pt = make_pair(x, y);
//         visited.insert(pt);
//         path.push_back(pt);
//         findPathInMazeUtil(maze, path, visited, pt);
//         path.pop_back();
//         visited.erase(pt);
//     }
// }
// int main()
// {
//     int maze[N][N] = 
//     {
//     { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
//     { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
//     { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
//     { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
//     { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
//     { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
//     { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
//     { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
//     { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
//  };
//     findPathInMaze(maze);
//     return 0;
//  }
// *******************************************************Arithmetic Expression***********************************************************
// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> split(const string &);
// int main ()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));
//     string n_temp;
//     getline(cin, n_temp);
//     int n = stoi(ltrim(rtrim(n_temp)));
//     string arr_temp_temp;
//     getline(cin, arr_temp_temp);
//     vector<string> arr_temp = split(rtrim (arr_temp_temp));
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         int arr_item = stoi(arr_temp[i]);
//         arr[i] = arr_item;
//     }
//     string result = arithmeticExpressions(arr);
//     fout << result << "/n";
//     fout.close();
//     return 0;
// }
// string ltrim(const string &str) {
//     string s(str);
//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );
//     return s;
// }
// string rtrim(const string &str) {
//     string s(str);
//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),s.end()
//     );
//     return s;
// }
// vector<string> split(const string &str) {
//     vector<string> tokens;
//     string::size_type start = 0;
//     string::size_type end = 0;
//     while ((end = str.find(" ", start)) != string::npos)
//     {
//         tokens.push_back(str.substr(start, end - start));
//         start = end + 1;
//     }
//     tokens.push_back(str.substr(start));
//     return tokens;
// }
//write a program in python that uses Matplotlib to create a figure containing two subplot- one representing the number of visitor to a website each month and the other representing the bounce rate over the same period ?