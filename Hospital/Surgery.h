//
// Created by user on 09.05.2023.
//

#ifndef HOSPITAL_SURGERY_H
#define HOSPITAL_SURGERY_H
#include "string"
#include "HospitalDepartment.h"

class Surgery {
private:
    int NumberOfPatients;
public:
    bool isEfficient();
    std::string toString() const;

};


#endif //HOSPITAL_SURGERY_H
