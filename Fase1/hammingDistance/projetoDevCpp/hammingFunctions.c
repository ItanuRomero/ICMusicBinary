#include <stdio.h>
#include "hammingFunctions.h"

// Realiaza a analise
float analyse_file(char arq_name1, char arq_name2)
{
    FILE *arq;
    FILE *arq2;
    int bit[BLOCO], bit_2[BLOCO], teste1, teste2, result, contador = 0, i = 0, divisor = 0;
    double similaridade, acumulador = 0;
    float media;

    // Faz leitura dos arquivos
    arq = fopen(arq_name1, "rb");
    arq2 = fopen(arq_name2, "rb");

    // Verifica se houve erro na leitura
    if (readingFileError(arq, arq2) == 1) {
        printf("\nDetectamos um erro ao abrir os arquivos!!\nfavor verificar e tentar novamente\n\n");
        return 1;
    };

        teste1 = fread( bit, sizeof(int), BLOCO, arq );
        teste2 = fread( bit_2, sizeof(int), BLOCO, arq2 );

        printf("\n\nvalor de teste1: %d valor de teste2: %d\n\n", teste1, teste2);



        // Enquanto os arquivos ainda tem dados a serem lidos
        while (teste1 == BLOCO && teste2 == BLOCO) {

                // Vai correr pelos valores de 0 a 100 dos vetores bit e bit_2
                while (contador <= BLOCO) {

                    printf("valor de bit: %d\n", bit[contador]);
                    printf("valor de bit2: %d\n", bit_2[contador]);

                    result = hammingDistance(bit[contador], bit_2[contador]);
                    printf("-Result = %d-\n", result);

                    similaridade = (100 * result) / 32;
                    similaridade = 100 - similaridade;

                    // Para mostrar o valor double temos que usar %lf
                    printf("Sim Hamming = %lf%%\n", similaridade);

                    acumulador = acumulador + similaridade;

                    contador = contador + 1;
                }

            divisor = contador + divisor
            //retorna contador para 0 para que o while possa contar novamente
            contador = 0;


            i++;
            printf("bloco de numero %d lido corretamente.\n", i);

            teste1 = fread(bit, sizeof(int), BLOCO, arq );
            teste2 = fread(bit_2, sizeof(int), BLOCO, arq2 );

        }
    media = acumulador / divisor;

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
// Salva os dados para analise em um arquivo externo
void save_data(float media)
{
    FILE *arq;

    arq = fopen("./testes/arquivoDeAnalise.txt", "a");

        fprintf(arq, "%f\n", media);

    fclose(arq);
}

char name_archive(int number)
{
    int number_archive = number, number_of_char = 30;
    char name_for_analisis[number_of_char];
    printf("Favor inserir o nome do arquivo %d\n com o maximo de %d caracteres! ", number_archive, number_of_char);
    printf("(Digite 'padrao' para seguir com dados internos\n")
    scanf("%s", &name_for_analisis);

    return name_for_analisis;
}
