//
// Created by youngliqui on 22.02.2024.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include "Coder.h"
#include "string"

using namespace std;
namespace fs = filesystem;

int main() {
    // проверка на наличие директории
    string dirName = R"(C:\Users\youngliqui\CLionProjects\oop_4term\lab3\files)";
    if (!fs::exists(dirName)) {
        fs::create_directory(dirName);
    }

    string inputFilePath = R"(C:\Users\youngliqui\CLionProjects\oop_4term\lab3\files\input.txt)";
    string outputFilePath = R"(C:\Users\youngliqui\CLionProjects\oop_4term\lab3\files\output.txt)";

    ifstream inputFile(inputFilePath);

    // проверка на наличие файла, а если он отсутствует - запись в файл с консоли
    if (!inputFile) {
        ofstream newInputFile(inputFilePath);

        string inputText;
        cout << "Enter text:" << endl;
        getline(cin, inputText);

        newInputFile << inputText << endl;
        newInputFile.close();

        cout << "New file created and data written successfully!" << endl;
        inputFile.open(inputFilePath);
    }


    if (!inputFile.is_open()) {
        cerr << "Failed to open file!" << endl;
        return -1;
    }

    // чтение с файла и подсчет количества знаков препинания
    int count = 0;
    string line;
    while (getline(inputFile, line)) {
        for (char symbol: line) {
            if (ispunct(symbol)) {
                count++;
            }
        }
    }

    inputFile.close();
    cout << "Punctuations: " << count;

    // кодирование и запись ответа в файл output
    int key = 97;
    int encryptedValue = Coder::encrypt(count, key);
    ofstream outputFile(outputFilePath);

    if (!outputFile.is_open()) {
        cerr << "Failed to open the file!" << endl;
    }

    outputFile << encryptedValue << endl;
    outputFile.close();

    return 0;
}