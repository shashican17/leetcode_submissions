class Solution:
    def checkRows(self, b: List[List[str]], i : int):
        vals = dict()
        for j in range(9):
            if b[i][j] != ".":
                if b[i][j] in vals:
                    return False
                else:
                    vals[b[i][j]] = 1

        return True

    def checkCols(self, b: List[List[str]], j : int):
        vals = dict()
        for i in range(9):
            if b[i][j] != ".":
                if b[i][j] in vals:
                    return False
                else:
                    vals[b[i][j]] = 1
        
        return True
    
    def checkGrid(self, b: List[List[str]], i, j):
        vals = dict()
        for k in range(i, i+3):
            for l in range(j, j+3):
                if b[k][l] != ".":
                    if b[k][l] in vals:
                        return False
                    else:
                        vals[b[k][l]] = 1
        
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            if not self.checkRows(board, i):
                return False
        
        for j in range(9):
            if not self.checkCols(board, j):
                return False

        i = 0
        while i < 9:
            j = 0
            while j < 9:
                if not self.checkGrid(board, i, j):
                    return False
                j += 3
            
            i += 3

        return True