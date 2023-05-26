// COPYRIGHT DASSAULT SYSTEMES 2020 ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : TCA1
//
// DESCRIPTION  : Automatically fill different types of holes with different 
//                  types of continuities according to the surrounding topology
//                
//=============================================================================
// Creation TCA1 March 2020
//=============================================================================

#ifndef CATAutoSkinFillerOpe_H
#define CATAutoSkinFillerOpe_H

#include "CATMathDef.h"
#include "CATTopOperator.h"

#include "ListPOfCATEdge.h"

#include "CATCleverOffset.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATString;

class CATExtCGMReplay;
class CATCGMStream;
class CATCGMOutput;

class CATAutoSkinFillerImpl;


//-----------------------------------------------------------------------------
// CATAutoSkinFillerOpe
//-----------------------------------------------------------------------------
class ExportedByCATCleverOffset CATAutoSkinFillerOpe : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATAutoSkinFillerOpe);

public:

  //--------------------------------------------------------------
  // BEFORE RUN
  //--------------------------------------------------------------

  /**
  * SetBorderEdges
  */
  void SetBorderEdges(CATLISTP(CATEdge)& iBorderEdges);

  /**
  * SetAllowMonoBoundary
  */
  void SetAllowMonoBoundary(short iAllowMonoBoundary = 1);

  /**
  * SetAllowOpenBoundary
  */
  void SetAllowOpenBoundary(short iAllowOpenBoundary = 1);


  //--------------------------------------------------------------
  // AFTER RUN
  //--------------------------------------------------------------

  /**
  * GetUnfilledBorderEdges
  */
  void GetUnfilledBorderEdges(CATLISTP(CATEdge)& iUnfilledBorderEdges);

public:
  virtual ~CATAutoSkinFillerOpe();

protected:
  CATAutoSkinFillerOpe(
    CATGeoFactory *             iFactory,
    CATTopData *                iTopData,
    CATAutoSkinFillerImpl *     iImpl);

  //---------------------------------------------------------
  // RunOperator
  //---------------------------------------------------------
  int RunOperator();

private:
  //---------------------------------------------------------
  // GetImpl
  //---------------------------------------------------------
  CATAutoSkinFillerImpl * GetImpl();

  //-------------------------------------------------------------------
  // CGMReplay Methods
  //-------------------------------------------------------------------
public:
  static CATString const *  GetDefaultOperatorId();
  CATString const *         GetOperatorId();
  void SetCGMMode( short iCGMMode );

  CATExtCGMReplay * IsRecordable(short& oLevelOfRuntime, short& oVersionOfStream);

  void WriteInput(CATCGMStream & oStr);
  void ReadInput(CATCGMStream & ioStr, int iVersionOfStream, short iCGMReplayVersion);
  void Dump(CATCGMOutput & os);

  void RequireDefinitionOfInputAndOutputObjects();

  //-----------------
  // FRIEND FUNCTIONS
  //-----------------
public:
  friend ExportedByCATCleverOffset CATAutoSkinFillerOpe * CATCreateAutoSkinFillerOpe(
    CATGeoFactory *     iFactory,
    CATTopData *        iTopData,
    CATBody *           iBody);
};

ExportedByCATCleverOffset CATAutoSkinFillerOpe * CATCreateAutoSkinFillerOpe(
  CATGeoFactory *     iFactory,
  CATTopData *        iTopData,
  CATBody *           iBody);

#endif
