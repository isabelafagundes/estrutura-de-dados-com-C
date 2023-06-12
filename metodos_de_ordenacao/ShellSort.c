/*
	Name: ShellSort.c
	Author: Isabela Fagundes
	Date: 17/05/23 09:44
	Description: Implementação do método de ordenação Shell Sort.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//Sessão de prototipação
void shellSort(int *, int);

main() {
	int vet[10];
	int i, tam;
	tam = sizeof(vet)/sizeof(int);
	
	srand(time(NULL)); //Retira informações da hora do sistema
	
	for(i = 0; i < tam; i++) vet[i] = rand() % 10; //números aleatórios de 1 a 10
	
	puts("-----> Vetor desordenado: \n");
	for(i = 0; i < tam; i++) printf("%d |", vet[i]);
	
	shellSort(vet, tam);
	
	puts("\n\n-----> Vetor ordenado: by Shell Sort \n");
	for(i = 0; i < tam; i++) printf("%d |", vet[i]);
}

void shellSort(int *vet, int size) {
	int i, j, valor;
	int h = 1; //variável do salto
	
	while(h < size){
		h = 3 * h + 1;
	}
	
	while(h > 0){
		
		for(i = h; i < size; i++){
			valor = vet[i];
			j = i;
			while(j > h - 1 && valor <= vet[j-h]){
				vet[j] = vet[j - h];
				j = j - h;
			}
			vet[j] = valor;
		}
		
		h = h/2;
		
	}
}

