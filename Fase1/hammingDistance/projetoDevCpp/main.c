#include <stdio.h>
#include "hammingFunctions.h"

int main(){
    float media;
    
	//save_information();

    media = analyse_file();

    save_data(media);

    return 0;
} 
