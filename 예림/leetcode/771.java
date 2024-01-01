class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> st = new HashSet<>();
        int answer = 0;

        for(char j : jewels.toCharArray()) {
            st.add(j);
        }

        for(char s : stones.toCharArray()) {
            if(st.contains(s)) {
                answer++;
            }
        }

        return answer;
    }
}