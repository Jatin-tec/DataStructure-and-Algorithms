def drawBoard():
    board = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
    return board

def isAttacked(board, m, n):
    queenPositions = []
   
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 'Q':
                queenPositions.append([i, j])

    for queenPosition in queenPositions:
        if (queenPosition[0]+queenPosition[1] == m+n or queenPosition[0]-queenPosition[1] == m-n):
            # print('digonal')
            return True
        elif (queenPosition[0]==m or queenPosition[1]==n):
            # print(queenPosition)
            # print('row_col')
            return True
    
    return False    

def placeQueen(board, qpos):
    if qpos>=4:
        return True
 
    for i in range(len(board)):      
        if not isAttacked(board, i, qpos):
            board[i][qpos] = 'Q'

            if(placeQueen(board, qpos+1)==True):
                return True
            
            board[i][qpos]=0     
    
    return False


if __name__ == '__main__':
    board = drawBoard()

    placeQueen(board, 0)

    for row in range(len(board)):
        for col in range(len(board)):
            print(board[row][col], end=' ')   
        print('\n')   

    print(isAttacked(board, 2, 3))     
