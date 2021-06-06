#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

void insertion_sort(int vet[], int n);
void selection_sort(int vet[], int n);
void quick_sort(int sort[], int left, int right);
void merge_sort(int sort[], int pri, int ult);
void merge(int sort[], int pri, int meio, int ult);
void print_vet(int vet[], int n);
void ordenacao(int vet[], int n);

void insertion_sort(int vet[], int n)
{
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    int i, j, aux;
    int *sort;
    sort = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        sort[i] = vet[i];
    }

    for (i = 1; i < n; i++)
    {
        aux = sort[i];
        j = i - 1;

        for (j; j >= 0 && sort[j] > aux; j = j - 1)
        {
            sort[j + 1] = sort[j];
        }
        sort[j + 1] = aux;
    }

    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;

    print_vet(sort, n);
    ordenacao(sort, n);
    free(sort);

    printf("Tempo: %.5f segundos.\n", elapsed);
}
void selection_sort(int vet[], int n)
{
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    int i, j, aux;
    int *sort;
    sort = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        sort[i] = vet[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        aux = i;
        for (j = i + 1; j < n; j++)
            if (sort[j] < sort[aux])
                aux = j;
        int temp = sort[aux];
        sort[aux] = sort[i];
        sort[i] = temp;
    }

    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;

    print_vet(sort, n);
    ordenacao(sort, n);
    free(sort);

    printf("Tempo: %.5f segundos.\n", elapsed);
}
void quick_sort(int sort[], int left, int right)
{
    {
        int i, j, pivo, temp;
        i = left;
        j = right;
        pivo = sort[left + (rand() % (right - left))];

        do
        {

            while (sort[i] < pivo)
            {
                i++;
            }
            while (pivo < sort[j])
            {
                j--;
            }

            if (i <= j)
            {
                temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
                i++;
                j--;
            }

        } while (i <= j);

        if (left < j)
        {
            quick_sort(sort, left, j);
        }
        if (i < right)
        {
            quick_sort(sort, i, right);
        }
    }
}
void merge_sort(int sort[], int pri, int ult)
{

    if (pri < ult)
    {

        int meio = pri + (ult - pri) / 2;
        merge_sort(sort, pri, meio);
        merge_sort(sort, meio + 1, ult);
        merge(sort, pri, meio, ult);
    }
}
void merge(int sort[], int pri, int meio, int ult)
{
    int i, j, k;
    int p1 = meio - pri + 1;
    int p2 = ult - meio;

    int vet1[p1], vet2[p2];

    for (i = 0; i < p1; i++)
    {
        vet1[i] = sort[pri + i];
    }
    for (j = 0; j < p2; j++)
    {
        vet2[j] = sort[meio + 1 + j];
    }
    i = 0;
    j = 0;
    k = pri;
    while (i < p1 && j < p2)
    {
        if (vet1[i] <= vet2[j])
        {
            sort[k] = vet1[i];
            i++;
        }
        else
        {
            sort[k] = vet2[j];
            j++;
        }
        k++;
    }

    while (i < p1)
    {
        sort[k] = vet1[i];
        i++;
        k++;
    }
    while (j < p2)
    {
        sort[k] = vet2[j];
        j++;
        k++;
    }
}

void print_vet(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("---%d---\n", vet[i]);
    }
    printf("\n");
}
void ordenacao(int vet[], int n)
{
    int a = 1, i = 0;

    while (a == 1 && i < n - 1)
    {
        if (vet[i] > vet[i + 1])
        {
            a = 0;
        }
        i++;
    }
    if (a == 1)
        printf("O vetor esta ordenado.\n");
    else
        printf("O vetor nao esta ordenado\n");
}

int main()
{
    int n, i, *vet, v, *sort;
    char c;

    printf("Quantos elementos voce deseja ter no vetor?");
    scanf("%d", &n);
    vet = (int *)malloc(n * sizeof(int));

    srand((unsigned)time(NULL));
    for (i = 0; i < n; i++)
    {
        vet[i] = rand();
    }

    while (v = 1)
    {
        printf("|========================<<<ORDENACAO>>>=======================|\n");
        printf("|==============================================================|\n");
        printf("|==================|<A>   Insertion Sort    |==================|\n");
        printf("|==================|<B>   Selection Sort    |==================|\n");
        printf("|==================|<C>     Quick Sort      |==================|\n");
        printf("|==================|<D>     Merge Sort      |==================|\n");
        printf("|==================|<E>   Vetor original    |==================|\n");
        printf("|==================|<F>        Sair         |==================|\n");
        printf("|==============================================================|\n");
        scanf(" %c", &c);

        switch (c)
        {
        case 'A':
        case 'a':
            insertion_sort(vet, n);
            break;

        case 'B':
        case 'b':
            selection_sort(vet, n);
            break;

        case 'C':
        case 'c':
            sort = (int *)malloc((n) * sizeof(int));
            for (i = 0; i < n; i++)
            {
                sort[i] = vet[i];
            }
            struct timeval inicio, fim;
            gettimeofday(&inicio, 0);

            quick_sort(sort, 0, (n - 1));

            gettimeofday(&fim, 0);
            long segundos = fim.tv_sec - inicio.tv_sec;
            long microsegundos = fim.tv_usec - inicio.tv_usec;
            double elapsed = segundos + microsegundos * 1e-6;

            print_vet(sort, n);
            ordenacao(sort, n);
            printf("Tempo: %.5f segundos.\n", elapsed);
            free(sort);

            break;

        case 'D':
        case 'd':
            sort = (int *)malloc((n) * sizeof(int));
            for (i = 0; i < n; i++)
            {
                sort[i] = vet[i];
            }
            struct timeval begin, end;
            gettimeofday(&begin, 0);

            merge_sort(sort, 0, (n - 1));

            gettimeofday(&end, 0);
            long seconds = end.tv_sec - begin.tv_sec;
            long microseconds = end.tv_usec - begin.tv_usec;
            double colapso = seconds + microseconds * 1e-6;

            print_vet(sort, n);
            ordenacao(sort, n);
            printf("Tempo: %.5f segundos.\n", colapso);
            free(sort);
            break;

        case 'E':
        case 'e':
            print_vet(vet, n);
            ordenacao(vet, n);
            break;

        case 'F':
        case 'f':
            free(vet);
            v = 0;

            return 0;
            break;
        }
    }
    return 0;
}