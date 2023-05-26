#ifndef _CATPLMComponentSpaceFilter_H
#define _CATPLMComponentSpaceFilter_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @level Protected
 * @usage U1       
 */
#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATPLMCoreType.h"
#include "CATPLMTypeDefinitionStrings.h"
#include "CATPLMTypeHArray.h"

/**
*  Allows to filter components on space
*/
class ExportedByCATPLMIdentificationAccess CATPLMComponentSpaceFilter
{
public:

  /** 
  * Empty Constructor
  * */
  CATPLMComponentSpaceFilter();

	/**
  * Destructor
  */
	virtual ~CATPLMComponentSpaceFilter();

  /**
  * @deprecated V6R214
  * @use SetCoreTypeHFilter( const CATUnicodeString & iPLMType )
  */
	CATPLMComponentSpaceFilter & SetCoreTypeFilter( CATPLMCoreType iCoreType );

  /**
  * Define filter based on core type
  *
  * @param iTypes
  *    Specified Core Type filter
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
	CATPLMComponentSpaceFilter & SetCoreTypeHFilter( const CATUnicodeString & iPLMType );

private:

  friend class CATOxEventsFilter;

	/* forbidden operations */
	CATPLMComponentSpaceFilter (CATPLMComponentSpaceFilter &);
	CATPLMComponentSpaceFilter& operator=(CATPLMComponentSpaceFilter&);

	/* heap is forbidden */
	void *operator new(size_t iSize,void *iAllocType=NULL, void *iAddr=NULL,int iReservedSize=0); 

  void ReAllocateCoreTypesFilter(short iNumberOfNewlyAllocated);

  short            _CoreTypeUsed;
  short            _CoreTypeAllocated;
  CATPLMCoreType * _CoreType;  
  CATPLMTypeHArray _CoreTypeH;
};

#endif
