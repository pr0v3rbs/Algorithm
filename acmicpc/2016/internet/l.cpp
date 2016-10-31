#include <bits/stdc++.h>
using namespace std;

int n, w, L;
int arr[1000];
int bridge[100];

int main()
{
    int truckWSum = 0;
    int truckIdx = 0;
    int time = 1;

    scanf("%d%d%d", &n, &w, &L);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    truckWSum = arr[truckIdx];
    bridge[w - 1] = arr[truckIdx++];

    while (truckIdx != n)
    {
        time++;
        if (bridge[0])
            truckWSum -= bridge[0];

        for (int i = 0; i < w - 1; i++)
            bridge[i] = bridge[i + 1];
        bridge[w - 1] = 0;

        if (truckWSum + arr[truckIdx] <= L)
        {
            truckWSum += arr[truckIdx];
            bridge[w - 1] = arr[truckIdx++];
        }
    }

    printf("%d\n", time + w);
}
