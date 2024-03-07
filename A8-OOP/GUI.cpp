#include "GUI.h"

GUI::GUI(QWidget* parent): QMainWindow{parent}
{
	
	auto dogs1=filerepo.read_from_file();
	this->dogs = dogs1;
	this->initMainMenu();
	this->initModeMenu();
	this->initAdminMenu();
	this->mainMenuConnect();
	this->modeMenuConnect();
	this->adminMenuConnect();
	this->adminAddMenuConnect();
	this->adminDeleteMenuConnect();
	this->adminUpdateMenuConnect();
	this->setCentralWidget(this->mainWidget);
	this->resize(150, 70);

}

GUI::~GUI()
{
	std::vector<Pet> dogss = this->dogs;
	std::ofstream file("dogs");
	for (auto d : dogss) {
		file << d;
	}
	file.close();
}

void GUI::initMainMenu()
{
	this->mainWidget = new QWidget{};
	this->mainMenu = new QVBoxLayout{};
	this->CSVRepoButton = new QPushButton{ "CSV Repository" };
	this->HTMLRepoButton = new QPushButton{ "HTML Repository" };
	this->mainMenu->addWidget(this->CSVRepoButton);
	this->mainMenu->addWidget(this->HTMLRepoButton);
	this->mainWidget->setLayout(this->mainMenu);
}

void GUI::initModeMenu()
{
	this->modeWidget = new QWidget{};
	this->modeMenu = new QVBoxLayout{};
	this->adminModeButton = new QPushButton{ "Admin Mode" };
	this->userModeButton = new QPushButton{ "User Mode" };
	this->modeMenu->addWidget(this->adminModeButton);
	this->modeMenu->addWidget(this->userModeButton);
	this->modeWidget->setLayout(this->modeMenu);
}

void GUI::populateList(std::vector<Pet> dogs)
{
	
	this->adminDogsList->clear();
	for (auto d : dogs)
		this->adminDogsList->addItem(QString::fromStdString(d.toString()));
}

