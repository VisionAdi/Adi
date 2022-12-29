/*
Write a C++ program that creates an output file, writes information to it, closes the 
file, open it again as an input file and read the information from the file.

*/

//theory

/*

fstream is used to read and write from a file. This requires another standard C++ library called fstream, 
which defines three new data types:

1. ofstream- This data type represents the output file stream and is used to create files and to write information to files.
2. ifstream- This data type represents the input file stream and is used to read information from files.
3. fstream- This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which 
			means it can create files, write information to files, and read information from files.
			
To perform file processing in C++, header files <iostream> and <fstream> must be included in your C++ source file.

*/

#include<iostream>
#include<fstream>

using namespace std;

class student{
	private:
		string name;
		int rno;
	public:
		void getdata(){
			
			fstream fs;
			
			//Append mode. All output to that file to be appended to the end.
			fs.open("D:\\SCOE THIRD SEM\\OOP\\PRACTICALS\\practical 4.txt",ios::app);
			
			if(!fs){
				cout<<"\nfile creation failed";
			}
			else{
				
				cout<<"\nenter name: ";
				cin>>name;
				
				cout<<"\nenter roll number: ";
				cin>>rno;
				
				fs<<"\n";
				
				fs<<name<<" "; //write name to file
				fs<<rno<<"\n"; //write rno to file
				
				fs.close();
			}
		}
		
		void display(){
			
			fstream fs;
			
			//Open a file for reading.
			fs.open("D:\\SCOE THIRD SEM\\OOP\\practical 4.txt",ios::in);
			
			if(!fs){ //checking whether file exists or not
				cout<<"\nno such file exists";	
			}
			
			else{
				while(!fs.eof())// read till end of the file
		        {
		            fs>>name;   //  Reading name from file
		            fs>>rno;
					 //  Reading rollno from file
		            if(!fs.eof())  // checking whether reached eof
		            {
		            	cout<<name<< " ";
		            	cout<<rno;
		            	cout<<"\n";   // Message display on screen
		            
		            }// end of if
		        } // end of while
		        
				fs.close();
			}//end of else
		}
		
};

int main(){
	int ch;
	student s;
	fstream fs;
	
	do{
		cout<<"\n1-add info\n2-display info\n3-exit";
		cout<<"\nenter choice: ";
		cin>>ch;
		
		switch(ch){
			case 1:
				s.getdata();
				break;
			case 2:
				s.display();
				break;
			case 3:
				cout<<"\nexiting..";
				break;
			default:
				cout<<"\ninvalid choice";
				break;
		}
	}while(ch!=3);
	return 0;
}

