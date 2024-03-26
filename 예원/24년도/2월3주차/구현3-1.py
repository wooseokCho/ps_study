input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0]))-int(ord("a"))+1

horse_move = [(-2,-1), (-1,-2), (1,2), (2,1), (-2,1), (1, -2), (-1,2), (1,-2)]

result = 0
for move in horse_move:
    row_move = row + move[0]
    column_move = column +move[1]
    if row_move>=1 or column_move>=1 or row_move<=8 or column_move<=8:
        result+=1
print(result)