/*
	Name: Pilha.cpp
	Author: Isabela Fagundes
	Date: 12/04/23 09:51
	Description: Programa para demonstrar o funcionamento do conceito de Pilhas - LIFO
*/

#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

//sess�o de prototipa��o
void push(char); //inserir elemento
char pop(); //retira um elemento
int isEmpty(); //se est� vazia
int isFull();// se est� cheia
char top(); //aponta pro elemento do topo da lista
void listarPilha(); //imprime elementos da pilha
void conversorBinario();
void exibirNumBinario();

//vari�veis globais
char pilha[10];
int topo = -1; //recebe -1 para indicar que ele n�o est� apontando pra nenhum elemento da pilha



main (){
	setlocale(LC_ALL, "Portuguese");

	
	while(1){
		
	int opc = 0;
	printf("\n1 ==> Inserir elemento\n2 ==> Retirar elemento\n3 ==> Exibir elementos\n4 ==> Conversor bin�rio\n5 ==> Sair");
	printf("\n\nInsira uma op��o: ");
	scanf("%d", &opc);
		
		switch(opc){
			case 1: char e;
					e = ' ';
					printf("Insira um caractere na pilha de letras: ");
					fflush(stdin); //limpa o buffer de sa�da
					scanf("%c", &e);
					push(e);
					break;
			case 2: pop();
					break;
			case 3: listarPilha();
					break;
			case 4: conversorBinario();
					break;
			case 5: exit(0);
			default: puts("Op��o inv�lida, digite novamente!");
		}
		
		puts("\n>>>>>> Pressione qualquer tecla :)");
		getch();
		system("cls");
	}
	
}//fim do programa

void push(char elem){
	
	if(isFull() == 1) puts("\nPilha cheia =====> Stack Overflow");
	else {
		topo++;
		pilha[topo] = elem; //adciona o elemento no topo
	}
	
}//fim do push

char pop(){
	
	if(isEmpty() == 1) puts("\nPilha vazia ====>");
	else{
		char elemento;
		elemento = pilha[topo];
		topo--;
		return elemento; //retira e retorna o elemento do topo
	}
	
}

int isEmpty(){
	
	if(topo == -1) return 1;
	else return 0;
	
}//fim do isEmpty()

int isFull(){
	
	if(topo == sizeof(pilha) - 1) return 1;
	else return 0;
	
}//fim do isFull()

char top(){
	
	return pilha[topo];
	
}//fim do top()

void listarPilha(){
	
	puts("\n Conte�do da Pilha: ");
	if(isEmpty() == 1) puts("====> Pilha vazia");
	else for(int i = topo; i >= 0; i--){
		
		printf("\n %d | %c |", i, pilha[i]);//mostra o �ndice | caractere
		
	}
	
}//fim do listar

void conversorBinario(){
	
	int numBaseDez = 0;
	printf("Digite um n�mero na base 10: ");
	scanf("%d", &numBaseDez);
	
	while(numBaseDez >= 2){
		
		push(numBaseDez%2); //insere o resto na pilha
		numBaseDez = numBaseDez/2; //efetua divis�o por 2 enquando for maior ou igual a 2
		
	}
	
	push(numBaseDez);
	exibirNumBinario();
	
}

void exibirNumBinario(){
	
	puts("Enquivalente Bin�rio: ");
	while(isEmpty() == 0){
		
		int elemento;
		elemento = pop(); //pop retorna o �ltimo a entrar
		printf("%d", elemento);
		//char pode ser exibido com %c (mostrando seus caracteres alfab�ticos)
		//ou %d (mostrando seus caracteres num�ricos).
		
	}
	
}
