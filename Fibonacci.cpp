/*
	Name: Fibonacci.cpp
	Author: Isabela Fagundes
	Date: 08/03/23 09:48
	Description: Programa pra demonstrar a sequência de Fibonacci
	1,1,2,3,5,8,13,21,34,55...
	ant., atual, prox.
*/

# include <stdio.h>

int realizarFibo(int);

int limite = 0;

main() {
	printf("Quantos numeros da sequencia de Fibonacci deseja exibir? ");
	scanf("%d", &limite);
	
	for(int i = 1; i <= limite; i++) printf(" %d", realizarFibo(i));
}

int realizarFibo(int n){
	
	if(n == 1) return 1;
	if(n == 2) return 1;
	
	return realizarFibo(n - 1) + realizarFibo(n - 2);

}

