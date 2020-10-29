// DiagonalMatrix.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>
#include <malloc.h>

struct Matrix
{
    int *A;
    int n;
};

void Diplay(struct Matrix m);
void Set(struct Matrix *m, int i, int j, int x);
int Get(struct Matrix *m, int i, int j);

int main()
{
    struct Matrix m;
    m.n = 4;
    m.A = (int*)malloc(m.n * sizeof(int));
    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 8);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 12);
    Diplay(m);
    return 0;
}

void Diplay(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}

int Get(struct Matrix *m, int i, int j)
{
    if (i == j)
        return m->A[i - 1];
    else
        return 0;
}