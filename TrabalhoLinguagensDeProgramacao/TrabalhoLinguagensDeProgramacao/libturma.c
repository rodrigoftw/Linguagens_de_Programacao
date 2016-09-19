#include "libturma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

turma *criarTurma(int codigo)
{
	turma *trm = malloc(sizeof(turma));
	trm->codigo = codigo;
	trm->professorDaTurma = NULL;
	trm->disciplinaDaTurma = NULL;
	trm->alunosDaTurma.inicio = NULL;
	trm->proximaTurma = NULL;
	return trm;
}

turma *buscarTurma(listaDeTurmas *lista, int codigo)
{
	turma *trmAux = lista->inicio;

	while (trmAux != NULL)
	{
		if (trmAux->codigo == codigo)
		{
			return trmAux;
		}
		trmAux = trmAux->proximaTurma;
	}
	return NULL;
}

void exibirTodasAsTurmas(listaDeTurmas *lista) 
{
	turma *trmAux = lista->inicio;

	while (trmAux != NULL)
	{
		printf("---------------------------------------------------------------------------\n");
		printf("\tTURMA:\t%d\n", trmAux->codigo);
		printf("\t\t\tCOD/MAT\t\tNOME\n");
		if (trmAux->professorDaTurma != NULL) 
		{
			printf("\tPROFESSOR:\t%d\t\t%s\n", trmAux->professorDaTurma->codigo, trmAux->professorDaTurma->nome);
		}
		else 
		{
			printf("\tPROFESSOR:\tNENHUM PROFESSOR CADASTRADO.\n");
		}
		if (trmAux->disciplinaDaTurma != NULL) 
		{
			printf("\tDISCIPLINA:\t%d\t\t%s\n", trmAux->disciplinaDaTurma->codigo, trmAux->disciplinaDaTurma->nome);
		}
		else 
		{
			printf("\tDISCIPLINA:\tNENHUMA DISCIPLINA CADASTRADA.\n");
		}

		aluno *alnAux = trmAux->alunosDaTurma.inicio;
		if (alnAux != NULL) 
		{
			while (alnAux != NULL)
			{
				printf("\tALUNO:\t\t%d\t\t%s\n", alnAux->matricula, alnAux->nome);
				alnAux = alnAux->proximoAluno;
			}
		}
		else
		{
			printf("\tALUNO:\t\tNENHUM ALUNO CADASTRADO.\n");
		}
		trmAux = trmAux->proximaTurma;
	}
	printf("---------------------------------------------------------------------------\n");
}

void exibirTurmaAtual(turma * trm) 
{
	printf("-----------------------------------------------------------------------------\n");
	printf("\tTURMA:\t%d\n", trm->codigo);
	printf("\t\t\tCOD/MAT\t\tNOME\n");
	if (trm->professorDaTurma != NULL)
	{
		printf("\tPROFESSOR:\t%d\t\t%s\n", trm->professorDaTurma->codigo, trm->professorDaTurma->nome);
	}
	else
	{
		printf("\tPROFESSOR:\tNENHUM PROFESSOR CADASTRADO.\n");
	}
	if (trm->disciplinaDaTurma != NULL)
	{
		printf("\tDISCIPLINA:\t%d\t\t%s\n", trm->disciplinaDaTurma->codigo, trm->disciplinaDaTurma->nome);
	}
	else
	{
		printf("\tDISCIPLINA:\tNENHUMA DISCIPLINA CADASTRADA.\n");
	}

	aluno *alnAux = trm->alunosDaTurma.inicio;
	if (alnAux != NULL)
	{
		while (alnAux != NULL)
		{
			printf("\tALUNO:\t\t%d\t\t%s\n", alnAux->matricula, alnAux->nome);
			alnAux = alnAux->proximoAluno;
		}
	}
	else
	{
		printf("\tALUNO:\t\tNENHUM ALUNO CADASTRADO.\n");
	}
	printf("\n");
}

turma *inserirTurma(listaDeTurmas *lista, int codigo) 
{
	turma *trm = criarTurma(codigo);

	if (lista->inicio == NULL)
	{
		lista->inicio = trm;
	}
	else
	{
		turma *trmAux = lista->inicio;

		while (true)
		{
			if (trmAux->proximaTurma == NULL)
			{
				trmAux->proximaTurma = trm;
				break;
			}
			trmAux = trmAux->proximaTurma;
		}
	}
	return trm;
}

