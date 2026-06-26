from priority_queue import PriorityQueue

def dijkstra(graph: dict, start_node) -> dict:
    pq = PriorityQueue()
    d = dict.fromkeys(graph, float('inf'))
    d[start_node] = 0
    pq.push(start_node, 0)
    while len(pq) > 0:
        new_dist, curr_node = pq.pop()
        if new_dist > d[curr_node]:
            continue
        for adj, dist in graph.get(curr_node, {}).items():
            new_cost = d[curr_node] + dist
            if d[adj] > new_cost:
                d[adj] = new_cost
                pq.push(adj, new_cost)
    return d