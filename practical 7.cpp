/*
Write a program in C++ to use map associative container. The keys will be the names 
of states and the values will be the populations of the states. When the program runs, 
the user is prompted to type the name of a state. The program then looks in the map, 
using the state name as an index and returns the population of the state. 
*/

//theory

/*

Maps are part of the C++ STL (Standard Template Library). Maps are the associative containers that store 
sorted key-value pair, in which each key is unique and it can be inserted or deleted but cannot be altered. 
Values associated with keys can be changed.

*/

#include <iostream>
#include <map>

using namespace std;

int main(){
	
	typedef map<string,int> mapType;
	mapType populationMap;
	
	populationMap.insert(pair<string,int>("maharashtra", 1234566));
	populationMap.insert(pair<string,int>("gujarat", 5584566));
	populationMap.insert(pair<string,int>("rajasthan", 854666));
	populationMap.insert(pair<string,int>("telangana", 123599));
	populationMap.insert(pair<string,int>("kerala", 452666));
	
	
	cout<<"\nsize of populationMap is: "<<populationMap.size();
	
	string state_name;
	cout<<"\nenter state name: ";
	cin>>state_name;
	
	mapType::iterator p;
	
	p = populationMap.find(state_name);
	if(p!=populationMap.end()){
		cout<<state_name<<" 's population is: "<<p->second;
	}
	else{
		cout<<"\nkey is not populationMap";
		populationMap.clear();
	}
	
	return 0;
}
