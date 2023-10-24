def solution(rsp):
    answer = ''
    rsp_asset = ['2','0','5']
    for i in rsp:
        if i == '2':
            answer = answer+rsp_asset[1]
        elif i == '0':
            answer+=rsp_asset[2]
        else:
            answer+=rsp_asset[0]
    return answer