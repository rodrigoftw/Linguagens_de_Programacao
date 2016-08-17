#include "libdisciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

disciplina *criarDisciplina(int codigo, char nome[50])
{
	disciplina *discip = malloc(sizeof(disciplina));
	discip->codigo = codigo;
	strcpy_s(discip->nome, 50, nome);
	discip->proximaDisciplina = NULL;
	return discip;
}

disciplina *buscarDisciplina(listaDeDisciplinas *lista, int codigo)
{
	disciplina *discipAux = lista->inicio;

	while (discipAux != NULL)
	{
		if (discipAux->codigo = codigo)
		{
			return discipAux;
		}
		discipAux = discipAux->proximaDisciplina;
	}
	return NULL;
}

void exibirTodasAsDisciplinas(listaDeDisciplinas *lista)
{
	disciplina *discip = lista->inicio;

	printf("\tCODIGO\t NOME\n");

	while (discip != NULL)
	{
		printf("\t%d\t %s\n", discip->codigo, discip->nome);
		discip = discip->proximaDisciplina;
	}
}

void inserirDisciplina(listaDeDisciplinas *lista, int codigo, char nome[50])
{
	disciplina *discip = criarDisciplina(codigo, nome);

	if (lista->inicio == NULL)
	{
		lista->inicio = discip;
	}
	else
	{
		disciplina *discipAux = lista->inicio;

		while (true)
		{
			if (discipAux->proximaDisciplina == NULL)
			{
				discipAux->proximaDisciplina = discip;
				return;
			}
			discip = discip->proximaDisciplina;
		}
	}
}

void editarDisciplina(listaDeDisciplinas *lista, int codigo)
{
	disciplina *discip = buscarDisciplina(lista, codigo);

	printf("\tNOME: ");
	scanf("%s", discip->nome);
}

bool excluirDisciplina(listaDeDisciplinas *lista, int codigo)
{
	disciplina *discipAtual = lista->inicio;
	bool resultado = false;

	// caso em que o aluno a ser excluido esta na primeira posicao
	if (lista->inicio->codigo == codigo)
	{
		lista->inicio = lista->inicio->proximaDisciplina;
		free(discipAtual);
		resultado = true;
	}
	else
	{
		disciplina *discipAnterior = discipAtual;
		discipAtual = discipAtual->proximaDisciplina;

		while (discipAtual != NULL)
		{
			if (discipAtual->codigo == codigo)
			{
				discipAnterior->proximaDisciplina = discipAtual->proximaDisciplina;
				free(discipAtual);
				resultado = true;
				break;
			}
			discipAnterior = discipAtual;
			discipAtual = discipAtual->proximaDisciplina;
		}
	}
	return resultado;
}