#ifndef CATDynTransformation_H_
#define CATDynTransformation_H_

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
*/
#include "CATDynOperator.h"
#include <CATMathDef.h>
#include "CATCGMDynTransformationReportMode.h"

class CATMathVector;
class CATBody;
class CATMathPlane;
class CATMathTransformation;
class CATMathPoint;
class CATMathLine;
class CATTopData;

  /**
* Class representing the topological operator that transforms a CATBody.
* <br>
* It follows the use frame of all operator and satisfies to the smart mechanism: the
* input body is not modified. A new resulting body is created, 
* possibly sharing data with the input one.
*<ul>
* <li>A CATDynTransformation is created with the <tt>CATCreateDynTransformation</tt> global function:
* It must be
* directly deleted after use with the usual C++ <tt>delete</tt> operator.
* It is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method. In particular, the operator can be re-use to
* transform the same body with different transformations; in this case, you can precise another journal to
* be filled, with the <tt>SetNewJournal</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. 
*</ul>
* This operator is optimized and simplified with regards to the @href CATTransfoManager : The CATDynTransfomation
* operator chooses the best way to call the CATTransfoManager. In another way, the CATTransfoManager provides more
* options.
*/

class ExportedByBODYNOPE CATDynTransformation : public CATDynOperator
{
  CATCGMVirtualDeclareClass(CATDynTransformation);
public:
 /** 
  * @nodoc
  * Deprecated.
  * Virtual constructor.<br>
  * Cannot be called. Use the <tt>CATDynCreateTransformation</tt> global function
  * to create a CATDynTransformation.
	*/
  CATDynTransformation (  CATGeoFactory* 
                        , CATCGMJournalList* journal=NULL
#ifdef CATIACGMR419CAA
                        , CATExtTopOperator*      iExtensible = NULL
#endif
                        );

  /** 
  * @nodoc
  * Virtual constructor.<br>
  * Cannot be called. Use the <tt>CATDynCreateTransformation</tt> global function
  * to create a CATDynTransformation.
	*/
  CATDynTransformation (  CATGeoFactory* 
                          , CATTopData* 
#ifdef CATIACGMR419CAA
                          , CATExtTopOperator*      iExtensible = NULL
#endif
                       );

   /**
	* Destructor.
	*/
  virtual ~CATDynTransformation();
	
	/**
	* Defines <tt>this</tt> CATDynTransformation as a translation.
	* @param iTranslationVector
	* The vector of the translation.
	*/
  virtual void SetTranslation    (const CATMathVector& iTranslationVector) = 0;
	
	
	/**
	* @nodoc
	*  Deprecated, use now the signature 
	* <tt>SetRotation       (const CATAngle iAngle, const CATMathLine & iAxis) </tt>,
	* where the angle is in radian.
	* <br>Defines the CATDynTransformation as a rotation.
	* @param iOrigin
	* The origin of the plane perpendicular to the rotation axis.
	* @param iAxis
	* Direction of the rotation.
	* @param iAngle
	* Angle of the rotation (in degrees).
	*/
	virtual void SetRotation       (const CATMathPoint& iOrigin,const CATMathVector& iAxis,CATAngle iAngle) = 0;
	
	/**
	* Defines <tt>this</tt> CATDynTransformation as a rotation.
	* @param iAngle
	* The angle of the rotation (in radians).
	* @param iAxis
	* The direction of the rotation.
	*/
  virtual void SetRotation       (const CATAngle iAngle, const CATMathLine & iAxis) = 0;
	
	
	/**
	* Defines <tt>this</tt> CATDynTransformation as a symmetry.
	* @param iSymmetryPlane
	* The plane of symmetry.
	*/
  virtual void SetSymmetry       (const CATMathPlane& iSymmetryPlane) = 0;

	/**
	* Defines <tt>this</tt> CATDynTransformation as an affinity.
	* @param iReflectPlane
	* The plane for the reflecting part of the affinity.
	* @param iRatio
	* The value of the ratio for the scaling part of the affinity.<br>
	* The value <tt>iRatio=-1</tt> is the only value allowed for the moment.
	* Use better the <tt>SetSymmetry</tt> method.
	*/
  virtual void SetAffinity       (const CATMathPlane& iReflectPlane, CATLength iRatio) = 0;
	
	/**
	* Defines <tt>this</tt> CATDynTransformation as a scaling.
	* @param iOrigin
	* The origin of the scaling.
	* @param iRatio
	* The value of the scaling
	*/
  virtual void SetScaling        (const CATMathPoint& iOrigin, CATLength iRatio) = 0;
	
