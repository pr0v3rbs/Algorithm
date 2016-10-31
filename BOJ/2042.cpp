#include <bits/stdc++.h>
using namespace std;

long long arr[1000000];
vector<long long> tree;

long long SegTreeInit(int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    else
        return tree[node] = SegTreeInit(node * 2, start, (start + end) / 2) + SegTreeInit(node * 2 + 1, (start + end) / 2 + 1, end);
}

void SegTreeUpdate(int node, int start, int end, int idx, long long diff)
{
    if (idx < start || end < idx) return;
    tree[node] += diff;
    if (start != end)
    {
        SegTreeUpdate(node * 2, start, (start + end) / 2, idx, diff);
        SegTreeUpdate(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}

long long SegTreeSum(int node, int start, int end, int left, int right)
{
    // mistake caution.
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return SegTreeSum(node * 2, start, (start + end) / 2, left, right) + SegTreeSum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
    int n, m, k;
    int treeHeight, treeSize;

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    treeHeight = (int)ceil(log2(n));
    treeSize = (1 << (treeHeight + 1));
    tree.reserve(treeSize);

    SegTreeInit(1, 0, n - 1);

    m += k;
    while (m--)
    {
        long long t1, t2, t3;
        scanf("%lld%lld%lld", &t1, &t2, &t3);

        if (t1 == 1)
        {
            long long diff = t3 - arr[--t2];
            arr[t2] = t3;
            SegTreeUpdate(1, 0, n - 1, t2, diff);
        }
        else
        {
            printf("%lld\n", SegTreeSum(1, 0, n - 1, t2 - 1, t3 - 1));
        }
    }
}
