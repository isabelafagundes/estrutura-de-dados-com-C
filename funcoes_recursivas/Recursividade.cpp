/*
	Name: Recursividade.cpp
	Author: Isabela Fagundes
	Date: 01/03/23 10:03
	Description: Programa para demonstrar o conceito de execução de recursividade
*/

# include <stdio.h>

//Sessão de protatipação:
int regressiva(int, int);

//Variáveis globais:
int n = 0;
int i = n;

main(){

	printf("Insira um numero: ");
	scanf("%d", &n);
	i = n;
	
	linha(n, i);
	
}

int linha(int n, int i){
	
	if(n < -i) return 1;
		
	printf("%d ", n--);
	regressiva(n, i); 	
}
