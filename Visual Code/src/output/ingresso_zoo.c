#include <stdio.h>
#include "ingresso_zoo_calcul.h"

int main() {
    int quantidade, dataCompacta;
    int dia, mes, ano, idade;
    int precoUnitario, precoTotal = 0;
    int criancas = 0, adultos = 0, idosos = 0;

    printf("Quantidade de bilhetes (1 a 5): ");
    scanf("%d", &quantidade);

    quantidade = quantidadeValida(quantidade);
    if (quantidade == -1) {
        printf("Erro: quantidade de bilhetes inválida. (Permitido de 1 a 5)\n");
        return 1;
    }

    for (int i = 1; i <= quantidade; i++) {
        printf("Data nascimento visitante %d (DDMMAAAA): ", i);
        scanf("%d", &dataCompacta);

        // Valida estrutura e lógica da data
        if (validarDataCompacta(dataCompacta) == -1) {
            printf("Data inválida. Tente novamente.\n\n");
            i--;
            continue;
        }

        // Só extrai se a data foi validada
        dia = dataCompacta / 1000000;
        mes = (dataCompacta / 10000) % 100;
        ano = dataCompacta % 10000;

        idade = calcularIdade(dia, mes, ano);
        precoUnitario = precoPorIdade(idade);
        precoTotal += precoUnitario;

        // Contadores
        if (idade <= 12) criancas++;
        else if (idade >= 60) idosos++;
        else adultos++;

        printf("Visitante %d - Idade: %d anos - Preço: R$ %d\n\n", i, idade, precoUnitario);
    }

    // Resumo final (fora do laço)
    printf("Resumo:\n");
    printf("Crianças: %d\nAdultos: %d\nIdosos: %d\nTotal: R$ %d\n", criancas, adultos, idosos, precoTotal);

    return 0;
}
