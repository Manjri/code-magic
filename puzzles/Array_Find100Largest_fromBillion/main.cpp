You can keep a (min heap)priority queue of the 100 biggest numbers, iterate through the billion numbers,
whenever you encounter a number greater than the smallest number in the queue (the head of the queue),
remove the head of the queue and add the new number to the queue.


- Fill the first 100 numbers in unsorted array
- Starting from 101st element, insert into MinHeap by comparing with head and replacing if it is greater then head
- At the end of the array, we would have maintained the top 100 items