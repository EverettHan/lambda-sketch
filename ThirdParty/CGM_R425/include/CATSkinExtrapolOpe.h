// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : Class representing an operator that extrapolates a shell body
//                
//=============================================================================
// Creation ZUT May 2011
//=============================================================================

#ifndef CATSkinExtrapolOpe_H
#define CATSkinExtrapolOpe_H

#include "CATSkinExtrapol.h"
#include "Thick.h"
#include "CATMathDef.h"

class CATGeoFactory;
class CATTopData;
class CATBody;

class ExportedByThick CATSkinExtrapolOpe : public CATSkinExtrapol
{
  CATCGMVirtualDeclareClass(CATSkinExtrapolOpe);

public:
  /**
   * @nodoc
   * Constructeur. Ne pas appeler directement. Utiliser CATCreateSkinExtrapol().
   */
  CATSkinExtrapolOpe( CATGeoFactory * iFactory, CATBody * iSkin, CATTopData * iTopData );

  virtual ~CATSkinExtrapolOpe();

  /**
   * Runs <tt>this</tt> operator.
   */
  virtual int Run();

  //---------------------------------------------------------------------------
  // CGMREPLAY METHODS
  //---------------------------------------------------------------------------

  static const CATString * GetDefaultOperatorId();
  const CATString * GetOperatorId();
  CATExtCGMReplay * IsRecordable( short & oLevelOfRuntime, short & oVersionOfStream );
  void RequireDefinitionOfInputAndOutputObjects();

  void WriteInput( CATCGMStream  & oStr );
  void ReadInput( CATCGMStream  & iStr, int iVersionOfStream );
  void Dump( CATCGMOutput & oStr );
  void DumpOutput( CATCGMOutput & oStr );

protected:

  //---------------------------------------------------------------------------
  // PROTECTED METHODS
  //---------------------------------------------------------------------------  

  /**
   * Internal run
   */
  virtual int RunOperator();
};

#endif /* CATSkinExtrapolOpe_H */
