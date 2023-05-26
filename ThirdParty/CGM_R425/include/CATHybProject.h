#ifndef CATHybProject_h
#define CATHybProject_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
*/ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATHybOperatorImp.h"
#include "CATCGMOperatorDebug.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATFace.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "BOHYBOPELight.h"
#include "CATIAV5Level.h"

/** @nodoc @nocgmitf */
ExportedByBOHYBOPELight CATHybProject* CATCreateTopPoseSur(CATGeoFactory*           iFactory,
  CATTopData*              iData,
  CATBody*                 iBodyToProject,
  CATBody*                 iBodySupport);
   
/** @nocgmitf */
ExportedByBOHYBOPELight CATHybProject * CATCreateTopProject(CATGeoFactory*           iFactory,
  CATTopData*              iData,
  CATBody*                 iBodyToProject,
  CATBody*                 iBodySupport,
  CATMathDirection*        iDirection);
   

class CATExtHybProject;

/**
* Class defining the operator that projects a body on another one.
* It follows the general frame of all operator and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>CATHybProject is created with the <tt>CATCreateTopProject</tt> global function.
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable. 
* <li>The intersection can be restricted on a given domain on each body with the methods
* <tt>SetFirstDomainToIntersect</tt> and <tt>SetSecondDomainToIntersect</tt>
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopProject
*/
class ExportedByBOHYBOPELight CATHybProject : public CATHybOperatorImp
{
   
   friend ExportedByBOHYBOPELight CATHybProject* CATCreateTopPoseSur(CATGeoFactory*           iFactory,
      CATTopData*              iData,
      CATBody*                 iBodyToProject,
      CATBody*                 iBodySupport);
   
   friend ExportedByBOHYBOPELight CATHybProject * CATCreateTopProject(CATGeoFactory*           iFactory,
      CATTopData*              iData,
      CATBody*                 iBodyToProject,
      CATBody*                 iBodySupport,
      CATMathDirection*        iDirection);
   
  CATCGMVirtualDeclareClass(CATHybProject);
protected :
   
   /** @nodoc */
   CATHybProject(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybProject* iExtensible,
      CATBody* iBodyToProject, CATBody* iBodySupport, CATMathDirection* iDirection);	

public :

   //  Destructor
   ~CATHybProject();     

   /** @nodoc  */
   #ifdef CATIACGMV5R20
   #define CATHybProjectDefineRunOperator
   #endif
   // (Empty macro in customer release mode; no effect on generated code)
    #ifdef CATCGMOperatorDebugMode
   #define CATHybProjectDefineRunOperator
    #endif
   #ifdef CATHybProjectDefineRunOperator
   virtual int Run() ;
  /** @nodoc @nocgmitf */
   virtual int RunOperator() ;
   #endif

   /**
    * Defines which domain of the first body must be projected.
    * @param iDomain
    * The pointer to the domain to project.
    */
   void SetDomainToProject(CATDomain* iDomain); 
   /**
    * Defines on which domain of the second body the projection is done.
    * @param iDomain
    * The pointer to the domain on which to project.
    */
   void SetDomainSupport(CATDomain* iDomain);   
   
   /**
    * Returns the maximum distance of projection for a given domain of the resulting body.
    * @param iDomainOfResultBody
    * The pointer to the domain.
    * @return
    * The distance.
    */
   double GetDistance(CATDomain* iDomainOfResultBody);
   
  /** @nodoc
   * Asks operator to suppress domains in wich all cells result from flatten operation.
   * <br> This option is not active by default.
   * @param yes_or_no
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> Desactivate mode.
   *     <dt><tt>1</tt><dd> Activate mode.</dl>
   */
   void SetSuppressFlattenDomainMode(int yes_or_no=1);

  /** @nodoc
   * Returns suppress flatten domain mode.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> Mode isn't active.
   *     <dt><tt>1</tt><dd> Mode is active.</dl>
   */
   int  GetSuppressFlattenDomainMode() const;

   /** 
   * Specifies the faces of the support body on which the projection should be done.
   * <br> By default, all faces are taken into account.
   * @param iCoveredFaces
   * The faces on which the projection should be done.
   */
   void SetCoveredFaces(CATLISTP(CATFace) & iCoveredFaces);

  /** @nodoc
   * returns if faces have been specified.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No faces specified.
   *     <dt><tt>1</tt><dd> Faces have been specified.</dl>
   */
   int IsCoveredFacesActive() const;

    /**
    * Specify a maximum distance for the solution(s) to be kept. By default all the solutions
    * are returned.
    * @param iMaxDistance
    * The maximum distance.
    */
   void SetMaxDistanceValue(double iMaxDistance);

