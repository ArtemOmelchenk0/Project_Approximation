#include "solve.h"
#include "gauss.h"

#include <stdio.h>

int solve(matrix_t *eqs)
{
    if (check_diag(eqs))
        return 1;
    gaus_siedel(eqs);
    return 0;
}
