#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QApplication *application = 0, Qt::WindowFlags flags = 0);
    virtual ~MainWindow();
    
private:
    QApplication *m_application;
    Ui::MainWindow *m_ui;
};

#endif