#ifndef LIBALUNO_H
#define LIBALUNO_H
#include "libboolean.h"

struct Aluno
{
	int matricula;
	char nome[51];
	struct Aluno *proximoAluno;
};

typedef struct Aluno aluno;

struct ListaDeAlunos
{
	aluno *inicio;
};

typedef struct ListaDeAlunos listaDeAlunos;

aluno *criarAluno(int matricula, char nome[51]);

aluno *buscarAluno(listaDeAlunos *lista, int matricula);

void exibirTodosOsAlunos(listaDeAlunos *lista);

void inserirAluno(listaDeAlunos *lista, int matricula, char nome[51]);

aluno *editarAluno(listaDeAlunos *lista, int matricula);

bool excluirAluno(listaDeAlunos *lista, int matricula);

#endif // !LIBALUNO_H
