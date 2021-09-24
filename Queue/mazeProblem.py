# queue = ['']

# for _ in range(15):
#     x = queue.pop(0)
#     y = x + '0'
#     z = x + '1'

#     queue.append(y)
#     queue.append(z)
#     print(queue)

def drawMaze():
    maze = []

    maze.append(['O', ' ', ' ', 'S', 'O'])
    maze.append([' ', ' ', ' ', ' ', ' '])
    maze.append(['O', ' ', ' ', 'O', 'O'])
    maze.append([' ', 'O', ' ', ' ', 'O'])
    maze.append(['O', 'E', ' ', ' ', ' '])

    return maze

def printMaze(maze, path=''):
    for x, pos in enumerate(maze[0]):
      if pos == 'S':
        start = x 

    i = 0
    j = start
    tracer =[]

    for move in path:
        if move == 'L':
            j -= 1

        if move == 'R':
            j += 1 

        if move == 'U':
            i -= 1 

        if move == 'D':
            i += 1    

        tracer.append([i, j])
    
    for indx_row, row in enumerate(maze):
        for indx_col, column in enumerate(row):
            if [indx_row, indx_col] in tracer:
                print('* ', end='')
            else:
                print(column+' ', end='')    
        print()        

def isValid(maze, path):
    for x, pos in enumerate(maze[0]):
        if pos == 'S':
            start = x        

    i = 0
    j = start

    for move in path:
        if move == 'L':
            j -= 1

        if move == 'R':
            j += 1 

        if move == 'U':
            i -= 1 

        if move == 'D':
            i += 1    

        if not (0 <= j <len(maze[0]) and 0 <= i <len(maze)):
            return False
        
        elif (maze[i][j] == 'O'):
            return False

    return True

def findEnd(maze, path):
    for x, pos in enumerate(maze[0]):
        if pos == 'S':
            start = x        

    i = 0
    j = start

    for move in path:
        if move == 'L':
            j -= 1

        if move == 'R':
            j += 1 

        if move == 'U':
            i -= 1 

        if move == 'D':
            i += 1    

    if maze[i][j] == 'E':
        print('Found: ', path)  
        printMaze(maze, path)
        return True

    return False             



creatingPath = ['']
path = ''

maze = drawMaze()

while not findEnd(maze, path):
    path = creatingPath.pop(0)
    for i in ['L', 'R', 'U', 'D']:
        put = path+i
        if isValid(maze, put):
            creatingPath.append(put) 