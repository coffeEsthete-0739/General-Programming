def is_safe(graph, colors, node, c):
    for i in range(len(graph)):
        if graph[node][i] == 1 and colors[i] == c:
            return False
    return True

def graph_coloring(graph, m, node=0, colors=[]):
    if node == len(graph):
        print(colors)
        return True
    for c in range(1, m+1):
        if is_safe(graph, colors, node, c):
            if graph_coloring(graph, m, node+1, colors+[c]):
                return True
    return False

n = int(input("Enter number of vertices: "))
print("Enter adjacency matrix:")
graph = [list(map(int, input().split())) for _ in range(n)]
m = int(input("Enter number of colors: "))
if not graph_coloring(graph, m):
    print("No solution found")
