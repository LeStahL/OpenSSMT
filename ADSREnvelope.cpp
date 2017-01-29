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

#include "ADSREnvelope.h"

ADSREnvelope::ADSREnvelope(QString name, float attack, float decay, float sustain, float release)
    : m_name(name)
    , m_attack(attack)
    , m_decay(decay)
    , m_sustain(sustain)
    , m_release(release)
{
    
}

float ADSREnvelope::attack()
{
    return m_attack;
}

float ADSREnvelope::decay()
{
    return m_decay;
}

float ADSREnvelope::release()
{
    return m_release;
}

float ADSREnvelope::sustain()
{
    return m_sustain;
}

float ADSREnvelope::evaluate(float time, float endtime)
{
    if(time <=0) return 0;
    else if(time <= m_attack)
    {
        return time/m_attack;
    }
    else if(time <= m_attack+m_decay)
    {
        return (time-m_attack)*(m_sustain-1.)/m_decay+1.;
    }
    else if(time <= endtime)
    {
        return m_sustain;
    }
    else if(time <= endtime+m_release)
    {
        return m_sustain-m_sustain/m_release*(time-endtime);
    }
    else return 0;
}

ADSREnvelope::~ADSREnvelope()
{

}
