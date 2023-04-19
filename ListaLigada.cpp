/*
	Name: ListaLigada.cpp
	Author: Isabela Fagundes
	Date: 22/03/23 09:47
	Description: Implementação da lista encadeada simples
*/

// Nó é o elemento que engloba os valores + campo para apontar para o próximo Nó
// malloc() (memory alocation) -> Aloca na memória
// sizeof() (tamanho de) -> Retorna o tamanho de um tipo

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

//Estrutura para um Nó (node) da lista, contendo duas informações:
typedef struct No{
	
	int valor;
	struct No *proximo; //Guarda o endereço de memória no próximo Nó
};

//Estrutura que é a própria Lista ligada com vários Nós:
typedef struct Lista{
	
	No *inicio, *fim; //Guarda endereço de memório do ínicio e do fim
	int tamanho; //Tamanho da lista
};

//Função para inserir elementos no início da lista:
void inserirInicio(Lista *lista, int vlr){
	
//tipoNó ponteiro = (Casting do tipo Nó)(Aloca na memória(O tamanho do(Nó));	
	No *novo = (No*)malloc(sizeof(No));
	novo->valor = vlr;
	
	//Se a lista está vazia:
	if(lista->inicio == NULL){	
		
		novo->proximo = NULL;
		lista->inicio = novo;
		lista->fim = novo;
		
	} else {
		
		novo->proximo = lista->inicio;
		lista->inicio = novo;
		
	}
	
	lista->tamanho++;
}

//Função para inserir elementos no fim da lista:
void inserirFim(Lista *lista, int vlr){
	
	No *novo = (No*)malloc(sizeof(No)); //Cria o novo nó
	novo->valor = vlr;
	novo->proximo = NULL; //último elemento da lista sempre aponta para NULL
	
	//Se a Lista estiver vazia
	if(lista->inicio == NULL){
		
		lista->inicio = novo;
		lista->fim = novo;
		
	} else {
		
		lista->fim->proximo = novo;
		lista->fim = novo;
		
	}
	
	lista->tamanho++;
	
}



void imprimirLista(Lista *lista){
	
	No *inicio = lista->inicio;
	printf("Tamanho da Lista: %d\n\n", lista->tamanho);
	
	//Laço para percorrer todos os nós da lista
	while(inicio != NULL){
		printf("%d ", inicio->valor);
		inicio = inicio->proximo;
	}
	
	printf("\n\n");
	
}

main() {
	
	Lista listaNumeros;
	inserirInicio(&listaNumeros, 400);
	inserirFim(&listaNumeros, 222);
	inserirInicio(&listaNumeros, 999);
	inserirFim(&listaNumeros, 223);
	inserirInicio(&listaNumeros, 510);
	imprimirLista(&listaNumeros);
	
}

