// Exercise 1 
// Complexity 0(n)    
#include "stdio.h"
#include "stdlib.h"

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

long N;
long *a, *L, *R;

void make_L()
{
    long i;
    L[0] = a[0];
    for (i = 1; i < N; ++i)
    {
        L[i] = min(L[i-1], a[i]);
    }
}

void make_R()
{
    long i;
    R[N-1] = a[N-1];
    for (i = N-2; i >= 0; --i)
    {
        R[i] = max(R[i+1], a[i]);
    }
}

int main(int argc, char const *argv[])
{
    long i;
    long final_result = 0;
    long li = 0, ri = 0;

    FILE* fin = fopen(argv[1],"r");

    if (fin == NULL)
        exit(EXIT_FAILURE);

    if (fscanf(fin, "%ld\n", &N) <= 0) 
    {
        exit(1);
    }

    a = (long *)malloc(sizeof(long)*N);
    L = (long *)malloc(sizeof(long)*N);
    R = (long *)malloc(sizeof(long)*N);

    for (i = 0; i < N; ++i)
    {
        if (fscanf(fin, "%ld", &a[i]) <= 0)
        {
            exit(1);
        }
    }

    make_L();	/* L[i] holds the minimum value left from the i-th position */
    make_R();	/* R[i] holds the maximum value right from the i-th position */
    
    while(ri<N)
    {
        while(L[li] <= R[ri])
        {
            ri++;
            if(ri == N)
                break;
        }

        final_result = max(final_result, (ri-li-1));

        li++;
    }

    printf("%ld\n", final_result);

    free(a);
    free(L);
    free(R);

    return 0;
}   