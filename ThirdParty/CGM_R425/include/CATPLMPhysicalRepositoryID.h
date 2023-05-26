#ifndef _CATPLMPhysicalRepositoryID_h_
#define _CATPLMPhysicalRepositoryID_h_
/**
* @level Private
* @usage U2
*/
//
/*
===============================================================================
===============================================================================
*/
#include "CATPLMIntegrationInterfaces.h"
#include "CATDbBinary.h"

/**
  * Class associated with the Replication Engine.
  * <br><b>Role</b>: it is used to represent a Repository Identifier during different Replication application.
*/
class ExportedByCATPLMIntegrationInterfaces CATPLMPhysicalRepositoryID
{
public:
  CATPLMPhysicalRepositoryID(const CATDbBinary & iBinary);

  /**
  * Default constructor.
  */
  CATPLMPhysicalRepositoryID();

  CATPLMPhysicalRepositoryID& operator=(const CATPLMPhysicalRepositoryID &);

  /**
  * Destructor
  */
  ~CATPLMPhysicalRepositoryID();

  /**
  * Getter of the physical Identifier.
  */
  CATDbBinary GetBinary();
  
  /**
  * Const Getter of the physical Identifier.
  */
  CATDbBinary GetBinary() const ;


private:
  CATDbBinary _binary;

};

#endif
