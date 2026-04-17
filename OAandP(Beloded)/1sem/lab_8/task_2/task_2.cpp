//#include <stdio.h>
//#include <conio.h> 
//
//void main()
//{
//    char ch;
//    float sv, x, sum = 0;
//    float count = 0;
//    do
//    {
//        printf("Enter x:");
//        scanf_s("%f", &x);
//        sum += x;
//        count++;
//        sv = sum / count;
//        printf("sv=%1.3f\n", sv);
//        printf("if continue input 'y' else 'n' ");
//        ch = _getch();
//    } while (ch != 'n');
//}

#include <stdio.h>
#include <cmath>

void main()
{
    float sum = 0, a, t, p;
    for (int n = 2; n < 10; n++)
    {
        t = pow(n, log((float)n));
        p = pow(log((float)n), n);
        a = t / p;
        sum += a;
    }
    printf("S=%f\n", sum);
}


