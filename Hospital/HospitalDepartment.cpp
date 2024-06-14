//
// Created by user on 09.05.2023.
//

#include "HospitalDepartment.h"

std::string HospitalDepartment::toString() const {
    auto nrStr = std::to_string(numberOfDoctors);
    return this->hospitalName + " " +nrStr;
}