void GUI::initAdminMenu()
{
	this->adminWidget = new QWidget{};
	this->adminMenu = new QVBoxLayout{};
	//admin mode menu components

	//list component
	this->adminListLayout = new QVBoxLayout{};

	//list modifier operations component
	this->adminListModifierLayout = new QVBoxLayout{};

	this->adminMenu->addLayout(this->adminListLayout);
	this->adminMenu->addLayout(this->adminListModifierLayout);

	//list component structure
	this->adminDogsList = new QListWidget{};
	this->adminListLayout->addWidget(this->adminDogsList);

	//list modifier operations component structure
	this->adminAddButton = new QPushButton{ "Add dog" };
	this->adminDeleteButton = new QPushButton{ "Delete dog" };
	this->adminUpdateButton = new QPushButton{ "Update dog" };
	this->adminExitButton = new QPushButton{ "Exit" };
	this->adminListModifierLayout->addWidget(this->adminAddButton);
	this->adminListModifierLayout->addWidget(this->adminDeleteButton);
	this->adminListModifierLayout->addWidget(this->adminUpdateButton);
	this->adminListModifierLayout->addWidget(this->adminExitButton);

	this->adminWidget->setLayout(this->adminMenu);


	// add operation menu components
	//add has it's own window with a form
	this->adminAddWidget = new QWidget{};
	this->adminAddLayout = new QVBoxLayout{};

	//add form components
	this->adminAddForm = new QFormLayout{};
	this->adminAddBreedLabel = new QLabel{ "Breed: " };
	this->adminAddBreedEdit = new QLineEdit{};
	this->adminAddBreedLabel->setBuddy(this->adminAddBreedEdit);
	this->adminAddNameLabel = new QLabel{ "Name: " };
	this->adminAddNameEdit = new QLineEdit{};
	this->adminAddNameLabel->setBuddy(this->adminAddNameEdit);
	this->adminAddAgeLabel = new QLabel{ "Age: " };
	this->adminAddAgeEdit = new QLineEdit{};
	this->adminAddAgeLabel->setBuddy(this->adminAddAgeEdit);
	this->adminAddPhotoLabel = new QLabel{ "Photo: " };
	this->adminAddPhotoEdit = new QLineEdit{};
	this->adminAddPhotoLabel->setBuddy(this->adminAddPhotoEdit);
	this->adminAddForm->addRow(this->adminAddBreedLabel, this->adminAddBreedEdit);
	this->adminAddForm->addRow(this->adminAddNameLabel, this->adminAddNameEdit);
	this->adminAddForm->addRow(this->adminAddAgeLabel, this->adminAddAgeEdit);
	this->adminAddForm->addRow(this->adminAddPhotoLabel, this->adminAddPhotoEdit);
	this->adminAddLayout->addLayout(this->adminAddForm);

	//add buttons components
	this->adminAddButtonsLayout = new QHBoxLayout{};
	this->adminAdd2Button = new QPushButton{ "Add" };
	this->adminAddCancelButton = new QPushButton{ "Cancel" };
	this->adminAddButtonsLayout->addWidget(this->adminAdd2Button);
	this->adminAddButtonsLayout->addWidget(this->adminAddCancelButton);
	this->adminAddLayout->addLayout(this->adminAddButtonsLayout);

	//set the layout for the window
	this->adminAddWidget->setLayout(this->adminAddLayout);

	//delete operation menu components
	this->adminDeleteWidget = new QWidget{};
	this->adminDeleteLayout = new QVBoxLayout{};

	//delete form components
	this->adminDeleteForm = new QFormLayout{};
	this->adminDeleteBreedLabel = new QLabel{ "Breed: " };
	this->adminDeleteBreedEdit = new QLineEdit{};
	this->adminDeleteBreedLabel->setBuddy(this->adminDeleteBreedEdit);
	this->adminDeleteNameLabel = new QLabel{ "Name: " };
	this->adminDeleteNameEdit = new QLineEdit{};
	this->adminDeleteNameLabel->setBuddy(this->adminDeleteNameEdit);
	this->adminDeleteForm->addRow(this->adminDeleteBreedLabel, this->adminDeleteBreedEdit);
	this->adminDeleteForm->addRow(this->adminDeleteNameLabel, this->adminDeleteNameEdit);
	this->adminDeleteLayout->addLayout(this->adminDeleteForm);

	//delete buttons components
	this->adminDeleteButtonsLayout = new QHBoxLayout{};
	this->adminDelete2Button = new QPushButton{ "Delete" };
	this->adminDeleteCancelButton = new QPushButton{ "Cancel" };
	this->adminDeleteButtonsLayout->addWidget(this->adminDelete2Button);
	this->adminDeleteButtonsLayout->addWidget(this->adminDeleteCancelButton);
	this->adminDeleteLayout->addLayout(this->adminDeleteButtonsLayout);

	//set layout for the window
	this->adminDeleteWidget->setLayout(this->adminDeleteLayout);

	//update operation menu components
	this->adminUpdateWidget = new QWidget{};
	this->adminUpdateLayout = new QVBoxLayout{};

	//update form components
	this->adminUpdateForm = new QFormLayout{};
	this->adminUpdateBreedLabel = new QLabel{ "Breed: " };
	this->adminUpdateBreedEdit = new QLineEdit{};
	this->adminUpdateBreedLabel->setBuddy(this->adminUpdateBreedEdit);
	this->adminUpdateNameLabel = new QLabel{ "Name: " };
	this->adminUpdateNameEdit = new QLineEdit{};
	this->adminUpdateNameLabel->setBuddy(this->adminUpdateNameEdit);
	this->adminUpdateNewBreedLabel = new QLabel{ "New breed: " };
	this->adminUpdateNewBreedEdit = new QLineEdit{};
	this->adminUpdateNewBreedLabel->setBuddy(this->adminUpdateNewBreedEdit);
	this->adminUpdateNewNameLabel = new QLabel{ "New name: " };
	this->adminUpdateNewNameEdit = new QLineEdit{};
	this->adminUpdateNewNameLabel->setBuddy(this->adminUpdateNewNameEdit);
	this->adminUpdateNewAgeLabel = new QLabel{ "New age: " };
	this->adminUpdateNewAgeEdit = new QLineEdit{};
	this->adminUpdateNewAgeLabel->setBuddy(this->adminUpdateNewAgeEdit);
	this->adminUpdateNewPhotoLabel = new QLabel{ "New photo: " };
	this->adminUpdateNewPhotoEdit = new QLineEdit{};
	this->adminUpdateNewPhotoLabel->setBuddy(this->adminUpdateNewPhotoEdit);

	this->adminUpdateForm->addRow(this->adminUpdateBreedLabel, this->adminUpdateBreedEdit);
	this->adminUpdateForm->addRow(this->adminUpdateNameLabel, this->adminUpdateNameEdit);
	this->adminUpdateForm->addRow(this->adminUpdateNewBreedLabel, this->adminUpdateNewBreedEdit);
	this->adminUpdateForm->addRow(this->adminUpdateNewNameLabel, this->adminUpdateNewNameEdit);
	this->adminUpdateForm->addRow(this->adminUpdateNewAgeLabel, this->adminUpdateNewAgeEdit);
	this->adminUpdateForm->addRow(this->adminUpdateNewPhotoLabel, this->adminUpdateNewPhotoEdit);

	this->adminUpdateLayout->addLayout(this->adminUpdateForm);

	//update buttons components
	this->adminUpdateButtonsLayout = new QHBoxLayout{};
	this->adminUpdate2Button = new QPushButton{ "Update" };
	this->adminUpdateCancelButton = new QPushButton{ "Cancel" };
	this->adminUpdateButtonsLayout->addWidget(this->adminUpdate2Button);
	this->adminUpdateButtonsLayout->addWidget(this->adminUpdateCancelButton);
	this->adminUpdateLayout->addLayout(this->adminUpdateButtonsLayout);

	//set layout for the window
	this->adminUpdateWidget->setLayout(this->adminUpdateLayout);

}

