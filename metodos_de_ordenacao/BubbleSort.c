/*
	Name: BubbleSort.c
	Author: Isabela Fagundes
	Date: 07/05/23 21:17
	Description: Código implementado para demonstrar o método de ordenação
	             Bubble Sort.
*/


#include <stdio.h>
#include <conio.h>

main(){
	
	int senha[] = {7,202,14,25,17,8,13,19};
	int i, tam, aux, trocas, comp;
	
	tam = sizeof(senha)/sizeof(int);

	
	puts("Vetor desordenado:");
	for(i = 0; i < tam; i++)
		printf(" %d |", senha[i]);
	
	
	if(senha[i] > tam)
	i = 0;
		
	while(tam > 0){
			
		for(i = 0; i < tam - 1; i++){
				
			if(senha[i] > senha[i+1]){
				aux = senha[i];
				senha[i] = senha[i+1];
				senha[i+1] = aux;
				trocas++;
			}
			
			comp++;
		}
		
		tam--;
	}
	

	tam = sizeof(senha)/sizeof(int);
	puts("\n\nVetor ordenado ----> by Bubble Sort:");
	for(i = 0; i < tam; i++){
		printf(" %d |", senha[i]);
	}
	
	printf("\n\n-> Trocas: %d", trocas);
	printf("\n-> Comparacoes: %d", comp);
}
