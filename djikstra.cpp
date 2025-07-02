#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

const int N = 5;

/* void dijkstra(int adjMat[N][N], int src, int distMat[N][N])
{
    vector<bool> visited(N, false);
    vector<int> distance(N, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    distance[src] = 0;
    minHeap.push({distance[src], src});

    while (!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u])
        {
            continue;
        }

        visited[u] = true;

        for (int v = 0; v < N; v++)
        {
            if (adjMat[u][v] == 1 && !visited[v] && distMat[u][v] != 0)
            {
                int newDist = distance[u] + distMat[u][v];
                if (newDist < distance[v])
                {
                    distance[v] = newDist;
                    minHeap.push({distance[v], v});
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout<<"Node "<<i<<": ";
        if (distance[i] == INT_MAX)
        {
            cout<<"unreachable"<<endl;
        }
        else
        {
            cout<<distance[i]<<endl;
        }

    }

} */

/* void dijkstra(int adjMat[N][N], int src, int distMat[N][N])
{
    vector<bool> visited(N, false);
    vector<int> distance(N, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    distance[src] = 0;
    minHeap.push({distance[src], src});

    while (!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        for (int v = 0; v < N; v++)
        {
            if (adjMat[u][v] == 1 && !visited[v] && distMat[u][v] != 0)
            {
                int newDist = distMat[u][v] + distance[u];
                if (newDist < distance[v])
                {
                    distance[v] = newDist;
                    minHeap.push({distance[v], v});
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << "Node " << i << ": ";
        if (distance[i] == INT_MAX)
        {
            cout << "unreachable" << endl;
        }
        else
        {
            cout << distance[i] << endl;
        }
    }
} */

void dijkstra(int adjMat[N][N], int src, int distmat[N][N])
{
    vector<bool> visited(N, false);
    vector<int> distance(N, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    distance[src] = 0;
    minHeap.push({distance[src], src});

    while (!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        for (int v = 0; v < N; v++)
        {
            if (adjMat[u][v] == 1 && !visited[v] && distmat[u][v] != 0)
            {
                int newDist = distance[u] + distmat[u][v];
                if (newDist < distance[v])
                {
                    distance[v] = newDist;
                    minHeap.push({distance[v], v});
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "Node " << i << ": ";
        if (distance[i] == INT_MAX)
        {
            cout << "unreachable" << endl;
        }
        else
        {
            cout << distance[i] << endl;
        }
    }
}
int main()
{
    int adjMat[N][N] = {
        // 0  1  2  3  4
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0}};
    int dist[N][N] = {
        // 0  1  2  3  4
        {0, 7, 0, 0, 1},
        {7, 0, 3, 0, 8},
        {0, 3, 0, 6, 2},
        {0, 0, 6, 0, 7},
        {1, 8, 2, 7, 0}};
    int src = 0;
    dijkstra(adjMat, src, dist);
}
