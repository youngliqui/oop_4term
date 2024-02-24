//
// Created by youngliqui on 23.02.2024.
//

#ifndef OOP_4TERM_CLINIC_H
#define OOP_4TERM_CLINIC_H

#endif //OOP_4TERM_CLINIC_H

#include <vector>
#include <map>
#include <string>
#include <mutex>
#include "Doctor.h"
#include "Patient.h"
#include <condition_variable>
#include <deque>

using namespace std;

class Clinic {
public:
    Clinic();
    ~Clinic();
    void addPatient(Patient* patient);
    void processPatients();
    void printResults();
    void stop();

private:
    Doctor* findDoctor(Patient& patient);
    vector<Doctor*> doctors;
    deque<Patient*> patients;
    vector<string> services;
    map<string, vector<string>> visits;
    //map<string, vector<string>> services;
    mutex mut;
    condition_variable cv;
    bool stoppedByUser = false;
};