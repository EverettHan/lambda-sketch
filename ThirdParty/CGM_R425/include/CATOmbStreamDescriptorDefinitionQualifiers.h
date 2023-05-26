// COPYRIGHT Dassault Systemes 2005
//===================================================================
//  Apr 2005  Creation: Code generated by the CAA wizard  PHB
//===================================================================
#ifndef CATOmbStreamDescriptorDefinitionQualifiers_H
#define CATOmbStreamDescriptorDefinitionQualifiers_H

/**
* @level  Private
* @usage   U1
*/

#include "CATOmbSelectiveLoading.h"
#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATOmbStreamDescriptorFormat.h"
#include "CATOmbLoadableDataUniqueKey.h"

//-----------------------------------------------------------------------
/**
* Set of qualifiers for a stream descriptor definition.
*/
class ExportedByCATOmbSelectiveLoading CATOmbStreamDescriptorDefinitionQualifiers
{
public:
	/**
	*	Creates a Set of Qualifiers for a Stream Descriptor Definition.
	*
	* @param oQualifiers
	*	Created Set, if the execution is successful.
	*
	* @param iFormat
	*	Format of the stream descriptor.
	*
	* @param iRole
	*	Role of the stream descriptor.
	*
	* @param iLateType
	*	Late Type of the stream descriptor.
	*
	* @param iCheckWithSelectiveLoadingDictionary
	*	Indicate if check of definition existence must be done.
	*
	* @return
	*	S_OK, if creation succeeded.
	*	E_INVALIDARG, if format is not a valid one or if Late Type is not provided.
	*	E_FAIL, if tuple {iFormat,iRole,iLateType} is not in the SelectiveLoading dictionary.
	*/

	//Deprecated, use new identification (Format, iRole, iLateType, iPersistencyName)
	static
	HRESULT Create
		( CATOmbStreamDescriptorDefinitionQualifiers*&	oQualifiers
		, CATOmbStreamDescriptorFormat					iFormat
		, const CATUnicodeString&						iRole
		, const CATUnicodeString&						iLateType
		, CATBoolean iCheckWithSelectiveLoadingDictionary = TRUE
		);

	static
	HRESULT Create
		( CATOmbStreamDescriptorDefinitionQualifiers*&	oQualifiers
		, CATOmbStreamDescriptorFormat					iFormat
		, const CATUnicodeString&						iRole
		, const CATUnicodeString&						iLateType
		, const CATUnicodeString&						iPersistencyName
		, CATBoolean iCheckWithSelectiveLoadingDictionary
		);

	/**
	*	Creates a Set of Qualifiers for a Stream Descriptor Definition.
	*
	* @param oQualifiers
	*	Created Set, if the execution is successful.
	*
	* @param iKey
	*	Unique Key of the stream descriptor.
	*
	* @param iLateType
	*	Late Type of the stream descriptor.
	*
	* @param iCheckWithSelectiveLoadingDictionary
	*	Indicate if check of definition existence must be done.
	*
	* @return
	*	S_OK, if creation succeeded.
	*	E_INVALIDARG, if format is not a valid one or if Late Type is not provided.
	*	E_FAIL, if tuple {iFormat,iRole,iLateType} is not in the SelectiveLoading dictionary.
	*/
	static
	HRESULT Create
		( CATOmbStreamDescriptorDefinitionQualifiers*&	oQualifiers
		, const CATOmbLoadableDataUniqueKey&			iKey
		, const CATUnicodeString&						iLateType
		, CATBoolean iCheckWithSelectiveLoadingDictionary
		);


	//-----------------------------------------------------------------------
	//	CDTORS
	//	======
	/**
	*	Copy-Constructs a Set of Qualifiers for Stream Descriptor Definition.
	*/
	CATOmbStreamDescriptorDefinitionQualifiers ( const CATOmbStreamDescriptorDefinitionQualifiers& );
	/**
	*	Assigns a Set of Qualifiers for Stream Descriptor Definition to another Set.
	*/
	CATOmbStreamDescriptorDefinitionQualifiers&	operator= ( const CATOmbStreamDescriptorDefinitionQualifiers& );
	/**
	*	Destroys a Set of Qualifiers for Stream Descriptor Definition.
	*/
	~CATOmbStreamDescriptorDefinitionQualifiers();


	//-----------------------------------------------------------------------
	//	ACCESSORS
	//	=========
	/**
	*	Returns the Key of the Stream Descriptor for the SelectiveLoading dictionary.
	*/
	inline const CATOmbLoadableDataUniqueKey&			GetKey () const	{ return _Key; }

	/**
	*	Returns the Format of the Stream Descriptor.
	*/
	inline const CATOmbStreamDescriptorFormat&	GetFormat () const		{ return _Key.GetFormat(); }

	/**
	*	Returns the Role of the Stream Descriptor.
	*/
	inline const CATUnicodeString&			GetRole () const		{ return _Key.GetRole(); }

	/**
	*	Returns the Late Type for the Stream Descriptor.
	*/
	inline const CATUnicodeString&			GetLateType () const	{ return _LateType; }

    /**
    * Sets the PersistencyType of the Stream Descriptor.
    * @param iPersistencyType  The new persistency type.    
    */        
    inline void SetLateType(const CATUnicodeString& iLateType)     {_LateType = iLateType; }
  
	//-----------------------------------------------------------------------
	//	OPERATORS
	//	=========
  inline int operator==( const CATOmbStreamDescriptorDefinitionQualifiers&	iOpD ) const {return _Key==iOpD._Key && _LateType==iOpD._LateType;}
  inline int operator!=( const CATOmbStreamDescriptorDefinitionQualifiers&	iOpD ) const {return !this->operator==(iOpD);}
  
	      
private:
	//-----------------------------------------------------------------------
	// Data members
	// ============
	CATOmbLoadableDataUniqueKey		_Key;
	CATUnicodeString				_LateType;

	//-----------------------------------------------------------------------
	// For the Create static methods
	// =============================
public:
  //Do not use, reserved for Omb internal usage
	CATOmbStreamDescriptorDefinitionQualifiers(const CATOmbLoadableDataUniqueKey&	iKey,const CATUnicodeString&	iLateType);

  

};

//-----------------------------------------------------------------------

#endif