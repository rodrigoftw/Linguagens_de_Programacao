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
		printf("-----------------------------------------------------------------------------\n");
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
			printf("\tALUNO:\t\tNENHUM PROFESSOR CADASTRADO.\n");
		}
		trmAux = trmAux->proximaTurma;
	}
	printf("-----------------------------------------------------------------------------\n");
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

void excluirAlunoNaTurma(turma *trm, aluno *aln) 
{

}

void excluirProfessorNaTurma(turma *trm) 
{
	trm->professorDaTurma = NULL;
}

void excluirDisciplinaNaTurma(turma *trm) 
{
	trm->disciplinaDaTurma = NULL;
}