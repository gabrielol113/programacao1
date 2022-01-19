/*

        Aqui está a biblioteca para o uso das funções relacionada às moedas
        
        Feito por Gabriel Teixeira 44437 e Hélia Siquara 44431

*/

#include <stdio.h>
#include <string.h>
#define TMAX 30
#include <stdlib.h>
#define __STDC_WANT_LIB_EXT1__ 1

struct data_aquisicao
{
	int dia;
	int mes;
	int ano;

};

typedef struct moeda
{
	enum tp_estado {
		MC,
		BC,
		MBC,
		BELA,
		SOB
	}estado;

	int numRegister;
	int epoca;
	float valor;
	int anoCunho;
	float diametro;
	float peso;
	float valorComercial;
	char tipoMetal[30];

	struct data_aquisicao aquisicao;
} TMoeda;	

//Função que implementa um menu no programa

void exibeMenu(){
	printf("\t\t\tMenu\n");
	printf("\t[1] Inserir informação das Moedas\n");
	printf("\t[2] Listar todos os Registos de Moedas inseridos\n");
	printf("\t[3] Listar Moedas por Estado de Conservação\n");
	printf("\t[4] Remover Moedas por Número de Registo\n");
	printf("\t[5] Gravar Registos de Moedas no Ficheiro\n");
	printf("\t[6] Ler registos do Ficheiro e Mostrar\n");
	printf("\t[7] Ler do Ficheiro, Ordenar, Gravar e Mostrar\n");
	printf("\t[8] Calcular o Valor Comercial Total das Moedas da Coleção\n");
	printf("\t[0] Sair\n");
	printf("\nQual função deseja executar:");
}

// Função que grava as moedas no arquivo

void GravarMoedas(TMoeda aqr[], char arquivo[],int j){
	
	printf("\nEm qual arquivo deseja gravar:");
	scanf("%s", arquivo);
	int i;
	FILE *ptr_Arq;
	
	ptr_Arq	= fopen(arquivo, "a");
	
	if (ptr_Arq != NULL) {

		for ( i = 0; i < j; i++) {
			
			fwrite(&aqr[i], sizeof(TMoeda), 1, ptr_Arq);
			
		}
		
		fclose(ptr_Arq);
		system("cls");
		printf("Arquivo criado com sucesso!\n");
		
	}
	else {
		printf("\n\nErro: O arquivo não foi aberto\n");
	}
}

//Função que registra uma moeda no programa

int InsereMoeda(TMoeda v[], int qnt){

	int i;

	for (i = 0; i <= qnt-1; i++){
		
		printf("Insira as informações da moeda %d.\n\n",i+1);
		printf("Numero de Registo:");
		scanf("%d", &v[i].numRegister);

		printf("Época:");
		scanf("%d", &v[i].epoca);

		printf("Valor:");
		scanf("%f", &v[i].valor);

		printf("Ano de Cunho:");
		scanf("%d", &v[i].anoCunho);
		getchar();
		printf("Diâmetro:");
		scanf("%f", &v[i].diametro);
		getchar();
		printf("Peso:");
		scanf("%f", &v[i].peso);

		printf("Data de Aquisição      [dd/mm/aaaa]:");
		scanf("%d/%d/%d", &v[i].aquisicao.dia, &v[i].aquisicao.mes, &v[i].aquisicao.ano);

		printf("Valor comercial:");
		scanf("%f", &v[i].valorComercial);
		getchar();
		printf("Metal:");
		scanf("%s",&v[i].tipoMetal);
		getchar();
		printf("Estado de Conservação:");
		scanf("%d",&v[i].estado);
		getchar();
		system("cls");
		fflush(stdin);
	}
}

//Função que lê as moedas registradas em um arquivo externo

int LerMoedas(TMoeda auxMoedas[TMAX]){
	
	char arquivo[30];
	printf("O ficheiro a ser aberto é:");
	scanf("%s", arquivo);
	FILE *arq = fopen(arquivo,"rb");
  	if (arq != NULL){  	
			int indice = 0;
		while(1){
			
			size_t r = fread(&auxMoedas[indice], sizeof(TMoeda), 1, arq);
			
			if(r<1) break;
			else{
				indice++;
			}
		}
		fclose(arq);
		system("cls");
		printf("Arquivo lido!\n\n");
		return indice;	
	}
	else{
		system("cls");
		printf("Não conseguiu abrir o arquivo, tente novamente!\n\n");
	}
}

//Função que mostra as moedas registradas até o momento no programa

