#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char* nome;
    int mat;
};

tAluno* inicializaAluno(char* nome, int mat){
    tAluno* aluno = (tAluno*) malloc(sizeof(tAluno));
    aluno->nome = strdup(nome);
    aluno->mat = mat;
    //printf("começou\n");
    return aluno;
}

char* retornaNome(tAluno* aluno){
    return aluno->nome;
}

int retornaMat(tAluno* aluno){
    return aluno->mat;
}

void imprimeAluno(tAluno* aluno){
    printf("%s %d", aluno->nome, aluno->mat);
}

void larga(tAluno* aluno){
    free(aluno->nome);
    free(aluno);
}