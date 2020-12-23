#include <stdio.h>
#include "hammingFunctions.h"

int main(){
    float media;
    int number_shift = 0, range;
    
    /*
    *** para testes com o shift ***
    
    printf("Coloque o range: ");
    scanf("%d", &range);
    
    
    for ( number_shift = 0; number_shift <= range; number_shift = number_shift + 500 ){
    	media = analyse_file(number_shift);
    	save_data(media);
	}
	*/
	
	media = analyse_file(number_shift);
    save_data(media);

    return 0;
} 
