/* -*-c++-*- */
#ifndef CATDynSolidX_H_
#define CATDynSolidX_H_

#include "BOIMPOPE.h"
#include "CATDRepExtTopOperator.h"
#include "CATTopOpPrevisualization.h"  
#include "CATFilletReconfigFillFunction.h"
#include "CATFilletExportManager.h"
#include "CATCGMNewArray.h"

class CATBlendParams;
class CATGenericHealing;
class CATDynFilletRibbon;
class CATBody;
class CATMathPoint;
class CATCX_AuthorizedAnomaliesForCGMOperator;

//-----------------------------------------------------------------------------
class ExportedByBOIMPOPE CATDynSolidXCGM : public CATDRepExtTopOperator //CATExtTopOperator
//-----------------------------------------------------------------------------
{
 public:
  CATDynSolidXCGM (CATGeoFactory &    iContainer,
                   CATTopData &       iData,
                   CATBody*           iPart=NULL);
  CATCGMNewClassArrayDeclare;        // Pool allocation

  ~CATDynSolidXCGM();
  
  int Run();
  void SetPrevisualizationOnly ();
  void SetFastFilletPreview();
  void SetPrevisualizationMode (CATTopOpPrevisualization iMode);
  void SetTrueMultiRibbonOnly ();
  void SetCollisionCheckMode(CATBoolean iCollisionCheckMode);
  void DisableFatEdgesSimplification();
  void DisableRelimitation(CATBoolean iDisableRelimitation);
  void SetPart( CATBody *iPart) { _Part = iPart; }
  CATBody * GetPart() {return _Part;}
  void SetHealer(CATGenericHealing* iHealer);
  void SetSkinOptions (CATDynFilletRibbon *R, CATBlendParams *params);
  void SetBestInInSelectionPoint(const CATMathPoint &iBestInInSelectionPoint);
  void AddSupportJournalInfo(CATBoolean iAddSupportJournalInfo);
  void EnableSuperMaxOption(CATBoolean iSuperMaxOption);

  CATBoolean IsUntwistFillFunctionUsed() const ;

  virtual int RunOperator()=0;

  void GetParametersForDynFilteringOfAnomalies(CATCX_AuthorizedAnomaliesForCGMOperator *piAuthorizedAnomaliesForCGMOperator);


protected:
  virtual CATShell * GetInputShell(CATBody &iBody);
  
//-----------------------------------------------------------------------------
protected:
//-----------------------------------------------------------------------------
 CATBody*                      _Part; 
 CATBody*                      _InputBody;
 CATGenericHealing*            _Healer;
 CATFilletReconfigFillFunction _FillFct;
 CATFilletExportManagerCreate  _FilletExportManagerCreate;
 CATTopOpPrevisualization      _Previsu;
 CATBoolean                    _SpecialPreviewVertexBlend;
 int                           _TrueMultiRibbonOnly;
 CATBoolean                    _CollisionCheckMode;
 CATBoolean                    _DisableFatEdgesSimplification;
 CATBoolean                    _DisableRelimitation;
 CATBoolean                    _UntwistFillFunctionUsed;
 CATMathPoint                 *_BestInInSelectionPoint;
 CATBoolean                    _AddSupportJournalInfo;
 CATBoolean                    _SuperMaxOption;
//-----------------------------------------------------------------------------
};


#endif
