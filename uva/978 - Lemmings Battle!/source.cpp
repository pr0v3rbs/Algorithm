#include <stdio.h>
#include <queue>
#include <list>

int battleList[100000];

int main()
{
	int testN;
	int tem;
	scanf("%d", &testN);

	while (testN--)
	{
		std::priority_queue<int> gLemmings;
		std::priority_queue<int> bLemmings;
		int battleFieldNum, battleCount;
		int gN, bN;

		scanf("%d%d%d", &battleFieldNum, &gN, &bN);

		for (int i = 0; i < gN; i++)
		{
			scanf("%d", &tem);
			gLemmings.push(tem);
		}

		for (int i = 0; i < bN; i++)
		{
			scanf("%d", &tem);
			bLemmings.push(tem);
		}

		while (!gLemmings.empty() && !bLemmings.empty())
		{
			for (battleCount = 0;
				battleCount < battleFieldNum && !gLemmings.empty() && !bLemmings.empty();
				battleCount++)
			{
				battleList[battleCount] = gLemmings.top() - bLemmings.top();
				gLemmings.pop();
				bLemmings.pop();
			}

			for (int i = 0; i < battleCount; i++)
			{
				if (battleList[i] < 0)
				{
					bLemmings.push(-battleList[i]);
				}
				else if (battleList[i] > 0)
				{
					gLemmings.push(battleList[i]);
				}
			}
		}

		if (bLemmings.empty())
		{
			if (gLemmings.empty())
			{
				printf("green and blue died\n");
			}
			else
			{
				printf("green wins\n");
				while (!gLemmings.empty())
				{
					printf("%d\n", gLemmings.top());
					gLemmings.pop();
				}
			}
		}
		else
		{
			printf("blue wins\n");
			while (!bLemmings.empty())
			{
				printf("%d\n", bLemmings.top());
				bLemmings.pop();
			}
		}

		if (testN != 0)
		{
			printf("\n");
		}
	}
}