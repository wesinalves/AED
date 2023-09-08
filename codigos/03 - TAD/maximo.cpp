#include <iostream>
#include <vector>

using namespace std;

class Ponto{ // Cria uma estrutura de dados para trabalhar com um ponto bidimensional
	private:
		float x;
		float y;
	public:
		Ponto(float abscissa, float ordenada){
			x = abscissa;
			y = ordenada;
		} // Permite a definiçãoo de um ponto, dadas suas coordenadas
		Ponto(){
			x = 0;
			y = 0;
		} // Define (0,0) como inicialização default dos pontos
		~Ponto(){};
		void print(){
			cout << x << "\t" << y << endl;
		} // Imprime as coordenadas de um ponto separadas por uma tabulação
		float getX(){
			return x; 
		}	// Permite o acesso ao valor da coordenada x do ponto
		float getY(){
			return y;
		} // Permite o acesso ao valor da coordenada y do ponto
};

vector<Ponto> maximo (vector<Ponto> Pontos); // Retorna os pontos de máximo ao receber um conjunto de pontos
bool domina (Ponto P1, Ponto P2); // Verifica se um ponto domina outro ponto

int main(){
	setlocale(LC_ALL,""); // Habilita caracteres especiais
	
	char continuar;
	vector<Ponto> Pontos;
	Ponto draft;
	float x, y;
	
	cout << "Insira um conjunto de pontos para encontrar o máximo" << endl;
	do{
	cout << "Entre com as coordenadas do ponto, no formato (x, y), separadas por espaço" << endl;
	cin >> x >> y;
	cout << "Deseja inserir um novo ponto? (s/n)" << endl;
	cin >> continuar;
	draft = Ponto(x,y);	// Converte o par de inteiros recebidos para um ponto
	Pontos.push_back(draft); // Adiciona o ponto novo ponto ao conjunto de pontos cujo máximo ser� encontrado 
	}while(continuar=='S' || continuar=='s'); // Permite a adição de novos pontos ou a execução do progrmaa de determinação do máximo
	
	maximo(Pontos);
	return 0;
}

vector<Ponto> maximo (vector<Ponto> Pontos){
	bool dominado = false; // Verifica se o ponto já foi dominado
	vector<Ponto> maximos; // Armazena todos os pontos de máximo
	
	for (int i=0; i<Pontos.size(); i++){
		dominado = false;
		for (int j=0; dominado==false && j<Pontos.size(); j++){
			if (i!=j && domina(Pontos[j], Pontos[i])){
				dominado = true;
			}
		}
		// Compara todos cada ponto com todos os outros pontos e verifica se há algum ponto que o domina. 
		// Caso um ponto não seja dominado por nenhum outro ponto, ele é adicionado ao conjunto de máximos.
		if (dominado==false){
			maximos.push_back(Pontos[i]);
		}
	}

	cout << "Os Pontos máximos são:" << endl; // Imprime na tela os pontos máximos
	for(int i=0; i<maximos.size(); i++){
		maximos[i].print();
	}
	return maximos; // Retorna o conjunto de máximos
}


bool domina (Ponto P1, Ponto P2){
	return (P1.getX()>=P2.getX() && P1.getY()>=P2.getY()); // Verifica o domínio
}