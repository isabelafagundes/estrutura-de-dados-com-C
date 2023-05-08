/*
	Name: SelectionSort.c
	Author: Isabela Fagundes 
	Date: 03/05/23 09:58
	Description: Implementação do algoritmo de ordenação por
				 seleção - 1964
				 
*/

#include <stdio.h>

main(){
	
//	int vet[] = {7,202,14,25,17,8,13,19};
	int vet[] = {7, 8, 13, 14, 17, 19, 25, 202};
//	int vet[] = {13, 215, 13, -8, 4, 170, 8, 20};
	int tam = sizeof(vet)/sizeof(int);
	int i, j, menor, aux;
	int trocas, comparacoes = 0; //variável que armazena o total de trocas e comparações feitas
	
	puts("Vetor desordenado ---->\n");
	for(i = 0; i < tam; i++)
	{
		printf("%d | ", vet[i]);
	}
	
	for(i = 0; i < tam; i++)
	{
		
		menor = i; //Assume que o primeiro elemento é o menor
		
		/*  j recebe 1 + 1 pois estamos 'selecionando' o primeiro item e faremos
		a busca do menor no range de elementos que precede este elemento selecionado.  */	
		for(j = i + 1; j < tam; j++)
		{
			
			if(vet[j] < vet[menor]) //se o item do range de busca for menor que o indice do item selecionado
				menor = j;
			
			comparacoes++;	
		}
		
		comparacoes++;		
		if(i != menor) //se o indice de i é diferente do indice do menor
		{
			aux = vet[i];
			vet[i] = vet[menor];
			vet[menor] = aux;
			trocas++;
		}
		
	}
	
	tam = sizeof(vet)/sizeof(int);
	
	puts("\n\nVetor ordenado ----> by Selection Sort:\n");
	for(i = 0; i < tam; i++)
	{
		printf("%d | ", vet[i]);
	}
	
	printf("\n\n\n-> Numero de trocas: %d", trocas);
	printf("\n-> Numero de comparacoes: %d", comparacoes);
		
}
