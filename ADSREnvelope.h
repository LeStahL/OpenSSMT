#ifndef ADSRENVELOPE_H
#define ADSRENVELOPE_H

#include <QString>

class ADSREnvelope 
{
public:
    ADSREnvelope(QString name="Unnamed", float attack=1., float decay=1., float sustain=1., float release=1.0, float endtime = 2.);
    virtual ~ADSREnvelope();
    
    float evaluate(float time);
    
private:
    float m_attack;
    float m_decay;
    float m_sustain;
    float m_release;
    float m_end_time;
    QString m_name;
};

#endif