#pragma warning (disable : 4996)
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
	int codigo;
	char nome[51];
	int opcaoMenuPrincipal;
	int opcaoMenuInserir;
	int opcaoMenuEditar;
	int opcaoMenuExibir;
	int opcaoMenuExcluir;

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
		printf("\tESCOLHA A OPÇÃO DESEJADA: ");
		scanf("%d", &opcaoMenuPrincipal);

		switch (opcaoMenuPrincipal)
		{
		case 1:
			do 
			{
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
				scanf("%d", &opcaoMenuInserir);

				switch (opcaoMenuInserir)
				{
				case 1:
					system("cls");
					printf("\n");
					printf("---------------------------- ALUNOS CADASTRADOS -----------------------------\n");
					if (listaAluno.inicio != NULL) 
					{
						exibirTodosOsAlunos(&listaAluno);
						printf("\n");
					}
					else
					{
						printf("\tNENHUM ALUNO CADASTRADO...\n\n");
					}
					printf("------------------------------- INSERIR ALUNO -------------------------------\n");
					printf("\tINFORME A MATRICULA E O NOME DO ALUNO...\n");
					printf("\tMATRICULA: ");
					scanf("%d", &matricula);
					// função necessaria para pegar o \n do buffer do teclado
					// caso contrario, a string nome ira armazenar o \n
					getchar();
					printf("\tNOME: ");
					gets_s(nome, 50);
					printf("\n");
					aluno *aln = buscarAluno(&listaAluno, matricula);
					if (aln == NULL)
					{
						inserirAluno(&listaAluno, matricula, nome);
						printf("\tALUNO INSERIDO COM SUCESSO.\n");
					}
					else
					{
						printf("\tNÃO FOI POSSÍVEL INSERIR O ALUNO. MATRÍCULA JÁ CADASTRADA.\n");
					}
					system("pause");
					system("cls");
					break;
				case 2:
					system("cls");
					printf("\n");
					printf("-------------------------- PROFESSORES CADASTRADOS --------------------------\n");
					if (listaProfessor.inicio != NULL)
					{
						exibirTodosOsProfessores(&listaProfessor);
						printf("\n");
					}
					else
					{
						printf("\tNENHUM PROFESSOR CADASTRADO...\n\n");
					}
					printf("----------------------------- INSERIR PROFESSOR -----------------------------\n");
					printf("\tINFORME UM CÓDIGO(NUMÉRICO) E O NOME DO PROFESSOR...\n");
					printf("\tCÓDIGO: ");
					scanf("%d", &codigo);
					getchar();
					printf("\tNOME: ");
					gets_s(nome, 50);
					printf("\n");
					professor *prof = buscarProfessor(&listaProfessor, codigo);
					if (prof == NULL)
					{
						inserirProfessor(&listaProfessor, codigo, nome);
						printf("\tPROFESSOR INSERIDO COM SUCESSO.\n");
					}
					else
					{
						printf("\tNÃO FOI POSSÍVEL INSERIR O PROFESSOR. CÓDIGO JÁ CADASTRADO.\n");
					}
					system("pause");
					system("cls");
					break;
				case 3:
					system("cls");
					printf("\n");
					printf("-------------------------- DISCIPLINAS CADASTRADAS --------------------------\n");
					if (listaDisciplina.inicio != NULL)
					{
						exibirTodasAsDisciplinas(&listaDisciplina);
						printf("\n");
					}
					else
					{
						printf("\tNENHUMA DISCIPLINA CADASTRADA...\n\n");
					}
					printf("---------------------------- INSERIR DISCIPLINA -----------------------------\n");
					printf("\tINFORME UM CÓDIGO(NUMÉRICO) E O NOME DA DISCIPLINA...\n");
					printf("\tCÓDIGO: ");
					scanf("%d", &codigo);
					getchar();
					printf("\tNOME: ");
					gets_s(nome, 50);
					printf("\n");
					disciplina *discip = buscarDisciplina(&listaDisciplina, codigo);
					if (discip == NULL)
					{
						inserirDisciplina(&listaDisciplina, codigo, nome);
						printf("\tDISCIPLINA INSERIDA COM SUCESSO.\n");
					}
					else
					{
						printf("\tNÃO FOI POSSÍVEL INSERIR A DISCIPLINA. CÓDIGO JÁ CADASTRADO.\n");
					}
					system("pause");
					system("cls");
					break;
				case 4:
					//IMPLEMENTAR INSERIR TURMA
					break;
				case 0:
					system("cls");
					break;
				default:
					printf("\n");
					printf("\tOPÇÃO INVÁLIDA\n");
					system("pause");
					system("cls");
					break;
				}
			} while (opcaoMenuInserir != 0);
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
			scanf("%d", &opcaoMenuEditar);
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
			scanf("%d", &opcaoMenuExibir);
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
			scanf("%d", &opcaoMenuExcluir);
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
			system("pause");
			system("cls");
			break;
		}
	} while (opcaoMenuPrincipal != 0);
	
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
	
	//printf("\t------------------------------------------------------------\n");
	//printf("\tINFORME A MATRICULA DO ALUNO QUE DESEJA ALTERAR: ");
	//int matricula;
	//scanf("%d", &matricula);
	//editarAluno(&lista, matricula);
	
	//system("cls");
	//exibirTodosOsAlunos(&lista);
	//system("PAUSE");
	
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
