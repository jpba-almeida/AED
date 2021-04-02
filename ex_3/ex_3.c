#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda
{
    char name[10];
    int idade;
    int telefone;
    int n_pessoas;
    struct agenda *pBuffer;
} agenda;

void new_p_beg(agenda **head, int n_pessoas);
void new_p_last(struct agenda **head, char name[], int idade, int telefone);
void remove_p(agenda **head, char name[], int idade, int telefone);
void list_p(agenda *head);
void search_p(agenda *head, char name[]);
void limpeza(agenda **head);

void new_p_beg(agenda **head, int n_pessoas)
{
    agenda *temp = (agenda *)malloc(sizeof(agenda));
    temp->n_pessoas = n_pessoas;
    temp->pBuffer = *head;
    *head = temp;
}
void new_p_last(struct agenda **head, char name[], int idade, int telefone)
{
    agenda *temp = (struct agenda *)malloc(sizeof(agenda));
    agenda *last = *head;
    strcpy(temp->name, name);
    temp->idade = idade;
    temp->telefone = telefone;
    temp->pBuffer = *head;
    temp->pBuffer = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    while (last->pBuffer != NULL)
    {
        last = last->pBuffer;
    }
    last->pBuffer = temp;
    return;
}
void remove_p(agenda **head, char name[], int idade, int telefone)
{
    if (head == NULL)
    {
        printf("LISTA VAZIA");
        return;
    }
    if (strcmp(((*head)->name), name) == 0)
    {
        agenda *temp = *head;
        *head = (*head)->pBuffer;
        free(temp);
        printf("\nREMOVIDO\n");
        return;
    }
    for (agenda *curr = *head; curr != NULL && curr->pBuffer != NULL; curr = curr->pBuffer)
    {
        if (strcmp(curr->name, name) == 0)
        {
            agenda *temp = curr->pBuffer;
            curr->pBuffer = curr->pBuffer->pBuffer;
            free(temp);
            printf("\nREMOVIDO\n");
            return;
        }
    }
}
void list_p(agenda *head)
{
    int count = 0;

    while (head != NULL)
    {
        printf("\n%s\n", head->name);
        printf("%d\n", head->idade);
        printf("%d\n", head->telefone);
        head = head->pBuffer;
        count++;
    }
    new_p_beg(&head, count);
    printf("\nEssa agenda possui %d contados\n", head->n_pessoas);
}
void search_p(agenda *head, char name[])
{

    while (head != NULL)
    {

        if (strcmp(head->name, name) == 0)
        {
            printf("\nNome:%s\n", head->name);
            printf("Idade:%d\n", head->idade);
            printf("Telefone:%d\n", head->telefone);
        }
        head = head->pBuffer;
    }
}
void limpeza(agenda **head)
{
    agenda *curr = *head;

    if (curr != NULL)
    {
        agenda *aux = curr;
        curr = curr->pBuffer;
        free(aux);
    }
    *head = NULL;
    printf("MEMORIA LIMPA");
}
int main()
{

    agenda *head = NULL;
    memset(&head, 0, sizeof(head));
    char name[10], controle;
    int idade;
    int telefone;
    int pessoas = 0, v = 1;

    while (v = 1)
    {
        printf("|======================<<<AGENDA>>>=======================|\n");
        printf("|=========================================================|\n");
        printf("|==================|<A>   Adicionar    |==================|\n");
        printf("|==================|<B>    Remover     |==================|\n");
        printf("|==================|<C>    Listar      |==================|\n");
        printf("|==================|<D>    Buscar      |==================|\n");
        printf("|==================|<E>     Sair       |==================|\n");
        printf("|=========================================================|\n");
        scanf(" %c", &controle);

        switch (controle)
        {
        case 'A':
        case 'a':
            printf("Digite o nome:");
            scanf(" %s", name);
            printf("Digite a idade:");
            scanf("%d", &idade);
            printf("Digite o telefone:");
            scanf("%d", &telefone);
            new_p_last(&head, name, idade, telefone);
            break;

        case 'B':
        case 'b':
            printf("Digite o nome a ser removido:");
            scanf(" %s", name);
            remove_p(&head, name, idade, telefone);
            break;

        case 'C':
        case 'c':
            list_p(head);
            break;

        case 'D':
        case 'd':
            printf("Digite o nome do contado que deseja buscar:");
            scanf("%s", name);
            search_p(head, name);
            break;

        case 'E':
        case 'e':
            limpeza(&head);
            v = 0;
            return 0;
            break;
        }
    }
    return 0;
}