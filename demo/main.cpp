#include <iostream>
#include <string>
#include "CringeRAII.h"

void DemonstrateReading() {
    try {
        std::string path;
        std::cout << "Please, enter the file name and path to file: ";
        std::getline(std::cin, path);

        std::cout << "Trying to read from file..." << '\n';
        CringeRAII reader(path, std::ios::in);

        std::cout << "File opened successfully! Contents:" << '\n';
        while (true) {
            try {
                std::string line = reader.readLine();
                std::cout << line << '\n';
            }
            catch (const std::runtime_error& e) {
                if (std::string(e.what()) == "End of file reached") {
                    std::cout << "Finished reading file." << '\n';
                    break;
                }
                throw;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void DemonstrateWriting() {
    try {
        std::string path;
        std::cout << "Please, enter the file name and path to file: ";
        std::getline(std::cin, path);

        CringeRAII writer(path, std::ios::out);

        writer.writeLine("Hello, bro!");
        writer.writeLine("This is a cringe library written in the RAII style");
        writer.writeLine ("I don't know if I did everything correctly, but at least I'm satisfied with the result, and I'm looking forward to your feedback!");
        writer.writeLine("Goodbye!");

        std::cout << "Data written successfully." << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void DemonstrateError() {
    try {
        std::cout << "Trying to open non-existent file..." << '\n';
        CringeRAII reader("nonexistent.txt", std::ios::in);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << '\n';
    }
}

int main() {
    DemonstrateReading(); // Функция для демонстрации Чтения
    DemonstrateWriting(); // Функция для демонстрации Записи
    DemonstrateError(); // Функция для демонстрации кейса - Ошибка открытия файла
}