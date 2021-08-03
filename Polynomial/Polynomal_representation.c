#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Terms
{
    int Coeff;
    int Exp;
};

struct Poly
{
    int n;
    struct Terms *te;
};

void create(struct Poly *s1)
{
    printf("Enter no-zeros terms : ");
    scanf("%d", &s1->n);
    s1->te = (struct Terms *)malloc(s1->n*sizeof(struct Terms));

    for(int i=0; i < s1->n; i++)
    {
        printf("enter the coeff & exp : ");
        scanf("%d%d", &s1->te[i].Coeff, &s1->te[i].Exp);
    }
}

void display(struct Poly s1)
{
    for(int i=0; i < s1.n; i++)
        printf("coeff --> %d | exp --> %d", s1.te[i].Coeff, s1.te[i].Exp);
}

struct Poly *add(struct Poly *s1, struct Poly *s2)
{
    int i,j,k;
    i=j=k=0;

    struct Poly *sum;

    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->te = (struct Terms *)malloc((s1->n+s2->n)*sizeof(struct Terms));

    while(i < s1->n && j < s2->n)
    {
        if(s1->te[i].Exp > s2->te[j].Exp)
            sum->te[k++] = s2->te[j++];
        else if(s1->te[i].Exp < s2->te[j].Exp)
            sum->te[k++] = s1->te[i++];
        else
        {
            sum->te[k].Exp = s1->te[i].Exp;
            sum->te[k++].Coeff = s1->te[i++].Coeff + s2->te[j++].Coeff;
        }
    }
    for(;i<s1->n;i++)sum->te[k++] = s1->te[i];
    for(;j<s2->n;j++)sum->te[k++] = s2->te[j];
    sum->n = k;
    return sum;
}

int main()
{
    double x=0, result=0;

    struct Poly s1;
    struct Poly s2;
    struct Poly *sum;

    create(&s1);
    create(&s2);

    sum = add(&s1, &s2);

    printf("enter X value : ");
    scanf("%le", &x);

    for(int i=0; i < sum->n; i++)
        result += sum->te[i].Coeff*pow(x,sum->te[i].Exp);

    printf("result --> %.3lf", result);
    return 0;
}