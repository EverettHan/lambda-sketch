#ifndef CATHybIntersect_h
#define CATHybIntersect_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
*/

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATHybOperatorImp.h"
#include "CATCGMOperatorDebug.h"
#include "ListPOfCATCell.h"
#include "BOHYBOPELight.h"

#include "CATMathConstant.h"
#include "CATCreateTopIntersect.h"

class CATExtHybIntersect;

/**
*  *************************************************************************
*  *******              		 ******************					 *******
*  *******                       ***   WARNING  ***                  *******    
*  *******              		 ******************					 *******
*  *******              											 *******
*  *******  This class is Not supported any longer.					 *******
*  *******  it has been replaced by :	CATICGMHybIntersect		     *******
*  *******              											 *******
*  *************************************************************************
*
*  CATHybIntersect class has been removed from CAA in 3DEXPERIENCE level and  
*  has been replaced by CATICGMHybIntersect.
*  We recommend you to use only CATICGMHybIntersect, in order you be able
*  to migrate easily your CAA code from V5 to 3DEXPERIENCE level
*
*  **************************************************************************
*
* Class defining the operator that intersects two bodies.
*<br>
* This operator operates on the 2D (CATShell), 1D (CATWire) and 0D (CATVertexInVolume)
* domains of a CATBody.
* It follows the general frame of all operator and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created,
* possibly sharing data with the input bodies.
*<ul>
* <li><tt>CATHybIntersect</tt> is created with the <tt>CATCreateTopIntersect</tt> global function.
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable.
* <li>The intersection can be restricted on a given domain on each body with the methods
* <tt>SetFirstDomainToIntersect</tt> and <tt>SetSecondDomainToIntersect</tt>
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the
* geometric factory.
*  <li>When two coplanar skins are intersected, the returned body is a wire body along the boundary 
* of the intersection.
*</ul>
* @see CATCreateTopIntersect
*/
class ExportedByBOHYBOPELight CATHybIntersect : public CATHybOperatorImp
{

  friend ExportedByBOHYBOPELight CATHybIntersect* CATCreateTopIntersect(CATGeoFactory*     iFactory,
                                                          CATTopData*        iData,
                                                          CATBody*           iBody1ToIntersect,
                                                          CATBody*           iBody2ToIntersect);

  CATCGMVirtualDeclareClass(CATHybIntersect);
protected :

  /** @nodoc */
  CATHybIntersect(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybIntersect* iExtensible,
                  CATBody* iFirstBodyToIntersect, CATBody* iSecondBodyToIntersect);

public :

   //  Destructor
   ~CATHybIntersect();

   /** @nodoc  */
   #ifdef CATIACGMV5R20
   #define CATHybIntersectDefineRunOperator
   #endif
   // (Empty macro in customer release mode; no effect on generated code)
    #ifdef CATCGMOperatorDebugMode
   #define CATHybIntersectDefineRunOperator
    #endif
   #ifdef CATHybIntersectDefineRunOperator
   virtual int Run() ;
  /** @nodoc @nocgmitf */
   virtual int RunOperator() ;
#ifdef CATIACGMR419CAA   
   /** @nodoc @nocgmitf */
   virtual int RunExactOperator();
   /** @nodoc @nocgmitf */
   virtual int RunPolyOperator();
#endif
   #endif

   /**
    * Defines which domain of the first body must be intersected.
    * @param iDomainOnFirstBody
    * The pointer to the domain to intersect.
    */
   void SetFirstDomainToIntersect(CATDomain* iDomainOnFirstBody);
   /**
    * Defines which domain of the second body must be intersected.
    * @param iDomainOnSecondBody
    * The pointer to the domain to intersect.
    */
   void SetSecondDomainToIntersect(CATDomain* iDomainOnSecondBody);

  /**
   * @nodoc
   * @param iYesOrNo
   * Set the boundary mode to the operator (internal use only).
   */
   void SetBoundaryResultMode(int iYesOrNo=1);

  /**
   * @nodoc
   * Get the boundary mode to the operator (internal use only).
   * @return
   * The boundary mode:
   * <ul>
   * <li>0: the boundary mode is activated
   * <li>1: the boundary mode is deactivated.
   * </ul>
   */
   int GetBoundaryResultMode() const;

  /**
   * @nodoc
   * Set the OnShell Mode to the operator (internal use only).
   */
   void SetOnShellMode(CATShell* Support, int iYesOrNo=1);

  /**
   * @nodoc
   * Get the OnShell Mode to the operator (internal use only).
   */
   int GetOnShellMode() const;


