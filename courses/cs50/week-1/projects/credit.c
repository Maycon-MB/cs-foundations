#include <cs50.h>
#include <stdio.h>

// Protótipos das funções
void luhn(long card_number);
long get_number(void);

int main(void)
{
    // Obtém a entrada do usuário e inicia o processamento
    long answer = get_number();
    luhn(answer);
}

void luhn(long card_number)
{
    // Variáveis de controle de estado (a "memória" do programa)
    int total_sum = 0;
    int position = 1;     // Rastreia a posição do dígito da direita para a esquerda
    int first_digits = 0; // Armazenará os prefixos para identificar a bandeira

    while (card_number > 0)
    {
        // Extrai o último dígito atual usando o resto da divisão por 10
        long last_number = card_number % 10;

        // Captura os primeiros dígitos antes que o número seja totalmente "triturado"
        // A trava 'first_digits == 0' garante que guardamos apenas o valor mais à esquerda
        if ((card_number > 0 && card_number <= 99) && (first_digits == 0))
        {
            first_digits = card_number;
        }

        // Remove o último dígito para a próxima rodada do loop
        card_number = card_number / 10;

        // Algoritmo de Luhn: Processamento alternado baseado na posição
        if (position % 2 == 0)
        {
            // Multiplica cada segundo dígito por 2 e soma os produtos dos algarismos
            int multiplication = last_number * 2;
            int sum_digits = (multiplication / 10) + (multiplication % 10);
            total_sum = total_sum + sum_digits;
        }
        else
        {
            // Soma simples para os dígitos nas posições ímpares
            total_sum = total_sum + last_number;
        }
        position++;
    }

    // Validação final: A soma total deve terminar em 0 (divisível por 10)
    if (total_sum % 10 == 0)
    {
        // AMEX: 15 dígitos, começa com 34 ou 37
        if (position - 1 == 15 && (first_digits == 34 || first_digits == 37))
        {
            printf("AMEX\n");
        }
        // MASTERCARD: 16 dígitos, começa entre 51 e 55
        else if (position - 1 == 16 && (first_digits >= 51 && first_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        // VISA: 13 ou 16 dígitos, começa com 4
        else if ((position - 1 == 13 || position - 1 == 16) && (first_digits / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_number(void)
{
    long number;
    // Garante que o número do cartão não seja negativo
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);
    return number;