	/**
	* Sets to <tt>this</tt> CATDynTransformation the parameters of a given transformation.
	* @param iTransformation
	* The mathematical definition of the transformation.
	*/
  virtual void SetTransformation (const CATMathTransformation& iTransformation) = 0;
	
	
	/**
	* Type of follow-up to be written in the journal.<br>
	* This information is used by applications, depending on the type of operations they want to 
	* perform after calling the transformation. This information has no impact on the objects of the
	* geometrical modeler itself.
	* @param CATDynModification
	* The transformation is seen as a modification: the body is always duplicated, but the application
	* wants to mask the input body for showing only the resulting body (case of an applicative
	* transformation). This is the default of a CATDynTransformation.
	* @param CATDynCreation
	* The transformation is seen as a creation: The application keeps the input body and
	* the duplicated body, and wants to union them for example:
	* this is a typical case of an applicative operation of mirror.
	*/
  enum CATDynReportMode { CATDynModification= CATCGMDynTransformationModification ,CATDynCreation=CATCGMDynTransformationCreation }; 
	
	/**
	* Defines the type of follow-up of the modifications to write in the journal.<br>
    * This information is used by applications, depending on the type of operations they want to 
	* perform after calling the transformation. This information has no impact on the objects of the
	* geometric modeler itself.
	* @param iTypeOfFollowUp
	* The type of report mode.
	* <br><b>Legal values</b>:
	* <dl><dt><tt>CATDynModification</tt></dt>
	* <dd>The transformation is seen as a modification: the body is always duplicated, but the application
	* wants to mask the input body for showing only the resulting body (case of an applicative
	* transformation). This is the default of a CATDynTransformation.
	* <dt><tt>CATDynCreation</tt></dt>
	* <dd>The transformation is seen as a creation: The application keeps the input body and
	* the duplicated body, and wants to union them for example:
	* this is a typical case of an applicative operation of mirror.
	* </dl>
	*/
  virtual void SetReportMode(CATDynReportMode iTypeOfFollowUp) = 0;
	
	/**
	 * Defines whether a CATCGMJournalInfo has to be added to the item corresponding to <tt>this</tt> operation.
	 * @param iTrueOrFalse
	 * <tt>TRUE</tt> if an additional information must be added to the item, <tt>FALSE</tt> otherwise. In case of
	 * adding the additional information, this information is put to 0.
	 */
  virtual void SetJournalInfo(CATBoolean iTrueOrFalse) = 0;
	
	/**
	 * Defines another journal to be filled after another run of <tt>this</tt> operator.
	 * @param iJournal
	 * The pointer to the new journal to be filled in another run. This can be used in case of
	 * pattern transformation, if you want that each occurence has a different journal. 
	 */
  virtual void SetNewJournal(CATCGMJournalList* iJournal) = 0;

/**
   * Controls whether the operator will use full duplicate mode (false by
   * default). <br>By default, before the transformation is performed, the
   * operator checks for surfaces that will remain invariant under the
   * transformation. These surfaces are re-used in the output, rather than being
   * copied and transformed. Calling <tt>SetFullDuplicateMode(TRUE)</tt>
   * will make the operator skip this optimization step and create duplicates of
   * every input surface.
   * @param iYesOrNo If <tt>TRUE</tt>, sets the operator to full duplicate mode.
   */
  virtual void SetFullDuplicateMode(CATBoolean iYesOrNo) = 0;

};
/**
* Creates a CATDynTransformation.
* @param iFactory
* The factory of the geometry. 
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iBodyToTransform
* The pointer to the body to transform. This body will not be modified. A new resulting
* body is created, that can be retrieved by the <tt>GetResult</tt> method.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/
ExportedByBODYNOPE CATDynTransformation* CATCreateDynTransformation (CATGeoFactory*     iFactory,
                                                                     CATTopData*        iData,
                                                                     CATBody*           iBodytoTransform) ;    
/**
* @nodoc
* Deprecated. Use CATCreateDynTransformation.
*/
ExportedByBODYNOPE CATDynTransformation* CATDynCreateTransformation (CATGeoFactory*     iFactory,
                                                                     CATTopData*        iData,
                                                                     CATBody*           iBodytoTransform) ;    

/**
* @nodoc
* Deprecated. Use CATCreateDynTransformation.
*/
ExportedByBODYNOPE CATDynTransformation* CATDynCreateTransformation (CATGeoFactory*     iFactory,
                                                                     CATBody*           iBodytoTransform,
                                                                     CATCGMJournalList* iJournal=NULL) ;    

#endif
