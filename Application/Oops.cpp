#include<iostream>
using namespace std;
// class Hero {

//     private:
//     int health;

//     public:
//     char level;
//     Hero() {
//         cout << "Constructor called" << endl;
//     }

    // Parameterised Constructor
    // Hero(int health) {
    //     this -> health = health;
    // }

    // Hero(int health, char level) {
    //     this -> level = level;
    //     this -> health = health;
    // }
    
    // Copy constructor by user
    // Hero(Hero& temp) {
        // cout <<"Copy Constructor Called : " <<endl;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }
    // void print() {
        // cout << level << endl;
//         cout << "health" << this->health <<endl;
//         cout << "level" << this->level <<endl;

//     }
//     int gethealth(){
//     return health;
//     }
//     char getlevel(){
//     return level;
//     }
//     void sethealth(int h){
//     health = h;
//     }
//     void setlevel(char ch){
//     level = ch;
//     }
// };
// int main ()
// {
//     Hero S(70, 'c');
//     S.print();

    // Copy Constructor

    // Hero R(S);
    // R.print();





    // Default Constructor
    // Hero Ramesh(10);
    // cout <<" Address of Ramesh is : " <<&Ramesh << endl;
    // Ramesh.print();

    // Dynamically
    // Hero *h = new Hero;
    // h->print();

    // Hero temp(22, 'B');
    // temp.print();
    // Hero  a;
    // a.sethealth(80);
    // a.setlevel('B');
    // cout << " Level is : " <<a.level <<endl;
    // cout << " health is : "<<a.gethealth() <<endl;
    // Hero *b = new Hero;
    // b->sethealth(70);
    // b->setlevel('A');
    // cout << " Level is : " <<(*b).level <<endl;
    // cout << " health is : " <<(*b).gethealth() <<endl;
    // cout << " Health is : " <<b->gethealth() << endl;
    // cout << " Level is : "<<b->level << endl;

    // Hero Ramesh;
    // cout << " Size of : " << sizeof(Ramesh) <<endl;
    // Ramesh.sethealth(10);  
    // Ramesh.setlevel('S');
    // cout << " Ramesh health is :  " <<Ramesh.gethealth()<<endl;
    // cout << " Ramesh level is : " <<Ramesh.getlevel() <<endl;
    // Ramesh.sethealth(70);
    // Ramesh.level = 'A';
    // cout << "Health is : " << Ramesh.gethealth()<<endl;
    // cout << " Level is : " << Ramesh.level<<endl;
    // return 0;
// }
// *****************************************************
// class Circle{
//     public:
//     double radius;
//     double compute_id()
//     {
//         return 3.14 *  radius * radius;
//     }
// };
// int main()
// {
//     Circle obj;
//     obj.radius = 5.5;
//     cout <<" Radius is : "<<obj.radius<<endl;
//     cout <<" Area is : " <<obj.compute_id(); 
//     return 0;
// }
// *******************************************************
// class Parent {
//     protected:
//     int id_protected;
// };
// class child : public Parent{
//     public: 
//     void setId(int id)
//     {
//       id_protected = id;
//     }
//     void display()
//     {
//         cout<<" id_protected is : " <<id_protected <<endl;
//     }
// };
// int main()
// {
//     child obj1;
//     obj1.setId(81);
//     obj1.display();
//     return 0;
// }
// *********************************************************
// class Student{
// private:
// 	string name;
// 	string surname;
// 	int rollNo;

// public:
// 	Student(string studentName, string studentSurname, int studentRollNo){
// 		name = studentName;
// 		surname = studentSurname;
// 		rollNo = studentRollNo;
// 	}

// 	void getStudentDetails(){
// 		cout << "The name of the student is " << name << " " << surname << endl;
// 		cout << "The roll no of the student is " << rollNo << endl;
// 	}
// };

// int main() {
// 	Student student1("Saurabh", "Dixit", 21);
// 	student1.getStudentDetails();
// 	return 0;
// }
// ********************************************Encaptulation 
// class Student{
//     private:
//     string name;
//     int age;
//     int height;
 
//     public:
//     int getAge(){
//         return this -> age;
//     }
// };

// int main()
// {
//     Student first;
//     cout << " All is Well " <<endl;
//     return 0;
// }
// *********************************************Inheritance
// class Human{
//     public:
//     int height;
//     int weight;

//     private:
//     int age;

//     public:
//     int getage()
//     {                                                         Not Appropriate
//         return this-> age;
//     }

//     void getweight(int w){
//      this->weight = w;
//     } 
// };

// class Male: private Human{
//     public:
//     string color;

//     void work {
//         cout <<" Male Working "<<endl;
//     }
// };

// int main() {
    
//     Male m1;
//     cout << m1.getweight() << endl;
// }
// ************************************************Single Inheritanc
// class Animal{
//     public:
//     int age;
//     int weight;

