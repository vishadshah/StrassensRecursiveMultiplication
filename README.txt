EE599
Lab2
Vishad Shah
9738981811

Matrix Multiplication

1. Run the EE599_Lab2_9738981811 file. This file should be in the same folder as where the output_p1_golden.txt and script.sh is present. 
2. void MultiplyMatrix function gives the naive multiplication result. Three nested loops have been used for multiplying NxN matrix.
3. int PowerOf2 function checks if n is a power of 2 and returns n which is closest power of 2
4. int ** AddMat function takes NxN matrix as an input and returns addition of the two matrix as a pointer to a pointer.
5. int ** SubstractMat function takes NxN matrix as an input and returns subtraction of the two matrix as a pointer to a pointer.
6. void AddMat1 function takes two pointers, NxN matrix and n(value of size) as an input and stores addition as a result in the NxN matrix passed as an input.
7. void SubstractMat1 function takes two pointers, NxN matrix and n(value of size) as an input and stores subtraction as a result in the NxN matrix passed as an input.
8. int **STMP (Strassens) function takes two pointers as an input, breaks the input matrix into four sub matrices having size of N/2xN/2. It then computes 7 matrices (M1 to M7) using recursive call and finally stores the result in C matrix by combining the 4 sub matrices formed (C11 to C22). If the input size of n is 2, it will take scalar values of the input matrices and compute C which stores the result of multiplication.
9. The time taken by NaiveMethod and Strassens is stored in output2.txt while the result of Naive is stored in output_p1_m1.txt and Strassens output is stored in output_p2_m2.txt
10. Naive method works for any value of N(size of input) while Strassens works for N<=128. The result for both the matrix is same when size of N=128 or less as Strassens does not work for N>128.
11. In the main function if A and B are not of type 2^nX2^n , it fill the missing rows and columns with zeros
12. Below attached is screenshot of output for NaiveMethod and Strassens giving same result as the multiplication result.

