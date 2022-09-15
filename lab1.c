#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
void task1(double * x, double * z)
{
    printf("\nВведите x\t");
    scanf("%lf",&(*x));
    *z = sqrt(abs(3.0 + *x));
    if (*x >= M_PI)
        *z = log(*x);
    else if (*x <= 2.0 * M_PI)
        *z = sin(*x);
}
void task2(double * x, double * l, double * s)
{
    double n = 0.0;
    printf("\nВведите x\t");
    scanf("%lf",&(*x));
    printf("\nВведите количество слагаемых\t");
    scanf("%lf",&(*l));
    while (*l > n)
    {
        n += 1.0;
        *s += (sin(2.0 * n - 1.0) * *x) / (2.0 * n - 1.0);
        printf("\nN = %lf\tS = %lf", n, *s);
    }
}
void task3(double * s, double * a, double * b, unsigned * month)
{
    printf("\nВведите сбережения\t");
    scanf("%lf",&(*s));
    printf("\nВведите стипеднию\t");
    scanf("%lf",&(*a));
    printf("\nВведите затраты за месяц\t");
    scanf("%lf",&(*b));
    *month = 0;
    while (*s + *a - *b > 0.0)
    {
        *month += 1;
        *s += *a - *b;
        *b *= 1.02;
    }
}
int main() {
    double x, z, s, a, b, l;
    unsigned month;
    task1(&x, &z);
    printf("\nX = %lf\tZ = %lf", x, z);
    task2(&x, &l, &s);
    printf("\nX = %lf\tКоличество слагаемых = %lf\tСумма = %lf", x, l, s);
    task3(&s, &a, &b, &month);
    printf("\nСбережения = %lf\tСтипендия = %lf\tЗатраты = %lf\tМесяцев с сбережениями = %u", s, a, b, month);
    return 0;
}
