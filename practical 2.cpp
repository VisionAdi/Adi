/* Develop a program in C++ to create a database of student’s information system 
containing the following information: 

Name, Roll number, Class, Division, Date of Birth, 
Blood group, contact address, Telephone number, Driving license no. and other. 
Construct the database with suitable member functions. 

Make use of constructor, default constructor, copy constructor, destructor, static member functions, 
friend class, this pointer, inline code and dynamic memory allocation 
operators-new and delete as well as exception handling. */

//theory

/* static: scope of static variable is throughout the program. 
		it is initialised to 0 at start.
		static member functions can only access static data members
		
	this pointer: points to the current instance of the class
				  used to differentiate between instance variable and local variable
				  
	friend: If a function is defined as a friend function in C++, then the protected 
			and private data of a class can be accessed using the function.
	
	array of pointers: An array of pointers is an array that consists of variables 
						of pointer type, which means that the variable is a pointer addressing to some other element.
						
	constructor: Constructor in C++ is a special method that is invoked automatically at the time of object creation. 
				It is used to initialize the data members of new objects generally. 
				The constructor in C++ has the same name as the class or structure. 
				Constructor is invoked at the time of object creation. 
				It constructs the values i.e. provides data for the object which is why it is known as constructors.
				Constructor does not have a return value, hence they do not have a return type.
				
	inline: If make a function as inline, then the compiler replaces the function calling location 
			with the definition of the inline function at compile time.
			
	dynamic memory allocation: Memory in your C++ program is divided into two parts -
								The stack - All variables declared inside the function will take up 
								memory from the stack.
								The heap - This is unused memory of the program and can be used to allocate the 
								memory dynamically when program runs.
								Many times, you are not aware in advance how much memory you will need to store 
								particular information in a defined variable and the size of required memory can be determined at run time.
								You can allocate memory at run time within the heap for the variable of a given 
								type using a special operator in C++ which returns the address of the space allocated. This operator is called new operator.
								If you are not in need of dynamically allocated memory anymore, you can use delete operator, 
								which de-allocates memory that was previously allocated by new operator.
*/

#include<iostream>
#include<string.h>    // header file declares a set of functions to work strings.

using namespace std;
    
class db
{
    int roll;
    char name[20];
    char Class[10];
    char Div[10];
    char dob[12];
    char bg[5],city[10];
    char phone[12],license[12];

	public:
		
   	// declaration of static variable
    static int stdno;
	
	// defination of static function
    static void count(){   
    	cout<<"\n No.of objects created: "<<stdno;
    }
     
    inline void fin(){
	 	cout<<"Student Data is: ";
	}

	// default constructor
    db()        
    {
      roll=7;
      strcpy(name,"Sachin");
      strcpy(Class,"SE");
      strcpy(Div,"A");
      strcpy(dob,"13/08/1992");
      strcpy(bg,"B+");
      strcpy(city,"Pune");
      strcpy(phone,"9123456789");
      strcpy(license,"A1010");
      ++stdno;
    }
    
    // defining member function
    void getdata()
    {
        cout<<"Enter name: "<<endl;
        cin>>name;
        
        cout<<"rollno: "<<endl;
        cin>>roll;
        
        cout<<"Class: "<<endl;
        cin>>Class;
        
        cout<<"Div: "<<endl;
        cin>>Div;
        
        cout<<"DOB: "<<endl;
        cin>>dob;
        
        cout<<"bg: "<<endl;
        cin>>bg;
        
        cout<<"City: "<<endl;
        cin>>city;
        
        cout<<"Phone: "<<endl;
        cin>>phone;
        
        cout<<"license: "<<endl;
        cin>>license;
        
    }
        
    friend void display(db d);   // declaration of friend function

    ~db(){   // destructor
        cout<<"\n\n"<<name<<"(Object) is destroyed!\n";  
    }
    
};

void display(db d){ // defination of friend function
    cout<<"\n Name:"<<d.name;
    cout<<"\n Roll_No:"<<d.roll;
    cout<<"\n Class:"<<d.Class;
    cout<<"\n Div:"<<d.Div;
    cout<<"\n DOB:"<<d.dob;
    cout<<"\n Blood group:"<<d.bg;
    cout<<"\n City:"<<d.city;
    cout<<"\n Phone_No:"<<d.phone;
    cout<<" \n License_No:"<<d.license; 
}
      
int db::stdno; // Define static data member stdno outside the class;

int main(){

    int n,i;
    db d1,*ptr[5]; //array of pointers
	 
	d1.fin();
    cout<<"\nDefault values:";
    display(d1);

	cout<<"\nHow many objects u want to create?:";
    cin>>n;
    
    d1.getdata();
    display(d1);

    //new operator use for dynamic memory(run time) allocation
    for(i=1;i<n;i++)
    {                   
        ptr[i]=new db(); 
        ptr[i]->getdata(); 
    }
    
    //cout<<"\n"<<"name"<<"roll"<<"Class"<<"Div"<<"dob"<<"bg"<<"contact"<<"phone"<<"license";
    
    // calling of static function
    for(i=1;i<n;i++){
    	display(*ptr[i]);
    	db::count();
	}  

	//delete operator use to deallocation of memory
    for(i=1;i<n;i++){
            delete(ptr[i]); 
    }
    
    cout<<"\nObjects deleted!" ;
    
    return 0;
}
