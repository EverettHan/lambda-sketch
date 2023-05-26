/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeDescriptor_H
#define CATPLMTypeDescriptor_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeToolsDefinitions.h"
#include "CATPLMTypeH.h"
#include "CATPLMCoreType.h"
class CATUnicodeString;
class CATString;
class CATOmxKeyString;

/**
 * Class enabling to determine semantical description of a PLM type.
 *
 * <br><b>Role</b>: Given a PLM type, this class enables to determine the physical aspect of the PLM type.
 * <ul>
 * <li>Available entry points:</li>
 * <li>public:GetTypeName</li>
 * <li>public:IsDSType</li>
 * <li>public:GetDSType</li>
 * <li>public:IsKindOf</li>
 * <li>public:IsExtension</li>
 * <li>public:GetModelerName</li>
 * </ul>
 * <ul>
 * <code>
 * CATPLMID myComponent;
 * CATPLMTypeDescriptor Descriptor(myComponent); // Implicit build of CATPLMTypeH.
 * HRESULT rc_ds=Descriptor.IsDSType();
 * if ( SUCCEEDED(rc_ds) )
 * {
 *   if ( rc_ds==S_OK )
 *     printf("The PLM type of my Component is defined by DS modeler");
 *   else
 *     printf("The PLM type of my Component is a Specialization or Custo type");
 * }
 *
 * or
 *
 * CATPLMID myComponent;
 * CATPLMTypeH TypeH(myComponent);
 * CATPLMTypeDescriptor Descriptor(TypeH); 
 * HRESULT rc_ds=Descriptor.IsDSType();
 * if ( SUCCEEDED(rc_ds) )
 * {
 *   if ( rc_ds==S_OK )
 *     printf("The PLM type of my Component is defined by DS modeler");
 *   else
 *     printf("The PLM type of my Component is a Specialization or Custo type");
 * }
 * </code>
 * </ul>
 *
 * NB: if you already have a CATPLMTypeH, using the static methods will always
 *     be faster than creating a CATPLMTypeDescriptor to call the same method.
 */
class ExportedByCATPLMIdentificationAccess CATPLMTypeDescriptor : public CATPLMTypeH
{
public:
  CATPLMTypeDescriptor( const CATPLMTypeH & iType );

  /**
  * If the same type name is used for different domains (BusinessType, RelationType, extension, etc…):
  * @use CATPLMFindTypeH::BuildFromName
  */
  CATPLMTypeDescriptor( const CATUnicodeString & iTypeName, const CATPLMRepositoryName & iRepository=CATPLMRepositoryName_Null ) : CATPLMTypeH(iTypeName, iRepository) {}
  CATPLMTypeDescriptor( const CATUnicodeString & iTypeName, const CATPLMID & iPLMIDForRepositoryContext ) : CATPLMTypeH(iTypeName, iPLMIDForRepositoryContext) {}
  CATPLMTypeDescriptor( const CATUnicodeString & iTypeName, const CATProxySpace & iRepositoryContext ) : CATPLMTypeH(iTypeName, iRepositoryContext) {}
  CATPLMTypeDescriptor( const CATOmxKeyString & iTypeName, const CATPLMRepositoryName & iRepository=CATPLMRepositoryName_Null ) : CATPLMTypeH(iTypeName, iRepository) {}
  CATPLMTypeDescriptor( const CATOmxKeyString & iTypeName, const CATPLMID & iRepositoryContext ) : CATPLMTypeH(iTypeName, iRepositoryContext) {}
  CATPLMTypeDescriptor( const CATOmxKeyString & iTypeName, const CATProxySpace & iRepositoryContext ) : CATPLMTypeH(iTypeName, iRepositoryContext) {}
  CATPLMTypeDescriptor( const char * iTypeName, const CATPLMRepositoryName & iRepository=CATPLMRepositoryName_Null ) : CATPLMTypeH(iTypeName, iRepository) {}
  CATPLMTypeDescriptor( const char * iTypeName, const CATPLMID & iRepositoryContext ) : CATPLMTypeH(iTypeName, iRepositoryContext) {}
  CATPLMTypeDescriptor( const char * iTypeName, const CATProxySpace & iRepositoryContext ) : CATPLMTypeH(iTypeName, iRepositoryContext) {}

