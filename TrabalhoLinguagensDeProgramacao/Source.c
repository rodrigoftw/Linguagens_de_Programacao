#pragma warning (disable : 4996)
#include "libaluno.h"
#include "libprofessor.h"
#include "libdisciplina.h"
#include "libturma.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// exibir os alunos cadastrados ate o momento
void alunosCadastrados(listaDeAlunos *lista) 
{
	printf("---------------------------- ALUNOS CADASTRADOS ----------------------------\n");
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

// exibir os professores cadastrados ate o momento
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

// exibir as disciplinas cadastradas ate o momento
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

// exibir o codigo das turmas cadastradas ate o momento
void turmasCadastradas(listaDeTurmas *lista) 
{
	printf("---------------------------- TURMAS CADASTRADAS ----------------------------\n");
	
	turma *trmAux = lista->inicio;

	if (trmAux != NULL)
	{
		printf("\tCÓDIGO\n");
		while (trmAux != NULL)
		{
			printf("\t%d\n", trmAux->codigo);
			trmAux = trmAux->proximaTurma;
		}
	}
	else
	{
		printf("\tNENHUMA TURMA CADASTRADA...\n\n");
	}
}

// exibir os alunos da turma
void alunosDaTurma(turma *trm) 
{
	printf("----------------------------- ALUNOS DA TURMA ------------------------------\n");
	
	aluno *aln = trm->alunosDaTurma.inicio;

	if (aln != NULL) 
	{
		printf("\tMATRICULA\t NOME\n");

		while (aln != NULL)
		{
			printf("\t%d\t\t %s\n", aln->matricula, aln->nome);
			aln = aln->proximoAluno;
		}
		printf("\n");
	}
	else 
	{
		printf("\tA TURMA NÃO POSSUI ALUNOS.\n\n");
	}
}

// exibir o professor da turma
void professorDaTurma(turma *trm) 
{
	printf("---------------------------- PROFESSOR DA TURMA ----------------------------\n");

	professor *prof = trm->professorDaTurma;

	if (prof != NULL) 
	{
		printf("\tCÓDIGO\t NOME\n");
		printf("\t%d \t%s\n\n", prof->codigo, prof->nome);
	}
	else
	{
		printf("\tA TURMA NÃO POSSUI PROFESSOR CADASTRADO.\n\n");
	}
}

// exibir a disciplina da turma
void disciplinaDaTurma(turma *trm)
{
	printf("--------------------------- DISCIPLINA DA TURMA ----------------------------\n");

	disciplina *discip = trm->disciplinaDaTurma;

	if (discip != NULL)
	{
		printf("\tCÓDIGO\t NOME\n");
		printf("\t%d \t%s\n\n", discip->codigo, discip->nome);
	}
	else
	{
		printf("\tA TURMA NÃO POSSUI DISCIPLINA CADASTRADA.\n\n");
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

	// INSERÇÕES ESTÁTICAS
	inserirAluno(&listaAluno, 1, "Fabiano Abreu");
	inserirAluno(&listaAluno, 2, "Rodrigo Andrade");
	inserirAluno(&listaAluno, 3, "Luis Augusto");
	inserirAluno(&listaAluno, 4, "Morgana Almeida");
	inserirAluno(&listaAluno, 5, "Matheus Souza");
	inserirProfessor(&listaProfessor, 1, "Roberio Gomes");
	inserirProfessor(&listaProfessor, 2, "Alexandre Cavalcante");
	inserirProfessor(&listaProfessor, 3, "Ciro Coelho");
	inserirProfessor(&listaProfessor, 4, "Andre Bessa");
	inserirProfessor(&listaProfessor, 5, "Eduardo Mendes");
	inserirDisciplina(&listaDisciplina, 1, "Computacao Grafica");
	inserirDisciplina(&listaDisciplina, 2, "Computacao Basica");
	inserirDisciplina(&listaDisciplina, 3, "Linguagens de Programacao");
	inserirDisciplina(&listaDisciplina, 4, "Engenharia de Software");

	turma *trm = inserirTurma(&listaTurma, 1);
	inserirProfessorNaTurma(&listaProfessor,trm, 3);
	inserirDisciplinaNaTurma(&listaDisciplina, trm, 3);
	inserirAlunoNaTurma(&listaAluno, trm, 1);
	inserirAlunoNaTurma(&listaAluno, trm, 2);
	inserirTurma(&listaTurma, 2);
	inserirTurma(&listaTurma, 3);

	int matricula;
	int codigo;
	char nome[51];
	int opcaoMenuPrincipal;
	int opcaoMenuInserir;
	int opcaoMenuEditar;
	int opcaoMenuExibir;
	int opcaoMenuExcluir;
	int opcaoInserirNaTurma;
	int opcaoEditarTurma;
	int opcaoExluirTurma;
	char resposta;
	bool resultado;
	aluno *aln;

	do 
	{
		printf("------------------------------- MENU PRINCIPAL -----------------------------\n");
		printf("\t1 - INSERIR\n");
		printf("\t2 - EDITAR\n");
		printf("\t3 - EXIBIR\n");
		printf("\t4 - EXCLUIR\n");
		printf("\t0 - SAIR\n");
		printf("----------------------------------------------------------------------------\n");
		printf("\tESCOLHA A OPÇÃO DESEJADA: ");
		scanf("%d", &opcaoMenuPrincipal);

		system("cls");

		switch (opcaoMenuPrincipal)
		{
			case 1:
				do 
				{
					printf("------------------------------- MENU INSERIR -------------------------------\n");
					printf("\t1 - INSERIR ALUNO\n");
					printf("\t2 - INSERIR PROFESSOR\n");
					printf("\t3 - INSERIR DISCIPLINA\n");
					printf("\t4 - INSERIR TURMA\n");
					printf("\t0 - VOLTAR AO MENU PRINCIPAL\n");
					printf("----------------------------------------------------------------------------\n");
					printf("\tESCOLHA A OPÇÃO DESEJADA: ");
					scanf("%d", &opcaoMenuInserir);

					system("cls");

					switch (opcaoMenuInserir)
					{
						case 1:
							alunosCadastrados(&listaAluno);
							printf("------------------------------- INSERIR ALUNO -------------------------------\n");
							printf("\tINFORME A MATRICULA E O NOME DO ALUNO OU\n");
							printf("\tO VALOR '0' PARA VOLTAR AO MENU ANTERIOR: ");
							//printf("\tMATRICULA: ");
							scanf("%d", &matricula);

							if (matricula == 0) {
								system("cls");
								break;
							}

							// função necessaria para pegar o \n do buffer do teclado
							// caso contrario, a string nome ira armazenar o \n
							getchar();
							printf("\tNOME: ");
							gets_s(nome, 50);
							printf("\n");
							aln = buscarAluno(&listaAluno, matricula);
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
							break;
						case 2:
							professoresCadastrados(&listaProfessor);
							printf("----------------------------- INSERIR PROFESSOR -----------------------------\n");
							printf("\tINFORME UM CÓDIGO(NUMÉRICO) E O NOME DO PROFESSOR\n");
							printf("\tOU INSIRA O VALOR '0' PARA VOLTAR AO MENU ANTERIOR: ");
							//printf("\tCÓDIGO: ");
							scanf("%d", &codigo);

							if (codigo == 0) {
								system("cls");
								break;
							}

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
							break;
						case 3:
							disciplinasCadastradas(&listaDisciplina);
							printf("---------------------------- INSERIR DISCIPLINA -----------------------------\n");
							printf("\tINFORME UM CÓDIGO(NUMÉRICO) E O NOME DA DISCIPLINA\n");
							printf("\tOU INSIRA O VALOR '0' PARA VOLTAR AO MENU ANTERIOR: ");
							//printf("\tCÓDIGO: ");
							scanf("%d", &codigo);

							if (codigo == 0) {
								system("cls");
								break;
							}

							getchar();
							disciplina *discip = buscarDisciplina(&listaDisciplina, codigo);
							if (discip == NULL)
							{
								printf("\tNOME: ");
								gets_s(nome, 50);
								printf("\n");
								inserirDisciplina(&listaDisciplina, codigo, nome);
								printf("\tDISCIPLINA INSERIDA COM SUCESSO.\n");
							}
							else
							{
								printf("\n");
								printf("\tNÃO FOI POSSÍVEL INSERIR A DISCIPLINA. CÓDIGO JÁ CADASTRADO.\n");
							}
							system("pause");
							break;
						case 4:
							turmasCadastradas(&listaTurma);
							printf("------------------------------- INSERIR TURMA ------------------------------\n");
							printf("\tINFORME UM CÓDIGO(NUMÉRICO) PARA A TURMA OU\n");
							printf("\tO VALOR '0' PARA VOLTAR AO MENU ANTERIOR: ");
							//printf("\tCÓDIGO: ");
							scanf("%d", &codigo);

							if (codigo == 0) {
								system("cls");
								break;
							}

							turma *turmaJaFoiInserida = buscarTurma(&listaTurma, codigo);
							if (turmaJaFoiInserida == NULL)
							{
								// inserindo uma nova turma
								// trm recebe a turma recem criada
								trm = inserirTurma(&listaTurma, codigo);
								printf("\n");
								printf("\tTURMA INSERIDA COM SUCESSO.\n");
								system("pause");
							}
							else
							{
								printf("\n");
								printf("\tNÃO FOI POSSÍVEL INSERIR A TURMA. CÓDIGO JÁ CADASTRADO.\n");
								system("pause");
								break;
							}

							system("cls");

							do 
							{
								printf("----------------------------- INSERIR NA TURMA ----------------------------\n");
								printf("\t1 - INSERIR ALUNO\n");
								printf("\t2 - INSERIR PROFESSOR\n");
								printf("\t3 - INSERIR DISCIPLINA\n");
								printf("\t0 - VOLTAR AO MENU ANTERIOR\n");
								printf("---------------------------------------------------------------------------\n");
								printf("\tESCOLHA A OPÇÃO DESEJADA: ");
								scanf("%d", &opcaoInserirNaTurma);

								system("cls");

								switch (opcaoInserirNaTurma)
								{
									case 1:
										alunosCadastrados(&listaAluno);
										alunosDaTurma(trm);
										printf("-------------------------- INSERIR ALUNO NA TURMA --------------------------\n");
										printf("\tINFORME A MATRICULA DO ALUNO: ");
										scanf("%d", &matricula);
										printf("\n");
										aln = buscarAluno(&trm->alunosDaTurma, matricula);
										if (aln == NULL) 
										{
											resultado = inserirAlunoNaTurma(&listaAluno, trm, matricula);
											if (resultado)
											{
												printf("\tALUNO ADICIONADO COM SUCESSO.\n");
											}
											else
											{
												printf("\tMATRICULA INFORMADA NÃO ESTÁ CADASTRADA.\n");
											}
										}
										else 
										{
											printf("\tO ALUNO JÁ ESTÁ CASDASTRADO NA TURMA.\n");
										}
										system("pause");
										break;
									case 2:
										// verifica se o usuario ja adicionou um professor
										if (trm->professorDaTurma == NULL)
										{
											professoresCadastrados(&listaProfessor);
											printf("------------------------ INSERIR PROFESSOR NA TURMA -----------------------\n");
											printf("\tINFORME O CÓDIGO DO PROFESSOR: ");
											scanf("%d", &codigo);
											printf("\n");
											resultado = inserirProfessorNaTurma(&listaProfessor, trm, codigo);
											if (resultado) 
											{
												printf("\tPROFESSOR ADICIONADO COM SUCESSO.\n");
											}
											else
											{
												printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
											}
										}
										else
										{
											professorDaTurma(trm);
											printf("------------------------ INSERIR PROFESSOR NA TURMA ------------------------\n");
											printf("\tPROFESSOR JÁ ADICIONADO.\n");
											printf("\tSE DESEJAR ALTERAR O PROFESSOR, FAVOR SE DIRIGIR AO MENU EDITAR.\n\n");
										}
										system("pause");
										break;
									case 3:
										// verifica se o usuario ja adicionou uma disciplina
										if (trm->disciplinaDaTurma == NULL)
										{
											disciplinasCadastradas(&listaDisciplina);
											printf("----------------------- INSERIR DISCIPLINA NA TURMA -----------------------\n");
											printf("\tINFORME O CÓDIGO DA DISCIPLINA: ");
											scanf("%d", &codigo);
											printf("\n");
											resultado = inserirDisciplinaNaTurma(&listaDisciplina, trm, codigo);
											if (resultado)
											{
												printf("\tDISCIPLINA ADICIONADA COM SUCESSO.\n");
											}
											else
											{
												printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
											}
										}
										else
										{
											disciplinaDaTurma(trm);
											printf("----------------------- INSERIR DISCIPLINA NA TURMA -----------------------\n");
											printf("\tDISCIPLINA JÁ ADICIONADA.\n");
											printf("\tSE DESEJAR ALTERAR A DISCIPLINA, FAVOR SE DIRIGIR AO MENU EDITAR.\n\n");
										}
										system("pause");
										break;
									case 0:
										break;
									default:
										printf("\n");
										printf("\tOPÇÃO INVÁLIDA\n");
										system("pause");
										break;
								}
								system("cls");
							} while (opcaoInserirNaTurma != 0);
							break;
						case 0:
							break;
						default:
							printf("\n");
							printf("\tOPÇÃO INVÁLIDA\n");
							system("pause");
							break;
					}
					system("cls");
				} while (opcaoMenuInserir != 0);
				break;
			case 2:
				do 
				{
					printf("------------------------------- MENU EDITAR --------------------------------\n");
					printf("\t1 - EDITAR ALUNO\n");
					printf("\t2 - EDITAR PROFESSOR\n");
					printf("\t3 - EDITAR DISCIPLINA\n");
					printf("\t4 - EDITAR TURMA\n");
					printf("\t0 - VOLTAR AO MENU PRINCIPAL\n");
					printf("----------------------------------------------------------------------------\n");
					printf("\tESCOLHA A OPÇÃO DESEJADA: ");
					scanf("%d", &opcaoMenuEditar);

					system("cls");

					switch (opcaoMenuEditar)
					{
						case 1:
							alunosCadastrados(&listaAluno);
							printf("-------------------------------- EDITAR ALUNO -------------------------------\n");
							printf("\tINFORME A MATRICULA DO ALUNO PARA PODER EDITAR SEU NOME...\n");
							printf("\tMATRICULA: ");
							scanf("%d", &matricula);
							getchar();
							aln = editarAluno(&listaAluno, matricula);
							// atualizar o nome do aluno nas turma que ele esta cadastrado
							if (aln != NULL) 
							{
								atualizarTurmaPorEdicaoDeAluno(&listaTurma, aln);
							}
							system("pause");
							break;
						case 2:
							professoresCadastrados(&listaProfessor);
							printf("----------------------------- EDITAR PROFESSOR ------------------------------\n");
							printf("\tINFORME O CÓDIGO DO PROFESSOR PARA PODER EDITAR SEU NOME...\n");
							printf("\tCÓDIGO: ");
							scanf("%d", &codigo);
							getchar();
							editarProfessor(&listaProfessor, codigo);
							system("pause");
							break;
						case 3:
							disciplinasCadastradas(&listaDisciplina);
							printf("---------------------------- EDITAR DISCIPLINA ------------------------------\n");
							printf("\tINFORME O CÓDIGO DA DISCIPLINA PARA PODER EDITAR SEU NOME...\n");
							printf("\tCÓDIGO: ");
							scanf("%d", &codigo);
							getchar();
							editarDisciplina(&listaDisciplina, codigo);
							system("pause");
							break;
						case 4:
							turmasCadastradas(&listaTurma);
							printf("------------------------------- EDITAR TURMA --------------------------------\n");
							printf("\tINFORME O CÓDIGO DA TURMA QUE DESEJA EDITAR...\n");
							printf("\tCÓDIGO: ");
							scanf("%d", &codigo);
							trm = buscarTurma(&listaTurma, codigo);
							if (trm != NULL)
							{
								system("cls");

								do
								{
									printf("------------------------------- EDITAR TURMA --------------------------------\n");
									printf("\t1 - EDITAR ALUNO\n");
									printf("\t2 - EDITAR PROFESSOR\n");
									printf("\t3 - EDITAR DISCIPLINA\n");
									printf("\t0 - VOLTAR AO MENU ANTERIOR\n");
									printf("-----------------------------------------------------------------------------\n");
									printf("\tESCOLHA A OPÇÃO DESEJADA: ");
									scanf("%d", &opcaoEditarTurma);

									system("cls");

									switch (opcaoEditarTurma)
									{
										case 1:
											alunosCadastrados(&listaAluno);
											alunosDaTurma(trm);
											printf("-------------------------- INSERIR ALUNO NA TURMA --------------------------\n");
											printf("\tINFORME A MATRICULA DO ALUNO OU INSIRA\n");
											printf("\tO VALOR '0' PARA VOLTAR AO MENU ANTERIOR: ");
											scanf("%d", &matricula);
											printf("\n");
											if (matricula == 0) {
												system("cls");
												break;
											}
											aln = buscarAluno(&trm->alunosDaTurma, matricula);
											if (aln == NULL)
											{
												resultado = inserirAlunoNaTurma(&listaAluno, trm, matricula);
												if (resultado)
												{
													printf("\tALUNO ADICIONADO COM SUCESSO.\n");
												}
												else
												{
													printf("\tMATRICULA INFORMADA NÃO ESTÁ CADASTRADA.\n");
												}
											}
											else
											{
												printf("\tO ALUNO JÁ ESTÁ CASDASTRADO NA TURMA.\n");
											}
											system("pause");
											break;
										case 2:
											professoresCadastrados(&listaProfessor);
											professorDaTurma(trm);
											printf("------------------------ EDITAR PROFESSOR DA TURMA ------------------------\n");
											printf("\tINFORME O CÓDIGO DO PROFESSOR OU INSIRA\n");
											printf("\tO VALOR '0' PARA VOLTAR AO MENU ANTERIOR: ");
											scanf("%d", &codigo);
											printf("\n");
											if (codigo == 0) {
												system("cls");
												break;
											}
											resultado = inserirProfessorNaTurma(&listaProfessor, trm, codigo);
											if (resultado)
											{
												printf("\tPROFESSOR ALTERADO COM SUCESSO.\n");
											}
											else
											{
												printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
											}
											system("pause");
											break;
										case 3:
											disciplinasCadastradas(&listaDisciplina);
											disciplinaDaTurma(trm);
											printf("----------------------- EDITAR DISCIPLINA DA TURMA ------------------------\n");
											printf("\tINFORME O CÓDIGO DA DISCIPLINA OU INSIRA\n");
											printf("\tO VALOR '0' PARA VOLTAR AO MENU ANTERIOR: ");
											scanf("%d", &codigo);
											printf("\n");
											if (codigo == 0) {
												system("cls");
												break;
											}
											resultado = inserirDisciplinaNaTurma(&listaDisciplina, trm, codigo);
											if (resultado)
											{
												printf("\tDISCIPLINA ALTERADA COM SUCESSO.\n");
												system("pause");
											}
											else
											{
												printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
												system("pause");
											}
										case 0:
											break;
										default:
											printf("\n");
											printf("\tOPÇÃO INVÁLIDA\n");
											system("pause");
											break;
									}
									system("cls");
								} while (opcaoEditarTurma != 0);
							}
							else 
							{
								printf("\n");
								printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
							}
							system("cls");
							break;
						case 0:
							break;
						default:
							printf("\n");
							printf("\tOPÇÃO INVÁLIDA\n");
							system("pause");
							break;
					}
					system("cls");
				} while (opcaoMenuEditar != 0);
				break;
			case 3:
				do 
				{
					printf("------------------------------- MENU EXIBIR --------------------------------\n");
					printf("\t1 - EXIBIR ALUNO\n");
					printf("\t2 - EXIBIR PROFESSOR\n");
					printf("\t3 - EXIBIR DISCIPLINA\n");
					printf("\t4 - EXIBIR TURMA\n");
					printf("\t0 - VOLTAR AO MENU PRINCIPAL\n");
					printf("----------------------------------------------------------------------------\n");
					printf("\tESCOLHA A OPÇÃO DESEJADA: ");
					scanf("%d", &opcaoMenuExibir);

					system("cls");

					switch (opcaoMenuExibir)
					{
						case 1:
							alunosCadastrados(&listaAluno);
							system("pause");
							break;
						case 2:
							professoresCadastrados(&listaProfessor);
							system("pause");
							break;
						case 3:
							disciplinasCadastradas(&listaDisciplina);
							system("pause");
							break;
						case 4:
							exibirTodasAsTurmas(&listaTurma);
							system("pause");
							break;
						case 0:
							break;
						default:
							printf("\n");
							printf("\tOPÇÃO INVÁLIDA\n");
							system("pause");
							break;
					}
					system("cls");
				} while (opcaoMenuExibir != 0);
				break;
			case 4:
				do 
				{
					printf("------------------------------- MENU EXCLUIR -------------------------------\n");
					printf("\t1 - EXCLUIR ALUNO\n");
					printf("\t2 - EXCLUIR PROFESSOR\n");
					printf("\t3 - EXCLUIR DISCIPLINA\n");
					printf("\t4 - EXCLUIR TURMA\n");
					printf("\t0 - VOLTAR AO MENU PRINCIPAL\n");
					printf("----------------------------------------------------------------------------\n");
					printf("\tESCOLHA A OPÇÃO DESEJADA: ");
					scanf("%d", &opcaoMenuExcluir);

					system("cls");

					switch (opcaoMenuExcluir)
					{
						case 1:
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
									atualizarTurmaPorExclusaoDeAluno(&listaTurma, matricula);
								}
								else
								{
									printf("\tMATRÍCULA INFORMADA NÃO ESTÁ CADASTRADA.\n");
								}
							}
							system("pause");
							break;
						case 2:
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
									atualizarTurmaPorExclusaoDeProfessor(&listaTurma, codigo);
								}
								else
								{
									printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
								}
							}
							system("pause");
							break;
						case 3:
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
									atualizarTurmaPorExclusaoDeDisciplina(&listaTurma, codigo);
								}
								else
								{
									printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
								}
							}
							system("pause");
							break;
						case 4:
							turmasCadastradas(&listaTurma);
							printf("------------------------------ EXCLUIR TURMA -------------------------------\n");
							printf("\tINFORME O CÓDIGO DA TURMA E ESCOLHA AS OPCÕES A SEGUIR...\n");
							printf("\tCÓDIGO: ");
							scanf("%d", &codigo);
							trm = buscarTurma(&listaTurma, codigo);
							if (trm != NULL)
							{
								system("cls");

								do
								{
									printf("------------------------------ EXCLUIR TURMA -------------------------------\n");
									printf("\t1 - EXCLUIR ALUNO\n");
									printf("\t2 - EXCLUIR PROFESSOR\n");
									printf("\t3 - EXCLUIR DISCIPLINA\n");
									printf("\t4 - EXCLUIR A TURMA\n");
									printf("\t0 - VOLTAR AO MENU ANTERIOR\n");
									printf("----------------------------------------------------------------------------\n");
									printf("\tESCOLHA A OPÇÃO DESEJADA: ");
									scanf("%d", &opcaoExluirTurma);

									system("cls");

									switch (opcaoExluirTurma)
									{
										case 1:
											if (trm->alunosDaTurma.inicio != NULL) 
											{
												alunosDaTurma(trm);
												printf("-------------------------- EXCLUIR ALUNO DA TURMA --------------------------\n");
												printf("\tINFORME A MATRÍCULA DO ALUNO...\n");
												printf("\tMATRÍCULA: ");
												scanf("%d", &matricula);
												printf("\n");
												resultado = excluirAlunoNaTurma(trm, matricula);
												if (resultado)
												{
													printf("\tALUNO EXCLUÍDO COM SUCESSO.\n\n");
												}
												else
												{
													printf("\tMATRÍCULA INFORMADA NÃO ESTÁ CADASTRADA NA TURMA.\n");
												}
											}
											else
											{
												printf("-------------------------- EXCLUIR ALUNO DA TURMA --------------------------\n");
												printf("\tA TURMA NÃO POSSUI ALUNOS.\n\n");

											}
											system("pause");
											break;
										case 2:
											if (trm->professorDaTurma != NULL) 
											{
												professorDaTurma(trm);
												printf("------------------------ EXCLUIR PROFESSOR DA TURMA ------------------------\n");
												printf("\tTEM CERTEZA QUE DESEJA EXCLUIR?\n");
												printf("\tDIGITE 'S' PARA SIM OU 'N' PARA NÃO: ");
												getchar();
												scanf("%c", &resposta);
												printf("\n");
												if (resposta == 'S' || resposta == 's')
												{
													excluirProfessorNaTurma(trm);
													printf("\tPROFESSOR EXCLUÍDO COM SUCESSO.\n");
												}
												else if (resposta == 'N' || resposta == 'n')
												{
													printf("\tOPERAÇÃO CANCELADA.\n");
												}
												else
												{
													printf("\tRESPOSTA INVÁLIDA.\n");
												}
											}
											else
											{
												printf("------------------------ EXCLUIR PROFESSOR DA TURMA ------------------------\n");
												printf("\tA TURMA NÃO POSSUI PROFESSOR.\n\n");
											}
											system("pause");
											break;
										case 3:
											if (trm->disciplinaDaTurma != NULL) 
											{
												disciplinaDaTurma(trm);
												printf("----------------------- EXCLUIR DISCIPLINA DA TURMA ------------------------\n");
												printf("\tTEM CERTEZA QUE DESEJA EXCLUIR?\n");
												printf("\tDIGITE 'S' PARA SIM OU 'N' PARA NÃO: ");
												getchar();
												scanf("%c", &resposta);
												printf("\n");
												if (resposta == 'S' || resposta == 's')
												{
													excluirDisciplinaNaTurma(trm);
													printf("\tPROFESSOR EXCLUÍDO COM SUCESSO.\n");
												}
												else if (resposta == 'N' || resposta == 'n')
												{
													printf("\tOPERAÇÃO CANCELADA.\n");
												}
												else
												{
													printf("\tRESPOSTA INVÁLIDA.\n");
												}
											}
											else
											{
												printf("----------------------- EXCLUIR DISCIPLINA DA TURMA ------------------------\n");
												printf("\tA TURMA NÃO POSSUI DISCIPLINA.\n\n");
											}
											system("pause");
											break;
										case 4:
											exibirTurmaAtual(trm);
											printf("------------------------------ EXCLUIR TURMA -------------------------------\n");
											printf("\tTEM CERTEZA QUE DESEJA EXCLUIR?\n");
											printf("\tDIGITE 'S' PARA SIM OU 'N' PARA NÃO: ");
											getchar();
											scanf("%c", &resposta);
											printf("\n");
											if (resposta == 'S' || resposta == 's')
											{
												resultado = excluirTurma(&listaTurma, codigo);
												if (resultado)
												{
													printf("\tTURMA EXCLUÍDA COM SUCESSO.\n");
													opcaoExluirTurma = 0;
												}
												else
												{
													printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
												}
											}
											else if (resposta == 'N' || resposta == 'n')
											{
												printf("\tOPERAÇÃO CANCELADA.\n");
											}
											else
											{
												printf("\tRESPOSTA INVÁLIDA.\n");
											}
											system("pause");
											break;
										case 0:
											break;
										default:
											printf("\n");
											printf("\tOPÇÃO INVÁLIDA\n");
											system("pause");
											break;
									}
									system("cls");
								} while (opcaoExluirTurma != 0);
							}
							else
							{
								printf("\n");
								printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
							}
							break;
						case 0:
							break;
						default:
							printf("\n");
							printf("\tOPÇÃO INVÁLIDA\n");
							system("pause");
							break;
					}
					system("cls");
				} while (opcaoMenuExcluir != 0);
				break;
			case 0:
				break;
			default:
				printf("\n");
				printf("\tOPÇÃO INVÁLIDA\n");
				system("pause");
				break;
			}
			system("cls");
	} while (opcaoMenuPrincipal != 0);
	
	system("pause");

	return 0;
}
