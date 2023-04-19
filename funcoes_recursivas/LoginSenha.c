/*
	Name: Fila.cpp
	Author: Isabela Fagundes
	Date: 05/04/23 09:41
	Description: Implementação do conceito de Filas - FIFO
*/

#include <conio.h>
#include <stdio.h>
#include <locale.h>

//prototipação
void inserirLogin();
void inserirSenha();

//variáveis globais
char username = 'I';
int senha = 1234;
int chances = 0;

main() {
	
	setlocale(LC_ALL, "Portuguese");
	inserirLogin();
		
}

void inserirLogin(){
	char nome;
	
	printf("Insira seu username: ");
	scanf(" %c", &nome);
	//espaço antes do %c para zerar o buffer
	
	if(username == nome) inserirSenha();
	else inserirLogin();
	
}

void inserirSenha(){
	
	int pwd;
	
	printf("Insira sua senha: ");
	scanf("%d", &pwd);
	chances++;
	
	if(senha == pwd) puts("Você efetuou login com sucesso!");
	else if(chances < 3) inserirLogin();
	else puts("Suas chances acabaram! Encerrando o sistema...");
		
		
	
	
}

