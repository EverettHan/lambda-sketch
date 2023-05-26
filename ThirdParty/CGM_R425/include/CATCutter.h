// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : DBS
//
// DESCRIPTION  : Computes Disconnect Face of a given Body
//                and Clone underlying surface 
//=============================================================================
// Creation DBS November 2010
//=============================================================================

#ifndef CATCutter_H
#define CATCutter_H

#include "Thick.h"

#include "CATBoolean.h"
#include "CATPersistentOperator.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"


class CATCutterImpl;
class CATGeoFactory;
class CATTopData;
class CATFace;
class CATBody;


/**
* Abstract base class for the cutter operator
* <br> A topological operation is realized with the appropriate operator. 
* These operators follow the global frame of the topological operators and satisfy the smart mechanism: 
* the input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*/  

class ExportedByThick CATCutter : public CATPersistentOperator
{

  CATCGMVirtualDeclareClass(CATCutter);

public:

/**
 * @nodoc
 * Virtual constructor of a CATCutter.<br>
 * Cannot be called. Use the <tt>CATCreateCutterOperator</tt> global function
 * to create the CATCutter operator.
 */

  CATCutter(CATGeoFactory              * iFactory,
            CATTopData                 * iTopData,
            CATCutterImpl              * iImpl);

/**
 * Destructor.
 */
  virtual ~CATCutter();

  //------------------
  // SET/GET Methods
  //------------------

   /** 
   * @nodoc
   * Set one cutting body for one face.
   * @param ipFace
   * The input face to cut.
   * @param ipCuttingBody
   * The input cutting body.
   * @return
   * 0 if OK else 1 if KO 
   */
  int SetCuttingBody   (CATFace * ipFace, CATBody * ipCuttingBody);

   /** 
   * @nodoc
   * Set a list of cutting bodies for one face.
   * @param ipFace
   * The input face to cut.
   * @param ipListCuttingBody
   * The input cutting bodies list.
   * @return
   * 0 if OK else 1 if KO 
   */
  int SetCuttingBodies (CATFace * ipFace, CATLISTP(CATBody) & ipListCuttingBody);

   /** 
   * @nodoc
   * Set clone underlying surfaces (off by default)
   * @param iClone
   * The input to clone (1 for ON - 0 for OFF) surface of cut result bodies 
   * @return
   * 0 if OK else 1 if KO 
   */
  int SetCloneUnderlyingSurfaces(CATBoolean iClone);

  // Run @nocgmitf
  int RunOperator();


   /** 
   * @nodoc
   * Get the list of tricky faces.
   * @param oListTrickyFaces
   * The output list of tricky faces.
   * @param oListDiagResult
   * The output list of diag faces.
   * @return
   * 0 if OK else 1 if KO 
   */
  int GetTrickyFaces(CATLISTP(CATFace) & oListTrickyFaces,
                     CATListOfInt      & oListDiagResult);

  //------------------
  // CGMReplay methods
  //------------------
  /** @nocgmitf */
  static const CATString * GetDefaultOperatorId ();
  /** @nocgmitf */
  const CATString        * GetOperatorId        ();
  /** @nocgmitf */
  void                     WriteInput           (CATCGMStream  & oStr);
  /** @nocgmitf */
  void                     ReadInput            (CATCGMStream  & ioStr, int iVersionOfStream, short iNumReplayVersion = 1);
  /** @nocgmitf */
  CATExtCGMReplay        * IsRecordable         (short & oLevelOfRuntime, short & oVersionOfStream);
  /** @nocgmitf */
  void                     Dump                 ( CATCGMOutput & os ) ;
  /** @nocgmitf */
  void                     RequireDefinitionOfInputAndOutputObjects();

protected:

  CATCutterImpl * GetCutterImpl();

};

// ------------------------
// CATCreateCutterOperator
// ------------------------

/** 
 * Global function for the creation of a CATCutter operator.
 * @param iFactory
 * The pointer to the factory of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. The journal inside <tt>iTopData</tt> 
 * @param iInputBody
 * The pointer to the input body.
 */

ExportedByThick CATCutter * CATCreateCutterOperator(CATGeoFactory * iFactory,
                                                    CATTopData    * iTopData,
                                                    CATBody       * iInputBody); 


#endif // CATCutter_H



