#include "arvoreAluno.h"
#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    ArvAluno* abb = NULL;
    abb = arvAluno_insere(inicializaAluno("Luca", 3), abb);

    abb = arvAluno_insere(inicializaAluno("Felipe", 1), abb);
    abb = arvAluno_insere(inicializaAluno("Josue", 2), abb);

    abb = arvAluno_insere(inicializaAluno("Clarice", 8), abb);
    abb = arvAluno_insere(inicializaAluno("Debora", 10), abb);
    abb = arvAluno_insere(inicializaAluno("Poliana", 5), abb);
    abb = arvAluno_insere(inicializaAluno("Karen", 6), abb);
    abb = arvAluno_insere(inicializaAluno("Johann", 4), abb);
    //abb = arvAluno_insere(inicializaAluno("Mateus", 4), abb);

    // abb = arvAluno_insere(inicializaAluno("Fernanda", 4), abb);

    imprimeArvAluno(abb);
    printf("\n");
    
    tAluno* vendoAluno = buscaAlunoPorNome(abb, "Felipe");
    imprimeAluno(vendoAluno);
    printf("\n");

    printf("%d\n", ocorrenciasAluno(abb, 4));

    //removeu item da arvore, sem eliminar o item
    tAluno* removendoItem = removeAlunoDaArvore(abb, "Clarice");
    imprimeAluno(removendoItem);
    printf("\n");
    
    liberaArvoreAluno(abb);

    imprimeArvAluno(abb);

    larga(removendoItem);
    
    return 0;

}