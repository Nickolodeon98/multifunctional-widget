#include "globals.h"

#include <QLabel>
#include <string>
#include <sstream>

#include <iostream>
#include <string>

#include "gitpp.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>
#include <QComboBox>



namespace {

class HelloWorldLabel : public QTabWidget{
public:
	HelloWorldLabel() : QTabWidget(){
    //Create git path
    std::string path=".";
  	GITPP::REPO r(path.c_str());

    //count number of branches
    int a = 0;
    for(GITPP::BRANCH i : r.branches())
    {
      a = a + 1;
    }

    //Initialise varaibales
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QGridLayout *commitLayout = new QGridLayout;
    QGridLayout *branchLayout = new QGridLayout;


    QLabel *labels[a];
    QLabel *commitInfo[a];

    a=2;
    //If more than one branch
    if(a>1)
    {
      int count = 0;

      //Populate combobox with branches
      QComboBox *comboBox = new QComboBox;
      QLineEdit* textField=new QLineEdit();
      QPushButton *updateButton = new QPushButton("Update List", this);
      connect(updateButton, SIGNAL(clicked()), this, SLOT(function()));

      count = 1;

      for(GITPP::BRANCH i : r.branches())
      {
        comboBox->addItem(QString::fromStdString(i.name()));
      }

      branchLayout->addWidget(comboBox,count+1, 0);
      branchLayout->addWidget(updateButton, count+1, 1);

      // r.checkout("new_branch");

      mainLayout->addLayout(branchLayout);
    }
    int countCommits = 0;
    for(GITPP::COMMIT i : r.commits())
    {
      countCommits = countCommits + 1;
    }

    // countCommits=countCommits+1;
    //If no commits
    if(countCommits==0)
    {
      labels[0] = new QLabel("No Commits to display!");
      labels[1] = new QLabel("Add commits to display!");

      commitLayout->addWidget(labels[0], 0, 0);
      commitLayout->addWidget(labels[1], 1, 0);


    }
    else
    {
      //List commits (upto to ten)
      int j = 0;
      for(auto i : r.commits())
      {
        if(j<10)
        {
          std::stringstream ss;
          ss << "<" << i.id() << "> \n <" << i.author() << ">\n <" << i.message() << " \n";
          std::string s = ss.str();

          //std::string commitDisplay << "<" <<  "> <" << i.author() << "> <" << i.message() << "";
          labels[j] = new QLabel(tr("%1:").arg(j + 1));
          commitInfo[j] = new QLabel(QString::fromStdString(s));

          commitLayout->addWidget(labels[j], j, 0);
          commitLayout->addWidget(commitInfo[j], j, 1);
          // QLabel* label = new QLabel("str");
          // std::cout << (j+1)<<". <" << i <<"> <"<< i.signature().name() << "> <" << i.message() << "\n";
          j = j + 1;
        }
        else
        {
          break;
        }
      }
    }
    mainLayout->addLayout(commitLayout);
    setLayout(mainLayout);
	}
};

INSTALL_TAB(HelloWorldLabel, __FILE__);

}
