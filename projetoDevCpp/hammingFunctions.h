#ifndef HAMMINGFUNCTIONS_H_INCLUDED
#define HAMMINGFUNCTIONS_H_INCLUDED

    #define BLOCO 1
    #define QUANT_CHAR 30
    #define QUANT_BIT 32

    float analyse_file(int shift);
    int hammingDistance(int n1, int n2);
    int readingFileError(FILE *arch1, FILE *arch2);
    void save_data(float media);
    

#endif // HAMMINGFUNCTIONS_H_INCLUDED
