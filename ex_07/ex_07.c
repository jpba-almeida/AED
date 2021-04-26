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

} agenda;
typedef struct controle
{
    agenda *agenda;
    agenda *head, *tail, *temp, *remove;
    char name[10];
    char sel;

    int idade;
    int telefone;
    int v;

} controle;

void *pBuffer;

agenda *insert(controle *var);
void insert_node_end(controle *var);
void print_list(controle *var);
void print_list(controle *var);
void remove_node(controle *var);
void search_node(controle *var);

void add_contato(controle *var)
{
    printf("Digite o nome:");
    scanf(" %s", var->name);
    printf("Digite a idade:");
    scanf("%d", &(var->idade));
    printf("Digite o telefone:");
    scanf("%d", &(var->telefone));
    insert_node_end(var);
}
agenda *insert(controle *var)
{
    agenda *new_node = (agenda *)malloc(sizeof(agenda));
    strcpy(new_node->name, var->name);
    new_node->idade = var->idade;
    new_node->telefone = var->telefone;
    new_node->prox = NULL;
    return new_node;
}
void insert_node_end(controle *var)
{
    agenda *new_node = insert(var);
    var->temp = var->head;

    if (var->head == NULL)
    {
        (var->head) = new_node;
        return;
    }

    for (var->temp; var->temp->prox != NULL; var->temp = var->temp->prox)
    {
    }
    var->temp->prox = new_node;
}
void print_list(controle *var)
{
    var->temp = var->head;
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

int main()
{
    pBuffer = (controle *)malloc(sizeof(controle));
    ((controle *)pBuffer)->agenda = (agenda *)(malloc(sizeof(agenda)));
    ((controle *)pBuffer)->head = NULL;
    ((controle *)pBuffer)->tail = NULL;

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

            ((controle *)pBuffer)->v = 0;
            return 0;
            break;
        }
    }

    return 0;
}