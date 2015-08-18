#include <stdio.h>
#include <string.h>

int setArr[100005];

int GetRoot(int current)
{
	int prev = -1;

	while (prev != current)
	{
		prev = current;
		current = setArr[current];
	}

	return current;
}

void SetRoot(int current, int root)
{
	int prev = -1;

	while (prev != current)
	{
		prev = current;
		current = setArr[current];
		setArr[prev] = root;
	}
}

int main()
{
	int input1, input2;
	int head1, head2;
	int result = 0;

	memset(setArr, -1, sizeof(setArr));

	while (1)
	{
		if (scanf("%d", &input1) == EOF)
		{
			break;
		}
		if (input1 == -1)
		{
			printf("%d\n", result);
			result = 0;
			memset(setArr, -1, sizeof(setArr));
			continue;
		}
		scanf("%d", &input2);

		if (setArr[input1] == -1)
			setArr[input1] = input1;
		if (setArr[input2] == -1)
			setArr[input2] = input2;

		head1 = GetRoot(input1);
		head2 = GetRoot(input2);

		if (head1 == head2)
		{
			result++;
		}
		else
		{
			SetRoot(input2, head1);
		}
	}
}