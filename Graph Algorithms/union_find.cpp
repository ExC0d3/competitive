/*
Author 		:	manojpandey
Algorithn	:	Disjoint Data Structure: Union Find Algorithm
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <tr1/unordered_map>
#define MAX 200001
#define MOD 1000000007

typedef long long ll;
ll a[MAX];

using namespace std;

int size [MAX];
int parent [MAX];

// Find the root 
int root(int i) {
	while(i!=parent[i])
		i = parent[i];
	return i;
}

// Union of two group of nodes
void unite(int a,int b){	
	int ra = root(a);
	int rb = root(b);
	if(ra==rb)
		return;
	if(size[ra] > size[rb]) {
		parent[rb] = ra;
		size[ra] += size[rb];
	}
	else { 
		parent[ra] = rb;
		size[rb] += size[ra];
	}
	return;
}

int main() {

	int test;
	scanf("%ld",&test);
	while(test--) {	
		tr1::unordered_map<string,int> table;
		int n;
		scanf("%d",&n);
		int index = 1;
		while(n--) {
			string a,b;
			cin >> a >> b;
			if(!table[a]) {
				table[a] = index;
				size[index] = 1;
				parent[index] = index;
				index++;
			}
			if(!table[b]) {
				table[b] = index;
				parent[index] = index;
				size[index] = 1;
				index++;
			}

		// union of two sets!
			unite(table[a],table[b]);
			printf("%lld\n",size[root(table[a])]);
		} 
	}
	return 0;
}