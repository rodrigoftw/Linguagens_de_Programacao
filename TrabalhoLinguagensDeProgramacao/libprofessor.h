#ifndef LIBPROFESSOR_H
#define LIBPROFESSOR_H
#include "libboolean.h"

struct Professor 
{
	int codigo;
	char nome[51];
	struct Professor *proximoProfessor;
};

typedef struct Professor professor;

struct ListaDeProfessores 
{
	professor *inicio;
};

typedef struct ListaDeProfessores listaDeProfessores;

professor *criarProfessor(int codigo, char nome[50]);

professor *buscarProfessor(listaDeProfessores *lista, int codigo);

void exibirTodosOsProfessores(listaDeProfessores *lista);

void inserirProfessor(listaDeProfessores *lista, int codigo, char nome[50]);

void editarProfessor(listaDeProfessores *lista, int codigo);

bool excluirProfessor(listaDeProfessores *lista, int codigo);

#endif // !LIBPROFESSOR_H