  /**
  * Constructor
  */
  CATPLMTypeDescriptor( const CATPLMTypeId & iPLMType, const CATPLMRepositoryName & iRepository=CATPLMRepositoryName_Null ) : CATPLMTypeH(iPLMType, iRepository) {}
  CATPLMTypeDescriptor( const CATPLMTypeId & iPLMType, const CATPLMID & iPLMIDForRepositoryContext ) : CATPLMTypeH(iPLMType, iPLMIDForRepositoryContext) {}
  CATPLMTypeDescriptor( const CATPLMTypeId & iPLMType, const CATProxySpace & iRepositoryContext ) : CATPLMTypeH(iPLMType, iRepositoryContext) {}
  CATPLMTypeDescriptor( CATPLMType * iPLMType ) : CATPLMTypeH(iPLMType) {}
  CATPLMTypeDescriptor( CATIAdpType * iAdpType ) : CATPLMTypeH(iAdpType) {}
  CATPLMTypeDescriptor( CATIAdpExtType * iAdpExtType ) : CATPLMTypeH(iAdpExtType) {}
  CATPLMTypeDescriptor( CATIType * iType ) : CATPLMTypeH(iType) {}
  CATPLMTypeDescriptor( const CATPLMID & iComponent ) : CATPLMTypeH(iComponent) {}
  CATPLMTypeDescriptor( const CATComponentId & iComponent ) : CATPLMTypeH(iComponent) {}
  CATPLMTypeDescriptor( CATIAdpPLMIdentificator * iComponent ) : CATPLMTypeH(iComponent) {}
  CATPLMTypeDescriptor( CATIPLMComponent * iComponent ) : CATPLMTypeH(iComponent) {}

  // Non-virtualité du destructeur de CATPLMTypeH pour baisser en taille memoire. Les classes derivees ne doivent dons pas avoir de donnees membre pour eviter les fuites potentielles.
  inline ~CATPLMTypeDescriptor() {}

