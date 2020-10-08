#ifndef HAMMINGFUNCTIONS_H_INCLUDED
#define HAMMINGFUNCTIONS_H_INCLUDED

    #define BLOCO 44100
    #define QUANT_CHAR 30
    #define QUANT_BIT 64

    float analyse_file();
    int hammingDistance(int n1, int n2);
    int readingFileError(FILE *arch1, FILE *arch2);
    void save_data(float media);

#endif // HAMMINGFUNCTIONS_H_INCLUDED
