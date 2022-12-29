/*
Imagine a publishing company which does marketing for book and audio cassette 
versions. Create a class publication that stores the title (a string) and price (type float) 
of publications. From this class derive two classes: book which adds a page count 
(type int) and tape which adds a playing time in minutes (type float). Write a program 
that instantiates the book and tape class, allows user to enter data and displays the 
data members. If an exception is caught, replace all the data member values with zero 
values
*/

#include <iostream>

using namespace std;

class publication{
	
	private:
		string title;
		float price;
	public:
		publication(){
			title="";
			price=0.0;
		}
	void getdata(){
		cout<<"\nenter title: ";
		cin>>title;
		cout<<"\nenter price: ";
		cin>>price;
	}
	void display(){
		cout<<"\ntitle: "<<title;
		cout<<"\nprice: "<<price;
	}
		
};

class book:public publication{
	private:
		int pages;
	public:
		book(){
			pages=0;
		}
		
		void getdata(){
			publication::getdata();
			cout<<"\nenter number of pages of book: ";
			cin>>pages;
		}
		void display(){
			publication::display();
			try{
				if(pages<0){
					throw pages;
				}
			}
			catch(int f){
				cout<<"\nnumber of pages are invalid "<<pages;
				pages=0;
			}
			cout<<"\nnumber of pages: "<<pages;
		}
};

class tape:public publication{
	private:
		float time;
	public:
		tape(){
			time=0.0f;
		}
		void getdata(){
			publication::getdata();
			cout<<"\nenter time of tape: ";
			cin>>time;
		}
		void display(){
			publication::display();
			try{
				if(time<0.0){
					throw time;
				}
			}
			catch(float f){
				cout<<"\ninvalid time "<<f;
				time=0.0f;
			}
			cout<<"\ntime of tape is: "<<time;
		}
};

int main(){
	
	book b[10];
	tape t[10];
	
	int bookcount=0,tapecount=0,ch=0,i,j;
	do{
		cout<<"\n------------------------------------------------------------------";
		cout<<"\n1-add book\n2-add tape\n3-display book\n4-display tape\n5-exit";
		cout<<"\n------------------------------------------------------------------";
		cout<<"\nenter choice: ";
		cin>>ch;
		cout<<"\n------------------------------------------------------------------";
		switch(ch){
			
			case 1:
				cout<<"\nadd book:";
				b[bookcount].getdata();
				bookcount++;
				break;
			case 2:
				cout<<"\nadd tape:";
				t[tapecount].getdata();
				tapecount++;
				break;
			case 3:
				cout<<"\nbooks:";
				for(i=0;i<bookcount;i++){
					b[i].display();
				}		
				break;
			case 4:
				cout<<"\ntapes:";
				for(j=0;j<tapecount;j++){
					t[j].display();
				}
				break;
			case 5:
				cout<<"\nexiting..";
				break;
			default:
				cout<<"\ninvalid option!";
		
		}	
	}while(ch!=5);
	return 0;
	
}
