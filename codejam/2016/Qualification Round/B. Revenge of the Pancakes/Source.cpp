#include <stdio.h>
#include <string.h>

char pancakes[101];
int idx = 0;

void GetIdx()
{
    char t = pancakes[0];

    idx = 1;
    while (pancakes[idx] == t)
    {
        ++idx;
    }

    --idx;
}

void Flip()
{
    int len = (idx + 1) / 2;
    for (int i = 0; i < len; ++i)
    {
        pancakes[i] ^= pancakes[idx - i];
        pancakes[idx - i] ^= pancakes[i];
        pancakes[i] ^= pancakes[idx - i];

        pancakes[i] = pancakes[i] == '-' ? '+' : '-';
        pancakes[idx - i] = pancakes[idx - i] == '-' ? '+' : '-';
    }

    if (idx % 2 == 0)
    {
        pancakes[idx / 2] = pancakes[idx / 2] == '-' ? '+' : '-';
    }
}

int main()
{
    int testN;
    scanf_s("%d%*c", &testN);
    for (int test = 1; test <= testN; ++test)
    {
        int result = 0;
        int strLength = 0;
        gets_s(pancakes);
        strLength = strlen(pancakes);

        GetIdx();
        while (idx != strLength - 1)
        {
            Flip();
            GetIdx();
            result += 1;
        }

        if (pancakes[0] == '-') result += 1;

        printf("Case #%d: %d\n", test, result);
    }
}