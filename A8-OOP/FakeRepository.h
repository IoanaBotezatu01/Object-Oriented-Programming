#pragma once
#include "FileRepository.h"

class FakeRepository :
    public FileRepository
{
public:
    FakeRepository() = default;

    bool isTrue;
    int add_item_repo(Pet new_item) override;
    int remove_item_repo(std::string name) override;
};

