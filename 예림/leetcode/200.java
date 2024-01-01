class Solution {
    int M, N;
    boolean[][] visited;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public boolean isOut(int x, int y) {
        return (x < 0 || x >= M || y < 0 || y >= N);
    }

    public void dfs(char[][] grid, int x, int y) {
        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!isOut(nx, ny) && grid[nx][ny] == '1' && !visited[nx][ny]) {
                dfs(grid, nx, ny);
            }
        }
    }

    public int numIslands(char[][] grid) {
        int answer = 0;

        M = grid.length;
        N = grid[0].length;

        visited = new boolean[M][N];

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j);
                    answer++;
                }
            }
        }

        return answer;
    }
}