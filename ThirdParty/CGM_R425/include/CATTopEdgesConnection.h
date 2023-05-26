//===================================================================
 // COPYRIGHT Microsoft 2014
//===================================================================
// CATTopEdgesConnection.h
// Header definition of class CATTopEdgesConnection
//===================================================================
//
// Usage notes:
// 
//===================================================================
// 2014/02/05 Creation: DBS
//===================================================================
// 
//
// Example :
// ---------
//
// #include "CATTopEdgesConnection.h"
// #include "CATTopEdgesConnectionResult.h"
// #include "CATTopEdgesNUpletResult.h"
// 
// // SET all TYPES of Equation / Quality / Builder
// 
// CATTopEvalEquation           :: CATTopEvalEquationType            EquationType = CATTopEvalEquation           :: TopEvalEquationBarycentric;
// CATTopEvalQuality            :: CATTopEvalQualityType             QualityType  = CATTopEvalQuality            :: TopEvalQualityBarycentric;
// CATTopEdgesConnectionBuilder :: CATTopEdgesConnectionBuilderType  BuilderType  = CATTopEdgesConnectionBuilder :: TopEdgesConnectionBuilderNUplet;
//
// // Construct [CATTopEdgesConnection]
//
// CATTopEdgesConnection * pTopEdgesConnection = ::CATCreateTopEdgesConnection(Config, Factory, EquationType, QualityType, BuilderType);
//
// // ADD EDGES (each AddEdges add a list of connected edges)
//
// HRESULT hr_add = pTopEdgesConnection -> AddEdges( ... );
//
// HRESULT hr_add = pTopEdgesConnection -> AddFaces( ... ); // !!!! OPTIONNAL to link with faces
// ...
// 
// // RUN
//
// // rc_run = 0 : if operation succeeded.
// // rc_run > 0 : if KO or operation failed
// int rc_run = pTopEdgesConnection -> Run();
//
// // RESULT
//
// CATTopEdgesConnectionResult * pEdgesConnectionResult = NULL;
// HRESULT hr_result = pTopEdgesConnection -> GetResult (pEdgesConnectionResult);
//
// // GET RESULT of TYPE of Builder
//
// CATLISTP(CATTopEdgesNUpletResult) ListOfNUpletResult;
// HRESULT hr_result_NUplet = pEdgesConnectionResult -> GetResultList_N_Uplets (ListOfNUpletResult);
//
// --> scan [ListOfNUpletResult] to visit all NUplet of N-[CATCurve, CATCrvparam] and N-[CATFace]
//
// // DELETE RESULT : life cycle of result
// 
// CATSysDeletePtr( pTopEdgesConnection );
// CATSysDeletePtr( pEdgesConnectionResult );
//
//
//===================================================================


#ifndef CATTopEdgesConnection_H
#define CATTopEdgesConnection_H

#include "CATTopOperator.h"
#include "MultiWireCoupling.h"

#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"
#include "CATTopEvalEquation.h"
#include "CATTopEvalQuality.h"
#include "CATTopEdgesConnectionBuilder.h"
#include "CATBoolean.h"
#include "CATErrorDef.h" 

class CATTopEdgesConnectionImpl;
class CATTopEdgesConnectionResult;
class CATTopData;
class CATGeoFactory;
class CATEdge;
class CATFace;
class CATString;
class CATCGMOutput;

class ExportedByMultiWireCoupling CATTopEdgesConnection : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopEdgesConnection);

