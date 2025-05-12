#include <stdio.h>
#include <limits.h>
#include <string.h>

#define V 6

int visited[V];

int bfs(int graph[V][V], int s, int t, int parent[V]) {
    int queue[V], front = 0, rear = 0;
    memset(visited, 0, sizeof(visited));
    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (visited[v] == 0 && graph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return (visited[t] == 1);
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v, parent[V], max_flow = 0;
    int residualGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            residualGraph[u][v] = graph[u][v];

    while (bfs(residualGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (residualGraph[u][v] < path_flow)
                path_flow = residualGraph[u][v];
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    int source = 0, sink = 5;
    printf("%d\n", fordFulkerson(graph, source, sink));
    return 0;
}