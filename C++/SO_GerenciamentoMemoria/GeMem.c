#include <stdio.h>
#include <stdlib.h>
#include "GeMem.h"

//Fun�ao que insere na memoria
char* Aloc(int tnTam){

    if(Limite<tnTam)
        return 0;

    //GerMemInit(); //seta espa�o vazio total como primeiro no da lista

    int tnTamAux = tnTam;
    Memoria *lsMem,*lsEsp,*Aux;//criando ponteiro nova lista de memoria.
    lsMem=(Memoria*)malloc(sizeof(Memoria));//alocando o espa�o em mem�ria e converte
    lsMem->nMem  = 0;
    Aux = PMemoria;
    Aux->lAloc = 's';
    while(Aux!=NULL || tnTamAux!=0){
        printf("Parte 1  - %c \n",PMemoria->lAloc);
        if(Aux->lAloc == ' '){

            // novo no para o espa�o
            lsMem->nMem  = Aux->nMem;
            lsMem->lAloc = 's';

            // verifica se falta espa�o para gravar
            if(Aux->nTam < tnTamAux){
                lsMem->nTam = Aux->nTam;
                tnTamAux-=Aux->nTam;
            }
            else{
                // verifica se sobra espa�o
                if(Aux->nTam > tnTamAux){
                    lsMem->nTam = tnTamAux;
                    Aux->nTam-=tnTamAux;
                    tnTamAux = 0;
                }
                // verifica se tem o espa�o exato
                else{
                    lsMem->nTam = tnTamAux;
                    tnTamAux = 0;
                }
            }
            lsMem->oAnt  = Aux->oAnt;
            lsMem->oProx = Aux->oProx;

            // se n�o faltar mais memoria para alocar, marca como final
            if(tnTamAux==0){
                lsMem->lFim = 's';

                if(Aux->nTam > 0){
                    lsEsp=(Memoria*)malloc(sizeof(Memoria));
                    lsEsp->nMem = Aux->nMem + Aux->nTam;
                    lsEsp->nTam = Aux->nTam;
                    lsEsp->oAnt = lsMem;
                    lsEsp->oProx= Aux->oProx;
                    // COLOCA O ESPA�O LIVRE NA FRENTE DO ESPA�O ALOCADO
                    lsMem->oProx = lsEsp;
                }
                free(Aux);
            }
        }
        Aux = Aux->oProx;
        if(Aux==NULL){
            tnTamAux = 0;
        }
    }
    return lsMem;
}

void Libera(char *tpMem){
    // se a lista est� nula ignora
    if(PMemoria == NULL){
        return;
    }
    Memoria *Aux;
    Aux = BuscarMem(tpMem);

    // se retornar null n�o tem nada para fazer
    if(Aux==NULL)
        return;

    Memoria *oAnt,*oProx;
    // guarda a lista anterior
    oAnt = Aux->oAnt;

    while(Aux->lFim != 's' || Aux->oProx == NULL)
    {
        Aux->lAloc = ' ';
        Aux->lFim = ' ';
        Aux->nMem = 0;
        Aux = Aux->oProx;
    }
    //guarda o proximo
    oProx = Aux->oProx;
    // apaga o ultimo no
    Aux->lAloc = ' ';
    Aux->lFim = ' ';
    Aux->nMem = 0;
}

Memoria* BuscarMem(char *tnMem)
{
    Memoria *MAux;
    MAux = PMemoria; //coloca a lista atual na lista auxiliar

    while(MAux != NULL)
    {
		if (tnMem >= MAux->nMem && tnMem <= (MAux->nMem+MAux->nTam))
		{
			while (MAux->oAnt != NULL)
				if(MAux->oAnt->lFim=='s')
					break;
				else
					MAux = MAux->oAnt;

			break;
		}
		MAux = MAux->oProx;
	}
	return MAux;
}

void GerMemInit()
{
	 // cria a lista inicial caso ela n�o exista
	if(PMemoria == NULL){
        PMemoria 		= (Memoria*)malloc(sizeof(Memoria));
		PMemoria->nMem 	= cHeap;
		PMemoria->nTam 	= sizeof(cHeap);
		PMemoria->lAloc = ' ';
		PMemoria->lFim	= ' ';
		PMemoria->oProx	= NULL;
		PMemoria->oAnt	= NULL;
	}
}
