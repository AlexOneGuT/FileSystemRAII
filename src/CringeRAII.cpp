#include "CringeRAII.h"
#include <stdexcept>

// Конструктор - открываем файл
CringeRAII::CringeRAII(const std::string& filePath, std::ios_base::openmode mode) : path(filePath) {
    file.open(filePath, mode);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }
}

// Деструктор - закрываем файл
CringeRAII::~CringeRAII() {
    if (file.is_open()) {
        file.close();
    }
}

// Чтение строки из файла
std::string CringeRAII::readLine() {
    std::string line;
    if (!std::getline(file, line)) {
        if (file.eof()) {
            throw std::runtime_error("End of file reached");
        }
        else {
            throw std::runtime_error("Error reading from file: " + path);
        }
    }
    return line;
}

// Запись строки в файл
void CringeRAII::writeLine(const std::string& line) {
    if (!(file << line << '\n')) {
        throw std::runtime_error("Error writing to file: " + path);
    }
}