#include<bits/stdc++.h>
#include<stack>
using namespace std;
// class Stack {
//     public:
//     int top;
//     int size;
//     int *arr;
    
//     Stack(int size) {
//         this -> size = size;
//         arr = new int [size];
//         top = -1;
//     }
//     void push(int element){
//         if (size - top > 1) {
//             top++;
//             arr[top] = element;
//     }
//     else {
//        cout<<"Stack overflow " <<endl;
//     }
//    }
//     void pop() {
//         if(top >= 0){
//             top--;
//         }
//         else {
//             cout <<"Stack Underflow" <<endl;
//         }
//     }
//     int peek () {
//         if(top >= 0){
//             return arr[top];
//         }
//         else {
//             cout <<" Stack is Empty " <<endl;
//             return -1;
//         }
//     }
//     bool isEmpty() {
//         if (top == -1 ){
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
// };
// int main()
// {
//     Stack st(5);
//     st.push(34);
//     st.push(45);
//     st.push(87);
//     st.push(33);
//     st.push(65);
//     cout <<st.peek() <<endl;
//     st.pop();
//     cout <<st.peek() <<endl;
//     st.pop();
//     cout <<st.peek() <<endl;
//     st.pop();
//     cout <<st.peek() <<endl;
//     st.pop();
//     cout <<st.peek() <<endl;
//     st.pop();
//     cout <<st.peek() <<endl;
//     if(st.isEmpty()) {
//         cout <<"Stack is empty hai" <<endl;
//     }
//     else{
//         cout <<"Stack is nhi empty" <<endl;
//     }
//     // stack<int> s;
//     // s.push(2);
//     // s.push(3);
//     // s.pop();
//     // cout <<" Printing the element: " <<s.top()<<endl;
//     // if(s.empty()){
//     //     cout<<"Stack is empty"<<endl;
//     // }
//     // else{
//     //     cout <<"Stack is Not empty "<<endl;
//     // }    
//     // cout <<" size of stack is : " <<s.size() <<endl;
//     return 0;
// }
// ***********************************************************Reverse the Stack*******************************
// int main() {
//     string str = "kuch bhi";
//     stack<char> s;
//     for(int i =0; i < str.length(); i++) {
//         char ch = str[i];
//         s.push(ch);
//     }
//     string ans = "";
//     while (!s.empty()) 
//     {
//         char ch = s.top();
//         ans.push_back(ch);
//         s.pop();
//     }
//     cout <<" Answer is : " <<ans <<endl;
//     return 0;
// }
// ******** Questions on gfg
// 2 stack in linked list
// 2 stack in array
// delete middle element in stack
// valid parenthedsis
// Insert an Element at the Bottom of a Stack
// reverse stack using recursion
// sort a stack
// Minimum cost to make valid string 