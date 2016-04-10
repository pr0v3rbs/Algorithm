#include <stdio.h>
#include <string.h>

bool canSleep;
char findNum[10];
char compare[10] = { 1,1,1,1,1,1,1,1,1,1 };

void CheckNum(int N)
{
    do
    {
        findNum[N % 10] = 1;
        N /= 10;
    } while (N);

    if (!memcmp(findNum, compare, 10))
        canSleep = true;
}

int main()
{
    int testN;
    scanf_s("%d", &testN);

    for (int test = 1; test <= testN; ++test)
    {
        canSleep = false;
        __int64 N;
        __int64 result = 0;

        memset(findNum, 0, 10);

        scanf_s("%lld", &N);

        if (N)
        {
            while (canSleep == false)
            {
                result += N;
                CheckNum(result);
            }
        }
        
        if (canSleep)
        {
            printf("Case #%d: %lld\n", test, result);
        }
        else
        {
            printf("Case #%d: INSOMNIA\n", test);
        }
    }
}