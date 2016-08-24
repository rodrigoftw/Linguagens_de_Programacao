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
	trm->alunosDaTurma->inicio = NULL;
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