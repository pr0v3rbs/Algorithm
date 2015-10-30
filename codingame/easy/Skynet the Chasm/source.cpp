#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int road; // the length of the road before the gap.
    cin >> road; cin.ignore();
    int gap; // the length of the gap.
    cin >> gap; cin.ignore();
    int platform; // the length of the landing platform.
    cin >> platform; cin.ignore();
    bool isJumped = false;

    cerr << road << endl;
    cerr << gap << endl;
    cerr << platform << endl;

    // game loop
    while (1) {
        int speed; // the motorbike's speed.
        cin >> speed; cin.ignore();
        int coordX; // the position on the road of the motorbike.
        cin >> coordX; cin.ignore();
        
        if (!isJumped)
        {
            if (speed <= gap)
            {
                cout << "SPEED" << endl;
            }
            else if (speed > gap + 1)
            {
                cout << "SLOW" << endl;
            }
            else if (road - coordX <= speed)
            {
                cout << "JUMP" << endl;
                isJumped = true;
            }
            else
            {
                cout << "WAIT" << endl;
            }
        }
        else
        {
            cout << "SLOW" << endl;
        }
    }
}