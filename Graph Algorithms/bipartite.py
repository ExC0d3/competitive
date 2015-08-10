# -*- coding: utf-8 -*- 
"""
Bipartite Graph: 

	A bipartite graph is an undirected graph G = (V, E) 
	in which V can be partitioned into two sets V1 and V2 
	such that (u, v) ∈ E implies either u ∈ V1 and v ∈ V2 or u ∈ V2 and v ∈ V1.

2-coloring problem for detecting a bipartite graph:
	To check if a given undirected graph can be bipartite or not.

Algorithm:

1. Start BFS or DFS from any vertex as source.

2. Label the color as Red.

3. Mark all it's neighbours as Black.

4. Proceed in this way, alternatively marking the colors, as Red and Black.

5. At any time, if we find that for a vertex, if it's neighbour is colored same, then 
	the graph cannot be 2-colored OR the graph is NOT bipartite.
"""

def bipartite_DFS (graph, source, visited = []):
	"""
		This method takes an undirected graph and a source vertex as input
		and checks whether the graph is bipartite or not
		
		visited list saves the record for every vertex if it is visited
		Initally all are unvisited, and visited[] is empty

	"""
	# Put source in stack
	# Here the list 'stack' will act as a LIFO structure
	stack = [source]
	# Let's start colring the source by red
	color[source] = 0
	# While stack is not empty:
	while stack:
		# vertex = top of stack and pop it
		vertex = stack.pop(-1)
		# if vertex is not visited:
		if vertex not in visited:
			# mark it visited
			visited += [vertex]
			# Put vertex's neighbours to stack
			stack += (graph[vertex])
			# color the children if uncolored
			# children's will be colored opposite to that of parent
			for v in graph[vertex]:
				if color[v] == -1 :
					color[v] = (color[vertex] + 1) % 2
			# if colored, match children and parent's color, if equal, not bipartite
				elif color[v] == color[vertex]:
					print "NOT BIPARTITE"
					return
	print "BIPARTITE"
	# print final color states
	for i in range(vertices):
		print "color of vertex", i , " is ", findColor(color[i])

vertices = 7 # number of vertices

# A Bipartite graph
graph = {
	0:[1,2],
	1:[4,3,0],
	2:[5,0],
	3:[1],
	4:[1],
	5:[6,2],
	6:[5]
}


# Non-bipartite Graph
"""
vertices = 7 # number of vertices
graph = {
	0:[1,2],
	1:[4,3,0],
	2:[5,0],
	3:[1],
	4:[1],
	5:[6,2],
	6:[5]
}
"""

# color states
# -1	:	UNCOLORED
# 0		:	RED
# 1		:	BLACK

def findColor(state):
	if state == 0:
		return "Red"
	elif state == 1:
		return "Black"

# This will save the color state for every vertex
# Initially, uncolored
color = [-1 for i in range(vertices)]


def main():
	# Checking bipartiteness with DFS
	bipartite_DFS(graph, 0)

if __name__ == '__main__':
	main()
