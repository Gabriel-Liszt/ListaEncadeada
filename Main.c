#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *cabeca;
    int tamanho;
} ListaEncadeada;

// Função para criar uma lista vazia
ListaEncadeada* criar_lista() {
    ListaEncadeada *lista = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));
    lista->cabeca = NULL;
    lista->tamanho = 0;
    return lista;
}

// Função para verificar se a lista está vazia
int esta_vazia(ListaEncadeada *lista) {
    return lista->tamanho == 0;
}

// Função para obter o tamanho da lista
int obter_tamanho(ListaEncadeada *lista) {
    return lista->tamanho;
}

// Função para obter o valor de um elemento em uma posição específica
int obter_elemento(ListaEncadeada *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return -1;
    }
    No *atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->prox;
    }
    return atual->dado;
}

// Função para modificar o valor de um elemento em uma posição específica
void modificar_elemento(ListaEncadeada *lista, int posicao, int novo_valor) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    No *atual = lista->cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->prox;
    }
    atual->dado = novo_valor;
}

// Função para inserir um elemento em uma posição específica
void inserir(ListaEncadeada *lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("Posição inválida!\n");
        return;
    }
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->dado = valor;
    if (posicao == 1) {
        novo_no->prox = lista->cabeca;
        lista->cabeca = novo_no;
    } else {
        No *atual = lista->cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->prox;
        }
        novo_no->prox = atual->prox;
        atual->prox = novo_no;
    }
    lista->tamanho++;
}

// Função para retirar um elemento de uma posição específica
void remover(ListaEncadeada *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    No *atual = lista->cabeca;
    if (posicao == 1) {
        lista->cabeca = atual->prox;
    } else {
        No *anterior = NULL;
        for (int i = 1; i < posicao; i++) {
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = atual->prox;
    }
    free(atual);
    lista->tamanho--;
}

// Função para imprimir os elementos da lista
void imprimir_lista(ListaEncadeada *lista) {
    No *atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    ListaEncadeada *lista = criar_lista();
    
    printf("Inserindo elementos: 10, 20, 30, 40 na lista.\n");
    inserir(lista, 1, 10);
    inserir(lista, 2, 20);
    inserir(lista, 3, 30);
    inserir(lista, 4, 40);
    imprimir_lista(lista);
    
    printf("Tamanho da lista: %d\n", obter_tamanho(lista));
    
    printf("Elemento na posição 2: %d\n", obter_elemento(lista, 2));
    
    printf("Modificando elemento na posição 3 para 50.\n");
    modificar_elemento(lista, 3, 50);
    imprimir_lista(lista);
    
    printf("Removendo elemento na posição 2.\n");
    remover(lista, 2);
    imprimir_lista(lista);
    
    printf("A lista está vazia? %s\n", esta_vazia(lista) ? "Sim" : "Não");
    
    return 0;
}
