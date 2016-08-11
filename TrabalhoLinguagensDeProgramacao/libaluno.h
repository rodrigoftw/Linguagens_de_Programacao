#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int matricula;
	char nome[50];
	struct aluno *proxAluno;
} aluno;

typedef struct 
{
	aluno *cabeca;
} listaDeAlunos;


aluno *criarAluno( int matricula, char nome[50])
{
	aluno *a = malloc(sizeof(aluno));
	a->matricula = matricula;
	strcpy(a->nome, nome);
	a->proxAluno = NULL;
	return a;
};

void inserirAluno(listaDeAlunos *lista, int matricula, char nome[50])
{
	
}
