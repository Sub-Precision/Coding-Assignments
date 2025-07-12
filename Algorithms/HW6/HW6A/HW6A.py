import heapq

def dijkstra(graph, s):
    # example in the slides was either incomplete or bugged because
    # it didnt like the .nodes function, so i added this so it will work
    path = {vertex: float('inf') for vertex in graph}
    path[s] = 0
    nodes = [(0, s)]
    # added history list to append to to record the visited node history
    visited = []
    while nodes: # while remaining nodes
        # added variables to record visited nodes
        (dist, current) = heapq.heappop(nodes)

        if dist > path[current]:
            continue

        for v, weight in graph[current].items():
            min_node = dist + weight # relaxation
            if min_node < path[v]:
                path[v] = min_node
                heapq.heappush(nodes, (min_node, v))
                visited.append((current, v, min_node))

    return path, visited

def main():
    graph = {
    'A': {'B': 4, 'C': 2},
    'B': {'A': 4, 'C': 1, 'D': 5},
    'C': {'A': 2, 'B': 1, 'D': 8, 'E': 10},
    'D': {'B': 5, 'C': 8, 'E': 2, 'F': 6},
    'E': {'C': 10, 'D': 2, 'F': 3, 'G': 5},
    'F': {'D': 6, 'E': 3, 'G': 2, 'H': 4},
    'G': {'E': 5, 'F': 2, 'H': 1},
    'H': {'F': 4, 'G': 1}
    }

    distances, history = dijkstra(graph, 'A')
    print("min distance to each node:", distances)
    print()
    print()
    print("history:", history)

main()

