#ifndef LIBALUNO_H
#define LIBALUNO_H
#include "libboolean.h"

struct Aluno
{
	int matricula;
	char nome[50];
	struct Aluno *proximoAluno;
};

typedef struct Aluno aluno;

struct ListaDeAlunos
{
	aluno *inicio;
};

typedef struct ListaDeAlunos listaDeAlunos;

aluno *criarAluno(int matricula, char nome[50]);

aluno *buscarAluno(listaDeAlunos *lista, int matricula);

void exibirTodosOsAlunos(listaDeAlunos *lista);

void inserirAluno(listaDeAlunos *lista, int matricula, char nome[50]);

void editarAluno(listaDeAlunos *lista, int matricula);

bool excluirAluno(listaDeAlunos *lista, int matricula);

#endif // !LIBALUNO_H
