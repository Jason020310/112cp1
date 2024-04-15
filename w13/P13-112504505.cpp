#include <bits/stdc++.h>
using namespace std;

// Function declarations
void DFS(int x, int y);
void remove(int x, int y);

// Global variables
bool visited[10][10] = {0};
char park[10][10];
int area;
int startnum = 0;

// Structure definition for storing information about connected components
typedef struct {
    int x, y, area;
} LOG;

int main(void) {
    // Local variables
    LOG array[100];
    vector<int> areas;

    // Input for the park array
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> park[i][j];
        }
    }

    // Loop to identify connected components of 'w' cells
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // If a 'w' cell is found and has not been visited, perform DFS
            if (park[i][j] == 'w' && visited[i][j] == false) {
                area = 0;
                DFS(i, j);
                // Store information about the connected component
                array[startnum].x = i;
                array[startnum].y = j;
                array[startnum].area = area;
                areas.push_back(area);
                startnum++;
            }
        }
    }

    // Sort and reverse the areas vector to get the largest connected component first
    sort(areas.begin(), areas.end());
    reverse(areas.begin(), areas.end());

    // Clear the visited array and remove cells from the largest connected component
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < startnum; i++) {
        if (array[i].area == areas[0]) {
            DFS(array[i].x, array[i].y);
        }
    }

    // Mark the visited cells as 'D'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (visited[i][j] == 1) {
                park[i][j] = 'D';
            }
        }
    }

    // Output the areas of connected components
    for (int i = 0; i < areas.size(); i++) {
        cout << areas[i] << " ";
    }
    cout << endl;

    // Output the modified park array
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << park[i][j] << " ";
        }
        cout << endl;
    }
}

// Depth-First Search (DFS) function
void DFS(int x, int y) {
    // Base cases for DFS termination
    if (x > 9 || y > 9 || x < 0 || y < 0 || park[x][y] == 'D' || visited[x][y] == true) {
        return;
    }

    // Mark the current cell as visited and increment the area
    visited[x][y] = true;
    area += 1;

    // Recursive DFS calls for neighboring cells
    DFS(x + 1, y);
    DFS(x - 1, y);
    DFS(x, y - 1);
    DFS(x, y + 1);
}