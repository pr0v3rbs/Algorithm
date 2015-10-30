#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int lightX;
    int lightY;
    int initialTX;
    int initialTY;
    scanf("%d%d%d%d", &lightX, &lightY, &initialTX, &initialTY);
    
    int goX = lightX - initialTX;
    int goY = lightY - initialTY;

    while (1) {
        int remainingTurns;
        scanf("%d", &remainingTurns);
        
        if (goY > 0)
        {
            cout<<"S";
            goY--;
        }
        else if (goY < 0)
        {
            cout<<"N";
            goY++;
        }
        if (goX < 0)
        {
            cout<<"W";
            goX++;
        }
        else if (goX > 0)
        {
            cout<<"E";
            goX--;
        }
        
        cout<<endl;
    }
}