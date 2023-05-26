/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2017
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATPLMAutoNamingInput_H
#define CATPLMAutoNamingInput_H

#include "CATBaseUnknown.h"
#include "CATPLMServicesItf.h"

class CATPLMAutoNamingInput;
class CATPLMAutoNamingOutput;

// List management
#include "CATLISTP_Clean.h"
#define CATLISTP_Append
#include "CATLISTP_Declare.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMServicesItf
CATLISTP_DECLARE( CATPLMAutoNamingInput )

#include "CATUnicodeString.h"
#include "CATOmxKeyString.h"
class CATIAdpType;

/**
* Class to use as input of CATPLMProtectedAutoNamingServices.
*/
class ExportedByCATPLMServicesItf CATPLMAutoNamingInput : public CATBaseUnknown
{
  friend class CATPLMAutoNamingOutput;
  friend class CATPLMCompAutoNamingService;
  friend class CATPLMAutoNamingCache;
  friend class CATPLMAutoNamingLocalGenerator;
  friend class ContextTSTCATPLMCompAutoNamingService;
  friend class ContextTSTCATPLMAutoNamingCache;

public:
  /** 
  * Builds an input.
  *
  * @param iType [in]
  *    The type of the input.
  * @param iDiscipline [in]
  *    The discipline of the input.
  * @param iUsage [in]
  *    The usage of the input.
  * @param iUserString [in]
  *    A user string to be used if needed by providers.
  */
  CATPLMAutoNamingInput(const CATIAdpType *iType, const CATUnicodeString &iDiscipline, const CATUnicodeString &iUsage, const CATUnicodeString &iUserString);
  CATPLMAutoNamingInput(const CATPLMAutoNamingInput &);
  CATPLMAutoNamingInput& operator=( const CATPLMAutoNamingInput&);

  virtual ~CATPLMAutoNamingInput();

  /** 
  * Returns the input informations.
  *
  * @param oType [out,CATBaseUnknown]
  *    The type of the input.
  * @param oDiscipline [out]
  *    The discipline of the input.
  * @param oUsage [out]
  *    The usage of the input.
  * @param oUserString [out]
  *    A user string to be used if needed by providers.
  */
  virtual HRESULT GetInfo (CATIAdpType **oType, CATUnicodeString &oDiscipline, CATUnicodeString &oUsage, CATUnicodeString &oUserString);

  virtual int operator != (const CATPLMAutoNamingInput &iInput) const; 

  /** 
  * Sets the number of input to generate if using ReserveNames.
  * if the function is called at least one time the attribute _NbReservedSetted is setted to 'true'.
  *
  * @param iNb [in]
  *    The number of element to generate for this input.
  */
  virtual void SetReservationNumber (unsigned int iNb);
  virtual unsigned int GetReservationNumber();

  /**
  * Returns the physical repository id (the server's id).
  *
  * @return
  *   _PhysicalRepositoryId
  */
  CATUnicodeString GetPhysicalRepositoryId();

  /**
  * Sets the physical repository id (the server id) used to compute key.
  * This is very useful to split entries from different servers.
  * It can be used to compute the input key (disabled by default) to split names per servers.
  * It's mostly used for the filesystem cache CATPLMAutoNamingCache.
  * Example:
  *   Let's say there are two servers: R420A and R420B.
  *   The unique names will be stored and retrieved with the following keys: 
  *     R420A_ID/[input_key]
  *     R420B_ID/[input_key]
  *   Then, the unique names from R420A will not be used if you are connected
  *   to R420B and vise-versa.
  *
  * @param iPhysicalRepositoryId [in]
  *   The physical repository id.
  */
  void SetPhysicalRepositoryId(CATUnicodeString iPhysicalRepositoryId);

  /*
  * Returns the tenant id (the server's tenant id).
  *
  * @return
  *   _TenantId
  */
  CATUnicodeString GetTenantId();

  /*
  * Sets the tenant id (used by cloud setups) used to compute key.
  * Same as PhysicalRepositoryId, the TenantId will be used so split autonames entries from different cloud Tenants.
  * It's mostly used for the filesystem cache CATPLMAutoNamingCache.
  */
  void SetTenantId(CATUnicodeString iTenantId);

  /**
  * Compares current input to the other input.
  * CompreTo ignores PhysicalRepositoryId.
  *
  * @param ipOther [in]
  *   The other input.
  *
  * @return 
  *   -1    this < ipOther
  *    0    this == ipOther
  *    1    this > ipOther
  */
  int CompareTo(const CATPLMAutoNamingInput* ipOther) const;

  /**
  * Returns the hash code of the input.
  * Hash ignores PhysicalRepositoryId.
  *
  * @return
  *   unsigned int: the computed hash code.
  */
  CATHashKey Hash() const;

private:
  /**
  * Return the input's key.
  * The PhysicalRepositoryId is optional and is not used by default.
  * It is recommanded to enable it to avoid collision between names from different servers.
  * It's mostly used for the CATPLMAutoNamingCache.
  *
  * @return
  *   (PhysicalRepositoryId/)TypeId/DomainId:Discipline:Usage
  */
  CATUnicodeString ComputeKey(CATBoolean iUsePhysicalRepositoryId = FALSE) const;

  /**
  * Return the hash key, based on the return of ComputeKey
  */
  unsigned ComputeHashKey(CATBoolean iUsePhysicalRepositoryId = FALSE) const;

  /**
  * Attributes
  */
  // Server's identifiers
  CATUnicodeString _PhysicalRepositoryId; // The server id where the names come from
  CATUnicodeString _TenantId; // The tenant id (cloud specific) where the names come from

  // Type's identifications
  CATIAdpType  *_pType; // Replace by TypeId / DomainId
  CATOmxKeyString _TypeId;
  CATOmxKeyString _TypeDomainId;

  // Other informations
  CATUnicodeString _Discipline;
  CATUnicodeString _Usage;
  CATUnicodeString _UserString;

  // Number of autoname to reserve
  // For CATPLMCompAutoNamingService::ReserveNames: allowed values: 1 to n
  // For CATPLMCompAutoNamingService::GenerateName and CATPLMCompAutoNamingService::GenerateNames: allowed value: ONLY 1
  int _NbReserve;
};

#endif
