judge=["1", "2", "3"]

def game_369():
    for number in range(1, 100):
        if judge[0] in str(number) or judge[1] in str(number) or judge[2] in str(number):
            claps = str(number).count(judge[0]) + str(number).count(judge[1]) + str(number).count(judge[2])
            print('박수' * claps)
        else:
            print(f'틀렸습니다. {number}를 말해야 합니다.')
            break
    else:
        print('성공했습니다.')
game_369()