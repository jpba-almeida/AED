#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Node
{
    int valor;
    int alt;
    struct Node *dir;
    struct Node *esq;
} node;

int alt(node *N);
node *new_node(int valor);
node *insert_node(node *node, int valor);
node *dirRotate(node *y);
node *esqRotate(node *x);
int balance(node *N);
void print(node *root);
int EhArvoreArvl(node *root);
void deleteTree(node *node);

int alt(node *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return raiz->alt;
}
int balance(node *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return alt(raiz->esq) - alt(raiz->dir);
}
int var(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
node *new_node(int valor)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->valor = valor;
    new_node->esq = NULL;
    new_node->dir = NULL;
    new_node->alt = 1;
    return (new_node);
}
node *insert_node(node *node, int valor)
{
    if (node == NULL)
    {
        return (new_node(valor));
    }

    if (valor < node->valor)
    {
        node->esq = insert_node(node->esq, valor);
    }

    else if (valor > node->valor)
    {
        node->dir = insert_node(node->dir, valor);
    }

    else
    {
        return node;
    }
    node->alt = 1 + var(alt(node->esq), alt(node->dir));

    int val = balance(node);

    if (val > 1 && valor > node->esq->valor)
    {
        node->esq = esqRotate(node->esq);
        return dirRotate(node);
    }

    if (val < -1 && valor < node->dir->valor)
    {
        node->dir = dirRotate(node->dir);
        return esqRotate(node);
    }
    if (val > 1 && valor < node->esq->valor)
    {
        return dirRotate(node);
    }

    if (val < -1 && valor > node->dir->valor)
    {
        return esqRotate(node);
    }

    return node;
}
node *dirRotate(node *y)
{
    node *x = y->esq;
    node *aux = x->dir;
    x->dir = y;
    y->esq = aux;
    y->alt = var(alt(y->esq), alt(y->dir)) + 1;
    x->alt = var(alt(x->esq), alt(x->dir)) + 1;
    return x;
}
node *esqRotate(node *x)
{
    node *y = x->dir;
    node *aux = y->esq;
    y->esq = x;
    x->dir = aux;
    x->alt = var(alt(x->esq), alt(x->dir)) + 1;
    y->alt = var(alt(y->esq), alt(y->dir)) + 1;
    return y;
}
void print(node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->valor);
        print(root->esq);
        print(root->dir);
    }
}
void deleteTree(node *node)
{
    if (node == NULL)
    {
        return;
    }
    deleteTree(node->esq);
    deleteTree(node->dir);
    free(node);
}

int EhArvoreArvl(node *root)
{
    int fb;
    if (root == NULL)
        return 1;
    if (!EhArvoreArvl(root->esq))
        return 0;
    if (!EhArvoreArvl(root->dir))
        return 0;
    fb = balance(root);
    if ((fb > 1) || (fb < -1))
        return 0;
    else
        return 1;
}

int main()
{
    node *root = NULL;

    int n, i;

    printf("Quantos nos voce deseja ter na arvore?");
    scanf("%d", &n);
    srand((unsigned)time(0));

    for (i = 0; i < n; i++)
    {
        root = insert_node(root, rand());
    }

    print(root);
    printf("AVL:%d", EhArvoreArvl(root));
    deleteTree(root);
    root = NULL;
    printf("\narvore deletada\n");
    printf("Caso 1\n");
    root = insert_node(root, 4);
    root = insert_node(root, 26);
    root = insert_node(root, 3);
    root = insert_node(root, 9);
    root = insert_node(root, 21);
    root = insert_node(root, 30);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 11);
    root = insert_node(root, 15);
    print(root);
    deleteTree(root);
    root = NULL;
    printf("\narvore deletada\n");

    printf("Caso 2\n");
    root = insert_node(root, 20);
    root = insert_node(root, 4);
    root = insert_node(root, 26);
    root = insert_node(root, 3);
    root = insert_node(root, 9);
    root = insert_node(root, 21);
    root = insert_node(root, 30);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 11);
    root = insert_node(root, 8);
    print(root);
    deleteTree(root);
    root = NULL;
    printf("\narvore deletada\n");
    return 0;
}