size = 0
maze = []
while True:
    try:
        maze.append(int(raw_input()))
        size += 1
    except:
        break

step = 0
x = 0
while 0 <= x < size:
    t = maze[x]
    maze[x] += 1
    x += t
    step += 1
print step
