♞ Knight Moves (BFS on a 2D Grid) — Shortest Path for a Knight
🔍 Problem Description

The objective of the Knight Moves problem is to compute the minimum number of moves a knight requires to travel from square A to square B on a standard 8×8 chessboard.

This can be modeled as a shortest path problem on an unweighted graph, where:

Concept	Meaning
Nodes	All 64 squares of the chessboard
Edges	A legal knight move between two squares
Cost	Each move has equal cost (1 step)

Given that all edges have uniform weight, the most suitable algorithm for computing the shortest path is Breadth-First Search (BFS).

🧠 Why Use BFS?

Breadth-First Search (BFS) explores graph layers level-by-level, using a queue.
Because BFS always explores all nodes at distance k before nodes at distance k + 1, it guarantees the shortest path in any unweighted graph.

For the knight problem:

Level 0: Start square

Level 1: All reachable squares in 1 move

Level 2: All reachable squares in 2 moves

… and so on

The moment the destination square is first reached, we have found the minimum number of knight moves.

🎲 Representing the Board and Knight's Movement

Before applying BFS, we define how a knight moves on a chessboard.

♘ Knight’s 8 Possible Moves

From any position (r, c), a knight can move to up to eight valid squares:

(r-2, c+1), (r-2, c-1)
(r-1, c+2), (r-1, c-2)
(r+1, c+2), (r+1, c-2)
(r+2, c+1), (r+2, c-1)

Code Representation
int dr[8] = { 2,  2, -2, -2,  1,  1, -1, -1 };
int dc[8] = { 1, -1,  1, -1,  2, -2,  2, -2 };


Looping from 0 to 7,
newR = r + dr[i]
newC = c + dc[i]
computes all possible moves from (r, c).

🧩 Required Data Structures
Name	Purpose
| Name                     | Purpose                             |
| ------------------------ | ----------------------------------- |
| **dist[8][8]**           | Stores minimum moves to each square |
| **state[8][8]**          | Tracks visitation status            |
| **queue<pair<int,int>>** | BFS frontier                        |

State Values
| Value | Meaning               |
| ----- | --------------------- |
| `-1`  | Unvisited             |
| `1`   | In queue (discovered) |
| `2`   | Processed             |

📘 Pseudocode
FUNCTION KnightShortestPath(startR, startC, endR, endC):

    N = 8
    DECLARE dist[N][N]
    DECLARE state[N][N]
    DECLARE queue Q

    FOR r FROM 0 TO N-1:
        FOR c FROM 0 TO N-1:
            dist[r][c] = +∞
            state[r][c] = -1

    dist[startR][startC] = 0
    state[startR][startC] = 1
    ENQUEUE (startR, startC)

    WHILE Q is not empty:
        (r, c) = DEQUEUE()

        IF (r == endR AND c == endC):
            RETURN dist[r][c]

        FOR i FROM 0 TO 7:
            newR = r + dr[i]
            newC = c + dc[i]

            IF newR,newC is inside board AND state[newR][newC] == -1:
                state[newR][newC] = 1
                dist[newR][newC] = dist[r][c] + 1
                ENQUEUE (newR, newC)

        state[r][c] = 2

    RETURN -1

