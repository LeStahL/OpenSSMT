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

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "ADSREnvelopePainter.h"
#include "ADSREnvelope.h"

#include <qt5/QtWidgets/qgraphicsscene.h>
#include <qt5/QtWidgets/qgraphicsview.h>
#include <QResizeEvent>
#include <QDebug>

MainWindow::MainWindow(QApplication* application, Qt::WindowFlags flags)
    : m_application(application)
    , m_ui(new Ui::MainWindow)
    , m_edit_envelope(new ADSREnvelope("Unnamed", 100, 50, 0.5, 75))
{
    m_ui->setupUi(this);
    m_ui->graphicsView_2->setScene(new QGraphicsScene(QRectF(0,0,400, 100)));
    
    m_envelope_painter = new ADSREnvelopePainter(0);
    m_envelope_painter->setEnvelope(m_edit_envelope);
    m_ui->graphicsView_2->scene()->addItem(m_envelope_painter);
    
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    m_ui->graphicsView_2->fitInView(m_envelope_painter->boundingRect());
    m_envelope_painter->update();
}

void MainWindow::showEvent(QShowEvent* e)
{
    m_ui->graphicsView_2->fitInView(m_envelope_painter->boundingRect());
    m_envelope_painter->update();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}