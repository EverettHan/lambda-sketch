#ifndef CATDynAdvancedDraft_H
#define CATDynAdvancedDraft_H

// COPYRIGHT DASSAULT SYSTEMES  2003

#include "CATDynDraft.h"
#include "AdvancedDraft.h"
#include "CATFreeFormDef.h"
#include "CATIAV5Level.h"
#include "ListPOfCATBody.h"
#include "CATListOfInt.h"
#include "CATDynDraftReorderZone.h" // SOU : 2004:3:9

class CATGeoFactory;
class CATBody;
class CATTopData;
class CATDynSolidDraftCGM;
class CATAutomaticDraftContext;

class CATPoint;
class CATPlane;

/**
* Class defining an operator to draft faces of a 3D body.
* This operator offers more capabilities than <tt>CATICGMDynDraft</tt> and 
* might be able generate a result in cases where <tt>CATICGMDynDraft</tt> could fail.
* <br>
* <br>
* The <tt>CATICGMDynAdvancedDraft</tt> operator follows the global frame of the topological
* operators and satisfies the smart mechanism: 
* the input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>A <tt>CATICGMDynAdvancedDraft</tt> operator is created with the <tt>CATCGMCreateDynAdvancedDraft</tt> global method:
* It must be directly released with the <tt>Release</tt> method after use. It is not streamable. 
*<li>Options can be precised (such as the untwist mode) with the appropriate methods, before
* asking for the computation with the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
*/
class ExportedByAdvancedDraft CATDynAdvancedDraft : public CATDynDraft
{
  CATCGMVirtualDeclareClass(CATDynAdvancedDraft);
  public:
  /* Do not use */
  CATDynAdvancedDraft(CATGeoFactory*     iContainer,
                      CATTopData*        iData,
                      CATDynSolidDraftCGM* iImplementation);

  virtual ~CATDynAdvancedDraft();

  /**
   * @nodoc
   */
  void SetContinuityLevel(const CATFrFContinuity  iContinuityLevel, // CATFrFPointCont or CATFrFTangentCont
                          const CATPositiveLength iTolerance = 0.); // Default = approximation not allowed

  /**
   * @nodoc
   */
  void GetRecommendedLimitingElements(CATLISTP(CATBody) &oListLimitingBody,
                                      CATListOfInt      &oListLimitingOrientations);

  //to be used after Run()
  //Get the number of twist zones that caused the failure of draft operation
  /** @nodoc */
  int GetNumberOfTwistZones();

  //to be used after Run()
  //Get the reorder zone corresponding to a given twist zone index and given CATDynDraftReorderZoneParams 
  //you need to delete the memory allocated by the operator to oReorderZone
  //returns TRUE on success. else FALSE
  /** @nodoc */
  CATBoolean GetReorderZone(const int &iReorderZoneIndex, CATDynDraftReorderZone* &oReorderZone
                            ,CATDynDraftReorderZoneParams* iReorderParams = 0);
                                  
  //to be used before Run()
  //This will fail if used together with SetUntwistDraftFillFunction
  //The SetAutomaticUntwistMode method will also fail under this condition!
  //The iReorderZone may not get used for untwisting if it is invalid
  //returns TRUE on success. else FALSE
  /** @nodoc */
  CATBoolean SetReorderZone(CATDynDraftReorderZone* iReorderZone);

  //to be used before Run()
  //This will set the option to keep features during the draft both sides
  /** @nodoc */
  void SetKeepFeature( CATBoolean iKeepFeature );

  /**
   * Defines how twisted topology is handled.
   * <br>By default, the automatic untwisting of topology is turned off.  When activated, the twisting is repaired.
   * @param iAutoUntwistMode
   * If <tt>iAutoUntwistMode</tt> is TRUE, untwisting is activated.
   */
  void SetAutomaticUntwistMode(CATBoolean iAutoUntwistMode);

  //iAutoUntwistOffset = the offset used to modify the limits of default twist zones  on neutral wire (mm). 1mm is the default offset
  /** @nodoc */
  void SetAutomaticUntwistOffset(double iAutoUntwistOffset); 

  // For DraftBothSides fitted Draft, to be used before Run() and with SetAutomaticUntwistMode on
  //By default automatic gapfill mode is off
  //one can activate it by using iAutoGapFillMode=TRUE
  /** @nodoc */
  void SetAutomaticGapFillMode(CATBoolean iAutoGapFillMode); 

  // For DraftBothSides Reflect-Reflect Draft, to be used after Run()
  /** @nodoc */
  int GetNumberOfLimitingElements();
  /** @nodoc */
  void GetLimitingElement(int iNumber, double iShift, CATBody *& oLimitingElement, CATOrientation &oOrientation);

  /**
   * @nodoc
   */
  void SetAutomaticDraftContext(CATAutomaticDraftContext *iContext);

  /**
   * @nodoc
   */
  void SimplifyDraftOnTransversEdges(CATBoolean iSimplifyDraft = TRUE);

   /**
   * @nodoc
   */
  void NeedOrderAgnosticResult(CATBoolean iValue = TRUE);

};

/**
 * Creates a CATDynDraft operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iPart
 * The pointer to the body to draft.
 * @param iType
 * The type of the draft operation.
 * @return [out, delete]
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByAdvancedDraft CATDynAdvancedDraft* CATCreateDynAdvancedDraft(CATGeoFactory*        iContainer,
                                                                       CATTopData*           iData,
                                                                       CATBody*              iPart,
                                                                       const CATDynDraftType iType);

#endif
