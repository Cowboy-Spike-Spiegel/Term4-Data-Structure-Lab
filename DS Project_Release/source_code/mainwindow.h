#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"compression.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QList>
#include <QDrag>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTime>
#include <QObject>
#include <QCryptographicHash>
#include <QHash>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QHash<QByteArray,QStringList> fileMd5;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStringList getFiles(const QString &path);
    QByteArray getFileMd5(const QString &fileName);
    void display();
    void setFilepath(QString str);
    void setFilename(QString str);
    int CompareMsg(char* msg1, char* msg2);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);


private slots:
    void on_openButton_clicked();

    void on_codeButton_clicked();

    void on_decodeButton_2_clicked();

    void on_checkButton_clicked();

    void on_checkButton_clicked(QString filepath);

private:
    QString Filepath;
    QString Filename;
    Ui::MainWindow *ui;
    Compression *process;
    QString path;
    int z;

};

#endif // MAINWINDOW_H
