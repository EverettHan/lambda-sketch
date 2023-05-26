#ifndef CATSkinExtrapol_h
#define CATSkinExtrapol_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/ 


#include "Thick.h"
#include "CATGeoToTopOperator.h"
#include "ListPOfCATEdge.h"
#include "CATListOfCATCells.h"
#include "CATMathDef.h"
#include "CATTopOperator.h"
#include "CATIACGMLevel.h"

class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
class CATTopData;
class CATVertex;
class CATCurve;

/**
*  ***********************************************************************
*  *******                         WARNING                         *******
*  ***********************************************************************
*  *******
*  *******  This class is Not supported any longer.
*  *******  it has been replaced by CATICGMSkinExtrapol
*  *******
*  *******
*  ***********************************************************************
*  ***********************************************************************
*  CATSkinExtrapol class has been removed from CAA in 3DEXPERIENCE level and
*  has been replaced by CATICGMSkinExtrapol.
*  We recommend you to use only CATICGMSkinExtrapol, in order you will  be  
*  able to easily migrate   your CAA code from  V5 to 3DEXPERIENCE level
*
*  **************************************************************************
*
 * Class representing an operator that extrapolates a shell body.
 *<br>The edges to extrapolate must be on the boundary of the shell, or 
 * must lie on a bounding edge of the shell.
 *<br>The extrapolation values can be different for each edge. A positive
 * value defines an extrapolation along the outside direction of the shell.
 *<br>The extrapolation gives a result that is continuous in curvature.
 * To use it:
 * <ul>
 * <li>Create it with the <tt>CATCreateSkinExtrapol</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. 
 * <li>Run it
 * <li>Get the resulting body, using the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 *<li>Delete it after use  with the usual C++ <tt>delete</tt> operator.
 *</ul> 
 */
class ExportedByThick CATSkinExtrapol : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATSkinExtrapol);
public:

  /** @nodoc */
  CATSkinExtrapol(CATBody* iSkin, CATCGMJournalList* iJournal=NULL);
    /** @nodoc */
  CATSkinExtrapol(CATGeoFactory * iFactory, CATBody * iSkin, CATTopData * iTopData);
  ~CATSkinExtrapol();

  /**
   * Sets the ability to later modify the resulting body.
   * @param iFreezeMode
   * The freeze mode.
   */
  void SetFreezeMode(CATBodyFreezeMode iFreezeMode);
  
  /**
   * Appends a list of edges to extrapolate.
   * It replaces the current value of an already selected edges by <tt>iExtrapolValue</tt>.
   * @param iBoundaryEdges
   * The list of edges to append.
   * @param iExtrapolValue
   * The common extrapolation value for all the edges of the <tt>iBoundaryEdges</tt> list.
   */
#ifdef CATIACGMV5R21
  void Append(const CATLISTP(CATEdge) & iBoundaryEdges, CATLength iExtrapolValue ) ;
#else
  void Append(CATLISTP(CATEdge) iBoundaryEdges, CATLength iExtrapolValue ) ;
#endif

  /**
   * Appends an edge to extrapolate.
   * It replaces the current value of an already selected edges by <tt>iExtrapolValue</tt>.
   * @param iBoundaryEdge
   * The edge to append.
   * @param iExtrapolValue
   * The extrapolation value for the <tt>iBoundaryEdge</tt> edge.
   */
  void Append(CATEdge* iBoundaryEdge, CATLength iExtrapolValue ) ;

  /**
   * Selects all the edges of the shell boundary and sets to them a common extrapolation value.
   * @param iExtrapolValue
   * The new current extrapolation value of the already selected edges.
   */
  void SetDefaultExtrapolationValue( CATLength iExtrapolValue );
  
  /**
   * Defines the propagation mode of the extrapolation value.
   * @param iPropagationMode
   *<dl>
   *<dt><tt>0</tt></dt><dd> No propagation of the extrapolation value.
   *<dt><tt>1</tt></dt><dd> Defines the automatic definition of the extrapolation value on an edge
   * to the one of its tangential adjacent edges.
   * This mode is used by default at the creation of the operator.
   *</dl>
   */
  void SetPropagationMode(int iPropagationMode);

  /**
   * Defines the relimitation mode for all boundary extremities affected by the operator.
   * @param iNormalMode
   *<dl>
   *<dt><tt>0</tt></dt><dd> Extrapolate adjacent edges to cut the offset boundary.
   * This mode is enabled by default at the creation of the operator.
   *<dt><tt>1</tt></dt><dd> Add junction edges in the normal direction of boundary extremities.
   *</dl>
   */
  void SetExtremitiesMode(int iNormalMode);

#ifdef CATIACGMR217CAA
  /**
  * @nodoc
  * Defines whether the result should contain the whole extrapolated surface or only the extrapolated area.
  * @param iKeepOnlyExtrapolatedArea
  *<dl>
  *<dt><tt>0</tt></dt><dd> The whole extrapolated surface is returned.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> The result contains the extrapolated area only.
  *</dl>
  */
  void SetKeepOnlyExtrapolatedArea(short iKeepOnlyExtrapolatedArea);

  /**
   * @nodoc
   * Enables or disables deviation checking.
   * @param iWithDeviation
   * <dl>
   * <dt><tt>1</tt><dd> Check if surface deviations are below maximum value.
   * This value can be provided by the user through <tt>SetDeviationAllowed</tt> method.
   * Default value is the factory resolution
   * <dt><tt>0</tt><dd> No deviation checking is performed
   * This mode is used by default at the creation of the operator.
   * </dl>
   **/
  void SetDeviationMode(short iDeviationMode);

  /**
   * @nodoc
   * Defines the maximum deviation value allowed by the user.
   * @param iDeviation
   * The value of the deviation. This value must be positive.
   */
  void SetDeviationAllowed(CATLength iMaxDeviation);
#endif /* CATIACGMR217CAA */

  /**
   * @nodoc
   * Do not use.
   */
  void SetExtremitySpecification(CATVertex * iVtxExtremity,
                                 int iSpecifiedMode, 
                                 CATCurve * iGuideCurve=NULL);

  /**
   * Returns the pointer to the resulting body.
   */
  CATBody * GetResult();
  
  /**
   * Returns a pointer to the topological journal dedicated to <tt>this</tt> CATSkinExtrapol operator.
   * <br>Only available if a journal was given at the creation of the operator.
   */
  CATCGMJournalList * GetJournal();


  /**
   * Runs <tt>this</tt> operator.
   */
  int Run();

#if defined CATIAR206
    /**
    * @nodoc @nocgmitf
    * Internal use. internal run
    */
  virtual int RunOperator();

    /**
    * @nodoc @nocgmitf
    * Internal use.
    */
   void RequireDefinitionOfInputAndOutputObjects();
#endif

  /** @nodoc */
  virtual void SetSoftwareConfiguration( CATSoftwareConfiguration * iNewConfig );

protected:
  /** @nodoc */
  void          * _implementation;
  CATTopData    * _CreatedTopData;
};


/**
 * Creates a skin extrapolation operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iSkin
 * The pointer to the skin body to extrapolate.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByThick CATSkinExtrapol * CATCreateSkinExtrapol( CATGeoFactory * iFactory, 
                                                         CATTopData    * iTopData, 
                                                         CATBody       * iSkin );
                                                        

#endif
