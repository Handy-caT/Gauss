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

double** RandomMatrix(int rows, int cols) {
    
    int i = 0;
    int j = 0;
    
    double** result = new double*[rows]; //RESULT i/j
    
    while( i < rows) {
        
        result[i] = new double[cols];
        j = 0;
        
        while( j < cols) {
            
            result[i][j] = Random(-100, 100);
            
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
                
                result[i][j] += left[row1][k] * right[k][col2];
                k++;
            }
            
            j++;
        }
        
        i++;
    }
    
    return result;
    
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
    
    MatrixShow(a, 2, 2);*/
    
    double** a;
    double** b;
    double** c;
    
    RandomSet();
    a = RandomMatrix(3, 3);
    b = RandomMatrix(3, 3);
    
    MatrixShow(a, 3, 3);
    MatrixShow(b, 3, 3);
    
    c = MatrixMultiply(a, b, 3, 3, 3);
    
    MatrixShow(c, 3, 3);
    
    
    
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
