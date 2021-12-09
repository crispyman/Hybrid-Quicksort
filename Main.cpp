//
// Created by Andrew Pobrica on 11/7/21.
//
#include "Main.h"
#include <iostream>
#include <chrono>
#include<fstream>
#include <algorithm>
#include <random>


//using namespace std;

#define SORT_NAME sorter
#define SORT_TYPE int

#include "sort.h"


void Main::swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}


void Main::sortF(int *data, int first, int last, int (*v) (int*, int, int)) {
    if(first < last){
        int pv = v(data, first, last);
        sortF(data, first, pv-1, v);
        sortF(data, pv+1, last, v);
    }
}

int Main::Lomuto(int *data, int first, int r){
    int pivot = data[r];
    int i = first -1;
    for (int j = first; j < r; j++)
        if (data[j] <= pivot)
            swap(data[++i], data[j]);
    swap(data[++i], data[r]);
    return i;
}

int Main::MLomuto(int* data, int first, int last){
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

int Main::Hoare(int* data, int first, int last) {
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

int Main::MHoare(int* data, int first, int last) {
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

int  Main::M5(int *data, int first, int last) {
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

void Main::Shell(int *data, int first, int last) {

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

void Main::HF(int *data, int first, int last, int (*v) (int*,int,int), int cutoff) {
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

void Main::quick3(int *data, int left, int right) {
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

bool Main::check_sorted(int *data, int length){
    for (int i = 1; i < length; i++){
        if (data[i] < data[i-1]){
            return false;
        }
        else
            return true;
    }
    return true;
}


int Main::compareUnique(){
    std::ofstream file;
    file.open("times.csv");

    constexpr int arraycount = 1000000;
    int array[arraycount];
    int arraycopy[arraycount];
    double average;

    constexpr int cutoffStart = 6;
    constexpr int cutoffEnd = 32;
    const int numberOfCutoffs = cutoffEnd - cutoffStart;

    for (int i = 0; i < arraycount; i++){
        array[i] = i % 1000;
    }


    std::shuffle(array, array + arraycount, std::default_random_engine(1000));

    file << "alg";
    for(volatile int i=cutoffStart; i <= cutoffEnd; i++) {
        file << "," << i;

    }
    std::cout << "\n" << "M5: ";

    file << "\nM5";

    for(volatile int i=cutoffStart; i <= cutoffEnd; i++) {

        average = 0;

        for (int j = 0; j < 50; j++) {
            int tempI = i;
            memcpy(arraycopy, array, 4 * arraycount);
            auto start = std::chrono::steady_clock::now();
            HF(arraycopy, 0, arraycount, M5, tempI);
            auto stop = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            average += duration.count();

        }
        average /= 50;
        file << "," << average;
    }
    std::cout << "\n" << "Hoare: ";

    file << "\nHoare";

    for(volatile int i=cutoffStart; i <= cutoffEnd; i++) {

        average = 0;
        for (volatile int j = 0; j <= 50; j++) {
            int tempI = i;
            memcpy(arraycopy, array, 4 * arraycount);
            auto start = std::chrono::steady_clock::now();
            HF(arraycopy, 0, arraycount, Hoare, tempI);
            auto stop = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            average += duration.count();

        }
        average /= 50;
        file << "," << average;
    }

    std::cout << "\n" << "MHoare: ";
    file << "\nMHoare";



    for(volatile int i=cutoffStart; i <= cutoffEnd; i++) {

        average = 0;
        for (volatile int j = 0; j <= 50; j++) {
            int tempI = i;
            memcpy(arraycopy, array, 4 * arraycount);
            auto start = std::chrono::steady_clock::now();
            HF(arraycopy, 0, arraycount, MHoare, tempI);
            auto stop = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            average += duration.count();

        }
        average /= 50;
        file << "," << average;
    }
    std::cout << "\n" << "Lomuto: ";
    file << "\nLomuto";


    for(volatile int i=cutoffStart; i <= cutoffEnd; i++) {

        average = 0;
        for (volatile int j = 0; j <= 50; j++) {
            int tempI = i; // Needed because MLomuto modifies i
            memcpy(arraycopy, array, 4 * arraycount);
            auto start = std::chrono::steady_clock::now();
            HF(arraycopy, 0, arraycount, Lomuto, tempI);
            auto stop = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            average += duration.count();
        }
        average /= 50;
        file << "," << average;
    }

    std::cout << "\n" << "MLomuto: ";
    file << "\nMLomuto";

    for(volatile int i=cutoffStart; i <= cutoffEnd; i++) {

        average = 0;
        for (volatile int j = 0; j <= 50; j++) {
            int tempI = i; // Needed because MLomuto modifies i
            memcpy(arraycopy, array, 4 * arraycount);
            auto start = std::chrono::steady_clock::now();
            HF(arraycopy, 0, arraycount, MLomuto, tempI);
            auto stop = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            average += duration.count();
        }
        average /= 50;
        file << "," << average;
    }
    std::cout << "\n";
    file.close();

    return 0;
}


int Main::comparesizes(){

    std::ofstream file;
    file.open("sizes.csv", std::ios_base::app);

    const int arraycount = 300000;
    int array[arraycount];
    int arraycopy[arraycount];
    double average;

    file << "\n" <<  arraycount;

    for (int i = 0; i < 300; i++){
        array[i] = rand() % 300000;
    }
    for (int i = 1000; i < arraycount; i++){
        array[i] = i;
    }

    //for (int i = 0; i < arraycount; i++){
    //    array[i] = i;
    //}


    std::shuffle(array, array + arraycount, std::default_random_engine(1000));


    auto start = std::chrono::steady_clock::now();
    auto stop = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


    average = 0;

    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        HF(arraycopy, 0, arraycount, MHoare, 22);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        average += duration.count();
    }
    average /= 50;
    file << "," << average;

    average = 0;

    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        HF(arraycopy, 0, arraycount, Lomuto, 22);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        average += duration.count();

    }
    average /= 50;
    file << "," << average;
    average = 0;

    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        HF(arraycopy, 0, arraycount, MHoare, 19);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        average += duration.count();

    }
    average /= 50;
    file << "," << average;
    average = 0;

    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        HF(arraycopy, 0, arraycount, Hoare, 19);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        average += duration.count();
    }
    average /= 50;
    file << "," << average;
    average = 0;


    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        HF(arraycopy, 0, arraycount, Hoare, 29);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            average += duration.count();

    }
    average /= 50;
    file << "," << average;
    average = 0;

    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        HF(arraycopy, 0, arraycount, Hoare, 30);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            average += duration.count();

        }
    average /= 50;
    file << "," << average;
    average = 0;

    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        std::sort(arraycopy, arraycopy + arraycount);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        average += duration.count();

    }
    average /= 50;
    file << "," << average;
    average = 0;

    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        sorter_tim_sort(arraycopy, arraycount);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        average += duration.count();

    }
    average /= 50;
    file << "," << average;
    average = 0;

    for (int i = 0; i < 50; i++) {
        memcpy(arraycopy, array, 4 * arraycount);
        start = std::chrono::steady_clock::now();
        sorter_merge_sort(arraycopy, arraycount);
        stop = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        average += duration.count();

    }
    average /= 50;
    file << "," << average;
    average = 0;



    std::cout << "\n";
    file.close();
    return 0;
}

int main(){
    Main::comparesizes();
    // Main::compareUnique();


    return 0;
}