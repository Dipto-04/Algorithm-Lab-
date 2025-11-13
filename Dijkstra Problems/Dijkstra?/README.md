🧭 Dijkstra — Shortest Path in a Weighted Graph

🔍 Problem Overview

The goal of this problem is to determine the minimum-cost (shortest) path from vertex 1 to vertex n in a weighted undirected graph.

In other words, we want to find —
👉 “The path from vertex 1 to vertex n that requires the least total edge weight, and identify the sequence of vertices along this path.”

📥 Input Description

The input format is as follows:


n m a1 b1 w1 a2 b2 w2 ... am bm wm


| Symbol   | Meaning                                |
| :------- | :------------------------------------- |
| **n**    | Total number of vertices (2 ≤ n ≤ 10⁵) |
| **m**    | Total number of edges (0 ≤ m ≤ 10⁵)    |
| **a, b** | Two vertices connected by an edge      |
| **w**    | Weight of the edge (1 ≤ w ≤ 10⁶)       |


The graph may contain multiple edges and self-loops.


📤 Output Description

If no path exists from vertex 1 to vertex n, print -1.

Otherwise, print the shortest path (the sequence of vertices in order).

🧠 Nature of the Problem

This is a Single Source Shortest Path (SSSP) problem, where all edge weights are positive.

If all weights were equal (e.g., = 1), it could be solved using BFS.

Since the weights vary (from 1 to 10⁶), the most efficient approach is Dijkstra’s Algorithm.

⚙️ Dijkstra’s Algorithm (Concept)

Dijkstra’s Algorithm is based on a Greedy approach.

Start from the source node (vertex 1).

Repeatedly choose the vertex with the smallest known distance.

Update (relax) all its neighbors if a shorter distance is found.

Continue until the destination vertex (n) is reached or all vertices are processed.

🧩 Graph Representation (Adjacency List)

Each vertex maintains a list of its neighbors along with corresponding edge weights:

1 → (2, 2), (4, 1)
2 → (1, 2), (3, 4), (5, 5)
4 → (1, 1), (3, 3)
3 → (2, 4), (4, 3), (5, 1)
5 → (2, 5), (3, 1)

🧮 Variables Used

| Variable    | Description                                                                         |
| :---------- | :---------------------------------------------------------------------------------- |
| **dist[i]** | Minimum distance from vertex 1 to vertex i                                          |
| **orig[i]** | Parent vertex of i (used for path reconstruction)                                   |
| **pq**      | Min-heap (priority queue) that always returns the vertex with the smallest distance |
| **INF**     | A large value representing infinity (e.g., 1e18)                                    |

💡 Pseudocode
FUNCTION Dijkstra(n, m, edges):
    Initialize graph as adjacency list
    For each edge (a, b, w):
        Add (b, w) to graph[a]
        Add (a, w) to graph[b]
    
    For i = 1 to n:
        dist[i] = INF
        orig[i] = -1
    
    dist[1] = 0
    pq = priority_queue()
    pq.push((0, 1))  // (distance, vertex)

    WHILE pq is not empty:
        (d, u) = pq.top()
        pq.pop()
        IF d > dist[u]:
            CONTINUE
        FOR each (v, w) in graph[u]:
            IF dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                orig[v] = u
                pq.push((dist[v], v))

    IF dist[n] == INF:
        RETURN -1
    ELSE:
        BUILD path from n to 1 using orig[]
        REVERSE path
        PRINT path


🧩 Example Input

5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1


🧱 Step-by-Step Visualization

| Step | Current Node | Neighbors (v, w)    | Relaxation           | Updated dist[ ] | PQ Content   |
| :--: | :----------: | :------------------ | :------------------- | :-------------- | :----------- |
| Init |       —      | —                   | —                    | [0, ∞, ∞, ∞, ∞] | (0,1)        |
|   1  |       1      | (2,2), (4,1)        | dist[2]=2, dist[4]=1 | [0,2,∞,1,∞]     | (1,4), (2,2) |
|   2  |       4      | (1,1), (3,3)        | dist[3]=4            | [0,2,4,1,∞]     | (2,2), (4,3) |
|   3  |       2      | (1,2), (5,5), (3,4) | dist[5]=7 (temp)     | [0,2,4,1,7]     | (4,3), (7,5) |
|   4  |       3      | (2,4), (4,3), (5,1) | dist[5]=5 (improved) | [0,2,4,1,5]     | (5,5)        |
|   5  |       5      | —                   | —                    | —               | —            |

🔄 Path Reconstruction


From the orig[] array, we trace back the path:

5 ← 3 ← 4 ← 1


Hence, the shortest path is:

1 → 4 → 3 → 5


✅ Output:

1 4 3 5


⏱️ Time and Space Complexity

| Complexity           | Explanation                                                                                             |
| :------------------- | :------------------------------------------------------------------------------------------------------ |
| **Time Complexity**  | O((n + m) log n) — each edge is relaxed at most once, and the priority queue operations take log n time |
| **Space Complexity** | O(n + m) — for storing adjacency lists, distance, and parent arrays                                     |

🧾 Summary

| Topic                   | Description                                                          |
| :---------------------- | :------------------------------------------------------------------- |
| **Problem**             | Find the shortest path from vertex 1 to vertex n in a weighted graph |
| **Algorithm**           | Dijkstra’s Algorithm                                                 |
| **Graph Type**          | Undirected, Weighted                                                 |
| **Negative Weights**    | Not supported                                                        |
| **Data Structure Used** | Min-Heap (Priority Queue)                                            |
| **Output**              | Shortest Path sequence or -1                                         |

