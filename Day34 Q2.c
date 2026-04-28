int calculate(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    
    int stack[len];
    int top = -1;
    long currentNumber = 0;
    char operation = '+';

    for (int i = 0; i < len; i++) {
        char currentChar = s[i];
        
        if (isdigit(currentChar)) {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
        }
        
        if ((!isdigit(currentChar) && !isspace(currentChar)) || i == len - 1) {
            if (operation == '+') {
                stack[++top] = currentNumber;
            } else if (operation == '-') {
                stack[++top] = -currentNumber;
            } else if (operation == '*') {
                stack[top] = stack[top] * currentNumber;
            } else if (operation == '/') {
                stack[top] = stack[top] / currentNumber;
            }
            operation = currentChar;
            currentNumber = 0;
        }
    }

    int result = 0;
    while (top != -1) {
        result += stack[top--];
    }
    return result;
}