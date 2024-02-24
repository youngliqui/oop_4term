//
// Created by youngliqui on 23.02.2024.
//

#ifndef OOP_4TERM_PATIENT_H
#define OOP_4TERM_PATIENT_H

#endif //OOP_4TERM_PATIENT_H

#include <string>
#include <vector>

using namespace std;

class Patient {
public:
    Patient(string name, vector<string> services);
    ~Patient();
    string getName() const;
    vector<string> getServices() const;

private:
    string name;
    vector<string> services;
};