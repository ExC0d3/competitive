/*
Author: Manoj Pandey
Codechef, Codeforces, Spoj  @ manojpandey
*/

//Includes

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stddef>
#include <sstream> // istringstream>> ostring stream<<
#include <stack>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <cstring>
#include <string>
#include <cstdlib>
#include <valarray>
#include <queue>
#include <bitset>
#include <ctime>
#include <stack>
#include <cassert>

using namespace std;

//Typedefs

typedef long long                   ll;
typedef long double                 ld;
typedef unsigned long long          ull;
typedef vector <int>                vi; 
typedef vector <vi>                 vvi; 
typedef vector <string>             vs;
typedef vector <ll>                 vll; 
typedef vector <pair<int,int> >     vpii;
typedef vector <pair<ll, ll> >      vpll;
typedef pair <int,int>              pii; 
typedef pair <long long,long long>  pll; 
typedef istringstream iss;
typedef ostringstream oss;

//Defines

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define fu(i,a,n) for(int (i)=(int)(a);(i)<=(int)(n);++(i))
#define fd(i,n,a) for(int (i)=(int)(n);(i)<=(int)(a);--(i))
#define all(c) ((c).begin(),(c).end()) 
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) //Travelling Iterator
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mset(m,v) memset(m,v,sizeof(m))
#define ln length()
#define sz(a) int((a).size()) 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
#define present(c,x) ((c).find(x) != (c).end()) // for all other containers
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vector 
#define getchar getchar_unlocked
#define putchar putchar_unlocked

#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif

#define EPS (1e-9)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define MAX 111111
#define MOD 1000000007

template <typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template <typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

inline void fastRead_int(int *a) {
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33) {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

inline void fastRead_string(char *str) {
    register char c=0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked();
    while (c > 65) {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}

inline void fastWrite(int a) {
    char snum[20];
    int i=0;
    do {
        snum[i++]=a%10+48;
        a=a/10;
    }   while(a!=0);
    
    i--;
    while(i >= 0)   putchar(snum[i--]);
}

int main () {

	return 0;
}