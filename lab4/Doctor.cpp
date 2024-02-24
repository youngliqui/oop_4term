//
// Created by youngliqui on 23.02.2024.
//
#include "Doctor.h"

/**
 * std::move(T) гарантирует перемещение значения T в this->T без лишних копирований.
 * @param name - имя доктора
 * @param specialization - специализация(терапевт, ортопед, хирург)
 * @param services - услуги доктора
 */
Doctor::Doctor(string name, string specialization, vector<string> services) {
    this->name = std::move(name);
    this->specialization = std::move(specialization);
    this->services = std::move(services);
}

Doctor::~Doctor() = default;

string Doctor::getName() const {
    return name;
}

string Doctor::getSpecialization() const {
    return specialization;
}

vector<string> Doctor::getServices() const {
    return services;
}

bool Doctor::isBusy() const {
    return busy;
}

