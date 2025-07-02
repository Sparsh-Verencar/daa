#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

const int N = 4;

void dfs(int adjMat[][N], int root, vector<bool> visited)
{
    visited[root] = true;
    cout << "visiting (DFS): " << root;

    for (int i = 0; i < N; i++)
    {
        if (adjMat[root][i] == 1 && !visited[i])
        {
            dfs(adjMat, i, visited);
        }
    }
    return;
}

void bfs(int adjMat[][N], int root)
{
    vector<bool> visited(N, false);
    queue<int> q;
    visited[root] = true;
    q.push(root);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << "visiting (DFS): " << root;

        for (int i = 0; i < N; i++)
        {
            if (adjMat[root][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int adjMatrix[N][N] = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 1},
        {1, 0, 0, 0}};

    vector<bool> visitedDFS(N, false);

    cout << "Depth First Search\n";
    dfs(adjMatrix, 0, visitedDFS);

    cout << "\nBreadth First Search\n";
    bfs(adjMatrix, 0);

    return 0;
}
