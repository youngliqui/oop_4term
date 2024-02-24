//
// Created by youngliqui on 23.02.2024.
//

#ifndef OOP_4TERM_DOCTOR_H
#define OOP_4TERM_DOCTOR_H

#endif //OOP_4TERM_DOCTOR_H

#include <string>
#include <vector>

using namespace std;

class Doctor {
public:
    Doctor(string name, string specialization, vector<string> services);

    ~Doctor();

    string getName() const;

    string getSpecialization() const;

    vector<string> getServices() const;

    bool isBusy() const;

private:
    string name;
    string specialization;
    vector<string> services;
    bool busy;
};