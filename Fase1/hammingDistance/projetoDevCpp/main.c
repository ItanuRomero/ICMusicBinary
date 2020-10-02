#include <stdio.h>
#include <stdlib.h>
#include "hammingFunctions.h"

int main(){
    float media;

    media = analyse_file();

    save_data(media);
    
    return 0;
}
