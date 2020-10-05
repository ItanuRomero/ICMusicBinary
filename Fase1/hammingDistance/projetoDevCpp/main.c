#include <stdio.h>
#include <stdlib.h>
#include "hammingFunctions.h"

int main(){
    float media;
    char name_1[30], name_2[30];
    name_1 = name_archive(1);
    name_2 = name_archive(2);

    // Valor padrao para testes
    if (name_1 == "padrao") {
        name_1 = "./testes/texto01.txt"
    }
    if (name_2 == "padrao") {
        name_2 = "./testes/texto02.txt"
    }

    media = analyse_file(name_1, name_2);

    save_data(media);

    return 0;
}
