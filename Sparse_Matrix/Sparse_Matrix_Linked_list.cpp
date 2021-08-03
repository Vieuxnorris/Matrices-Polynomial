#include <iostream>

/*
0 0 0 0 8 0
0 0 0 7 0 0
5 0 0 0 9 0
0 0 0 0 0 3
6 0 0 4 0 0
*/

const int m=5;
const int n=6;

class Node {
public:
    int Col;
    int Value;
    struct Node *Next;
};

void Add(struct Node *p, int col, int value)
{
    while(p->Col != col)p = p->Next;

    p->Value = value;   
}

void Create(struct Node *p, int line)
{
    Node *last = new Node;
    last = p;
    for (int i=0;i<n;i++)
    {
        if (i == 0)
        {
            p->Col = i;
            p->Value = 0;
            p->Next = NULL;
        }
        else
        {
            Node *t = new Node;
            t->Col = i;
            t->Value = 0;
            t->Next = NULL;
            last->Next = t;
            last = t;
        }
    }
}

void Diplay(struct Node *p[])
{
    Node *q = new Node;
    for (int i=0; i<m;i++)
    {
        q = p[i];
        for (int j=0; j<n;j++)
        {
            std::cout << q->Value << " ";
            if (q->Next != NULL)
                q = q->Next;
        }
        std::cout << std::endl;
    }
}

int main()
{
    struct Node *A[m];
    for (int i=0;i<m;i++)
    {
        A[i] = new Node;
        Create(A[i], i);
    }

    Add(A[0], 4, 8);
    Add(A[1], 3, 7);
    Add(A[2], 0, 5);
    Add(A[2], 4, 9);
    Add(A[3], 5, 3);
    Add(A[4], 0, 6);
    Add(A[4], 3, 4);
    
    Diplay(A);
    return 0;
}