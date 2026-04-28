typedef struct {
    int *data;
    int *min;
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    obj->data = malloc(30000 * sizeof(int));
    obj->min = malloc(30000 * sizeof(int));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->data[obj->top] = val;
    if (obj->top == 0) {
        obj->min[obj->top] = val;
    } else {
        int currentMin = obj->min[obj->top - 1];
        obj->min[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->min);
    free(obj);
}