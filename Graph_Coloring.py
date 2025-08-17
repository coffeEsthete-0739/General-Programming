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

graph = [
    [0,1,1,1],
    [1,0,1,0],
    [1,1,0,1],
    [1,0,1,0]
]
graph_coloring(graph, 3)
