/*
	Name: Calculos.cpp
	Author: Isabela Fagundes
	Date: 01/03/23 07:57
	Description: Programa para demonstrar a utilização de funções
*/

# include <locale.h>
# include <conio.h>
# include <stdio.h>

//Sessão de prototipação
int realizarSoma(int, int);
int realizarSub(int, int);
int realizarMulti(int, int);
float realizarDivi(int, int);
int lerNum();

main(){
	
	setlocale(LC_ALL, "Portuguese");
	int a, b;
	//Exmplo de recurssão no código, efeito em cascata:
	a = b = 0;
	
//	result = realizarSoma(a, b);
//	printf("O resultado é: %d", result);
//	printf("O resultado da soma é: %d", realizarSoma(lerNum(), lerNum()));
	printf("\nO resultado da divisao é: %.2f", realizarDivi(lerNum(), lerNum()));
	
//	printf("\nO resultado da subtração é: %d", realizarSub(a, b));
//	printf("\nO resultado da multiplicação é: %d", realizarMulti(a, b));
//	printf("\nO resultado da multiplicação é: %.2f", realizarDivi(a, b));

}

int lerNum(){
	int num;
	printf("Digite um número: ");
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


