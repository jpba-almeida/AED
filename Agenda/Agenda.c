#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Agenda
{
    char name[10];
    int idade;
    int telefone;
    int n_pessoas;
    struct Agenda *prox;
    struct Agenda *prev;
} agenda;
typedef struct controle
{
    agenda *agenda, *new_node;
    agenda *head, *tail, *temp, *remove, *node_fila;
    agenda *front, *rear, *aux;
    agenda *node_ord, *front_ord, *rear_ord;
    agenda *node_decre, *front_decre, *rear_decre;
    char name[10];
    char sel;

    int idade;
    int telefone;
    int v, tam, count;

} controle;

void *pBuffer;

agenda *insert(controle *var);
//agenda *insert_ord(controle *var);
void insert_node_end(controle *var);
void fila(controle *var);
void print_list(controle *var);
void print_fila_cres(controle *var);
void print_fila_decre(controle *var);
void remove_node(controle *var);
void search_node(controle *var);
void menu_sorting();
void sorting_idade_cres(controle *var);
void sorting_idade_decre(controle *var);
void delete_list_queue(controle *var);
//void sorting_cres(controle *var);

void add_contato(controle *var)
{
    printf("Digite o nome:");
    scanf(" %s", var->name);
    printf("Digite a idade:");
    scanf("%d", &(var->idade));
    printf("Digite o telefone:");
    scanf("%d", &(var->telefone));
    insert_node_end(var);
    fila(var);
    sorting_idade_cres(var);
    sorting_idade_decre(var);
}
agenda *insert(controle *var)
{
    agenda *new_node = (agenda *)malloc(sizeof(agenda));
    strcpy(new_node->name, var->name);
    new_node->idade = var->idade;
    new_node->telefone = var->telefone;
    new_node->prev = NULL;
    new_node->prox = NULL;
    return new_node;
}
void insert_node_end(controle *var)
{
    var->new_node = insert(var);
    var->temp = var->head;

    if (var->head == NULL)
    {
        (var->head) = var->new_node;
        return;
    }

    for (var->temp; var->temp->prox != NULL; var->temp = var->temp->prox)
    {
    }
    var->temp->prox = var->new_node;
    var->new_node->prev = var->new_node;
    var->tam++;
}
void fila(controle *var)
{
    var->node_fila = insert(var);
    if (var->front == NULL)
    {
        var->front = var->node_fila;
        var->rear = var->node_fila;
        var->node_fila->prox = NULL;
    }
    else
    {
        var->node_fila->prox = var->front;
        var->front->prev = var->node_fila;
        var->front = var->node_fila;
    }
}
void print_list(controle *var)

{
    printf("\n\nEssa agenda possui %d contatos\n", var->tam);
    var->temp = var->head;
    printf("\n-------------LISTA ENCADEADA-------------");
    while (var->temp != NULL)
    {
        printf("\nNome:%s\n", var->temp->name);
        printf("Idade:%d\n", var->temp->idade);
        printf("Telefone:%d\n", var->temp->telefone);
        var->temp = var->temp->prox;
    }
    var->temp = var->front;
    printf("\n\n-------------------FILA-------------------");
    while (var->temp != NULL)
    {
        printf("\nNome:%s\n", var->temp->name);
        printf("Idade:%d\n", var->temp->idade);
        printf("Telefone:%d\n", var->temp->telefone);
        var->temp = var->temp->prox;
    }
}
void remove_node(controle *var)
{
    if (var->head == NULL)
    {
        return;
    }
    if (strcmp(var->head->name, var->name) == 0)
    {
        var->remove = var->head;
        var->head = var->head->prox;
        free(var->remove);
        printf("\nREMOVIDO\n");
        var->tam--;
        return;
    }
    for (var->temp = var->head; var->temp->prox != NULL; var->temp = var->temp->prox)
    {
        if (strcmp(var->temp->prox->name, var->name) == 0)
        {
            var->remove = var->temp->prox;
            var->temp->prox = var->temp->prox->prox;
            free(var->remove);
            printf("\nREMOVIDO\n");
            var->tam--;
            return;
        }
    }
}
void search_node(controle *var)
{
    if (var->head == NULL)
    {
        return;
    }
    if (strcmp(var->head->name, var->name) == 0)
    {
        printf("\nNome:%s\n", var->head->name);
        printf("Idade:%d\n", var->head->idade);
        printf("Telefone:%d\n", var->head->telefone);
        return;
    }
    for (var->temp = var->head; var->temp->prox != NULL; var->temp = var->temp->prox)
    {
        if (strcmp(var->temp->name, var->name) == 0)
        {
            printf("\nNome:%s\n", var->temp->name);
            printf("Idade:%d\n", var->temp->idade);
            printf("Telefone:%d\n", var->temp->telefone);
            return;
        }
    }
}

