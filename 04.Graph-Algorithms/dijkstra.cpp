/*
Author      :   manojpandey
Algorithm   :   Dijkstra's algorithm for Single Source Shortest Path
                Speeding up using Priority Queue
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring> //memset
#include <queue>
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
#define traverse(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define rep(i,n) for (i=0; i<n ; i++)
#define rep1(i,n) for (i=1; i<=n ; i++)
#define MAX 1111111
#define INF 100000000

typedef pair<int, int> ii;

int depths[MAX+1];
vector<ii> adj[MAX+1];
bool completed[MAX+1];

struct MinHeap {
    bool operator()(int a, int b) {
        return depths[a] > depths[b];
    }
};

int dijkstra(int source, int dest) {
    int temp, newv, cost;
    depths[source] = 0;
    priority_queue<int, vector<int>, MinHeap> Q;
    Q.push(source);
    while(!Q.empty()) {
        temp = Q.top();
        Q.pop();
        if(completed[temp])
            continue;
        completed[temp] = true;
        if(temp == dest)
            return depths[dest];
        traverse(adj[temp], w) {
            newv = (*w).first;
            cost = (*w).second;
            if(completed[newv])
                continue;
            if(depths[temp] + cost < depths[newv]) {
                depths[newv] = depths[temp] + cost;
                Q.push(newv);
            }
        }
    }
    return 0;
}

int main() {
    int n, m, source, dest, a, b, c;
    cin >> n;
    for(int i = 0; i <= n; i++)
        depths[i] = INF;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back(ii(b, c));
        adj[b].push_back(ii(a, c));
    }
    cin >> source >> dest;
    cout << dijkstra(source, dest) << "\n";
    return 0;
}