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
	trm->alunosDaTurma = NULL;
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
		printf("\tPROFESSOR\t%d\t\t%s\n", trmAux->professorDaTurma->codigo, trmAux->professorDaTurma->nome);

		trmAux = trmAux->proximaTurma;
	}
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

bool inserirAlunoNaTurma(turma *trm, aluno *aln) 
{

}

bool inserirProfessorNaTurma(turma *trm, professor *prof) 
{
	bool resultado = false;

	if (trm->professorDaTurma == NULL)
	{
		trm->professorDaTurma = prof;
		resultado = true;
	}
	return resultado;
}

bool inserirDisciplinaNaTurma(turma *trm, disciplina *discip) 
{
	bool resultado = false;

	if (trm->disciplinaDaTurma == NULL)
	{
		trm->disciplinaDaTurma = discip;
		resultado = true;
	}
	return resultado;
}