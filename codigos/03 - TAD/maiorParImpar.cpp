#include <iostream>

using namespace std;

float maior(float x, float y);
void paridade(int x);

int main(){
	int n;
	bool flag=false; // Verifica se o menu j� foi executado
	setlocale(LC_ALL,""); //Habilita caracteres especiais
	while(1){
	do{
	cout << "Escolha a fun��o que voc� deseja executar: " << endl;
	cout << "1. Verificar o maior n�mero" << endl;
	cout << "2. Verificar a paridade" << endl;
	cout << "3. Sair" << endl;
	if (flag==true){
		cout << "Erro! Op��o inv�lida" << endl;
	}
	cin >> n; // Pede que o usu�rio escolha uma op��o
	flag=true; // Marca que o menu j� foi executado. A flag controla a exibi��o de uma mensagem de erro.
	system("cls"); // Limpa a tela
	}
	while((n<0)||(n>3)); // Impede que o usu�rio escolha uma op��o inv�lida
	flag = false; // Limpa a flag, fazendo com que n�o seja exibida nenhuma mensagem de erro ao acessar novamente o menu
	switch(n){ // Executa o programa de acordo com a op��o escolhida pelo usu�rio
		case 1:
			float x;
			float y;
			cout << "Entre com os dois n�meros para serem comparados" << endl;
			cin >> x >> y;
			cout << "O maior n�mero �: " << maior(x, y) << endl;
			break;
		case 2:
			int numero;
			cout << "Entre com o n�mero para verificar sua paridade" << endl;
			cin >> numero;
			paridade(numero);
			break;
		case 3:
			return 0;
		}
		system("pause");
		system("cls");
	}
return 0;
}

float maior(float x, float y){
	if (x>y){
		return x;
	}
	else{
		return y;
	}
}

void paridade(int x){
	if (x%2 == 0){
		cout << "O valor informado � par" << endl;
	}
	else{
		cout << "O valor informado � �mpar" << endl;
	}
}