void menu_sorting()
{
    printf("|--------------Escolha uma opção de ordenação para agenda-------------|\n");
    printf("|====================|<A>    IDADE CRESCENTE     |====================|\n");
    printf("|====================|<B>    IDADE DECRESCENTE   |====================|\n");
    printf("|====================|<C>       TELEFONE         |====================|\n");
    scanf(" %c", &(((controle *)pBuffer)->sel));
    switch (((controle *)pBuffer)->sel)
    {
    case 'A':
    case 'a':
        print_fila_cres(pBuffer);
        break;

    case 'B':
    case 'b':
        print_fila_decre(pBuffer);
        break;

    case 'C':
    case 'c':
        break;
    }
}
void sorting_idade_cres(controle *var)
{
    var->node_ord = insert(var);
    if (var->front_ord == NULL)
    {
        var->front_ord = var->node_ord;
        var->rear_ord = var->node_ord;
        var->node_ord->prox = NULL;
    }
    else
    {
        if (var->idade <= var->front_ord->idade)
        {
            var->node_ord->prox = var->front_ord;
            var->front_ord->prev = var->node_ord->prox;
            var->front_ord = var->node_ord;
        }
        else if (var->idade > var->rear_ord->idade)
        {
            var->node_ord->prox = NULL;
            var->rear_ord->prox = var->node_ord;
            var->node_ord->prev = var->rear_ord->prox;
            var->rear_ord = var->node_ord;
        }
        else
        {
            var->aux = var->front_ord->prox;
            for (var->aux->idade; var->aux->idade > var->idade; var->aux = var->aux->prox)
            {
            }
            (var->aux->prev)->prox = var->node_ord;
            var->node_ord->prox = var->aux->prev;
            var->node_ord->prev = (var->aux->prev)->prox;
            var->aux->prev = var->node_ord->prox;
        }
    }
}
void print_fila_cres(controle *var)
{
    var->temp = var->front_ord;
    printf("\n\n-------------------FILA-------------------");
    while (var->temp != NULL)
    {
        printf("\nNome:%s\n", var->temp->name);
        printf("Idade:%d\n", var->temp->idade);
        printf("Telefone:%d\n", var->temp->telefone);
        var->temp = var->temp->prox;
    }
}
void sorting_idade_decre(controle *var)
{
    var->node_decre = insert(var);
    if (var->front_decre == NULL)
    {
        var->front_decre = var->node_decre;
        var->rear_decre = var->node_decre;
        var->node_decre->prox = NULL;
    }
    else
    {
        if (var->idade >= var->front_decre->idade)
        {
            var->node_decre->prox = var->front_decre;
            var->front_decre->prev = var->node_decre->prox;
            var->front_decre = var->node_decre;
        }
        else if (var->idade <= var->rear_decre->idade)
        {
            var->node_decre->prox = NULL;
            var->rear_decre->prox = var->node_decre;
            var->node_decre->prev = var->rear_decre->prox;
            var->rear_decre = var->node_decre;
        }
        else
        {
            var->aux = var->front_decre->prox;
            for (var->aux->idade; var->aux->idade > var->idade; var->aux = var->aux->prox)
            {
            }
            (var->aux->prev)->prox = var->node_decre;
            var->node_decre->prox = var->aux->prev;
            var->node_decre->prev = (var->aux->prev)->prox;
            var->aux->prev = var->node_decre->prox;
        }
    }
}
void print_fila_decre(controle *var)
{

    var->temp = var->front_decre;
    printf("\n\n-------------------FILA-------------------");
    while (var->temp != NULL)
    {
        printf("\nNome:%s\n", var->temp->name);
        printf("Idade:%d\n", var->temp->idade);
        printf("Telefone:%d\n", var->temp->telefone);
        var->temp = var->temp->prox;
    }
}

void delete_list_queue(controle *var)
{
    // var->temp = var->head;
    // while (var->temp != NULL)
    // {
    //     var->aux = var->temp->prox;
    //     free(var->temp);
    //     var->temp = var->temp->prox;
    // }
    // var->head = NULL;
    // printf("\nLISTA LIMPA");

    // var->temp = var->front_ord;
    // while (var->temp != NULL)
    // {
    //     var->remove = var->temp;
    //     var->front_ord = var->front_ord->prox;
    //     free(var->remove);
    //     if (var->front_ord == NULL)
    //         var->rear_ord = NULL;
    //     var->temp = var->temp->prox;
    // }
    // printf("\nFILA LIMPA\n");
}
//oque eu queria ter feito era passar os nos da lista para os nos da fila, essas foram algumas das inumeras tentativas.

