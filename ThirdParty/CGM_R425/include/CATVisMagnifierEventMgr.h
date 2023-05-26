#ifndef CATVisMagnifierEventMgr_H
#define CATVisMagnifierEventMgr_H

// COPYRIGHT Dassault Systemes 2020

#include "CATVisController.h"
#include "CATCallbackManager.h"

class ExportedByCATVisController CATVisMagnifierEventMgr : public CATCallbackManager
{
public:

   CATDeclareClass ;

   CATDeclareCBEvent(MAGNIFIER_POSITION_UPDATE);

public: 

   CATVisMagnifierEventMgr();
   virtual ~CATVisMagnifierEventMgr();

private:

   // Copy constructor and equal operator
   // -----------------------------------
  CATVisMagnifierEventMgr(const CATVisMagnifierEventMgr & i_original);
  CATVisMagnifierEventMgr& operator=(const CATVisMagnifierEventMgr & i_original);
};

#endif
