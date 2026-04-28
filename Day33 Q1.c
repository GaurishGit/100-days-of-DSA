/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 0;
    
    int *stack = (int *)malloc(n * sizeof(int));/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(sizeof(int) * tokensSize);
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* s = tokens[i];
        if (strlen(s) > 1 || (s[0] >= '0' && s[0] <= '9')) {
            stack[++top] = atoi(s);
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch (s[0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }
    int result = stack[top];
    free(stack);
    return result;
}

int main() {
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int size = 5;
    printf("Result: %d\n", evalRPN(tokens, size));
    return 0;
}
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }
    
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
    
    free(stack);
    return 0;
}