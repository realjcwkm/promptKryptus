#include "listaDinEnc.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    int value;
    struct node *next;
};
typedef struct node Node;

List* create_list(){
    List* li = (List*) malloc(sizeof(List));

    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void free_list(List* li){
    if(li != NULL){
        Node* node;
        while((*li) != NULL){
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        free(li);
    }
}

int get_size_list(List* li){
    if(li == NULL)
        return 0;

    int cont = 0;
    Node* node = *li;
    while(node != NULL){
        cont++;
        node = node->next;
    }
    return cont;
}

int check_list_empty(List* li){
    if(li == NULL || *li == NULL)
        return 1;
    return 0;
}

int insert_list(List* li, int value){
    if(li == NULL)
        return 0;
    
    Node* node = (Node*) malloc(sizeof(Node));
    if(node == NULL)
        return 0;

    node->value = value;
    node->next = (*li);
    *li = node;

    return 1;
}

int insert_list_sorted(List* li, int value){
    if(li == NULL)
        return 0;
    
    Node* node = (Node*) malloc(sizeof(Node));
    if(node == NULL)
        return 0;

    node->value = value;
    if( check_list_empty(li) ){
        node->next = (*li);
        *li = node;
    }
    else{
        Node *ant, *atual = *li;
        while(atual != NULL && atual->value < value){
            ant = atual;
            atual = atual->next;
        }
        if(atual == *li){
            node->next = (*li);
            *li = node;
        }
        else{
            node->next = ant->next;
            ant->next = node;
        }
    }
    return 1;
}

int insert_list_last(List* li, int value){
    if(li == NULL)
        return 0;
    
    Node* node = (Node*) malloc(sizeof(Node));
    if(node == NULL)
        return 0;

    node->value = value;
    node->next = NULL;
    if((*li) == NULL){
        *li = node;
    }
    else{
        Node *aux = *li;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    return 1;

}

int remove_list_at(List* li, int position){
    if(li == NULL)
        return -1;

    Node *ant, *node = *li;
    int value;
    int pos_atual = 1;
    while(node != NULL && pos_atual < position){
        ant = node;
        node = node->next;
        pos_atual++;
    }

    if(node == NULL){
        return -1;
    }
    if(pos_atual == position){
        if(node == *li){
            *li = node->next;
        }
        else{
            ant->next = node->next;
        }
        value = node->value;
        free(node);
    }
    return value;
}

int search_list_at(List* li, int pos, int *value){
    if(li == NULL || pos <= 0)
        return 0;

    Node *node = *li;
    int i = 1;

    while(node != NULL && i < pos){
        node = node->next;
        i++;
    }

    if(node == NULL)
        return 0;
    else{
        *value = node->value;
        return 1;
    }
}

void show_list(List* li){
    if(li == NULL)
        return;

    Node *node = *li;

    while(node != NULL){
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}






