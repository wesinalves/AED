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
	cout << "Insira os " << n << " elementos do array separados por espa�o" << endl;
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
	cout << "O array ordenado �: " << endl;
	for (int i=0; i<n; i++){
		cout << array[i] << "\t";
	}
	cout << endl;
	return 0;
	 
}


void mergeSort(int vetor[], int l, int r) //Recebe o array e seus limites como par�metro
										//e sub-divide o array em dois sub-arrays
{ //Ordena cada um individualmente e, por fim, junta os resultados
    if (l < r) 
    {  
        int m = (l+r)/2; //Encontra o piv� do array
  
        /*Ordena a primeira e a segunda metade dos arrays, depois junta os resultados!
        Se l < r, o c�digo de mergesort reduz a inst�ncia v[l..r]
		do problema ao par de inst�ncias v[l..m] e v[m+1..r]. Essas duas inst�ncias s�o estritamente
		menores que a inst�ncia original, uma vez que l < m < r gra�as � condi��o l < r.
		Assim, por hip�tese de indu��o, o vetor v[l..m] estar� em ordem crescente no fim da linha 51
		e o vetor v[m+1..r] estar� em ordem crescente no fim da linha 52. Portanto, no fim da linha 53,
		de acordo com a documenta��o da classe merge(), o vetor v[l..r] estar� em ordem crescente*/
        
		mergeSort(vetor, l, m); 
        mergeSort(vetor, m+1, r); 
        merge(vetor, l, m, r); 
    } 
} 

void merge(int vetor[], int l, int m, int r)  //Recebe o array original, seus dois limites
									//e o piv� para juntar os dois sub-arrays ordenados
									//em um �nico array ordenado
{                                           
    int i, j, k;  
    int n1 = m - l + 1; //Encontra o tamanho do primeiro sub-array
    int n2 =  r - m; // Encontra o tamanho do segundo sub-array
  
    int L[n1], R[n2]; //Cria arrays tempor�rios
    
    // Copia o sub-array esquerdo em L
    for (i = 0; i < n1; i++){
        L[i] = vetor[l + i]; 
    }
    // Copia o sub-array direito em R
    for (j = 0; j < n2; j++){
        R[j] = vetor[m + 1+ j];
		}
  
    i = 0; // �ndice de in�cio do primeiro sub-array 
    j = 0; // �ndice de in�cio do segundo sub-array 
    k = l; // �ndice de in�cio do sub-array da uni�o
    while (i < n1 && j < n2) //Para todos os elementos dos sub-arrays 
    { 
        if (L[i] <= R[j])  // Compara os elementos do primeiro e do segundo sub-array
        { 
        	/* Como os sub-arrays s�o ordenados em ordem crescente, come�a verificando se
			o menor elementodo primeiro sub-array � menor do que o menor elemento do
        	segundo sub-array. Enquanto for menor, verifica se os elementos posteriores tamb�m s�o menores */ 
            vetor[k] = L[i]; // Constroi o vetor da uni�o (vetor) em ordem crescente
            i++; 
        } 
        else
        { 
        /* Caso o elemento do segundo sub-array seja menor que o do primeiro,
		verifica-se o contr�rio (at� que os elementos do segundo sub-array 
		sej�o menores do que os elementos do primeiro, variando, para isso, apenas o j*/ 
            vetor[k] = R[j];  // Constroi o vetor da uni�o (vetor) em ordem crescente
            j++; 
        } 
        k++; 
    } 
  
    /*Um dos sub-arrays acabar� primeiro do que o outro, isto �,
	ter� seu maior elemento menor do que algum elemento do outro 
    Dessa forma, precisamos copiar tamb�m os elementos restantes para o array de uni�o*/ 
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

