#include "TrainList.h"
#include <iostream>
#include <stdexcept>

TrainList::TrainList() {
    std::cout << "Создан список поездов (пустой)\n";
}

TrainList::TrainList(const TrainList& other) : a_(nullptr), n_(other.n_) {
    std::cout << "Создан список поездов (копирование), элементов: " << n_ << "\n";
    if (n_ > 0) {
        a_ = new TRAIN[n_];
        for (int i = 0; i < n_; ++i) a_[i] = other.a_[i];
    }
}

TrainList::~TrainList() {
    std::cout << "Удален список поездов, элементов было: " << n_ << "\n";
    delete[] a_;
}

TrainList& TrainList::operator=(const TrainList& other) {
    if (this != &other) {
        delete[] a_;
        n_ = other.n_;
        a_ = (n_ > 0) ? new TRAIN[n_] : nullptr;
        for (int i = 0; i < n_; ++i) a_[i] = other.a_[i];
    }
    return *this;
}

int TrainList::size() const { return n_; }

TRAIN& TrainList::at(int pos) {
    if (pos < 0 || pos >= n_) throw std::runtime_error("Индекс вне диапазона.");
    return a_[pos];
}

const TRAIN& TrainList::at(int pos) const {
    if (pos < 0 || pos >= n_) throw std::runtime_error("Индекс вне диапазона.");
    return a_[pos];
}

void TrainList::addAt(int pos, const TRAIN& t) {
    if (pos < 0 || pos > n_) throw std::runtime_error("Позиция вставки вне диапазона.");

    TRAIN* b = new TRAIN[n_ + 1];
    for (int i = 0; i < pos; ++i) b[i] = a_[i];
    b[pos] = t;
    for (int i = pos; i < n_; ++i) b[i + 1] = a_[i];

    delete[] a_;
    a_ = b;
    ++n_;

}

void TrainList::removeAt(int pos) {
    if (pos < 0 || pos >= n_) throw std::runtime_error("Позиция удаления вне диапазона.");

    if (n_ == 1) {
        delete[] a_;
        a_ = nullptr;
        n_ = 0;
        return;
    }

    TRAIN* b = new TRAIN[n_ - 1];
    for (int i = 0, j = 0; i < n_; ++i) {
        if (i == pos) continue;
        b[j++] = a_[i];
    }

    delete[] a_;
    a_ = b;
    --n_;
}

int TrainList::findByNumber(int num) const {
    for (int i = 0; i < n_; ++i)
        if (a_[i].getNumber() == num) return i;
    return -1;
}

void TrainList::printAll() const {
    if (n_ == 0) {
        std::cout << "(список пуст)\n";
        return;
    }
    for (int i = 0; i < n_; ++i) std::cout << i << ") " << a_[i] << "\n";
}

void TrainList::sortByNumber() {
    for (int i = 0; i < n_; ++i)
        for (int j = 0; j + 1 < n_ - i; ++j)
            if (a_[j].getNumber() > a_[j + 1].getNumber()) {
                TRAIN tmp = a_[j];
                a_[j] = a_[j + 1];
                a_[j + 1] = tmp;
            }
}
void TrainList::sort() {
    sortByNumber();  
}

