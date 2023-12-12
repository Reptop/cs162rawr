## Greeting for TA 
Greetings, Sam Rynerson; I hope we meet again... 

## Name and ONID

Name: Raed Kabir
ONID: 934-455-007

-----------USED 1 GRACE DAY------------

## Description:

This program demonstrates the functionality of a linked list, which is a fundamental data structure used for storing and managing data. The focus of this program is on a linked list capable of storing integers. This program allows users a variety of operations to manipulate the list,catering to different needs for data management. Some key features of this linked list include: dynamic storage of integers, adding elements, deleting elements, clearing all elements, and sorting elements in ascending and descending order. This program utilizes mergesort, a sorting algorithm to handle its sorting functionality in ascending order. For descending order, this program utilizes selection sort, a different sorting algorithm. This program is mainly meant for educational purposes; if new to programming, this serves as an introduction in how computers can arrange data--like a list of integers--efficiently.

## Compilation Instructions

To compile the program, you will need to be in the same directory as the source code. Follow these steps:

1. Navigate to the directory containing the source code. This could be the `linked_list` folder or the `recursion` folder.

2. Once you are in the correct directory, type the following command in your terminal: make

## Limitations:

This program cannot handle user input; the user must modify the source code if they aim to change specific values stored into the 
linked list. A linked list also cannot store other data types other than integer. Overall, this program is merely for educational 
purposes an cannot perform actions that go outside the scope of demonstrating basic functionality for a linked list.

## Extra Credit:

The extra credit included within this assignment is implementing the sort_descending() function through a recursive selection sort 
algorithm. This was painfully difficult for me because I had to swap the node's next pointers, not the values stored in each node.

## Complexity Analysis 

For merge sort:
  Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge operation is the key process that assumes that the two halves are sorted and merges them into a single 
sorted array.

  The overall time complexity of Merge Sort is O(nlog(n)). This is because the algorithm splits the array into halves log(n) 
times (dividing the array), and for each split, it takes O(n) time to merge the arrays. Hence, this is linearithmic time complexity.

For selection sort:
  Recursive Selection Sort is a sorting algorithm that works by recursively selecting the smallest (or largest, depending on the order of sorting) element from the unsorted part of the array and moving it to the beginning (or end). This process continues until the entire array is sorted.

The overall time complexity of Recursive Selection Sort is O(n^2) This is due to the arithmetic series sum, indicating that the number of operations increases quadratically (hence n^2) with the size of the input array. Iterating, swapping, repeating, and continuing this sorting process yields
O(n^2). 









