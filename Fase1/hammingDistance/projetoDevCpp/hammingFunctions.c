#include <stdio.h>
#include "hammingFunctions.h"

// Realiaza a analise
float analyse_file()
{
        int bit[BLOCO], bit_2[BLOCO], teste1, teste2, result, contador = 0, i = 0;
        FILE *arq;
        FILE *arq2;
        double acumulador = 0;
        double similaridade, media;

        // Faz leitura dos arquivos
        arq = fopen("./testes/texto01.txt", "rb");
        arq2 = fopen("./testes/texto02.txt", "rb");

            // Verifica se houve erro na leitura
            if (readingFileError(arq, arq2) == 1) {
                printf("\nDetectamos um erro ao abrir os arquivos!!\nfavor verificar e tentar novamente\n\n");
                return 1;
            };

            teste1 = fread( bit, sizeof(int), BLOCO, arq );
            teste2 = fread( bit_2, sizeof(int), BLOCO, arq2 );

            printf("\n\n%d %d\n\n", teste1, teste2);



            // Enquanto os arquivos ainda tem dados a serem lidos
            while (teste1 == BLOCO && teste2 == BLOCO) {

            	    // Vai correr pelos valores de 0 a 100 dos vetores bit e bit_2
                    while (contador <= BLOCO) {

                        /*if ( bit[contador] == EOF || bit_2[contador] == EOF )
                        {
                            printf("valor nulo!\n");
                        }*/

                        printf("valor de bit: %d\n", bit[contador]);
                        printf("valor de bit2: %d\n", bit_2[contador]);

                        result = hammingDistance(bit[contador], bit_2[contador]);
                        printf("-Result = %d-\n", result);

                        similaridade = (100 * result) / 32;
                        similaridade = 100 - similaridade;

                        printf("Sim Hamming = %f%%\n", similaridade);

                        acumulador = acumulador + similaridade;

                        contador = contador + 1;
                    }

                //retorna contador para 0 para que o while possa contar novamente
                contador = 0;

                i++;
                printf("\n%d\n", i);

                teste1 = fread(bit, sizeof(int), BLOCO, arq );
                teste2 = fread(bit_2, sizeof(int), BLOCO, arq2 );

            }
            media = acumulador / contador;

    fclose(arq);
    fclose(arq2);
    return media;
}

// Retorna o numero de bits DIFERENTES na amostra
int hammingDistance(int n1, int n2)
{
    int x = n1 ^ n2;
    int setBits = 0;

    while (x > 0) {
        setBits += x & 1;
        x >>= 1;
    }

    return setBits;
}

// Verifica se um dos arquivos nao pode ser lido
int readingFileError(FILE *arch1, FILE *arch2)
{
    int retornar;
    if (arch1 == NULL || arch2 == NULL){
        printf("\nErro na abertura de um dos arquivos!!\n");
        retornar = 1;
    }
    else {
        printf("Nenhum erro");
        retornar = 0;
    }
    return retornar;
}

void save_data(float media)
{
    FILE *arq;

    arq = fopen("./testes/arquivoDeAnalise.txt", "a");

        fprintf(arq, "%f\n", media);

    fclose(arq);
}
