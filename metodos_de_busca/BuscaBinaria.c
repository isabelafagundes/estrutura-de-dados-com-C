/*
	Name: BuscaBinaria.cpp 
	Author: Isabela Fagundes
	Date: 24/05/23 09:58
	Description: Implementa��o do algoritmo de busca bin�ria
				ou logar�tmica.
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

//sess�o de prototipa��o
void buscaBinaria(int *, int, int);
void insertionSort(int *, int);

//vari�veis globais
int achou = 0; 

main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	int vet[100];
	int tamanho = sizeof(vet)/sizeof(int);
	int elemento = 0;
	
	srand(time(NULL));
	for(int i = 0; i < tamanho; i++) vet[i] = rand()%100; //Carregar o vetor com n�meros aleat�rios
	
	puts("Conte�do do vetor desordenado: ");
	for(int i = 0; i < tamanho; i++){
		printf("%d | ", vet[i]);
	}
	
	puts("\n\n");
	
	insertionSort(vet, tamanho);
	
	puts("Conte�do do vetor ordenado: ");
	for(int i = 0; i < tamanho; i++){
		printf("%d | ", vet[i]);
	}
	
	printf("\n\nInsira um elemento para ser buscado: ");
	scanf("%d", &elemento);
	
	buscaBinaria(vet, elemento, tamanho);
		
}

void buscaBinaria(int *vetor, int elemento, int tamanho){
	
	int inicio, meio, fim;
	inicio = 0;
	fim = tamanho-1; //�ltimo �ndice
	int comparacoes = 0;
	
	while(inicio <= fim) {
		
		meio = (inicio + fim)/2;
		comparacoes++;
		//O elemento � igual a meio?
		if(elemento == vetor[meio]) {
			achou = 1;
			break;	
		} 
		else if(elemento < vetor[meio]) fim = meio - 1;
		else inicio = meio + 1;
	}
	
	if(achou == 0) puts("\n---> Elemento n�o encontrado...");
	else printf("\n---> O elemento %d foi localizado com sucesso! Foi encontrado na posi��o: %d \n", elemento, (meio+1));
	
	printf("\nO n�mero de compara��es foi: %d", comparacoes);
	
}

void insertionSort(int vet[], int tam) {
	
	int i, j, chave;
	
	for(i = 1; i < tam; i++){
		chave = vet[i];
		j = i - 1; 
		
		while(j >= 0 && vet[j] > chave){
			vet[j+1] = vet[j];
			j--;
		}
		
		vet[j+1] = chave;	
	}
}
