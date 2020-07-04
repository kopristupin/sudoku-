
#include <iostream>
#include<vector>
#include<algorithm>


std::pair<int, int> getSquare(int x1, int y1) {
    std::pair<int, int> square;
    for (int r = 1; r <= 3; r++) {
        if (x1 + 1 <= r * 3) {
            for (int c = 1; c <= 3; c++) {            
                if (y1 + 1 <= c * 3) {
                        square.first = (r - 1) * 3; square.second = (c - 1) * 3;
                        return square;
                }  
            }                              
        }
    }
}

std::vector<int> constructCandidates(int rowC,int columnC, int a[9][9]) {
    std::vector<int> resultCand;
    int candidates[9] = { 1,2,3,4,5,6,7,8,9 };
    std::vector<int> notCand;

    for (int i = 0; i < 9; i++) {

        if (a[rowC][i] != 0) {
            notCand.push_back(a[rowC][i]);
        }
        if (a[i][columnC] != 0) {
            notCand.push_back(a[i][columnC]);
        }      
   } 

    std::pair<int, int> checkSq;
    checkSq = getSquare(rowC, columnC);

    int qX1 = checkSq.first; int qY1=checkSq.second;
   for (int i = 0; i < 3; i++) {
       for (int u = 0; u < 3; u++) {
           if (a[qX1 + i][qY1 + u] != 0) {            
               notCand.push_back(a[qX1 + i][qY1 + u]);
           }
       }
   }
   for (int u = 0; u < notCand.size(); u++)
       
     for (int i=0; i < 9; i++) {
         if (std::find(notCand.begin(), notCand.end(), candidates[i])== notCand.end()) {
             resultCand.push_back(candidates[i]);        
         }
        }
   sort(resultCand.begin(), resultCand.end());
resultCand.erase(unique(resultCand.begin(), resultCand.end()), resultCand.end());
    return resultCand;
}

void backtrack(int a[9][9], int start[9][9], int row, int column) {
    
        std::vector<int> candidatesForEach;
        if (start[row][column]==0) {
            if (start[row][column] == 0) {
                std::vector<int> res(constructCandidates(row, column, a));
                for (int y = 0; y < res.size(); y++) {
                    candidatesForEach.push_back(res[y]);
                }
            }
        }
        
        if (start[row][column] != 0)
           candidatesForEach.push_back(0);

        for (int i = 0; i < candidatesForEach.size(); i++) {
           
            if (start[row][column] == 0) {
                a[row][column] = candidatesForEach[i];
            }

            int b[9][9];
            for (int q = 0; q < 9; q++) 
                for (int y = 0; y < 9; y++)
                     b[q][y] = a[q][y];
           
            int rowCp;
            int columnCp;

           

            if (column == 8) {
                columnCp = 0; rowCp = row + 1;;
            }
            else {
                columnCp = column + 1;
                rowCp = row;
            } 
            

            if (row == 8 && column == 8) {
for (int q = 0; q < 9; q++) {
                for (int y = 0; y < 9; y++)
                    std::cout << a[q][y] << " ";
                std::cout << std::endl;
            }
return;
            }
            
        
            backtrack(b, start, rowCp, columnCp);
        }

}

int main()
{
    int data[9][9] = {
    { 0, 9, 4, 0, 0, 5, 0, 0, 0 },
    { 0, 8, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 2, 0, 8, 0, 1, 0, 0, 9 },
    { 9, 0, 7, 1, 8, 0, 0, 5, 0 },
    { 0, 1, 8, 0, 0, 0, 7, 9, 0 },
    { 0, 4, 0, 0, 9, 6, 8, 0, 1 },
    { 3, 0, 0, 2, 0, 7, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 4, 0 },
    { 0, 0, 0, 5, 0, 0, 9, 7, 0 } 
    };

    int a[9][9];
    for (int i = 0; i < 9; i++)
        for (int y = 0; y < 9; y++)
            a[i][y] = data[i][y];
    int row = 0; int column = 0; 
    std::cout << a[row][column] << std::endl;
    backtrack(a, data, row, column);

}

