/*
	Name: ListaLigada.cpp
	Author: Isabela Fagundes
	Date: 22/03/23 09:47
	Description: Implementa��o da lista encadeada simples
*/

// N� � o elemento que engloba os valores + campo para apontar para o pr�ximo N�
// malloc() (memory alocation) -> Aloca na mem�ria
// sizeof() (tamanho de) -> Retorna o tamanho de um tipo

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

//Estrutura para um N� (node) da lista, contendo duas informa��es:
typedef struct No{
	
	int valor;
	struct No *proximo; //Guarda o endere�o de mem�ria no pr�ximo N�
};

//Estrutura que � a pr�pria Lista ligada com v�rios N�s:
typedef struct Lista{
	
	No *inicio, *fim; //Guarda endere�o de mem�rio do �nicio e do fim
	int tamanho; //Tamanho da lista
};

//Fun��o para inserir elementos no in�cio da lista:
void inserirInicio(Lista *lista, int vlr){
	
//tipoN� ponteiro = (Casting do tipo N�)(Aloca na mem�ria(O tamanho do(N�));	
	No *novo = (No*)malloc(sizeof(No));
	novo->valor = vlr;
	
	//Se a lista est� vazia:
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

//Fun��o para inserir elementos no fim da lista:
void inserirFim(Lista *lista, int vlr){
	
	No *novo = (No*)malloc(sizeof(No)); //Cria o novo n�
	novo->valor = vlr;
	novo->proximo = NULL; //�ltimo elemento da lista sempre aponta para NULL
	
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
	
	//La�o para percorrer todos os n�s da lista
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

