#ifndef LIBTURMA_H
#define LIBTURMA_H
#include "libaluno.h"
#include "libprofessor.h"
#include "libdisciplina.h"
#include "libboolean.h"

struct Turma
{
	int codigo;
	professor *professorDaTurma;
	disciplina *disciplinaDaTurma;
	listaDeAlunos alunosDaTurma;
	struct Turma *proximaTurma;
};

typedef struct Turma turma;

struct ListaDeTurmas
{
	turma *inicio;
};

typedef struct ListaDeTurmas listaDeTurmas;

turma *criarTurma(int codigo);

turma *buscarTurma(listaDeTurmas *lista, int codigo);

void exibirTodasAsTurmas(listaDeTurmas *lista);

void exibirTurmaAtual(turma * trm);

turma *inserirTurma(listaDeTurmas *lista, int codigo);

bool inserirAlunoNaTurma(listaDeAlunos *lista, turma *trm, int matricula);

bool inserirProfessorNaTurma(listaDeProfessores *lista, turma *trm, int codigo);

bool inserirDisciplinaNaTurma(listaDeDisciplinas *lista, turma *trm, int codigo);

void atualizarTurmaPorEdicaoDeAluno(listaDeTurmas *lista, aluno *aln);

void atualizarTurmaPorExclusaoDeAluno(listaDeTurmas * lista, int matricula);

void atualizarTurmaPorExclusaoDeProfessor(listaDeTurmas * lista, int codigo);

void atualizarTurmaPorExclusaoDeDisciplina(listaDeDisciplinas *lista, int codigo);

bool excluirTurma(listaDeTurmas *lista, int codigo);

bool excluirAlunoNaTurma(turma *trm, int matricula);

void excluirProfessorNaTurma(turma *trm);

void excluirDisciplinaNaTurma(turma *trm);

#endif // !LIBTURMA_H


