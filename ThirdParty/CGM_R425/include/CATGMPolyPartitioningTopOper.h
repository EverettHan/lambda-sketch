/* -*-C++-*-*/
#ifndef CATGMPolyPartitioningTopOper_H
#define CATGMPolyPartitioningTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATGMPolyPartitioningTopOper : polyhedral implementation of CATIPGMTopDisconnectOneCellOnly
//
// DESCRIPTION :
// 
// Class defining the operator which disconnects an input body (or a set of specific cells belonging to this body) 
// by a dividing operand, or a list of dividing operands.
// If no dividing operand does intersect the cells to disconnect, the returned result is the input body.
// Else, the returned result will contain a partition of high cells connected by new internal cells coming from the dividing operands
// If the input body is volumic, the output body won't be simplified and will contain lumps with several volumes separated by internal faces.
//
//
// History
//
// 2021 June 18th DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "CATMapOfPtrToPtr.h"
#include "GMPolyAdvancedBool.h"   // ExportedBy

#include "CATTopDefine.h"
#include "CATDynExtrapolationToolsDef.h" // CATDynExtrapolationMode, CATDynExtrapolationLimit

#include "CATBoolean.h"
#include "CATSysBoolean.h"


class CATGMPolyPartitioningTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyAdvancedBool CATGMPolyPartitioningTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyPartitioningTopOper);

public:
  
  /**
  * Destructor
  */
  virtual ~CATGMPolyPartitioningTopOper();
  
  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyPartitioningTopOper() method to create an instance
  static CATGMPolyPartitioningTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyPartitioningTopExt & iExtension);
  

  //=============================================================================
  // Inputs
  //=============================================================================

  /* Limits the operation to a subset of high cells (Volumes, Faces, edges)
  *  @param iCellsToDivide
  *    The pointer to the cells to divide, contained by the input body to partition
  *    All the cells should have the same dimension at the highest level of the input body !!
  */
  void SetListOfSpecCellsToDivide(const CATLISTP(CATCell) &iCellsToDivide);


  //=============================================================================
  // Settings
  //=============================================================================

  void SetExtrapolationMode(CATDynExtrapolationMode iExtrapolMode);

  void SetExtrapolationLimit(CATDynExtrapolationLimit iLimit);

  void SetImprintFollowUpMode(CATBoolean iImprintFollowUpMode);
  
  void SetProjectionMode(CATBoolean iProjectionMode);

  /**
* Activates (before Run) the option associating information of filiation to each result cell
* whose the dimension is conform to the disconnection type (volumic or surfacic)
* In case of a volumic disconnection, this option allows to retrieve the filiation of volumes (not candidate for reporting in the Journal)
* In all cases, this option allows also to locate a result sub-cell of a subdivided cell in the different half-spaces defined by the oriented disconnecting bodies
*  @return
* returns TRUE only if this option is available, else returns FALSE
*/
  CATBoolean EnableResultCellsFiliationInfoRequest();



  //=============================================================================
  // Outputs
  //=============================================================================

  /**
 * Retrieves the original data as parents of a given result cell, after disconnection
 * The dimension of the result cell has to be conform to the way the disconnection has been defined (volumic or surfacic)
 *  @param iResultCell
 *    a CATCell respecting the disconnection dimension and belonging to the result CATBody
 *    Only one type is expected here according to the operation definition:
 *         CATVolumeType if the operation consists in partitioning the matter of a volumic body
 *         CATFaceType if the operation consists in partitioning a surfacic body or the outer/inner shell of a volumic body
 *
 *  @param oOriginalCell
 *    The pointer to the single parent CATCell belonging to the input body to disconnect
 *    with the same dimension than iResultCell (CATVolume or CATFace)
 *    3 different types of filiation here:
 *         1. The original CATCell is untouched by the operation, then reused in the result body: iResultCell = oOriginalCell
 *         2. The original CATCell is touched on its boundary, as neighbor of another CATCell to disconnect
 *         3. The original CATCell is subdivided into several result CATCell
 *            In this last case, the result cell comes also from at least one disconnecting bodies (see the next argument comment)
 *
 *  @param oDisconnectingBodies
 *    The list of input disconnecting bodies subdividing the current original cell (third case of the previous argument comment)
 *    this list is empty in case of untouched cell, or simple modification of cell without any subdivision.
 *
 *  @param oDisconnectingOrientations
 *    list parallel to oDisconnectingBodies,
 *    associating a relative orientation to each disconnecting body crossing and subdividing the current original cell,
 *    in order to identify the half-space containing the current sub-cell from the current oriented disconnecting body
 *
 *  @return
 *    The HRESULT diagnosis of this request
 *  returns E_FAIL if this method is called before the Run()
 *  returns E_FAIL if the "ResultCellsFiliationInfoRequest" has not been enabled before the Run() or had returned FALSE (not available)
 *  returns E_FAIL if the result cell is not belonging to the result CATBody
 *  returns E_FAIL if the result cell has not the expected dimension
 *  returns S_FALSE if no original CATCell has been retrieved as single parent of iResultCell
 *  returns S_OK if the filiation information has been correctly retrieved and returned
 */
  HRESULT GetFiliationInfoFromResultCell(CATCell* iResultCell, CATCell*& oOriginalCell, CATLISTP(CATBody)& oDisconnectingBodies, CATListOfInt& oDisconnectingOrientations);

//-----------------------------------------------------------------------------
// Return map of Result Cells to Source Cells and Disconnecting Bodies
  void GetResultCellsAndFiliation(ListPOfCATCell & ListOFResultCells, CATListPV& ListOfData);


  //=============================================================================
  // CGMReplay
  //=============================================================================
    
  // ------------------
  // CGMReplay Methods => currently in CATGMPolyTopOperator and calling the extensions' methods.
  // Soon, only the extensions will implement the <MethodName>Ext versions for lighter CGMReplay impl.
  // Beware, CATGMPolyTopOperator::DumpOutput seems to handle stuff like tass & dump of journal.
  // Has to be moved over to the mother extension DumpOutputExt.
  // ------------------

  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();

protected:
  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyPartitioningTopOper() method to create an instance
  CATGMPolyPartitioningTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyPartitioningTopExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyPartitioningTopOper();
  CATGMPolyPartitioningTopOper(const CATGMPolyPartitioningTopOper& iOneOf); 
  CATGMPolyPartitioningTopOper& operator =(const CATGMPolyPartitioningTopOper& iOneOf);

};


/**
 * Creates a CATGMPolyPartitioningTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToPartition
 * The pointer to the target body which might be modified by adding internal cells from dividing operands
 * @param iDividingBodies
 * The list of bodies as operands partitioning the input body to modify
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be deleted with the <tt>delete</tt> method after use.
 */
ExportedByGMPolyAdvancedBool CATGMPolyPartitioningTopOper * CATCreatePolyPartitioningTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyToPartition, const ListPOfCATBody & iDividingBodies);

#endif
