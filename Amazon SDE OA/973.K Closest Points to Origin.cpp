/*
Calculating each distance first
The rest part of this problem equals to finding the K smallest elements.
  - Sorting O(nlogn)
  - Max Heap O(k+(n-k)logk)
  Constract a heap with only K element, and if the next element is smaller than the current largest number in the heap(heap.top()), then replace the largest number.
*/

