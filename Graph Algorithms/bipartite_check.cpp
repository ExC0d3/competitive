/*
Author      :   manojpandey
Algorithm   :   Checking for Bipartiteness in an undirected graph
*/


#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
#define MAX 1001
 
int n, e;
int partition[MAX], visited[MAX];
vector< int > G[MAX];
 
bool is_bipartite() {
    int i, u, v, start;
    queue< int > Q;
    start = 1; // nodes labeled from 1
    Q.push(start);
    partition[start] = 1; // 1 left, 2 right
    visited[start] = 1; // set gray
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        for(i=0; i < G[u].size(); i++) {
            v = G[u][i];
            if(partition[u] == partition[v]) return false;
            if(visited[v] == 0) {
                visited[v] = 1;
                partition[v] = 3 - partition[u]; // alter 1 and 2
                Q.push(v);
            }
        }
    }
    return true;
}
 
int main() {
    int i, u, v;
    scanf("%d %d", &n, &e);
    for(i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(is_bipartite()) printf("Yes\n");
    else printf("No\n");
    return 0;
}