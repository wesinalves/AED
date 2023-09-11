#include <iostream>
#include<string>
using namespace std;

class aluno{
public:

	string materia1, materia2, materia3, materia4, aux;
	int cap, i, j;

    void insere(){

		cout << "Informe as materias que Pedro teve no dia:" << endl;
		cin >> materia1;
		cin >> materia2;
		cin >> materia3;
		cin >> materia4;
	}

	void fhash(){
	    j = 4;

        do{
            cout << endl;
            cout << "Qual materia voce quer buscar o capitulo? " << endl;
            cin >> aux;

            cap = (aux[0] / aux.size());
            if((cap >= 0) & (cap <= 99)){
                cap = cap;
            }else{
                cout << "ESTRAPOLOU" << endl;
            }

            cout << "O capitulo da materia " << aux << " eh " << cap << endl;
            j --;
        }while(j > 0);
    }

    void menu(){

        cout << endl;
        cout << "Para inserir a grade horaria: (1)" << endl;
        cout << "Para consultar o capitulo da materia: (2)" << endl;
        cout << "Sair do programa(3). " << endl;
    }
};

int main(){

	int num;
	aluno obj;

	do{
	    obj.menu();
        cin >> num;

        switch(num){
        case 1:
            obj.insere();
            break;
        case 2:
            obj.fhash();
            break;
        case 3:
            return 0;
            break;
        }
    }while(num == 1 || num == 2 || num == 3);

return 0;
}