bool inserirAlunoNaTurma(listaDeAlunos *lista, turma *trm, int matricula)
{
	bool resultado = false;
	aluno *aln = buscarAluno(lista, matricula);
	if (aln != NULL)
	{
		inserirAluno(&trm->alunosDaTurma, aln->matricula, aln->nome);
		resultado = true;
	}
	return resultado;
}

bool inserirProfessorNaTurma(listaDeProfessores *lista, turma *trm, int codigo) 
{
	bool resultado = false;
	professor *prof = buscarProfessor(lista, codigo);
	if (prof != NULL)
	{
		trm->professorDaTurma = prof;
		resultado = true;
	}
	return resultado;
}

bool inserirDisciplinaNaTurma(listaDeDisciplinas *lista, turma *trm, int codigo) 
{
	bool resultado = false;
	disciplina *discip = buscarDisciplina(lista, codigo);
	if (discip != NULL)
	{
		trm->disciplinaDaTurma = discip;
		resultado = true;
	}
	return resultado;
}

void atualizarTurmaPorEdicaoDeAluno(listaDeTurmas *lista, aluno *aln) 
{
	turma *trm = lista->inicio;
	aluno *alunoDaTurma;

	if (trm != NULL) 
	{
		while (trm != NULL)
		{
			alunoDaTurma = buscarAluno(&trm->alunosDaTurma, aln->matricula);
			if (alunoDaTurma != NULL) 
			{
				strcpy_s(alunoDaTurma->nome, 50, aln->nome);
			}
			trm = trm->proximaTurma;
		}
	}
}

void atualizarTurmaPorExclusaoDeAluno(listaDeTurmas *lista, int matricula) 
{
	turma *trm = lista->inicio;

	if (trm != NULL)
	{
		while (trm != NULL)
		{
			if (trm->alunosDaTurma.inicio != NULL) 
			{
				excluirAluno(&trm->alunosDaTurma, matricula);
			}
			trm = trm->proximaTurma;
		}
	}
}

void atualizarTurmaPorExclusaoDeProfessor(listaDeTurmas *lista, int codigo) 
{
	turma *trm = lista->inicio;
	professor *prof = NULL;

	if (trm != NULL) 
	{
		while (trm != NULL)
		{
			if (trm->professorDaTurma != NULL && trm->professorDaTurma->codigo == codigo) 
			{
				// atribuicao feita apenas para usar a funcao free posteriormente
				prof = trm->professorDaTurma;
				trm->professorDaTurma = NULL;
				
			}
			trm = trm->proximaTurma;
		}
		free(prof);
	}
}

void atualizarTurmaPorExclusaoDeDisciplina(listaDeDisciplinas *lista, int codigo) 
{
	turma *trm = lista->inicio;
	disciplina *discip = NULL;

	if (trm != NULL)
	{
		while (trm != NULL)
		{
			if (trm->disciplinaDaTurma != NULL && trm->disciplinaDaTurma->codigo == codigo)
			{
				// atribuicao feita apenas para usar a funcao free posteriormente
				discip = trm->disciplinaDaTurma;
				trm->disciplinaDaTurma = NULL;
			}
			trm = trm->proximaTurma;
		}
		free(discip);
	}
}

bool excluirTurma(listaDeTurmas *lista, int codigo) 
{
	turma *trmAtual = lista->inicio;
	bool resultado = false;

	// caso em que a turma a ser excluida esta na primeira posicao
	if (lista->inicio->codigo == codigo)
	{
		lista->inicio = lista->inicio->proximaTurma;
		free(trmAtual);
		resultado = true;
	}
	else
	{
		turma *trmAnterior = trmAtual;
		trmAtual = trmAtual->proximaTurma;

		while (trmAtual != NULL)
		{
			if (trmAtual->codigo == codigo)
			{
				trmAnterior->proximaTurma = trmAtual->proximaTurma;
				free(trmAtual);
				resultado = true;
				break;
			}
			trmAnterior = trmAtual;
			trmAtual = trmAtual->proximaTurma;
		}
	}
	return resultado;
}

bool excluirAlunoNaTurma(turma *trm, int matricula)
{
	return excluirAluno(&trm->alunosDaTurma, matricula);
}

void excluirProfessorNaTurma(turma *trm) 
{
	trm->professorDaTurma = NULL;
}

void excluirDisciplinaNaTurma(turma *trm) 
{
	trm->disciplinaDaTurma = NULL;
}