#include "globals.h"

#include <QLabel>
#include <string>
#include <iostream>
#include "gitpp.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>

namespace searchCommits{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
		// setText("Jacks Tab");
		GITPP::REPO r;

		QLineEdit* textField=new QLineEdit();
		textField->setFont(QFont("Typewriter", 25));
		textField->setPlaceholderText("Enter your search terms here");

		QGridLayout* layout = new QGridLayout();
		layout->addWidget(textField, 0, 0);
		// layout->addWidget(searchResults, 1, 0);


		setLayout(layout);
	}
};

INSTALL_TAB(HelloWorldLabel, "Jack's Tab");

}
