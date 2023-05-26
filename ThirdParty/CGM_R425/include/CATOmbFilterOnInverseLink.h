#ifndef CATOmbFilterOnInverseLink_H
#define CATOmbFilterOnInverseLink_H


// COPYRIGHT Dassault Systemes 2007


/**
* @level Protected
* @usage U1
*/


#include "CATObjectModelerBase.h"
#include "CATBoolean.h"
#include "CATIOmbFunction.h"

class CATOmbFilterOnInverseLinkImpl;
class CATUnicodeString;

/**
* Class that enables to build a filter to get inverse links.
*/

class ExportedByCATObjectModelerBase CATOmbFilterOnInverseLink
{
public:

	/**
	* The type of link to retrieve.
	* @param External
	*  External links.
	* @param Reference
	*  Instance/reference links.
	* @param AllLinkType
	*  All links.
	*/
	enum LinkType{ External, Reference, AllLinkTypes };

	/**
	* Constructs a filter with the default parameters.
	*/
	CATOmbFilterOnInverseLink();

	/**
	* Constructs a filter with specified parameters.
	* @param ipLateTypeFilter
	*  The late type of the pointing objects to returned.
	* @param iType
	*  The type of the inverse links to process.
	* @param iIncludingVO
	*  If TRUE, and if the object is included in a VO, all inverse links on the VO will be processed.
	*/

	CATOmbFilterOnInverseLink( const char *ipLateTypeFilter, LinkType iType, CATBoolean iIncludingVO );

	/**
	* Constructs a filter with specified parameters.
	* @param ipLateTypeFilter
	*  The late type of the pointing objects to returned.
	* @param iType
	*  The type of the inverse links to process.
	* @param iIncludingVO
	*  If TRUE, and if the object is included in a VO, all inverse links on the VO will be processed.
	* @param iAttributeName
	*  The name of the pointing attributes to process.
	*/
    CATOmbFilterOnInverseLink( const char *ipLateTypeFilter, LinkType iType, CATBoolean iIncludingVO, CATUnicodeString iAttributeName );

	/**
	* Copy constructor.
	*/
	CATOmbFilterOnInverseLink( const CATOmbFilterOnInverseLink& iFilter );

	~CATOmbFilterOnInverseLink();

	/**
	* Sets a filter on the late type of the pointing objects.
	* <br><b>Note:</b>Only the objects with this late type will be returned. 
	* <br>If no late type is set, all links are processed.
	* @param ipLateTypeFilter
	*  The late type of the pointing objects to returned.
	* @return
	*  The filter itself.
	*/
	CATOmbFilterOnInverseLink& SetLateTypeFilter( const char *ipLateTypeFilter );

	/**
	* Sets a filter on the type of the inverse links.
	* <br><b>Note:</b>Only the link with this type will be processed. 
	* @param iType
	*  The type of the inverse links to process.
	* @return
	*  The filter itself.
	*/
	CATOmbFilterOnInverseLink& SetLinkTypeFilter( LinkType iType );

	/**
	* Sets a filter on including VO.
	* @param iIncludingVO
	*  If TRUE, and if the object is included in a VO, all inverse links on the VO will be processed.
	* @return
	*  The filter itself.
	*/
	CATOmbFilterOnInverseLink& SetIncludingVOFilter( CATBoolean iIncludingVO );

    CATOmbFilterOnInverseLink & SetFilterFunction (CATIOmbFunction_var &);

	/**
	* Sets a filter on the name of the attribute of the pointing objects.
	* <br><b>Note:</b>Only the objects with this name of attribute will be returned. 
	* <br>If no attribute name is set, all links are processed.
	* @param iAttributeName
	*  The attribute name of the pointing objects to returned.
	* @return
	*  The filter itself.
	*/
    CATOmbFilterOnInverseLink& SetAttributeNameFilter(CATUnicodeString & iAttributeName);

	/**
	* Gets the late type set on the current filter.
	* @return
	*  The late type, NULL if it is not set.
	*/
	const char* GetLateTypeFilter() const ;

	/**
	* Gets the link type set on the current filter.
	* @return
	*  The link type.
	*/
	LinkType GetLinkTypeFilter() const ;

	/**
	* Checks whether the including VO filter is active or not.
	* @return
	*  TRUE if the filter is active, FALSE else.
	*/
	CATBoolean GetIncludingVOFilter() const ;

	/** 
	* The filter with the default parameters.
	* <br><b>Note:</b>By default, there is no filter on late type, 
	* only external links are retrieved and 
	* the inverse links on the including VO are not retrieved.
	*/
	static const CATOmbFilterOnInverseLink DefaultFilter;

	/** 
	* The filter to ignore the link type.
	* <br><b>Note:</b>There is no filter on late type and
	* the inverse links on the including VO are not retrieved.
	*/
	static const CATOmbFilterOnInverseLink AllLinkTypesFilter;

    CATIOmbFunction_var  GetFilterFunction() const;

	/**
	* Gets the attribute name set on the current filter.
	* @return
	*  The attribute name.
	*/
    CATUnicodeString GetAttributeNameFilter() const;

private:

    CATOmbFilterOnInverseLinkImpl * _impl;
};

#endif

