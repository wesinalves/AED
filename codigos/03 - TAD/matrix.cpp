#include <iostream>
#include <vector>

using namespace std;

vector<vector<float> > soma (vector<vector<float> > A, vector<vector<float> > B); // Declara o cabe�alho da fun��o de soma, que recebe duas matrizes de qualquer tamanho e retorna uma matriz 


int main(){
	setlocale(LC_ALL,"");
	int LinhasM1, ColunasM1, LinhasM2, ColunasM2;
	float draft;
	vector<float> LinhaDraft; 
	vector<vector<float> > Matriz1, Matriz2;
	cout << "Entre com o n�mero de linhas da primeira matriz" << endl;
	cin >> LinhasM1;
	cout << "Entre com o n�mero de colunas da primeira matriz" << endl;
	cin >> ColunasM1;
	cout << "Entre com o n�mero de linhas da segunda matriz" << endl;
	cin >> LinhasM2;
	cout << "Entre com o n�mero de colunas da segunda matriz" << endl;
	cin >> ColunasM2;

// Define o formato da matriz
	
	for (int i=0; i<LinhasM1; i++){
	cout << "Entre com os elementos da " << i+1 << "� linha da primeira matriz separados por espa�o" << endl;
	for(int j=0; j<ColunasM1; j++){
		cin >> draft; 
		LinhaDraft.push_back(draft); // L� todas os elementos em uma �nica linha
	}
	Matriz1.push_back(LinhaDraft); // Adiciona a linha � matriz
	LinhaDraft.clear(); // Limpa a linha com os elementos, permitindo que a vari�vel seja reutilizada
}

// L� a primeira matriz, recebendo do teclado a matriz no formato proposto

for (int i=0; i<LinhasM2; i++){
	cout << "Entre com os elementos da " << i+1 << "� linha da segunda matriz separados por espa�o" << endl;
	for(int j=0; j<ColunasM2; j++){
		cin >> draft;
		LinhaDraft.push_back(draft);
	}
	Matriz2.push_back(LinhaDraft);
	LinhaDraft.clear();
}

soma(Matriz1, Matriz2);	


return 0;
}

vector<vector<float> > soma (vector<vector<float> > A, vector<vector<float> > B){
	int LinhasA = A.size();
	int ColunasA = A[0].size();
	int LinhasB = B.size();
	int ColunasB = B[0].size();
	// Descobre o tamanho das Matrizes
	if (!((LinhasA == LinhasB) && (ColunasA == ColunasB))){
		cout << "Erro! Dimens�es Incompat�veis" << endl;
	} // Verifica se os tamanhos s�o compat�veis para definir a opera��o de soma
	else{
		vector< vector<float>> Matriz3;
		vector<float> LinhasMatriz3;
		float C;
		cout << "A matriz resultante da soma �: " << endl;
		for (int i=0; i<LinhasA; i++){
			for (int j=0; j<ColunasA; j++){
				C = A[i][j]+B[i][j]; // Realiza a soma, elemento a elemento
				LinhasMatriz3.push_back(C); // Adiciona o novo elemento � uma linha da matriz
				cout << C << "\t"; // Imprime a matriz na tela
			}
			cout << endl;
			Matriz3.push_back(LinhasMatriz3); // Adiciona a linha � matriz
			LinhasMatriz3.clear(); // Limpa a linha da matriz
		}
		return Matriz3; // Retorna a matriz soma 
	}

}

