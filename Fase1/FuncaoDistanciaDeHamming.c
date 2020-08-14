#include <stdio.h>


int main()
{
    open_file();
    printf("\ntudo certo.");
    return 0;
}

void open_file(){
    FILE *arq;
    int result;
    char Str[50];

    arq = fopen("/home/itanu/Documentos/MeusProjetosGit/ICMusicBinary/Fase1/D.B._Ricapito_-_So_Crazy.mp3", "rb");

    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        return;
    }
        int bit;
        int stop = 0;
            while  ( ( bit = fgetc( arq ) ) != EOF )
            {
                printf( "%c", bit );
                stop = stop + 1;
                if (stop == 100) {
                    break;
                }
            }
    fclose(arq);
}
