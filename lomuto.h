//
// Created by andrewiii on 11/4/21.
//

#ifndef HYBRID_QUICKSORT_LOMUTO_H
#define HYBRID_QUICKSORT_LOMUTO_H


class lomuto {
public:
    static void swap(int &a, int &b);
    static int Lomuto(int *data, int first, int r);
    static int MLomuto(int *data, int first, int r);

};


#endif //HYBRID_QUICKSORT_LOMUTO_H
