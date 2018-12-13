#include "globals.h"
// #include "sc17j4a.h"

#include <QLabel>
#include <string>
#include <iostream>
#include "gitpp.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>

namespace SearchTab{

class SearchTab : public QTabWidget{
private:
	Q_OBJECT

	QGridLayout* layout = new QGridLayout();
	QGridLayout* headerLayout = new QGridLayout();

	QLabel* header=new QLabel("Search your commits");
	QLineEdit* searchField=new QLineEdit();
	// searchField->setFont(QFont("Typewriter", 25));
	QString placeholder = "Enter your search terms here";

	QPushButton* updateButton = new QPushButton("Search", this);

	QListWidget* searchResults=new QListWidget();
	QString noRes = "Sorry, no results were found.";



public:
	SearchTab(){
		searchField->setPlaceholderText(placeholder);

		headerLayout->addWidget(header, 0, 0, 1, 2, Qt::AlignCenter);
		headerLayout->addWidget(searchField, 1, 0);
		headerLayout->addWidget(updateButton, 1, 1);
		layout->addLayout(headerLayout, 0, 0, 1, 3, Qt::AlignCenter);
		layout->addWidget(searchResults, 1, 0, 3, 3, Qt::AlignCenter);


		connect(updateButton, SIGNAL(clicked()), this, SLOT(updateResults()));




		setLayout(layout);
	}

	// SearchTab() : ~SearchTab(){
	// 	delete layout;
	// 	delete header;
	// 	delete headerLayout;
	// 	delete searchField;
	// 	delete updateButton;
	// 	delete searchResults;
	// 	delete noResults;
	// }


public slots:
		void updateResults(){
			//clears list
			searchResults->blockSignals(true); //required to avoid seg fault
			searchResults->clear();
			searchResults->blockSignals(false);

			std::string searchTerm = searchField->text().toStdString();

			GITPP::REPO r;
			for(auto i : r.commits()){
				if (i.message().find(searchTerm) != std::string::npos) { //if term found
					std::string tempString = i.id() + " " + i.signature().name()
					+ "\n message: " + i.message(); //converts commit to string
					QString temp = QString::fromStdString(tempString);
					searchResults->addItem(new QListWidgetItem(temp, searchResults));
				} else if (searchResults->count()==0) {
					searchResults->addItem(new QListWidgetItem(noRes, searchResults));
			}
			}

		}
};


INSTALL_TAB(SearchTab, "Jack's Tab");

}

#include "sc17j4a.moc"
