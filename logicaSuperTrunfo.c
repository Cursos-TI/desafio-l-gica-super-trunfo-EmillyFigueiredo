#include <stdio.h>
#include <locale.h>

#define TOTAL_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CIDADES (TOTAL_ESTADOS * CIDADES_POR_ESTADO)

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Declaração das variáveis para armazenar os dados das cartas
    char codigos[TOTAL_CIDADES][4]; // Códigos como A01, B02
    int populacoes[TOTAL_CIDADES];
    float areas[TOTAL_CIDADES];
    float pibs[TOTAL_CIDADES];
    int pontosTuristicos[TOTAL_CIDADES];
    float densidades[TOTAL_CIDADES];
    float pibPerCapita[TOTAL_CIDADES];

    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int i, j, c = 0;

    printf("=== Cadastro de Cartas - Super Trunfo: Países ===\n");

    // Cadastro das cartas
    for (i = 0; i < TOTAL_ESTADOS; i++) {
        for (j = 1; j <= CIDADES_POR_ESTADO; j++) {
            sprintf(codigos[c], "%c%02d", estados[i], j);
            printf("\nCadastro da cidade %s:\n", codigos[c]);

            printf("Informe a população: ");
            scanf("%d", &populacoes[c]);

            printf("Informe a área (em km²): ");
            scanf("%f", &areas[c]);

            printf("Informe o PIB (em bilhões): ");
            scanf("%f", &pibs[c]);

            printf("Informe o número de pontos turísticos: ");
            scanf("%d", &pontosTuristicos[c]);

            // Cálculo dos indicadores
            densidades[c] = populacoes[c] / areas[c];
            pibPerCapita[c] = pibs[c] / populacoes[c];

            c++;
        }
    }

    // Exibição dos dados cadastrados
    printf("\n=== Cartas Cadastradas ===\n");
    for (i = 0; i < TOTAL_CIDADES; i++) {
        printf("\nCidade %s\n", codigos[i]);
        printf("População: %d\n", populacoes[i]);
        printf("Área: %.2f km²\n", areas[i]);
        printf("PIB: %.2f bilhões\n", pibs[i]);
        printf("Pontos turísticos: %d\n", pontosTuristicos[i]);
        printf("Densidade Populacional: %.2f hab/km²\n", densidades[i]);
        printf("PIB per capita: %.6f bilhões/hab\n", pibPerCapita[i]);
    }

    return 0;
}
