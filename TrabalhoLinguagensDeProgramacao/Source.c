#pragma warning (disable : 4996)
#include "libaluno.h"
#include "libprofessor.h"
#include "libdisciplina.h"
#include "libturma.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void alunosCadastrados(listaDeAlunos *lista) 
{
	printf("---------------------------- ALUNOS CADASTRADOS -----------------------------\n");
	if (lista->inicio != NULL)
	{
		exibirTodosOsAlunos(lista);
		printf("\n");
	}
	else
	{
		printf("\tNENHUM ALUNO CADASTRADO...\n\n");
	}
}

void professoresCadastrados(listaDeProfessores *lista)
{
	printf("-------------------------- PROFESSORES CADASTRADOS --------------------------\n");
	if (lista->inicio != NULL)
	{
		exibirTodosOsProfessores(lista);
		printf("\n");
	}
	else
	{
		printf("\tNENHUM PROFESSOR CADASTRADO...\n\n");
	}
}

void disciplinasCadastradas(listaDeDisciplinas *lista)
{
	printf("-------------------------- DISCIPLINAS CADASTRADAS --------------------------\n");
	if (lista->inicio != NULL)
	{
		exibirTodasAsDisciplinas(lista);
		printf("\n");
	}
	else
	{
		printf("\tNENHUMA DISCIPLINA CADASTRADA...\n\n");
	}
}

