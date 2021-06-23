#include "notes.h"
#include "ui_notes.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QWindow>
#include <iostream>
#include <QFrame>
#include <QFileInfo>
#include <QDebug>

Notes::Notes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notes)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
}

Notes::~Notes()
{
    delete ui;
}


void Notes::on_actionNew_triggered()
{
    FilePath = "";
    ui->plainTextEdit->setPlainText("");
    QFileInfo FileInfo(QDir::currentPath());
    QString FileName = FileInfo.fileName();
    QMainWindow MW ;
    MW.setWindowTitle(FileName);
}


void Notes::on_actionOpen_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this , "Open the File");
    QFile File(FileName);
    FilePath = FileName;
    if(!File.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this , "Warning" , "Unable to Open the file");
        return ;
    }
    QTextStream in(&File);

    QString Text = in.readAll();
    ui->plainTextEdit->setPlainText(Text);
    File.close();
}


void Notes::on_actionSave_triggered()
{
    QFile File(FilePath);
    if(!File.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::critical(this , "" , "Unable to Save the file");
        return ;
    }
    QTextStream out(&File);
    QString Text = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->setPlainText(Text);
    out << Text;
    File.flush();
    File.close();
}


void Notes::on_actionSave_As_triggered()
{
    QString FileName = QFileDialog::getSaveFileName(this , "Save the File");
    QFile File(FileName);
    FilePath = FileName;
    if(!File.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::critical(this , "Error" , "Unable to Open the file");
        return ;
    }
    QTextStream out(&File);
    QString Text = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->setPlainText(Text);
    out << Text;
    File.flush();
    File.close();
}


void Notes::on_actionExit_triggered()
{
    QMessageBox::StandardButton Reply;
    Reply = QMessageBox::question(this , "Warning" , "Do you really Want to Exit", QMessageBox::Yes|QMessageBox::No);
    if(Reply == QMessageBox::Yes)
        close();
    else if(Reply == QMessageBox::No)
        return;
}


void Notes::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}


void Notes::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void Notes::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}


void Notes::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}


void Notes::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}


void Notes::on_actionFull_Screen_triggered()
{
    QWidget::showFullScreen();
}


void Notes::on_actionExit_Full_Screen_triggered()
{
    QWidget::showMaximized();
}


void Notes::on_actionNew_Window_triggered()
{
    QMainWindow *NewWindow = new Notes ;
    NewWindow->show();
}


