#ifndef CATVisAnnotation_H
#define CATVisAnnotation_H

#include <memory>
//--- visu fw ---//
#include "CATVisAnnotationTypeAndDef.h"

//--- CAT FW ---//
#include "SGInfra.h"
#include "CATVisFilter.h"
#include "CATErrorDef.h"
#include "CAT3DFilterBagRep.h"

//--- Forward Declarations ---//
class CATVisAnnotationStrategy;
class CATVisAnnotationValue;
class CATRepPath;
class CATPathElement;

//++ SGCAAPlan
class IVisSGAnnotation;
//-- SGCAAPlan


/** 
 *	An annotation is a specialized filter which manages contextual filtering on CATReps which are aggregated under the CAT3DFilterBagRep where the annotation is added.	
 *	To use this feature, you will need these files : CATVisAnnotationTypeAndDef.h CATVisAnnotationStrategy.h and CATVisAnnotationValue.h
 *	
 */
class ExportedBySGInfra CATVisAnnotation : public CATVisFilter
{
	CATDeclareVisFilter(CATVisAnnotation);
public:
	//++ SGCAAPlan
	CATVisDeclarePublicInterfaceAdhesion(CATVisAnnotation, IVisSGAnnotation, CATVisAnnotationIVisSGAnnotationBOAImpl);
	//-- SGCAAPlan

	//------------------------------------------------------------------------------

	/** Create an annotation
	 *	@param oAnnotation 
	 *		This output will contain a pointer to a new allocated annotation.
	 *	@param iStrategy
	 *		This class used "strategy" design pattern. Allow the user to do its own implementation. @see CATVisAnnotationStrategy
	 *  @param iMode
	 *		Type of Annotation
	 *	@return S_OK or E_FAIL or E_OUTOFMEMORY or E_ACCESSDENIED or E_INVALIDARG   
	 */
	static HRESULT Create(CATVisAnnotation** oAnnotation, CATVisAnnotationStrategy* iStrategy, fAnnotationMode iMode = fModeNormal);

	/** Add a path element in the annotation and link it with a value
	 *	@param iPath 
	 *		This is the path element the user would like to add in the annotation
	 *	@param iValue 
	 *		This is the value to link with the path element
	 *	@return S_OK or E_FAIL or E_INVALIDARG
	 */
	HRESULT AddPath(CATPathElement* iPath, const CATVisAnnotationValue& iValue) ;

	/** Remove a path element from an annotation
	 *	@param iPath 
	 *		This is the path element the user could like to remove from the annotation
	 *	@return S_OK or E_FAIL or E_INVALIDARG
	 */
	HRESULT RemovePath(CATPathElement* iPath);

	/** Clear the annotation. Remove any path element an its values */
	void	Clear();

	/** Say if the path element is visible or not
	 *	@param iPath 
	 *		This is the path element to find out if it's visible or not
	 *	@return S_OK or E_FAIL or E_INVALIDARG	 
	 */
	HRESULT IsPathVisible(CATPathElement* iPath);

	/** Return the mode of the annotation
	 *	@return fAnnotationMode 	
	 */
	fAnnotationMode GetMode() const;

	/** Returns the strategy internally used by the annotation */
	HRESULT GetStrategy(CATVisAnnotationStrategy*& oStrategy) const;

	/**
	 * @brief Returns a CATPathElement (copy) and its associated CATVisAnnotationValue 
	 * 
	 * @param iIndex 
	 * @param oPath [out, IUnknown#Release] 
	 * @param oValue 
	 * @return HRESULT 
	 */
	HRESULT GetPath(size_t iIndex, CATPathElement*& oPath, std::shared_ptr<CATVisAnnotationValue>& oValue) const;

	//------------------------------------------------------------------------------

	/** INTERNAL USE ONLY (Visualization Team) */
	void	Initialize();

	//+++ DEPRECATED : DO NOT USE IT
	static HRESULT Create(CATVisAnnotation** oAnnotation, CAT3DFilterBagRep* iRep, CATVisAnnotationStrategy* iStrategy, fAnnotationMode iMode = fModeNormal);
	//--- DEPRECATED : DO NOT USE IT

  virtual void Visit(VisSGFilterVisitor& iVisitor) const;

  size_t GetNumPaths() const;

	
protected:

	HRESULT _Build(CATVisAnnotationStrategy* iStrategy, fAnnotationMode iMode);
	
	//+++ CTR/DTR
	CATVisAnnotation();
	virtual ~CATVisAnnotation();
	//--- CTR/DTR

};

#endif // end : CATVisAnnotation_H
