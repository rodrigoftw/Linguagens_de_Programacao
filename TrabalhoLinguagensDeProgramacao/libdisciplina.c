#pragma warning (disable : 4996)
#include "libdisciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

disciplina *criarDisciplina(int codigo, char nome[51])
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
		if (discipAux->codigo == codigo)
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

void inserirDisciplina(listaDeDisciplinas *lista, int codigo, char nome[51])
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
			discipAux = discipAux->proximaDisciplina;
		}
	}
}

void editarDisciplina(listaDeDisciplinas *lista, int codigo)
{
	disciplina *discip = buscarDisciplina(lista, codigo);
	
	if (discip != NULL)
	{
		printf("\tNOME: ");
		gets_s(discip->nome, 50);
		printf("\n");
		printf("\tDISCIPLINA EDITADA COM SUCESSO.\n");
	}
	else
	{
		printf("\n");
		printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
	}
}

bool excluirDisciplina(listaDeDisciplinas *lista, int codigo)
{
	disciplina *discipAtual = lista->inicio;
	bool resultado = false;

	// caso em que o aluno a ser excluido esta na primeira posicao
	if (lista->inicio->codigo == codigo)
	{
		lista->inicio = lista->inicio->proximaDisciplina;
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
				resultado = true;
				break;
				// funcao free sera usada na funcao atualizarTurmaPorExclusaoDeDisciplina
			}
			discipAnterior = discipAtual;
			discipAtual = discipAtual->proximaDisciplina;
		}
	}
	return resultado;
}