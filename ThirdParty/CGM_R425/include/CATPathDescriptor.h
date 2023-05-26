#ifndef CATPathDescriptor_h
#define CATPathDescriptor_h

#include "CATIPathTypeDescriptor.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATLifSpecs.h"

//----------------------------------------------------------------------------------------------------------------------------------------
// This class is proposed to software components that start from a path and want to access some information on it
// - the CATIPathTypeDescriptor that regroups behavioral patterns related to such a path 
// - the display name that can be shown in UI (Edit Links / Impact graph)
// - to test if such a path corresponds to a path type that they know of
// They need to build a CATPathDescriptor from the different persistent information available on the path
// - the path type name (the type of path)
// - the value stored in the Role attribute
// - the value stored in the Category attribute
// If the values do not correspond to an existing path type, the CATPathDescriptor will be invalid
// Note that at the origin, we imagined that applications would manipulate in memory this triplet that would correspond to the real persistency
// Later, we made the choice that this information would only rely on path type !
//
// Starting from a SR, the sequence of code is the following
//	  CATPLMSemanticRelationData* pSRData = NULL;
//    SemanticRelation.GetSRData(&pSRData); // SemanticRelation is a CATPLMSemanticRelation
//    pSRData->GetSemanticsN(oIDrel,iPathTypeName,iCategory,iRole); // Note that this method has 4 arguments compared to the previous one
//	  CATPathDescriptor pathDescriptor (iPathTypeName,iRole,iCategory);
//
//----------------------------------------------------------------------------------------------------------------------------------------
 
class  ExportedByCATLifSpecs CATPathDescriptor
{
	
public :
	
	/**
	 * Constructor to create a CATPathDescriptor from the persistent information on the path
   * The persistent information is retrieved in session, or through PLM Adapter (MQL)
	 * @param  iPathTypeNameStoredOnThePath is the name of the path type stored on the path
	 * @param  iRoleNameStoredOnThePath is the value stored in the role attribute (that may be empty when path type project is activated)
	 * @param  iCategoryNameStoredOnThePath is the value stored in the category attribute (that may be empty when path type project is activated)
   * It is important to understand that these 3 informations are just what is stored on the path data model
	 */
	CATPathDescriptor (	const CATUnicodeString &iPathTypeNameStoredOnThePath,
						          const CATUnicodeString &iRoleNameStoredOnThePath,
						          const CATUnicodeString &iCategoryNameStoredOnThePath);

	/**
	 * Constructor to create a CATPathDescriptor from the persistent information on the path
   * The persistent information is retrieved in session, or through PLM Adapter (MQL)
	 * @param  iPathTypeName is the name of the path type stored on the path
	 */
	CATPathDescriptor (	const CATUnicodeString &iPathTypeName);

	/** 
	 * Destructor
	 */
	virtual ~CATPathDescriptor() ;

	/**
	 * Copy constructor 
	 */
	CATPathDescriptor (const CATPathDescriptor&);

	/** 
	 * Indicates if the path descriptor is a valid one
   * A path is valid if we can retrieve the path type name in the PLM Dictionary (whether it is local or global path type)
   * We also verify that role and category are empty if they are supposed to be empty (CATUnicorn::RoleAndCategoryReplaced()==true)
	 * If it is not valid, PathDescriptor & PathTypeDisplayName methods won't work
	 */
	CATBoolean IsValid() const;

	/** 
	 * Returns the path descriptor if the path was valid
	 */
	CATIPathTypeDescriptor_var PathDescriptor () const;
	
	/** 
	 * Returns the NLS name to display in the user interface if the path was valid
	 */
	CATUnicodeString PathTypeDisplayName() const ;

  /**
   * Tests if the path corresponds to a particular type (that is expressed with a path type name)
   * Here again, it is important to understand that the PathTypeName in input is the path type known by the application
   * @param  iPathTypeName is the name of the path type known by the application. For example, ClassA.Rel1 for local paths or Role_Categorie or PathTypeName2 for global paths 
   * @return TRUE if the semantic relation is of the right path type
   */
  CATBoolean Recognize (const CATUnicodeString &iPathTypeName) const;


private:
	
	// Input elements
	CATUnicodeString _PathTypeNameStoredOnPath;
	CATUnicodeString _RoleNameStoredOnPath;
  CATUnicodeString _CategoryNameStoredOnPath;

	// Computed values
	CATUnicodeString _DisplayName;
	CATIPathTypeDescriptor_var _PathDescriptor;
	CATBoolean _isValid;

	// Method computing the display name, the path type descriptor and the validity status
	void Compute();
}; 

#endif


