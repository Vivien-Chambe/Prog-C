#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void prpnbs(unsigned n)
{
    double *nums;

    nums = malloc(sizeof(*nums) * (n-2));
    //le malloc était mal assigné ce qui provoquait une erreur "invalid write..."
    if (nums == 0)
    {
        fprintf(stderr, "not enough memory\n");
        return;
    }
    nums -= 2;

    for (int i = 2; i < n; i++)
    {
        nums[i] = 1;
    }

    for (int i = 2; i < n; i++)
    {
        if (nums[i])
        {
            for (int j = 2 * i; j < n; j += i)
            {
                nums[j] = 0;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (nums[i])
            printf("%d ", i);
    }
    printf("\n");

    nums += 2;
    free(nums);
    //nums=0 ce qui provoque un accés après avoir free ce qui est illégal
    return;
}

int main()
{
    prpnbs(3000000000);
    //Trop grand pour 3 000 000 000 pas assez de mémoire
}
