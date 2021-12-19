#include "texteditor.h"
#include "ui_texteditor.h"


texteditor::texteditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::texteditor)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->plainTextEdit);

    ui->actionNew->setShortcut(tr("Ctrl+N"));
    ui->actionOpen->setShortcut(tr("Ctrl+O"));
    ui->actionSave->setShortcut(tr("Ctrl+S"));
    ui->actionSave_As->setShortcut(tr("Ctrl+Schift+S"));
    ui->actionExit->setShortcut(tr("Ctrl+Q"));
    ui->actionCopy->setShortcut(tr("Ctrl+C"));
    ui->actionPaste->setShortcut(tr("Ctrl+V"));
    ui->actionCut->setShortcut(tr("Ctrl+X"));
    ui->actionUndo_Ctrl_Z->setShortcut(tr("Ctrl+Z"));
    ui->actionRedo_Ctrl_Y->setShortcut(tr("Ctrl+Y"));
}

texteditor::~texteditor()
{
    delete ui;
}


void texteditor::on_actionNew_triggered()
{

    ui->plainTextEdit->clear();
    ui->statusbar->showMessage("");





}

void texteditor::on_actionOpen_triggered()
{

    QString path = QFileDialog :: getOpenFileName(this,"open a file");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"Error",file.errorString());
        return;
    }
    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();

    ui->statusbar->showMessage(path);
    m_filename = path;
}

void texteditor::on_actionSave_triggered()
{

    QString path = QFileDialog :: getSaveFileName(this,"Save a file");
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"Error",file.errorString());
        return;
    }
    QTextStream stream(&file);
   stream << ui->plainTextEdit->toPlainText();
    file.close();

    ui->statusbar->showMessage(path);
    m_filename = path;



}

void texteditor::on_actionSave_As_triggered()
{
    QString path = QFileDialog :: getSaveFileName(this,"Save as");
    QFile file(path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file :" + file.errorString());
        return;
    }
     m_filename = path;
    setWindowTitle(path);
  QTextStream out(&file);
   QString  text = ui->plainTextEdit->toPlainText();

    out << text;
    file.close();

}

void texteditor::on_actionExit_triggered()
{
ui->plainTextEdit->close();
}

void texteditor::on_actionCut_triggered()
{
ui->plainTextEdit->cut();
}

void texteditor::on_actionCopy_triggered()
{
ui->plainTextEdit->copy();

}

void texteditor::on_actionPaste_triggered()
{
ui->plainTextEdit->paste();
}

void texteditor::on_actionAbout_triggered()
{

    QMessageBox::about(this, tr("About Application"),
               tr("The <b>Application</b>  demonstrates how to "
                  "write modern GUI applications using Qt, with a menu bar, "
                  "toolbars, and a status bar."));
}

void texteditor::on_actionAbout_Qt_triggered()
{
  QApplication::aboutQt();
}






void texteditor::on_actionUndo_Ctrl_Z_triggered()
{
    ui->plainTextEdit->undo();
}

void texteditor::on_actionRedo_Ctrl_Y_triggered()
{
       ui->plainTextEdit->redo();
}
