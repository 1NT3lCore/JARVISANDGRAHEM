#include <iostream>
#include "convex_hull.h"
#include <windows.h>
using namespace std;


int main() {
    SetConsoleOutputCP(1251);
    std::string input;
    int n;
    do {
        std::cout << "Введите количество точек (должно быть натуральным числом и >= 3 или введите 'exit' для выхода): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            return 0; // Завершение программы
        }

        if (is_int(input)) {
            n = std::stoi(input);
            if (n >= 3) break; // Выход из цикла, если введено корректное значение
        }

        std::cout << "Неверный ввод. Пожалуйста, введите корректное натуральное число >= 3.\n";
    } while (true);

    std::vector<point2d> points(n);
    for (int i = 0; i < n; ++i) {
        do {
            std::cout << "Введите точку " << i + 1 << " (x,y): ";
            std::getline(std::cin, input);
            std::stringstream ss(input);
            std::string x_str, y_str;
            std::getline(ss, x_str, ',');
            std::getline(ss, y_str, ',');

            if (is_int(x_str) && is_int(y_str)) {
                points[i].x = std::stoi(x_str);
                points[i].y = std::stoi(y_str);
                break; // Выход из цикла, если введены корректные значения
            }

            std::cout << "Неверный ввод, пожалуйста, введите действительные целые числа, разделенные запятой.\n";
        } while (true);
    }

    int choice;
    do {
        std::cout << "Выберите алгоритм для вычисления выпуклой оболочки:\n";
        std::cout << "1. Сканирование Грэхема\n";
        std::cout << "2. Марш Джарвиса\n";
        std::cout << "Введите ваш выбор (1 или 2): ";
        std::getline(std::cin, input);

        if (is_int(input)) {
            choice = std::stoi(input);
            if (choice == 1 || choice == 2) break; // Выход из цикла, если введено корректное значение
        }

        std::cout << "Неверный выбор. Пожалуйста, введите 1 или 2.\n";
    } while (true);

    std::vector<point2d> ch;
    if (choice == 1) {
        ch = graham_scan(points);
    }
    else {
        ch = jarvis_march(points);
    }

    std::cout << "Точки выпуклой оболочки:\n";
    for (const auto& pt : ch) {
        std::cout << pt.x << ' ' << pt.y << '\n';
    }

    return 0;
}