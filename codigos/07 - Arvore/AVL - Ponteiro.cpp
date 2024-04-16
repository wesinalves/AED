#include <iostream>

using namespace std;
  
class ArvoreAVL 
{ 
	public:
    int valor; 
    ArvoreAVL *esquerda; 
    ArvoreAVL *direita; 
    int altura;
	int determinarAltura(); 
	ArvoreAVL *RotacionarParaDireita();
	ArvoreAVL *RotacionarParaEsquerda();
	ArvoreAVL* inserirElemento(int Elemento);
	int determinarDiferenca();
	void exibirArvore(); 
	int buscarElemento(int Elemento);
};   

int max(int a, int b); 
  
/* Fun��o auxiliar que aloca uma nova ArvoreAVL com
ponteiros de valor NULL a esquerda e a direira. */
ArvoreAVL* novaArvoreAVL(int Elemento) 
{ 
    ArvoreAVL* NovaFolha = new ArvoreAVL; 
    NovaFolha->valor     = Elemento; 
    NovaFolha->esquerda  = NULL; 
    NovaFolha->direita   = NULL; 
    NovaFolha->altura    = 1; 
    return NovaFolha; 
} 
  
  
// Encontra a diferen�a de altura entre as sub-�rvores
int ArvoreAVL::determinarDiferenca() 
{ 
    if (this == NULL) 
        return 0; 
    return (this->esquerda)->determinarAltura() - (this->direita)->determinarAltura(); 
} 

/*
Fun��o recursiva para inserir um valor na sub�rvore
com raiz em ArvoreAVL e retorna a nova raiz da sub�rvore*/
ArvoreAVL* ArvoreAVL::inserirElemento(int Elemento) 
{ 
    /* 1. Insere o novo elemento */
    // if (this == NULL)

	if (this == NULL){
    	ArvoreAVL *NovaFolha = novaArvoreAVL(Elemento);
    	/*this->valor = NovaFolha->valor;
    	this->esquerda = NovaFolha->esquerda;
    	this->direita = NovaFolha->direita;
    	this->altura = NovaFolha->altura;
    	this->isEmpty = false;*/
        return NovaFolha; 
		}
  
    if (Elemento < this->valor){
        this->esquerda  = (this->esquerda)->inserirElemento(Elemento); 
    }
    else if (Elemento > this->valor){
        this->direita = (this->direita)->inserirElemento(Elemento); 
    }
    else // N�o � permitido adicionar valores iguais
        return this; 
  
    /* 2. Atualiza a altura da �rvore */
    this->altura = 1 + max((this->esquerda)->determinarAltura(), 
                           (this->direita)->determinarAltura()); 
  
    /* 3. Atualiza a diferen�a entre as sub-�rvores */
    int diferenca = determinarDiferenca(); 
  
    // Se a �rvore AVL estiver desbalanceada, � necess�rio realizar a rota��o 
    // Para isso, verificaremos em qual dos casos estamos:  
  
    // Esquerda-Esquerda
    if (diferenca > 1 && Elemento < this->esquerda->valor) 
        return RotacionarParaDireita(); 
  
    // Direita-Direita
    if (diferenca < -1 && Elemento > this->direita->valor) 
        return RotacionarParaEsquerda(); 
  
    // Esquerda-Direita 
    if (diferenca > 1 && Elemento > this->esquerda->valor) 
    { 
        this->esquerda =  (this->esquerda)->RotacionarParaEsquerda(); 
        return RotacionarParaDireita(); 
    } 
  
    //Direita-Esquerda
    if (diferenca < -1 && Elemento < this->direita->valor) 
    { 
        this->direita = (this->direita)->RotacionarParaDireita(); 
        return RotacionarParaEsquerda(); 
    } 
  
    return this; 
} 
  
int main() 
{ 
	setlocale(LC_ALL,"");
	ArvoreAVL *root = NULL;
  	cout << "Ol�" << endl;
  	root = root->inserirElemento(10); 
    root = root->inserirElemento(20); 
    root = root->inserirElemento(30); 
    root = root->inserirElemento(40); 
    root = root->inserirElemento(50);
  	root = root->inserirElemento(25); 
  
  /*
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */
  cout << "A �rvore inserida foi" << endl; 
    root->exibirArvore(); 
    cout << endl;
	root->buscarElemento(25);
	root->buscarElemento(37);
  
  return 0; 
} 


int ArvoreAVL::determinarAltura() 
{ 
    if (this == NULL){
        return 0; 
    }
    return this->altura; 
} 

int max(int a, int b) 
{ 
	if (a > b){
		return a;
	}
	else{
		return b;
	}
} 

// Rotaciona a sub-�rvore para a direita no crit�rio AVL 
ArvoreAVL *ArvoreAVL::RotacionarParaDireita() 
{ 
    ArvoreAVL *x = this->esquerda; 
    ArvoreAVL *T2 = x->direita; 
  
    // Inverte as sub-�rvores
    x->direita = this; 
    this->esquerda = T2; 
  
    // Atualiza as alturas de cada sub-�rvore 
    this->altura = max((this->esquerda)->determinarAltura(), (this->direita)->determinarAltura())+1; 
    x->altura = max((x->esquerda)->determinarAltura(), (x->direita)->determinarAltura())+1; 
  
    // Devolve a nova ra�z
    return x; 
} 
  
// Rotaciona a sub-�rvore para a esquerda no crit�rio AVL
ArvoreAVL *ArvoreAVL::RotacionarParaEsquerda() 
{ 
    ArvoreAVL *y = this->direita; 
    ArvoreAVL *T2 = y->esquerda; 
  
    // Inverte as sub-�rvores
    y->esquerda = this; 
    this->direita = T2; 
  
    // Atualiza as alturas de cada sub-�rvore 
    this->altura = max((this->esquerda)->determinarAltura(), (this->direita)->determinarAltura())+1; 
    y->altura = max((y->esquerda)->determinarAltura(), (y->direita)->determinarAltura())+1; 
  
    // Devolve a nova ra�z da sub-�rvore
    return y; 
} 

void ArvoreAVL::exibirArvore()
{ 
    if(this != NULL) 
    { 
        cout << this->valor << "\t"; 
        (this->esquerda)->exibirArvore(); 
        (this->direita)->exibirArvore(); 
    } 
} 


int ArvoreAVL::buscarElemento(int Elemento){
	while(this != NULL) { 
		if (this->valor == Elemento){
			cout << "O valor procurado est� presente na �rvore" << endl;
			return Elemento;
		} 
		else{
			if(Elemento < this->valor){
				(this->esquerda)->buscarElemento(Elemento);
				return Elemento;
			}
			else{
				(this->direita)->buscarElemento(Elemento);
				return Elemento;
			}
		}
	}
	cout << "O valor procurado n�o est� presente na �rvore" << endl;
	return -1;
}    


