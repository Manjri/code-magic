/**
Let us consider the array int A[] = {2, -1, 4, 3, 5, -1, 3, 2}
1) Construct an auxiliary array inc[] from left to right such that inc[i] 
 contains longest length of the nondecreaing subarray ending at arr[i].

 For above A[] it is:
 
 int inc[] = {1,1,2,2,3,1,2,2}

2) Construct another array dec[] from right to left such that dec[i] 
 contains longest length of nonincreasing subarray starting at arr[i].

 For above A[] it is:
 
 int dec[] = {2,1,3,2,3,1,2,1}

3) Once we have the inc[] and dec[] arrays, all we need to do is find the maximum value of (inc[i] + dec[i] – 1).

 so max from:
 
 int addition[] = {2, 1, 4, 3, 5, 1, 3, 2}

 max is: 5 its position gives where the ditonic peaks at
 
*/