  CATPLMTypeDescriptor( const CATPLMTypeDescriptor & iSource ) : CATPLMTypeH(iSource) {}
  CATPLMTypeDescriptor & operator =( const CATPLMTypeDescriptor & iSource ) { this->CATPLMTypeH::operator =(iSource); return *this; }

/**
 * Retrieve the Name of the PLM Type.
 * <br><b>Role:</b>This method enables to determine the Type Name as declared in the PLM metadata.
 *
 * @param oTypeName [out]
 * The TypeName as defined in the metadata.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the name of the Type was found.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  HRESULT GetTypeName( CATUnicodeString & oTypeName ) const;
  static HRESULT GetTypeName( const CATPLMTypeH & iTypeH, CATUnicodeString & oTypeName );

  /**
   * Same as previous using CATOmxKeyString for better perfomances.
   */
  HRESULT GetTypeName( CATOmxKeyString & oTypeName )const;
  static HRESULT GetTypeName( const CATPLMTypeH & iTypeH, CATOmxKeyString & oTypeName );

/**
 * Checks if the Component/PLM type is defined in the internal DS metadata.
 * <br><b>Role:</b>This method enables to determine if a has be defined by a Customer in his own metadata or in the proper DS metadata.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the PLM type is a DS type.</li> 
 * <li><tt>S_FALSE</tt> if the PLM type is a Customer PLM type.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  HRESULT IsDSType() const;
  static HRESULT IsDSType( const CATPLMTypeH & iTypeH );

/**
 * Gets a DS Modeler PLM type from the given PLM type.
 * <br><b>Role:</b>This method enables to give the DS modeler type corresponding to the given type qualifier.
 *
 * @param iDSModelerQualifier [in]
 * The DS modeler level the user wants the type.
 * <ul>
 * <li>Use CATPLMTypeDescriptorDefs::mqFirst if you want to retrieve the first DS type.</li>
 * <li>Use CATPLMTypeDescriptorDefs::mqTop if you want to retrieve the first Top Modeler DS type.</li>
 * </ul>
 * @param oPLMType [out]
 * The PLM type.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the PLM type could be retrieved.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * <li><tt>E_INVALIDARG</tt> if the qualifier is invalid.</li>
 * </ul>
 */
  HRESULT GetDSType( CATPLMTypeDescriptorDefs::DSModelerQualifier iDSModelerQualifier, CATPLMTypeH & oPLMType ) const;
  static HRESULT GetDSType( const CATPLMTypeH & iTypeH, CATPLMTypeDescriptorDefs::DSModelerQualifier iDSModelerQualifier, CATPLMTypeH & oPLMType );


/**
 * Checks if the type of the Component belongs to the family of the given PLM type.
 * <br><b>Role:</b>This method enables to determine if a PLM type can be seen as the given PLM type.
 * @example
 * <pre>
 * CATPLMTypeDescriptor TypeDescriptor(<my_component>);
 * if ( TypeDescriptor.IsKindOf(PLMType_CoreReference)==S_OK )
 * {
 *   ... I do my job here
 * }
 * </pre>
 *
 * @param iPLMType [in]
 * The PLM type to be compared with.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the Component can be seen has a Component of the given <code>iPLMType</code> type.</li> 
 * <li><tt>S_FALSE</tt> if the Component is not a kind of <code>iPLMType</code>.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type to compare with is invalid.</li>
 * </ul>
 */
  HRESULT IsKindOf( const CATPLMTypeH & iPLMType ) const;
  static HRESULT IsKindOf( const CATPLMTypeH & iTypeHToCompate, const CATPLMTypeH & iRefTypeH );

/**
 * Checks if the Component/PLM type is an Extension type.
 * <br><b>Role:</b>This method enables to determine if the given PLM type is an Extension PLM type.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the PLM type is an Extension PLM type.</li> 
 * <li><tt>S_FALSE</tt> if the PLM type is not an Extension PLM type.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  HRESULT IsExtension() const;
  static HRESULT IsExtension( const CATPLMTypeH & iTypeH );

/**
 * Checks if the Component/PLM type is an abstract type.
 * <br><b>Role:</b>This method enables to determine if the given PLM type is an abstract PLM type.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the PLM type is an abstract PLM type.</li> 
 * <li><tt>S_FALSE</tt> if the PLM type is not an abstract PLM type.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  HRESULT IsAbstract() const;
  static HRESULT IsAbstract( const CATPLMTypeH & iTypeH );

/**
 * Retrieve the name of the Modeler which defines the given PLM Type.
 * <br><b>Role:</b>This method enables to determine the name of the Modeler whose metadata contains the definition of the given PLM type.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the Modeler name was found.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  HRESULT GetModelerName( CATUnicodeString & oModelerName ) const;
  static HRESULT GetModelerName( const CATPLMTypeH & iTypeH, CATUnicodeString & oModelerName );

/**
 * Determine if the given PLM type is a IRPC type.
 * <br><b>Role:</b>This method enables to determine if the PLM type is an IRPC type.
 *
 * @param oCoreType [out]
 * The IRPC core type of the PLM type.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if the PLM type is defined in the IRPC PLM Model.</li> 
 * <li><tt>S_FALSE</tt> if the PLM type is not defined in the IRPC PLM Model.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_INVALIDARG</tt> if the given PLM Type is invalid.</li>
 * </ul>
 */
  HRESULT IsIRPCType( CATPLMCoreType & oCoreType ) const;
  static HRESULT IsIRPCType( const CATPLMTypeH & iTypeH, CATPLMCoreType & oCoreType );
};
#endif
