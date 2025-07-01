#ifndef CRINGE_RAII_H
#define CRINGE_RAII_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <utility>

class CringeRAII {
public:
    // Конструктор, принимающий путь и метод открытия файла (чтение/запись)
    CringeRAII(const std::string& filePath, std::ios_base::openmode mode);

    // Деструктор - из определения понятно, что будет делать
    ~CringeRAII();

    // Метод readLine - будет использоваться для чтения строк из файла
    std::string readLine();

    // Метод writeLine - будет использоваться для записи информации в файл
    void writeLine(const std::string& line);


    CringeRAII(const CringeRAII&) = delete;
    CringeRAII (const CringeRAII&& other) = delete;
    CringeRAII& operator= (CringeRAII& other) = delete;
    CringeRAII& operator= (CringeRAII&& other);


private:
    // file - поток для работы с файлом
    // path - путь к файлу 
    std::fstream file;
    std::string path;
};

#endif
