//
// Created by andrewiii on 11/3/21.
//

#ifndef HYBRID_QUICKSORT_HOARE_H
#define HYBRID_QUICKSORT_HOARE_H

class hoare {

public:
    static void swap(int &a, int &b);
    static void sortF(int *data, int first, int last, int (*v) (int*, int, int));
    static int Hoare(int* data, int first, int last);
    static int MHoare(int* data, int first, int last);

};



#endif //HYBRID_QUICKSORT_HOARE_H
