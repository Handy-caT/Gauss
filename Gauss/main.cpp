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

// A[строки][столбцы]

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
    
    while( i < rows ) {
        
        result[i] =  new double[rows];
        j = 0;
        
        while(j < cols) {
            
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
    
    while( i < rows ) {
        
        result[i] =  new double[rows];
        j = 0;
        
        while(j < cols) {
            
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
    
    while( i < rows) {
        
        result[i] = new double[rows];
        j = 0;
        
        while( j < cols) {
            
            result[i][j] = (double) Random(-100, 100); //наоборот тк заполнение по строкам
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

double** RowsResidual(double** A, int firstRow, int rows, int cols, double** f, int fCols) {
    
    int i = firstRow + 1;
    int j = 0;
    int k = 0;
    int number;
    
    while( i < rows) {
        
        j = firstRow + 1;
        k = 0;
        number = A[i][firstRow];
        
        while( j < cols || k < fCols) {
            
            if( j < cols ) {
                A[i][j] = A[i][j] - A[firstRow][j]*number;
                j++;
            }
            if( k < fCols ) {
                f[i][k] = f[i][k] - f[firstRow][k]*number;
                k++;
            }
            
            
        }
        //MatrixShow(A, 3, 3);
        //MatrixShow(f, 3, 1);
        i++;
    }
    
    return A;
}

double** ZeroCol(double** A, int col, int rows) {
    
    int i = col;
    while( i < rows ) {
        A[i][col] = (double) 0;
        i++;
    }
    
    return A;
}

double** ReverseSteps(double** userA, int rows, int cols, double** userf, int fCols) {
    
    int i = rows - 2;
    int j = 0;
    int k = 0;
    
    double** X = CopyMatrix(userf, rows, fCols);
    
    while( i >= 0) {
        j = cols - 1;
        k = rows - 1;
        while( j != i ){
            
            X[i][0] = X[i][0] - userA[i][j]*X[k][0];
            
            k--;
            j--;
        }
        
        i--;
    }
    
    return X;
}

double** RowsChange(double** A, int cols, int from, int to, double** f, int fCols) {
    
    int i = 0;
    
    while( i < cols || i < fCols) {
        
        if( i < cols ) std::swap(A[from][i],A[to][i]);
        if( i < fCols ) std::swap(A[from][i],A[to][i]);
        
        i++;
        
    }
    
    return A;
    
}

int MaxInCol(double** A, int col, int rows){
    
    int max = A[0][col];
    int imax = 0;
    int i = 0;
    
    while( i < rows) {
        
        if( A[i][col] > max) {
            max = A[i][col];
            imax = i;
        }
        
        i++;
    }
    
    return imax;
}

double** StraightGauss(double** userA, int rows, int cols, double** userf, int fCols) {
    
    int i = 0;
    
    double leading;
    
    double** X;
    double** A = CopyMatrix(userA, rows, cols);
    double** f = userf;
    
    while( i < rows - 1 ) {
        
        leading = A[i][i];
        
        RowDivide(A, i, cols, i+1, leading);
        //MatrixShow(A, 3, 3);
        RowDivide(f, i, fCols, 0, leading);
        //MatrixShow(f, 3, 1);
        RowsResidual(A, i, rows, cols, f, fCols);
        //MatrixShow(A, 3, 3);
        //MatrixShow(f, 3, 1);
        ZeroCol(A, i, rows);
        A[i][i] = 1;
        
        i++;
    }
    
    leading = A[i][i];
    RowDivide(f, i, fCols, 0, leading);
    A[i][i] = 1;
    
    //MatrixShow(A, 3, 3);
    //MatrixShow(f, 3, 1);
    
    X = ReverseSteps(A, rows, cols, f, fCols);
    
    return X;
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
    
    MatrixShow(a, 3, 3);
    MatrixShow(b, 3, 1);
    
    c = StraightGauss(a, 3, 3, b, 1);
    //c = RowsResidual(a, 0, 3, 3, b, 1);
    
    MatrixShow(c, 3, 1);
    //MatrixShow(b, 3, 1);
    
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
