//
// Created by andrewiii on 11/7/21.
//

#ifndef HYBRID_QUICKSORT_MAIN_H
#define HYBRID_QUICKSORT_MAIN_H


class Main {
public:
    static void swap(int &a, int &b);
    static void sortF(int *data, int first, int last, int (*v) (int*, int, int));
    static int Hoare(int* data, int first, int last);
    static int MHoare(int* data, int first, int last);
    static void HF(int *data, int first, int last, int (*v) (int*,int,int), int cutoff);
    static int Lomuto(int *data, int first, int r);
    static int MLomuto(int *data, int first, int r);
    static int M5(int *data, int first, int last);
    static void Q3(int *data, int left, int right);
    static void Shell(int *data, int first, int last);


    int main();
};


#endif //HYBRID_QUICKSORT_MAIN_H
