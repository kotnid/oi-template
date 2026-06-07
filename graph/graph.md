# Definition #

## Articulation Point ##
a node of a graph whose deletion increases the graph's number of connected components

## Biconnected Component ##
within a BCC, every pair of nodes has at least two different paths without duplicate nodes (excluding starting and ending nodes)

## Block-Cut Tree ##
connect every bcc to form a tree 

## Bridge ## 
an edge of a graph whose deletion increases the graph's number of connected components.

## Bridge Connected Component ##
Group of components which connected when 1 edge is removed (2-edge-connected Component)

## Strongly Connected Component ##
a directed graph is strongly connected if every node u could reach every other node v (including node u itself) in the graph.

## Euler cycle ##
Connected graph and every node has even degree
Path start and end in same node 

## Euler Path ##
euler cycle or 2 odd and even 

## Remainder Shortest Path(同余最短路) ## 
if we have transition formula like : 
dp[v] = dp[u] + edge(u,v)
We can treat it as a shortest path algor 
Usually we will fixed the smallest available transition (as mod)

## 01 bfs ##
Edge weight either 0 or k 
push 0 at front, k at back


---

# Random graph knowledge

## Vertex Cover vs Independent Set
- Vertex Cover: set of nodes such that every edge touches at least one of the nodes 
- Independent Set: set of nodes such that no edge touches 2 nodes 
- Given Independent Set <=> unselected nodes form Vertex Cover (not form only when exist 1 edge 2 nodes in IS, which contradict with definition)
- Max IS + MIN VC = Total Vertices 

## Konig's Theorem (MVC in Bipartite)
- MVC = Maximum Matching if graph is bipartite
- Max flow can find the value then 