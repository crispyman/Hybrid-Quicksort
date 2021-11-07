//
// Created by andrewiii on 11/7/21.
//
#include "hoare.cpp"
#include "shell.cpp"

#include "hf.h"
void HF(int *data, int first, int last, int (*v) (int*,int,int), int cutoff){
    if (first < last){
        if(last - first <= cutoff){
            shell::Shell(data, first, last);
            return;
        }
        int pv = v(data, first, last);
        hoare::sortF(data, first, pv-1, v);
        hoare::sortF(data, pv+1, last, v);
    }
}
