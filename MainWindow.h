/*    
 *  OpenSSMT - OpenSSMT Software Synthesizer and Music Tracker. 
 *  Copyright (C) 2016  Alexander Kraus <alexander.kraus@student.kit.edu>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ADSREnvelopePainter.h"

#include <QMainWindow>
#include <QApplication>

class QShowEvent;
namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QApplication *application = 0, Qt::WindowFlags flags = 0);
    virtual ~MainWindow();
    
protected:
    void resizeEvent(QResizeEvent *e);
    void showEvent(QShowEvent *e);
    
private:
    QApplication *m_application;
    Ui::MainWindow *m_ui;
    ADSREnvelopePainter *m_envelope_painter;
    ADSREnvelope *m_edit_envelope;
};

#endif