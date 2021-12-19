#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class texteditor; }
QT_END_NAMESPACE

class texteditor : public QMainWindow
{
    Q_OBJECT
public:
    texteditor(QWidget *parent = nullptr);
    ~texteditor();
private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

      void on_actionUndo_Ctrl_Z_triggered();

      void on_actionRedo_Ctrl_Y_triggered();
private:
    Ui::texteditor *ui;
    QString m_filename;
};
#endif // TEXTEDITOR_H
