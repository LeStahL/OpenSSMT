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
 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ADSREnvelopePainter.h"
#include "ADSREnvelope.h"

#include <qt5/QtWidgets/qgraphicsitem.h>
#include <qt5/QtGui/QPainter>
#include <QGraphicsView>
#include <QDebug>
#include <QRectF>
#include <QPen>

ADSREnvelopePainter::ADSREnvelopePainter(QGraphicsItem* parent)
    : QGraphicsItem(parent)
{
    
}

QRectF ADSREnvelopePainter::boundingRect() const
{
    return QRectF(0,0,400, 100);
}

ADSREnvelope* ADSREnvelopePainter::envelope()
{
    return m_envelope;
}

void ADSREnvelopePainter::setEnvelope(ADSREnvelope* e)
{
    m_envelope = e;
}

void ADSREnvelopePainter::paint(QPainter* p, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    p->setRenderHint(QPainter::Antialiasing);
    float w = 2*m_envelope->attack()+m_envelope->decay()+m_envelope->release();
    p->fillRect(boundingRect(), Qt::lightGray);
    QPen pen = p->pen(), oldpen = pen;
    pen.setColor(Qt::red);
    pen.setWidth(4.);
    p->setPen(pen);
    QPainterPath path;
    path.moveTo(0,boundingRect().height());
    path.lineTo(boundingRect().width()/w*m_envelope->attack(), 0);
    path.lineTo(boundingRect().width()/w*(m_envelope->attack()+m_envelope->decay()), boundingRect().height()*(1-m_envelope->sustain()));
    path.lineTo(boundingRect().width()/w*(2*m_envelope->attack()+m_envelope->decay()), boundingRect().height()*(1-m_envelope->sustain()));
    path.lineTo(boundingRect().width(), boundingRect().height());
    QBrush brush;
    brush.setColor(Qt::darkGray);
    brush.setStyle(Qt::SolidPattern);
    p->fillPath(path, brush);
    p->drawPath(path);
    p->setPen(oldpen);
}

ADSREnvelopePainter::~ADSREnvelopePainter()
{

}

