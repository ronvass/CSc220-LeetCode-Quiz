class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        // Scan every cell in the grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // Only start a BFS if we find unvisited land
                if (grid[r][c] == '1') {
                    islands++;

                    /* BFS
                    Using 2 arrays as a manual queue, row and col stored separately */
                    int queueRow[90001]; // Max grid size is 300x300 = 90000
                    int queueCol[90001];
                    int front = 0;
                    int back  = 0;

                    // Enqueue the starting cell
                    queueRow[back] = r;
                    queueCol[back] = c;
                    back++;

                    // Marked visited right away so it doesn't get re-enqueued
                    grid[r][c] = '0';

                    /* BFS Loop
                    Keep going until every cell of this island is processed */
                    while (front < back) {

                        // Dequeue the front cell
                        int row = queueRow[front];
                        int col = queueCol[front];
                        front++;

                        // Check all 4 neighbors; up, down, left, right)

                        // Up
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            queueRow[back] = row - 1;
                            queueCol[back] = col;
                            back++;
                            grid[row-1][col] = '0'; // Mark visited
                        }

                        // Down
                        if (row + 1 < rows && grid[row+1][col] == '1') {
                            queueRow[back] = row + 1;
                            queueCol[back] = col;
                            back++;
                            grid[row+1][col] = '0';
                        }

                        // Left
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            queueRow[back] = row;
                            queueCol[back] = col - 1;
                            back++;
                            grid[row][col-1] = '0';
                        }

                        // Right
                        if (col + 1 < cols && grid[row][col+1] == '1') {
                            queueRow[back] = row;
                            queueCol[back] = col + 1;
                            back++;
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        // Each BFS we started corresponds to one island
        return islands;
    }
};