public class Solution {
    public int minArea(char[][] image, int x, int y) {
        int ranges[] = {image.length - 1, 0, image[0].length - 1, 0};
        dfs(image, x, y, ranges);
        return (ranges[1] - ranges[0] + 1) * (ranges[3] - ranges[2] + 1);
    }
    private void dfs(char[][] image, int x, int y, int[] ranges) {
        if(x < 0 || y < 0 || x >= image.length || y >= image[0].length || image[x][y] == '0') {
            return;
        }
        image[x][y] = '0';
        ranges[0] = Math.min(ranges[0], x);
        ranges[1] = Math.max(ranges[1], x);
        ranges[2] = Math.min(ranges[2], y);
        ranges[3] = Math.max(ranges[3], y);
        dfs(image, x - 1, y, ranges);
        dfs(image, x + 1, y, ranges);
        dfs(image, x, y - 1, ranges);
        dfs(image, x, y + 1, ranges);
    }
}
