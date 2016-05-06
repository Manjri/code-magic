//
//  2D_Pointers.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//
//http://www.ibiblio.org/pub/languages/fortran/append-c.html

#include "2D_Pointers.h"

#define N 3

// No Tricks! Just specify 2nd dimension, leave first blank
void print_2d_matrix1(int arr[][N]){
    
    for(int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
}

// column specified - pointer to an array of ints
void print_2d_matrix2(int (*arr)[3]){
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
}

// single pointer - flattened!
void print_2d_matrix3(int *arr, int m, int n){
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", *(arr + (n*i) + j));
        }
        printf("\n");
    }
}

// double pointer
void print_2d_matrix4(int **arr, int m, int n){
    
    // use an auxilary array of pointers
    int *index[3];
    
    for(int i=0; i<3; i++)
        index[i] = (int*)arr + i*3;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", index[i][j]);
        }
        printf("\n");
    }
}

void test_2d_arrays() {
    
    int arr[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    
    print_2d_matrix1(arr);
    //print_2d_matrix2(arr);
    //print_2d_matrix3((int*)arr, 3, 3);
    //print_2d_matrix4((int**)arr, 3, 3);
    
}