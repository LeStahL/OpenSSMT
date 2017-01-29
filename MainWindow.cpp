#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QApplication* application, Qt::WindowFlags flags)
    : m_application(application)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}