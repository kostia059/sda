#include <stdio.h>
#include <math.h>

#define pi M_PI

int main()
{
    double n;
    printf("Введіть n=");
    scanf("%lf", &n);
    printf("\n");
    
    long int o = 0;
    o++; ///scanf
    
    double x = 1;
    x /= 3;
    double result = (pi + 2 * x) * (pi + 2 * x) * .25;
    double P = 1;
    o += 10; //=|/=|=|+|*|*|+|*|*|=
    for (int i = 1; i <= n; i++)
    {
        double sum = 0;
        o++; //=
        for (int j = 1; j <= i; j++)
        {
            sum += 2*j - 1;
            o += 3; //+=|*|-
            o += 3; //<=|++|jmp
        }
        o++; //=

        double numerator = (pi + 2*x) * (pi + 2*x);
        o += 6; //=|+|*|*|+|*
        double denominator = 4 * pi * pi * sum;
        o += 4; //=|*|*|*
        double fraction = numerator / denominator;
        o += 2; //=|/
        double factor = 1 - fraction;
        o += 2; //=|-
        
        P *= factor;
        o++; //*=
        o += 3; //<=|++|jmp
    }
    o++; //=
    P *= P;
    result *= P;
    o += 2; //*=|*=

    printf("P=%0.7f\n", result);
    printf("Кількість операцій=%d", o);
    return 0;
}
