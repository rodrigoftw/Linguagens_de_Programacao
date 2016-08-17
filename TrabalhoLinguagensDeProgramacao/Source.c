#include "libaluno.h"
#include "libprofessor.h"
#include "libdisciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() 
{
	setlocale(LC_ALL, "Portuguese");

	listaDeAlunos listaAluno;
	listaAluno.inicio = NULL;
	listaDeProfessores listaProfessor;
	listaProfessor.inicio = NULL;
	listaDeDisciplinas listaDisciplina;
	listaDisciplina.inicio = NULL;

	int matricula;
	char nome[50];
	int opcao;

	do 
	{
		printf("\n");
		printf("------------------------------ MENU PRINCIPAL ------------------------------\n");
		printf("\t1 - INSERIR\n");
		printf("\t2 - EDITAR\n");
		printf("\t3 - EXIBIR\n");
		printf("\t4 - EXCLUIR\n");
		printf("\t0 - SAIR\n");
		printf("----------------------------------------------------------------------------\n");
		
		do 
		{
			printf("\tESCOLHA A OPÇÃO DESEJADA: ");
			scanf("%d", &opcao);

			switch (opcao)
			{
			case 1:
				system("cls");
				printf("\n");
				printf("------------------------------- MENU INSERIR -------------------------------\n");
				printf("\t1 - INSERIR ALUNO\n");
				printf("\t2 - INSERIR PROFESSOR\n");
				printf("\t3 - INSERIR DISCIPLINA\n");
				printf("\t4 - INSERIR TURMA\n");
				printf("\t0 - VOLTAR AO MENU PRINCIPAL\n");
				printf("----------------------------------------------------------------------------\n");
				printf("\tESCOLHA A OPÇÃO DESEJADA: ");
				scanf("%d", &opcao);
				
				switch (opcao)
				{
				case 1:
					system("cls");
					printf("\n");
					printf("------------------------------- INSERIR ALUNO -------------------------------\n");
					printf("\tINFORME A MATRICULA E O NOME DO ALUNO...\n");
					printf("\tMATRICULA: ");
					scanf("%d", &matricula);
					printf("\tNOME: ");
					scanf("%s", nome);
					inserirAluno(&listaAluno, matricula, nome);
				default:
					break;
				}
				system("cls");
				break;
			case 2:
				system("cls");
				printf("\n");
				printf("------------------------------- MENU EDITAR --------------------------------\n");
				printf("\t1 - EDITAR ALUNO\n");
				printf("\t2 - EDITAR PROFESSOR\n");
				printf("\t3 - EDITAR DISCIPLINA\n");
				printf("\t4 - EDITAR TURMA\n");
				printf("\t0 - VOLTAR AO MENU PRINCIPAL\n");
				printf("----------------------------------------------------------------------------\n");
				printf("\tESCOLHA A OPÇÃO DESEJADA: ");
				scanf("%d", &opcao);
				//CONTINUAr
				//...
				system("cls");
				break;
			case 3:
				system("cls");
				printf("\n");
				printf("------------------------------- MENU EXIBIR --------------------------------\n");
				printf("\t1 - EXIBIR ALUNO\n");
				printf("\t2 - EXIBIR PROFESSOR\n");
				printf("\t3 - EXIBIR DISCIPLINA\n");
				printf("\t4 - EXIBIR TURMA\n");
				printf("\t0 - VOLTAR AO MENU PRINCIPAL\n");
				printf("----------------------------------------------------------------------------\n");
				printf("\tESCOLHA A OPÇÃO DESEJADA: ");
				scanf("%d", &opcao);
				//CONTINUAR
				//...
				system("cls");
				break;
			case 4:
				system("cls");
				printf("\n");
				printf("------------------------------- MENU EXCLUIR -------------------------------\n");
				printf("\t1 - EXCLUIR ALUNO\n");
				printf("\t2 - EXCLUIR PROFESSOR\n");
				printf("\t3 - EXCLUIR DISCIPLINA\n");
				printf("\t4 - EXCLUIR TURMA\n");
				printf("\t0 - VOLTAR AO MENU PRINCIPAL\n");
				printf("----------------------------------------------------------------------------\n");
				printf("\tESCOLHA A OPÇÃO DESEJADA: ");
				scanf("%d", &opcao);
				//CONTINUAR
				//...
				system("cls");
				break;
			case 0:
				system("cls");
				break;
			default:
				printf("\n");
				printf("\tOPÇÃO INVÁLIDA\n");
				opcao = 0;
				system("pause");
				system("cls");
				break;
			}
		} while (opcao != 0);
		
	} while (opcao != 0);
	
	system("pause");



	// funções 'criarAluno' 'inserirAluno' e 'exibirTodosOsAlunos' teoricamente estão funcionando
	// teste simples abaixo realizado com sucesso
	//listaDeAlunos lista;
	//lista.inicio = NULL;
	//inserirAluno(&lista, 1, "fabiano abreu");
	//inserirAluno(&lista, 2, "Morgana Sousa");
	//inserirAluno(&lista, 3, "Rodrigo Andrade");
	//inserirAluno(&lista, 4, "Gustavo Barbosa");
	//exibirTodosOsAlunos(&lista);
	//system("PAUSE");

	//excluirAluno(&lista, 3);
	//exibirTodosOsAlunos(&lista);
	//system("PAUSE");

	// funções 'buscarAluno' e 'editarAluno' teoricamente estão funcionando
	// teste simples abaixo realizado com sucesso
	
	/*printf("\t------------------------------------------------------------\n");
	printf("\tINFORME A MATRICULA DO ALUNO QUE DESEJA ALTERAR: ");
	int matricula;
	scanf("%d", &matricula);
	editarAluno(&lista, matricula);
	
	system("cls");
	exibirTodosOsAlunos(&lista);
	system("PAUSE");*/
	
	/*aluno a ;

	a.matricula = 123;
	printf("\tDigite o nome do aluno:\t");
	fgets(a.nome, 50, stdin);
	printf("\t%d", a.matricula);
	printf("\n");
	printf("\tNome do aluno: %s\n", a.nome);
	//printf(a.nome);

	a.matricula = 456;
	printf("\tDigite novamente o nome do aluno:\t");
	fgets(a.nome, 50, stdin);
	printf("%d", a.matricula);
	printf("\tNome do aluno: %s\n", a.nome);
	system("pause");

	a.proxAluno = NULL;*/
	

	return 0;
}
