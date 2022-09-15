#include <stdio.h>
#include <stdlib.h>
void getmax(const int * array, const unsigned * size, int * max)
{
    *max = array[0];
    for (unsigned i = 0; i < *size; ++i)
        if (*max < array[i])
            *max = array[i];
}
void getmin(const int * array, const unsigned * size, int * min)
{
    *min = array[0];
    for (unsigned i = 0; i < *size; ++i)
        if (*min > array[i])
            *min = array[i];
}
void getavg(const int * array, const unsigned * size, double * avg)
{
    for (unsigned i = 0; i < *size; ++i)
        *avg += array[i];
    *avg = *avg == 0 ?  0 : *avg / *size;
}
void getodds(const int * array, const unsigned * size, unsigned * oddscount, int * oddssum)
{
    *oddscount = *oddssum = 0;
    for (unsigned i = 0; i < *size; ++i)
        if (array[i] % 2 == 0)
            *oddscount += 1, *oddssum += array[i];
}
void geteven(const int * array, const unsigned * size, unsigned * evenscount, int * evenssum)
{
    *evenscount = *evenssum = 0;
    for (unsigned i = 0; i < *size; ++i)
        if (array[i] % 2 == 1)
            *evenscount += 1, *evenssum += array[i];
}
void sortdesc(int * array, const unsigned * size)
{
    int temp;
    for (unsigned i = 0; i < *size; ++i)
        for (unsigned j = i + 1; j < *size; ++j)
            if (array[j] > array[i])
                temp = array[i],
                array[i] = array[j],
                array[j] = temp;
}
void sortasc(int * array, const unsigned * size)
{
    int temp;
    for (unsigned i = 0; i < *size; ++i)
        for (unsigned j = i + 1; j < *size; ++j)
            if (array[j] < array[i])
                temp = array[i],
                array[i] = array[j],
                array[j] = temp;
}
void fillvec(int * array, const unsigned * size)
{
    for (unsigned i = 0; i < *size; ++i)
        array[i] = rand() % 20;
}
void printvec(const int * array, const unsigned * size)
{
    for (unsigned i = 0; i < *size; ++i)
        printf(i % 5 != 0 ? "%i " : "\n%i ", array[i]);
}
int main() {
    srand(time(NULL));
    unsigned n;
    printf("Введите размерность вектора случайных чисел ");
    scanf("%u", &n);
    int x[n], max, min;
    double avg;
    fillvec(&x,&n);
    printvec(&x,&n);
    getmax(&x,&n,&max);
    printf("\nМаксимальный элемент вектора = %i", max);
    getmin(&x,&n,&min);
    printf("\nМинимальный элемент вектора = %i", min);
    getavg(&x,&n,&avg);
    printf("\nСредний элемент вектора = %lf", avg);
    unsigned oddscount; int oddssum;
    unsigned evenscount; int evenssum;
    getodds(&x,&n,&oddscount, &oddssum);
    printf("\nКоличество чётных элементов вектора = %u\tСумма чётных элементов вектора = %i", oddscount, oddssum);
    geteven(&x,&n,&evenscount,&evenssum);
    printf("\nКоличество нечётных элементов вектора = %u\tСумма нечётных элементов вектора = %i", evenscount, evenssum);
    sortasc(&x,&n);
    printf("\nВектор отсортированный по-возрастанию");
    printvec(&x,&n);
    sortdesc(&x,&n);
    printf("\nВектор отсортированный по-убыванию");
    printvec(&x,&n);
    return 0;
}
