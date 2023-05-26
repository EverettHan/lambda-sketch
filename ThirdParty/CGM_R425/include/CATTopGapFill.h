#ifndef CATTopGapFill_H
#define CATTopGapFill_H



#include "CATTopOperator.h"
#include "AdvancedDraft.h"
#include "BOIMPOPE.h"
#include "CATTopDefine.h"
#include "CATMathDef.h"
#include "CATBodyFreezeMode.h"
#include "CATIACGMLevel.h"

class CATGeoFactory;
class CATBody;
class CATFace;

class ExportedByAdvancedDraft CATTopGapFill : public CATTopOperator
{
public:
  CATTopGapFill (CATGeoFactory*     iContainer,
                      CATTopData * iData,
                      CATExtTopOperator* iExtensible);

  virtual ~CATTopGapFill();

  void SetPartingElement(CATBody* iParting);

  CATBody* GetResultBody();

  //VUC: 2010-02-02
  void RequireDefinitionOfInputAndOutputObjects();
  //CATBody* _ResultBody;
private:
    
  virtual int  RunOperator();

};

ExportedByAdvancedDraft CATTopGapFill* CATCreateTopGapFill (CATGeoFactory*        iContainer,
                                                       CATTopData*            iData,
                                                       CATBody*              iPart,
                                                       CATFace*           iFace1,
                                                       CATFace*           iFace2);

#endif
