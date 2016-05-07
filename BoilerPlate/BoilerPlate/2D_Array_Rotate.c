//
//  2D_Array_Rotate.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/6/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "2D_Array_Rotate.h"

// single pointer - flattened!
void print_2d_matrix(int *arr, int m, int n){
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", *(arr + (n*i) + j));
        }
        printf("\n");
    }
}

int read_2D(int *arr, int n, int i, int j){
    
    return *(arr + i*n + j);
}

void write_2D(int *arr, int n, int val, int i, int j){
    *(arr + i*n + j) = val;
}

// 90 deg clockwise rotation
void rotate_90(int *arr, int n){
 
    for(int layer = 0; layer < n; layer++){
        
        int first = layer; int last = n-1-layer;
        
        for(int i=first; i<last; i++){
            
            int offset = i - first;
            
            int top = read_2D(arr, n, first, i);                                            // save top
            write_2D(arr, n, read_2D((int*)arr, n, last-offset, first), first, i);                // left to top
            write_2D(arr, n, read_2D((int*)arr, n, last, last-offset), last-offset, first);       // bottom to left
            write_2D(arr, n, read_2D((int*)arr, n, i, last), last, last-offset);                  // right to bottom
            write_2D(arr, n, top, i, last);                                                 // top to right
        } // for-elements-in-layer
    }   // for-layer-end
} // rotate_90

void test_rotate(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printf("Before Rotation\n");
    print_2d_matrix((int*)arr,3,3);
    rotate_90((int*)arr, 3);
    printf("Rotation by 90 deg clockwise\n");
    print_2d_matrix((int*)arr,3,3);
    printf("Rotation by 90 deg clockwise\n");
    rotate_90((int*)arr, 3);
    print_2d_matrix((int*)arr,3,3);
    printf("Rotation by 90 deg clockwise\n");
    rotate_90((int*)arr, 3);
    print_2d_matrix((int*)arr,3,3);
    printf("Rotation by 90 deg clockwise\n");
    rotate_90((int*)arr, 3);
    print_2d_matrix((int*)arr,3,3);
}




