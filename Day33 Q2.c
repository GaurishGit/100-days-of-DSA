int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* s = tokens[i];
        
        if ((s[0] >= '0' && s[0] <= '9') || (s[0] == '-' && s[1] != '\0')) {
            stack[++top] = atoi(s);
        } else {
            int b = stack[top--];
            int a = stack[top--];
            
            if (s[0] == '+') stack[++top] = a + b;
            else if (s[0] == '-') stack[++top] = a - b;
            else if (s[0] == '*') stack[++top] = a * b;
            else if (s[0] == '/') stack[++top] = a / b;
        }
    }
    return stack[top];
}