int main() 
{

	setlocale(LC_ALL, "Portuguese");

	listaDeAlunos listaAluno;
	listaAluno.inicio = NULL;
	listaDeProfessores listaProfessor;
	listaProfessor.inicio = NULL;
	listaDeDisciplinas listaDisciplina;
	listaDisciplina.inicio = NULL;
	listaDeTurmas listaTurma;
	listaTurma.inicio = NULL;
	

	// INSERÇÕES ESTATICAS
	inserirAluno(&listaAluno, 1, "Fabiano Abreu");
	inserirAluno(&listaAluno, 2, "Rodrigo Andrade");
	inserirAluno(&listaAluno, 3, "Luis Augusto");
	inserirAluno(&listaAluno, 4, "Morgana Almeida");
	inserirProfessor(&listaProfessor, 1, "Roberio Gomes");
	inserirProfessor(&listaProfessor, 2, "Alexandre Cavalcante");
	inserirProfessor(&listaProfessor, 3, "Ciro Coelho");
	inserirProfessor(&listaProfessor, 4, "Andre Bessa");
	inserirDisciplina(&listaDisciplina, 1, "Computacao Grafica");
	inserirDisciplina(&listaDisciplina, 2, "Computacao Basica");
	inserirDisciplina(&listaDisciplina, 3, "Linguagens de Programacao");


	turma *trm = inserirTurma(&listaTurma, 1);
	professor *prof = buscarProfessor(&listaProfessor, 3);
	inserirProfessorNaTurma(trm, prof);
	disciplina *discip = buscarDisciplina(&listaDisciplina, 3);
	inserirDisciplinaNaTurma(trm, discip);
	aluno *aln = buscarAluno(&listaAluno, 1);
	inserirAlunoNaTurma(trm, aln);
	aln = buscarAluno(&listaAluno, 4);
	inserirAlunoNaTurma(trm, aln);
	exibirTodasAsTurmas(&listaTurma);

	/*int matricula;
	int codigo;
	char nome[51];
	int opcaoMenuPrincipal;
	int opcaoMenuInserir;
	int opcaoMenuEditar;
	int opcaoMenuExibir;
	int opcaoMenuExcluir;
	bool resultado;

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
					// exibi os alunos cadastrados ate o momento
					alunosCadastrados(&listaAluno);

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
					// exibi os professores cadastrados ate o momento
					professoresCadastrados(&listaProfessor);

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
					// exibi as disciplinas cadastradas ate o momento
					disciplinasCadastradas(&listaDisciplina);

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
					system("cls");
					printf("\n");
					// implementar inserir turma
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
			do 
			{
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

				switch (opcaoMenuEditar)
				{
				case 1:
					system("cls");
					printf("\n");
					alunosCadastrados(&listaAluno);

					printf("-------------------------------- EDITAR ALUNO -------------------------------\n");
					printf("\tINFORME A MATRICULA DO ALUNO PARA PODER EDITAR SEU NOME...\n");
					printf("\tMATRICULA: ");
					scanf("%d", &matricula);
					getchar();
					editarAluno(&listaAluno, matricula);
					system("pause");
					system("cls");
					break;
				case 2:
					system("cls");
					printf("\n");
					professoresCadastrados(&listaProfessor);

					printf("----------------------------- EDITAR PROFESSOR ------------------------------\n");
					printf("\tINFORME O CÓDIGO DO PROFESSOR PARA PODER EDITAR SEU NOME...\n");
					printf("\tCÓDIGO: ");
					scanf("%d", &codigo);
					getchar();
					editarProfessor(&listaProfessor, codigo);
					system("pause");
					system("cls");
					break;
				case 3:
					system("cls");
					printf("\n");
					disciplinasCadastradas(&listaDisciplina);

					printf("---------------------------- EDITAR DISCIPLINA ------------------------------\n");
					printf("\tINFORME O CÓDIGO DA DISCIPLINA PARA PODER EDITAR SEU NOME...\n");
					printf("\tCÓDIGO: ");
					scanf("%d", &codigo);
					getchar();
					editarDisciplina(&listaDisciplina, codigo);
					system("pause");
					system("cls");
					break;
				case 4:
					system("cls");
					printf("\n");
					// implementar editar turma
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
			} while (opcaoMenuEditar != 0);
			break;
		case 3:
			do 
			{
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

				switch (opcaoMenuExibir)
				{
				case 1:
					system("cls");
					printf("\n");
					alunosCadastrados(&listaAluno);
					system("pause");
					system("cls");
					break;
				case 2:
					system("cls");
					printf("\n");
					professoresCadastrados(&listaProfessor);
					system("pause");
					system("cls");
					break;
				case 3:
					system("cls");
					printf("\n");
					disciplinasCadastradas(&listaDisciplina);
					system("pause");
					system("cls");
					break;
				case 4:
					system("cls");
					printf("\n");
					// implementar exibir turma
					system("pause");
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
			} while (opcaoMenuExibir != 0);
			break;
		case 4:
			do 
			{
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

				switch (opcaoMenuExcluir)
				{
				case 1:
					system("cls");
					printf("\n");
					if (listaAluno.inicio == NULL) 
					{
						printf("-------------------------------- EXCLUIR ALUNO ------------------------------\n");
						printf("\tNENHUM ALUNO CADASTRADO...\n\n");
					}
					else 
					{
						alunosCadastrados(&listaAluno);

						printf("-------------------------------- EXCLUIR ALUNO ------------------------------\n");
						printf("\tINFORME A MATRICULA DO ALUNO PARA PODER EXCLUI-LO...\n");
						printf("\tMATRICULA: ");
						scanf("%d", &matricula);

						resultado = excluirAluno(&listaAluno, matricula);
						printf("\n");
						if (resultado)
						{
							printf("\tALUNO EXCLUÍDO COM SUCESSO.\n");
						}
						else
						{
							printf("\tMATRÍCULA INFORMADA NÃO ESTÁ CADASTRADA.\n");
						}
					}
					system("pause");
					system("cls");
					break;
				case 2:
					system("cls");
					printf("\n");
					if (listaProfessor.inicio == NULL) 
					{
						printf("----------------------------- EXCLUIR PROFESSOR ------------------------------\n");
						printf("\tNENHUM PROFESSOR CADASTRADO...\n\n");
					}
					else 
					{
						professoresCadastrados(&listaProfessor);

						printf("----------------------------- EXCLUIR PROFESSOR ------------------------------\n");
						printf("\tINFORME O CÓDIGO DO PROFESSOR PARA PODER EXCLUI-LO...\n");
						printf("\tCÓDIGO: ");
						scanf("%d", &codigo);

						resultado = excluirProfessor(&listaProfessor, codigo);
						printf("\n");
						if (resultado)
						{
							printf("\tPROFESSOR EXCLUÍDO COM SUCESSO.\n");
						}
						else
						{
							printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
						}
					}
					system("pause");
					system("cls");
					break;
				case 3:
					system("cls");
					printf("\n");
					if (listaDisciplina.inicio == NULL) 
					{
						printf("---------------------------- EXCLUIR DISCIPLINA ------------------------------\n");
						printf("\tNENHUMA DISCIPLINA CADASTRADA...\n\n");
					}
					else 
					{
						disciplinasCadastradas(&listaDisciplina);

						printf("---------------------------- EXCLUIR DISCIPLINA ------------------------------\n");
						printf("\tINFORME O CÓDIGO DA DISCIPLINA PARA PODER EXCLUI-LA...\n");
						printf("\tCÓDIGO: ");
						scanf("%d", &codigo);

						resultado = excluirDisciplina(&listaDisciplina, codigo);
						printf("\n");
						if (resultado)
						{
							printf("\tDISCIPLINA EXCLUÍDA COM SUCESSO.\n");
						}
						else
						{
							printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
						}
					}
					system("pause");
					system("cls");
					break;
				case 4:
					system("cls");
					printf("\n");
					// implementar excluir turma
					system("pause");
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
			} while (opcaoMenuExcluir != 0);
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
	
	system("pause");*/

	return 0;
}
