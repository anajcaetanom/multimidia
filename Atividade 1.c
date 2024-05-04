#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definindo os tamanhos padronizados pelas abreviações
#define kb 1024
#define mb 1024*kb


void modo_aleatorio(char *filename) {
    FILE *arquivo = fopen(filename, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // configurando o tamanho do arquivo
    int TAM = 10 * mb;

    for (int i = 0; i<TAM; i++) {
        // unsigned char possui 1 byte como um char comum, mas vai de 0 à 255.
        // pq funciona? pq letras são números! ao menos, para o computador.
        unsigned char aux = rand()%256; // números de 0 à 255
        fwrite(&aux, sizeof(unsigned char), 1, arquivo);
    }

    fclose(arquivo);
}


void modo_aleatorio_restrito(char *filename) {
    FILE *arquivo = fopen(filename, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // configurando o tamanho do arquivo
    int TAM = 10 * mb;

    for (int i = 0; i<TAM; i++) {
        unsigned char aux = rand()%26; // números de 0 à 25
        fwrite(&aux, sizeof(unsigned char), 1, arquivo);
    }

    fclose(arquivo);
}


void modo_nao_aleatorio(char *filename) {
    // pega o tamanho do arquivo (em mb, considerando apenas a parte inteira) no momento da iteração e insere no arquivo
    FILE *arquivo = fopen(filename, "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    unsigned char j = 0;

    // configurando o tamanho do arquivo
    int TAM = 10 * mb;

    for (int i = 0; i<TAM; i++) {
        fwrite(&j, sizeof(unsigned char), 1, arquivo);

        if ((j+1) * mb == i) j++;
    }

    fclose(arquivo);
}

// MAIN
int main(){
    srand(time(NULL));

    modo_aleatorio("aleatorio.bin");
    modo_aleatorio_restrito("aleatorio_restrito.bin");
    modo_nao_aleatorio("nao_aleatorio.bin");

    return 0;
}
