
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int   hc;

    const char bsize = 5;
    char b[bsize];
    char *p = b;
    short valid;

    char input_char;
    short char_read_count = 0;

    do
    {
        printf("Your height: ");
        p = b;
        char_read_count = 0;
        while ((input_char = getchar()) != '\n')
        {
            *p++ = input_char;
            char_read_count++;
            if (char_read_count >= bsize - 1)
            {
                break;
            }
        }
        *p = '\0';

        valid = 1;
        p = b;
        for (int i = 0; i < char_read_count; p++, i++)
        {
            short charIsNoFigure = (*p > '9') || (*p < '0');
            if (charIsNoFigure)
            {
                valid = 0;
                break;
            }
            if (*p == '\0')
            {
                break;
            }
        }
    } while (!valid);

    p = b;
    hc = 0;
    for (int i = 0; i < bsize; p++, i++)
    {
        if (*p == '\0')
        {
            break;
        }
        else
        {
            hc = 10 * hc + (*p - '0');
        }
    }

    hc = hc - 10;

    int rk = 6371;
    int rc = rk * 100000;

    printf("\nDistance is %.2f\n", rk * acos((float)rc / (float)(rc + hc)));

    return 0;
}