public:

  // Destructor
  //-----------

  virtual ~CATTopEdgesConnection();

  /**
  *  Add a list of connected edges.
  *  @param iListEdges
  *     input list of edges.
  *  @return
  *     HRESULT
  *  Legal values :
  *     - E_FAIL : if KO (list of edges not connected or null list).
  *     - S_OK : if operation succeeded.
  */
  HRESULT AddEdges(CATLISTP(CATEdge)  & iListEdges, double iWeight=1.);

  /**
  *  Add a optionnal list of connected faces (edges are borders).
  *  @param iListFaces
  *     input list of faces.
  *  @param iListOrientation
  *     input list of CATOrientation face vs shell.
  *  @return
  *     HRESULT
  *  Legal values :
  *     - E_FAIL : if KO.
  *     - S_OK : if operation succeeded.
  */
  HRESULT AddFaces(CATLISTP(CATFace)  & iListFaces, CATListOfInt & iListOrientation);

  /**
  *  Get the distance to sample all Edges.
  *  @param oDistance
  *     output oDistance
  *  @return
  *     HRESULT
  *  Legal values :
  *     - E_FAIL : if KO.
  *     - S_OK : if operation succeeded.
  */
  HRESULT GetDistanceSampler(double & oDistance);

  /**
  *  Get the result.
  *  TO BE CALLED ONLY ONCE
  *  The caller must delete the object after use.
  *  @param oResult
  *     output oResult.
  *  @return
  *     HRESULT
  *  Legal values :
  *     - E_FAIL : if KO.
  *     - S_FALSE : if no result.
  *     - S_OK : if operation succeeded.
  */
  HRESULT GetResult(CATTopEdgesConnectionResult *& oResult);

  /**
  * @nodoc
  */
  HRESULT DebugActiveDefaultResult(CATBoolean iIsDebugActiveDefaultResult);

  //------------------
  // CGMReplay methods
  //------------------
  /** @nocgmitf ID for CGMReplay */
  static const CATString * GetDefaultOperatorId();

  /** @nocgmitf ID for CGMReplay */
  const CATString * GetOperatorId();

  /** @nocgmitf for CGMReplay */
  CATExtCGMReplay * IsRecordable( short & oLevelOfRuntime, short & oVersionOfStream );

  /** @nocgmitf for CGMReplay */
  void WriteInput( CATCGMStream  & oStr );

  /** @nocgmitf for CGMReplay */
  void ReadInput( CATCGMStream  & iStr , int iVersionOfStream);

  /** @nocgmitf for CGMReplay */
  void Dump( CATCGMOutput & oStr );

  /** @nocgmitf for CGMReplay */
  void DumpOutput( CATCGMOutput & oStr );

  /** @nocgmitf for CGMReplay */
  void DumpOutput( CATCGMStream & iStr, CATCGMOutput & oStr, int iVersionNumber=1 );

  /** @nocgmitf for CGMReplay */
  void WriteOutput( CATCGMStream & oStr );

  /** @nocgmitf for CGMReplay */
  CATBoolean ValidateOutput( CATCGMStream & iStr, CATCGMOutput & oStr, int iVersionNumber=1 );

  /** @nocgmitf for CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nocgmitf for CGMReplay */
  void SetCGMMode( short iCGMMode );

protected:

  /**
  * Protected constructor
  * Construct a CATTopEdgesConnection.
  * @param ipFactory
  *    input CATGeoFactory.
  * @param ipTopData
  *    input CATTopData.
  */
  CATTopEdgesConnection(CATGeoFactory * ipFactory, CATTopData * ipTopData);

  void SetEquationType(CATTopEvalEquation::CATTopEvalEquationType                     iEquationType);
  void SetQualityType (CATTopEvalQuality::CATTopEvalQualityType                       iQualityType);
  void SetBuilderType (CATTopEdgesConnectionBuilder::CATTopEdgesConnectionBuilderType iBuilderType);

  int RunOperator();

  CATTopEdgesConnectionImpl * GetTopEdgesConnectionImpl();

  // Friend function
  //----------------

  friend ExportedByMultiWireCoupling CATTopEdgesConnection * CATCreateTopEdgesConnection(CATGeoFactory                                                   * iFactory,
                                                                                         CATTopData                                                      * iTopData,
                                                                                         CATTopEvalEquation           :: CATTopEvalEquationType            iEquationType,
                                                                                         CATTopEvalQuality            :: CATTopEvalQualityType             iQualityType,
                                                                                         CATTopEdgesConnectionBuilder :: CATTopEdgesConnectionBuilderType  iBuilderType);
};

// ---------------------------
// CATCreateTopEdgesConnection
// ---------------------------

/** 
 * Global function for the creation of a CATCreateTopEdgesConnection operator.
 *  @param ipFactory
 *     input CATGeoFactory.
 *  @param ipTopData
 *     input CATTopData.
 *  @param iEquationType
 *     input CATTopEvalEquationType.
 *  @param iQualityType
 *     input CATTopEvalQualityType.
 *  @param iBuilderType
 *     input CATTopEdgesConnectionBuilderType.
 */
ExportedByMultiWireCoupling CATTopEdgesConnection * CATCreateTopEdgesConnection(CATGeoFactory                                                   * iFactory,
                                                                                CATTopData                                                      * iTopData,
                                                                                CATTopEvalEquation           :: CATTopEvalEquationType            iEquationType,
                                                                                CATTopEvalQuality            :: CATTopEvalQualityType             iQualityType,
                                                                                CATTopEdgesConnectionBuilder :: CATTopEdgesConnectionBuilderType  iBuilderType);

#endif // CATTopEdgesConnection_H
