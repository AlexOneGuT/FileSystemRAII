#include "CringeRAII.h"
#include <stdexcept>

// Êîíñòðóêòîð - îòêðûâàåì ôàéë
CringeRAII::CringeRAII(const std::string& filePath, std::ios_base::openmode mode) : path(filePath) {
    file.open(filePath, mode);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }
}

// Äåñòðóêòîð - çàêðûâàåì ôàéë
CringeRAII::~CringeRAII() {
    if (file.is_open()) {
        file.close();
    }
}

CringeRAII::CringeRAII& operator= (CringeRAII&& other) noexcept {
    if (this != &other) {
        if (file.is_open()) {
            file.close();
        }
        file = std::move(other.file);
        path = std::move(other.path);
        other.file.close();
    }
    return *this;
}

// ×òåíèå ñòðîêè èç ôàéëà
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

// Çàïèñü ñòðîêè â ôàéë
void CringeRAII::writeLine(const std::string& line) {
    if (!(file << line << '\n')) {
        throw std::runtime_error("Error writing to file: " + path);
    }
}
