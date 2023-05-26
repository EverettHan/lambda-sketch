/**
 * @level Private
 * @usage U1
 */
#ifndef __CATAbendObject_H
#define __CATAbendObject_H

#include "CATOme.h"
#include "CATOmxSharable.h"

class ExportedByCATOme CATOmeAbendObject : public CATOmxSharable
{
public :
  enum Identifier { Specs, TOS, Links, OMB };

  CATOmeAbendObject(CATOmeAbendObject::Identifier iIdentifier){ m_id=iIdentifier; }
  
  Identifier GetIdentifier(){ return m_id; }

  virtual const char * GetInfos (CATOmeAbendObject::Identifier iFrom)=0;

protected :
  Identifier m_id;
private :
	CATOmeAbendObject();
  CATOmeAbendObject( const CATOmeAbendObject &);
  CATOmeAbendObject& operator = (const CATOmeAbendObject &);
};


#endif
