#include <stdio.h>
#include <random>
#include <chrono>
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
    *avg = 0.0;
    for (unsigned i = 0; i < *size; ++i)
        *avg += array[i];
    if (*avg != 0) *avg /= *size;
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
        if (array[i] % 2 != 0)
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
void fillvec(int * array, const unsigned * size, int * from, int * to)
{
    printf("\nВведите начальный предел генерирования чисел");
    scanf_s("%i", &(*from));
    printf("\nВведите конечный предел генерирования чисел");
    scanf_s("%i", &(*to));
    while (*from >= *to) {
        printf("\nВведите начальный предел генерирования чисел");
        scanf_s("%i", &(*from));
        printf("\nВведите конечный предел генерирования чисел");
        scanf_s("%i", &(*to));
        if (*from >= *to)
            printf("Недопустимый предел генерирования чисел от %i до %i", *from, *to);
    }
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(*from, *to);
    for (unsigned i = 0; i < *size; ++i)
        array[i] = distribution(generator);
}
void printvec(const int * array, const unsigned * size)
{
    for (unsigned i = 0; i < *size; ++i)
        printf(i % 5 != 0 ? "%i " : "\n%i ", array[i]);
}
int main() {
    unsigned n;
    printf("Введите размерность вектора случайных чисел ");
    scanf_s("%u", &n);
    int x[n], max, min, from, to;
    double avg;
    fillvec(x,&n, &from, &to);
    printvec(x,&n);
    getmax(x,&n,&max);
    printf("\nМаксимальный элемент вектора = %i", max);
    getmin(x,&n,&min);
    printf("\nМинимальный элемент вектора = %i", min);
    getavg(x,&n,&avg);
    printf("\nСредний элемент вектора = %lf", avg);
    unsigned oddscount; int oddssum;
    unsigned evenscount; int evenssum;
    getodds(x,&n,&oddscount, &oddssum);
    printf("\nКоличество чётных элементов вектора = %u\tСумма чётных элементов вектора = %i", oddscount, oddssum);
    geteven(x,&n,&evenscount,&evenssum);
    printf("\nКоличество нечётных элементов вектора = %u\tСумма нечётных элементов вектора = %i", evenscount, evenssum);
    sortasc(x,&n);
    printf("\nВектор отсортированный по-возрастанию");
    printvec(x,&n);
    sortdesc(x,&n);
    printf("\nВектор отсортированный по-убыванию");
    printvec(x,&n);
    return 0;
}
