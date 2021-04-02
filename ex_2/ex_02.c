#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *name_str;

void new_p(char *nome)
{

    name_str = realloc(name_str, ((strlen(nome) + 2) + strlen(name_str)) * sizeof(char));
    if (name_str == NULL)
    {
        printf("ERRO ALOCAÇAO DE MEMORIA");
    }
    strcat(name_str, nome);
    strcat(name_str, " ");
}
void remove_p(char *nome)
{
    {
        int i = 0, j = 0, k = 0;
        char ma_str[100][100];
        char *aux;
        aux = malloc(sizeof(char));
        *aux = NULL;
        aux = realloc(aux, ((strlen(name_str) - strlen(nome)) * sizeof(char)));

        for (i = 0; name_str[i] != '\0'; i++)
        {
            if (name_str[i] == ' ')
            {
                ma_str[k][j] = '\0';
                k++;
                j = 0;
            }
            else
            {
                ma_str[k][j] = name_str[i];
                j++;
            }
        }

        ma_str[k][j] = '\0';

        j = 0;
        for (i = 0; i < k + 1; i++)
        {
            if (strcmp(ma_str[i], nome) == 0)
            {
                ma_str[i][j] = '\0';
            }
        }

        j = 0;

        for (i = 0; i < k + 1; i++)
        {
            if (ma_str[i][j] == '\0')
                continue;
            else
            {
                if (name_str == NULL)
                {
                    printf("ERRO ALOCAÇAO DE MEMORIA");
                }
                strcat(aux, ma_str[i]);
                strcat(aux, " ");
            }
        }
        free(name_str);
        name_str = malloc(sizeof(char));
        *name_str = NULL;
        name_str = realloc(name_str, ((strlen(aux + 2) - strlen(nome)) * sizeof(char)));

        strncpy(name_str, aux, strlen(aux) + 1);
        printf("\n%s\n", name_str);
        printf("\n");
        free(aux);
    }
}
void list_p(char *nome)
{
    // char *str_aux;
    // str_aux = realloc(name_str, (strlen(nome) + strlen(name_str)) * sizeof(char));
    // strncpy(str_aux, name_str, strlen(name_str) + 1);

    // char *str;
    // str = realloc(name_str, (strlen(nome) + strlen(name_str)) * sizeof(char));
    // str = strtok(str_aux, " ");

    // while (str != NULL)
    // {
    //     printf("%s\n", str);
    //     str = strtok(NULL, " ");
    // }
    // free(str);
    // free(str_aux);

    printf("\n\n");

    for (int i = 0; i < strlen(name_str); i++)
    {
        printf("%c", name_str[i]);
    }
    printf("\n\n");
}
int main()
{
    name_str = malloc(sizeof(char));
    *name_str = NULL;
    char nome[10], controle;
    int v = 1;

    while (v = 1)
    {
        printf("|======================<<<AGENDA>>>=======================|\n");
        printf("|=========================================================|\n");
        printf("|==================|<A>   Adicionar    |==================|\n");
        printf("|==================|<B>    Remover     |==================|\n");
        printf("|==================|<C>    Listar      |==================|\n");
        printf("|==================|<E>     Sair       |==================|\n");
        printf("|=========================================================|\n");
        scanf(" %c", &controle);

        switch (controle)
        {
        case 'A':
        case 'a':
            printf("Digite o nome:");
            scanf(" %s", nome);
            new_p(nome);
            break;

        case 'B':
        case 'b':
            printf("Digite o nome a ser removido:");
            scanf(" %s", nome);
            remove_p(nome);
            break;

        case 'C':
        case 'c':
            list_p(nome);
            break;

        case 'E':
        case 'e':
            v = 0;
            free(name_str);
            return 0;
            break;
        }
    }
    free(name_str);
    return 0;
}
