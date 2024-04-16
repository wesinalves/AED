//Exemplo de uso de hash para gravação de dados ordenados e pesquisa otimizada
#include <iostream>
#include<string>
using namespace std;

struct aluno {
	int mat; // 4 bytes = 4 bytes
	string nome; // 1 byte * 81 = 81 bytes
	string email; // 1 byte * 41 = 41 bytes
};
typedef struct aluno Aluno; 

int funcao_hash(int matricula) {
	int valor;
	valor = matricula-1723500;
	if((valor >= 0) & (valor <=99)){
		return valor;
	}
	else{
		return -1;
	}

}


int main(){
	int indice;
	
	//definimos que dentro do nosso universo de matriculas teremos até 100 alunos na turma
	Aluno *tabAlunos= new Aluno[99];
	
	/*ao usarmos a funcao_hash garantimos que os alunos serão sempre armazenados em nosso sistema
	de forma ordenada(pela matricula) mesmo que sejam inseridos em uma ordem aleatoria*/	
	indice = funcao_hash(1723543);
	
	cout << "usando a matricula 1723543 como exemplo" << endl << endl;
	cout << "o indice hash para essa matricula e " << indice << endl <<endl;
	
	//inserido os dados do aluno em nosso array 
	tabAlunos[indice].mat=1723543;
   	tabAlunos[indice].nome="Albert Einstein Pereira de Lima";
   	tabAlunos[indice].email="alberte@unb.br";
   	
   	//imprimindo os ados do aluno
   	cout << "dados do aluno:" << endl;
   	cout << tabAlunos[funcao_hash(1723543)].mat << endl;
   	cout << tabAlunos[funcao_hash(1723543)].nome << endl;
   	cout << tabAlunos[funcao_hash(1723543)].email;
   	
    return 0;
}

