#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno tAluno;

char* retornaNome(tAluno* aluno);
int retornaMat(tAluno* aluno);
tAluno* inicializaAluno(char* nome, int mat);
void imprimeAluno(tAluno* aluno);
void larga(tAluno* aluno);

#endif