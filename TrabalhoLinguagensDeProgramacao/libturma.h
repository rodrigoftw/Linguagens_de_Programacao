#include <stdio.h>
#include <stdlib.h>
#include "libaluno.h"
#include "libprofessor.h"
#include "libdisciplina.h"

struct Turma
{
	int codigo;
	professor *professorDaTurma;
	disciplina *disciplinaDaTurma;
	listaDeAlunos *alunosDaTurma;
	struct Turma *proximaTurma;
};

typedef struct Turma turma;

struct ListaDeTurmas 
{
	turma *inicio;
};

typedef struct ListaDeTurmas listaDeTurmas;

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

}


