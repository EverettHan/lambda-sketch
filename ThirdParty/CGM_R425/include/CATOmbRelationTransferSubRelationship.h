#ifndef CATOmbRelationTransferSubRelationship_H
#define CATOmbRelationTransferSubRelationship_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U3
 */
#include "CATOmbRelationTransfer.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATPLMID;
class CATOmbRelationTransferSubRelationshipImpl;
class CATOmxAny;

/**
 * Class that defines a listener to raise PLMIntegrity violation.
 */
class  ExportedByCATOmbRelationTransfer CATOmbRelationTransferSubRelationship
{
public:

  /**
  * constructor
  * 
  * @param iSRDictionaryName
  *        Name of the sub relationalship
  * @param iPosition
  *        Position in the list. Zero if no list.
  */
  CATOmbRelationTransferSubRelationship(const CATUnicodeString & iSRDictionaryName, unsigned int iPosition = 0);
  ~CATOmbRelationTransferSubRelationship();

  /**
  * Populate Path content one by one (starting from begining to the end)
  * 
  * @param iPointedSimplePLMID
  *        PLM Identifier of the simple pointed component.
  * @param iPointedSynchroStamp
  *        Synchro stamp of the simple pointed component.
  *        This information is mandatory for not neutral relations.
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : if failure
  */
  HRESULT Append(CATPLMID & iPointedSimplePLMID, const CATOmxAny & iPointedSynchroStamp);

  /**
  * Gets dictionary SR name
  * @return
  *        The dictionary SR name
  */
  const CATUnicodeString & GetDictionaryName() const;

  /**
  * Gets position
  * @return
  *        0 if no position declared
  */
  unsigned int GetPosition() const;

  /**
  * Returns FALSE if assistant is valuated 
  */
  CATBoolean operator!() const;

  /** 
  * Empty Constructor
  * */
  CATOmbRelationTransferSubRelationship();

  /**
  * Constructor by Copy (Handler)
  */
  CATOmbRelationTransferSubRelationship(const CATOmbRelationTransferSubRelationship &iCopy);

  /**
  * Assigning  Handler value by copy
  */
  CATOmbRelationTransferSubRelationship& operator=(const CATOmbRelationTransferSubRelationship &iCopy);

private:

  friend class CATOmbRelationTransferSubRelationshipImpl;
  inline CATOmbRelationTransferSubRelationshipImpl * GetUsage() const {return _ImplUsage;};  
  void SetUsage(CATOmbRelationTransferSubRelationshipImpl * iAssistant); 
  CATOmbRelationTransferSubRelationshipImpl * _ImplUsage; 

  /* forbidden operations */
  int operator==(const CATOmbRelationTransferSubRelationship & iOtherComponent) const;
  int operator!=(const CATOmbRelationTransferSubRelationship & iCopy) const;
} ;

#endif

