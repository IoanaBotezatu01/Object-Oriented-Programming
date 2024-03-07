#include "Service.h"


using namespace std;

Service::Service(std::unique_ptr<FileRepository> repo) :pet_repo{ std::move(repo)} {}

void Service::add_pet(string breed, string name, string age, string photograph)
{
    Pet new_pet(breed, name, age, photograph, 0);
    if (this->pet_repo->add_item_repo(new_pet))
        throw RepositoryException("The pet is already in the list!\n");
}

void Service::remove_pet(string name)
{
    if (this->pet_repo->remove_item_repo(name))
        throw RepositoryException("The pet that you want to remove is not in the pet list.\n");
}

void Service::update_pet(string breed, string name, std::string age, string photograph)
{
    Pet new_pet(breed, name, age, photograph, 0);
    this->pet_repo->update_item_repo(new_pet);
}

int Service::find_pet(string name)
{
    int length_pet_list = this->pet_repo->get_length(), i;
    for (i = 0; i < length_pet_list; i++)
        if (this->pet_repo->get_repo_item(i).get_name() == name)
            return i;
    return -1;
}

int Service::find_unique_pet(string breed, string name, std::string age, string photograph)
{
    int length_pet_list = this->pet_repo->get_length();
    Pet compared_pet(breed, name, age, photograph, 0);
    for (int i = 0; i < length_pet_list; i++)
    {
        if (this->pet_repo->get_repo_item(i) == compared_pet)
            return 1;
    }
    return 0;
}

void Service::adopt_pet(int pet_position, Pet adopted_pet)
{
    this->pet_repo->set_item_adoption(pet_position, adopted_pet);
}

vector<Pet> Service::get_pet_list()
{
    return this->pet_repo->get_repo();
}

int Service::get_pet_list_size()
{
    return this->pet_repo->get_length();
}

Pet Service::get_pet(int position)
{
    return this->pet_repo->get_repo_item(position);
}

void Service::set_pet(int position, Pet pet)
{
    this->pet_repo->set_repo_item(position, pet);
}

void Service::setRepo(std::unique_ptr<FileRepository> repo)
{
    this->pet_repo = std::move(repo);
}

std::string Service::get_filename()
{
    return this->pet_repo->get_filename();
}

void Service::export_into_file(std::string file_name, std::string extension)
{
    this->pet_repo->export_into_file(file_name + "." + extension);
}
