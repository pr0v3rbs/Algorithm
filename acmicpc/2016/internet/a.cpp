#include <cstdio>
#include <cmath>
#include <algorithm>


#define LEFT(x) x*2+1
#define RIGHT(x) x*2+2

struct Node
{
	int value;
	short lMax;
	short rMax;
};

struct Node tree[3000000];
int k;

short SetMaxLength(int depth, int nodeNum)
{
        if (depth == k)
	{
		return tree[nodeNum].value;
	}

	tree[nodeNum].lMax = SetMaxLength(depth + 1, LEFT(nodeNum));
	tree[nodeNum].rMax = SetMaxLength(depth + 1, RIGHT(nodeNum));

	return tree[nodeNum].value + std::max(tree[nodeNum].lMax, tree[nodeNum].rMax);
}

void Solve(int depth, int nodeNum)
{
	if (depth == k) return;

	short l = tree[nodeNum].lMax;
	short r = tree[nodeNum].rMax;

	if (l <= r)
	{
		tree[LEFT(nodeNum)].value += r - l;
		Solve(depth + 1, RIGHT(nodeNum));
		Solve(depth + 1, LEFT(nodeNum));
	}
	else // l > r
	{
		tree[RIGHT(nodeNum)].value += l - r;
		Solve(depth + 1, LEFT(nodeNum));
		Solve(depth + 1, RIGHT(nodeNum));
	}
}

int main()
{
	int len;
	long long result = 0;
	scanf("%d", &k);

	len = (int)pow(2, k + 1) - 2;
	for (int i = 1; i <= len; i++)
	{
		scanf("%d", &tree[i].value);
	}

	SetMaxLength(0, 0);

	Solve(0, 0);

	for (int i = 1; i <= len; i++)
	{
		result += tree[i].value;
	}

	printf("%lld\n", result);
}
