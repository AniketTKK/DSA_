1.	Backtracking algorithm using stack data structure:
2.	1. Backtracking algorithm using stack data structure:
3.	c
4.	#include <stdio.h>
5.	#include <stdlib.h>
6.	#define MAX 100
7.
8.	int stack[MAX];
9.	int top = -1;
10.
11.	void push(int x) {
12.	    stack[++top] = x;
13.	}
14.
15.	int pop() {
16.	    return stack[top--];
17.	}
18.
19.	int isStackEmpty() {
20.	    return top == -1;
21.	}
22.
23.	void printStack() {
24.	    int i;
25.	    printf("Stack: ");
26.	    for (i = 0; i <= top; i++) {
27.	        printf("%d ", stack[i]);
28.	    }
29.	    printf("\n");
30.	}
31.
32.	void backtrackingUsingStack(int n) {
33.	    int i, j;
34.	    int a[n][n];
35.	    for (i = 0; i < n; i++) {
36.	        for (j = 0; j < n; j++) {
37.	            a[i][j] = 0;
38.	        }
39.	    }
40.	    push(0);
41.	    while (!isStackEmpty()) {
42.	        int row = pop();
43.	        if (row == n) {
44.	            printStack();
45.	            continue;
46.	        }
47.	        for (i = 0; i < n; i++) {
48.	            if (a[row][i] == 0) {
49.	                push(i);
50.	                a[row][i] = 1;
51.	            }
52.	        }
53.	        push(row + 1);
54.	    }
55.	}
56.
57.	int main() {
58.	    int n;
59.	    printf("Enter the number of queens: ");
60.	    scanf("%d", &n);
61.	    backtrackingUsingStack(n);62.	}
