/*
	Name: Fila.cpp
	Author: Isabela Fagundes
	Date: 05/04/23 09:41
	Description: Implementação do conceito de Filas - FIFO
*/

#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>

//prototipação
void inserir(int); // inserir um elemento no fim da fila
int retirar(); // retira um elemento do começo da fila
int estaVazio(); // testa se a fila está vazia
int estaCheio(); // testa se a fila está cheia
void imprimirFila(); // imprimir fila

//variáveis globais
int inicio, fim, total;
int senhas[5]; //estrutura de fila com 5 elementos

main(){
	setlocale(LC_ALL, "Portuguese");
	inicio = 0;
	fim = 0;
	total = 0;
	
	
	while(1){
		int menu = 0;
		printf("1- Inserir \n2 - Retirar\n3 - Imprimir\n4 - Sair");
		printf("\nOpcao: ");
		scanf("%d", &menu);
		switch(menu){
		
			case 1: int e;
					e = 0;
					printf("Dgite o elemento a incluir: ");
					scanf("%d", &e);
					inserir(e);
					break;
			case 2: retirar();
					break;
			case 3: imprimirFila();
					break;
			case 4: exit(0);
			default: printf("Opcao inválida!");				
		}
		puts("\n>>>>>> Pressione qualquer tecla");
		getch(); //captura o pressionar de qualquer tecla
		system("cls");//limpa a tela
		
	}
	
}// fim main

// inserir um elemento no fim da fila
void inserir(int elem){
	
	if(estaCheio() == 1) puts("A fila está cheia!");
	else {
		
		senhas[fim] = elem; //insrção de um elemento no final da fila
		
		//com este cálculo podemos descobrir a posição após o último elemento, assim definindo o novo fim
		fim = (fim+1)%5;
		total++;
	}
	
	
}

// retira um elemento do começo da fila
int retirar(){
	
	if(estaVazio() == 1) puts("A fila está vazia!");
	else {
		
		int elemento;
		elemento = senhas[inicio]; 
		
		//com este cálculo podemos descobrir a posição após o elemento inicial, assim definindo o novo início
		inicio = (inicio+1)%5; 
		total--;
		return elemento;
		
	}
	
}

// testa se a fila está vazia
int estaVazio(){
	
	if(total == 0) return 1; //true
	else return 0; //false
	
}

 // testa se a fila está cheia
 int estaCheio(){
 	
 	if(total == 5) return 1;//true
 	else return 0;//false
 	
 }
 
 // imprimir fila
 void imprimirFila(){
 	
 	printf("\n");
 	int cont, i;
 	
 	for(cont = 0, i = inicio; cont < total; cont++){
 		
 		printf("%d | ", senhas[i++]);
 		if(i == 5) i = 0;
 		
	 }
 }