void GUI::mainMenuConnect()
{
	QObject::connect(this->CSVRepoButton, &QPushButton::clicked, this, [this]() {
		std::unique_ptr<FileRepository> repo = std::make_unique<FileRepositoryCSV>("AdoptionList.csv");
		this->Service.setRepo(std::move(repo));
		std::ifstream coats("Dogs");
		Pet dog;
		while (coats >> dog) {
			this->Service.add_pet(dog.get_breed(), dog.get_name(), dog.get_age()
				, dog.get_photograph());
		}
		coats.close();
		this->setCentralWidget(this->modeWidget);
		});

	QObject::connect(this->HTMLRepoButton, &QPushButton::clicked, this, [this]() {
		std::unique_ptr<FileRepository> repo = std::make_unique<FileRepositoryHTML>("AdoptionList.html");
		this->Service.setRepo(std::move(repo));
		std::ifstream coats("Dogs");
		Pet dog;
		while (coats >> dog) {
			this->Service.add_pet(dog.get_breed(), dog.get_name(), dog.get_age()
				, dog.get_photograph());
		}
		coats.close();
		this->setCentralWidget(this->modeWidget);
		this->Service.get_filename();
		});
}

void GUI::modeMenuConnect()
{
	QObject::connect(this->adminModeButton, &QPushButton::clicked, this, [this]() {
		QWidget* modeMenuWidget = this->modeMenu->parentWidget();
		QWidget* placeholderWidget = new QWidget(this);
		modeMenuWidget->setParent(placeholderWidget);

		this->setCentralWidget(this->adminWidget);
		this->populateList(this->dogs);

		modeMenuWidget->setParent(this);
		delete placeholderWidget;
		this->resize(300, 400);
		});

	QObject::connect(this->userModeButton, &QPushButton::clicked, this, [this]() {
		QWidget* modeMenuWidget = this->modeMenu->parentWidget();
		QWidget* placeholderWidget = new QWidget(this);
		modeMenuWidget->setParent(placeholderWidget);

		this->setCentralWidget(this->userWidget);

		modeMenuWidget->setParent(this);
		delete placeholderWidget;

		this->resize(300, 400);
		});
}

