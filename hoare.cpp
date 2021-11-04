//
// Created by Andrew Pobrica on 11/3/21.
//

#include "hoare.h"

void hoare::sortF(int *data, int first, int last, int (*v) (int*, int, int)) {
    if(first < last){
        int pv = v(data, first, last);
        sortF(data, first, pv-1, v);
        sortF(data, pv+1, last, v);
    }
}

void hoare::swap(int &a, int &b) {
    int c=a;
    a=b;
    b=c;
}

int hoare::Hoare(int* data, int first, int last) {
    if (first < last) {
        int pivot = data[first];
        int i = first;
        int j = last + 1;
        while (true) {
            while (++i <= last && data[i] < pivot);
            while (data[--j] > pivot);
            if (i > j)
                break;
            swap(data[i], data[j]);
        }
        swap(data[first], data[j]);
        return j;
    }
    return -1;
}

int hoare::MHoare(int* data, int first, int last){
    if(data[first]>data[last])
        swap(data[first], data[last]);
    int pivot = data[first];
    while(true) {
        while(data[--last] > pivot);
        data[first]=data[last];
        while(data[++first] < pivot);
        if(first < last)
            data[last]=data[first];
        else{
            if (data[last+1] <= pivot)
                last++;
            data[last] = pivot;
            return last;
        }
    }
}

