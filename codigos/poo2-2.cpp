#include <iostream>
#include <fstream>
using namespace std;
#include <string>

class Pessoa{
    string nome;
    string sobrenome;
    public:
    string getNome(){return nome;}
    void setNome(string n){nome = n;}
    string getSobrenome(){return sobrenome;}
    void setSobrenome(string n){sobrenome = n;}
};

class Empregado : public Pessoa{
    float vencimentoBase;

    public:
        float calcularSalario(){return  vencimentoBase;}
        void setVencimentoBase(float v){vencimentoBase = v;}
        float getVencimentoBase(){return vencimentoBase;}
};

class Vendedor : public Empregado{
    float valorVendas;
    float comissao;

    public:
    float calcularSalario(float com, float vend){
        float salario = getVencimentoBase() + vend * com;
        return salario;
    };
    void setValorVendas(float v){valorVendas = v;}
    void setComissao(float c){comissao = c;}
    float getValorVendas(){return valorVendas;}
    float getComissao(){return comissao;}

};

int main(){


    Vendedor v1;
    v1.setNome("Andre");
    v1.setSobrenome("Silva");
    v1.setValorVendas(10000.0);
    v1.setVencimentoBase(2000.0);

    float s = v1.calcularSalario(0.20, 10000.0);
    cout << "Salario de " << v1.getNome() << " = " << s << endl;

    return 0;
}