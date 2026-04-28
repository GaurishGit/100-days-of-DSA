#include <stdlib.h>

typedef struct {
    int maxHeap[100000];
    int minHeap[100000];
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

/* MAX HEAP */

void maxUp(MedianFinder* obj,int i){
    while(i>0){
        int p=(i-1)/2;
        if(obj->maxHeap[p] < obj->maxHeap[i]){
            swap(&obj->maxHeap[p],&obj->maxHeap[i]);
            i=p;
        }else break;
    }
}

void maxDown(MedianFinder* obj,int i){
    while(1){
        int l=2*i+1,r=2*i+2,big=i;

        if(l<obj->maxSize && obj->maxHeap[l]>obj->maxHeap[big]) big=l;
        if(r<obj->maxSize && obj->maxHeap[r]>obj->maxHeap[big]) big=r;

        if(big!=i){
            swap(&obj->maxHeap[i],&obj->maxHeap[big]);
            i=big;
        }else break;
    }
}

void maxInsert(MedianFinder* obj,int val){
    obj->maxHeap[obj->maxSize]=val;
    maxUp(obj,obj->maxSize);
    obj->maxSize++;
}

int maxPop(MedianFinder* obj){
    int root=obj->maxHeap[0];
    obj->maxHeap[0]=obj->maxHeap[--obj->maxSize];
    maxDown(obj,0);
    return root;
}

/* MIN HEAP */

void minUp(MedianFinder* obj,int i){
    while(i>0){
        int p=(i-1)/2;
        if(obj->minHeap[p] > obj->minHeap[i]){
            swap(&obj->minHeap[p],&obj->minHeap[i]);
            i=p;
        }else break;
    }
}

void minDown(MedianFinder* obj,int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;

        if(l<obj->minSize && obj->minHeap[l]<obj->minHeap[small]) small=l;
        if(r<obj->minSize && obj->minHeap[r]<obj->minHeap[small]) small=r;

        if(small!=i){
            swap(&obj->minHeap[i],&obj->minHeap[small]);
            i=small;
        }else break;
    }
}

void minInsert(MedianFinder* obj,int val){
    obj->minHeap[obj->minSize]=val;
    minUp(obj,obj->minSize);
    obj->minSize++;
}

int minPop(MedianFinder* obj){
    int root=obj->minHeap[0];
    obj->minHeap[0]=obj->minHeap[--obj->minSize];
    minDown(obj,0);
    return root;
}

/* MEDIAN FINDER */

MedianFinder* medianFinderCreate(){
    MedianFinder* obj=malloc(sizeof(MedianFinder));
    obj->maxSize=0;
    obj->minSize=0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj,int num){

    if(obj->maxSize==0 || num<=obj->maxHeap[0])
        maxInsert(obj,num);
    else
        minInsert(obj,num);

    if(obj->maxSize > obj->minSize+1)
        minInsert(obj,maxPop(obj));

    if(obj->minSize > obj->maxSize)
        maxInsert(obj,minPop(obj));
}

double medianFinderFindMedian(MedianFinder* obj){

    if(obj->maxSize == obj->minSize)
        return (obj->maxHeap[0]+obj->minHeap[0])/2.0;

    return obj->maxHeap[0];
}

void medianFinderFree(MedianFinder* obj){
    free(obj);
}