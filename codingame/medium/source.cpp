#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int N;
set<int> gGraph[500];
vector<int> gateways;
int gDistance[500];

void SetDistance()
{
    int distance = 0;
    queue<int> q;
    int node;
    bool checkList[500];
    size_t qSize = 0;
    
    for (auto gIter = gateways.begin(); gIter != gateways.end(); ++gIter)
    {
        distance = 1;
        for (int i = 0; i < N; ++i)
            checkList[i] = false;
        checkList[*gIter] = true;
        
        for (auto nIter = gGraph[*gIter].begin(); nIter != gGraph[*gIter].end(); ++nIter)
        {
            q.push(*nIter);
            checkList[*nIter] = true;
        }
        
        while (!q.empty())
        {
            qSize = q.size();
            
            for (int i = 0; i < qSize; ++i)
            {
                node = q.front();
                q.pop();
    
                if (gDistance[node] == 0 || gDistance[node] > distance)
                {
                    gDistance[node] = distance;
                }
                
                
                for (auto nIter = gGraph[node].begin(); nIter != gGraph[node].end(); ++nIter)
                {
                    if (checkList[*nIter] == false)
                    {
                        q.push(*nIter);
                        checkList[*nIter] = true;
                    }
                }
            }
            
            ++distance;
        }
    }

    for (auto gIter = gateways.begin(); gIter != gateways.end(); ++gIter)
    {
        gDistance[*gIter] = 0;
    }
}
 
int main()
{
    int L; // the number of links
    int E; // the number of exit gateways
    set<int>::iterator sIter;
    
    cin >> N >> L >> E; cin.ignore();
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        gGraph[N1].insert(N2);
        gGraph[N2].insert(N1);
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        gateways.push_back(EI);
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        int shortPath = 1000;

        for (int i = 0; i < N; i++)
            gDistance[i] = 0;
        SetDistance();

        for (auto nIter = gGraph[SI].begin(); nIter != gGraph[SI].end(); ++nIter)
        {
            if (shortPath >= gDistance[*nIter])
            {
                shortPath = gDistance[*nIter];
                sIter = nIter;
            }
        }
        
        for (auto nIter = gGraph[*sIter].begin(); nIter != gGraph[*sIter].end(); ++nIter)
        {
            if (*nIter == SI)
            {
                gGraph[*sIter].erase(nIter);
                break;
            }
        }
        
        gGraph[SI].erase(sIter);
        cout << SI << " " << *sIter << endl;
    }
}