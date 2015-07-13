/*
Author 		: manojpandey
Algorithm	: Depth First Search
*/

#include <iostream>
#include <vector>
#include <stack>
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

bool dfs(int start_vertex) {
	int i, u, v, len;
    vi visited(n+1, false);
    stack <int> S;
    S.push(start_vertex);
    while (!S.empty()) {
        u = S.top();
        S.pop();
        cout << u << " ";
        if (!(visited[u])) {
            visited[u] = true;
            tr(g[u], it) { 
                S.push(*it);
            }
        }
    }
}

int main () {

	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &e);
	int i, u, v;
	rep(i,e) {
		scanf("%d%d", &u, &v);
		cout << u <<" --> " << v << "\n";
		g[u].push_back(v);
	}
	
	//Traverse the given graph from vertex-0
	dfs(1);
	
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