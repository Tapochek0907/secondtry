#include "Train.h"
#include <stdexcept>

TRAIN::TRAIN() {
    std::cout << "Создан поезд (конструктор без параметров)\n";
}

TRAIN::TRAIN(const std::string& dest, int num, const std::string& time)
    : destination_(dest), number_(num), departureTime_(time) {
}

TRAIN::TRAIN(const TRAIN& other)
    : destination_(other.destination_), number_(other.number_), departureTime_(other.departureTime_) {
    std::cout << "Создан поезд (копирующий конструктор): №" << number_ << "\n";
}

TRAIN::~TRAIN() {
   
}

TRAIN& TRAIN::operator=(const TRAIN& other) {
    if (this != &other) {
        destination_ = other.destination_;
        number_ = other.number_;
        departureTime_ = other.departureTime_;
    }
    return *this;
}

const std::string& TRAIN::getDestination() const { return destination_; }
int TRAIN::getNumber() const { return number_; }
const std::string& TRAIN::getDepartureTime() const { return departureTime_; }

void TRAIN::setDestination(const std::string& dest) { destination_ = dest; }

void TRAIN::setNumber(int num) {
    if (num <= 0) throw std::runtime_error("Номер поезда должен быть положительным.");
    number_ = num;
}

void TRAIN::setDepartureTime(const std::string& time) {
    if (time.empty()) throw std::runtime_error("Время отправления не должно быть пустым.");
    departureTime_ = time;
}

std::istream& operator>>(std::istream& is, TRAIN& t) {
    std::string dest, time;
    int num;

    std::cout << "Пункт назначения: ";
    std::getline(is >> std::ws, dest);

    std::cout << "Номер поезда: ";
    if (!(is >> num)) throw std::runtime_error("Ошибка ввода номера поезда.");
    is.ignore(1024, '\n');

    std::cout << "Время отправления (например, 12:34): ";
    std::getline(is, time);

    t.setDestination(dest);
    t.setNumber(num);
    t.setDepartureTime(time);

    return is;
}

std::ostream& operator<<(std::ostream& os, const TRAIN& t) {
    return os << "Поезд №" << t.number_ << ", " << t.departureTime_ << ", " << t.destination_;
}
