#include "globals.h"

#include <QLabel>
#include <QtWidgets>
#include <QComboBox>
#include "gitpp.h"
#include <iostream>
#include <sstream>
#include <string>

namespace{
class createRepositoryTab : public QTabWidget{
	QVBoxLayout *layout = new QVBoxLayout;

	QLabel *title = new QLabel("Create or select repository");
	QPushButton *createButton = new QPushButton("Create repository", this);


public:	createRepositoryTab(): QTabWidget(){
	std::string path=".";
	try{
		GITPP::REPO r(path.c_str());
	}
	catch(GITPP::EXCEPTION_CANT_FIND const&)
	{
		QLabel *hi = new QLabel("Hiiii");
		layout-> addWidget(hi);
	}

	title->setAlignment(Qt::AlignCenter);

	connect(createButton, SIGNAL (released()), this, SLOT (handleCreateButton()));

	layout-> addWidget(title);
	//layout-> addWidget(hi);
	layout-> addWidget(createButton);
	setLayout(layout);
}
};

// class HelloWorldLabel : public QLabel{
// public:
// 	HelloWorldLabel() : QLabel(){
// 		setText("hiiiiiii");
// 		std::string path=".";
// 		try{
// 			GITPP::REPO r(path.c_str());
// 		}
// 		catch(GITPP::EXCEPTION_CANT_FIND const&)
// 		{
// 			setText("hiii");
// 		}
// 	}
// };

INSTALL_TAB(createRepositoryTab, "Cyrus's Tab");

}
