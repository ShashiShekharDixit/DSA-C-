#include<iostream>
using namespace std;
int main()
{
     int myarray[10] = {12,34,4,32,54,35,23,20,60,40};
     cout<<"\nInput list is \n";
     for(int i=0; i<10; i++)
     {
        cout<<myarray[i]<<"\t";
     }
     for(int k=1; k<10; k++)
     {
        int temp = myarray[k];
        int j= k-1;
        while(j>=0 && temp <= myarray[j])
        {
            myarray[j+1] = temp;
        }
     }   
        cout<<"\nSorted list is \n";
        for(int i=0;i<10;i++)
        {
            cout<<myarray[i]<<"\t";
        }   
}
