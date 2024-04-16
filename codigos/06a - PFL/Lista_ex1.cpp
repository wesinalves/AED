#include<iostream>
#include<list>

using namespace std;

int main(){
	int i;
	list <int> sequencia;
	
	
	for(i=0 ; i<10 ; i++){
		sequencia.push_front(i); 
	}
	
	//sequencia.clear();
	cout << "N = " << sequencia.size() << endl;
	
	// de 9 a 0
	///*	
	for(i=0 ; i<10 ; i++){
		cout << sequencia.front() << endl;
		sequencia.pop_front();
	}
	//*/
	
	
	//de 0 a 9
	/*
	for(i=0 ; i<10 ; i++){
		cout << sequencia.back() << endl;
		sequencia.pop_back();
	}
	*/
	
		
	
	
	return 0;
}

