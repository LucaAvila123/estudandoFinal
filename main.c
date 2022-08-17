#include "arvore.h"
#include "aluno.h"
#include <string.h>

int ondeIr(int numero1, int numero2){
    if(numero1 > numero2){
        return 1;
    }
    if(numero1 < numero2){
        return 0;
    }
    return -1;
}

int qualAluno(tAluno* alunoDaqui, tAluno* alunoNaArvore){
    return ondeIr(retornaMat(alunoDaqui), retornaMat(alunoNaArvore));
}
void deleteNumero(int n){
    return;
}

void printaNumero(int n){
    printf("%d", n);
}

int nomesIguais(tAluno* aluno, char* nomeBusca){
    int i = 0;
    char* string = strdup(retornaNome(aluno));
    while(string[i] == nomeBusca[i]){
        i++;
    }
    if(i != strlen(string) || i != strlen(nomeBusca)){
        free(string);
        return 0;
    }
    free(string);
    return 1;
}

int main(){
    Arv* abb = arv_criavazia();
    tAluno* luca = inicializaAluno("Luca", 4);
    tAluno* felipe = inicializaAluno("Felipe", 2);
    tAluno* josue = inicializaAluno("Josue", 3);
    tAluno* clarice = inicializaAluno("Clarice", 6);
    tAluno* debora = inicializaAluno("Debora", 7);
    tAluno* poliana = inicializaAluno("Poliana", 5);

    abb = arv_insere(luca, abb, qualAluno);
    abb = arv_insere(felipe, abb, qualAluno);
    abb = arv_insere(josue, abb, qualAluno);
    abb = arv_insere(clarice, abb, qualAluno);
    abb = arv_insere(debora, abb, qualAluno);
    abb = arv_insere(poliana, abb, qualAluno);

    arv_imprime(abb, imprimeAluno);
    printf("\n");
    
    tAluno* vendoAluno = (tAluno*) info(busca_no(abb, "Felipe", nomesIguais));
    imprimeAluno(vendoAluno);
    printf("\n");

    arv_libera(abb, larga);

    return 0;

}