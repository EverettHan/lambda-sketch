// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUS
//
// DESCRIPTION  : Computes the MidSurface of a given body
//                
//=============================================================================
// Creation ZUS February 2009
//=============================================================================

#ifndef CATMidSurfaceOperator_H
#define CATMidSurfaceOperator_H

#include "CATCleverOffset.h"

#include "CATPersistentOperator.h"
#include "ListPOfCATFace.h"

class CATMidSurfaceOperatorImpl;
class CATFace;
class CATGeoFactory;
class CATTopData;


/**
* Abstract base class for the MidSurface operator
* <br> A topological operation is realized with the appropriate operator. 
* These operators follow the global frame of the topological operators and satisfy the smart mechanism: 
* the input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*/  

class ExportedByCATCleverOffset CATMidSurfaceOperator : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATMidSurfaceOperator);

public:

/**
 * @nodoc
 * Virtual constructor of a CATMidSurfaceOperator.<br>
 * Cannot be called. Use the <tt>CATCreateMidSurfaceOperator</tt> global function
 * to create the CATMidSurfaceOperator operator.
 */
  CATMidSurfaceOperator(CATGeoFactory             * iFactory,
                        CATTopData                * iTopData,
                        CATMidSurfaceOperatorImpl * iImpl);

/**
 * Destructor.
 */
  virtual ~CATMidSurfaceOperator();

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
  void SetRatio(double iRatio);

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
  void AddPairOfFaces(CATFace * iPFace, CATFace *iQFace);


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
// CATMidSurfaceOperator
// --------------------------------

/** 
 * Global function for the creation of a CATMidSurfaceOperator operator.
 * @param iFactory
 * The pointer to the factory of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. The journal inside <tt>iTopData</tt> 
 * @param iInputBody
 * The pointer to the input body.
 */

ExportedByCATCleverOffset 
CATMidSurfaceOperator * CATCreateMidSurfaceOperator(CATGeoFactory * iFactory,
                                                    CATTopData      * iTopData,
                                                    CATBody  * iInputBody); 



#endif



