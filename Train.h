#pragma once
#include <iostream>
#include <string>

class TRAIN {
    std::string destination_;
    int number_{};
    std::string departureTime_; // как строка "HH:MM"

public:
    TRAIN();
    TRAIN(const std::string& dest, int num, const std::string& time);
    TRAIN(const TRAIN& other);
    ~TRAIN();

    TRAIN& operator=(const TRAIN& other);

    const std::string& getDestination() const;
    int getNumber() const;
    const std::string& getDepartureTime() const;

    void setDestination(const std::string& dest);
    void setNumber(int num);
    void setDepartureTime(const std::string& time);

    friend std::istream& operator>>(std::istream& is, TRAIN& t);
    friend std::ostream& operator<<(std::ostream& os, const TRAIN& t);
};
