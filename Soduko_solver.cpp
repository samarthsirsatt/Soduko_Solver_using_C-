#include<iostream>
#include <bits/stdc++.h> 

bool isSafe(int row, int col, vector<vector<int>>& board, int val){
    int n = board[0].size();
    for(int i = 0; i < n; i++){
        //check row
        if(board[row][i] == val){
            return false;
        }
        //check col
        if(board[i][col] == val){
            return false;
        }
        //for(3*3) matrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board){

    int n = board[0].size();
    //traverse the matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0){
                for(int val = 1; val <= 9; val++){
                    if(isSafe(i, j, board, val)){
                        board[i][j] = val;

                        //recursive call
                        bool frontSolPossible = solve(board);
                        if(frontSolPossible){
                            return true;
                        }
                        else{
                            //backtracking
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }

        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}s