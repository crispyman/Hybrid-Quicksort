//
// Created by andrewiii on 11/4/21.
//

#include "lomuto.h"

int lomuto::Lomuto(int *data, int first, int r){
    int pivot = data[r];
    int i = first -1;
    for (int j = first; j < r; j++)
        if (data[j] <= pivot)
            swap(data[++i], data[j]);
        swap(data[++i], data[r]);
        return i;
}

int lomuto::MLomuto(int* data, int first, int last){
    int x = data[first];
    int i = first;
    int j = last;
    while(true) {
        while (data[j] > x) j--;
        if (j <= i) break;
        data[i] = data[j];
        data[j] = data[++i];
    }
    data[i] = x;
    return i;
}

void lomuto::swap(int &a, int &b) {
    int c=a;
    a=b;
    b=c;
}



