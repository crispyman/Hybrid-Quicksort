//
// Created by andrewiii on 11/4/21.
//

#include "m5.h"

int m5::M5(int *data, int first, int last) {
    if(data[first >= data[last]])
        return -1;
    int i = first;
    int j = last+1;
    int range = last - first;
    if (range > 5){
        int k[] = {first, first + range / 4,
                   first + range /2,
                   first +3 * range / 4, last};
        for (int i=1; i < 5; i++) {
            int j = i;
            int c = data[k[i]];
            for (j = i; j > 0; j--)
                if (c < data[k[j - 1]])
                    data[k[j]] = data[k[j - 1]];
            data[k[j]] = c;
        }
        swap(data[k[0]], data[k[2]]);
    }
    int x = data[first];
    while(true) {
        while(++i <= last && data[i] < pivot);
        while(data[--j] > pivot);
        if (i > j) break;
        swap(data[i], data[j]);
    }
    swap(data[first], data[j]);
    return j;
}

void m5::swap(int &a, int &b) {
    int c=a;
    a=b;
    b=c;
