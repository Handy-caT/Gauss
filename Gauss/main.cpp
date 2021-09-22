//
//  main.cpp
//  Gauss
//
//  Created by Максим on 19.09.2021.
//  Copyright © 2021 Максим. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void RandomSet() {
    srand(static_cast<unsigned int>(time(0)));
}

int Random(int min, int max) {
    return rand() % (max- min + 1) + min;
}

double** CopyMatrix(double** Matrix, int rows, int cols) {
    
    int i = 0;
    int j = 0;
    
    double** result = new double*[cols];
    
    while( i < cols ) {
        
        result[i] =  new double[rows];
        j = 0;
        
        while(j < rows) {
            
            result[i][j] = Matrix[i][j];
            j++;
            
        }
        
        i++;
    }
    
    return result;
    
}

double** MatrixMake(int rows, int cols) {
    
    int i = 0;
    int j = 0;
    
    double** result = new double*[cols];
    
    while( i < cols ) {
        
        result[i] =  new double[rows];
        j = 0;
        
        while(j < rows) {
            
            result[i][j] = 0;
            j++;
            
        }
        
        i++;
    }
    
    return result;
}

double** RandomMatrix(int rows, int cols) {
    
    int i = 0;
    int j = 0;
    
    double** result = new double*[cols]; //RESULT i/j
    
    while( i < cols) {
        
        result[i] = new double[rows];
        j = 0;
        
        while( j < rows) {
            
            result[i][j] = (double) Random(-100, 100);
            j++;
        }
        
        i++;
    }
    
    return result;
}

void MatrixShow(double** matrix, int rows, int cols) {
    
    int i = 0;
    int j = 0;
    
    while( i < rows ) {
        
        j = 0;
        while( j < cols) {
            std::cout << matrix[i][j] << " ";
            j++;
        }
        
        std::cout << "\n";
        i++;
    }
    
}

double** MatrixMultiply(double** left, double** right, int row1, int p, int col2) {
    
    //LEFT row1/p
    //RIGHT p/col2
    int i = 0;
    int j = 0;
    int k = 0;
    
    double** result = new double*[row1]; //RESULT i/j
    
    while( i < row1) {
        
        result[i] = new double[col2];
        j = 0;
        
        while( j < col2) {
            
            result[i][j] = 0;
            k = 0;
            
            while (k < p) {
                
                result[i][j] += left[i][k] * right[k][j];
                k++;
            }
            
            j++;
        }
        
        i++;
    }
    
    return result;
    
}

double** RowDivide(double** A, int row, int cols, int firstCol, double number) {
    
    int i = firstCol;
    while( i < cols ) {
        A[row][i] = A[row][i]/number;
        //std::cout << A[row][i] << " " << A[row][i]/number << "\n";
        i++;
    }
    
    return A;
}

double** ZeroCol(double** A, int col, int rows) {
    
    int i = 0;
    while( i < rows ) {
        A[i][col] = (double) 0;
        i++;
    }
    
    return A;
}

double** StraightGauss(double** userA, int rows, int cols, double** userf, int fCols) {
    
    int i = 0;
    int j = 0;
    
    double leading;
    
    double** X = MatrixMake(rows, fCols);
    double** A = CopyMatrix(userA, rows, cols);
    double** f = CopyMatrix(userf, rows, fCols);
    
    MatrixShow(A, 3, 3);
    
    while( i < rows - 1 ) {
        
        leading = A[i][i];
        
        ZeroCol(A, i, rows);
        MatrixShow(A, 3, 3);
        RowDivide(A, i, cols, i+1, leading);
        MatrixShow(A, 3, 3);
        RowDivide(f, i, fCols, i, leading);
        
        A[i][i] = 1;
        
        i++;
    }
    
    leading = A[i][i];
    RowDivide(f, i, fCols, i, leading);
    A[i][i] = 1;
    
    return A;
}

int main(int argc, const char * argv[]) {
    
    /*
    double** a;
    
    a = new double*[2];
    a[0] = new double[2];
    a[1] = new double[2];
    
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 2;
    a[1][1] = 3;
    
    MatrixShow(a, 2, 2);
    
    double** a;
    double** b;
    double** c;
    
    RandomSet();
    a = RandomMatrix(3, 3);
    b = RandomMatrix(3, 3);
    
    MatrixShow(a, 3, 3);
    MatrixShow(b, 3, 3);
    
    c = MatrixMultiply(a, b, 3, 3, 3);
    
    MatrixShow(c, 3, 3);*/
    
    double** a;
    double** b;
    double** c;
    
    RandomSet();
    a = RandomMatrix(3, 3);
    b = RandomMatrix(3, 1);
    
    c = StraightGauss(a, 3, 3, b, 1);
    
    MatrixShow(c, 3, 3);
    
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