  /** @nodoc
   * Returns the maximum distance that has been set.
   * <br> This method should not be called if a maximum distance hasn't been set.
   * @return 
   * The value of maximum distance.
   */
   double GetMaxDistanceValue() const;

  /** @nodoc
   * Returns if a maximum distance has been set.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No maximum distance.
   *     <dt><tt>1</tt><dd> Maximum distance has been set.</dl>
   */
   int IsMaxDistanceActive() const;  
   
  /** @nodoc 
   * Returns the type of operation.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>PROJECTION</tt><dd> Operator performs a projection.
   *     <dt><tt>POSAGE</tt><dd> Operator performs a laydown.</dl>
   */
   CATHybProjectionContext GetContext();

  /** @nodoc 
   * Changes type of operation. 
   * <br> Default operation is a projection.
   * @param iContext
   * <br><b>Legal values</b>:
   * <dl><dt><tt>PROJECTION</tt><dd> Operator performs a projection.
   *     <dt><tt>POSAGE</tt><dd> Operator performs a laydown.</dl>
   */
   void SetContext(CATHybProjectionContext iContext);

  /** @nodoc
   * Asks operator to perform simplification of the result.
   * <br> This option is not active by default.
   * @param iSimplification
   * <br><b>Legal values</b>:
   * <dl><dt><tt>TRUE</tt><dd> Mode is active.
   *     <dt><tt>FALSE</tt><dd> Mode isn't active</dl>
   */
   void SetSimplificationMode(CATBoolean iSimplification);

  /** @nodoc 
   * Returns simplification mode.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>TRUE</tt><dd> Mode is active.
   *     <dt><tt>FALSE</tt><dd> Mode isn't.</dl>
   */
   CATBoolean  GetSimplificationMode() const;

 /** @nodoc
  * Checks if result is completely laid down.
  * <br> To be called after having run operator.
  * @return 
  * <br><b>Legal values</b>:
  * <dl><dt><tt>TRUE</tt><dd> Result is totally laid down.
  *     <dt><tt>FALSE</tt><dd> Result isn't totally laid down.</dl>
  */
   CATBoolean IsCompletelyLaidDown();

 /** @nodoc  
  * Internal use.
  */
  inline CATExtHybProject* GetHybProjectExtensible() const;

 /** @nodoc
  * Asks operator to perfom smoothing of wires to project.
  * <br> This option is not active by default.
  * @param iSmooth
  * <br><b>Legal values</b>:
  * <dl><dt><tt>0</tt><dd> No Smoothing. 
  *     <dt><tt>1</tt><dd> Smooth for tangency continuity. 
  *     <dt><tt>2</tt><dd> Smooth for curvature continuity .</dl>
  */
  void SetNewSmoothing(CATLONG32 iSmooth);	

  /** @nodoc 
   * Returns smoothing mode.
   * @param oSmooth
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No Smoothing. 
   *     <dt><tt>1</tt><dd> Smooth for tangency continuity. 
   *     <dt><tt>2</tt><dd> Smooth for curvature continuity .</dl>
   */
   void GetNewSmoothing(CATLONG32 & oSmooth);

  /** @nodoc
   * Asks operator to do a 3D cleaning of result wires, when smoothing mode is active. 
   * <br> By default a 2D cleaning is applied.
   * @param iOutputWireCleaning3DMode
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> 2D cleaning. 
   *     <dt><tt>1</tt><dd> 3D cleaning. </dl>
   */
   void SetOutputWireCleaning3DMode(CATLONG32 iOutputWireCleaning3DMode);

  /** @nodoc 
   * Returns 3D cleaning mode.
   * @param oOutputWireCleaning3DMode
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> 2D cleaning. 
   *     <dt><tt>1</tt><dd> 3D cleaning. </dl>
   */
   void GetOutputWireCleaning3DMode(CATLONG32 & oOutputWireCleaning3DMode);

#ifdef CATIACGMR419CAA
   /** @nodoc 
   * Set the extrapolation mode 
   * for the extrapolation of the projection result wire on the SupportSurface
   * @param iExtrapolationMode
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No Extrapolation. 
   *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. </dl>
   *     <dt><tt>1</tt><dd> Extrapolation in curvature continuity. </dl>
   */
  void SetExtrapolationMode(short iExtrapolationMode = 0);

  /** @nodoc 
   * Get the extrapolation mode 
   * for the extrapolation of the projection result wire on the SupportSurface
   * @param iExtrapolationMode
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No Extrapolation. 
   *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. </dl>
   *     <dt><tt>1</tt><dd> Extrapolation in curvature continuity. </dl>
   */
  void GetExtrapolationMode(short &oExtrapolationMode);
#endif
};

/** @nodoc  */
inline CATExtHybProject* CATHybProject::GetHybProjectExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybProject*) _Extensible;
}

#endif
