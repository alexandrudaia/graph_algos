from collections import deque 

def bfs(n , adj ,start , end):
    dist = [float('inf')]*(n+1)
    queue=deque()
    queue.append(start)
    dist[start]=0
    while queue:
        now=queue.popleft()
        for vertex in adj[now]:
            if dist[vertex] == float('inf'):
                queue.append(vertex)
                dist[vertex]=dist[now]+1
    return dist[end]

if __name__ == '__main__':
    n_vertices, n_edges = map(int, input().split())
    adjacency_list = [[] for _ in range(n_vertices + 1)]
    for i in range(n_edges):
        a, b = map(int, input().split())
        adjacency_list[a].append(b)
        adjacency_list[b].append(a)
    u, v = map(int, input().split())
    distance = bfs(n_vertices, adjacency_list, u, v)
    if distance == float('inf'):
        print(-1)
    else:
        print(distance)
