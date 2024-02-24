//
// Created by youngliqui on 23.02.2024.
//
#include "Patient.h"


Patient::Patient(string name, vector<string> services) {
    this->name = std::move(name);
    this->services = std::move(services);
}

string Patient::getName() const {
    return name;
}

vector<string> Patient::getServices() const {
    return services;
}

Patient::~Patient() = default;

