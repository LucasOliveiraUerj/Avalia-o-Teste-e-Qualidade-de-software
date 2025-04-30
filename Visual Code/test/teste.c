// test/test.c
#include "minunit-master/minunit.h"
#include "../src/output/ingresso_zoo_calcul.h"

// Teste da Quantidade

// Teste: quantidade válida (dentro do limite)
MU_TEST(test_quantidade_valida_ok) {
    mu_assert_int_eq(3, quantidadeValida(3));
}

// Teste: quantidade menor que 1 (Fora do Limite)
MU_TEST(test_quantidade_menor) {
    mu_assert_int_eq(-1, quantidadeValida(0));
}

// Teste: quantidade maior que 5 (Fora do Limite)
MU_TEST(test_quantidade_maior) {
    mu_assert_int_eq(-1, quantidadeValida(8));
}

// Teste: Vericação de limite (dentro do limite)
MU_TEST(test_quantidade_limiteMenor_ok) {
    mu_assert_int_eq(1, quantidadeValida(1));
}

// Teste: Verificação de Limite (dentro do limite)
MU_TEST(test_quantidade_limiteMaior_ok) {
    mu_assert_int_eq(5, quantidadeValida(5));
}

// Teste: Verificação de Limite menor 1
MU_TEST(test_quantidade_intervaloMenor) {
    mu_assert_int_eq(-1, quantidadeValida(0));
}

// Teste: Verificação de Limite meinor 5
MU_TEST(test_quantidade_intervaloMaior) {
    mu_assert_int_eq(-1, quantidadeValida(6));
}

// Teste Data Dígitos
MU_TEST(test_data_de_8_digitos) {
    mu_assert_int_eq(10122002, validarDataCompacta(10122002)); // 8 dígitos
}
MU_TEST(test_data_menos_de_8_digitos) {
    mu_assert_int_eq(-1, validarDataCompacta(101202)); // 6 dígitos
}

MU_TEST(test_data_mais_de_8_digitos) {
    mu_assert_int_eq(-1, validarDataCompacta(1234567890)); // 10 dígitos
}

// Teste Data Dígitos
MU_TEST(test_data_limite_menos_de_8_digitos) {
    mu_assert_int_eq(-1, validarDataCompacta(1012024)); // 7 dígitos
}

MU_TEST(test_data_limite_mais_de_8_digitos) {
    mu_assert_int_eq(-1, validarDataCompacta(123456789)); // 9 dígitos
}


//Teste das Datas

// Teste: Data válida no ingressoCalculo (dia, mês e ano corretos)
MU_TEST(test_ingresso_data_valida) {
    mu_assert_int_eq(6072002, ingressoCalculo(6, 7, 2002));  // 6 de julho de 2002
}

// Teste: Dia inválido (dia maior que o permitido no mês)
MU_TEST(test_ingresso_data_dia_invalido) {
    mu_assert_int_eq(-1, ingressoCalculo(39, 5, 2000)); // 39 de maio de 2000 (não existe)
}

// Teste: Dia dentro do limite (mesmo número de dias no mês)
MU_TEST(test_ingresso_data_dia_limite_valido) {
    mu_assert_int_eq(17052000, ingressoCalculo(17, 5, 2000)); // 31 de maio de 2000
}

// Teste: Dia fora do limite (não existe dia 31 no mês de abril)
MU_TEST(test_ingresso_data_dia_limite_invalido) {
    mu_assert_int_eq(-1, ingressoCalculo(32, 4, 2024)); // 32 de maio de 2000  (não existe)
}

// Teste: Data inválida para fevereiro em ano não bissexto
MU_TEST(test_ingresso_data_fevereiro_nao_bissexto) {
    mu_assert_int_eq(-1, ingressoCalculo(29, 2, 2023)); // 29 de fevereiro de 2023 (não é bissexto)
}

// Teste: Data válida para fevereiro em ano bissexto
MU_TEST(test_ingresso_data_fevereiro_bissexto) {
    mu_assert_int_eq(29022024, ingressoCalculo(29, 2, 2024)); // 29 de fevereiro de 2024 (é bissexto)
}

// Teste: Mês Válido
MU_TEST(test_ingresso_data_mes_valido) {
    mu_assert_int_eq(17112000, ingressoCalculo(17, 11, 2000)); // 17 de novembro de 2000
}

// Teste: Mês inválido
MU_TEST(test_ingresso_data_mes_invalido) {
    mu_assert_int_eq(-1, ingressoCalculo(17, 14, 2000)); // mês 14 não existe
}

