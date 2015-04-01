/* 
    Topological Sort
    Author : manojpandey

    Algo:

        1. Store each vertex’s In-Degree in an array D

        2. Initialize queue with all “in-degree=0” vertices

        3. While there are vertices remaining in the
        queue:

            (a) Dequeue and output a vertex
            (b) Reduce In-Degree of all vertices adjacent to it by 1
            (c) Enqueue any of these vertices whose In-Degree
                became zero

        4. If all vertices are output then success,
        otherwise there is a cycle
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

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

int n, e;
int a[MAX];
vector <int> g[MAX];
bool visited[MAX];

void topsort(){
    int i;
    queue <int> Q;
    rep1(i,n) if( a[i] == 0 ) Q.push(i) ;
    while(!Q.empty()){
        int u = Q.front(); Q.pop(); cout << u << " ";
        tr(g[u],it){
            a[*it]--;
            if( !a[*it ] ) Q.push(*it) ;
        }
    }
}

int main () {
    freopen ("in.txt", "r", stdin);
    int i, u, v;
    cin >> n >> e;
    rep(i,e) {
        cin >> u >> v;
        a[v]++;
        g[u].push_back(v);
    }
    topsort();
    return 0;
}

/*
------
in.txt
------
7 9 // 7 vertices and 9 edges

1 2
1 3
2 4
3 5
4 5
4 6
5 6
7 2
7 3

Output: 1 7 2 3 4 5 6
*/