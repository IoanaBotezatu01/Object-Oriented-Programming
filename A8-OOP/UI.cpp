#include "UI.h"
#include <chrono>
#include <thread>
#include <string>
#include <cstring>
#include <windows.h>
#include "Validator.h"

using namespace std;
/*

void print_menu()
{
	cout << "What do you want to do today?\n"
		<< "1. Add a new pet\n"
		<< "2. Remove a pet from our data base\n"
		<< "3. Update the status of a pet\n"
		<< "4. Print the list of all the available pets\n"
		<< "0. Exit the program\n";
}

void print_user_menu()
{
	cout << "1. See the dogs one by one\n"
		<< "2. See all the dogs with a specific breed with an age less than a given number\n"
		<< "3. See the current adoption list\n"
		<< "0. Exit the program\n";
}

UI::UI(std::string file, std::string user_file_option)
{
	this->user_file_option = user_file_option;
	if (stricmp(user_file_option.c_str(), "html") == 0)
		this->pet_repo = new FileRepositoryHTML{ file };
	else if (stricmp(user_file_option.c_str(), "csv") == 0)
		this->pet_repo = new FileRepositoryCSV{ file };
	this->service = Service(this->pet_repo);
}

void UI::start()
{
	while (true)
	{
		cout << "You want to run the program as:\n"
			<< "1. Administrator\n"
			<< "2. User\n"
			<< "3. Export the data\n"
			<< "0. Exit\n";
		const int ADMINISTRATOR = 1, USER = 2, EXPORT = 3 , EXIT = 0;
		string option;
		getline(cin, option, '\n');
		cout << '\n';
		if (Validator::is_number(option))
		{
			cout << "The input option is invalid!\n";
		}
		else
		{
			int int_option = stoi(option);

			if (int_option == ADMINISTRATOR)
			{
				const int ADD = 1, REMOVE = 2, UPDATE = 3, PRINT_ALL = 4 , EXIT_ADMINISTRATOR = 0;
				while (true)
				{
					print_menu();
					cout << "Your option: ";
					string administrator_option;
					getline(cin, administrator_option, '\n');
					if (Validator::is_number(administrator_option))
					{
						cout << "The input option must be a number!\n";
					}
					else
					{
						int int_administrator_option = stoi(administrator_option);
						if (int_administrator_option == ADD)
						{
							string new_pet_breed, new_pet_name, new_pet_age, new_pet_photograph;
							try
							{
								cout << "The new pet's breed: ";
								getline(cin, new_pet_breed, '\n');
								Validator::valid_breed(new_pet_breed);
								cout << "The new pet's name: ";
								getline(cin, new_pet_name, '\n');
								Validator::valid_name(new_pet_name);
								cout << "The new pet's age: ";
								getline(cin, new_pet_age, '\n');
								Validator::valid_age(new_pet_age);
								int int_new_pet_age = stoi(new_pet_age);
								cout << "The new pet's photo: ";
								getline(cin, new_pet_photograph, '\n');
								this->service.add_pet(new_pet_breed, new_pet_name, int_new_pet_age, new_pet_photograph);
								cout << "\nDone!\n\n";
							}
							catch (ValidatorException& ex)
							{
								cerr << '\n' << ex.what() << '\n';
							}
							catch (RepositoryException& ex)
							{
								cerr << '\n' << ex.what() << '\n';
							}
						}


						else if (int_administrator_option == REMOVE)
						{
							bool breakpoint = 0;
							string deleted_pet_name;
							cout << "The deleted pet name: ";
							getline(cin, deleted_pet_name, '\n');
							try
							{
								Validator::valid_name(deleted_pet_name);
								this->service.remove_pet(deleted_pet_name);
								cout << "\nDone!\n\n";
							}
							catch (ValidatorException& ex)
							{
								cerr << '\n' << ex.what() << '\n';
							}
							catch (RepositoryException& ex)
							{
								cerr << '\n' << ex.what() << '\n';
							}
						}


						else if (int_administrator_option == UPDATE)
						{
							string new_breed, new_name, new_age, new_photograph;
							try
							{
								cout << "The name of the pet you want to change the data from: ";
								getline(cin, new_name, '\n');
								Validator::valid_name(new_name);
								cout << "The new breed of the pet: ";
								getline(cin, new_breed, '\n');
								Validator::valid_breed(new_breed);
								cout << "The new age of the pet: ";
								getline(cin, new_age, '\n');
								Validator::valid_age(new_age);
								int int_new_age = stoi(new_age);
								cout << "The new photograph of the pet: ";
								getline(cin, new_photograph, '\n');
								this->service.update_pet(new_breed, new_name, int_new_age, new_photograph);
								cout << "\nDone!\n\n";
							}
							catch (ValidatorException& ex)
							{
								cerr << '\n' << ex.what() << '\n';
							}
							catch (RepositoryException& ex)
							{
								cerr << '\n' << ex.what() << '\n';
							}
						}


						else if (int_administrator_option == PRINT_ALL)
						{
							cout << "\n";
							vector<Pet> repo_list = this->service.get_pet_list();
							for (int i = 0; i < this->service.get_pet_list_size(); i++)
							{
								cout << "Pet's breed: " << repo_list[i].get_breed() << '\n';
								cout << "Pet's name: " << repo_list[i].get_name() << '\n';
								cout << "Pet's age: " << repo_list[i].get_age() << '\n';
								cout << "Pet's photo link: " << repo_list[i].get_photograph() << "\n\n";
							}
							if (this->service.get_pet_list_size() == 0)
								cout << "The list is empty :(\n";
						}


						else if (int_administrator_option == EXIT_ADMINISTRATOR)
							break;

						else
							cout << "The input value is not valid!\n";
					}
				}

			}


			else if (int_option == USER)
			{
				const int ALL_DOGS = 1, SPECIFIC_BREED_DOGS = 2, ADOPTION_LIST = 3, EXIT_USER = 0;
				while (true)
				{
					string user_option;
					print_user_menu();
					getline(cin, user_option, '\n');
					if (Validator::is_number(user_option))
						cout << "The input option is invalid!\n";
					else
					{
						int int_user_option = stoi(user_option);

						if (int_user_option == ALL_DOGS)
						{
							cout << "\n";
							int i;
							while (true)
							{
								string adopt_option;
								vector<Pet> repo_list = this->service.get_pet_list();
								for (i = 0; i < this->service.get_pet_list_size(); i++)
								{
									cout << "Pet's breed: " << repo_list[i].get_breed() << '\n';
									cout << "Pet's name: " << repo_list[i].get_name() << '\n';
									cout << "Pet's age: " << repo_list[i].get_age() << '\n';
									std::string fullCommand = (string)"start " + repo_list[i].get_photograph();

									system(fullCommand.c_str());
									if (repo_list[i].get_adoption() == 0)
									{
										cout << "Do you want to adopt this pet?(y/n) ";
										getline(cin, adopt_option, '\n');
										if (adopt_option == "y")
										{
											this->service.adopt_pet(i, repo_list[i]);
										}
									}
									cout << "Do you want to see the next dog?(y/n) ";
									getline(cin, adopt_option, '\n');
									if (adopt_option == "n")
										break;
									else if (adopt_option != "y")
									{
										i--;
										cout << "Your option for the adoption of a pet is invalid!\n";
									}
									cout << '\n';
								}
								cout << '\n';
								if (adopt_option == "n")
									break;
							}
						}

						else if (int_user_option == SPECIFIC_BREED_DOGS)
						{
							string searched_breed, searched_age;
							try
							{
								cout << "The breed you want to search for: ";
								getline(cin, searched_breed, '\n');
								cout << "The maximum age of the pet you are searching for: ";
								getline(cin, searched_age, '\n');
								cout << '\n';
								Validator::valid_age(searched_age);
								int int_searched_age = stoi(searched_age);
								if (searched_breed == "")
								{
									int i;
									while (true)
									{
										string adopt_option;
										vector<Pet> repo_list = this->service.get_pet_list();
										for (i = 0; i < this->service.get_pet_list_size(); i++)
										{
											if (repo_list[i].get_age() < int_searched_age)
											{
												cout << "Pet's breed: " << repo_list[i].get_breed() << '\n';
												cout << "Pet's name: " << repo_list[i].get_name() << '\n';
												cout << "Pet's age: " << repo_list[i].get_age() << '\n';
												std::string fullCommand = (string)"start " + repo_list[i].get_photograph();

												system(fullCommand.c_str());
												if (repo_list[i].get_adoption() == 0)
												{
													cout << "Do you want to adopt this pet?(y/n) ";
													getline(cin, adopt_option, '\n');
													if (adopt_option == "y")
													{
														this->service.adopt_pet(i, repo_list[i]);
													}
												}
												cout << "Do you want to see the next dog?(y/n) ";
												getline(cin, adopt_option, '\n');
												if (adopt_option == "n")
													break;
												else if (adopt_option != "y")
												{
													i--;
													cout << "Your option for the adoption of a pet is invalid!\n";
												}
											}
										}
										cout << '\n';
										if (adopt_option == "n")
											break;
									}
								}
								else
								{
									int i;
									while (true)
									{
										string adopt_option;
										vector<Pet> repo_list = this->service.get_pet_list();
										for (i = 0; i < this->service.get_pet_list_size(); i++)
										{
											if (repo_list[i].get_breed() == searched_breed && repo_list[i].get_age() < int_searched_age)
											{
												cout << "Pet's breed: " << repo_list[i].get_breed() << '\n';
												cout << "Pet's name: " << repo_list[i].get_name() << '\n';
												cout << "Pet's age: " << repo_list[i].get_age() << '\n';
												std::string fullCommand = (string)"start " + repo_list[i].get_photograph();

												system(fullCommand.c_str());
												if (repo_list[i].get_adoption() == 0)
												{
													cout << "Do you want to adopt this pet?(y/n) ";
													getline(cin, adopt_option, '\n');
													if (adopt_option == "y")
													{
														this->service.adopt_pet(i, repo_list[i]);
													}
												}
												cout << "Do you want to see the next dog?(y/n) ";
												getline(cin, adopt_option, '\n');
												if (adopt_option == "n")
													break;
												else if (adopt_option != "y")
												{
													i--;
													cout << "Your option for the adoption of a pet is invalid!\n";
												}
											}
										}
										if (adopt_option != "n" && adopt_option != "y")
										{
											cout << "There is no pet with that breed\n";
											break;
										}
										cout << '\n';
										if (adopt_option == "n")
											break;
									}
								}
							}
							catch (ValidatorException& ex)
							{
								cerr << '\n' << ex.what() << '\n';
							}
						}

						else if (int_user_option == ADOPTION_LIST)
						{
							cout << '\n';
							vector<Pet> repo_list = this->service.get_pet_list();
							for (int i = 0; i < this->service.get_pet_list_size(); i++)
								if (repo_list[i].get_adoption() == 1)
								{
									cout << "Pet's breed: " << repo_list[i].get_breed() << '\n';
									cout << "Pet's name: " << repo_list[i].get_name() << '\n';
									cout << "Pet's age: " << repo_list[i].get_age() << '\n';
									cout << "Pet's photograph: " << repo_list[i].get_photograph() << '\n';
									cout << '\n';
									std::string fullCommand = (string)"start " + repo_list[i].get_photograph();

									system(fullCommand.c_str());
								}
						}

						else if (int_user_option == EXIT_USER)
							break;

						else
							cout << "The input option is invalid!\n";
					}
				}

			}

			else if (int_option == EXPORT)
			{
				string file_name;
				cout << "Please input the name of the file you want to save the data in (without the extension!!): ";
				getline(cin, file_name, '\n');
				this->service.export_into_file(file_name, this->user_file_option);
			}

			else if (int_option == EXIT)
			{
				cout << "Thank you for choosing our shelter!";
				this_thread::sleep_for(chrono::seconds(3));
				break;
			}

			else
				cout << "The input option is invalid!\n";

		}
		cout << '\n';
	}
}

*/

