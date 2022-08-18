#include "arvoreAluno.h"
#include "arvore.h"
#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>

struct arvAluno{
    Arv* arv;
};

ArvAluno* arvAluno_insere(tAluno* aluno, ArvAluno* arvAluno){
    if(arvAluno == NULL)
        arvAluno = (ArvAluno*) calloc (1, sizeof(ArvAluno));
    
    arvAluno -> arv = arv_insere(aluno, arvAluno -> arv, ondeIr);

    return arvAluno;
}

int ondeIr(int numero1, int numero2){
    if(numero1 >= numero2){
        return 1;
    }
    if(numero1 < numero2){
        return 0;
    }
    //return -1;
}
    if(numero1 >= numero2)
        return 1;
    else
        return 0;
int qualAluno(void* alunoDaqui, void* alunoNaArvore){
    return ondeIr(retornaMat((tAluno*)alunoDaqui), retornaMat((tAluno*)alunoNaArvore));
}

int matriculaNumero(void* aluno, int n){
    if(aluno){
        if(retornaMat((tAluno*) aluno) == n) 
            return 1;
    }
    return 0;
}

void printaNumero(int n){
    printf("%d", n);
}

int nomesIguais(tAluno* aluno, char* nomeBusca){
    int i = 0;
    char* string = strdup(retornaNome(aluno));
    while(string[i] && nomeBusca[i] && string[i] == nomeBusca[i]){
        //printf("%c", string[i]);
        i++;
    }

    if(i != strlen(string) || i != strlen(nomeBusca)){
        //printf("%d %d %d\n", i, strlen(string), strlen(nomeBusca));
        //printf("Nao sao iguais\n");
        free(string);
        return 0;
    }
    free(string);
    return 1;
    

    /*if(strcmp(string, retornaNome(aluno))){
        free(string);
        return 0;
    }
    else{
        free(string);
        return 1;
    }*/
    //printf("sao iguais\n");
    
}

void imprimeArvAluno(ArvAluno* abb){
    arv_imprime(abb -> arv, imprimeAluno);
}

tAluno* buscaAlunoPorNome(ArvAluno* abb, char* nome){
    return (tAluno*) info(busca_no(abb -> arv, nome, nomesIguais));
}

tAluno* removeAlunoDaArvore(ArvAluno* abb, char* nome){
    return removeNode(abb -> arv, nome, nomesIguais);
}

void liberaArvoreAluno(ArvAluno* abb){
    if(abb){
        arv_libera(abb -> arv);
        free(abb);
    }
    
}