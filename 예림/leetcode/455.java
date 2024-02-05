class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int i = 0;
        int j = 0;
        int answer = 0;

        Arrays.sort(g);
        Arrays.sort(s);

        while(i < g.length && j < s.length) {
            if(s[j] >= g[i]) {
                answer++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return answer;
    }
}