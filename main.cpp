#include "TrainList.h"
#include "TextTask.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <clocale>

#ifdef _WIN32
#include <windows.h>
#endif

static int readInt(const char* prompt) {
    std::cout << prompt;
    int x;
    if (!(std::cin >> x)) throw std::runtime_error("Ошибка ввода целого числа.");
    std::cin.ignore(1024, '\n');
    return x;
}

static void trainMenu() {
    TrainList list;

    for (;;) {
        std::cout
            << "\nTRAIN меню:\n"
            << "1) Добавить поезд (в позицию)\n"
            << "2) Удалить поезд (по индексу)\n"
            << "3) Редактировать поезд (по индексу)\n"
            << "4) Показать все\n"
            << "5) Найти по номеру\n"
            << "6) Сортировать\n"
            << "0) Назад\n> ";

        int cmd;
        if (!(std::cin >> cmd)) throw std::runtime_error("Ошибка ввода команды.");
        std::cin.ignore(1024, '\n');

        if (cmd == 0) return;

        if (cmd == 1) {
            int pos = readInt("Позиция (0..n): ");
            TRAIN t;
            std::cin >> t;
            list.addAt(pos, t);
        }
        else if (cmd == 2) {
            int pos = readInt("Индекс (0..n-1): ");
            list.removeAt(pos);
        }
        else if (cmd == 3) {
            int pos = readInt("Индекс (0..n-1): ");
            TRAIN& t = list.at(pos);
            std::cout << "Текущее: " << t << "\n";
            std::cout << "Введите новые значения:\n";
            std::cin >> t;
        }
        else if (cmd == 4) {
            list.printAll();
        }
        else if (cmd == 5) {
            int num = readInt("Номер поезда: ");
            int idx = list.findByNumber(num);
            if (idx < 0) std::cout << "Поезд с таким номером не найден.\n";
            else std::cout << list.at(idx) << "\n";
        }
        else if  (cmd == 6){ list.sort(); 
        }
        else {
            std::cout << "Неизвестная команда.\n";\

        }
    }
}

static void textMenu() {
    const std::string path = "input.txt";
    int words = readInt("Количество слов в предложении: ");
    printSentencesWithWordCount(path, words);
}

int main() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    setlocale(LC_ALL, ""); // включает локаль ОС (обычно тоже помогает) [web:150]

    try {
        for (;;) {
            std::cout
                << "\nГлавное меню:\n"
                << "1) Задача TRAIN\n"
                << "2) Текст (input.txt): предложения по числу слов\n"
                << "0) Выход\n> ";

            int cmd;
            if (!(std::cin >> cmd)) throw std::runtime_error("Ошибка ввода команды.");
            std::cin.ignore(1024, '\n');

            if (cmd == 0) break;
            if (cmd == 1) trainMenu();
            else if (cmd == 2) textMenu();
            else std::cout << "Неизвестная команда.\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Исключение: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
