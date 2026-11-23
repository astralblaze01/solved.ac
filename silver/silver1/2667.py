def init_list(size : int) -> list:
    # 입력
    arr = []
    # 배열 입력
    for _ in range(size):
        line = input()
        element = [int(line[i]) for i in range(size)]
        arr.append(element)
        
    return arr


def init_mark(size : int) -> list:
    zero = 0        
    arr = [[zero for _ in range(size)] for _ in range(size)]
    
    return arr


def prevent_illegal_move(row, col, size):
    if(row < 0):
        row = row + 1
        
    elif(row >= size):
        row = row - 1
    
    elif(col < 0):
        col = col + 1
        
    elif(col >= size):
        col = col - 1
    
    return row, col

        
def move(size, row, col, where):
    
    UP = 0
    RIGHT = 1
    DOWN = 2
    LEFT = 3
    
    # 위쪽 이동
    if(where == UP):
        col = col - 1
        
    # 오른쪽 이동
    elif(where == RIGHT):
        row = row + 1
        
    # 아래 이동
    elif(where == DOWN):
        col = col + 1
    
    # 왼쪽 이동
    elif(where == LEFT):
        row = row - 1

    row, col = prevent_illegal_move(row, col, size)
    
    return row, col


def find_group(row, col, size, square, mark):
    # mark가 0이고 square이 1일때 수행조건이기 때문에 미리 넣어줌
    queue = []
    group_size = 1
    mark[col][row] = 1
    
    index = {"col" : col, "row" : row}
    queue.append(index)
    
    while(len(queue) != 0):
        temp_index = queue.pop(0)
        
        temp_col = temp_index["col"]
        temp_row = temp_index["row"]
                
        # 이동
        for mov in range(4):
           mov_row, mov_col = move(size, temp_row, temp_col, mov)
           
           if(mark[mov_col][mov_row] == 0 and square[mov_col][mov_row] == 1):
                mov_index = {"col" : mov_col, "row" : mov_row}
                queue.append(mov_index)
                
                mark[mov_col][mov_row] = 1
                group_size = group_size + 1
    
    return group_size


def explor(size, square, mark):
    
    group_village = []
    
    # i = col j = row
    for i in range(size):
        for j in range(size):
            
            if(mark[i][j] == 0 and square[i][j] == 1):
                # 1일때만 group 찾기
                group_size = find_group(j, i, size, square, mark)
                group_village.append(group_size)
            
            
    return group_village
    
    
def main():
    
    size = int(input())
    square = init_list(size)
    mark = init_mark(size)
    
    group_village = explor(size, square, mark)
       
    group_village.sort()
    print(len(group_village))
    for group_num in group_village:
        print(group_num)
    
    '''
    # =====================================
    # 디버깅
    print("square")
    for i in range(size):
        print(square[i])
    
    print("mark")
    for i in range(size):
        print(mark[i])
        
    # 같게 나오는지 확인
    print(mark == square)
    #======================================
    '''
    
if __name__ == "__main__":
    main()