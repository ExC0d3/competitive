/*
Author      :   manojpandey
Algorithm   :   Prim's Algorithm for Minimum Spanning Tree
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

struct Path {
	int edgeVal;
	int endIndex;
};

struct minHeap {
    bool operator()(Path a , Path b ) {
        return a.edgeVal > b.edgeVal;
    }
};

int main() {	

	int test; {
		
		int junctions, ways;
		scanf("%d %d", &junctions, &ways);
		queue<Path>array[junctions]; //adjacency_list
		bool reached[junctions];
		priority_queue <Path, vector<Path> ,minHeap> pq ;
		
		for(int i=0;i<ways;i++) {	
			int a1,a2,cost;
			scanf("%d %d %d", &a1, &a2, &cost);
			a1--; a2--;

			Path one,two;

			one.edgeVal = cost;
			two.edgeVal = cost;
			one.endIndex = a2;
			two.endIndex = a1;
			array[a1].push(one);// making a graph
			array[a2].push(two);
			reached[a1] = reached[a2] = false;
		}

		int counter = 1;
		reached[0]= true;
		int mst = 0;
		int currIndex = 0;	
		while(1) {	
			if(counter >=junctions) break;
			Path temp;
			while(!array[currIndex].empty()) {
				temp = array[currIndex].front();
				array[currIndex].pop();
				if(!reached[temp.endIndex]) {
					pq.push(temp);
				}					
			}
			
			Path minimum;
			do { 	
				if(pq.empty())
					break;	
				minimum = pq.top();
				pq.pop();
			} while (reached[minimum.endIndex]);
			mst += minimum.edgeVal;
			currIndex = minimum.endIndex;
			reached[currIndex] = true;
			counter ++ ;
		}
		printf("%d\n",mst);
	}
	return 0;
}
