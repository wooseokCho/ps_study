class Solution(object):
    def trap(self, height: List[int])-> int:
        if not height:
            return 0
        l, r = 0, len(height)-1
        lmax, rmax = height[l], height[r]
        volume = 0
        while l<r:
            lmax, rmax = max(height[l], lmax), max(height[r], rmax)

            if lmax <= rmax:
                volume += lmax - height[l]
                l+=1
            else:
                volume+=rmax -height[r]
                r-=1