//     public:
//     void Bark() {
//         cout <<" Barking " <<endl;
//     }
// };
// class Dog: public Animal {

// };

// int main()
// {
//     Dog d;
//     d.Bark();
//     cout << d.age <<endl;
// }
// ********************************************MultiLevel Inheritance
// class Animal{
//     public:
//     int age;
//     int weight;

//     public:
//     void Bark() {
//         cout <<" Barking " <<endl;
//     }
// };

// class Dog: public Animal {

// };

// class GermanShepherd: public Dog {

// };

// int main()
// {
//    GermanShepherd g;
//    g.Bark();
// }
// ********************************************Multiple Inheritance
// class Animal{
//     public:
//     int age;
//     int weight;

//     public:
//     void Bark() {
//         cout <<" Barking " <<endl;
//     }
// };
// class Human {
//     public:
//     string color;
//     public:
//     void speak() {
//         cout <<" Speaking " <<endl;
//     }
// };
// class Dog: public Animal, public Human {

// };

// int main()
// {
//     Dog obj1;
//     obj1.speak(); 
//     obj1.Bark();

//     return 0;
// }
// *******************************Hierarchical Inheritance
// class ParentClass {
//     public:
//     void printParent(){
//         cout <<"Inside Function 1 " <<endl;
//     }
// };

// class child1: public ParentClass {
//     public:
//     void printchild1() {
//         cout <<"Inside Function 2 " <<endl;
//     }
// };

// class child2: public ParentClass {
//     public :
//     void printchild2() {
//         cout <<"Inside Function 3 " <<endl;
//     }
// };

// int main()
// {
//     ParentClass object1;
//     object1.printParent();

//     child1 object2;
//     object2.printParent(); 
//     object2.printchild1();

//     child2 object3;
//     object3.printParent(); 
//     object3.printchild2();
// }
// **************************************************Hybrid Inheritance
// class vehicle {
//     public:
//     vehicle() {
//         cout <<" This is a Vehicle " <<endl;
//     }
// };

// class Fare {
//     public:
//     Fare() {
//         cout <<" Fare of vehicle " <<endl;
//     }
// };

// class Car: public vehicle {

// };
// class Bus: public vehicle, public Fare {

// };

// int main()
// {
//     Bus obj1;
//     return 0;
// }
// ************************************************Inheritance Ambiguity
// class A {
//     public:
//     void func() {
//         cout<<" I am A "<<endl;
//     }
// };

// class B {
//     public:
//     void func() {
//         cout<<" I am B "<<endl;
//     }
// };

// class C: public A, public B {

// };

// int main()
// {
//     C obj;
//     obj.A::func();
//     obj.B::func();
//     return 0;
// }

// ********************************************************Polymorphisms(Compile Time)
// class A {
//     public:
//     void sayHello() {
//         cout <<" Hello Everyone " <<endl;
//     }
//     int sayHello(char name) {
//         cout <<" Hii.. Everyone " <<endl;
//         return 1;
//     }
//     void sayHello(string name) {
//         cout <<" Hello " <<endl;
//     }
// };

// int main()
// {
//     A obj;
//     obj.sayHello();
//     return 0;
// }
// *********************************************************Function Overloading
// int add(int num1, int num2) {
//     return num1 + num2;
// }

// int add(int num1, int num2, int num3) {
//     return num1 + num2 + num3;
// }

// int main() {
//     cout << add(10, 20) <<endl;
//     cout << add(10, 20, 30);
//     return 0;
// }
// *********************************************************Operator Overloading
//  class A {
//     public:
//     void sayHello() {
//         cout <<" Hello Everyone " <<endl;
//     }
//     int sayHello(char name) {
//         cout <<" Hii.. Everyone " <<endl;
//         return 1;
//     }
//     void sayHello(string name) {
//         cout <<" Hello " <<endl;
//     }
// };
// class B {
//     public:
//     int a;
//     int b;

//     public:
//     int add() {
//         return a+b;
//     }

//     void operator+ (B &obj){
//         int value1 = this->a;
//         int value2 = obj.a;
//         cout <<" Output " << value2 - value1 <<endl;
//     }

//     void operator() () {
//         cout<<" Function call " << this -> a << endl ;
//     }
// };
// int main()
// {
//     B obj1, obj2;
//     obj1.a = 4;
//     obj2.a = 7;
//     obj1 + obj2;
//     obj1();
//     return 0;
// }
// ************************************************************(Function Overriding)Run Time Polymorphisms
// class Animal{
//     public :
//     void speak() {
//         cout << " Speaking " <<endl;
//     }
// };

// class Dog: public Animal {
//     public:
//     void speak() {
//         cout <<" Barking " <<endl;
//     }
// };

// int main()
// {
//     Animal obj;
//     obj.speak();
    
//     Dog obj;
//     obj.speak();
// }