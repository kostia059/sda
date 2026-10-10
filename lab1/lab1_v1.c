#include <stdio.h>


int main()
{
    double x;
    printf("x=");
    scanf("%lf", &x);

    double result;
    
    if (x > 14)
    {
        result = -4*x*x*x + 3*x - 7;
        printf("x is in D2 y=%lf\n", result);

    }
    else if (x > -13)
    {
        if (x <= -3)
        {
            result = -4*x*x*x + 3*x - 7;
            printf("x is in D2 y=%lf\n", result);
        }
        else if (x >=2)
        {
            if (x <= 7)
            {
                result = x*x*x + 14;
                printf("x is in D1; y=%lf\n", result);
            }
            else
            {
                printf("function is undefined for x=%lf\n", x);
            }
        }
        else
        {
            printf("function is undefined for x=%lf\n", x);
        }
    }
    else
    {
        printf("function is undefined for x=%lf\n", x);
    }

    return 0;
}
