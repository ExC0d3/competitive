/*
Author    : manojpandey
Algorithm : Breadth First Search
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>

using namespace std;

// From TopCoder
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define rep(i,n) for (i=0; i<n ; i++)
#define rep1(i,n) for (i=1; i<=n ; i++)
#define MAX 11111

int n, e; // number of vertices, edges
vi g[MAX]; // lists of adjacent vertices

bool bfs(int start_vertex) { 
  vi visited(n+1, false);
  queue<int> Q; 
  Q.push(start_vertex); 
  visited[start_vertex] = true; 
  while(!Q.empty()) { 
       int u = Q.front(); 
       cout << u << " ";
       Q.pop(); 
       tr(g[u], it) {            
            if(!visited[*it]) { 
                 visited[*it] = true; 
                 Q.push(*it); 
            } 
       } 
  } 
} 

int main() {
	
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &e);
    int i, u, v;
    rep(i,e) {
      scanf("%d%d", &u, &v);
      cout << u <<" --> " << v << "\n";
      g[u].push_back(v);
      g[v].push_back(u);
    }
	
	//Traverse the given graph from vertex-0
	bfs(1);

	return 0;
}

/*
------
in.txt
------

10 9	// 10 vertices, 9 edges
1 2
1 3
2 4
2 5
3 6
5 7
5 8
6 9
6 10

*/