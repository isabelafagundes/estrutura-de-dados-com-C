/*
	Name: MergeSort.c
	Author: Isabela Fagundes
	Date: 14/05/23 15:58
	Description: Implementação do método de ordenação Merge Sort
*/


#include <stdio.h>
#include <conio.h>

//prototipação
void merge(int *, int, int, int);
void mergeSort(int *, int, int);

main () {
	int vet[] = {13, 215, 7, -8, 4, 170, 8, 20};
	int inicio, fim, i;
	inicio = 0;
	fim = sizeof(vet) / sizeof(int) - 1;
	
	puts("----> Vetor desordenado:\n");
	for(i = 0; i <=fim; i++) printf("%d |", vet[i]);
	
	mergeSort(vet, inicio, fim);
	
	puts("\n-----> Vetor ordenado: by Merge Sort\n\n");
	for(i = 0; i <= fim; i++) printf("%d |", vet[i]);
		
}

//-----> Divisão em dois subvetores
void mergeSort(int vet[], int inicio, int fim){
	
	//caso inicio = fim, o vetor tem tamanho 0
	if(inicio < fim){
		//-----> Divisão
		int meio = (inicio + fim) / 2;
		mergeSort(vet, inicio, meio); //divisão em subvetor1
		mergeSort(vet, meio + 1, fim); //divisão em subvetor2
		
		//-----> Conquista: Intercala as duas metades que vão estar ordenadas
		merge(vet, inicio, meio, fim);
	}
	
}

void merge(int vet[], int inicio, int meio, int fim){
int comparacao1 = inicio;
int comparacao2 = meio + 1;
int comparacaoAux = 0;
int tam = (fim - inicio) + 1;
int vetAux[tam];

while(comparacao1 <= meio && comparacao2 <= fim){
	
	//-----> Intercalação
	
	//se o inicio da primeira metade for menor que o inicio da segunda metade
	if(vet[comparacao1] < vet[comparacao2]){
		vetAux[comparacaoAux] = vet[comparacao1]; //então o colocamos no vetor auxiliar
		comparacao1++;
	} else {
		vetAux[comparacaoAux] = vet[comparacao2]; //senão colocamos o início da segunda metade no vetor auxiliar
		comparacao2++;
	}
	
	comparacaoAux++;
	
	
	}//fim do while
	
	// -----> Copiando o resto do subvetor que não terminou
	
	//verificando se ainda existe elementos na primeira metade
	while(comparacao1 <= meio){
		vetAux[comparacaoAux] = vet[comparacao1];
		comparacaoAux++;
		comparacao1++;
	}
	
	//verificando se ainda existe elementos na segunda metade
	while(comparacao2 <= fim){
		vetAux[comparacaoAux] = vet[comparacao2];
		comparacaoAux++;
		comparacao2++;
	}
	
	//-----> Copiando o vetor auxiliar para o vetor original
	
	for(comparacaoAux = inicio; comparacaoAux <= fim; comparacaoAux++){
		vet[comparacaoAux] = vetAux[comparacaoAux - inicio];
	}
	
}
