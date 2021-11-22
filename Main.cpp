//
// Created by andrewiii on 11/7/21.
//
#include "Main.h"
#include <stdlib.h>
#include <iostream>
#include <chrono>

using namespace std;
void static swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}


void static sortF(int *data, int first, int last, int (*v) (int*, int, int)) {
    if(first < last){
        int pv = v(data, first, last);
        sortF(data, first, pv-1, v);
        sortF(data, pv+1, last, v);
    }
}

int static Lomuto(int *data, int first, int r){
    int pivot = data[r];
    int i = first -1;
    for (int j = first; j < r; j++)
        if (data[j] <= pivot)
            swap(data[++i], data[j]);
    swap(data[++i], data[r]);
    return i;
}

int static MLomuto(int* data, int first, int last){
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

int static Hoare(int* data, int first, int last) {
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

int static MHoare(int* data, int first, int last) {
    if (data[first] > data[last])
        swap(data[first], data[last]);
    int pivot = data[first];
    while (true) {
        while (data[--last] > pivot);
        data[first] = data[last];
        while (data[++first] < pivot);
        if (first < last)
            data[last] = data[first];
        else {
            if (data[last + 1] <= pivot)
                last++;
            data[last] = pivot;
            return last;
        }
    }
}

int static M5(int *data, int first, int last) {
    if(first >= last)
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
    int pivot = data[first];
    while(true) {
        while(++i <= last && data[i] < pivot);
        while(data[--j] > pivot);
        if (i > j) break;
        swap(data[i], data[j]);
    }
    swap(data[first], data[j]);
    return j;
}

void static Shell(int *data, int first, int last) {

    const int k[]={1,7,19};
    int l=0, range=last-first;

    while(l<3 && k[l] < range)
        l++;

    while(--l >= 0) {
        int t = k[l];
        for(int i=first+t; i<last; i++) {
            int kt = data[i], j=i;
            for(; j>first; j-=kt)
                if(t < data[j-kt])
                    data[j]=data[j-kt];
            data[j]=t;
        }
    }
}

void static HF(int *data, int first, int last, int (*v) (int*,int,int), int cutoff) {
    if (first < last) {
        if (last - first <= cutoff) {
            Shell(data, first, last);
            return;
        }
        int pv = v(data, first, last);
        sortF(data, first, pv - 1, v);
        sortF(data, pv + 1, last, v);
    }
}

void static quick3(int *data, int left, int right) {
    if(left >= right)
        return;
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

bool static check_sorted(int *data, int length){
    for (int i = 1; i < length; i++){
        if (data[i] < data[i-1]){
            return false;
        }
        else
            return true;
    }
    return true;
}


int main(){
    int arraycount = 10000;
    int array[arraycount];
    int arraycopy[arraycount];

    srand(1000);
    int cutoffStart = 6;
    int cutoffEnd = 32;
    int numberOfCutoffs = cutoffEnd - cutoffStart;

    for (int i = 0; i < arraycount; i++){
        array[i] = rand();
    }

    std::cout << "\n" << "M5: ";

    for(int i=cutoffStart; i <= cutoffEnd; i++){

        std::copy(array, array + arraycount , arraycopy);
        auto start = std::chrono::high_resolution_clock::now();
        HF(array, 0, arraycount, M5, i);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        std::cout << duration.count() << ", ";
    }

    std::cout << "\n" << "Hoare: ";



    for(int i = cutoffStart; i <= cutoffEnd; i++){
        std::copy(array, array + arraycount , arraycopy);
        auto start = std::chrono::high_resolution_clock::now();
        HF(array, 0, arraycount, Hoare, i);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        std::cout << duration.count() << ", ";
    }

    std::cout << "\n" << "MHoare: ";




    for(int i=cutoffStart; i<=cutoffEnd; i++){
        std::copy(array, array + arraycount , arraycopy);
        auto start = std::chrono::high_resolution_clock::now();
        HF(array, 0, arraycount, MHoare, i);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        std::cout << duration.count() << ", ";
    }

    std::cout << "\n" << "Lomuto: ";

    for(int i=cutoffStart; i<=cutoffEnd; i++){
        std::copy(array, array + arraycount , arraycopy);
        auto start = std::chrono::high_resolution_clock::now();
        HF(array, 0, arraycount, Lomuto, i);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        std::cout << duration.count() << ", ";
    }

    std::cout << "\n" << "MLomuto: ";

    for(int i=cutoffStart; i<=cutoffEnd; i++){
        int tempI = i; // Needed because MLomuto modifies i
        std::copy(array, array + arraycount , arraycopy);
        auto start = std::chrono::high_resolution_clock::now();
        HF(array, 0, arraycount, MLomuto, tempI);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        std::cout << duration.count() << ", ";
    }

    std::cout << "\n";

}
