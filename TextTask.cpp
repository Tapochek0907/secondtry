#include "TextTask.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

static int countWords(const std::string& s) {
    std::stringstream ss(s);
    int c = 0;
    std::string w;
    while (ss >> w) ++c;
    return c;
}

static void flushSentence(std::string& sentence, int needWords) {
    if (!sentence.empty() && countWords(sentence) == needWords)
        std::cout << sentence << "\n";
    sentence.clear();
}

void printSentencesWithWordCount(const std::string& path, int words) {
    if (words <= 0) throw std::runtime_error(" оличество слов должно быть положительным.");

    std::ifstream in(path);
    if (!in) throw std::runtime_error("Ќе удалось открыть файл: " + path);

    std::string line;
    std::string cur;

    while (std::getline(in, line)) {
        for (size_t i = 0; i < line.size(); ++i) {
            char ch = line[i];
            cur += ch;

            if (ch == '.' || ch == '!' || ch == '?') {
                flushSentence(cur, words);
            }
        }

        // перевод строки тоже завершает предложение
        flushSentence(cur, words);
    }

    // на вс€кий случай, если файл не оканчиваетс€ переводом строки
    if (!cur.empty()) flushSentence(cur, words);
}
