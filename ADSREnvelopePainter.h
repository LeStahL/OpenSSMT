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

#ifndef ADSRENVELOPEPAINTER_H
#define ADSRENVELOPEPAINTER_H

#include <QGraphicsItem>
#include <QSize>
#include <QPaintEvent>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsScene>
#include <QColor>

class ADSREnvelope;

class QResizeEvent;
class ADSREnvelopePainter : public QGraphicsItem
{
public:
    ADSREnvelopePainter(QGraphicsItem *parent = 0);
    virtual ~ADSREnvelopePainter();
    QRectF boundingRect() const;
    void paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setEnvelope(ADSREnvelope *e);
    ADSREnvelope *envelope();

private:
    ADSREnvelope *m_envelope;
};

#endif