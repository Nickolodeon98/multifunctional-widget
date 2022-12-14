#include "globals.h"
//#include "sc17r2jbWidgets.h"

#include <QLabel>
#include <QString>
#include <string>
#include <iostream>
#include "gitpp.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>

// NameButton::NameButton(){
// 	NameButton *nameButton = new NameButton("update", this); //to be changed
// }

namespace{
class ConfigurationTab: public QTabWidget{
	//layouts
	QVBoxLayout *mainLayout = new QVBoxLayout;
	QGridLayout *coreLayout = new QGridLayout;
	QGridLayout *userLayout = new QGridLayout;

	QLabel *coreLabels[5];
	QLabel *title = new QLabel("<h3>Configurations<h3>");

	QLabel *pushDefaultLabel = new QLabel("push.default:");
	//labels for core
	QLabel *rfvLabel = new QLabel("repositoryformatversion:");
	//QLabel *rfvValueLabel = new QLabel();
	QLabel *filemodeLabel = new QLabel("filemode:");
	//QLabel *fmValueLabel = new QLabel();
	QLabel *bareLabel = new QLabel("bare:");
	//QLabel *bareValueLabel = new QLabel();
	QLabel *logallrefupdatesLabel = new QLabel("logallrefupdates:");
	//QLabel *lruValueLabel = new QLabel();
	//labels for user
	QLabel *nameLabel = new QLabel("name:");
	QLabel *nameLabelValue = new QLabel("                           ");
	QLabel *emailLabel = new QLabel("email:");
	QLabel *emailValueLabel = new QLabel("                           ");
	//for updating name
	QLineEdit *nameEdit = new QLineEdit();
	QPushButton *nameButton = new QPushButton("update", this); //to be changed
	//for updating email
	QLineEdit *emailEdit = new QLineEdit();
	QPushButton *emailButton = new QPushButton("update", this); //to be changed

public:	ConfigurationTab(): QTabWidget(){
	//getting variables from .config
	GITPP::REPO r;
	int a = 0;
	for(auto i : r.config()){
		if(i.name() != "remote.origin.fetch" && i.name() != "user.stuff"){
			coreLabels[a] = new QLabel(QString::fromStdString(i.value()));
			//coreLabels[a]->setText(i.name());
			a++;
		}
	}

	title->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	//core layout
	coreLayout->addWidget(pushDefaultLabel, 0, 0);
	coreLayout->addWidget(coreLabels[0], 0, 1);
	coreLayout->addWidget(rfvLabel, 1, 0);
	coreLayout->addWidget(coreLabels[1], 1, 1);
	coreLayout->addWidget(filemodeLabel, 2, 0);
	coreLayout->addWidget(coreLabels[2], 2, 1);
	coreLayout->addWidget(bareLabel, 3, 0);
	coreLayout->addWidget(coreLabels[3], 3, 1);
	coreLayout->addWidget(logallrefupdatesLabel, 4, 0);
	coreLayout->addWidget(coreLabels[4], 4, 1);
	//user layout
	userLayout->addWidget(nameLabel, 0, 0);
	userLayout->addWidget(nameLabelValue, 0, 1);
	userLayout->addWidget(nameEdit, 0, 2);
	userLayout->addWidget(nameButton, 0, 3);
	userLayout->addWidget(emailLabel, 1, 0);
	userLayout->addWidget(emailValueLabel, 1, 1);
	userLayout->addWidget(emailEdit, 1, 2);
	userLayout->addWidget(emailButton, 1, 3);
	//line edit text
	nameEdit->setPlaceholderText("new name...");
	emailEdit->setPlaceholderText("new email here");
	//buttons
	//connect(nameButton, SIGNAL (released()), this, SLOT (handleNameButton()));		//these create issues
	//connect(emailButton, SIGNAL (released()), this, SLOT (handleEmailButton()));  //these create issues
	//add to mainLayout
	//mainLayout->addWidget(title);
	mainLayout->addLayout(coreLayout);
	mainLayout->addLayout(userLayout);
	setLayout(mainLayout);
	}
void handleNameButton(){
	nameEdit->setText("okay");
	}
void handleEmailButton(){
	emailEdit->setText("okay");
	}
};
INSTALL_TAB(ConfigurationTab, "Configurations"); //change to sc17r2jb
}


/*
class GIT_LCONFIG : public HCI_PAGE{ //prints out info
    using HCI_PAGE::HCI_PAGE;
public: // overrides
    void show(){
        GITPP::REPO r;

        std::cout << "List Configuration\n\n";

        for(auto i : r.config()){
            if (i.name() != "remote.origin.fetch" && i.name() != "user.stuff"){
                std::cout << i.name() << ": " << i.value() << "\n";
            }
        }
        std::cout << "\n";
    }
};

class GIT_CONFIG : public HCI_PAGE{ //gets new info
    using HCI_PAGE::HCI_PAGE;
public: // overrides
    char newName[20], newEmail[30];

    void show(){
        GITPP::REPO r;

        std::cout << "Configure Repository\n\n";

        std::cout << "Name: ";
        std::cin.getline(newName, 20);
        r.config()["user.name"] = newName;																			//collect username with this

        std::cout << "Email: ";
        std::cin.getline(newEmail, 30);
        r.config()["user.email"] = newEmail;																		//collect email with this

        std::cout << "\n";
    }
};
*/
