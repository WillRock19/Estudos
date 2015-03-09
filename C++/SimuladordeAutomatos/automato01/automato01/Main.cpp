#include <iostream>
#include <string.h>
// implementen��o do AFD {w | w cont�m no m�nimo dois 0s e no m�ximo um 1}

// estados de aceita��o
int aceita[2] = { 4, 7 };

// estado inicial
int state = 1;

//  alfabeto de entrada
char* alfabeto = "10";

//palavra de entrada
char input[15];
int qtdChars = 0;


// headers dos metodos
void transictionFunc(char);
void show(int);
int stop(char*);

int main()
{
	int index = 0;

	// faz leitura da entrada
	std::cout << "{w | w contem no minimo dois 0s e no maximo um 1};\n Entrada >";
	gets_s(input);
	std::cout << "\n";

	// guarda qtd de simbolos de entrada
	qtdChars = strlen(input);
	
	// verifica alfabeto
	int qtdAlfa = strlen(alfabeto)
		,errAlfabeto=0;
	for (int i = 0; i < qtdChars; i++)
		for (int j = 0; j < qtdAlfa; j++)
			if (input[i] == alfabeto[j])
			{
				errAlfabeto = 0;
				break;
			}
			else
				errAlfabeto = 1;

	if (errAlfabeto)
		return stop("Sentenca NAO pertence ao alfabeto");


	// inica loop de fun��o de transi��o
	while (index < qtdChars)
	{
		// exibe opera��es 
		show(index);

		// executa fun��o de transi��o
		transictionFunc(input[index]);

		if (state == -1)
			return stop("Sentenca NAO reconhecida");
		
		index++;
	}
	show(index);

	// verifica se estado que parou e estado de aceita��o
	short ok = 0;
	for (int i = 0; i < sizeof(aceita)/sizeof(int); i++)
		if (aceita[i] == state)
			ok = 1;

	if (ok)
		return stop("Sentenca reconhecida");
	else
		return stop("Sentenca NAO reconhecida");

	
}

void transictionFunc(char c)
{
	switch (state)
	{
		case 1:
			if (c == '1')
				state = 2;
			else if (c =='0')
				state = 5;

			break;
		case 2:
			if (c == '1')
				state = 8;
			else if (c == '0')
				state = 3;

			break;
		case 3:
			if (c == '1')
				state = 8;
			else if (c == '0')
				state = 4;

			break;
		case 4:
			if (c == '1')
				state = 8;
			else if (c == '0')
				state = 4;

			break;
		case 5:
			if (c == '1')
				state = 6;
			else if (c == '0')
				state = 7;

			break;
		case 6:
			if (c == '1')
				state = 8;
			else if (c == '0')
				state = 4;

			break;
		case 7:
			if (c == '1')
				state = 1;
			else if (c == '0')
				state = 7;

			break;
		case 8:
			if (c == '1')
				state = 8;
			else if (c == '0')
				state = 8;

			break;
		default:
			state = -1;
			break;
	}


}


void show(int index)
{
	//exibe opera��o
	for (int i = 0; i < index; i++)
		std::cout << input[i];

	std::cout << "(q" << state << ")";

	//exibe opera��o
	for (int i = index; i < qtdChars; i++)
		std::cout << input[i];

	std::cout << std::endl;
}


int stop(char* message)
{
	std::cout << "\n" << message << std::endl;
	system("pause");
	return 0;
	
}
