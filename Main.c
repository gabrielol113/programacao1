#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "coinLibrary.h"
#include <stdlib.h>
/*

	Feito por Gabriel Teixeira 44437 e Hélia Siquara 44431

*/

void main(int argc,char *argv[]){
	
	TMoeda Coin[TMAX];
	int op,qnt,qMoedas=0;
	setlocale(LC_ALL, "Portuguese");
	char arquivo[30];
	while(1){

		exibeMenu();
		scanf("%d", &op);

		switch (op)
		{
		case 1://Função que insere moedas no programa
			
			system("cls");
			printf("Quantas moedas desejas inserir:");
			scanf("%d", &qnt);
			system("cls");
			InsereMoeda(Coin, qnt);
			qMoedas += qnt;
			break;
			
		case 2://Função que mostra as moedas que foram inseridas no programa mas não foram gravadas em ficheiro ainda
			
			system("cls");
			mostrarMoedas(Coin, qMoedas);
			break;
		
		case 3://Função que mostra as moedas que foram inseridas por estado de conservação desejada
			system("cls");
			int estado;
				printf("0 - Mal Cuidada\n 1 - Bem Cuidado\n 2 - Muito Bem Cuidada\n 3 - Bela\n 4 - Soberba\n\n");
			printf("Que estado de conservação deseja exibir:");
			scanf("%d", &estado);
			system("cls");
			mostrarConservacao(Coin,qMoedas,estado);
			break;
		
		case 4: // Remover Moedas por Número de Registo
			system("cls");
			printf("Informe o número de registro da moeda a ser removida:");
    		scanf("%d", &qnt);
			RemoverElemento(Coin, qnt);
			break;
		
		case 5:
			system("cls");
			GravarMoedas(Coin, arquivo ,qnt);
			break;
		
		case 6:
			system("cls");
			op = 1000;
			qMoedas += LerMoedas(Coin);
			break;
			

		case 7: // Ler do Ficheiro, Ordenar, Gravar e Mostrar
			system("cls");
			op = 1000;
			LerMoedas(Coin);
			OrdenarMoedas(Coin, qnt);
			GravarMoedas(Coin, arquivo ,qnt);
			mostrarMoedas(Coin, qMoedas);    
			break;
		
		case 8:
			system("cls");
			calculaValor(Coin, qMoedas);
			break;
			
		case 0:
			system("cls");
			exit(1);
		default :
			system("cls");
			printf("Seleção Invalida\n");
			
		}
	}
}
