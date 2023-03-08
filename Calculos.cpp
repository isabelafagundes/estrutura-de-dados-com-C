/*
	Name: Calculos.cpp
	Author: Isabela Fagundes
	Date: 01/03/23 07:57
	Description: Programa para demonstrar a utiliza��o de fun��es
*/

# include <locale.h>
# include <conio.h>
# include <stdio.h>

//Sess�o de prototipa��o
int realizarSoma(int, int);
int realizarSub(int, int);
int realizarMulti(int, int);
float realizarDivi(int, int);
int lerNum();

main(){
	
	setlocale(LC_ALL, "Portuguese");
	int a, b;
	//Exmplo de recurss�o no c�digo, efeito em cascata:
	a = b = 0;
	
//	result = realizarSoma(a, b);
//	printf("O resultado �: %d", result);
//	printf("O resultado da soma �: %d", realizarSoma(lerNum(), lerNum()));
	printf("\nO resultado da divisao �: %.2f", realizarDivi(lerNum(), lerNum()));
	
//	printf("\nO resultado da subtra��o �: %d", realizarSub(a, b));
//	printf("\nO resultado da multiplica��o �: %d", realizarMulti(a, b));
//	printf("\nO resultado da multiplica��o �: %.2f", realizarDivi(a, b));

}

int lerNum(){
	int num;
	printf("Digite um n�mero: ");
	scanf("%d", &num);
	return num;
}

int realizarSoma(int n1, int n2){
	return n1 + n2;
}

int realizarSub(int n1, int n2){
	return n1 - n2;
}

int realizarMulti(int n1, int n2){
	return n1 * n2;
}

float realizarDivi(int n1, int n2){
	//Converte para float, se chama casting
	return (float) n2 / n1;
}


