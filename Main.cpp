//
// Created by andrewiii on 11/7/21.
//

#include "Main.h"
#include "hf.h"
#include "m5.h"
#include "hoare.h"
int main(){
    for(int i=6; i <= 32; i++){
        sortHF(array, 0, arraycount, m5::M5, i);
    }
    for(int i = 6; i <= 32; i++){
        sortHF(array, 0, arraycount, hoare::Hoare, i);
    }
    for(int i=6; i<=32; i++){
        sortHF(array, 0, arraycount, hoare::MHoare, i);
    }
}
