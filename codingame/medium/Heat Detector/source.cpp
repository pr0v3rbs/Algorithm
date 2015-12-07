#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 char Check(char* BOMB_DIR, char c)
 {
     if (BOMB_DIR[0] == c || BOMB_DIR[1] == c)
        return 1;
     else
        return 0;
 }
 
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int Xcurrent, Xmove;
    int Ycurrent, Ymove;
    char isFirst = 1;
    scanf("%d%d", &Xcurrent, &Ycurrent);

    // game loop
    while (1) {
        char BOMB_DIR[3]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", BOMB_DIR);
        
        if (isFirst)
        {
            if (Check(BOMB_DIR, 'D'))
            {
                Ymove = (H - Ycurrent) / 2;
            }
            else if (Check(BOMB_DIR, 'U'))
            {
                Ymove = (Ycurrent) / 2;
            }
            if (Check(BOMB_DIR, 'R'))
            {
                Xmove = (W - Xcurrent) / 2;
            }
            else if (Check(BOMB_DIR, 'L'))
            {
                Xmove = (Xcurrent) / 2;
            }
            isFirst = 0;
        }

        if (Check(BOMB_DIR, 'D'))
        {
            Ycurrent += Ymove;
            Ymove++;
        }
        else if (Check(BOMB_DIR, 'U'))
        {
            Ycurrent -= Ymove;
            Ymove++;
        }
        if (Check(BOMB_DIR, 'R'))
        {
            Xcurrent += Xmove;
            Xmove++;
        }
        else if (Check(BOMB_DIR, 'L'))
        {
            Xcurrent -= Xmove;
            Xmove++;
        }
        
        if (Xcurrent >= W) Xcurrent = W - 1;
        else if (Xcurrent < 0) Xcurrent = 0;
        if (Ycurrent >= H) Ycurrent = H - 1;
        else if (Ycurrent < 0) Ycurrent = 0;

        Xmove /= 2;
        Ymove /= 2;
        
        printf("%d %d\n", Xcurrent, Ycurrent);
    }

    return 0;
}