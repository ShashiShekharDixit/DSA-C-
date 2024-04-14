#include<iostream>
// #include<array>
// #include<vector>
// #include<deque>
// #include<list>
// #include<stack>
// #include<queue>
// #include<set>
// #include<map>
// #include<algorithm>
using namespace std;
// int main()
// {
//     int basic[3] = {1,2,3};
//     array<int,4> a={1,2,3,4};
//     int size = a.size();
//     for(int i=0;i<size;i++){
//     std::cout<<a[i]<<endl;
//     }
//     std::cout<<"Element at 2nd Index: "<<a.at(2)<<endl;
//     std::cout<<"Empty or not: "<<a.empty()<<endl;
//     std::cout<<"First Element: "<<a.front()<<endl;
//     std::cout<<"Last Element: "<<a.back()<<endl;
// }
// *************************************************************vector**************************************************************
// int main()
// {
//     vector<int> v;
//     vector<int> a(5,1);
//     vector<int> last(a);
//     cout<<"print last"<<endl;
//     for(int i:last){
//         cout<<i<<" ";
//     }cout<<endl;

//     std::cout<<"Capacity: "<<v.capacity()<<endl;
//     v.push_back(1);
//     std::cout<<"Capacity: "<<v.capacity()<<endl;
//     v.push_back(2);
//     std::cout<<"Capacity: "<<v.capacity()<<endl;
//     v.push_back(3);
//     std::cout<<"Capacity: "<<v.capacity()<<endl;
//     std::cout<<"Size: "<<v.size()<<endl;
//     std::cout<<"Element at 2nd Index" <<v.at(2)<<endl;
//     std::cout<<"front "<<v.front()<<endl;
//     std::cout<<"back "<<v.back()<<endl;
//     std::cout<<"before pop"<<endl;
//     for(int i:v) {
//         std::cout<<i<<" ";
//     }std::cout<<endl;

//     v.pop_back();
//     std::cout<<"after pop"<<endl;
//     for(int i:v){
//         std::cout<<i<<" ";
//     }
//        cout<<"before clear size "<<v.size()<<endl;
//        v.clear();
//        cout<<"after clear size "<<v.size()<<endl;
//        v.clear();
// }
// ***************************************************Deque*************************************************************************
// int main()
// {
//     deque<int> d;
//     d.push_back(1);
//     d.push_front(2);
    // for(int i: d) {
    //     cout<<i<<" ";
    // }
    // d.pop_front();
    // std::cout<<endl;
    // for(int i: d) {
    //     cout<<i<<" ";
    // }
//     std::cout<<"Print First Index Element: "<<d.at(1)<<endl;
//     std::cout<<"Front "<<d.front()<<endl;
//     std::cout<<"Back "<<d.back()<<endl;
//     std::cout<<"Empty or not"<<d.empty()<<endl;
//     std::cout<<"before erase" <<d.size()<<endl;
//     d.erase(d.begin(),d.begin()+1);
//     std::cout<<"after erase"<<d.size()<<endl;
//     for(int i:d){
//         std::cout<<i<<endl;
//     }
// }
// ************************************************************list******************************************************************
// int main()
// {
//     list<int> l;
//     list<int> n(5,100);
//     cout<<"Printing n"<<endl;
//     for(int i:n) {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     l.push_back(1);
//     l.push_front(2);
//     for(int i:l)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     l.erase(l.begin());
//     cout<<"after erase"<<endl;
//     for(int i: l) {
//         cout<<i<<" ";
//     }
//     cout<<"size of list"<<l.size()<<endl;
// }
// *****************************************************************Stack**************************************************************
// int main()
// {
//        stack<string> s;
//        s.push("Shashi");
//        s.push("Shekhar");
//        s.push("Dixit JI");
//        cout<<"Top Element: "<<s.top()<<endl;
//        s.pop();
//        cout<<"Top Element: "<<s.top()<<endl;
//        cout<<"Size of stack"<<s.size()<<endl;
//        cout<<"Empty or not "<<s.empty()<<endl;
// }
// *********************************************************************queue***********************************************************
// int main()
// { 
//     queue<string> q;
//     q.push("Shashi");
//     q.push("Shekhar");
//     q.push("DIXIT");
//     cout<<"Size before pop "<<q.size()<<endl;
//     cout<<"First Element "<<q.front()<<endl;
//     q.pop();
//     cout<<"First Element "<<q.front()<<endl;
//     cout<<"Size after pop "<<q.size()<<endl;
    
