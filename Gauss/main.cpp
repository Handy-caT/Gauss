//
//  main.cpp
//  Gauss
//
//  Created by Максим on 19.09.2021.
//  Copyright © 2021 Максим. All rights reserved.
//

#include <iostream>

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
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
