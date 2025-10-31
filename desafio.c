#include <stdio.h>

int main() {
    // dados da carta 1
    char estado1[10], codigo1[10], cidade1[50];
    unsigned long int populacao1;   
    int pontos_turisticos1;
    double area1, pib1;             
    double densidade1, pib_per_capita1;
    float super_poder1;

    // dados da carta 2
    char estado2[10], codigo2[10], cidade2[50];
    unsigned long int populacao2;
    int pontos_turisticos2;
    double area2, pib2;
    double densidade2, pib_per_capita2;
    float super_poder2;

    // ===== carta 1 =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf("%s", estado1);

    printf("Codigo (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da cidade: ");
    scanf("%s", cidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km2): ");
    scanf("%lf", &area1);

    
    printf("PIB (em BILHOES): ");
    scanf("%lf", &pib1);
    pib1 = pib1 * 1000000000.0;  

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);

    // contas da carta 1
    densidade1 = populacao1 / area1;
    pib_per_capita1 = pib1 / populacao1;
    super_poder1 = (float)populacao1
                 + (float)area1
                 + (float)pib1
                 + (float)pontos_turisticos1
                 + (float)pib_per_capita1
                 + (float)(1.0 / densidade1);

    // ===== carta 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf("%s", estado2);

    printf("Codigo (ex: A01): ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    scanf("%s", cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km2): ");
    scanf("%lf", &area2);

    printf("PIB (em BILHOES): ");
    scanf("%lf", &pib2);
    pib2 = pib2 * 1000000000.0;

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // contas da carta 2
    densidade2 = populacao2 / area2;
    pib_per_capita2 = pib2 / populacao2;
    super_poder2 = (float)populacao2
                 + (float)area2
                 + (float)pib2
                 + (float)pontos_turisticos2
                 + (float)pib_per_capita2
                 + (float)(1.0 / densidade2);

    // mostrando tudo antes de comparar (fica mais fácil de ver se deu certo)
    printf("\n=============================\n");
    printf("Carta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2lf km2\n", area1);
    printf("PIB: %.2lf reais\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2lf hab/km2\n", densidade1);
    printf("PIB per Capita: %.2lf reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2lf km2\n", area2);
    printf("PIB: %.2lf reais\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2lf hab/km2\n", densidade2);
    printf("PIB per Capita: %.2lf reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // ===== parte do desafio novo =====
    // vou comparar por populacao
    printf("\n=== Comparacao de cartas (Atributo: Populacao) ===\n");
    printf("Carta 1 - %s (%s): %lu\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu\n", cidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    // deixei as comparações antigas aqui só pra testar outros atributos rápido
    printf("\n=== Comparacoes rapidas (1 = carta 1 venceu) ===\n");
    printf("Populacao (maior vence): %d\n", populacao1 > populacao2);
    printf("Area (maior vence): %d\n", area1 > area2);
    printf("PIB (maior vence): %d\n", pib1 > pib2);
    printf("Pontos Turisticos (maior vence): %d\n", pontos_turisticos1 > pontos_turisticos2);
    printf("PIB per Capita (maior vence): %d\n", pib_per_capita1 > pib_per_capita2);
    printf("Super Poder (maior vence): %d\n", super_poder1 > super_poder2);
    // na densidade é o contrário: ganha quem tem MENOS
    printf("Densidade Populacional (MENOR vence): %d\n", densidade1 < densidade2);

    return 0;
}
