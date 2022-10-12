#include <stdio.h>
#include <stdint.h>

uint64_t rf(uint64_t n)
{
    if (n == 0)
        return 1;

    uint64_t acc = rf(n - 1);

    return n + 2*(acc + 3) + 5*(acc + 4);
}

int main()
{
    printf("%llu\n", rf(1000000000ULL));

    return 0;
}
