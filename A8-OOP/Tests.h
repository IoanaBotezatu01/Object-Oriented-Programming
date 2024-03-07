#pragma once
#include "Service.h"
#include "Pet.h"
#include "Repository.h"
#include "FakeRepository.h"
#include <assert.h>
#include <exception>

class Tests
{
public:
    void testAll();
    //void Add_duplicateName_RaiseException();
    //void Remove_unexistingPet_RaiseException();
};