// Teste: Mês Limite válido (12)
MU_TEST(test_ingresso_data_mes_valido_limite1) {
    mu_assert_int_eq(17122000, ingressoCalculo(17, 12, 2000)); // 17 de Dezembro de 2000
}

// Teste: Mês Limite válido (01)
MU_TEST(test_ingresso_data_mes_valido_limite2) {
    mu_assert_int_eq(17012000, ingressoCalculo(17, 1, 2000)); // 17 de Janeiro de 2000
}

// Teste: Mês Limite inválido (13)
MU_TEST(test_ingresso_data_mes_invalido_limite1) {
    mu_assert_int_eq(-1, ingressoCalculo(17, 13, 2000)); // mes 13 não existe
}

// Teste: Mês Limite inválido (00)
MU_TEST(test_ingresso_data_mes_invalido_limite2) {
    mu_assert_int_eq(-1, ingressoCalculo(17, 00, 2000)); // mes 00 não existe
}

// Teste: Ano inválido (fora do intervalo permitido)
MU_TEST(test_ingresso_data_ano_invalido) {
    mu_assert_int_eq(-1, ingressoCalculo(17, 3, 1800)); // ano fora do intervalo
}

// Teste: Ano válido
MU_TEST(test_ingresso_data_ano_valido) {
    mu_assert_int_eq(17062003, ingressoCalculo(17, 6, 2003)); // 17 de junho de 2003
}

// Teste: Ano Limite válido (2025)
MU_TEST(test_ingresso_data_ano_valido_limite1) {
    mu_assert_int_eq(29042025, ingressoCalculo(29, 4, 2025)); // 29 de abril de 2024
}

// Teste: Ano Limite válido (1901)
MU_TEST(test_ingresso_data_ano_valido_limite2) {
    mu_assert_int_eq(29041901, ingressoCalculo(29, 4, 1901)); // 29 de abril de 1901
}

// Teste: Ano Limite inválido (2026)
MU_TEST(test_ingresso_data_ano_invalido_limite1) {
    mu_assert_int_eq(-1, ingressoCalculo(29, 4, 2026)); // 2026 fora do limite
}

// Teste: Ano Limite inválido (2026)
MU_TEST(test_ingresso_data_ano_invalido_limite2) {
    mu_assert_int_eq(-1, ingressoCalculo(29, 4, 1900)); // 1900 fora do limite 
}

// Grupo de testes
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_quantidade_valida_ok);
    MU_RUN_TEST(test_quantidade_menor);
    MU_RUN_TEST(test_quantidade_maior);
    MU_RUN_TEST(test_quantidade_limiteMenor_ok);
    MU_RUN_TEST(test_quantidade_limiteMaior_ok);
    MU_RUN_TEST(test_quantidade_intervaloMaior);
    MU_RUN_TEST(test_quantidade_intervaloMenor);

    MU_RUN_TEST(test_data_de_8_digitos);
    MU_RUN_TEST(test_data_menos_de_8_digitos);
    MU_RUN_TEST(test_data_mais_de_8_digitos);
    MU_RUN_TEST(test_data_limite_menos_de_8_digitos);
    MU_RUN_TEST(test_data_limite_mais_de_8_digitos);
  

    MU_RUN_TEST(test_ingresso_data_valida);
    MU_RUN_TEST(test_ingresso_data_dia_invalido);
    MU_RUN_TEST(test_ingresso_data_dia_limite_valido);
    MU_RUN_TEST(test_ingresso_data_dia_limite_invalido);
    MU_RUN_TEST(test_ingresso_data_fevereiro_nao_bissexto);
    MU_RUN_TEST(test_ingresso_data_fevereiro_bissexto);
    MU_RUN_TEST(test_ingresso_data_mes_valido);
    MU_RUN_TEST(test_ingresso_data_mes_invalido);
    MU_RUN_TEST(test_ingresso_data_mes_valido_limite1);
    MU_RUN_TEST(test_ingresso_data_mes_valido_limite2);
    MU_RUN_TEST(test_ingresso_data_mes_invalido_limite1);
    MU_RUN_TEST(test_ingresso_data_mes_invalido_limite2);
    MU_RUN_TEST(test_ingresso_data_ano_invalido);
    MU_RUN_TEST(test_ingresso_data_ano_valido);
    MU_RUN_TEST(test_ingresso_data_ano_valido_limite1);
    MU_RUN_TEST(test_ingresso_data_ano_valido_limite2);
    MU_RUN_TEST(test_ingresso_data_ano_invalido_limite1);
    MU_RUN_TEST(test_ingresso_data_ano_invalido_limite2);

}

// Função principal dos testes
int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
