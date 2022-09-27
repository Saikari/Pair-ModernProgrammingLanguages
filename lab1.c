#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
void task1(const double * x, double * z)
{
    printf("\nВведите x\t");
    scanf_s("%lf",&(*x));
    if (*x >= M_PI)
        *z = log(*x);
    else if (*x <= -2.0 * M_PI)
        *z = sin(*x);
    else
        *z = sqrt(fabs(3.0 + *x));
}
void task2(const double * x, const double * l, double * s)
{
    printf("\nВведите x\t");
    scanf_s("%lf",&(*x));
    printf("\nВведите эпсилон\t");
    scanf_s("%lf",&(*l));
    while (*l > 1.0)
    {
        if (*l > 1.0)
            printf("\nЭпсилон должен быть меньше 1.0");
        printf("\nВведите эпсилон\t");
        scanf_s("%lf",&(*l));
    }
    double n = 1.0;
    *s = (sin(2.0 * n - 1.0) * *x) / (2.0 * n - 1.0);
    double item = (sin(2.0 * n - 1.0) * *x) / (2.0 * n - 1.0);
    while (*l <= fabs(item))
    {
        n += 1.0;
        item = (sin(2.0 * n - 1.0) * *x) / (2.0 * n - 1.0);
        *s += item;
        printf("\nN = %lf\tS = %lf\titem = %lf", n, *s, item);
    }
}
void task3(double * s, const double * a, double * b, unsigned * month)
{
    printf("\nВведите сбережения\t");
    scanf_s("%lf",&(*s));
    printf("\nВведите стипеднию\t");
    scanf_s("%lf",&(*a));
    printf("\nВведите затраты за месяц\t");
    scanf_s("%lf",&(*b));
    *month = 0;
    while (*s >= *b)
    {
        *month += 1;
        *s += *a - *b;
        *b *= 1.02;
    }
}
int main() {
    double x = 0, z, s, a = 0, b, l = 0;
    unsigned month = 0;
    task1(&x, &z);
    printf("\nX = %lf\tZ = %lf", x, z);
    task2(&x, &l, &s);
    printf("\nX = %lf\tКоличество слагаемых = %lf\tСумма = %lf", x, l, s);
    task3(&s, &a, &b, &month);
    printf("\nСбережения = %lf\tСтипендия = %lf\tЗатраты = %lf\tМесяцев с сбережениями = %u", s, a, b, month);
    return 0;
}
