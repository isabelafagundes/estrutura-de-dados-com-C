/*
	Name: Fila.cpp
	Author: Isabela Fagundes
	Date: 05/04/23 09:41
	Description: Implementa��o do conceito de Filas - FIFO
*/

#include <conio.h>
#include <stdio.h>
#include <locale.h>

//prototipa��o
void inserirLogin();
void inserirSenha();

//vari�veis globais
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
	//espa�o antes do %c para zerar o buffer
	
	if(username == nome) inserirSenha();
	else inserirLogin();
	
}

void inserirSenha(){
	
	int pwd;
	
	printf("Insira sua senha: ");
	scanf("%d", &pwd);
	chances++;
	
	if(senha == pwd) puts("Voc� efetuou login com sucesso!");
	else if(chances < 3) inserirLogin();
	else puts("Suas chances acabaram! Encerrando o sistema...");
		
		
	
	
}

