#line = input()
#line.split(' ')
n = int(input("N ?")) #no. of vertices.
m = int(input("M ?")) #no. of edges
graph = {}
#print(n)
visited = []
i = 0
while i < n:
	graph[i + 1] = []
	visited.append(i + 1)
	i+=1

i = 0
while i < m:
	x = int(input("Node 1"))
	y = int(input("Node 2"))

	graph[x].append(y)
	graph[y].append(x)
	i += 1

print("The Graph")
print(graph)
def hamil_path(graph, visited, x):
	if visited == []:
		return [x]
	for p in graph[x]:
		if p in visited:
			visited.remove(p)
			path = hamil_path(graph, visited, p)
			if(path != []):
				path.append(x)
				return path
			else:
				visited.append(p)
	
	return []

start = 1
visited.remove(start)
print(hamil_path(graph, visited, start))
