def format_matrix(matrix):
    for posX in range(4):
        print "%-2c %-2c %-2c %-2c" % (matrix[posX][0], matrix[posX][1], matrix[posX][2], matrix[posX][3])

def reflect_over_y_axis(matrix):
    for posX in range(4):
        # Switch outer
        tmp = matrix[posX][0]
        matrix[posX][0] = matrix[posX][3]
        matrix[posX][3] = tmp

        # Switch inner
        tmp = matrix[posX][1]
        matrix[posX][1] = matrix[posX][2]
        matrix[posX][2] = tmp

def reflect_over_right_diagonal(matrix):
    for posX in range(4):
        for posY in range(4):
            if posX == 0 and posY == 0:
                tmp = matrix[3][3]
                matrix[3][3] = matrix[posX][posY]
                matrix[posX][posY] = tmp
            elif posX == 1 and posY == 0:
                tmp = matrix[3][2]
                matrix[3][2] = matrix[posX][posY]
                matrix[posX][posY] = tmp
            elif posX == 2 and posY == 0:
                tmp = matrix[3][1]
                matrix[3][1] = matrix[posX][posY]
                matrix[posX][posY] = tmp
            elif posX == 0 and posY == 1:
                tmp = matrix[2][3]
                matrix[2][3] = matrix[posX][posY]
                matrix[posX][posY] = tmp
            elif posX == 1 and posY == 1:
                tmp = matrix[2][2]
                matrix[2][2] = matrix[posX][posY]
                matrix[posX][posY] = tmp
            elif posX == 0 and posY == 2:
                tmp = matrix[1][3]
                matrix[1][3] = matrix[posX][posY]
                matrix[posX][posY] = tmp

if __name__ == "__main__":
    # Initialize 4x4 matrix
    matrix = [[0]*4 for i in range(4)]
    
    letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P']
    currIndex = 0

    for posX in range(4):
        for posY in range(4):
            matrix[posX][posY] = letters[currIndex]
            currIndex += 1

    print "Original:"
    format_matrix(matrix)

    reflect_over_y_axis(matrix)
    print "Reflected over y axis:"
    format_matrix(matrix)
    
    reflect_over_right_diagonal(matrix)
    print "Reflected over right diagonal:"
    format_matrix(matrix)

