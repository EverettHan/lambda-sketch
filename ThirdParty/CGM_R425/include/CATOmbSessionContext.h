#ifndef CATOmbSessionContext_H
#define CATOmbSessionContext_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @level Private
 * @usage U1
 */

#include  "AC0XXLNK.h"

class CATOmbSessionPrivateData;
class CATOmbSessionContextFactory;
class CATSession;

/**   
 * CATIA session context object.
 * <b>Role</b>: This object is meant to be used as a context for instanciating session services.<br>
 * Applications should only manipulate it as a forward declared pointer type. They don't have access to its methods.<br> 
 * Infrastructure frameworks implementing services, or using the session cache have access to internal data.<br>
 * 
 * ONLY INFRASTRUCTURE FRAMEWORKS ARE ALLOWED TO INCLUDE THIS HEADER (ObjectModelerBase, ObjectModelerCATIA, ObjectModelerBaseUI) 
 */

class ExportedByAC0XXLNK CATOmbSessionContext
{
public:

	CATOmbSessionPrivateData& GetPrivateData() { return (CATOmbSessionPrivateData&)*this;}
	CATSession *GetSession() const { return m_pSession; };

  friend class CATSession; // creates, destroys CATOmbSessionContext instances
protected:
  // pointer to the corresponding CATSession 
  CATSession *m_pSession;

  // constructor is private
  CATOmbSessionContext(CATSession& ipSession ):m_pSession(&ipSession) {}

  // destructor is private
  virtual ~CATOmbSessionContext();
private:
  // copy constructor should not be implemented
  CATOmbSessionContext(CATOmbSessionContext& ICOPY);

  // = operator should not be implemented
  CATOmbSessionContext operator=(CATOmbSessionContext& ICOPY);
  
};


#endif


