#include <iostream>

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int n;
    int m;
    int num;
    Element *elem;
public:
    Sparse(int n, int m, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        this->elem = new Element[this->num];
    }
    ~Sparse()
    {
        delete [] this->elem;
    }

    Sparse operator+(Sparse &s);

    friend std::istream & operator>>(std::istream &is, Sparse &s);
    friend std::ostream & operator<<(std::ostream &os, Sparse &s);
};

Sparse Sparse::operator+(Sparse &s)
{
    int i,j,k;

    if(this->m != s.m || this->n != s.n)
        return Sparse(0,0,0);
    Sparse *sum = new Sparse(this->m,this->n,this->num+s.num);

    i=j=k=0;
    while(i < num && j<s.m)
    {
        if(this->elem[i].i < s.elem[j].i)
            sum->elem[k++] = this->elem[i++];
        else if(this->elem[i].i > s.elem[j].i)
            sum->elem[k++] = s.elem[j++];
        else
        {
            if(this->elem[i].j < s.elem[j].j)
                sum->elem[k++] = elem[i++];
            else if (this->elem[i].i > s.elem[j].i)
                sum->elem[k++] = s.elem[j++];
            else
            {
                sum->elem[k] = this->elem[i];
                sum->elem[k++].x = this->elem[i++].x + s.elem[j++].x;
            }
        }
    }
    for(;i<this->num;i++) sum->elem[k++] = this->elem[i];
    for(;j<s.num;j++) sum->elem[k++] = s.elem[j];
    sum->num = k;

    return *sum;
}

std::istream & operator>>(std::istream &is, Sparse &s)
{
    std::cout << "Enter non-zeros elements : " << std::endl;
    for(int i=0; i < s.num; i++)
        std::cin >> s.elem[i].i >> s.elem[i].j >> s.elem[i].x;
    return is;
}

std::ostream & operator<<(std::ostream &os, Sparse &s)
{
    int k=0;
    std::cout << "display matrix : " << std::endl;
    for(int i=0; i < s.m; i++)
    {
        for (int j=0; j < s.n; j++)
        {
            if(s.elem[k].i == i && s.elem[k].j == j)
                std::cout << s.elem[k++].x << " ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
    return os;
}

int main()
{
    Sparse s1(5,5,5);
    Sparse s2(5,5,5);

    std::cin>>s1;
    std::cin>>s2;

    Sparse sum = s1 + s2;

    std::cout << "First Matrix :" << std::endl << s1;
    std::cout << "Second Matrix : " << std::endl << s2;
    std::cout << "Sum Matrix : " << std::endl << sum;
    return 0;
}