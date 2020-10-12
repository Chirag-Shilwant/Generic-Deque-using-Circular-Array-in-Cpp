# Generic-Deque-using-Circular-Array-in-Cpp

## Task :
Implemented a Generic Deque. Deque is the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted,
with their storage being handled automatically by the container. They support Insertion and Deletion from both ends in Amortized constant time.

## Opeartions Implemented:
1. deque() - initalize a blank deque.
2. deque(n,x) - initalize a deque of length n with all values as x.
3. push_back(x) - append data x at the end.
4. pop_back() - erase data at the end.
5. push_front(x) - append data x at the beginning.
6. pop_front() - erase data at the beginning.
7. front() - returns the frst element(value) in the deque.
8. back() - returns the last element(value) in the deque.
9. empty() - returns true if deque is empty else returns false.
10. size() - returns the current size of deque.
11. resize(x, d) - changes the size dynamically.If resize increases size of the deque then all new elements must have d as it's values. If resize decrease size of the deque then
  just pop the elements from back until deque is resized to it's desired size.
12. clear() - remove all elements of deque.
13. D[n] - returns the nth element of the deque.
