#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

struct Node
{
    int edge;
    int degree;
    friend bool operator < (const Node &t1, const Node &t2)
    {
        return t1.degree > t2.degree;
    }
    Node(){}
    Node(int e, int d) : edge(e), degree(d) {}
};

char hasNotAirport[2000];
int dijk[2000][2000];
std::vector<int> airportLine[2000];
std::priority_queue<Node, std::vector<Node>> pQueue;

void MakeDijk(int startN, int maxN)
{
    Node temNode;
    Node addNode;
    int temStartEdge = 0;
    int temDestEdge = 0;
    int airportNum = 0;

    for (int i = 0; i < maxN; i++)
        dijk[startN][i] = 2001;

    dijk[startN][startN] = 1;
    pQueue.push(Node(startN, hasNotAirport[startN]));

    while (!pQueue.empty())
    {
        temNode = pQueue.top();
        pQueue.pop();
        temStartEdge = temNode.edge;
        if (dijk[startN][temNode.edge] < temNode.degree) continue;

        airportNum = airportLine[temStartEdge].size();
        for (int i = 0; i < airportNum; i++)
        {
            temDestEdge = airportLine[temStartEdge][i];
            if (dijk[startN][temDestEdge] > temNode.degree + hasNotAirport[temDestEdge])
            {
                dijk[startN][temDestEdge] = temNode.degree + hasNotAirport[temDestEdge];
                addNode.edge = temDestEdge;
                addNode.degree = dijk[startN][temDestEdge];
                pQueue.push(addNode);
            }
        }
    }
}

int main()
{
    int X = 0;
    int i = 0;
    scanf("%d", &X);

    for (int test = 1; test <= X; test++)
    {
        int N = 0;
        int M = 0;
        int K = 0;
        int Q = 0;
        int tem1 = 0;
        int tem2 = 0;

        scanf("%d%d%d", &N, &M, &K);

        for (i = 0; i < N; i++)
        {
            dijk[i][i] = 2001;
            hasNotAirport[i] = 1;
            airportLine[i].clear();
        }

        for (i = 0; i < K; i++)
        {
            scanf("%d", &tem1);
            hasNotAirport[tem1 - 1] = 0;
        }

        for (i = 0; i < M; i++)
        {
            scanf("%d%d", &tem1, &tem2);
            airportLine[tem1 - 1].push_back(tem2 - 1);
            airportLine[tem2 - 1].push_back(tem1 - 1);
        }

        scanf("%d", &Q);

        printf("Case %d:\n", test);
        for (i = 0; i < Q; i++)
        {
            scanf("%d%d", &tem1, &tem2);

            if (tem1 == tem2)
            {
                printf("0\n");
            }
			else
			{
				if (dijk[tem1 - 1][tem1 - 1] == 2001)
				{
					MakeDijk(tem1 - 1, N);
				}

				if (dijk[tem1 - 1][tem2 - 1] == 2001)
				{
					printf("-1\n");
				}
				else
				{
					printf("%d\n", dijk[tem1 - 1][tem2 - 1]);
				}
			}
        }
        printf("\n");
    }
}