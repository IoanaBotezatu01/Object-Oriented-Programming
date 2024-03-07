#include "Tests.h"
#include "Exceptions.h"

void Tests::testAll()
{
	//this->Add_duplicateName_RaiseException();
	//this->Remove_unexistingPet_RaiseException();

	//std::cout << "Tests done!\n\n";
}
/*void Tests::Add_duplicateName_RaiseException()
{
	FakeRepository* fake_repo = new FakeRepository{};
	Service* service = new Service(fake_repo);
	fake_repo->isTrue = true;
	try
	{
		service->add_pet("sa", "", "1", "");
		assert(false);
	}
	catch (RepositoryException& ex)
	{
		assert(true);
	}
}

void Tests::Remove_unexistingPet_RaiseException()
{
	FakeRepository* fake_repo = new FakeRepository();
	Service* service = new Service(fake_repo);
	fake_repo->isTrue = true;
	try
	{
		service->remove_pet("sa");
		assert(false);
	}
	catch (RepositoryException& ex)
	{
		assert(true);
	}
}


*/

