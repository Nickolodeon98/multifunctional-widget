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

namespace listCommits{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
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
    QGridLayout* layout = new QGridLayout();
    QLabel *labels[a];
    QLineEdit *lineEdits[a];
    QLabel *branchInfo[a];
    QLabel *commitInfo[a];

    a=2;
    //If more than one branch
    if(a>1)
    {
      int count = 0;

      //List all branches
      QLineEdit* textField=new QLineEdit();
      textField->setFont(QFont("Typewriter", 15));
      textField->setPlaceholderText("Select Branch Name...");
      layout->addWidget(textField, count+1, 0);

      labels[count] = new QLabel(textField->text());
      layout->addWidget(labels[count],10, 0);

      count = 1;

      for(auto i : r.branches())
      {
        labels[count] = new QLabel(tr("%1:").arg(count));
        branchInfo[count] = new QLabel(QString::fromStdString(i.name()));

        layout->addWidget(branchInfo[count], count+1, 1);
        layout->addWidget(labels[count], count+1, 0);

        count = count + 1;
      }

      //Get input to show which branch
      // QPushButton* button = qobject_cast<QPushButton*>( textField );
      //
      // if ( button )
      // {
      //   connect( button, SIGNAL(clicked()), this, SLOT(keyboardButtonPressed()) );
      // }

      // GITPP::REPO* repository=nullptr;
      // QLabel* label = new QLabel("str");
      // layout->addWidget(label,a,0);
      // ) << "select a branch to display commits\n";


      // a = 0;
      // for(GITPP::BRANCH i : r.branches())
      // {
      //   std::cout << a << " "<< i <<"\n" ;
      //   a = a + 1;
      // }

      // r.checkout("new_branch");

      //List commits for the branch
      if(1==1) //On Submit of textField
      {
        for(auto i : r.branches())
        {
          if(textField->text() == QString::fromStdString(i.name()))
          {
            // r.checkout(textField->text());                                     //////ADD checkout funcion
          }
        }
        // try
        // {
        //   repository=new GITPP::REPO();
        // }catch(GITPP::EXCEPTIONCANTFIND const& e)
        // {
        //   QMessageBox errordialog(QMessageBox::Critical, "err";
        //   errordialog.exec();
        // }
        // std::string str = std::to_string(a);
        int j = 0 ;
        int gridValue = a + 1;
        for(auto i : r.commits())
        {
          std::stringstream ss;
          ss << "<" << i.id() << "> <" << i.author() << "> <" << i.message() << "";
          std::string s = ss.str();

          //std::string commitDisplay << "<" <<  "> <" << i.author() << "> <" << i.message() << "";
          labels[j] = new QLabel(tr("%1:").arg(j + 1));
          commitInfo[j] = new QLabel(QString::fromStdString(s));

          layout->addWidget(labels[j], gridValue + 1, 0);
          layout->addWidget(commitInfo[j], gridValue + 1, 1);
          if(j<10)
          {
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
    }
    else
    {
      //Count commits
      int countCommits = 0;
      for(auto i : r.commits())
      {
        countCommits = countCommits + 1;
      }

      //If no commits
      if(countCommits==0)
      {
        labels[0] = new QLabel("Not Commits to display!");
        labels[1] = new QLabel("Add commits to display!");

        layout->addWidget(labels[0], 0, 0);
        layout->addWidget(labels[1], 1, 0);


      }
      else
      {
        //List commits (upto to ten)
        int j = 0;
        for(auto i : r.commits())
        {
          if(j<10)
          {
            labels[j] = new QLabel(tr("%1:").arg(j + 1));
            lineEdits[j] = new QLineEdit;
            layout->addWidget(labels[j], j + 1, 0);
            layout->addWidget(lineEdits[j], j + 1, 1);
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
    }
		setLayout(layout);
	}
};

INSTALL_TAB(HelloWorldLabel, __FILE__);

}
