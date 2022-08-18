#ifndef ARVOREALUNO_H
#define ARVOREALUNO_H

#include "aluno.h"

typedef struct arvAluno ArvAluno;

ArvAluno* arvAluno_insere(tAluno* aluno, ArvAluno* arvAluno);

int ondeIr(int numero1, int numero2);
int qualAluno(void* alunoDaqui, void* alunoNaArvore);
int matriculaNumero(void* aluno, int n);
void printaNumero(int n);
int nomesIguais(tAluno* aluno, char* nomeBusca);

void imprimeArvAluno(ArvAluno* abb);

tAluno* buscaAlunoPorNome(ArvAluno* abb, char* nome);

tAluno* removeAlunoDaArvore(ArvAluno* abb, char* nome);

int ocorrenciasAluno(ArvAluno* abb, char* nome);

void liberaArvoreAluno(ArvAluno* abb);
#endif