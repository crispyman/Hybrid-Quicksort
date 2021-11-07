#include "shell.h"

void Shell(int *data, int first, int
last) {
    
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
