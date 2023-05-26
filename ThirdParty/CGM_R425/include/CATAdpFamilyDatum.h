/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
#ifndef CATAdpFamilyDatum_H
#define CATAdpFamilyDatum_H

/**
 * @level Protected
 * @usage U1  
 */

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATAdpStdAttributeSet.h"
class CATIAdpPLMIdentificator;

/**
 * Class defining a set of data mandatory to perform a family operation.
 *
 * <br><b>Role</b>: provide a set of data used to perform a family operation.
 */
class ExportedByCATPLMIntegrationAccess CATAdpFamilyDatum
{
public:

/** 
 * Build a family datum.
 *
 * <br><b>Role</b>: Enables to build a family datum which can be used for family operations through
 * the @href CATAdpProtectedFamilyServices API.
 *
 * @param iGenericComponent [in]
 *   The generic component being the ancestor of the family. 
 * <ul>
 * <li>The identifier must not be nul. Otherwise, <code>E_INVALIDARG</code> is returned.</li> 
 * </ul>
 * @param iSolvedComponent [in]
 *   The identifier of the component related to the ancestor, which is solved in accordance to specific rules.
 * @param iAttributes [in]
 *   Some attributes related to the solved component.
 *
 */
  CATAdpFamilyDatum( CATIAdpPLMIdentificator * iGenericComponent, CATIAdpPLMIdentificator * iSolvedComponent, 
                     const CATAdpStdAttributeSet & iAttributes );
  virtual ~CATAdpFamilyDatum( void );
  CATAdpFamilyDatum( const CATAdpFamilyDatum & );
  CATAdpFamilyDatum & operator=( const CATAdpFamilyDatum & );
  int operator ==( const CATAdpFamilyDatum & other ) const;
  int operator !=( const CATAdpFamilyDatum & other ) const;

/** 
 * Gets the generic component identifier.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpPLMIdentificator enabling to identify the ancestor of the family.
 *
 * @param oGenericComponent [out]
 *   The generic component identifier.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the related identifier could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  HRESULT GetGenericComponent( CATIAdpPLMIdentificator *& oGenericComponent ) const;

/** 
 * Gets the solved component identifier.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpPLMIdentificator enabling to identify on of the solved components of the family.
 *
 * @param oSolvedComponent [out]
 *   The solved component identifier.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the related identifier could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  HRESULT GetSolvedComponent( CATIAdpPLMIdentificator *& oSolvedComponent ) const;

/** 
 * Gets some attributes of the solved component.
 *
 * <br><b>Role</b>: Gets the @href CATAdpStdAttributeSet related to the solved component.
 *
 * @param oAttributes [out]
 *   The attributes.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the date could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  HRESULT GetAttributes( CATAdpStdAttributeSet & oAttributes ) const;

private:
  CATIAdpPLMIdentificator * _GenericComponent;
  CATIAdpPLMIdentificator * _SolvedComponent;
  CATAdpStdAttributeSet _Attributes;
};



// CATLISTV(CATAdpFamilyDatum) definition

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Required functions
/** @nodoc INTERNAL */
#define CATLISTV_Append
#define CATLISTV_Size
#define CATLISTV_RemoveAll

// Get macros
// Generate interface of collection-class
#include "CATLISTV_Declare.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIntegrationAccess
CATLISTV_DECLARE(CATAdpFamilyDatum);

// Typedef declaration for users easy identification.
typedef CATLISTV(CATAdpFamilyDatum) CATAdpFamilyData;

#endif
