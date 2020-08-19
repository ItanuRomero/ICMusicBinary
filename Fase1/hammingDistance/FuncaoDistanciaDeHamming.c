#include <stdio.h>


int main()
{
    open_file();
    printf("\ntudo certo.");
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
        int stop = 0;

        arq = fopen("./D.B._Ricapito_-_So_Crazy.mp3", "rb");
        arq2 = fopen("./The_Devil_Music_Co._-_Head_Over_Heels.mp3", "rb");

            while  ( ( bit = fgetc( arq ) ) != EOF )
            {
                while ( ( bit_2 = fgetc( arq2 ) ) != EOF )
                {
                    //verifica se o valor eh nulo, caso correto, desconsidera essa volta
                    if ( bit == NULL || bit_2 == NULL )
                    {
                        printf("valor nulo!\n");
                        stop = (stop - 1);
                        break;
                    }
                    printf("%c", bit);
                    printf("%c", bit_2);

                    //faz a operacao ou exclusivo
                    xor = (bit ^ bit_2);

                    if ( xor == 0 )
                    {
                        //caso o resultado for zero, ele aumenta 1 no contador
                        printf("xor igual a 0.\n");
                        count_zero = (count_zero + 1);
                    } else
                    {
                        if ( xor == 1 )
                        {
                            printf("xor igual a 1.\n");
                        }
                    }
                    break;
                }
                stop = (stop + 1);
                if (stop == 10)
                {
                    break;
                }

            }
            printf("O numero de zeros: %d", count_zero);
}
