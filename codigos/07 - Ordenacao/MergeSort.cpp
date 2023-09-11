#include <iostream>

using namespace std;

void mergeSort(int vetor[], int l, int r);
void merge(int vetor[], int l, int m, int r);

int main(){
	setlocale(LC_ALL,"");
	int n;
	do{
	cout << "Entre com o tamanho do array" << endl;
	cin >> n;
	}while(n<=0);
	cout << "Insira os " << n << " elementos do array separados por espaço" << endl;
	int array[n];
	for (int i=0; i<n; i++){
		cin >> array[i];
	}
	cout << "O array inserido foi: " << endl;
	for (int i=0; i<n; i++){
		cout << array[i] << "\t"; 
	}
	cout << endl;
	mergeSort(array,0,n-1);
	cout << "O array ordenado é: " << endl;
	for (int i=0; i<n; i++){
		cout << array[i] << "\t";
	}
	cout << endl;
	return 0;
	 
}


void mergeSort(int vetor[], int l, int r) //Recebe o array e seus limites como parâmetro
										//e sub-divide o array em dois sub-arrays
{ //Ordena cada um individualmente e, por fim, junta os resultados
    if (l < r) 
    {  
        int m = (l+r)/2; //Encontra o pivô do array
  
        /*Ordena a primeira e a segunda metade dos arrays, depois junta os resultados!
        Se l < r, o código de mergesort reduz a instância v[l..r]
		do problema ao par de instâncias v[l..m] e v[m+1..r]. Essas duas instâncias são estritamente
		menores que a instância original, uma vez que l < m < r graças à condição l < r.
		Assim, por hipótese de indução, o vetor v[l..m] estará em ordem crescente no fim da linha 51
		e o vetor v[m+1..r] estará em ordem crescente no fim da linha 52. Portanto, no fim da linha 53,
		de acordo com a documentação da classe merge(), o vetor v[l..r] estará em ordem crescente*/
        
		mergeSort(vetor, l, m); 
        mergeSort(vetor, m+1, r); 
        merge(vetor, l, m, r); 
    } 
} 

void merge(int vetor[], int l, int m, int r)  //Recebe o array original, seus dois limites
									//e o pivô para juntar os dois sub-arrays ordenados
									//em um único array ordenado
{                                           
    int i, j, k;  
    int n1 = m - l + 1; //Encontra o tamanho do primeiro sub-array
    int n2 =  r - m; // Encontra o tamanho do segundo sub-array
  
    int L[n1], R[n2]; //Cria arrays temporários
    
    // Copia o sub-array esquerdo em L
    for (i = 0; i < n1; i++){
        L[i] = vetor[l + i]; 
    }
    // Copia o sub-array direito em R
    for (j = 0; j < n2; j++){
        R[j] = vetor[m + 1+ j];
		}
  
    i = 0; // Índice de início do primeiro sub-array 
    j = 0; // Índice de início do segundo sub-array 
    k = l; // Índice de início do sub-array da união
    while (i < n1 && j < n2) //Para todos os elementos dos sub-arrays 
    { 
        if (L[i] <= R[j])  // Compara os elementos do primeiro e do segundo sub-array
        { 
        	/* Como os sub-arrays são ordenados em ordem crescente, começa verificando se
			o menor elementodo primeiro sub-array é menor do que o menor elemento do
        	segundo sub-array. Enquanto for menor, verifica se os elementos posteriores também são menores */ 
            vetor[k] = L[i]; // Constroi o vetor da união (vetor) em ordem crescente
            i++; 
        } 
        else
        { 
        /* Caso o elemento do segundo sub-array seja menor que o do primeiro,
		verifica-se o contrário (até que os elementos do segundo sub-array 
		sejão menores do que os elementos do primeiro, variando, para isso, apenas o j*/ 
            vetor[k] = R[j];  // Constroi o vetor da união (vetor) em ordem crescente
            j++; 
        } 
        k++; 
    } 
  
    /*Um dos sub-arrays acabará primeiro do que o outro, isto é,
	terá seu maior elemento menor do que algum elemento do outro 
    Dessa forma, precisamos copiar também os elementos restantes para o array de união*/ 
    while (i < n1) //Se o segundo sub-array tiver acabado primeiro,
	//copia os elementos restantes do primeiro sub-array
    { 
        vetor[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) // Se o primeiro sub-array tiver acabado primeiro,
	//copia os elementos restantes do primeiro sub-array
    { 
        vetor[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

