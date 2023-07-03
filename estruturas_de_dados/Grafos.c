/*
	Name: Grafo.c
	Author: Isabela Fagundes
	Date: 01/07/23 20:41
	Description: Implementação de uma estrutura de grafo.
*/

#include <stdio.h>
#include <malloc.h>
#include <locale.h>

void montarListaPrincipal(int);
int montarSublista(int, int, int);
void exibirListaPrincipal();
void exibirGrafo(int);

typedef struct sublista 
{
	int chave;
	struct sublista *proximo;
	
} adjacente;

typedef struct principal 
{
	int chave;
	struct sublista *adjacente;
	struct principal *seguinte;
	
} lista;

lista *novaLista, *listaAux, *inicio;
adjacente *primeiro, *novaSub;

main ()
{
	setlocale(LC_ALL, "Portuguese");
	int quantidade, chaveSub, chavePrincipal, subMontada;
	char continuar = 's';
	
	do 
	{
		printf("Qual seria a quantidade de itens na lista principal? ");
		scanf("%d", &quantidade);	
		
	} while(quantidade <= 0);
	
	montarListaPrincipal(quantidade);
	exibirListaPrincipal();
	
	while(continuar == 's' || continuar == 'S')
	{
		
		do 
		{
		
			printf("\nEm qual item deseja inserir uma chave? ");
			scanf("%d", &chavePrincipal);
			
			if(chavePrincipal >= 0)
			{
				printf("\nQual seria o valor dessa chave? ");
				scanf("%d", &chaveSub);	
			}		
		
		} while(chavePrincipal <= 0 && chaveSub <= 0);
	
		subMontada = montarSublista(chavePrincipal, chaveSub, quantidade);
		if(subMontada == 0) exibirGrafo(quantidade);
		
		printf("\n\nDeseja continuar inserindo chaves? [s/n] ");
		fflush(stdin);
		scanf("%c", &continuar);
		
	}
	
}

void montarListaPrincipal(int quantidade)
{
	//Criação do primeiro item da lista principal com chave 0
	novaLista = (lista*)malloc(sizeof(lista));
	novaLista->seguinte = NULL;
	novaLista->chave = 0;
	novaLista->adjacente = NULL;
	//inicio e listaAux apontam para este primeiro item
	inicio = novaLista;
	listaAux = novaLista;
	int i;
	
	for(i = 1; i < quantidade; i++)
	{
		//criação de uma nova lista
		novaLista = (lista*)malloc(sizeof(lista));
		novaLista->adjacente = NULL;
		novaLista->chave = i;
		novaLista->seguinte = NULL;
		//Adiciona este novo item ao item seguinte
		listaAux->seguinte = novaLista;
		/*
		Salva o item criado na lista auxiliar, para caso
		ainda tenha mais listas a serem criadas, seja possível
		adicioná-la ao seguinte
		*/
		listaAux = novaLista;
	}	
}

int montarSublista(int chavePrincipal, int chaveSub, int quantidade)
{
	//Validação da entrada de dados do usuário
	if(chavePrincipal < 0 || chaveSub < 0 || chavePrincipal >= quantidade)
	{
		puts("\nOs dados inseridos para encontrar o item estão incorretos!");
		return 1;
	}
	
	//Lista auxiliar apontando para o primeiro item da lista principal
	listaAux = inicio;
	
	//Encontrar a chave da lista principal para inserir a sublista
	while(listaAux->chave != chavePrincipal)
	{
		if(listaAux == NULL) break;
		else listaAux = listaAux->seguinte;
	}
	
	if(listaAux == NULL) 
	{
		puts("\nLocal incorreto!");
		return 1;
	}
	
	//Criando a nova sublista
	novaSub = (adjacente*)malloc(sizeof(adjacente));
	novaSub->chave = chaveSub;
	novaSub->proximo = NULL;
	
	//Se não possui sublista recebe a nova criada
	if(listaAux->adjacente == NULL) 
	{
		listaAux->adjacente = novaSub;
		return 0;
	}
	
	//Variável primeiro apontando para a primeira sublista
	primeiro = listaAux->adjacente;
	//Encontrando a sublista com próximo nulo
	while(primeiro->proximo != NULL) primeiro = primeiro->proximo;
	//Adicionando sublista em próximo nulo
	primeiro->proximo = novaSub;
	return 0;
}

void exibirListaPrincipal()
{
	
	if(inicio == NULL) puts("Lista principal vazia!!\n\n");
	listaAux = inicio; //Para exibir a lista do começo
	printf("\n");
	while(listaAux != NULL)
	{
		printf("%d -> ", listaAux->chave);
		listaAux = listaAux->seguinte;
	}
	printf("NULL\n");
	
}

void exibirGrafo(int quantidade)
{
	
	if(inicio == NULL) 
	{
		puts("\nA lista principal vazia!");
		return;	
	}
	
	listaAux = inicio;
	while(listaAux != NULL)
	{
		
		printf("\n%d : ", listaAux->chave);
		
		primeiro = listaAux->adjacente;
		
		if(primeiro == NULL) printf("NULL");
		else {
			while(primeiro != NULL)
			{
				printf("%d -> ", primeiro->chave);
				primeiro = primeiro->proximo;
			}
			printf("NULL");
		}
		
		listaAux = listaAux->seguinte;
		
	}
	
}
