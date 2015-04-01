/*
Author      :   manojpandey
Algorithm   :   Kruskal's Algorithm for Minimum Spanning Tree
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;
  
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define rep(i,n) for (i=0; i<n ; i++)
#define rep1(i,n) for (i=1; i<=n ; i++)
#define MAX 1111111
#define CHAR_BIT 8
#define edge pair< int, int >

vector< pair< int, edge > > GRAPH, MST;
int parent[MAX], total, N, E;

int findset(int x, int *parent) {
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal() {
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // arrange in order of edge weights
    for(i = total = 0; i<E; i++) {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv) {
            MST.push_back(GRAPH[i]); // include in the spanning tree
            total += GRAPH[i].first; // include the edge cost
            parent[pu] = parent[pv]; // connect
        }
    }
}

void init() {
    for (int i = 1; i <= N; i++) 
        parent[i] = i;
}

void print() {
    int i, sz;
    sz = MST.size();
    for(i=0; i<sz; i++) {
        printf ("( %d, %d ): %d\n", MST[i].second.first, MST[i].second.second , MST[i].first );
    }
    printf("Minimum cost: %d\n", total);
}

int main() {
    freopen("in.txt", "r", stdin);
    int i, u, v, w;

    scanf("%d %d", &N, &E);
    init();
    for(i=0; i<E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        GRAPH.push_back(pair< int, edge >(w, edge(u, v)));
    }
    kruskal(); 
    print(); 
    return 0;
}