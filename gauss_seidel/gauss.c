#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

int check_diag(matrix_t *m)
{
    for (int i = 0; i < m->rn; i++)
        if (m->e[i * m->cn + i] == 0)
            return 1;
    return 0;
}


void *gaus_siedel(matrix_t *m)
{   
    double *solutions = calloc(m->rn, sizeof(double));
    double delta = 1;
    int iter = 1000000;
    while (delta && iter--)
    {
        delta = 0;
        for (int i = 0; i < m->rn; i++)
        {
            delta += solutions[i];
            double temp = m->e[(i + 1) * m->cn - 1];
            for (int j = 0; j < m->cn - 1; j++)
            {
                if (i == j)
                    continue;
                temp -= m->e[i * m->cn + j] * solutions[j];
            }
            temp /= m->e[i * m->cn + i];
            delta -= temp;
            solutions[i] = temp;
        }
    }
    for (int i = 0; i < m->rn; i++)
        m->e[(i + 1) * m->cn - 1] = solutions[i]; 
    free(solutions);
    
}
