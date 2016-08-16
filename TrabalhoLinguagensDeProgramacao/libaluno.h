#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

aluno *criarAluno(int matricula, char nome[50])
{
	aluno *aln = malloc(sizeof(aluno));
	aln->matricula = matricula;
	strcpy_s(aln->nome, 50, nome);
	aln->proximoAluno = NULL;
	return aln;
};

aluno *buscarAluno(listaDeAlunos *lista, int matricula) 
{
	aluno *alnAux = lista->inicio;

	while (alnAux != NULL)
	{
		if (alnAux->matricula == matricula)
		{
			return alnAux;
		}
		alnAux = alnAux->proximoAluno;
	}
	return NULL;
}

void exibirTodosOsAlunos(listaDeAlunos *lista)
{
	aluno *alnAux = lista->inicio;

	printf("\tID\t NOME\n");

	while (alnAux != NULL)
	{
		printf("\t%d\t %s\n", alnAux->matricula, alnAux->nome);
		alnAux = alnAux->proximoAluno;
	}
}

void inserirAluno(listaDeAlunos *lista, int matricula, char nome[50])
{
	aluno *aln = criarAluno(matricula, nome);

	if (lista->inicio == NULL)
	{
		lista->inicio = aln;
	}
	else
	{
		aluno *alnAux = lista->inicio;

		while (true)
		{
			if (alnAux->proximoAluno == NULL)
			{
				alnAux->proximoAluno = aln;
				return;
			}
			alnAux = alnAux->proximoAluno;
		}
	}
} 

// talvez seja necessario alterar essa funcao
// ver onde sera melhor colocar a verificacao se a funcao 'buscarAluno' não retorna o valor NULL
void editarAluno(listaDeAlunos *lista, int matricula) 
{
	aluno *aln = buscarAluno(lista, matricula);

	printf("\tNOME: ");
	scanf("%s", aln->nome);
}

bool excluirAluno(listaDeAlunos *lista, int matricula) 
{
	aluno *alnAtual = lista->inicio;
	bool resultado = false;

	// caso em que o aluno a ser excluido esta na primeira posicao
	if (lista->inicio->matricula == matricula)
	{
		lista->inicio = lista->inicio->proximoAluno;
		free(alnAtual);
		resultado = true;
	}
	else
	{
		aluno *alnAnterior = alnAtual;
		alnAtual = alnAtual->proximoAluno;

		while (alnAtual != NULL)
		{
			if (alnAtual->matricula == matricula)
			{
				alnAnterior->proximoAluno = alnAtual->proximoAluno;
				free(alnAtual);
				resultado = true;
				break;
			}
			alnAnterior = alnAtual;
			alnAtual = alnAtual->proximoAluno;
		}
	}
	return resultado;
}

