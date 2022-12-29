/*Write a function template for selection sort that inputs, sorts and outputs an integer 
array and a float array. */

//theory

/*
1. selection sort-
The selection sort algorithm sorts an array by repeatedly finding the minimum element
(considering ascending order) from the unsorted part and putting it at the beginning. 
The algorithm maintains two subarrays in a given array.
The subarray which already sorted. 
The remaining subarray was unsorted

2.template-
A C++ template is a powerful feature added to C++. It allows you to define the generic classes 
and generic functions and thus provides support for generic programming. 
templates are independent of any particular datatype.

3. function template- 
We can define a template for a function. For example, if we have an add() function,
we can create versions of the add function for adding the int, float or double type values.
We pass datatype as parameter so that we dont have to write the same code again and again.
*/

#include <iostream>

using namespace std;

//T is a generic datatype
template<typename T>

T selection_sort(){
	
	T arr[10];
	T temp;
	int i,j,min;
 	
 	
	cout<<"\nenter elements for sorting: "<<endl;
	//accepting elements
	for(i=0;i<10;i++){
		cout<<"arr["<<i<<"]=";
		cin>>arr[i];
	}
	
	//sorting elements using selection sort
 	for(i=0;i<10-1;i++)
 	{
 		min=i;
 		for(j=i+1;j<10;j++)
 		{
 			if(arr[j]<arr[min])
 				min=j;
 		}
 		temp=arr[i];
 		arr[i]=arr[min];
 		arr[min]=temp;
	}
	
	//displaying elements
	for(i=0;i<10;i++){
		cout<<"\na["<<i<<"]="<<arr[i];
	}
}

int main(){
	
	cout<<"\nsorting of integer array: ";
	selection_sort<int>();
	
	cout<<"\nsorting of float array: ";
	selection_sort<float>();
	
	return 0;
}
