#include<iostream>
using namespace std;
int main()
{ 
     int a,b;
     cout << "Enter the First number : ";
     cin>>a;
     cout << "Enter the Second number : ";
     cin>>b;
     cout << "\n\nValue Before Swapping: \n"<<endl;
     cout << "First Number = "<< a <<endl;
     cout << "Second Number = "<< b <<endl;
     a = a + b;
     b = a - b;
     a = a - b;
     cout << "\n\nValue After Swapping: \n"<<endl;
     cout << "First Number = " << a <<endl;
     cout << "Second Number = " << b <<endl;
     cout << "\n\n\n";
     return 0; 
}