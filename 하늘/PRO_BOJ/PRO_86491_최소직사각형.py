def solution(sizes):
    W,H=0,0
    for w,h in sizes: W,H=max(W,w,h),max(H,min(w,h))
    return W*H
