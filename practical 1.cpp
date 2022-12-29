/* Practical 1: Implement a class Complex which represents the Complex Number data type. 
Implement the following:
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overload operator + to add two complex numbers. 
3. Overload operator * to multiply two complex numbers. 
4. Overload operators << and >> to print and read Complex Numbers */

#include <iostream>

using namespace std;

class complex{
	
	float real,imag;
	
	public:
	complex(){
		real=0;
		imag=0;
	}
	
	complex operator +(complex);
	complex operator *(complex);
	
	friend istream &operator >>(istream &input, complex &t){
		cout<<"\nEnter the real part: ";
		input>>t.real;
		cout<<"Enter the imaginary part: ";
		input>>t.imag;
	}
	
	friend ostream &operator <<(ostream &output, complex t){
		output<<t.real<<"+"<<t.imag<<"i\n";
	}
	
	
	
};

complex complex::operator +(complex c){
	complex temp;
	temp.real=real+c.real;
	temp.imag=imag+c.imag;
	return temp;
}

// (a+bi) * (c+di)
// (ac-bd) + (ad+bc)
complex complex::operator *(complex c){
	complex temp2;
	temp2.real=(real*c.real)-(imag*c.imag);
	temp2.imag=(imag*c.real)+(real*c.imag);
	return temp2;
} 

int main(){
	
	complex c1,c2,c3,c4;

	//1-
	cout<<"\nDefault constructor value is: ";
	cout<<c1;
		
	cout<<"\nEnter first number: ";
	cin>>c1;
	cout<<"\nEnter second number: ";
	cin>>c2;
	
	c3=c1+c2;
	c4=c1*c2;
	
	cout<<"\nFirst number is: ";
	cout<<c1;
	
	cout<<"\nSecond number is: ";
	cout<<c2;
	
	//2-
	cout<<"\nAddition is: ";
	cout<<c3;
	
	//3-
	cout<<"\nMultiplication is: ";
	cout<<c4;
	
	return 0;	

}
