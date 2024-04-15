/*
Assignment13
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
*/
#include <bits/stdc++.h>
using namespace std;
char maze[10][10];
bool visited[10][10] = {0};
bool foundP = false;

// Function to perform Depth-First Search
void DFS(int x, int y);

int main(void)
{
    int length = 1;

    // Input the maze
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> maze[i][j];
        }
    }

    // Start DFS from position (1,1)
    DFS(1, 1);

    // Mark the starting point as 'C'
    maze[1][1] = 'C';

    if (foundP == false)
    {
        cout << "Fail" << endl;
    }
    else
    {
        cout << "Success" << endl;

        // Count the length of the path
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (maze[i][j] == '-')
                {
                    length += 1;
                }
            }
        }

        // Output the length of the path
        cout << length << endl;
    }

    // Output the maze
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int x, int y)
{
    // If 'P' is found, set foundP to true
    if (maze[x][y] == 'P')
    {
        foundP = true;
        return;
    }

    // Mark the current position as visited
    maze[x][y] = '-';

    // Check if out of bounds or already visited
    if (x > 9 || y > 9 || x < 0 || y < 0 || visited[x][y] == 1)
    {
        return;
    }

    visited[x][y] = true;

    // Recursively explore neighboring positions
    if (maze[x][y + 1] != '1' && visited[x][y + 1] == 0 && foundP == false)
    {
        DFS(x, y + 1);
    }
    if (maze[x - 1][y] != '1' && visited[x - 1][y] == 0 && foundP == false)
    {
        DFS(x - 1, y);
    }
    if (maze[x][y - 1] != '1' && visited[x][y - 1] == 0 && foundP == false)
    {
        DFS(x, y - 1);
    }
    if (maze[x + 1][y] != '1' && visited[x + 1][y] == 0 && foundP == false)
    {
        DFS(x + 1, y);
    }

    // If 'P' is not found, mark the current position as 'w'
    if (foundP == false)
    {
        maze[x][y] = 'w';
    }
    return;
}