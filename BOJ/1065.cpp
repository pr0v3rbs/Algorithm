#include <stdio.h>

bool IsHan(int num)
{
    if (num == 1000)
        return false;

    if (num / 100 > 0)
    {
        if ((num / 100) - ((num % 100) / 10) == ((num % 100) / 10) - (num % 10))
            return true;
        else
            return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int input;
    int sum = 0;

    scanf("%d", &input);

    for (int i = 1; i <= input; i++)
    {
        if (IsHan(i))
        {
            sum += 1;
        }
    }

    printf("%d\n", sum);

    return 0;
}
