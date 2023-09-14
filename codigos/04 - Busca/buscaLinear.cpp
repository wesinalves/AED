#include <iostream>
using namespace std;

class Busca{
    private:

    int opcao;
    const int tamanho = 10;
    int vetor[11];
    int res;

    public:
    
    void menu(){
        // opções do Menu inicial
        cout << "Insira a opcao desejada:" << endl;
        cout << "1) inserir elemento no array" << endl;
        cout << "2) apresentar array" << endl;
        cout << "3) informar elemento a ser buscado" << endl;
        cout << "4) sair do programa" << endl;
        cin >> opcao;
    }

    void insereElemento(){
        for(int i=0; i<tamanho; i++){
            cout << "Informe o valor do elemento " << i << endl;
            cin >> vetor[i];
        }
    }

    void apresentarVetor(){
        cout << "O vetor de entrada é:" << endl;
        for(int i=0; i<tamanho; i++){
            cout << vetor[i] << "\t";
        }
        cout << endl;
    }

    int buscaLinear(int sent){
        int i = 0;
        vetor[tamanho] = sent;
        while(vetor[i] != sent)
            i++;
        return (i == tamanho) ? -1 : i;
    }

    // métodos get e set
    
    void setResposta(int valor){
        res = valor;
    }
    int getResposta(){
        return res;
    }
    int getOpcao(){
        return opcao;
    }
};

int main(){
    Busca bl;
    
    while(1){
        bl.menu();
        if (bl.getOpcao() == 1){
            bl.insereElemento();
        }else if(bl.getOpcao() == 2){
            bl.apresentarVetor();
        }else if(bl.getOpcao() == 3){
            int sentinela;
            cout << "Qual valor a ser buscado?" << endl;
            cin >> sentinela;
            bl.setResposta(bl.buscaLinear(sentinela));
            cout << "O elemento " << sentinela << " foi encontrado na posicao " << bl.getResposta() << endl;
        }else{
            cout << "Saindo do programa." << endl;
            break;
        }

    }
    
    return 0;
}

