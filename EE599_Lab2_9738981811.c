//
//  main.c
//  V
//
//  Created by Vishad Shah on 1/18/19.
//  Copyright Â© 2019 Vishad Nehal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int N=256;

// Checks if n is a power of 2 and returns n which is closest power of 2
int PowerOf2(int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

//Naive Multiplication Function
void MultiplyMatrix(int **mat1, int **mat2, int result[N][N])
{
    int i,j,k;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            result[i][j] = 0;
            for (k =0;k<N;k++)
                result[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
}


// Function to Add
int **AddMat(int matrix1[][N], int matrix2[][N],int n){
    int i, j;
    int **sum;
    sum = malloc(sizeof(int*) * n);
    
    for(i = 0; i < n; i++) {
        sum[i] = malloc(sizeof(int*) * n);
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return sum;
}


// Function to Substract
int **SubstractMat(int matrix1[][N], int matrix2[][N],int n){
    int i, j;
    int **sub;
    sub = malloc(sizeof(int*) * n);
    
    for(i = 0; i < n; i++) {
        sub[i] = malloc(sizeof(int*) * n);
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            sub[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return sub;
}



// Function to Add two pointers and return 2D array
void AddMat1(int **A, int **B, int C[N][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to substract two pointers and return 2D array
void SubstractMat1(int **A, int **B, int C[N][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to Calculate Strassens Matrix
int **STMP(int **A,int **B ,int n)
{
    int i,j;
    int **C;
    C = malloc(sizeof(int*) * n);
    
    for(i = 0; i < n; i++) {
        C[i] = malloc(sizeof(int*) * n);
    }
    //printf("Entered function again\n");
    int m1,m2,m3,m4,m5,m6,m7;
    int A11[N][N],A12[N][N],A21[N][N],A22[N][N],B11[N][N],B12[N][N],B21[N][N],B22[N][N],Ex[N][N],R1[N][N],R3[N][N],R2[N][N],R4[N][N],R5[N][N];
    //printf("No problem in assigning static memory\n");
    memset(Ex, 0, N*N*sizeof(int) );
    int **D1 = NULL;
    int **D2 = NULL;
    int **D3 = NULL;
    int **D4 = NULL;
    int **D5 = NULL;
    int **D6 = NULL;
    int **D7 = NULL;
    int **D8 = NULL;
    int **D9 = NULL;
    int **D10 = NULL;
    int C11[N][N];
    int C12[N][N];
    int C21[N][N];
    int C22[N][N];
    int **M1= NULL;
    int **M2= NULL;
    int **M3= NULL;
    int **M4= NULL;
    int **M5= NULL;
    int **M6= NULL;
    int **M7= NULL;
    int **D11 = NULL;
    int **D12 = NULL;
    int **D13 = NULL;
    int **D14 = NULL;
    int **D15 = NULL;
    int **D16= NULL;
    int **D17= NULL;
    //printf("No problem in assigning dynamic memory\n");
    
    if (n==2) {
        //printf("Entered if loop\n");
        int w=A[0][0];
        int r=A[0][1];
        int q=A[1][0];
        int t=A[1][1];
        int w1=B[0][0];
        int r1=B[0][1];
        int q1=B[1][0];
        int t1=B[1][1];
        m1= (w + t) * (w1 + t1);
        m2= (q + t) * w1;
        m3= w * (r1 - t1);
        m4= t * (q1 - w1);
        m5= (w + r) * t1;
        m6= (q - w) * (w1+r1);
        m7= (r - t) * (q1+t1);
        
        C[0][0] = m1 + m4 - m5 + m7;
        C[0][1] = m3 + m5;
        C[1][0] = m2 + m4;
        C[1][1] = m1 - m2 + m3 + m6;
        //printf("Completed if loop for %d \n",n);
    }
    
    else {
        
        // Dividing the Array into subparts
        //printf("in else for %d\n",n);
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                if((i<n/2) && (j<n/2)) {
                    A11[i][j] = A[i][j];
                    B11[i][j] = B[i][j];
                }
                if((i<n/2) && (j>=n/2)) {
                    A12[i][j-n/2]=A[i][j];
                    B12[i][j-n/2]=B[i][j];
                }
                if((i>=n/2) && (j<n/2)) {
                    A21[i-n/2][j] = A[i][j];
                    B21[i-n/2][j] = B[i][j];
                }
                if((i>=n/2) && (j>=n/2)) {
                    A22[i-n/2][j-n/2]=A[i][j];
                    B22[i-n/2][j-n/2]=B[i][j];
                }
                
            }
        }
        /*printf("A11\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",A11[i][j]);
         }
         printf("\n");
         }
         printf("B12\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",B12[i][j]);
         }
         printf("\n");
         }
         printf("B21\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",B21[i][j]);
         }
         printf("\n");
         }*/
        //printf("Division of array successful for %d \n",n);
        
        // Performing Addition of Matrix
        D1=AddMat(A11, A22,n/2);
        D2=AddMat(B11, B22,n/2);
        D3=AddMat(A21, A22,n/2);
        D4=AddMat(A11, A12,n/2);
        D5=AddMat(B11, B12,n/2);
        D6=AddMat(B21, B22,n/2);
        D7=SubstractMat(B12, B22,n/2);
        
        /*printf("D2\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",D2[i][j]);
         }
         printf("\n");
         }*/
        
        D8=SubstractMat(B21, B11,n/2);
        D9=SubstractMat(A21, A11,n/2);
        D10=SubstractMat(A12, A22,n/2);
        //printf("Performed Sub and Add\n");
        M1=STMP(D1,D2,n/2);
        
        /*printf("M1\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",M1[i][j]);
         }
         printf("\n");
         }*/
        D11=AddMat(B11,Ex,n/2);
        M2=STMP(D3,D11,n/2);
        D12=AddMat(A11, Ex, n/2);
        M3=STMP(D12,D7,n/2);
        D13=AddMat(A22, Ex, n/2);
        M4=STMP(D13,D8,n/2);
        D14=AddMat(B22, Ex, n/2);
        M5=STMP(D4,D14,n/2);
        M6=STMP(D9,D5,n/2);
        M7=STMP(D10,D6,n/2);
        AddMat1(M1, M4,R1,n/2);
        
        /*printf("R1\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",R1[i][j]);
         }
         printf("\n");
         }*/
        AddMat1(M1,M4,R2,n/2);
        D15=AddMat(R2,Ex, n/2);
        //R2=AddMat(M1, M4,n/2);
        SubstractMat1(D15,M5,R3,n/2);
        D16=AddMat(R3, Ex, n/2);
        AddMat1(D16,M7,C11,n/2);
        AddMat1(M3,M5,C12,n/2);
        AddMat1(M2,M4,C21,n/2);
        SubstractMat1(M1,M2,R4,n/2);
        D16=AddMat(R4, Ex, n/2);
        AddMat1(D16,M3,R5,n/2);
        D17=AddMat(R5, Ex, n/2);
        AddMat1(D17,M6,C22,n/2);
        
        /*printf("C11\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",C11[i][j]);
         }
         printf("\n");
         }
         printf("C12\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",C12[i][j]);
         }
         printf("\n");
         }
         printf("C21\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",C21[i][j]);
         }
         printf("\n");
         }
         printf("C22\n");
         for (i=0;i<n/2;i++) {
         for (j=0;j<n/2;j++) {
         printf("%d ",C22[i][j]);
         }
         printf("\n");
         }
         
         printf("Performed till the end\n");*/
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                if((i<n/2) && (j<n/2)) {
                    C[i][j]=C11[i][j];
                }
                if((i<n/2) && (j>=n/2)) {
                    C[i][j]=C12[i][j-n/2];
                }
                if((i>=n/2) && (j<n/2)) {
                    C[i][j]=C21[i-n/2][j];
                }
                if((i>=n/2) && (j>=n/2)) {
                    C[i][j]=C22[i-n/2][j-n/2];
                }
            }
        }
    }
    
    return C;
}



int main() {
    int num,i,j;
    //printf("enter input");
    scanf("%d",&num);
    int NewNum = PowerOf2(num);
    //printf("%d",NewNum);
    N=NewNum;
    int **C = calloc(NewNum, sizeof(int*));
    for(int i = 0; i < NewNum; i++) C[i] = calloc(NewNum, sizeof(int));
    int NaiveResult[N][N];
    
    
    int **A = calloc(NewNum, sizeof(int*));
    for(int i = 0; i < NewNum; i++) A[i] = calloc(NewNum, sizeof(int));
    // fill matrix
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            //A[i][j]=1;
            scanf("%d", &A[i][j]);
        }
    }
    
    
    int **B = calloc(NewNum, sizeof(int*));
    for(int i = 0; i < NewNum; i++) B[i] = calloc(NewNum, sizeof(int));
    // fill matrix
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            //B[i][j]=1;
            scanf("%d", &B[i][j]);
        }
    }
    // Printing matrix A
    /*printf("A\n");
     for (i=0;i<NewNum;i++)
     {
     for (j=0;j<NewNum;j++)
     {
     printf("%d ",A[i][j]);
     }
     printf("\n");
     }
     
     // Printing matrix B
     printf("B\n");
     for (i=0;i<NewNum;i++)
     {
     for (j=0;j<NewNum;j++)
     {
     printf("%d ",B[i][j]);
     }
     printf("\n");
     }*/
    clock_t t1,t2;
    FILE *f3 = fopen("output_p2.txt", "w");
    FILE *f1 = fopen("output_p1_m1.txt", "w");
    t2 = clock();
    MultiplyMatrix(A, B, NaiveResult);
    // Printing Result
    //printf("Using Naive Multiplication method, C is\n");
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            fprintf(f1, "%d ", NaiveResult[i][j]);
            //printf("%d ",NaiveResult[i][j]);
        }
        fprintf(f1,"\n");
        //printf("\n");
    }
    t2 = clock() - t2;
    double time_taken = ((double)t2)/CLOCKS_PER_SEC;
    int final_time=time_taken*1000;
    fprintf(f3, "%d ", final_time);
    printf("Using Naive Multiplication method time taken is %d\n",final_time);
    fclose(f1);
    
    
    FILE *f2 = fopen("output_p2_m2.txt", "w");
    t1 = clock();
    //printf("calling STMP for %d",NewNum);
    C=STMP(A,B,NewNum);
    // Printing Result
    //printf("Using STMP method, C is\n");
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            //printf("%d ",C[i][j]);
            fprintf(f2, "%d ", C[i][j]);
        }
        //printf("\n");
        fprintf(f2,"\n");
    }
    t1 = clock() - t1;
    double time_STMP = ((double)t1)/CLOCKS_PER_SEC;
    int STMP_time=time_STMP*1000;
    fprintf(f3, "%d ", STMP_time);
    printf("Using STMP time taken is %d\n",STMP_time);
    fclose(f2);
}