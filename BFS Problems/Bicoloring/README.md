Bicoloring (BFS-Based) Problem Analysis
Problem Overview: Graph Bicoloring

The objective of the graph bicoloring problem is to determine whether a given graph can be colored using exactly two colors (e.g., White and Black) such that no two adjacent vertices share the same color. In formal terms, we must verify whether the graph is bipartite.

Core Concept: Bipartite Graph

A graph is considered bipartite if its vertices can be partitioned into two disjoint sets (Set A and Set B) such that every edge connects a vertex in Set A to a vertex in Set B. This equivalently means the graph can be colored with two colors without any adjacent vertices having identical colors.

When Is Bicoloring Not Possible?

A graph cannot be bicolored if and only if it contains an odd-length cycle.
Example: A triangle (cycle of length 3) is not bicolorable. Once two vertices are assigned opposite colors, the third vertex inevitably conflicts because it becomes adjacent to two vertices with different required colors.

Solution Strategy: Breadth-First Search (BFS)

BFS is an efficient method for checking whether the graph can be bicolored. During traversal, each vertex is assigned a color (0 or 1), and we verify that no adjacent vertices share the same color.

Algorithm Steps

Initialization: Mark all vertices as Uncolored (value = -1).

Start BFS: Assign color 0 to a starting vertex (e.g., vertex 0) and insert it into a queue.

Traverse:

Dequeue a vertex u.

Determine the opposite color (1 - color[u]).

For each neighbor v of u:

If v is uncolored, assign the opposite color and enqueue it.

If v already has the same color as u, a conflict is detected. This implies the presence of an odd cycle, and the graph is not bicolorable.

Completion:

If the BFS completes without conflicts, the graph is bicolorable.

Pseudocode

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

