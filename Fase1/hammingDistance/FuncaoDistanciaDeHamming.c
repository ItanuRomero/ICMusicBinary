#include <stdio.h>


int main()
{
    open_file();
    printf("tudo certo.\n");
    analyse_file();
    return 0;
}

void open_file(){
    FILE *arq;
    FILE *arq2;
    int result;
    char Str[50];

    arq = fopen("./D.B._Ricapito_-_So_Crazy.mp3", "rb");
    arq2 = fopen("./The_Devil_Music_Co._-_Head_Over_Heels.mp3", "rb");


    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        return;
    }
    if (arq2 == NULL)
    {
        printf("Problemas na abertura do arquivo 2\n");
        return;
    }


    fclose(arq);
    fclose(arq2);
}

void analyse_file(){
        int bit, bit_2;
        FILE *arq;
        FILE *arq2;
        int xor, count_zero = 0;
        int buffer[100];
        int result;

        arq = fopen("./D.B._Ricapito_-_So_Crazy.mp3", "rb");
        arq2 = fopen("./The_Devil_Music_Co._-_Head_Over_Heels.mp3", "rb");

            bit = fread( &buffer, 10, 1, arq );
            bit_2 = fread( &buffer, 10, 1, arq2 );

                if ( bit == NULL || bit_2 == NULL )
                {
                    printf("valor nulo!\n");
                }
                printf("valor de bit: %d\n", bit);
                printf("valor de bit2: %d\n", bit_2);
                result = hammingDistance(bit, bit_2); // esta dando core dumped
                printf('%d', result);

            printf("O numero de zeros: %d", count_zero);
    fclose(arq);
    fclose(arq2);
}

int hammingDistance(int n1, int n2)
{
    int x = n1 ^ n2;
    int setBits = 0;

    while (x > 0) {
        setBits += x & 1;
        x >>= 1;
        printf("%d", setBits);
    }

    return setBits;
}
