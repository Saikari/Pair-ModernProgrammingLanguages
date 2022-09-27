#include <iostream>
int main() {
    double a, b, c, x, x2;
    std::cout << "Введите а" << std::endl;
    std::cin >> a;
    std::cout << "Введите b" << std::endl;
    std::cin >> b;
    std::cout << "Введите c" << std::endl;
    std::cin >> c;
    if (a == 0.0)
    {
        std::cout << "Линейное уравнение " << std::endl;
    }
    else
    {
        double D = b * b - 4.0 * a * c;
        if (D == 0.0)
            x = -b / (2.0 * a);
        else if (D > 0.0)
        {
            x = (-b + sqrt(D)) / (2.0 * a);
            x2 = (-b - sqrt(D)) / (2.0 * a);
        }
        if (D < 0.0)
            std::cout << "Нет корней!" << std::endl;
        else if (D > 0.0)
            std::cout << "X = " << x << " X2 = " << x2 << std::endl;
        else
            std::cout << "X = " << x << std::endl;
    }
    return 0;
}