void GUI::adminMenuConnect()
{
	QObject::connect(this->adminAddButton, &QPushButton::clicked, this, [this]() {
		this->adminAddWidget->show();
		});

	QObject::connect(this->adminDeleteButton, &QPushButton::clicked, this, [this]() {
		this->adminDeleteWidget->show();
		});
	QObject::connect(this->adminUpdateButton, &QPushButton::clicked, this, [this]() {
		this->adminUpdateWidget->show();
		});
	QObject::connect(this->adminExitButton, &QPushButton::clicked, this, [this]() {
		QWidget* adminMenuWidget = this->adminMenu->parentWidget();
		QWidget* placeholderWidget = new QWidget(this);
		adminMenuWidget->setParent(placeholderWidget);

		this->setCentralWidget(this->modeWidget);

		adminMenuWidget->setParent(this);
		delete placeholderWidget;

		this->resize(150, 70);
		});
}

void GUI::adminAddMenuConnect()
{
	QObject::connect(this->adminAdd2Button, &QPushButton::clicked, this, [this]() {
		std::string breed = this->adminAddBreedEdit->text().toStdString();
		std::string name = this->adminAddNameEdit->text().toStdString();
		std::string age = this->adminAddAgeEdit->text().toStdString();
		std::string photograph = this->adminAddPhotoEdit->text().toStdString();
		try {
			Validator::validateDog(breed, name, age, photograph);
			this->Service.add_pet(breed, name, age, photograph);
			this->populateList(this->dogs);
			this->adminAddWidget->close();
		}
		catch (InputException& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.message()));
		}
		catch (RepositoryException& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.message()));
		}
		});
	QObject::connect(this->adminAddCancelButton, &QPushButton::clicked, this, [this]() {
		this->adminAddWidget->close();
		});
}

void GUI::adminDeleteMenuConnect()
{
	QObject::connect(this->adminDelete2Button, &QPushButton::clicked, this, [this]() {
		std::string breed = this->adminDeleteBreedEdit->text().toStdString();
		std::string name = this->adminDeleteNameEdit->text().toStdString();
		try {
			Validator::validateDog(breed, name, "0",  "abc");
			this->Service.remove_pet(name);
			this->populateList(this->dogs);
			this->adminDeleteWidget->close();
		}
		catch (InputException& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.message()));
		}
		catch (RepositoryException& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.message()));
		}
		});
	QObject::connect(this->adminDeleteCancelButton, &QPushButton::clicked, this, [this]() {
		this->adminDeleteWidget->close();
		});
}

void GUI::adminUpdateMenuConnect()
{
	QObject::connect(this->adminUpdate2Button, &QPushButton::clicked, this, [this]() {
		std::string breed = this->adminUpdateBreedEdit->text().toStdString();
		std::string name = this->adminUpdateNameEdit->text().toStdString();
		std::string newBreed = this->adminUpdateNewBreedEdit->text().toStdString();
		std::string newName = this->adminUpdateNewNameEdit->text().toStdString();
		std::string newAge = this->adminUpdateNewAgeEdit->text().toStdString();
		std::string newPhotograph = this->adminUpdateNewPhotoEdit->text().toStdString();
		try {
			Validator::validateDog(newBreed, newName, newAge, newPhotograph);
			this->Service.update_pet( newBreed, newName, newAge,newPhotograph);
			this->populateList(this->dogs);
			this->adminUpdateWidget->close();
		}
		catch (InputException& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.message()));
		}
		catch (RepositoryException& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.message()));
		}
		});
	QObject::connect(this->adminUpdateCancelButton, &QPushButton::clicked, this, [this]() {
		this->adminUpdateWidget->close();
		});
}


