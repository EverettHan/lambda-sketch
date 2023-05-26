#ifndef CATAdpOperationDatum_H
#define CATAdpOperationDatum_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
class CATAdpPrivateOperationDatum;
class CATPLMID;
class CATUnicodeString;

/**
* Class to represent a modification in a history
**/
class ExportedByCATPLMIntegrationAccess CATAdpOperationDatum
{
public:
  enum OperationType { OT_UNDEFINED=0, OT_CREATE=1, OT_UPDATE=2, OT_DELETE=3, OT_CHANGESTATUS=4, OT_LOCK=5, OT_UNLOCK=6, 
                       OT_CHANGEAUTHORITYCONTROL=7, OT_TRANSFEROWNERSHIP=8, OT_NEWVERSION=9, OT_CLONE=10, OT_MODIFCORRECTION=11,
                       OT_NEWMINORVERSION=12 };

  CATAdpOperationDatum();

  CATAdpOperationDatum( const CATAdpOperationDatum & );
  CATAdpOperationDatum & operator=( const CATAdpOperationDatum & );
  int operator==(const CATAdpOperationDatum & iOther) const;
  int operator!=(const CATAdpOperationDatum & iOther) const;

  virtual ~CATAdpOperationDatum ();
   
  /**
   * Get the component the modification deals with.
   * @param oComponent [out]
   *   The component the operation deals with.
   *
   * @return
   * <dl>
   *   <li><code>S_OK</code> if everything ran ok.</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation.</li>
   * </dl>  
   */
  HRESULT GetComponent( CATPLMID & oComponent ) const;

  /**
   * Get the type of modification which was performed on the component.
   * @param oOperationType [out]
   *   The operation type.
   *
   * @return
   * <dl>
   *   <li><code>S_OK</code> if everything ran ok.</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation.</li>
   * </dl>  
   */
  HRESULT GetOperationType( OperationType & oOperationType ) const;

  /**
   * Get the owner of the component the modification deals with.
   * @param oOwner [out]
   *   The owner of the component if applicable.
   *
   * @return
   * <dl>
   *   <li><code>S_OK</code> if the owner of the component is available.</li>
   *   <li><code>S_FALSE</code> if no owner is available for the component (case for @href PLMCoreReference or @href PLMCoreRepReference).</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation.</li>
   * </dl>  
   */
  HRESULT GetOwner( CATPLMID & oOwner ) const;

  /**
   * Get the reference of the component the modification deals with.
   * @param oReference [out]
   *   The owner of the component if applicable.
   *
   * @return
   * <dl>
   *   <li><code>S_OK</code> if the owner of the component is available.</li>
   *   <li><code>S_FALSE</code> if no owner is available for the component (case for @href PLMCoreReference, 
@href PLMCoreRepReference, @href PLMPort or @href PLMConnection).</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation.</li>
   * </dl>  
   */
  HRESULT GetReference( CATPLMID & oReference ) const;

  HRESULT GetSnapshot( CATPLMID & oSnapshot ) const;

  // CCM specific
  HRESULT GetDerivedFrom( CATPLMID & oDerivedFrom ) const;
  HRESULT GetEventID( CATUnicodeString & oEventID ) const;
  HRESULT GetUserFactID( CATUnicodeString & oUserFactID ) const;
  HRESULT GetUserFactName( CATUnicodeString & oUserFactName ) const;
  HRESULT GetUserData( CATUnicodeString & oUserData ) const;

private :
  friend class CATAdpTransactionHistory;
  friend class CATAdpOperationDatumAccess;
  friend class CATAdpCorrectionOperationAccess;
  CATAdpOperationDatum( CATAdpPrivateOperationDatum * iLetter );

private :
  CATAdpPrivateOperationDatum * _letter;

};

#endif
