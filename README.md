## Comparison-of-AVL-and-Binary-Tree

### Introduction
In this project BST and AVL tree are implemented and the research on insertion and searching in binary search measured, the time taken will compared and depicted in the graphs.

### Methodology
Programming language which was used is C++. The binary search tree and AVL tree were implemented using templates to handle insertion of strings. The measurements were done on three datasets: random data, ordered data and nearly ordered data (the half of the array will be sorted). The algorithms were used for vectors with the size from 0 up to 200000 with the step 5000. Each array size was tested 100 times. The part of the book was used as the source of the words to be extracted and inserted into the vector (it was more than 300000 words).


### Images
![](/Graphs/Find_operation.jpg "")

![](/Graphs/Insertion_Random.jpg "")

![](/Graphs/Insertion_sorted.jpg "")


### Conclusion
Conclusion, in general both AVL and BST performed best for the unsorted data inserted, while the sorted and nearly sorted arrays appeared to be the worst case for the BST.
