#include "globals.h"

#include <QLabel>
#include <string>
#include <iostream>
#include "gitpp.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>

namespace searchCommits{

class SearchTab : public QTabWidget{

	QGridLayout* layout = new QGridLayout();
	QGridLayout* searchResults = new QGridLayout();

	QLabel* header=new QLabel('Search your commits', layout);
	QLineEdit* searchField=new QLineEdit();
	// searchField->setFont(QFont("Typewriter", 25));
	searchField->setPlaceholderText("Enter your search terms here");
	QPushButton* updateButton = new QPushButton("Search", layout);

	QListWidget* searchResults=new QListWidget();
	QListWidgetItem* noResults = new QListWidgetItem(searchResults);



public:
	SearchTab() : QTabWidget(){

		layout->addWidget(header, 0, 0, 0, 2, Qt::AlignCenter);
		layout->addWidget(searchField, 1, 0);
		layout->addWidget(updateButton, 1, 1);
		layout->addWidget(searchResults, 2, 0, 0, 2, Qt::AlignCenter);


		connect(updateButton, SIGNAL(clicked()), SLOT(updateResults(searchField->text()));
		QString searchTerm = searchField->text();



		setLayout(layout);
	}


	public slots:
		void updateResults( QString searchTerm ) {
			GITPP::REPO r;
			for(auto i : r.commits()){
				if (i.message().find(searchTerm) != std::string::npos) {
					std::cout << i << " " << i.signature().name()
					<< "\n message: " << i.message() << "\n";
				}
				else {
					searchResults->addItem(noResults)
					noResults->setText('Sorry, no results were found.')
				}

			}
		}
};


INSTALL_TAB(SearchTab, "Jack's Tab");

}
