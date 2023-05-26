// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//=============================================================================
//
// DESCRIPTION  : Computes the MidSurface of a given body
//                
//=============================================================================
// Creation ZUS February 2009
//=============================================================================

#ifndef CATMidSurfaceAdvancedOperator_H
#define CATMidSurfaceAdvancedOperator_H

#include "CATCleverOffset.h"
#include "CATPersistentOperator.h"
#include "ListPOfCATFace.h"

class CATMidSurfaceOperatorImpl;
class CATFace; 
class CATFace;
class CATGeoFactory;
class CATTopData;

/**
* Abstract base class for the MidSurfaceAdvanced operator
* <br> A topological operation is realized with the appropriate operator. 
* These operators follow the global frame of the topological operators and satisfy the smart mechanism: 
* the input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*/  

class ExportedByCATCleverOffset CATMidSurfaceAdvancedOperator : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATMidSurfaceAdvancedOperator);

public:

/**
 * @nodoc
 * Virtual constructor of a CATMidSurfaceAdvancedOperator.<br>
 * Cannot be called. Use the <tt>CATCreateMidSurfaceAdvancedOperator</tt> global function
 * to create the CATMidSurfaceAdvancedOperator operator.
 */
  CATMidSurfaceAdvancedOperator(CATGeoFactory              * iFactory,
                                CATTopData                 * iTopData,
                                CATMidSurfaceOperatorImpl  * iImpl);

/**
 * Destructor.
 */
  virtual ~CATMidSurfaceAdvancedOperator();

  //------------------
  // SET/GET Methods
  //------------------

   /** 
   * @nodoc
   * SetRatio .
   * @param iRatio
   * The ratio .
   * @return
   * 
   */
  void SetRatio                 (double iRatio);

   /** 
   * @nodoc
   * AddPairOfFaces .
   * @param ipFaceP
   * The Face P .
   * @param ipFaceQ
   * The Face Q .
   * @return
   * 
   */
  void AddPairOfFaces           (CATFace * ipFaceP, CATFace * ipFaceQ);

   /** 
   * @nodoc
   * InitPairOfFaces .
   * @param ipFaceP
   * The Face P .
   * @param ipFaceQ
   * The Face Q .
   * @param iRatio
   * The ratio .
   * @return
   * 
   */
  void InitPairOfFaces          (CATFace * ipFaceP, CATFace * ipFaceQ, double iRatio);


   /** 
   * @nodoc
   * SetMainMidSurfaceForRib .
   * @param ipBodyMidSurfaceMain
   * The body of the main mid-surface .
   * @return
   * 
   */
  void SetMainMidSurfaceForRib  (CATBody * ipBodyMidSurfaceMain = NULL);


   /** 
   * @nodoc
   * InitListOfFaces .
   * @param iListOfFaces
   * The list of faces to mid-surface by offset .
   * @param iDistance
   * The distance to offset .
   * @param iRatio
   * The ratio .
   * @return
   * 
   */

  void InitListOfFaces(CATLISTP(CATFace) & iListOfFaces, double iDistance, double iRatio );

  /** 
   * @nodoc
   * InitListOfFaces .
   * @param iListOfFaces
   * The list of faces to mid-surface by offset in associative distance mode.
   * @param iRatio
   * The ratio .
   * @param iAssociativeDistanceMode
   * Mode set to 1 for MIN, set to 2 for MAX, and set to 3 for AVERAGE distance .
   * @param iMaxThickness
   * The Max thickness to filter faces with distance > iMaxThickness .
   * @return
   * 
   */
  void InitListOfFaces(CATLISTP(CATFace) & iListOfFaces, double iRatio, int iAssociativeDistanceMode, double iMaxThickness);

  // Run @nocgmitf
  int RunOperator();

  //------------------
  // CGMReplay methods
  //------------------
  /** @nocgmitf */
  static const CATString *GetDefaultOperatorId();
  /** @nocgmitf */
  const CATString * GetOperatorId();
  /** @nocgmitf */
  void WriteInput(CATCGMStream  & Str);
  /** @nocgmitf */
  void ReadInput(CATCGMStream  & ioStr, int VersionOfStream, short iNumReplayVersion, const double iXScaleFactor);
  /** @nocgmitf */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nocgmitf */
  void Dump( CATCGMOutput& os ) ;
  /** @nocgmitf */
  void RequireDefinitionOfInputAndOutputObjects();

protected:
  CATMidSurfaceOperatorImpl * GetMidSurfaceImpl();

};

// --------------------------------
// CATMidSurfaceAdvancedOperator
// --------------------------------

/** 
 * Global function for the creation of a CATMidSurfaceAdvancedOperator operator.
 * @param iFactory
 * The pointer to the factory of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. The journal inside <tt>iTopData</tt> 
 * @param iInputBody
 * The pointer to the input body.
 */
ExportedByCATCleverOffset 
CATMidSurfaceAdvancedOperator * CATCreateMidSurfaceAdvancedOperator(CATGeoFactory * iFactory,
                                                                    CATTopData    * iTopData,
                                                                    CATBody       * iInputBody); 



#endif



