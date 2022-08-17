//
//  arvore.h
//  Arvores
//
//  Created by Patricia Dockhorn Costa on 14/11/20.
//

#ifndef arvore_h
#define arvore_h

#include <stdio.h>

typedef struct arv Arv;

//Cria uma árvore vazia
Arv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (void* data, Arv* e, Arv* d);

//insere um elemento em algum ponto de acordo com uma funcao
Arv* arv_insere(void* data, Arv* a, int (*naOnde)(void*, void*));

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a, void (*liberaItem)(void*));

//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a);

//indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence (Arv* a, void* key, int (*verifica)(void*, void*));

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a, void (*imprimeItem)(void*));

//retorna o no procurado
Arv* busca_no (Arv* a, void* key, int (*verifica)(void*, void*));

//retorna a mãe de um dado no
Arv* arv_pai (Arv* a);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias (Arv* a, void* key, int (*verifica)(void*, void*));

//retorna o campo informacao de um dado no
void* info (Arv* a);

#endif /* arvore_h */
