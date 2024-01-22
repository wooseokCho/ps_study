public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> st = new HashSet<>();
        Set<Integer> ans = new HashSet<>();

        for (int num : nums1) {
            st.add(num);
        }

        for (int num : nums2) {
            if (st.contains(num)) {
                ans.add(num);
            }
        }

        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}