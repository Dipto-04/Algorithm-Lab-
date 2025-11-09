🌟 Bicoloring (BFS) – Problem Analysis








✅ Overview

The Graph Bicoloring Problem determines whether a graph can be colored using two colors such that no two adjacent vertices share the same color. This is equivalent to checking whether the graph is bipartite.

🔑 Key Concepts

A graph is bipartite if its vertices can be divided into two disjoint sets where all edges connect nodes from opposite sets.

Bicoloring fails when the graph contains an odd-length cycle.

BFS is an effective method for validating bipartite structure.

🧭 When Bicoloring Fails

Presence of any odd cycle (3-cycle, 5-cycle, etc.)

Example: A triangle (3-cycle) cannot be colored using only two colors without conflict.

🚀 BFS-Based Bicoloring Algorithm

Initialize all vertices as Uncolored (-1).

Select a starting vertex and color it 0.

Run BFS, assigning opposite colors (1 - color[u]) to adjacent vertices.

If any adjacent vertices share the same color, report NOT bicolorable.

If BFS completes without conflict, the graph is Bicolorable (Bipartite).

📘 Pseudocode

FUNCTION isBicolorable(n, adjList):

    DECLARE colors[n]
    FOR i FROM 0 TO n-1:
        colors[i] = -1   

    DECLARE queue

    colors[0] = 0       
    queue.push(0)

    WHILE queue is not empty:
        u = queue.pop()
        neighborColor = 1 - colors[u]

        FOR each neighbor v in adjList[u]:

            IF colors[v] == -1:
                colors[v] = neighborColor
                queue.push(v)

            ELSE IF colors[v] == colors[u]:
                RETURN false   

    RETURN true

