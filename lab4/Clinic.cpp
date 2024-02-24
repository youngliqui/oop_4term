//
// Created by youngliqui on 23.02.2024.
//
#include <algorithm>
#include "Clinic.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Clinic::Clinic() {
    services.emplace_back("General check-up");
    services.emplace_back("Vaccinations");
    services.emplace_back("Certificate");
    services.emplace_back("Fracture care");
    services.emplace_back("Arthroscopy");
    services.emplace_back("Operation");
    services.emplace_back("Implantation");
    services.emplace_back("Consultation");

    doctors.push_back(new Doctor("John", "Therapist", {services[0], services[1], services[2]}));
    doctors.push_back(new Doctor("Mary", "Orthopedist", {services[3], services[4], services[7]}));
    doctors.push_back(new Doctor("Peter", "Surgeon", {services[5], services[6], services[7]}));
}


Clinic::~Clinic() = default;

/**
 * @brief Находит доктора, способного оказать необходимые услуги пациенту.
 * @param patient Пациент, для которого требуется найти доктора.
 * @return Указатель на доктора, способного оказать нужные услуги пациенту. Иначе - новый пустой объект Doctor.
 */
Doctor *Clinic::findDoctor(Patient &patient) {
    for (Doctor* doctor: doctors) {
        for (const string& service: patient.getServices()) {
            if (find(doctor->getServices().begin(), doctor->getServices().end(), service) != doctor->getServices().end()) {
                return doctor;
            }
        }
    }
    return new Doctor("", "", {});
}

/**
 * @brief Добавляет пациента в список и уведомляет все потоки, ожидающие на condition_variable.
 * С помощью cv.wait(lock) поток блокируется и ожидает уведомление от condition_variable.
 * @param patient Пациент, которого необходимо добавить
 */
void Clinic::addPatient(Patient* patient) {
    unique_lock<mutex> lock(mut);
    while (patients.size() >= 2) {
        cv.wait(lock);
    }
    patients.push_back(patient);
    cv.notify_all();
}

/**
 * @brief Производит обработку пациентов до их ограничения или окончания работы.
 * @details Метод регулярно проверяет состояние очереди пациентов и производит операции с ними,
 * пока не будет достигнут лимит пациентов или не будет вызвана остановка работы клиники.
 */
void Clinic::processPatients() {
    while(true) {
        unique_lock<mutex> lock(mut);
        while((patients.size() > 2 || patients.empty())) {
            cout << "Wait" << endl;
            cv.wait(lock);
        }

        //for (int i = 0; i < 2; ++i) {
            Patient* patient = patients.front();
            patients.pop_front();

            cout << "Process - " << patient->getName() << endl;

            Doctor* doctor = findDoctor(*patient);
            visits[patient->getName()].push_back(doctor->getName());
            for (const string& service: patient->getServices()) {
                services[doctor->getName()].push_back(service);
            }

            this_thread::sleep_for(chrono::seconds(3));


      //  }
        cv.notify_one();
        cout << patient->getName() << " - processed" << endl;

        if (stoppedByUser) {
            break;
        }
    }
}

/**
 * @brief Печатает результаты работы клиника за неделю, включая истории посещений и списки оказаных услуг.
 */
void Clinic::printResults() {
    cout << "Weekly visits:" << endl;
    for (const auto& visit: visits) {
        cout << visit.first << ": ";
        for (Doctor *doctor: doctors) {
            cout << doctor->getName() << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Weekly services:" << endl;
    for (const auto& service: services) {
        cout << service.first << ": ";
        for (const string& s: service.second) {
            cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Clinic::stop() {
    stoppedByUser = true;
    cv.notify_all();
}

