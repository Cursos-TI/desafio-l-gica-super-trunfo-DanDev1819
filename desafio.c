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

    // escolhas do menu (2 atributos diferentes)
    int atr1, atr2;

    // ===== cadastro carta 1 =====
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

    // ===== cadastro carta 2 =====
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

    // mostrando pra conferir
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

    // ===== MENU DINAMICO: escolher 2 atributos diferentes =====
    // 1-Populacao | 2-Area | 3-PIB | 4-Pontos | 5-Densidade (MENOR vence) | 6-PIB per capita
    printf("\n=== Escolha o 1o atributo ===\n");
    printf("1 - Populacao (maior vence)\n");
    printf("2 - Area (maior vence)\n");
    printf("3 - PIB (maior vence)\n");
    printf("4 - Pontos turisticos (maior vence)\n");
    printf("5 - Densidade demografica (MENOR vence)\n");
    printf("6 - PIB per capita (maior vence)\n");
    printf("Opcao: ");
    scanf("%d", &atr1);

    // valida o primeiro 
    switch (atr1) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            break;
        default:
            printf("Opcao invalida para o 1o atributo.\n");
            return 0;
    }

    // segundo menu: nao mostro a opcao ja escolhida
    printf("\n=== Escolha o 2o atributo (diferente do 1o) ===\n");
    if (atr1 != 1) printf("1 - Populacao (maior vence)\n");
    if (atr1 != 2) printf("2 - Area (maior vence)\n");
    if (atr1 != 3) printf("3 - PIB (maior vence)\n");
    if (atr1 != 4) printf("4 - Pontos turisticos (maior vence)\n");
    if (atr1 != 5) printf("5 - Densidade demografica (MENOR vence)\n");
    if (atr1 != 6) printf("6 - PIB per capita (maior vence)\n");
    printf("Opcao: ");
    scanf("%d", &atr2);

    // valida o segundo 
    if (atr2 < 1 || atr2 > 6 || atr2 == atr1) {
        printf("Opcao invalida para o 2o atributo.\n");
        return 0;
    }

    // Atributo 1
    const char *rotulo1 = "";
    int menorVence1 = 0;       // so fica 1 se for densidade
    double v1_a = 0.0, v2_a = 0.0;

    switch (atr1) {
        case 1: rotulo1 = "Populacao";            v1_a = (double)populacao1;      v2_a = (double)populacao2;      menorVence1 = 0; break;
        case 2: rotulo1 = "Area (km2)";           v1_a = area1;                    v2_a = area2;                    menorVence1 = 0; break;
        case 3: rotulo1 = "PIB (reais)";          v1_a = pib1;                     v2_a = pib2;                     menorVence1 = 0; break;
        case 4: rotulo1 = "Pontos turisticos";    v1_a = (double)pontos_turisticos1; v2_a = (double)pontos_turisticos2; menorVence1 = 0; break;
        case 5: rotulo1 = "Densidade (hab/km2)";  v1_a = densidade1;               v2_a = densidade2;               menorVence1 = 1; break;
        case 6: rotulo1 = "PIB per capita (reais)"; v1_a = pib_per_capita1;       v2_a = pib_per_capita2;          menorVence1 = 0; break;
    }

    // Atributo 2
    const char *rotulo2 = "";
    int menorVence2 = 0;
    double v1_b = 0.0, v2_b = 0.0;

    switch (atr2) {
        case 1: rotulo2 = "Populacao";            v1_b = (double)populacao1;      v2_b = (double)populacao2;      menorVence2 = 0; break;
        case 2: rotulo2 = "Area (km2)";           v1_b = area1;                    v2_b = area2;                    menorVence2 = 0; break;
        case 3: rotulo2 = "PIB (reais)";          v1_b = pib1;                     v2_b = pib2;                     menorVence2 = 0; break;
        case 4: rotulo2 = "Pontos turisticos";    v1_b = (double)pontos_turisticos1; v2_b = (double)pontos_turisticos2; menorVence2 = 0; break;
        case 5: rotulo2 = "Densidade (hab/km2)";  v1_b = densidade1;               v2_b = densidade2;               menorVence2 = 1; break;
        case 6: rotulo2 = "PIB per capita (reais)"; v1_b = pib_per_capita1;       v2_b = pib_per_capita2;          menorVence2 = 0; break;
    }

    //  comparo cada atributo individualmente (regra geral: maior vence; densidade: menor vence) 
    const char *venc_atr1 =
        (v1_a == v2_a) ? "Empate"
                       : (menorVence1 ? (v1_a < v2_a ? "Carta 1" : "Carta 2")
                                      : (v1_a > v2_a ? "Carta 1" : "Carta 2"));

    const char *venc_atr2 =
        (v1_b == v2_b) ? "Empate"
                       : (menorVence2 ? (v1_b < v2_b ? "Carta 1" : "Carta 2")
                                      : (v1_b > v2_b ? "Carta 1" : "Carta 2"));

    // somo os dois atributos de cada carta
    double soma_c1 = v1_a + v1_b;
    double soma_c2 = v2_a + v2_b;

    // vencedor final por soma
    const char *vencedor_final =
        (soma_c1 == soma_c2) ? "Empate" : (soma_c1 > soma_c2 ? "Carta 1" : "Carta 2");

    // saida 
    printf("\n=== Comparacao AVANCADA (2 atributos) ===\n");

    // atributo 1
    printf("\nAtributo 1: %s %s\n", rotulo1, menorVence1 ? "(MENOR vence)" : "(maior vence)");
    // imprimo com formato mais adequado dependendo do atributo
    switch (atr1) {
        case 1: case 4:
            printf("Carta 1 - %s: %.0f\n", cidade1, v1_a);
            printf("Carta 2 - %s: %.0f\n", cidade2, v2_a);
            break;
        case 2:
            printf("Carta 1 - %s: %.2f km2\n", cidade1, v1_a);
            printf("Carta 2 - %s: %.2f km2\n", cidade2, v2_a);
            break;
        case 3:
            printf("Carta 1 - %s: %.2f reais\n", cidade1, v1_a);
            printf("Carta 2 - %s: %.2f reais\n", cidade2, v2_a);
            break;
        case 5:
            printf("Carta 1 - %s: %.2f hab/km2\n", cidade1, v1_a);
            printf("Carta 2 - %s: %.2f hab/km2\n", cidade2, v2_a);
            break;
        case 6:
            printf("Carta 1 - %s: %.2f reais\n", cidade1, v1_a);
            printf("Carta 2 - %s: %.2f reais\n", cidade2, v2_a);
            break;
    }
    printf("Vencedora no Atributo 1: %s\n", venc_atr1);

    // atributo 2
    printf("\nAtributo 2: %s %s\n", rotulo2, menorVence2 ? "(MENOR vence)" : "(maior vence)");
    switch (atr2) {
        case 1: case 4:
            printf("Carta 1 - %s: %.0f\n", cidade1, v1_b);
            printf("Carta 2 - %s: %.0f\n", cidade2, v2_b);
            break;
        case 2:
            printf("Carta 1 - %s: %.2f km2\n", cidade1, v1_b);
            printf("Carta 2 - %s: %.2f km2\n", cidade2, v2_b);
            break;
        case 3:
            printf("Carta 1 - %s: %.2f reais\n", cidade1, v1_b);
            printf("Carta 2 - %s: %.2f reais\n", cidade2, v2_b);
            break;
        case 5:
            printf("Carta 1 - %s: %.2f hab/km2\n", cidade1, v1_b);
            printf("Carta 2 - %s: %.2f hab/km2\n", cidade2, v2_b);
            break;
        case 6:
            printf("Carta 1 - %s: %.2f reais\n", cidade1, v1_b);
            printf("Carta 2 - %s: %.2f reais\n", cidade2, v2_b);
            break;
    }
    printf("Vencedora no Atributo 2: %s\n", venc_atr2);

    // somas e resultado final
    printf("\nSoma dos 2 atributos:\n");
    printf("Carta 1 - %s: %.2f\n", cidade1, soma_c1);
    printf("Carta 2 - %s: %.2f\n", cidade2, soma_c2);

    // resultado final da rodada
    if (soma_c1 == soma_c2) {
        printf("\nResultado FINAL: Empate!\n");
    } else {
        // ternario pra decidir a frase final
        const char *nome_vencedora = (soma_c1 > soma_c2) ? cidade1 : cidade2;
        const char *carta_vencedora = (soma_c1 > soma_c2) ? "Carta 1" : "Carta 2";
        printf("\nResultado FINAL: %s (%s) venceu!\n", carta_vencedora, nome_vencedora);
    }

    return 0;
}
// terminei :)
