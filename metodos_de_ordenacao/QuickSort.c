/*
	Name: QuickSort.c
	Author: Isabela Fagundes
	Date: 17/05/23 10:17
	Description: Implementação do método de ordenação Quick Sort 
*/

#include <stdio.h>
#include <conio.h>

//Prototipação das funções
void quickSort(int *, int, int);
int particionar(int *, int, int);

int trocas, comparacoes = 0;

main() {
	
	int vet[] = {13, 215, 7, -8, 4, 170, 8, 20};
	int i, tam;
	tam = sizeof(vet) / sizeof(int);
	
	puts("----> Vetor desordenado:\n");
	for(i = 0; i < tam; i++) printf("%d |", vet[i]);
	
	quickSort(vet, 0, tam - 1);
	
	puts("\n-----> Vetor ordenado: by Quick Sort\n");
	for(i = 0; i < tam; i++) printf("%d |", vet[i]);
	
	printf("\n\n----> Trocas: %d", trocas);
}

void quickSort(int *vet, int inicio, int fim){
	
	int pivo;
	if(fim > inicio) {
		pivo = particionar(vet, inicio, fim);
		quickSort(vet, inicio, pivo - 1); //do início até o pivô
		quickSort(vet, pivo + 1, fim);//do pivô até o fim
	}
}

int particionar(int *vet, int inicio, int fim) {
	
	int esquerda, direita, pivo, aux;
	esquerda = inicio;
	direita = fim;
	pivo = vet[inicio]; // considerando o pivo como o primeiro elemento do vetor
	
	while(esquerda < direita) {
		
		while(vet[esquerda] <= pivo) esquerda++; //pivô até fim
		
		while(vet[direita] > pivo) direita--; //fim até pivô
		
		//Verifica se o da esquerda é menor que o da direita e efetua a troca
		if(esquerda < direita) {
			aux = vet[esquerda];
			vet[esquerda] = vet[direita];
			vet[direita] = aux;
			trocas++;
		}
	}
	
	vet[inicio] = vet[direita];
	vet[direita] = pivo;
	return direita;
	
}


