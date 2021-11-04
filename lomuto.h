//
// Created by andrewiii on 11/4/21.
//

#ifndef HYBRID_QUICKSORT_LOMUTO_H
#define HYBRID_QUICKSORT_LOMUTO_H


class lomuto {
private:
    void swap(int &a, int &b);
public:
    int Lomuto(int *data, int first, int r);
    int MLomuto(int *data, int first, int r);

};


#endif //HYBRID_QUICKSORT_LOMUTO_H
