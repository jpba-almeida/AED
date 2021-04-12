#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct pessoa
{
    char nome[30];
    int idade;
    int altura;
    struct pessoa *prox;
} pessoa;

void alloc_p(pessoa **head, char nome[], int idade, int altura)
{
    pessoa *temp = (pessoa *)calloc(1, sizeof(pessoa));
    strcpy(temp->nome, nome);
    temp->idade = idade;
    temp->altura = altura;
    temp->prox = *head;
    *head = temp;
    temp = NULL;
}
void print_p(pessoa *head)
{
    printf("\n");
    while (head != NULL)
    {
        printf("Nome:%s\n", head->nome);
        printf("Idade:%i\n", head->idade);
        printf("Altura:%i\n", head->altura);
        head = head->prox;
        printf("\n");
    }
    printf("\n");
}
void limpeza(pessoa **head)
{
    pessoa *curr = *head;

    if (curr != NULL)
    {
        pessoa *aux = curr;
        curr = curr->prox;
        free(aux);
    }
    *head = NULL;
    printf("MEMORIA LIMPA");
}
int main()
{
    pessoa *head = NULL;
    char nome[30];
    int idade;
    int altura;
    char controle;
    int v = 1;
    while (v = 1)
    {
        printf("|=========================================================|\n");
        printf("|==================|<A>   Adicionar    |==================|\n");
        printf("|==================|<B>    Listar      |==================|\n");
        printf("|==================|<C>     Sair       |==================|\n");
        printf("|=========================================================|\n");
        scanf(" %c", &controle);

        switch (controle)
        {
        case 'A':
        case 'a':
            printf("Digite o nome:");
            scanf(" %s", nome);
            printf("Digite a idade:");
            scanf("%d", &idade);
            printf("Digite a altura:");
            scanf("%d", &altura);
            alloc_p(&head, nome, idade, altura);
            break;
        case 'B':
        case 'b':
            print_p(head);
            break;

        case 'C':
        case 'c':

            limpeza(&head);
            return 0;
            break;
        }
    }
    return 0;
}
