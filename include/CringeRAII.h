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

    //Запрещаем копирование и присваивание объекта, чтобы избежать ненужных ошибок, по типу владения одним и тем же ресурсом у двух объектов,
    //где закроется корректно один объект (файл), а второй - нет, будет неопределенное поведение
    CringeRAII(const CringeRAII&) = delete;
    CringeRAII& operator= (const CringeRAII&) = delete;

    CringeRAII (FileRAII&& other);

    CringeRAII& operator= (CringeRAII&& other);

private:
    // file - поток для работы с файлом
    // path - путь к файлу 
    std::fstream file;
    std::string path;
};

#endif
