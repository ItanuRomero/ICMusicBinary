#include <stdio.h>


int main()
{
    analyse_file();
    return 0;
}

void analyse_file(){
        int bit[100], bit_2[100];
        FILE *arq;
        FILE *arq2;
        int count_zero = 0;
        int result, contador = 0;

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

            fread( bit, sizeof(int), 100, arq );
            fread( bit_2, sizeof(int), 100, arq2 );
                while (contador <= 100) {

                    if ( bit[contador] == NULL || bit_2[contador] == NULL )
                    {
                        printf("valor nulo!\n");
                    }
                    printf("valor de bit: %d\n", bit[contador]);
                    printf("valor de bit2: %d\n", bit_2[contador]);
                    result = hammingDistance(bit[contador], bit_2[contador]);
                    printf("resultado: %d\n", result);

                    printf("-Result = %d-\n", result);

                    printf("Sim Hamming = %f", (32 - result)/32);

                    contador = contador + 1;
                }


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

    return setBits; // numero bits DIFERENTES na amostra
}
