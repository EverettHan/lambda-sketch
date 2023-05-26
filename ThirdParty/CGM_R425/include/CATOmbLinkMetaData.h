#ifndef CATOmbLinkMetaDataDescriber_H
#define CATOmbLinkMetaDataDescriber_H


// COPYRIGHT Dassault Systemes 2005

/**
 * @level Private
 * @usage U1
 */

// BSFBuildtimeData
#include "CATIAV5Level.h"
// System
#include "CATUnicodeString.h"
// SystemTS
#include "CATBoolean.h"
// CATPLMIdentificationAccess
#include "CATSemanticRelationMetaData.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"
#include "CATOmbPLMRelationshipSemantics.h"

/**
 * Class that defines a set of properties on a link.
 * <b>Role</b>: A CATOmbPrivateLinkMetaData stores the properties on a link
 * between two objects of different components.
 */

class ExportedByCATObjectModelerBase CATOmbPrivateLinkMetaData
{
public:

  /** 
   * The existing properties on a link that can be set or unset.
   * @param Sync
   *	To activate a "synchronization" button in Edit Links.
   * @param Deactivation
   *	To activate a "deactivate link" menu/button.
   * @see #Set
   */
  enum LinkProperty { Sync, Deactivation };

  /**
   * Constructs an instance of CATOmbPrivateLinkMetaData.
   */
  CATOmbPrivateLinkMetaData();

  /** @nodoc */
  // default: CATOmbPrivateLinkMetaData(const CATOmbPrivateLinkMetaData & iOther) = default;
  
  /** @nodoc */
  ~CATOmbPrivateLinkMetaData();
  
  /**
   * Sets the name of the link that will be displayed on the Edit/Links window.
   * @param iName
   *	The name of the link to set.
   */
  inline void SetName( const CATUnicodeString& iName ) { _Name = iName; };

  
  /**
   * Sets or unsets a property.
   * @param iLinkProperty
   *	The link property to set or unset.
   * @param iValue
   *	Use CATTrue to set the property or CATFalse to unset it.
   * @return
   *	An HRESULT value: 
   *	<dl>
   *		<dt>S_OK</dt>
   *			<dd>The property has successfully been set.</dd>
   *		<dt>E_FAIL</dt>
   *			<dd>The given property is not available.</dd>
   *	</dl>
   */
  HRESULT Set( LinkProperty iLinkProperty, CATBoolean iValue );
  
  /**
   * Returns the name of the link that will be displayed on the Edit/Links window.
   * @return
   *	The name of the link.
   */
  inline const CATUnicodeString& GetName() const { return _Name; };

  /**
   * Returns the status of a property.
   * @param iLinkProperty 
   *	The link property to check.
   * @return
   *	A CATBoolean:
   *	<dl>
   *		<dt>CATTrue</dt>
   *			<dd>The property is set.</dd>
   *		<dt>CATFalse</dt>
   *			<dd>The property is not set.</dd>
   *	</dl>
   */
  CATBoolean Get( LinkProperty iLinkProperty ) const;

  /** @nodoc */
  int operator== ( const CATOmbPrivateLinkMetaData& iPrivateLinkMetaData ) const;

  /** @nodoc */
  int operator!= ( const CATOmbPrivateLinkMetaData& iPrivateLinkMetaData ) const;

private:

  CATOmbPrivateLinkMetaData& operator=(const CATOmbPrivateLinkMetaData &); //not implemented
  
  CATUnicodeString _Name;
  CATUINTPTR m_BitField;
};


#include "CATOmbRelationMetaData.h"


/**
 * Class that embeds the properties on a link and on its relation.
 */
class ExportedByCATObjectModelerBase CATOmbLinkMetaData
{
public :
  
  /**
   * Creates an instance of CATOmbLinkMetaData.
   * <br><b>Role</b>: this factory is used to instantiate a CATOmbLinkMetaData from an instance 
   * of CATOmbPrivateLinkMetaData and an instance of CATOmbRelationMetaData.
   * @param iPrivateLinkMetaData
   *	The instance of CATOmbPrivateLinkMetaData.
   * @param iRelationMetaData
   *	The instance of CATOmbRelationMetaData.
   * @return
   *	The instantiated object. 
   */
  static CATOmbLinkMetaData* GetLinkMetaData( 
    CATOmbPrivateLinkMetaData& iPrivateLinkMetaData, 
    CATOmbRelationMetaData& iRelationMetaData );	
  
  /** @nodoc */
  ~CATOmbLinkMetaData();

  /**
   * Returns the instance of CATOmbPrivateLinkMetaData.
   * @return
   *	The instance of CATOmbPrivateLinkMetaData.
   */
  inline const CATOmbPrivateLinkMetaData& GetPrivateLinkMetaData() const { return _PrivateLinkMetaData; };

  /**
   * Returns the instance of CATOmbRelationMetaData.
   * @return
   *	The instance of CATOmbRelationMetaData.
   */
  inline CATOmbRelationMetaData& GetRelationMetaData() const { return _RelationMetaData; };

  /**
   * Returns the default instance of CATOmbLinkMetaData.
   * <br><b>Note:</b>Used when metadata are not specified on tk_ext.
   * @return
   *	The default instance of CATOmbLinkMetaData.
   */
  static CATOmbLinkMetaData& GetDefaultLinkMetaData();

  /**
   * Returns the dummy instance of CATOmbLinkMetaData.
   * <br><b>Note:</b>Used when metadata are not specified.
   * Should not be used out of product instance or reference, except for pointed catalogs.
   * @return
   *	The dummy instance of CATOmbRelationMetaData.
   */
  static CATOmbLinkMetaData& GetDummyLinkMetaData();

  /** @nodoc */
  int operator== ( const CATOmbLinkMetaData& iLinkMetaData ) const;

  /** @nodoc */
  int operator!= ( const CATOmbLinkMetaData& iLinkMetaData ) const;

  /** @nodoc */
  ULONG __stdcall AddRef() { return 0; } // TODO : Remove

  /** @nodoc */
  ULONG __stdcall Release() { return 0; } // TODO : Remove

  /** @nodoc */
  static void RemoveAll();
  

private:
  
  CATOmbLinkMetaData( const CATOmbLinkMetaData& ); //not implemented
  CATOmbLinkMetaData& operator=( const CATOmbLinkMetaData& ); //not implemented

  CATOmbLinkMetaData( 
    CATOmbPrivateLinkMetaData& iPrivateLinkMetaData, 
    CATOmbRelationMetaData& iRelationMetaData );

  CATOmbPrivateLinkMetaData _PrivateLinkMetaData;
  CATOmbRelationMetaData& _RelationMetaData;

  static CATOmbLinkMetaData* pDummyLinkMD;
};


#endif 
