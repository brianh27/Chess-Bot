
import math
import copy
def eval(board, game):
  points = [
      None,5,3,3.5,9,9999999,1
      
  ]
  adjust = [None,[
          -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0, 0, 0,
          0, -0.2, -0.4, -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, 0, 0.2,
          0.25, 0.25, 0.2, 0, -0.4, -0.4, 0, 0.2, 0.25, 0.25, 0.2, 0, -0.4,
          -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, -0.2, 0, 0, 0, 0, -0.2,
          -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5
      ],
      [
          -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0, 0, 0,
          0, -0.2, -0.4, -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, 0, 0.2,
          0.25, 0.25, 0.2, 0, -0.4, -0.4, 0, 0.2, 0.25, 0.25, 0.2, 0, -0.4,
          -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, -0.2, 0, 0, 0, 0, -0.2,
          -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5
      ],
      [
          -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0, 0, 0,
          0, -0.2, -0.4, -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, 0, 0.2,
          0.25, 0.25, 0.2, 0, -0.4, -0.4, 0, 0.2, 0.25, 0.25, 0.2, 0, -0.4,
          -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, -0.2, 0, 0, 0, 0, -0.2,
          -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5
      ],[
          -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0, 0, 0,
          0, -0.2, -0.4, -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, 0, 0.2,
          0.25, 0.25, 0.2, 0, -0.4, -0.4, 0, 0.2, 0.25, 0.25, 0.2, 0, -0.4,
          -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, -0.2, 0, 0, 0, 0, -0.2,
          -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5
      ],
      [
          -0.3, -0.4, -0.4, -0.5, -0.5, -0.4, -0.4, -0.3, -0.3, -0.4, -0.4,
          -0.5, -0.5, -0.4, -0.4, -0.3, -0.3, -0.4, -0.4, -0.5, -0.5, -0.4,
          -0.4, -0.3, -0.3, -0.4, -0.4, -0.5, -0.5, -0.4, -0.4, -0.3, -0.3,
          -0.4, -0.4, -0.5, -0.5, -0.4, -0.4, -0.3, -0.2, -0.2, -0.2, -0.2,
          -0.2, -0.2, -0.2, -0.2, 0.2, 0.2, 0, 0, 0, 0, 0.2, 0.2, 0.2, 0.3,
          0.1, 0, 0, 0.1, 0.3, 0.2
      ]
    , [
          -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5, -0.4, -0.2, 0, 0, 0,
          0, -0.2, -0.4, -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, 0, 0.2,
          0.25, 0.25, 0.2, 0, -0.4, -0.4, 0, 0.2, 0.25, 0.25, 0.2, 0, -0.4,
          -0.4, 0, 0.1, 0.2, 0.2, 0.1, 0, -0.4, -0.4, -0.2, 0, 0, 0, 0, -0.2,
          -0.4, -0.5, -0.4, -0.4, -0.4, -0.4, -0.4, -0.4, -0.5
      ]
  ]

  eval=0
  for a in range(8):
    for b in range(8):
        if board[a][b]==None:
           continue
        if board[a][b]<0==game:
           eval+=(points[board[a][b]]+adjust[board[a][b]])
        else:
           eval-=(points[board[a][b]]+adjust[board[a][b]][b*8+a])
           
  return eval
def s(a, b):
    if a==None:
        return False
    return (a > 0 and b > 0) or (a < 0 and b < 0)


def check(x,y,dx,dy,dist,board):
  moves=set()
  for a in range(1,dist+1):
    
    if y+dy*a>7 or y+dy*a<0 or x+dx*a>7 or x+dx*a<0:
       
       return moves
    elif s(board[x+dx*a][y+dy*a],board[x][y]):
       
       return moves
    else:
        moves.add((x,y,x+dx*a,y+dy*a))
        if board[x+dx*a][y+dy*a]==None:
       
            return moves
    
  return moves     
#positive next move

def moves(board, nex):
    
    
    
        
    possible = set()
    for a in range(8):
        for b in range(8):
            
            if board[a][b]==None:
                continue
            
            if (board[a][b]<0)==nex:
                
                t=abs(board[a][b])
                
                if t==1:
                    possible.update(check(a,b,0,1,99999999,board))
                    possible.update(check(a,b,1,0,99999999,board))
                    possible.update(check(a,b,-1,0,99999999,board))
                    possible.update(check(a,b,0,-1,99999999,board))
                elif t==3:
                    possible.update(check(a,b,1,1,99999999,board))
                    possible.update(check(a,b,-1,-1,99999999,board))
                    possible.update(check(a,b,1,-1,99999999,board))
                    possible.update(check(a,b,-1,1,99999999,board))
                elif t==4:
                    possible.update(check(a,b,1,1,99999999,board))
                    possible.update(check(a,b,-1,-1,99999999,board))
                    possible.update(check(a,b,1,-1,99999999,board))
                    possible.update(check(a,b,-1,1,99999999,board))
                    possible.update(check(a,b,0,1,99999999,board))
                    possible.update(check(a,b,1,0,99999999,board))
                    possible.update(check(a,b,-1,0,99999999,board))
                    possible.update(check(a,b,0,-1,99999999,board))
                elif t==2:
                    possible.update(check(a,b,-2,-1,1,board))
                    possible.update(check(a,b,-2,1,1,board))
                    possible.update(check(a,b,2,1,1,board))
                    possible.update(check(a,b,2,-1,1,board))
                    possible.update(check(a,b,1,-2,1,board))
                    possible.update(check(a,b,-1,-2,1,board))
                    possible.update(check(a,b,-1,2,1,board))
                    possible.update(check(a,b,1,2,1,board))
                elif t==5:
                    possible.update(check(a,b,1,1,1,board))
                    possible.update(check(a,b,-1,-1,1,board))
                    possible.update(check(a,b,1,-1,1,board))
                    possible.update(check(a,b,-1,1,1,board))
                    possible.update(check(a,b,0,1,1,board))
                    possible.update(check(a,b,1,0,1,board))
                    possible.update(check(a,b,-1,0,1,board))
                    possible.update(check(a,b,0,-1,1,board))
                elif t==6:
                    if nex:
                        if a==6:
                            possible.update(check(a,b,-1,0,2,board))
                        else:
                            possible.update(check(a,b,-1,0,1,board))
                    else:
                        if a==1:
                            possible.update(check(a,b,-1,0,2,board))
                        else:
                            possible.update(check(a,b,-1,0,1,board))
    return possible
            
games=[[[
        [1, None, 3, 4, 5, 3, 2, 1],
        [6, 6, 6, None, 6, 6, 6, 6],
        [None, None, 2, None, None, None, None, None],
        [None, None, None, 6, None, None, None, None],
        [None, None, None, None, None, None, None, None],
        [None, None, -2, None, -6, None, None, None],
        [-6, -6, -6, -6, None, -6, -6, -6],
        [-1, None, -3, -4, -5, -3, -2, -1]
    ],[]]]

for turn in range(4):
    print(turn)
    l=[]
    for b in games:
        
        t=moves(b[0],turn%2==0)
        
        for a in t:
            temp=copy.deepcopy(b)
            
            #swaparoo
            piece=temp[0][a[0]][a[1]]
            temp[0][a[0]][a[1]]=None
            temp[0][a[2]][a[3]]=piece
            temp[1].append(a)            
            l.append(temp)
    
    games=l.copy()
ans=-1
seen=-999999999999
for a in l:
    t=eval(a[0],True)
    if t>seen:
        ans=a[1][0]
        seen=t
print(ans)

