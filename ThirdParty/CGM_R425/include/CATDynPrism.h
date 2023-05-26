#ifndef CATDynPrism_H_
#define CATDynPrism_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATDynOperator.h"
#include <CATMathDef.h>
#include <CATListOfCATCurves.h>



class CATMathDirection;
class CATBody;
class CATPlane;
class CATGeometry;
class CATBody;


struct ExportedByBODYNOPE CATDynPrismLimit
{   
  CATDynLimitType        Type;
  CATBoolean             IsAxisReverted;
  CATLength              Offset;
  CATGeometry*           Init;
  CATGeometry*           Limit;
  CATDynPropagationType  Propag;
};



class ExportedByBODYNOPE CATDynPrism : public CATDynOperator
{
  CATCGMVirtualDeclareClass(CATDynPrism);
 public:
  CATDynPrism (CATGeoFactory* , CATCGMJournalList* journal=NULL);
  CATDynPrism (CATGeoFactory* , CATTopData * iData);
  virtual ~CATDynPrism();

  virtual void SetLimit(CATDynLimit           iId,
                        CATDynLimitType       iType,
                        CATBoolean            iIsAxisReverted,
                        CATLength             iOffset,
                        CATGeometry*          iInit,        // Initialisation de la Propagation
                        CATGeometry*          iLimit,       // Domaine de Propagation
                        CATDynPropagationType iPropag)   = 0;
 
  virtual void SetOperation     ( CATDynBooleanType iOperation = CATBoolNone ) = 0;
  virtual void SetTrim          ( CATBody*       iTrim = NULL )      = 0;  
  virtual void SetClosure       ( CATBoolean     isProfileClosed )  = 0;  
  virtual void SetStiffenerMode ( CATBoolean iStiffenerMode, CATBoolean iMatterSide ) = 0;
  virtual void SetBothResult   (CATBoolean   iBothResultRequired) =0 ; 
};


// Creation EntryPoints
ExportedByBODYNOPE CATDynPrism* CATDynCreatePrism (CATGeoFactory*             Container,
                                                   CATMathDirection*          iDirection,
                                                   const CATLISTP(CATCurve)&  iProfile,
                                                   CATPlane*                  iSupport, 
                                                   CATCGMJournalList*         iJournal=NULL) ;    

// Creation EntryPoints
ExportedByBODYNOPE CATDynPrism* CATCreateDynPrism (CATGeoFactory*             Container,
                                                   CATTopData *               iData,
                                                   CATMathDirection*          iDirection,
                                                   const CATLISTP(CATCurve)&  iProfile,
                                                   CATPlane*                  iSupport) ;    
#endif
