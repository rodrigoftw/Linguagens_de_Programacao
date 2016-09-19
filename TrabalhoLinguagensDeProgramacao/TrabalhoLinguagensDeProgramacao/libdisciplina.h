#ifndef LIBDISCIPLINA_H
#define LIBDISCIPLINA_H
#include "libboolean.h"

struct Disciplina
{
	int codigo;
	char nome[51];
	struct Disciplina *proximaDisciplina;
};

typedef struct Disciplina disciplina;

struct ListaDeDisciplinas
{
	disciplina *inicio;
};

typedef struct ListaDeDisciplinas listaDeDisciplinas;

disciplina *criarDisciplina(int codigo, char nome[50]);

disciplina *buscarDisciplina(listaDeDisciplinas *lista, int codigo);

void exibirTodasAsDisciplinas(listaDeDisciplinas *lista);

void inserirDisciplina(listaDeDisciplinas *lista, int codigo, char nome[50]);

void editarDisciplina(listaDeDisciplinas *lista, int codigo);

bool excluirDisciplina(listaDeDisciplinas *lista, int codigo);

#endif // !LIBDISCIPLINA_H