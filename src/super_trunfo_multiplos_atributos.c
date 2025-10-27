#include <stdio.h>

int main() {
    /* =========================
       CARTAS (substitua pelos seus dados)
       ========================= */
    char pais1[50]  = "Brasil";
    int  populacao1 = 203080000;
    float area1     = 8515767.0f;
    float pib1      = 9700.0f;   /* em bilhoes de reais (exemplo) */
    int  pontos1    = 45;

    char pais2[50]  = "Argentina";
    int  populacao2 = 45600000;
    float area2     = 2780400.0f;
    float pib2      = 3200.0f;   /* em bilhoes de reais (exemplo) */
    int  pontos2    = 30;

    /* derivados */
    float dens1 = 0.0f, dens2 = 0.0f;
    float pcap1 = 0.0f, pcap2 = 0.0f;

    if (area1 > 0.0f) dens1 = (float)populacao1 / area1; else dens1 = 0.0f;
    if (area2 > 0.0f) dens2 = (float)populacao2 / area2; else dens2 = 0.0f;

    if (populacao1 > 0) pcap1 = (pib1 * 1e9f) / (float)populacao1; else pcap1 = 0.0f;
    if (populacao2 > 0) pcap2 = (pib2 * 1e9f) / (float)populacao2; else pcap2 = 0.0f;

    /* =========================
       ESCOLHA DE 2 ATRIBUTOS
       2-População | 3-Área | 4-PIB | 5-Pontos | 6-Densidade | 7-PIB per capita
       ========================= */
    int op1 = -1, op2 = -1;
    int ok;

    /* menu 1 (usa switch + default) */
    do {
        printf("\n-- Escolha o 1o atributo --\n");
        printf("2 - Populacao (maior vence)\n");
        printf("3 - Area (maior vence)\n");
        printf("4 - PIB (maior vence)\n");
        printf("5 - Pontos turisticos (maior vence)\n");
        printf("6 - Densidade demografica (menor vence)\n");
        printf("7 - PIB per capita (maior vence)\n");
        printf("Opcao: ");
        if (scanf("%d", &op1) != 1) { printf("Entrada invalida.\n"); return 0; }

        ok = 1;
        switch (op1) {
            case 2: case 3: case 4: case 5: case 6: case 7:
                break;
            default:
                printf("Opcao invalida.\n");
                ok = 0;
                break;
        }
    } while (!ok);

    /* menu 2 (dinamico: esconde o escolhido no 1o) */
    do {
        printf("\n-- Escolha o 2o atributo (diferente do 1o) --\n");
        if (op1 != 2) printf("2 - Populacao (maior vence)\n");
        if (op1 != 3) printf("3 - Area (maior vence)\n");
        if (op1 != 4) printf("4 - PIB (maior vence)\n");
        if (op1 != 5) printf("5 - Pontos turisticos (maior vence)\n");
        if (op1 != 6) printf("6 - Densidade demografica (menor vence)\n");
        if (op1 != 7) printf("7 - PIB per capita (maior vence)\n");
        printf("Opcao: ");
        if (scanf("%d", &op2) != 1) { printf("Entrada invalida.\n"); return 0; }

        ok = 1;
        switch (op2) {
            case 2: case 3: case 4: case 5: case 6: case 7:
                if (op2 == op1) { printf("Nao pode repetir o atributo.\n"); ok = 0; }
                break;
            default:
                printf("Opcao invalida.\n");
                ok = 0;
                break;
        }
    } while (!ok);

    /* =========================
       CAPTURA DOS VALORES (como float)
       ========================= */
    float a1c1 = 0.0f, a1c2 = 0.0f;  /* atributo 1: carta1/carta2 */
    float a2c1 = 0.0f, a2c2 = 0.0f;  /* atributo 2: carta1/carta2 */

    /* atributo 1 */
    switch (op1) {
        case 2: a1c1 = (float)populacao1; a1c2 = (float)populacao2; break;
        case 3: a1c1 = area1;             a1c2 = area2;             break;
        case 4: a1c1 = pib1;              a1c2 = pib2;              break;
        case 5: a1c1 = (float)pontos1;    a1c2 = (float)pontos2;    break;
        case 6: a1c1 = dens1;             a1c2 = dens2;             break;
        case 7: a1c1 = pcap1;             a1c2 = pcap2;             break;
        default: break;
    }
    /* atributo 2 */
    switch (op2) {
        case 2: a2c1 = (float)populacao1; a2c2 = (float)populacao2; break;
        case 3: a2c1 = area1;             a2c2 = area2;             break;
        case 4: a2c1 = pib1;              a2c2 = pib2;              break;
        case 5: a2c1 = (float)pontos1;    a2c2 = (float)pontos2;    break;
        case 6: a2c1 = dens1;             a2c2 = dens2;             break;
        case 7: a2c1 = pcap1;             a2c2 = pcap2;             break;
        default: break;
    }

    /* =========================
       COMPARACOES INDIVIDUAIS
       (densidade: menor vence)
       ========================= */
    int c1VenceA1 = (op1 == 6) ? (a1c1 < a1c2) : (a1c1 > a1c2);
    int c1VenceA2 = (op2 == 6) ? (a2c1 < a2c2) : (a2c1 > a2c2);

    /* =========================
       SOMA DOS ATRIBUTOS + RESULTADO FINAL
       ========================= */
    float soma1 = a1c1 + a2c1;
    float soma2 = a1c2 + a2c2;

    int final; /* -1 = empate, 1 = carta1, 0 = carta2 */
    if (soma1 > soma2) final = 1;
    else if (soma1 < soma2) final = 0;
    else final = -1;

    /* =========================
       EXIBICAO DO RESULTADO
       ========================= */
    printf("\n===== RESULTADO =====\n");
    printf("Cartas: %s vs %s\n", pais1, pais2);

    /* nomes dos atributos impressos direto (sem sprintf) */
    printf("\nAtributo 1: ");
    if (op1 == 2) printf("Populacao\n");
    else if (op1 == 3) printf("Area (km2)\n");
    else if (op1 == 4) printf("PIB (bilhoes)\n");
    else if (op1 == 5) printf("Pontos turisticos\n");
    else if (op1 == 6) printf("Densidade (hab/km2)\n");
    else if (op1 == 7) printf("PIB per capita (R$)\n");
    printf(" - %s: %.2f\n - %s: %.2f\n", pais1, a1c1, pais2, a1c2);
    if (a1c1 == a1c2) printf(" -> Vencedor do Atributo 1: Empate\n");
    else printf(" -> Vencedor do Atributo 1: %s\n", c1VenceA1 ? pais1 : pais2);

    printf("\nAtributo 2: ");
    if (op2 == 2) printf("Populacao\n");
    else if (op2 == 3) printf("Area (km2)\n");
    else if (op2 == 4) printf("PIB (bilhoes)\n");
    else if (op2 == 5) printf("Pontos turisticos\n");
    else if (op2 == 6) printf("Densidade (hab/km2)\n");
    else if (op2 == 7) printf("PIB per capita (R$)\n");
    printf(" - %s: %.2f\n - %s: %.2f\n", pais1, a2c1, pais2, a2c2);
    if (a2c1 == a2c2) printf(" -> Vencedor do Atributo 2: Empate\n");
    else printf(" -> Vencedor do Atributo 2: %s\n", c1VenceA2 ? pais1 : pais2);

    printf("\nSoma dos atributos:\n");
    printf(" - %s: %.2f\n - %s: %.2f\n", pais1, soma1, pais2, soma2);

    if (final == -1) {
        printf("\nResultado final: Empate!\n");
    } else if (final == 1) {
        printf("\nResultado final: %s venceu!\n", pais1);
    } else {
        printf("\nResultado final: %s venceu!\n", pais2);
    }

    return 0;
}
