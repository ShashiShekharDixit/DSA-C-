#include<iostream>
using namespace std;
int main()
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;      //1234
     while(i<=n)      //1234
     {                //1234
         int j = 1;   //1234
         while(j<=n)
         {
         cout<<j;
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;       //****
     while(i<=n)       //****
     {                 //****
         int j = 1;    //****
         while(j<=n)
         {
         cout<<"*";
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;        //1111
     while(i<=n)        //2222
     {                  //3333
         int j = 1;     //4444
         while(j<=n)
         {
         cout<<i;
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;          //4321
     while(i<=n)          //4321
     {                    //4321
         int j = 1;       //4321
         while(j<=n)
         {
         cout<<n-j+1;
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;            //1 2 3 4
     int count = 1;         //5 6 7 8
     while(i<=n)            //9 10 11 12
     {                      //13 14 15 16
         int j = 1;
         while(j<=n)
         {
         cout<<count<<" ";
         count = count + 1;
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //*
     while(row<=n)            //**
     {                        //***
         int col = 1;         //****
         while(col<=row)
         {
         cout<<"*";
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;             //4
     while(row<=n)             //45
     {                         //456
         int col = 1;          //4567
         while(col<=row)
         {
         cout<<n+col-1;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;          //4
     while(row<=n)          //43
     {                      //432
         int col = 1;       //4321
         while(col<=row)
         {
         cout<<n-col+1;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //1
     while(row<=n)            //22
     {                        //333
         int col = 1;         //4444
         while(col<=row)
         {
         cout<<row;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;            //1 
     int count = 1;         //2 3
     while(i<=n)            //4 5 6 
     {                      //7 8 9 10
         int j = 1;
         while(j<=i)
         {
         cout<<count<<" ";
         count = count + 1;
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //1
     while(row<=n)            //23
     {                        //345
         int col = 1;         //4567
         int value = row;         
         while(col<=row)
         {
         cout<<value;
         value = value + 1;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;          //1
     while(row<=n)          //21
     {                      //321
         int col = 1;       //4321
         while(col<=row)
         {
         cout<<row-col+1;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;          //AAAA
     while(i<=n)          //BBBB
     {                    //CCCC
         int j = 1;       //DDDD
         while(j<=n)
         {
         char ch = 'A'+i-1;
         cout<< ch;
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;      //ABCD
     while(i<=n)      //ABCD
     {                //ABCD
         int j = 1;   //ABCD
         while(j<=n)
         {
         char ch = 'A'+j-1;
         cout<< ch <<" ";
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;      //ABCD
     while(i<=n)      //BCDE
     {                //CDEF
         int j = 1;   //DEFG
         while(j<=n)
         {
         char ch = 'A'+i+j-2;
         cout<< ch <<" ";
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //A
     while(row<=n)            //BB
     {                        //CCC
         int col = 1;         //DDDD
         while(col<=row)
         {
         char ch = 'A'+row-1;
         cout<<ch;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n";
     cin>>n;

     int i = 1 ;            //A 
     char value = 'A';      //B C
     while(i<=n)            //D E F 
     {                      //G H I J
         int j = 1;
         while(j<=i)
         {
         cout<<value<<" ";
         value = value + 1;
         j = j + 1;
         }
         cout<<endl;
         i = i + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //A
     while(row<=n)            //BC
     {                        //CDE
         int col = 1;         //DEFG
         while(col<=row)
         {
         char ch = 'A'+row+col-2;
         cout<<ch;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //D
     while(row<=n)            //CD
     {                        //BCD
         int col = 1;         //ABCD
         char value = 'A'+n-row;        
         while(col<=row)
         {
         cout<<value;
         value = value + 1;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //   *
     while(row<=n)            //  **
     {                        // ***
        int space = n-row;    //****
        while(space)
        {
            cout<<" ";
            space = space-1;
        }                 
         int col = 1;         
         while(col<=row)
         {
         cout<<'*';
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //   1
     while(row<=n)            //  121
     {                        // 12321
        int space = n-row;    //1234321
        while(space)
        {
            cout<<" ";
            space = space-1;
        }                 
         int col = 1;         
         while(col<=row)
         {
         cout<<col;
         col = col + 1;
         }
         int start = row - 1;
         while(start)
         {
            cout<<start;
            start = start - 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;            //   *
     while(row<=n)            //  ***
     {                        // *****
        int space = n-row;    //*******
        while(space)
        {
            cout<<" ";
            space = space-1;
        }                 
         int col = 1;         
         while(col<=row)
         {
         cout<<'*';
         col = col + 1;
         }
         int start = row - 1;
         while(start)
         {
            cout<<'*';
            start = start - 1;
         }
         cout<<endl;
         row = row + 1;
     }
}
{
     int n;
     cout<<"Enter the value of n =";
     cin>>n;

     int row = 1 ;
     int count = 1;         //      1
                            //     2 3
                            //    4 5 6
                            //   7 8 9 10
        while(row<=n)             
     {                         
        int space = n-row;     
        while(space)
        {
            cout<<" ";
            space = space-1;
        }                 
         int col = 1;         
         while(col<=row)
         {
         cout<<count<<" ";
         count = count + 1;
         col = col + 1;
         }
         cout<<endl;
         row = row + 1;
     }
}