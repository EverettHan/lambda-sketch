#ifndef CATCGMTopoChain_h
#define CATCGMTopoChain_h

#include "ExportedByBONEWOPE.h"
#include "CATCGMChain.h"


class CATBody;
class CATGeoFactory;
class CATCGMUnit;
class CATCGMChainLinkManager;
class CATString;


class ExportedByBONEWOPE CATCGMTopoChain : public CATCGMChain
{
  // CATCGMVirtualDeclareClass(CATCGMTopoChain);
 public:
   CATCGMTopoChain(CATGeoFactory*);
   virtual ~CATCGMTopoChain();

   virtual CATCGMUnit * CreateUnitFromName (const CATString  *iName);
private :
   virtual CATCGMUnit*  CreateUnitFromStream  (CATCGMStream*  iStream);
   CATCGMUnit*  CreateObjectfromType (int iType, CATString * Id=NULL);
 
};

extern "C" ExportedByBONEWOPE CATCGMTopoChain* CATCreateCGMTopoChain (CATGeoFactory*     ifactory);

#endif
