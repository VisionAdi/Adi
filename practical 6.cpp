/*
Write C++ program using STL for sorting and searching user defined records such 
as personal records (Name, DOB, Telephone number etc) using vector container
*/

//theory

/*

A vector is array like contianer. Just like array, it uses contiguous memory locations. 
But unlike array, it's size can be changed dynamically.

Member functions of vector:
1. modifiers-
push_back()
pop_back()
assign()
insert()
erase()
clear()

2. iterators-
begin()- returns iterator to the beginning
end()- returns iterator to the end

3. capacity-
size()
max_size()
resize()
capacity()
empty()

*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Student
{
  public:
    char name[10];
    int age;
    int roll_no;

    bool operator==(const Student &i1)
    {
       if(roll_no==i1.roll_no)
       	return 1;
       return 0;
    }
    
    /*bool operator<(const Student &i1)
   {
      if(roll_no<i1.roll_no)
      	return 1;
      return 0;
   }*/
};
//---------------------------------------------------------

vector<Student> o1;

void print(Student &i1);
void display();
void insert();
void search();

//----------------------------------------------------------

bool compare(const Student &i1, const Student &i2)
{

 return i1.roll_no < i2.roll_no;
}

//---------------------------------------------------------

int main()
{
 int ch;
 do
 {
 cout<<"\n*** Menu ***";
 cout<<"\n1.Insert";
 cout<<"\n2.Display";
 cout<<"\n3.Search";
 cout<<"\n4.Sort";
 cout<<"\n5.Exit";
 cout<<"\nEnter your choice:";
 cin>>ch;

 switch(ch)
 {
 case 1:
 insert();
 break;

 case 2:
 display();
 break;

 case 3:
 search();
 break;

 case 4:
 sort(o1.begin(),o1.end(),compare);
 cout<<"\n\n Sorted on Roll no:";
 display();
 break;


 case 5:
 exit(0);
 }

 }while(ch!=6);
 return 0;
}

//--------------------------------------------------------

void insert()
{
 Student i1;
 
 cout<<"\nEnter Student naame:";
 cin>>i1.name;
 
 cout<<"\nEnter Student Age:";
 cin>>i1.age;
 
 cout<<"\nEnter Student Roll_No:";
 cin>>i1.roll_no;
 
 o1.push_back(i1);
}

//--------------------------------------------------------

void display()
{
	//for_each is defined in header file algorithm
 for_each(o1.begin(),o1.end(),print);
}

//-------------------------------------------------------

void print(Student &i1)
{
 cout<<"\n";
 cout<<"\nName :"<<i1.name;
 cout<<"\nStudent Age:"<<i1.age;
 cout<<"\nStudent Roll_No::"<<i1.roll_no;

}

//---------------------------------------------------------

void search()
{
 vector<Student>::iterator p;
 Student i1;
 
 cout<<"\nEnter Student Roll_No: to search:";
 cin>>i1.roll_no;
 
 p=find(o1.begin(),o1.end(),i1);
 
 if(p==o1.end())
 {
 cout<<"\nNot found.";
 }
 else
 {
 cout<<"\nStudent  Found."<<endl;
 cout<<"Student Name : "<<p ->name<<endl;
 cout<<"Student Age : "<<p ->age<<endl;
 cout<<"Student Roll_No : "<<p ->roll_no<<endl;
 }
}

