#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <string.h>

	int registro(){
		
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf);
		
		FILE *file;
		file = fopen(arquivo, "w");
		fprintf(file, cpf);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		
		printf("Digite o NOME a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen (arquivo, "a");
		fprintf(file, nome);
		fclose(file);
		
		file = fopen (arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		
		printf("Digite o SOBRENOME a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen (arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen (arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o CARGO a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen (arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		system("pause");
		
		
	}

	int consulta(){
		
		setlocale(LC_ALL, "portuguese");
		
		char cpf[40];
		char conteudo[100];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL){
			printf("nao é possivel abrir o arquivo, tente novamente!!! \n");
		}
		
		while( fgets(conteudo, 100, file) != NULL){
			printf("Essas são as infromacoes do usuario: ");
			printf("%s", conteudo);
			printf(" \n\n");
		}
		system("pause");
		fclose(file);
	}

	int deleta(){
		
		//setlocale(LC_ALL, "portuguese");
		
		char cpf[40];
		
		printf("Digite o CPF do usuario que voce quer deletar do sistema: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE * file;
		file = fopen (cpf , "r");
		
		if(file == NULL)
		{
			printf("Usuario não encontrado no sistema!!");
			system("pause");
		}
		
		
		
	}


int main (){
	
	int opcao=0;
	int laco=1;
	
	for(laco=1; laco=1;){
		system("cls");
	
		setlocale(LC_ALL, "portuguese");
		printf("\tCartório da EBAC\t\n\n");
		printf("\tEscolha O Menu:\n\n");
		printf("\t 1- Registrar Nomes\n");
		printf("\t 2- Consultar Nomes\n");
		printf("\t 3- Deletar Nomes\n\n\n\n");
		printf("opcao: ");
	
		scanf("%d", & opcao);
	
		system("cls");
	
	switch (opcao)
	{
		case 1:
		registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deleta();
		break;
		
		default:
		printf("Essa Opcao Nao Esta Disponivel!!!\n");
		system("pause");
		break;
	}
	}
	
}

