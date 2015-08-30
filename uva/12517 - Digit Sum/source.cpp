#include <stdio.h>

long long GetRangeSum(long long start, long long end)
{
    long long sum = start + end;
    long long count = end - start + 1;
    long long rest = 0;

    if (end == 0)
    {
        return 0;
    }

    if (count % 2 == 1)
    {
        rest = sum / 2;
    }

    return sum * (count / 2) + rest;
}

long long GetSum(long long end)
{
    long long sum = 0;

    if (end < 10)
    {
        sum += GetRangeSum(1, end);
    }
    else
    {
        long long length = 1000000000;

        while (end / length == 0)
        {
            length /= 10;
        }

        sum += GetRangeSum(1, ((end / length) - 1)) * length;
        sum +=  (end / length) * GetSum(length - 1);

        sum += (end / length) * (end % length + 1);
        sum += GetSum(end % length);
    }

    return sum;
}

int main()
{
    int M, N;

    while (scanf("%d%d", &M, &N) && (M != 0 || N != 0))
    {
        printf("%lld\n", GetSum(N) - GetSum(M - 1));
    }
}