// agenda *insert_ord(controle *var)
// {
//     var->node_ord = (agenda *)malloc(sizeof(agenda));
//     strcpy(var->node_ord->name, var->temp->name);
//     var->node_ord->idade = var->temp->idade;
//     var->node_ord->telefone = var->temp->telefone;
//     var->node_ord->prev = NULL;
//     var->node_ord->prox = NULL;
//     return var->node_ord;
// }

// void sorting_cres(controle *var)
// {
//     var->temp = var->head;
//     while (var->temp != NULL)
//     {
//         // var->node_ord = (agenda *)malloc(sizeof(agenda));
//         // strcpy(var->node_ord->name, var->temp->name);
//         // var->node_ord->idade = var->temp->idade;
//         // var->node_ord->telefone = var->temp->telefone;
//         // var->node_ord->prev = NULL;
//         // var->node_ord->prox = NULL;
//         var->node_ord = insert_ord(var);
//         if (var->front_decre == NULL)
//         {
//             var->front_decre = var->node_decre;
//             var->rear_decre = var->node_decre;
//             var->node_decre->prox = NULL;
//         }
//         else
//         {
//             if (var->temp->idade >= var->front_decre->idade)
//             {
//                 var->node_decre->prox = var->front_decre;
//                 var->front_decre->prev = var->node_decre->prox;
//                 var->front_decre = var->node_decre;
//             }
//             else if (var->temp->idade <= var->rear_decre->idade)
//             {
//                 var->node_decre->prox = NULL;
//                 var->rear_decre->prox = var->node_decre;
//                 var->node_decre->prev = var->rear_decre->prox;
//                 var->rear_decre = var->node_decre;
//             }
//             else
//             {
//                 var->aux = var->front_decre->prox;
//                 for (var->aux->idade; var->aux->idade > var->temp->idade; var->aux = var->aux->prox)
//                 {
//                 }
//                 (var->aux->prev)->prox = var->node_decre;
//                 var->node_decre->prox = var->aux->prev;
//                 var->node_decre->prev = (var->aux->prev)->prox;
//                 var->aux->prev = var->node_decre->prox;
//             }
//         }
//         var->temp = var->temp->prox;
//     }
//     var->temp = var->front_ord;
//     printf("\n\n-------------------FILA DE PRIORIDADE-------------------");
//     while (var->temp != NULL)
//     {
//         printf("\nNome:%s\n", var->temp->name);
//         printf("Idade:%d\n", var->temp->idade);
//         printf("Telefone:%d\n", var->temp->telefone);
//         var->temp = var->temp->prox;
//     }
// }

int main()
{

    pBuffer = (controle *)malloc(sizeof(controle));
    ((controle *)pBuffer)->agenda = (agenda *)(malloc(sizeof(agenda)));
    ((controle *)pBuffer)->head = NULL;
    ((controle *)pBuffer)->tail = NULL;
    ((controle *)pBuffer)->front = NULL;
    ((controle *)pBuffer)->rear = NULL;
    ((controle *)pBuffer)->tam = 1;
    while (((controle *)pBuffer)->v = 1)
    {
        printf("|======================<<<AGENDA>>>=======================|\n");
        printf("|=========================================================|\n");
        printf("|==================|<A>   Adicionar    |==================|\n");
        printf("|==================|<B>    Remover     |==================|\n");
        printf("|==================|<C>    Listar      |==================|\n");
        printf("|==================|<D>    Buscar      |==================|\n");
        printf("|==================|<E>    Ordenar     |==================|\n");
        printf("|==================|<F>     Sair       |==================|\n");
        printf("|=========================================================|\n");
        scanf(" %c", &(((controle *)pBuffer)->sel));

        switch (((controle *)pBuffer)->sel)
        {
        case 'A':
        case 'a':
            add_contato(pBuffer);
            break;

        case 'B':
        case 'b':
            printf("Digite o nome a ser removido:");
            scanf(" %s", ((controle *)pBuffer)->name);
            remove_node(pBuffer);
            break;

        case 'C':
        case 'c':
            print_list(pBuffer);
            break;

        case 'D':
        case 'd':
            printf("Digite o nome do contado que deseja buscar:");
            scanf("%s", ((controle *)pBuffer)->name);
            search_node(pBuffer);
            break;

        case 'E':
        case 'e':
            menu_sorting();
            break;

        case 'F':
        case 'f':
            delete_list_queue(pBuffer);
            ((controle *)pBuffer)->v = 0;
            return 0;
            break;
        }
    }

    return 0;
}