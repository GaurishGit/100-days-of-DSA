typedef struct {
    int input[100];
    int output[100];
    int inTop;
    int outTop;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->inTop = -1;
    obj->outTop = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->input[++(obj->inTop)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->outTop == -1) {
        while (obj->inTop != -1) {
            obj->output[++(obj->outTop)] = obj->input[(obj->inTop)--];
        }
    }
    return obj->output[(obj->outTop)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->outTop == -1) {
        while (obj->inTop != -1) {
            obj->output[++(obj->outTop)] = obj->input[(obj->inTop)--];
        }
    }
    return obj->output[obj->outTop];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->inTop == -1 && obj->outTop == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}