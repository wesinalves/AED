#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

	int n, num, maior, op;
	double c, result=0, x;
	bool r;

//Fun��o que realiza a soma de n polin�mios e avalia o resultante caso o usu�rio queira.
void soma(){
	cout << "Quantos polin�mios deseja somar?" << endl;
	cin >> num;
	cout << endl << "Qual o n�mero de coeficientes do polin�mio de maior ordem?" << endl;
	cin >> maior;
	
	double matriz[num][maior];
	double soma[maior];
	
	for(int i=0; i<num; i++){
		cout << "Digite o n�mero de coeficientes do polin�mio " << i+1 << endl;
		cin >> n;
		double polinomio[maior];
		
		for(int z=0; z<n; z++){
			cout << "Digite o coeficiente de ordem " << z << endl;
			cin >> c;
			polinomio[z]=c;
		}
		
		if(n<maior){
			for(int k=n;k<maior;k++){
				polinomio[k]=0;
			}
		}		
		
		for(int j=0; j<maior; j++){
			matriz[i][j]=polinomio[j];
		}			
	}
	
	//Mostra matriz com os coeficientes dos polin�mios
	/*for(int i=0; i<num;i++){
		for(int j=0; j<maior; j++){
			cout << matriz[i][j];
		}
		cout << endl;
	}*/
	
	//Soma dos coeficientes dos polin�mios.
	for(int i=0; i<num;i++){
		for(int j=0; j<maior; j++){
			soma[j]=soma[j]+matriz[i][j];
		}
	}
	
	//Mostra polin�mio resultante.
	cout << "O polin�mio resultante da soma �: p(x) = ";
	for(int i=maior-1; i>=0; i--){
		cout << soma[i] << "*x^" << i;
		if(i!=0){
			cout << " + ";
		}
	}
	cout << "." << endl << endl;
	
	//Avalia polin�mio resultante em um x determinado pelo usu�rio.
	cout << "Deseja avaliar o polin�mio para algum x? (responda true(1) para sim ou false(0) para n�o)" << endl;
	cin >> r;
	
	if(r){
		cout << "Digite o valor de x." << endl;
		cin >> x;
		for(int i=maior-1; i>=0; i--){
			result=result+soma[i]*(pow(x,i));
		}
		
		cout << endl << "p(" << x << ") = " << result << endl << endl;
		system("pause");
		system("cls");	
	}
	else{
		system("pause");
		system("cls");
	}
}

//Fun��o que avalia um polin�mio especficado pelo usu�rio.
void avalia(){
	int np;
	double d, result2;
	
	cout << "Digite o n�mero de coeficientes do polin�mio." << endl;
	cin >> np;
	
	double polinomio2[np];
		
		for(int z=0; z<np; z++){
			cout << "Digite o coeficiente de ordem " << z << endl;
			cin >> d;
			polinomio2[z]=d;
		}
		
	cout << "Digite o valor de x para o qual deseja avaliar o polin�mio." << endl;
		cin >> x;
		for(int i=np-1; i>=0; i--){
			result2=result2+polinomio2[i]*(pow(x,i));
		}
		
	cout << endl << "p(" << x << ") = " << result2 << endl << endl;
	system("pause");
	system("cls");
}

int main() {
	
	setlocale (LC_ALL, "portuguese");
	bool ok=true;
	
	//Menu, para que o usu�rio escolha se deseja somar polin�mios ou avaliar um polin�mio diretamente.
	while(ok){ 
		cout << "Selecione uma op��o." << endl << "1.Somar polin�mios e avaliar o resultante;" << endl << "2.Avaliar um polin�mio;" << endl << "3.Sair." << endl;
		cin >> op;
		cout << endl << endl;
	
		switch(op){
			case 1: {
				soma();
				break;
			}
			case 2: {
				avalia();
				break;
			}
			case 3: {
				ok=false;
				break;
			}
		}
	
	}	
	
	return 0;	
}