void mostrarMoedas(TMoeda auxMoedas[], int imax){
	
	int opcao = 1,i=0;

	while(opcao != 0){
		
		system("cls");
		
		printf("Exibindo a moeda %d de  %d.\n\n", i+1, imax);
		printf("Numero de Registo:\n",auxMoedas[i].numRegister);
		printf("Época: %d\n",auxMoedas[i].epoca);
		printf("Valor: %.2f\n", auxMoedas[i].valor);
		printf("Ano de Cunho: %d\n", auxMoedas[i].anoCunho);
		printf("Diâmetro: %.3f\n", auxMoedas[i].diametro);
		printf("Peso: %.3f\n", auxMoedas[i].peso);
		printf("Data de Aquisição: %d/%d/%d\n", auxMoedas[i].aquisicao.dia, auxMoedas[i].aquisicao.mes, auxMoedas[i].aquisicao.ano);
		printf("Valor comercial: %.2f\n", auxMoedas[i].valorComercial);
		printf("Metal: %s\n", auxMoedas[i].tipoMetal);
		printf("Estado de Conservação:");
		exibeEnum(auxMoedas[i].estado);
		printf("\n");
		
		printf("Para a próxima moeda digite o numero 2\n");
		printf("Para a moeda anterior digite o numero 1\n");
		printf("Para sair da função digite 0\n");
		printf("\n\nOpção:");
		scanf("%d", &opcao);
		
		if(opcao == 2){
			i++;
			if(i == imax){
				i = 0;
			}
		}
		if(opcao == 1){
			i--;
			if(i < 0){
				i = imax;
			}
		}
		if(opcao == 0){
			system("cls");
			break;
		}
	}
	
}

//Função que ordena as moedas pelo seu ano de cunho 
int OrdenarMoedas(TMoeda auxMoedas[], int n){
	
	int i,j,temp;
	
	for (j = auxMoedas[i].anoCunho - 1; j<=1; j--){
		for(i = 0; i >j; i++){
			if(auxMoedas[i].anoCunho > auxMoedas[i+1].anoCunho){
				temp = auxMoedas[i].anoCunho;
				auxMoedas[i].anoCunho = auxMoedas[i+1].anoCunho;
				auxMoedas[i+1].anoCunho = temp;
			}
		}
	}
	return temp;
}

exibeEnum(int estado){
	
	if(estado == 0){
		printf("Mal Cuidada");
	}
		if(estado == 1){
		printf("Bem Cuidada");
	}
		if(estado == 2){
		printf("Muito Bem Cuidada");
	}
		if(estado == 3){
		printf("Bela");
	}
		if(estado == 4){
		printf("Soberba");
	}
}

mostrarConservacao(TMoeda aqr[], int j, int estado){
	
	int opcao= 1000, aux,aux2=0,imax;
	int auxiliarVet[j];
	

//Para anotar os indices em que o estado desejado se encontra		
		for(aux = 0; aux < j; aux++){
			if(estado == aqr[aux].estado){
				auxiliarVet[aux]=aux;
				aux2++;
			}
		}
		
//Parte em que mostra as moedas nos respectivos indices

		while(opcao !=0){
			int i=0;	
				system("cls");
				printf("Moeda %d:\n\n", i+1);
				printf("Numero de Registo:\n",aqr[auxiliarVet[i]].numRegister);
				printf("Época: %d\n",aqr[auxiliarVet[i]].epoca);
				printf("Valor: %.2f\n", aqr[auxiliarVet[i]].valor);
				printf("Ano de Cunho: %d\n", aqr[auxiliarVet[i]].anoCunho);
				printf("Diâmetro: %.3f\n", aqr[auxiliarVet[i]].diametro);
				printf("Peso: %.3f\n", aqr[auxiliarVet[i]].peso);
				printf("Data de Aquisição: %d/%d/%d\n", aqr[auxiliarVet[i]].aquisicao.dia, aqr[auxiliarVet[i]].aquisicao.mes, aqr[auxiliarVet[i]].aquisicao.ano);
				printf("Valor comercial: %.2f\n", aqr[auxiliarVet[i]].valorComercial);
				printf("Metal: %s\n", aqr[auxiliarVet[i]].tipoMetal);
				printf("Estado de Conservação:");
				exibeEnum(aqr[auxiliarVet[i]].estado);
				printf("\n");
				
				printf("Para a próxima moeda digite o numero 2\n");
				printf("Para a moeda anterior digite o numero 1\n");
				printf("Para sair da função digite 0\n");
				
				scanf("%d", &opcao);		
			
				if(opcao == 2){
					i++;
					if(i == aux2){
						i = 0;
					}
				}
				if(opcao == 1){
					i--;
					if(i < 0){
						i = aux2;
					}
				}
				if(opcao == 0){
					system("cls");
					break;
				}
			
			}
		
}

calculaValor(TMoeda aqr[], int j){
	
	int i;
	float soma;
	
	for(i=0; i < j; i++){
		soma += aqr[i].valorComercial;
	}
	
	printf("Valor total das moedas: %.2f", soma);
}


int RemoverElemento(TMoeda auxMoedas[],int k) {

    int j;
    int tam = sizeof(auxMoedas) / sizeof(auxMoedas[0]);

    if (auxMoedas == NULL) {
        printf("Não há registros de moedas.\n");
    }
    else {
        for (j = k + 1; j < tam; ++j) {
            auxMoedas[j - 1] = auxMoedas[j];
        }
        return tam - 1;
    }
    printf("Registro da moeda removida com sucesso!");
}



