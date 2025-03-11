
from Chess import moves

games=[[[
        [1, 2, 3, 4, 5, 3, 2, 1],
        [6, 6, 6, 6, 6, 6, 6, 6],
        [None, None, None, None, None, None, None, None],
        [None, None, None, None, None, None, None, None],
        [None, None, None, None, None, None, None, None],
        [None, None, None, None, None, None, None, None],
        [-6, -6, -6, -6, -6, -6, -6, -6],
        [-1, -2, -3, -4, -5, -3, -2, -1]
    ],[]]]

for _ in range(3):
    l=[]
    for board in games:
        for a in moves(board[0],[]):
            temp=board.copy()
            #swaparoo
            piece=temp[0][a[0]][a[1]]
            temp[0][a[0]][a[1]]=None
            temp[0][a[2]][a[3]]=piece
            temp[1].append(a)            
            l.append(temp)
    games=l.copy()
print(l)



