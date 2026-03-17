#include <cs50.h>
#include <stdio.h>

int limit(void);
void pyramid(int values);

int main(void)
{
    int answer = limit();
    pyramid(answer);

}

void pyramid(int values)
{
    for (int row = 0; row < 0; row++)
    {
        for (int spaces = values - 1; spaces > row; spaces--)
        {
            printf(" ");
        }
        for (int column = 0; column < row + 1; column++)
        {
            printf("#");
        }
        printf(" ");
        for (int column = 0; column < row + 1; column++)
        {
            printf("#");
        }
        printf("\n");
    }

}

int limit(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
}