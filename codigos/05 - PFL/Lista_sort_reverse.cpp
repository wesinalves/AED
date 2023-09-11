#include<iostream>
#include<list>
#include<string>

using namespace std;

int main(){
	int i;
	
	/*
	list<int> teste;
	
	
	teste.push_front(1);
	teste.push_front(4);
	teste.push_front(7);
	teste.push_front(9);
	teste.push_front(5);
	teste.push_front(3);
	teste.push_front(8);
	teste.push_front(2);
	teste.push_front(6);
	
	teste.sort();
	teste.reverse();
	
	for(i=0 ; !teste.empty() ; i++){
		cout<< teste.front() << endl;
		teste.pop_front();
	}
	*/
	
	
	///*
	list<string> exemplo;
	
	exemplo.push_back("Julia");
	exemplo.push_back("Artur");
	exemplo.push_back("Pedro");
	exemplo.push_back("Henrrique");
	exemplo.push_back("Mateus");
	
	
	exemplo.sort();
	//exemplo.reverse();
	
	for(i=0 ; !exemplo.empty() ; i++){
		cout<< exemplo.front() << endl;
		exemplo.pop_front();
	}
	//*/
	
	
	return 0;
}

