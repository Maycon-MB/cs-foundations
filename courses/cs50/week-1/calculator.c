#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_int("What's X? ");
    float y = get_int("What's Y? ");

    printf("%f0.50\n", x / y);
}