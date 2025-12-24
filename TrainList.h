
#include "Train.h"

class TrainList {
    TRAIN* a_{ nullptr };
    int n_{ 0 };

    void sortByNumber(); // простая сортировка

public:
    TrainList();
    TrainList(const TrainList& other);
    ~TrainList();

    TrainList& operator=(const TrainList& other);

    int size() const;

    void addAt(int pos, const TRAIN& t);   // 0..n
    void removeAt(int pos);               // 0..n-1
    TRAIN& at(int pos);
    const TRAIN& at(int pos) const;

    int findByNumber(int num) const;      // индекс или -1
    void printAll() const;
    void sort();
};
