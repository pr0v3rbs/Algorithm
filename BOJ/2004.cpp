#include <stdio.h>

inline unsigned long long min(unsigned long long x, unsigned long long y)
{
    if (x < y) return x;
    return y;
}

unsigned long long GetNum(unsigned long long n, int base)
{
    unsigned long long count = 0;
    unsigned long long i = base;

    for (; n/i >= 1; i *= base)
        count += n/i;

    return count;
}

int main()
{
    unsigned long long n, m;

    scanf("%lld%lld", &n, &m);

    printf("%lld\n", min(GetNum(n, 5) - GetNum(n - m, 5) - GetNum(m, 5),
                         GetNum(n, 2) - GetNum(n - m, 2) - GetNum(m, 2)));
}
