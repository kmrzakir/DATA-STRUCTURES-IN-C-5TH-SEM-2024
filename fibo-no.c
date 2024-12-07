#include<stdio.h>

int main()
{



    return 0;
}

int sum_of_n_fibo(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return n + sum_of_n_fibo(n - 1);

}