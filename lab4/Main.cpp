//
// Created by youngliqui on 23.02.2024.
//

#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include "Clinic.h"

using namespace std;


int main() {
    auto* clinic = new Clinic();

    thread patientThread([&clinic](){
        string name = "Patient #";
        int patientNumber = 0;

        // клиенты в первый день
        cout << "Day 1:" << endl;
        for (int i = 0; i < 10; i++) {
            clinic->addPatient(new Patient(name + to_string(patientNumber++), {}));
            clinic->addPatient(new Patient(name + to_string(patientNumber++), {}));
            this_thread::sleep_for(chrono::seconds(2));
        }

        // клиенты во второй день
        cout << "Day 2:" << endl;
        for (int i = 0; i < 10; i+=2) {
            clinic->addPatient(new Patient(name + to_string(patientNumber++), {}));
            clinic->addPatient(new Patient(name + to_string(patientNumber++), {}));
            this_thread::sleep_for(chrono::seconds(2));
        }

        // клиенты в третий день
        cout << "Day 3:" << endl;
        for (int i = 0; i < 10; i+=2) {
            clinic->addPatient(new Patient(name + to_string(patientNumber++), {}));
            clinic->addPatient(new Patient(name + to_string(patientNumber++), {}));
            this_thread::sleep_for(chrono::seconds(2));
        }

        clinic->stop();
    });

    thread clinicThread([&clinic](){
        clinic->processPatients();
    });

    patientThread.join();
    clinicThread.join();
    clinic->printResults();
}
