#include "globals.h"
#include "gitpp.h"

#include <string>
#include <sstream>

#include <iostream>
#include <string>

#include <QLabel>
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QObject>

namespace repo{
class createRepositoryTab : public QTabWidget{

public:	createRepositoryTab(): QTabWidget(){
	// std::string path=".";
	// GITPP::REPO r(path.c_str());

	QVBoxLayout *layout = new QVBoxLayout;
	QGridLayout *grid = new QGridLayout;

	//LABELS//
	QLabel *title = new QLabel("<h3>Create or select repository<h3>");
	title-> setAlignment(Qt::AlignCenter);

	QLabel *OR = new QLabel("OR");
	OR->setAlignment(Qt::AlignCenter);

	//BUTTONS//
	QPushButton *createButton = new QPushButton("Create repository");
	QObject::connect(createButton, SIGNAL(released()), SLOT(handleCreateButton));
	//connect(createButton, SIGNAL(released()), SLOT (handleCreateButton()));

	QPushButton *selectButton = new QPushButton("Select repository", this);
	connect(createButton, SIGNAL(released()), this, SLOT (handleSelectButton()));

	//COMBOBOX
	QComboBox *comboBox = new QComboBox;
	comboBox-> setFont(QFont("Times Roman", 20));
	comboBox->addItem("REPO1.git");
	comboBox->addItem("REPO2.git");
	comboBox->addItem("use file explorer");

	QLineEdit* textField=new QLineEdit();
	textField->setFont(QFont("Typewriter", 20));
	textField->setPlaceholderText("Name of new repository");

	layout-> addWidget(title);
	layout-> addWidget(textField);
	layout-> addWidget(createButton);
	layout-> addWidget(OR);
	layout-> addWidget(comboBox);
	layout-> addWidget(selectButton);

	layout->addLayout(grid);
	setLayout(layout);
}

public slots:
	void handleCreateButton(){
		std::string path=".";
		GITPP::REPO r(GITPP::REPO::_create, path.c_str());
		QMessageBox msgBox;
		msgBox.setText("Success");
		msgBox.exec();
	}

	void handleSelectButton(){
		QFileDialog dialog(this);
		dialog.setFileMode(QFileDialog::AnyFile);
	}

};
INSTALL_TAB(createRepositoryTab, "CreateSelectRepo");

}
