/*
	Name: InsertionSort.c
	Author: Isabela Fagundes
	Date: 14/05/23 16:15
	Description: Exemplo de implementa��o do m�todo de ordena��o Insertion Sort
*/

#include <stdio.h>
#include <conio.h>

//Sess�o de prototipa��o
void insertionSort(int *, int);

main() {
	int vet[] = {13, 215, 13, -8, 4, 170, 8, 20};
	int tam = sizeof(vet) / sizeof(int);
	int i;
	
	puts("-----> Vetor desordenado: \n");
	for(i = 0; i < tam; i++) printf("%d |", vet[i]);
	
	insertionSort(vet, tam);
	
	puts("\n-----> Vetor ordenado: by Insertion Sort\n\n");
	for(i = 0; i < tam; i++) printf("%d |", vet[i]);
}

void insertionSort(int vet[], int tam) {
	
	int i, j, chave;
	
	//i aponta para a segunda posi��o
	for(i = 1; i < tam; i++){
		chave = vet[i];
		j = i - 1; //j aponta para a posi��o anterior de i
		
		//Enquanto j for maior igual a 0 e a posi��o j for maior que a posi��o de i marcada pela chave
		while(j >= 0 && vet[j] > chave){
			vet[j+1] = vet[j];
			j = j - 1;
		}
		
		vet[j+1] = chave;
		
	}
	
}
