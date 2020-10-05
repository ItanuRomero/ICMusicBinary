#ifndef HAMMINGFUNCTIONS_H_INCLUDED
#define HAMMINGFUNCTIONS_H_INCLUDED

    #define BLOCO 20

    float analyse_file();
    int hammingDistance(int n1, int n2);
    int readingFileError(FILE *arch1, FILE *arch2);
    void save_data(float media);
    char name_archive(int number);

#endif // HAMMINGFUNCTIONS_H_INCLUDED
