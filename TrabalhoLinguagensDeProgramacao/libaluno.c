#pragma warning (disable : 4996)
#include "libaluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

	printf("\tMATRICULA\t NOME\n");

	while (alnAux != NULL)
	{
		printf("\t%d\t\t %s\n", alnAux->matricula, alnAux->nome);
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

	if (aln != NULL)
	{
		printf("\tNOME: ");
		gets_s(aln->nome, 50);
		printf("\n");
		printf("\tALUNO EDITADO COM SUCESSO.\n");
	}
	else
	{
		printf("\n");
		printf("\tMATRICULA INFORMADA NÃO ESTA CADASTRADA.\n");
	}
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