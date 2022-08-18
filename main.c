#include "arvoreAluno.h"
#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    ArvAluno* abb = arvAluno_insere(inicializaAluno("Luca", 4), abb);
    abb = arvAluno_insere(inicializaAluno("Felipe", 2), abb);
    abb = arvAluno_insere(inicializaAluno("Josue", 3), abb);
    abb = arvAluno_insere(inicializaAluno("Clarice", 6), abb);


    abb = arvAluno_insere(inicializaAluno("Debora", 7), abb);
    abb = arvAluno_insere(inicializaAluno("Poliana", 5), abb);
    abb = arvAluno_insere(inicializaAluno("Mateus", 4), abb);

    abb = arvAluno_insere(inicializaAluno("Fernanda", 4), abb);

    imprimeArvAluno(abb);
    printf("\n");
    
    tAluno* vendoAluno = buscaAlunoPorNome(abb, "Felipe");
    imprimeAluno(vendoAluno);
    printf("\n");

    printf("%d\n", ocorrencias(abb, 4, matriculaNumero));

    //removeu item da arvore, sem eliminar o item
    tAluno* removendoItem = removeAlunoDaArvore(abb, "Debora");
    imprimeAluno(removendoItem);
    printf("\n");
    
    arv_libera(abb, larga);

    larga(removendoItem);
    
    return 0;

}