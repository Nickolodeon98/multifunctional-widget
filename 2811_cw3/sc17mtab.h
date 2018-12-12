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
#include <QLabel>
#include <QVBoxLayout>

class listCommits : public QLabel{
  Q_OBJECT

  public:
    listCommits(){}
    ~ listCommits(){}

    void Execute()
    {
      //Populate combobox with branches
      QComboBox *comboBox;
      //  = new QComboBox;
      connect(comboBox, SIGNAL(currentTextChanged(QString)), SLOT(changeBranch(QString)));

    }

  public slots:
  void changeBranch( QString new_branch ) {
    std::string path=".";
    GITPP::REPO r(path.c_str());
    std::string newString = new_branch.toUtf8().constData();
    r.checkout(newString);
    this->update();
    // Execute();
  }
  //
  // void clickedSlot(QString branchName)
  // {
  //   this->update();
  //   QMessageBox msgBox;
  //   msgBox.setWindowTitle("MessageBox Title");
  //   // msgBox.setText("You Clicked "+ ((QPushButton*)sender())->text());
  //   msgBox.setText("Updating commits");
  //   //msgBox.setText(((QcomboBox*)com->itemData(comboBox->currentIndex()));
  //   msgBox.exec();
  // }
signals:
  void clickSignal(QString branchName);
};
