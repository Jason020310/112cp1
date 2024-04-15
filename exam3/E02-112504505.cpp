#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int top;
    int north;
    int west;
}
position;
void move(string direction,position &current,int angle);
int main(void)
{
    int n;
    string direction;
    int angle;
    position current;
    current.top = 1;
    current.north = 2;
    current.west = 3;
    while(cin >> n)
    {
        if(n == 0)
        {
            return 0;
        }
        for (int i = 0; i < n;i++)
        {
            cin >> direction >> angle;
            move(direction,current,angle);
        }
        cout  << "The number on the top of the die is " << current.top << "." << endl;
    }
}
void move(string direction,position &current,int angle)
{
    int times = angle / 90;
    if(direction == "north")
    {
        for (int i = 0 ; i < times;i++)
        {
            int orginal_top = current.top;
            current.top = 7 - current.north;
            current.north = orginal_top;
        }
    }
    else if (direction == "east")
    {
        for(int i = 0 ; i < times;i++)
        {
            int original_top = current.top;
            current.top = current.west;
            current.west = 7 - original_top;
        //北不變
        }
    }
    else if (direction == "south")
    {
        for (int i = 0 ; i < times;i++)
        {
            int original_top = current.top;
            current.top = current.north;
            current.north = 7 - original_top;
        }
    }
    else
    {
        for(int i = 0 ;i < times;i++)
        {
            int original_west = current.west;
            current.west = current.top;
            current.top = 7 - original_west;
        }
    }
    return;
}