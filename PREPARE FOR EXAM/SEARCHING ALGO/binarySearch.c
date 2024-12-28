
// Binary search is an efficient algorithm for finding an element in a sorted array. It works by repeatedly dividing the search interval in half.

// How Binary Search Works:
// Start with the entire array.
// Find the middle element:
// If the middle element is the target, the search is complete.
// If the target is smaller than the middle element, narrow the search to the left half.
// If the target is larger than the middle element, narrow the search to the right half.
// Repeat the process until the target is found or the search interval becomes empty.
// Requirements:
// The array must be sorted.

// Key Points:
// Time Complexity: O(logn), where n is the size of the array. It eliminates half of the remaining elements at each step.
// Space Complexity: O(1) for iterative implementation (no extra space needed). And O(logn) if we use recusion.
// Use Case: Works well for searching in large, sorted datasets.
// Comparison with Linear Search: written on notes.

// Feature	        |   Linear Search	        |     Binary Search
// Array Requirement|	Unsorted or sorted	    |    Must be sorted
// Time Complexity  |   O(n)	                |    O(logn)
// Speed	        |   Slower for large arrays	|    Faster for large arrays