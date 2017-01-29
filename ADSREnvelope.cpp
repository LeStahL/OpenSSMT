#include "ADSREnvelope.h"

ADSREnvelope::ADSREnvelope(QString name, float attack, float decay, float sustain, float release, float endtime)
    : m_name(name)
    , m_attack(attack)
    , m_decay(decay)
    , m_sustain(sustain)
    , m_release(release)
    , m_end_time(endtime)
{
    
}

float ADSREnvelope::evaluate(float time)
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
    else if(time <= m_end_time)
    {
        return m_sustain;
    }
    else if(time <= m_end_time+m_release)
    {
        return m_sustain-m_sustain/m_release*(time-m_end_time);
    }
    else return 0;
}

ADSREnvelope::~ADSREnvelope()
{

}
