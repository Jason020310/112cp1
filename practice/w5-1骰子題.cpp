#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int top;
    int north;
    int west;
}
position;
void move(string direction,position &current);
int main(void)
{
    int n;
    string direction;
    position current;
    while(cin >> n)
    {
        current.top = 1;
        current.north = 2;
        current.west = 3;
        if(n == 0)
        {
            return 0;
        }
        for (int i = 0; i < n;i++)
        {
            cin >> direction;
            move(direction,current);
        }
        cout  << current.top << endl;
    }
}
void move(string direction,position &current)
{
    if(direction == "north")
    {
        int orginal_top = current.top;
        current.top = 7 - current.north;
        current.north = orginal_top;
    }
    else if (direction == "east")
    {
        int original_top = current.top;
        current.top = current.west;
        current.west = 7 - original_top;
        //北不變
    }
    else if (direction == "south")
    {
        int original_top = current.top;
        current.top = current.north;
        current.north = 7 - original_top;
    }
    else
    {
        int original_west = current.west;
        current.west = current.top;
        current.top = 7 - original_west;
    }
    return;
}