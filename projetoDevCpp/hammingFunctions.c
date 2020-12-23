#include <stdio.h>
#include <string.h>
#include "hammingFunctions.h"

// Realiaza a analise
float analyse_file(int shift)
{
    FILE *arq;
    FILE *arq2;
    int bit[BLOCO], bit_2[BLOCO];
    int teste1, teste2, result, contador = 0, i = 0, divisor = 0, contador_espera = 0;
    double similaridade, acumulador = 0;
    float media;

        // colocar os paths do arquivo a ser analizado
        char name_1[QUANT_CHAR], name_2[QUANT_CHAR];
        int cont;

        for(cont = 1; cont <= 2; ++cont){
            printf("Favor inserir o nome do arquivo %d com o maximo de %d caracteres! ", cont, QUANT_CHAR);
            printf("(Digite 'padrao' para seguir com dados internos\n");
            if (cont == 1){
                scanf("%s", name_1);
            } else {
                scanf("%s", name_2);
            }
        }

        // Valor padrao para testes
        if (strcmp(name_1, "padrao") == 0) {
            strcpy(name_1, "./testes/live.mid");
        }
        if (strcmp(name_2, "padrao") == 0) {
            strcpy(name_2, "./testes/original.mid");
        }	

    // Faz leitura dos arquivos
    arq = fopen(name_1, "rb");
    arq2 = fopen(name_2, "rb");

    // Verifica se houve erro na leitura
    if (readingFileError(arq, arq2) == 1) {
        printf("\nDetectamos um erro ao abrir os arquivos!!\nfavor verificar e tentar novamente\n\n");
        return 1;
    };
    
    	// Inclusao de um shift caso necessario
    	if (shift != 0) {
			save_data(shift);	
			while (contador_espera < shift) {
				teste1 = fread( bit, sizeof(int), BLOCO, arq );
				contador_espera = contador_espera + 1;
			}
		}

        teste1 = fread( bit, sizeof(int), BLOCO, arq );
        teste2 = fread( bit_2, sizeof(int), BLOCO, arq2 );

        printf("\n\nvalor de teste1: %d valor de teste2: %d\n\n", teste1, teste2);



        // Enquanto os arquivos ainda tem dados a serem lidos
        while (teste1 == BLOCO && teste2 == BLOCO) {

                // Vai correr pelos valores de 0 a 100 dos vetores bit e bit_2
                while (contador < BLOCO) {

                    printf("valor de bit: %d\n", bit[contador]);
                    printf("valor de bit2: %d\n", bit_2[contador]);

                    result = hammingDistance(bit[contador], bit_2[contador]);
                    printf("-Result = %d-\n", result);

                    similaridade = (100 * result) / QUANT_BIT;
                    similaridade = 100 - similaridade;

                    // Para mostrar o valor double temos que usar %lf
                    printf("Sim Hamming = %lf%%\n", similaridade);

                    acumulador = acumulador + similaridade;

                    contador = contador + 1;
                }

            divisor = contador + divisor;
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

// Verifica se houve erro na abertura de arquivos
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
void save_data(float dado)
{
    FILE *arq;

    arq = fopen("./testes/arquivoDeAnalise.txt", "a");

        fprintf(arq, "%f\n", dado);

    fclose(arq);
}