// }
// **************************************************************************priority queue***********************************************
// int main()
// {
//     // max heap
//     priority_queue<int> maxi;
//     //min heap
//     priority_queue<int,vector<int>, greater<int> > mini;
//     maxi.push(1);
//     maxi.push(2);
//     maxi.push(3);
//     maxi.push(4);
//     cout<<"size: "<<maxi.size()<<endl;
//     int n = maxi.size();
//     for(int i=0;i<n;i++) {
//         cout<<maxi.top()<<" ";
//         maxi.pop();
//     }cout<<endl;
    
//     mini.push(5);
//     mini.push(4);
//     mini.push(6);
//     mini.push(3);
//     mini.push(2);
    
//     int m= mini.size();
//     for(int i=0;i<m;i++){
//         cout<<mini.top()<<" ";
//         mini.pop();
//     }cout<<endl;
// }
// *************************************************************************set*********************************************************
// int main()
// {
//    set<int> s;
//    s.insert(5);
//    s.insert(4);
//    s.insert(5);
//    s.insert(3);
//    s.insert(8);
//    for(auto i : s){
//     cout<<i<<endl;
//    }cout<<endl;
//    set<int>::iterator it = s.begin();
//    it++;
//    s.erase(it);
//    s.erase(s.begin());
//    for(auto i : s){
//     cout<<i<<endl;
//    }
//    cout<<endl;
//    cout<<"5 is present or not: "<<s.count(5)<<endl;
//    set<int>::iterator itr = s.find(5);
//    for(auto it=itr;it!=s.end();it++) {
//     cout<<*it<<" ";
//    }cout<<endl;
// }
// *****************************************************************Map******************************************************************
// int main()
// {
//     map<int,string> m;
//     m[1]="shashi";
//     m[21]="shekhar";
//     m[3]="dixit";
//     m.insert( {5,"saurabh"});

//     cout<<"before erase"<<endl;
//     for(auto i:m) {
//         cout<<i.first<<" "<<i.second<<endl;
//     }
//     cout<<"finding 3 : "<<m.count(3)<<endl;
//     m.erase(3);
//     cout<<"after erase"<<endl;
//     for(auto i:m) {
//         cout<<i.first<<" "<<i.second<<endl;
//     }
//     auto it = m.find(5);
//     for(auto i=it;i!=m.end();i++) {
//         cout<<(*i).first<<endl;
//     }
// }
// ***********************************************************************Alogirithm*******************************************************
// int main()
// {
//       vector<int> v;
//       v.push_back(1);
//       v.push_back(2);
//       v.push_back(4);
//       v.push_back(5);
// cout<<"Finding 5: "<<binary_search(v.begin(),v.end(),5)<<endl;
// cout<<"Lower bound: "<<lower_bound(v.begin(),v.end(),5)-v.begin()<<endl;
// cout<<"Upper bound: "<<upper_bound(v.begin(),v.end(),5)-v.begin()<<endl;

// int a = 3;
// int b = 5;
// cout<<"max: "<<max(a,b)<<endl;
// cout<<"min: "<<min(a,b)<<endl;
// swap(a,b);
// cout<<"a: "<<a<<endl;
// string abcd = "abcd";
// reverse(abcd.begin(),abcd.end());
// cout<<"string: "<<abcd<<endl;
// rotate(v.begin(),v.begin()+1,v.end());
// cout<<"after rotate"<<endl;
// for(int i:v){
//     cout<<i<<" ";
// }
// }