   // Analyze result according Tangent Design
  /**
  * (De)activates the detection of cells which are tangent to each other.
  * The tangent cells are retrieved by using the <tt>GetTangentDesignCells</tt> method.
  * <pre>
  * pIntersectOpe->SetWarningOnTangentDesign(1);
  *  ...
  * pIntersectOpe->Run();
  * CATBody *pBody =  pIntersectOpe->GetResult();
  * if  (pIntersectOpe->IsResultTangentDesign())
  * {
  *       ListPOfCATCell  ListOfCells;
  *       pIntersectOpe->GetTangentDesignCells(ListOfCells);
  * ...
  * }
  * </pre>
  * @param yes_or_no
  * <ul>
  * <li>0: deactivates the "tangent design" mode
  * <li>1: activates the "tangent design" mode.
  * </ul>
  */
   void  SetWarningOnTangentDesign(int yes_or_no=1);
  /**
  * Retrieves the tangent design mode.
  * @return
  * <ul>
  * <li>0: the "tangent design" mode is not activated
  * <li>1: the "tangent design" mode is activated.
  * </ul>
  */
   int  GetTangentDesignMode() const;
  /**
  * Retrieves the result of the tangent design analysis.
  * @return
  * <ul>
  * <li>0: no tangent cells have been detected
  * <li>1: tangent cells have been detected.
  * </ul>
  */
   int  IsResultTangentDesign() const;
  /**
  * Retrieves the list of tangent cells.
  * <pre>
  * pIntersectOpe->SetWarningOnTangentDesign(1);
  * ...
  * pIntersectOpe->Run();
  * CATBody *pBody =  pIntersectOpe->GetResult();
  * if  (pIntersectOpe->IsResultTangentDesign())
  * {
  *   ListPOfCATCell  ListOfCells;
  *   pIntersectOpe->GetTangentDesignCells(ListOfCells);
  *   ...
  * }
  * </pre>
  * @param oListOfCells
  * The list of tangent cells.
  * @return
  * <ul>
  * <li>0: no tangent cells have been detected
  * <li>1: tangent cells have been detected.
  * </ul>
  */
  int  GetTangentDesignCells(ListPOfCATCell& oListOfCells) const;

  /** @nodoc */
  void  SetBooleanOperationWillFollow(int yes_or_no=1);
  /** @nodoc */
  int  IsBooleanOperationWillFollow() const;

  #ifdef CATIACGMR425CAA //demander a Nader le niveau RITHA

     /** @nodoc
     * Extrapolation mode
     * for the extrapolation of the projection result wire on the SupportSurface
     * @param iExtrapolationMode
     * <br><b>Legal values</b>:
     * <dl><dt><tt>0</tt><dd> No Extrapolation.
     *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. </dl>
     *     <dt><tt>2</tt><dd> Extrapolation in curvature continuity. </dl>
     */
  void SetExtrapolationMode(short iExtrapolationMode = 0);
  void GetExtrapolationMode(short &oExtrapolationMode);
  //void SetTMMaxDeviation(double iTMMaxDeviation);  demander a GARY
  //void GetTMMaxDeviation(double &oTMMaxDeviation); demander a GARY
#endif

#ifdef CATIACGMV5R21
  /**
   * @nodoc
   *
   * Sets the state of single support mode. Typically, the edges in the
   * resulting wire can each contain several p-curves referring to several
   * differenct surfaces from the input bodies. In single support mode, the
   * operator chooses and retains as the geometry of each edge p-curves
   * referring to a surface in the reference body.  The reference body should
   * be one of the input bodies. Currently, also, the reference body should
   * contain only one surface.  Single support mode is only available when the
   * input bodies both contain 2D domains. The result of this operator
   * normally has lying-on links, but these are removed from the result in
   * single support mode.
   *
   * @param iYesOrNo
   * <ul>
   * <li>0: deactivates "single support" mode.
   * <li>1: activates "single support" mode.
   * </ul>
   * @param iReferenceBody
   * Body containing the surface geometry which will be referenced in the result.
   */
  void SetSingleSupportMode(int iYesOrNo, CATBody *iReferenceBody);

  /**
   * @nodoc
   * Retrieves the values of the parameters for "single support" mode.
   * @param iReferenceBody
   * Body containing the surface geometry which will be referenced in the result.
   * @return
   * <ul>
   * <li>0: "single support" mode is not activated
   * <li>1: "single support" mode is activated.
   * </ul>
   */
  int  GetSingleSupportMode(CATBody *&oReferenceBody) const;
#endif

  /** @nodoc  */
  inline CATExtHybIntersect* GetHybIntersectExtensible() const;

};

/** @nodoc  */
inline CATExtHybIntersect* CATHybIntersect::GetHybIntersectExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybIntersect*) _Extensible;
}

#endif
