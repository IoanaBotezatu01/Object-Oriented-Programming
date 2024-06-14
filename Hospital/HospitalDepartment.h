//
// Created by user on 09.05.2023.
//

#ifndef HOSPITAL_HOSPITALDEPARTMENT_H
#define HOSPITAL_HOSPITALDEPARTMENT_H
#include "string"

class HospitalDepartment {
private:
    std::string hospitalName;
    int numberOfDoctors;
public:
    virtual bool isEfficient();
    std::string toString() const;

};



#endif //HOSPITAL_HOSPITALDEPARTMENT_H
