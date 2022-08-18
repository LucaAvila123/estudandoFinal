#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arv{
    void* data;
    Arv* saee;
    Arv* saed;
    Arv* mae;
    int altura;
};

//Cria uma árvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//insere um elemento em algum ponto de acordo com uma funcao
Arv* arv_insere(void* data, Arv* a, int (naOnde)(void*, void*)){
    if(a == NULL)
        a = arv_cria(data, NULL, NULL);
    
    else{
        if(naOnde(data, a -> data) == 0){
            //printf("AGORA TU ME EXPLICA\n");
            a -> saee = arv_insere(data, a -> saee, naOnde);
            a -> saee -> altura++;
        }
            
        
        else if(naOnde(data, a -> data) == 1){
            a -> saed = arv_insere(data, a -> saed, naOnde);
            a -> saed -> altura++;
        }
    }
    return a;
}
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (void* data, Arv* e, Arv* d){
    Arv* arv = (Arv*) calloc (1, sizeof(Arv));
    arv -> data = data;
    
    if(e) 
        arv -> saee = e;
    if(d)
        arv -> saed = d;
    
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a, void (*liberaItem)(void*)){
    if(a){
        arv_libera(a -> saee, liberaItem);
        arv_libera(a -> saed, liberaItem);
        if(a -> data != NULL && liberaItem != NULL)
            liberaItem(a -> data);
        free(a);
    }

    return NULL;
}

//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a){
    return a == NULL;
}

//indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence (Arv* a, void* key, int (*verifica)(void*, void*)){
    if(a){
        if(verifica(a -> data, key) == 1)
            return 1;
        
        else{
            if(arv_pertence(a -> saee, key, verifica))
                return 1;
            else if(arv_pertence(a -> saed, key, verifica))
                return 1;
        }
    }
    return 0;
}

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a, void (*imprimeItem)(void*)){
    printf("<");
    if(a){
        imprimeItem(a -> data);
        arv_imprime(a -> saee, imprimeItem);
        arv_imprime(a -> saed, imprimeItem);
    }
    printf(">");
}

//busca um no
Arv* busca_no (Arv* a, void* key, int (*verifica)(void*, void*)){
    if(a){
        if(!arv_pertence(a, key, verifica)){
            //printf("Problema no arv_pertence\n");
            return NULL; //nao ta na arvore
        }
        else{
            //printf("Nao eh problema no arv_pertence\n");
            if(verifica(a -> data, key))
                return a; // ta no noh ali mesmo
            else{
                if(arv_pertence(a -> saee, key, verifica))
                    return busca_no(a -> saee, key, verifica);
                
                else 
                    return busca_no(a -> saed, key, verifica);
            }
        }
    }
    return NULL;
}

Arv* arv_pai (Arv* a){
    if(a){
        if(a -> mae)
            return a -> mae;
    }

    return NULL;
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a){
    int total = 0;
    if(a){
        if(a -> saed && a -> saee){
            total = 1;
        }
        else{
            total += folhas(a -> saee) + folhas(a -> saed);
        }
    }

    return total;
}

//retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias (Arv* a, void* key, int (*verifica)(void*, void*)){
    int total = 0;
    if(a){
        total += ocorrencias(a -> saee, key, verifica) + ocorrencias(a -> saed, key, verifica);
        if(verifica(a -> data, key))
            total += 1;
    }

    return total;
}

//retorna o campo informacao de um dado no
void* info (Arv* a){
    if(a) return a -> data;
    else return NULL;
}

int altura(Arv* a){
    if(a) 
        return a -> altura;
    else
        return -1; //arvore invalida
}

void* removeNode(Arv* a, void* key, int (*verifica)(void*, void*)){
    Arv* node = busca_no(a, key, verifica);
    if(node){
        if(!node -> saee && !node -> saed){
            void* data = node -> data;
            node -> data = NULL;
            node = NULL;
            //free(node);
            return data;
        }
    }
}