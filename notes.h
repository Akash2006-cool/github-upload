#ifndef NOTES_H
#define NOTES_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Notes; }
QT_END_NAMESPACE

class Notes : public QMainWindow
{
    Q_OBJECT

public:
    Notes(QWidget *parent = nullptr);
    ~Notes();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionFull_Screen_triggered();

    void on_actionExit_Full_Screen_triggered();

    void on_actionNew_Window_triggered();

    void on_FileNameValue_windowTitleChanged(const QString &title);

    void on_actionRefresh_triggered();

private:
    Ui::Notes *ui;
    QString FilePath;
};
#endif // NOTES_H
