	#include<stdio.h>
	main (){
	float a,b;
	int c;
	printf("Digite um primeiro numero: ");
	scanf("%f",&a);
	printf("Digite um segundo numero: ");
	scanf("%f",&b);
	printf("Escolha uma das 4 opera�oes basicas da matematica: \n\n");
	printf("\n 1-para Divisao");
	printf("\n 2-para multiplica�ao");
	printf("\n 3-para Soma");
	printf("\n 4-para Subtra�ao \n\n Escolha: ");
	scanf("%i",&c);
	printf("Total: ");
	if(c==1){
	printf("%f", a/b);
	}
	if(c==2){
	printf("%f", a*b);
	}
	if(c==3){
	printf("%f", a+b);
	}
	if(c==4){
	printf("%f", a-b);
	}
	}





