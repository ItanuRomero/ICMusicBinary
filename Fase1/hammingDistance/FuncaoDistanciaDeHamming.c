#include <stdio.h>


int main()
{
    analyse_file();
    return 0;
}

void analyse_file(){
        int bit[100], bit_2[100], percentage[1000];
        FILE *arq;
        FILE *arq2;
        int result, contador = 0, i = 0;
        float similaridade;

        // Faz leitura dos arquivos
        arq = fopen("./D.B._Ricapito_-_So_Crazy.mp3", "rb");
        arq2 = fopen("./The_Devil_Music_Co._-_Head_Over_Heels.mp3", "rb");

            // Verifica se houve erro na leitura
            if (readingFileError(arq, arq2) == 1) {
                printf("\nDetectamos um erro ao abrir os arquivos!!\nfavor verificar e tentar novamente\n\n");
                return;
            };

            // Enquanto os arquivos ainda tem dados a serem lidos
            while (!feof(arq) || !feof(arq2)) {

                fread( bit, sizeof(int), 100, arq );
                fread( bit_2, sizeof(int), 100, arq2 );

                    // Vai correr pelos valores de 0 a 100 dos vetores bit e bit_2
                    while (contador <= 100) {

                        if ( bit[contador] == NULL || bit_2[contador] == NULL )
                        {
                            printf("valor nulo!\n");
                        }
                        printf("valor de bit: %d\n", bit[contador]);
                        printf("valor de bit2: %d\n", bit_2[contador]);

                        result = hammingDistance(bit[contador], bit_2[contador]);
                        printf("-Result = %d-\n", result);

                        similaridade = (100 * result) / 32;
                        printf("Sim Hamming = %f%%\n", similaridade);

                        contador = contador + 1;
                    }

                //retorna contador para 0 para que o while possa contar novamente
                contador = 0;

                i++;
                printf("\n%d\n", i);
                }

    fclose(arq);
    fclose(arq2);
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
