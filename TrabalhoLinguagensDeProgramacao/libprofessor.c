#pragma warning (disable : 4996)
#include "libprofessor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

professor *criarProfessor(int codigo, char nome[51])
{
	professor *prof = malloc(sizeof(professor));
	prof->codigo = codigo;
	strcpy_s(prof->nome, 50, nome);
	prof->proximoProfessor = NULL;
	return prof;
}

professor *buscarProfessor(listaDeProfessores *lista, int codigo)
{
	professor *profAux = lista->inicio;

	while (profAux != NULL)
	{
		if (profAux->codigo == codigo)
		{
			return profAux;
		}
		profAux = profAux->proximoProfessor;
	}
	return NULL;
}

void exibirTodosOsProfessores(listaDeProfessores *lista)
{
	professor *profAux = lista->inicio;

	printf("\tCODIGO\t NOME\n");

	while (profAux != NULL)
	{
		printf("\t%d\t %s\n", profAux->codigo, profAux->nome);
		profAux = profAux->proximoProfessor;
	}
}

void inserirProfessor(listaDeProfessores *lista, int codigo, char nome[51])
{
	professor *prof = criarProfessor(codigo, nome);

	if (lista->inicio == NULL)
	{
		lista->inicio = prof;
	}
	else
	{
		professor *profAux = lista->inicio;

		while (true)
		{
			if (profAux->proximoProfessor == NULL)
			{
				profAux->proximoProfessor = prof;
				return;
			}
			profAux = profAux->proximoProfessor;
		}
	}
}

void editarProfessor(listaDeProfessores *lista, int codigo)
{
	professor *prof = buscarProfessor(lista, codigo);
	
	if (prof != NULL)
	{
		printf("\tNOME: ");
		gets_s(prof->nome, 50);
		printf("\n");
		printf("\tPROFESSOR EDITADO COM SUCESSO.\n");
	}
	else
	{
		printf("\n");
		printf("\tCÓDIGO INFORMADO NÃO ESTÁ CADASTRADO.\n");
	}
}

bool excluirProfessor(listaDeProfessores *lista, int codigo)
{
	professor *profAtual = lista->inicio;
	bool resultado = false;

	// caso em que o aluno a ser excluido esta na primeira posicao
	if (lista->inicio->codigo == codigo)
	{
		lista->inicio = lista->inicio->proximoProfessor;
		resultado = true;
	}
	else
	{
		professor *profAnterior = profAtual;
		profAtual = profAtual->proximoProfessor;

		while (profAtual != NULL)
		{
			if (profAtual->codigo == codigo)
			{
				profAnterior->proximoProfessor = profAtual->proximoProfessor;
				profAtual->proximoProfessor = NULL;
				resultado = true;
				break;
			}
			profAnterior = profAtual;
			profAtual = profAtual->proximoProfessor;
		}
	}
	return resultado;
	// funcao free sera usada na funcao atualizarTurmaPorExclusaoDeProfessor
}