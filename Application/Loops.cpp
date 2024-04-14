#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    cout<<"printing count from 1 to n" <<endl;
    int i=1;
    for(; ;){
        if(i<=n){
            cout<< i << endl;
        }
        else{
            break;
        }
       i++;
    }
}
**********************************************OR***************************************
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    cout<<"printing count from 1 to n" <<endl;
    for(int i=1;i<=n;i++)
    {
        cout<< i << endl;
    }
           
}
******************************************************************************************
{
     int n;
     cout<<"enter the value of n";
     cin>>n;

     int sum =0;
     for(int i=1; i<=n; i++)
     {
        sum=sum +i;
     }
     cout<<sum<<endl;
}
*****************************************************************************************Fibonacci Series/
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int a=0;
    int b=1;
    cout<<a <<" " <<b <<" ";
    for(int i=1; i<=n; i++)
    {
         int sumNumber = a+b;
         cout<<sumNumber<<" ";

         a = b;
         b = sumNumber;
    }
}
*********************************************************************************************Continue Statement/
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"HI" <<endl;
        cout<<"HEY" <<endl;
        continue;

        cout<<"YES ITS ME" <<endl;
    }
}
************************************************************************************************
{
     int prod = 1;
     int sum = 0;

     while(n!=0)
     {
        int digit = n%10;
        prod = prod * digit;
        sum = sum + digit;

        n= n/10;
     }
     int answer = prod - sum;
     return answer;
}
************************************************************************************************
{
    int n;
    cout<<"Enter the value of n =";
    cin>>n;

    int ans = 0;
    int i = 0;
    while(n!=0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;

        n = n>>1;
        i++;
    }
    cout<<" Answer is "<< ans <<endl;
}
*************************************************************************************************
{
    int n;
    cout<<"Enter the value of n =";
    cin>>n;

    int ans = 0;
    int i = 0;
    while(n!=0)
    {
        int digit = n % 10;
        if(digit == 1)
        {
            ans = ans + pow(2,i);
        }

        n = n/10;
        i++;
    }
    cout<< ans <<endl;
}
************************************************************************************************
{
    int n,rev=0,rem;
    cout<<"Enter the value of n";
    cin>>n;
    while(n!=0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }
    cout<<"Reversed Number:"<<rev<<endl;
    return 0;
}
***************************************Switch Statement****************************************
{
    int a , b;
    cout<<" Enter the value of a " <<endl;
    cin>>a;
    cout<<" Enter the value of b " <<endl;
    cin>>b;
    char op;
    cout<<"Enter the operation you want to perform" <<endl;
    cin>>op;

    switch(op)
    {
        case '+' : cout<<(a+b) <<endl;
        break;
        case '-' : cout<<(a-b) <<endl;
        break;
        case '*' : cout<<(a*b) <<endl;
        break;
        case '/' : cout<<(a/b) <<endl;
        break;
        case '%' : cout<<(a%b) <<endl;
        break;
        default: cout<<"Please enter a valid operation "<<endl;
        break;
    }
}
