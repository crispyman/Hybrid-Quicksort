//
// Created by Joshua on 11/7/2021.
//

#include "quick3.h"

int quick3::quick3(int *data, int left, int right) {
    if(left >= right) return;
    int li = left;
    int last = right;
    int pv = data[li];
    int ln = left;
    while(ln <= last) {
        if(data[ln] < pv) swap(data[li++], data[ln++]);
        else if(data[ln] > pv) swap(data[ln], data[last--]);
        else ln++;
    }
    quick3(data, left, li - 1);
    quick3(data, last + 1, right);
}

void quick3::swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}
