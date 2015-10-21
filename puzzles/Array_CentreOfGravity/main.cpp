/**

Array = [ 1   2   9   4   -1 ]
 
1. Calculate Partial/Running sum: PS[i] = PS[i-1]+A[i]
2. Calculate SumLeft: SumLeft[i] = PS[i-1]
3. Calculate SumRight: SumRight[i] = PS[n-1] - PS[i]
 
Original_Array  1   2   9   4   -1
Partial Sum     1   3   12  16  15
SumLeft         0   1   3   12  16
SumRight        14  12  3   -1  0


*/