#ifndef CATBasicFastRun_H_
#define CATBasicFastRun_H_

// Operateur Fast Update qui ne traite que la solution triviale
// (On regarde si on a les memes Inputs en entree, si oui on renvoie le meme resultat.)
// Pas de relation d'heritage avec CATFastRunBlackBoxOperator pour volontairement ne permettre aucune option.

#include "BODYNOPE.h"
#include "CATTopOperator.h"
#include "CATFastRunBlackBoxCheckType.h"
#include "CATString.h"

class CATBody;
class CATContextForFastRun;
class CATFastRunBlackBoxOperatorContextForFastRunExt;

class ExportedByBODYNOPE CATBasicFastRun : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATBasicFastRun);
public : 
  CATBasicFastRun( CATGeoFactory*     iContainer,
                   CATTopData*        iData,
                   CATExtTopOperator* iExtensible = NULL);
  ~CATBasicFastRun();
  void SetContext(CATContextForFastRun * ipContext);

  const CATString * GetOperatorId();
  CATExtCGMReplay * IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  void RequireDefinitionOfInputAndOutputObjects();
  void WriteInput(CATCGMStream &Str);
  void Dump( CATCGMOutput& os );




private :
  int  RunOperator();
  void SetContext(CATContextForFastRunExt * ipContextExt);

  CATString _OperatorId;
  

};

/**
 * @return [out, delete]
 */
ExportedByBODYNOPE CATBasicFastRun* CATCreateBasicFastRun (CATGeoFactory * ipContainer, CATTopData * ipData, CATError ** iopError );
ExportedByBODYNOPE CATBasicFastRun* CATCreateBasicFastRun (CATGeoFactory * ipContainer, CATTopData * ipData, CATContextForFastRun * ipContext, CATError ** iopError);
extern "C"  ExportedByBODYNOPE CATCGMOperator* CATLoadBasicFastRun(CATCGMStream &Str,const short LevelOfRuntime, const short VersionOfStream);

#endif

