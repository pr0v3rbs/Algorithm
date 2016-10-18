#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, d;
	int result = 0;

	scanf("%d", &n);

	vector<pair<int, int> > rails(n);
	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		rails[i].second = min(a, b);
		rails[i].first = max(a, b);
	}

	scanf("%d", &d);
	sort(rails.begin(), rails.end());

	for (int i = 0; i < n; i++)
	{
		pq.push(-rails[i].second);

		while (!pq.empty())
		{
			if (-(pq.top()) < rails[i].first - d)
			{
				pq.pop();
			}
			else
			{
				break;
			}
		}

		result = max(result, (int)pq.size());
	}

	printf("%d\n", result);
}
