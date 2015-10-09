Clearly, if we simply test all possible 3-tuples, we'd solve the problem in O(n3)
-- that's the brute-force baseline.


STEP: 1   First, we invest some time to sort the array,

which costs us an initial penalty of O(n log n). Now we execute this algorithm:

STEP: 2

for (i in 1..n-2) {
    j = i+1  // Start right after i.
    k = n    // Start at the end of the array.
    
    while (k >= j) {
        // We got a match! All done.
        if (A[i] + A[j] + A[k] == 0) return (A[i], A[j], A[k])
            
            // We didn't match. Let's try to get a little closer:
            //   If the sum was too big, decrement k.
            //   If the sum was too small, increment j.
            (A[i] + A[j] + A[k] > 0) ? k-- : j++
    }
    // When the while-loop finishes, j and k have passed each other and there's
    // no more useful combinations that we can try with this i.
}
This algorithm works by placing three pointers, i, j, and k at various points in the array.
i starts off at the beginning and slowly works its way to the end. k points to the very last element.
j points to where i has started at.

We iteratively try to sum the elements at their respective indices, and each time one of the following happens:
    
The sum is exactly right! We've found the answer.
The sum was too small. Move j closer to the end to select the next biggest number.
The sum was too big. Move k closer to the beginning to select the next smallest number.
For each i, the pointers of j and k will gradually get closer to each other.
Eventually they will pass each other, and at that point we don't need to try anything else for that i,
since we'd be summing the same elements, just in a different order. After that point, we try the next i and repeat.
    
Eventually, we'll either exhaust the useful possibilities, or we'll find the solution.
You can see that this is O(n2) since we execute the outer loop O(n) times and we execute the inner loop O(n) times.
It's possible to do this sub-quadratically if you get really fancy, by representing each integer
as a bit vector and performing a fast Fourier transform, but that's beyond the scope of this answer.