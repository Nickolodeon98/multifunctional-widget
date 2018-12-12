#include "globals.h"

#include <QLabel>
#include <QWidget>
#include <QGridLayout>
#include <QtWidgets>
#include <gitpp.h>
#include <QString>
#include <iostream>
namespace{

class StatisticsTab : public QTabWidget{
	QVBoxLayout * base = new QVBoxLayout;
	QGridLayout * background = new QGridLayout;
	QLabel * commitsNo = new QLabel("The number of commits: ");
	QLabel * branchesNo = new QLabel("The number of branches: ");
	QPushButton * showInfo = new QPushButton("show user info");
	QLabel * commit = new QLabel("0");
	QLabel * branch = new QLabel("0");
		QLabel * countC = new QLabel(this);
		QLabel * countB = new QLabel(this);
public:
	StatisticsTab() : QTabWidget(){

		// QLabel * example = new QLabel("This is a widget example");
		background->addWidget(commitsNo, 0, 0);
		background->addWidget(branchesNo, 1, 0);
		background->addWidget(showInfo, 2, 0);
		// example->show();
		std::string path = ".";
		GITPP::REPO r(path.c_str());


		int countNoC = 0;




		for(GITPP::COMMIT i : r.commits()){
			countNoC = countNoC + 1;
		}
		// QLabel * commit = new QLabel(this);
		if(countNoC > 0){
			countC->setText( QString::number(countNoC) );

			background->addWidget(countC, 0, 1);
		}
		else {

			background->addWidget(commit, 0, 1);
		}
		int countNoB= 0;




		for(GITPP::BRANCH i : r.branches()){
			countNoB = countNoB + 1;
		}
		// QLabel * commit = new QLabel(this);
		if(countNoB > 0){
			countB->setText( QString::number(countNoB) );

			background->addWidget(countB, 1, 1);
		}
		else {

			background->addWidget(branch, 1, 1);
		}
		base->addLayout(background);
		setLayout(base);
	}
};

// class StatisticsWidget : public QLabel{
// public:
// 	StatisticsWidget() : QLabel(){
// 		QLabel * example = new QLabel("This is a widget example");
// 		example->show();
// 	}
// };

INSTALL_TAB(StatisticsTab, __FILE__);
// INSTALL_TAB(StatisticsWidget, "Seunghwan's Tab");

}

// class showNoC {
// 	public:
// 		void printout(){
//
// 			int countC = 0;
// 			for(GITPP::COMMITS i : r.commits()){
// 				countC += 1;
// 			}
// 	}
// }
