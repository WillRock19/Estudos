#include<stdio.h>
main(){
float alt,peso,IMC;

printf("Confira se voce esta cima ou abaixo do peso \n\n");
printf("Digite sua altura: ");
scanf("%f", &alt);
printf("Digite seu peso: ");
scanf("%f", &peso);
IMC=peso/(alt*alt);
if(IMC < 20){printf("\n\n\nVoce esta abaixo do peso. Saudavel...");}
if(IMC >= 20.0 && IMC <= 24.9){printf("\n\n\nVoce esta com seu peso normal. Ainda saudavel...");}
if(IMC >= 25.0 && IMC <= 29.9){printf("\n\n\nVoce esta com excesso de peso. Gordo...");}
if(IMC >= 30.0 && IMC <= 39.9){printf("\n\n\nVoce esta obeso. Muito Gordo...........");}
if(IMC >= 40.0 ){printf("\n\n\nVoce esta morbido. Se mata cara......................");}

}






