#ifndef CRINGE_RAII_H
#define CRINGE_RAII_H

#include <string>
#include <fstream>
#include <stdexcept>

class CringeRAII {
public:
    // �����������, ����������� ���� � ����� �������� ����� (������/������)
    CringeRAII(const std::string& filePath, std::ios_base::openmode mode);

    // ���������� - �� ����������� �������, ��� ����� ������
    ~CringeRAII();

    // ����� readLine - ����� �������������� ��� ������ ����� �� �����
    std::string readLine();

    // ����� writeLine - ����� �������������� ��� ������ ���������� � ����
    void writeLine(const std::string& line);

    //��������� ����������� � ������������ �������, ����� �������� �������� ������, �� ���� �������� ����� � ��� �� �������� � ���� ��������,
    //��� ��������� ��������� ���� ������ (����), � ������ - ���, ����� �������������� ���������
    CringeRAII(const CringeRAII&) = delete;
    CringeRAII& operator= (const CringeRAII&) = delete;

private:
    // file - ����� ��� ������ � ������
    // path - ���� � ����� 
    std::fstream file;
    std::string path;
};

#endif