#include <time.h>

int quantidadeValida(int q) {
    if (q < 1 || q > 5)
        return -1;
    else
        return q;
}
//Verificação de Ano Bissexto 
int ehBissexto(int ano) {
    return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));
}
int validarDataCompacta(int dataCompacta) {
    // Verifica se o número tem exatamente 8 dígitos
    int temp = dataCompacta;
    int digitos = 0;
    while (temp > 0) {
        temp /= 10;
        digitos++;
    }
    if (digitos != 8) return -1;

    // Extrai os componentes da data
    int dia = dataCompacta / 1000000;
    int mes = (dataCompacta / 10000) % 100;
    int ano = dataCompacta % 10000;

    return ingressoCalculo(dia, mes, ano);
}

// Compacta data se válida, retorna -1 se inválida
int ingressoCalculo(int d, int m, int a) {
    int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (a <= 1900 || a >= 2026) return -1;
    if (m < 1 || m > 12) return -1;

    // Ajusta fevereiro se for ano bissexto
    if (m == 2 && ehBissexto(a)) {
        diasNoMes[1] = 29;
    }

    if (d < 1 || d > diasNoMes[m - 1]) return -1;

    return d * 1000000 + m * 10000 + a;
}

// Calcula idade com base na data atual do sistema
int calcularIdade(int dia, int mes, int ano) 
{
    time_t t = time(NULL);
    struct tm atual = *localtime(&t);
    int idade = atual.tm_year + 1900 - ano;

    if ((atual.tm_mon + 1) < mes || ((atual.tm_mon + 1) == mes && atual.tm_mday < dia)) 
    {
        idade--;
    }

    return idade;
}

// Retorna o preço com base na idade
int precoPorIdade(int idade) {
    if (idade <= 12)
    {
        return 10;
    }
    if (idade >= 60)
    {     
        return 15;
    }    

    return 30;
}
