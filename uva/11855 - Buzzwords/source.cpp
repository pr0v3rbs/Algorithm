#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

struct DSC
{
	std::vector<int> idxList;
	int count;
	int length;

	friend bool operator < (const DSC& item1, const DSC& item2)
	{
		if (item1.length > item2.length ||
			(item1.length == item2.length &&
			 item1.count < item2.count))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	std::priority_queue<DSC, std::vector<DSC>> DSCQueue;
	std::vector<int> charVector[26];
	std::vector<int> temList;
	char str[1001];
	DSC temItem;
	int temLength;
	int currentIdx = 0;
	int temSize = 0;
	int strLength = 0;

	while (1)
	{
		strLength = 0;
		currentIdx = 1;
		str[strLength] = getchar();
		
		for (int i = 0; i < 26; i++)
		{
			charVector[i].clear();
		}

		while (str[strLength] != '\n')
		{
			str[++strLength] = getchar();
			if (str[strLength] == ' ')
			{
				strLength--;
			}
		}

		if (str[0] == '\n')
		{
			break;
		}

		str[strLength] = '\0';

		for (int i = 0; i < strLength; i++)
		{
			charVector[str[i] - 'A'].push_back(i);
			str[i] -= 'A';
		}

		for (int i = 0; i < 26; i++)
		{
			temSize = charVector[i].size();
			if (temSize > 1)
			{
				temItem.idxList = charVector[i];
				temItem.count = temSize;
				temItem.length = 1;
				DSCQueue.push(temItem);
			}
		}

		while (1)
		{
			while (!DSCQueue.empty() && DSCQueue.top().length != currentIdx)
			{
				temItem = DSCQueue.top();
				temLength = temItem.length;
				temList = temItem.idxList;
				temSize = temItem.idxList.size();
				DSCQueue.pop();

				for (int i = 0; i < 26; i++)
				{
					charVector[i].clear();
				}

				for (int i = 0; i < temSize; i++)
				{
					if (temList[i] + temLength < strLength)
					{
						charVector[str[temList[i] + temLength]].push_back(temList[i]);
					}
				}

				for (int i = 0; i < 26; i++)
				{
					temSize = charVector[i].size();
					if (temSize > 1)
					{
						temItem.idxList = charVector[i];
						temItem.count = temSize;
						temItem.length = temLength + 1;
						DSCQueue.push(temItem);
					}
				}
			}

			if (DSCQueue.empty()) break;
			else printf("%d\n", DSCQueue.top().count);
			currentIdx++;
		}
		printf("\n");
	}
}