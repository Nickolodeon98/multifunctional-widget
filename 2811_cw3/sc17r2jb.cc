#include "globals.h"

#include <QLabel>
#include <string>
#include <iostream>
#include "gitpp.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>

namespace{
class ConfigurationTab: public QTabWidget{
	//layouts
	QVBoxLayout *mainLayout = new QVBoxLayout;
	CoreLayout *coreLayout = new CoreLayout;
	// QGridLayout *coreLayout = new QGridLayout;
	QGridLayout *userLayout = new QGridLayout;

	QLabel *title = new QLabel("<h3>Configurations<h3>");
	//labels for core
	// QLabel *rfvLabel = new QLabel("repositoryformatversion:");
	// QLabel *rfvValueLabel = new QLabel("a");
	// QLabel *filemodeLabel = new QLabel("filemode:");
	// QLabel *fmValueLabel = new QLabel("a");
	// QLabel *bareLabel = new QLabel("bare:");
	// QLabel *bareValueLabel = new QLabel("a");
	// QLabel *logallrefupdatesLabel = new QLabel("logallrefupdates:");
	// QLabel *lruValueLabel = new QLabel("a");
	//labels for user
	QLabel *nameLabel = new QLabel("name:");
	QLabel *nameLabelValue = new QLabel("                           ");
	QLabel *emailLabel = new QLabel("email:");
	QLabel *emailValueLabel = new QLabel("                           ");
	//for updating name
	QLineEdit *nameEdit = new QLineEdit();
	QPushButton *nameButton = new QPushButton("update", this);
	//for updating email
	QLineEdit *emailEdit = new QLineEdit();
	QPushButton *emailButton = new QPushButton("update", this);

public:	ConfigurationTab(): QTabWidget(){
	//title->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	//core layout
	// coreLayout->addWidget(rfvLabel, 0, 0);
	// coreLayout->addWidget(rfvValueLabel, 0, 1);
	// coreLayout->addWidget(filemodeLabel, 1, 0);
	// coreLayout->addWidget(fmValueLabel, 1, 1);
	// coreLayout->addWidget(bareLabel, 2, 0);
	// coreLayout->addWidget(bareValueLabel, 2, 1);
	// coreLayout->addWidget(logallrefupdatesLabel, 3, 0);
	// coreLayout->addWidget(lruValueLabel, 3, 1);
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
	nameEdit->setPlaceholderText("new name here");
	emailEdit->setPlaceholderText("new email here");
	//buttons
	connect(nameButton, SIGNAL (released()), this, SLOT (handleNameButton()));		//these create issues
	connect(emailButton, SIGNAL (released()), this, SLOT (handleEmailButton()));  //these create issues
	//add to mainLayout
	mainLayout->addWidget(title);
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
INSTALL_TAB(ConfigurationTab, "Ryan's Tab"); //change to sc17r2jb
}

class CoreLayout: public QGridLayout{
	//Q_OBJECT
	QGridLayout *coreLayout = new QGridLayout;
	//labels
	QLabel *rfvLabel = new QLabel("repositoryformatversion:");
	QLabel *rfvValueLabel = new QLabel("a");
	QLabel *filemodeLabel = new QLabel("filemode:");
	QLabel *fmValueLabel = new QLabel("a");
	QLabel *bareLabel = new QLabel("bare:");
	QLabel *bareValueLabel = new QLabel("a");
	QLabel *logallrefupdatesLabel = new QLabel("logallrefupdates:");
	QLabel *lruValueLabel = new QLabel("a");

public: CoreLayout(): QGridLayout(){
	coreLayout->addWidget(rfvLabel, 0, 0);
	coreLayout->addWidget(rfvValueLabel, 0, 1);
	coreLayout->addWidget(filemodeLabel, 1, 0);
	coreLayout->addWidget(fmValueLabel, 1, 1);
	coreLayout->addWidget(bareLabel, 2, 0);
	coreLayout->addWidget(bareValueLabel, 2, 1);
	coreLayout->addWidget(logallrefupdatesLabel, 3, 0);
	coreLayout->addWidget(lruValueLabel, 3, 1);
	}
};

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
