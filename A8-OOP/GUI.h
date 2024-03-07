#pragma once
#include <qwidget.h>
#include <QtWidgets>
#include "A8Ioana.h"
#include "GUI.h"
#include <vector>


#include <memory>
#include "../../../../Desktop/a7-Botezatu-Ioana/Service.h"
#include "../../../../Desktop/a7-Botezatu-Ioana/Pet.h"
#include "../../../../Desktop/a7-Botezatu-Ioana/Validator.h"

class GUI: public QMainWindow
{
	Q_OBJECT;
private:
	Service Service;
	FileRepository filerepo;
	std::vector<Pet> dogs;
	

	//window
	QWidget* window;

	//repository menu components
	QWidget* mainWidget;
	QVBoxLayout* mainMenu;
	QPushButton* CSVRepoButton;
	QPushButton* HTMLRepoButton;

	//mode menu components
	QWidget* modeWidget;
	QVBoxLayout* modeMenu;
	QPushButton* adminModeButton;
	QPushButton* userModeButton;

	//admin menu components
	QWidget* adminWidget;
	QVBoxLayout* adminMenu;
	QVBoxLayout* adminListLayout;
	QVBoxLayout* adminListModifierLayout;
	QListWidget* adminDogsList;
	QPushButton* adminAddButton;
	QPushButton* adminDeleteButton;
	QPushButton* adminUpdateButton;
	QPushButton* adminExitButton;




	//admin button pop up windows
	// add menu components
	QWidget* adminAddWidget;
	QVBoxLayout* adminAddLayout;
	QFormLayout* adminAddForm;
	QLabel* adminAddBreedLabel;
	QLineEdit* adminAddBreedEdit;
	QLabel* adminAddNameLabel;
	QLineEdit* adminAddNameEdit;
	QLabel* adminAddAgeLabel;
	QLineEdit* adminAddAgeEdit;
	QLabel* adminAddPhotoLabel;
	QLineEdit* adminAddPhotoEdit;
	QHBoxLayout* adminAddButtonsLayout;
	QPushButton* adminAdd2Button;
	QPushButton* adminAddCancelButton;

	// delete menu components
	QWidget* adminDeleteWidget;
	QVBoxLayout* adminDeleteLayout;
	QFormLayout* adminDeleteForm;
	QLabel* adminDeleteBreedLabel;
	QLineEdit* adminDeleteBreedEdit;
	QLabel* adminDeleteNameLabel;
	QLineEdit* adminDeleteNameEdit;
	QHBoxLayout* adminDeleteButtonsLayout;
	QPushButton* adminDelete2Button;
	QPushButton* adminDeleteCancelButton;

	// update menu components
	QWidget* adminUpdateWidget;
	QVBoxLayout* adminUpdateLayout;
	QFormLayout* adminUpdateForm;
	QLabel* adminUpdateBreedLabel;
	QLineEdit* adminUpdateBreedEdit;
	QLabel* adminUpdateNameLabel;
	QLineEdit* adminUpdateNameEdit;
	QLabel* adminUpdateNewBreedLabel;
	QLineEdit* adminUpdateNewBreedEdit;
	QLabel* adminUpdateNewNameLabel;
	QLineEdit* adminUpdateNewNameEdit;
	QLabel* adminUpdateNewAgeLabel;
	QLineEdit* adminUpdateNewAgeEdit;
	QLabel* adminUpdateNewPhotoLabel;
	QLineEdit* adminUpdateNewPhotoEdit;
	QHBoxLayout* adminUpdateButtonsLayout;
	QPushButton* adminUpdate2Button;
	QPushButton* adminUpdateCancelButton;

	//user menu components
	QWidget* userWidget;
	QVBoxLayout* userMenu;



public:
	//qmainwindow constructor
	GUI(QWidget* parent = 0);
	~GUI();
	void initMainMenu();
	void initModeMenu();
	void populateList(std::vector<Pet> dogs);
	void initAdminMenu();


	void mainMenuConnect();
	void modeMenuConnect();
	void adminMenuConnect();
	void adminAddMenuConnect();
	void adminDeleteMenuConnect();
	void adminUpdateMenuConnect();
};

