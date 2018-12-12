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

namespace commits
{
class listCommits : public QLabel{
public:
    listCommits() : QLabel(){
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


      //Declaring labels
      QLabel *labels[20];
      QLabel *commitInfo[20];
      //If more than one branch show combobox and Button
      if(a>1)
      {
        int count = 0;

        QComboBox *comboBox = new QComboBox;
        QPushButton *updateButton = new QPushButton("Update Button", this);
        //connect comboBox, when chagned send text to function
        connect(comboBox, SIGNAL(currentTextChanged(QString)), SLOT(changeBranch(QString)));

        count = 1;
        //Populate combobox with branch names
        for(GITPP::BRANCH i : r.branches())
        {
          comboBox->addItem(QString::fromStdString(i.name()));
        }
        //add combobox and update button
        branchLayout->addWidget(comboBox,count+1, 0);
        branchLayout->addWidget(updateButton, count+1, 1);

        //set layout
        mainLayout->addLayout(branchLayout);
      }

      int countCommits = 0;
      for(GITPP::COMMIT i : r.commits())
      {
        countCommits = countCommits + 1;
      }

      //If no commits
      if(countCommits==0)
      {
        labels[0] = new QLabel("No Commits to display!");
        labels[1] = new QLabel("Add commits to display!");

        commitLayout->addWidget(labels[0], 0, 0);
        commitLayout->addWidget(labels[1], 1, 0);
      }
      //If there are commits
      else
      {
        labels[0] = new QLabel("Listing commits...");
        mainLayout->addWidget(labels[0], 0, 0);


        int j = 1;
        //loop through all commits upto ten
        for(auto i : r.commits())
        {
          if(j<11)
          {
            //create message and convert to correct data type
            std::stringstream ss;
            ss << "<" << i.id() << "> \n <" << i.author() << ">\n <" << i.message() << " \n";
            std::string s = ss.str();

            //Add label, iteratae upto ten
            labels[j] = new QLabel(tr("%1:").arg(j));
            commitInfo[j] = new QLabel(QString::fromStdString(s));

            commitLayout->addWidget(labels[j], j, 0);
            commitLayout->addWidget(commitInfo[j], j, 1);
            j = j + 1;
          }
          else
          {
            break;
          }
        }
      }
      //Add layouts then set main
      mainLayout->addLayout(commitLayout);
      setLayout(mainLayout);
      show();
    }
  public slots:
    //gets combobox value then uses it to checkout
    void changeBranch( QString new_branch )
    {
      std::string path=".";
      GITPP::REPO r(path.c_str());
      std::string newString = new_branch.toUtf8().constData();
      r.checkout(newString);
      this->update();
    }
  };
INSTALL_TAB(listCommits, "List Commit's" );
}
