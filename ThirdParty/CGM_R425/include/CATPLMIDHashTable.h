#ifndef CATPLMIDHashTable_H
#define CATPLMIDHashTable_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/* 
* @COPYRIGHT DASSAULT SYSTEMES 2004
* ----------------------------------------------------------------------------------------------------------------------
*   Origin              : Local running (inside wintop) of remote persistency entity 
*                            associative kernel change/data set of ... actors ...
*                            made as simple as possible to be affordable for enhanced infrastructure integration
*   Software's Category : Physical Layer (Middleware services) dedicated to client side
*                            (in a kind of software classification similar to the layered OSI Network 
*                             upper (logical) Layer is mainly about two main axis  (
*                                  Modeler (domain) specialisation (for Data and Attributes ...)
*                                  Upper Levering Operand Integration exchange (QEOPS, 
*   Premilinary         : Do not forget to contact your Database Administrators or any other representative
*                            (Authoring definition) for more convenient support 
*                          (Just to be sure that appropriate schema (Table for Data , or Services) are supported 
*                              when reference persistency occured when dealing with local work realized  )
*   Specification       : Simple genuine (re-usable) services about 
*                            - associativity between local insulated implementation and shared remote repository
*                            - synthetic change set (persistency intents)
*   Limitations         : No attributes vocabulary provided to let this current functional component software 
*                              be as comprehensible in specifications
*                         Status is slaved to Modelers deployement and Behaviors
*                             for more detailled specification (UML sequence diagram, statechart, ..)  
*                             consult specialized specifications database relative to upper Logical Software layer 
*                             it means Product Structure Legacy, PLM Client Core, Representation Model
*   Favorites entry-point for developpers :
*                         CATPLMRepositoryName : Repository classification 
*                         CATProxySpace   : Instance of a domain resolution                    
*                         CATComponentId  : Handle on primary associativity between local and remote entity           
* ------------------ ----------------------------------------------------------------------------------------------------
*//**
* @level Private
* @usage U1       
*/
/**
* Project PLM Integration
*   Simple Hash Table on PLMID 
*
* Technical criteria on egality on PLMID are
*   HRESULT IsEqual(const CATPLMID    & iSecondIdentifier, TRUE, const CATBoolean    iPhysical);
*   HRESULT ComputeHashKey(unsigned int &oKey) const;
*/
#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"

class CATPLMID;
class CATPLMIDHashTableVisitor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentificationAccess IID IID_CATPLMIDHashTable;
#else
extern "C" const IID IID_CATPLMIDHashTable ;
#endif


/**
* Main functionnalities are about :
*
*    Browse
*      SearchById
*      Size 
*      Next 
*
*    Editing
*      Insert
*      RemoveById
*      RemoveAll
*
* Complementary specification is about :
*    Autonomeous Table (no coupling with Session mechanism)
*    Implementation if kept inside with the AddRef() 
*    Returned value for object are given with an AddRef()
*
*/
class ExportedByCATPLMIdentificationAccess CATPLMIDHashTable : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Search if an identifier is already associated (by physical identifier)
  *
  * @param iIdentifier
  *   Value of identifier
  *
  * @param oValue
  *   Value of identifier found
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Search succeeded</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>No result Found</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failure</dd>
  *   </dl>
  */
  virtual HRESULT SearchById(const CATPLMID & iIdentifier, CATUINTPTR & oValue, CATPLMID * oIdentifier = NULL ) const = 0;

  /**
  * Determines the number of identifiers in the Table
  *
  * @param oNumberOfPLMIDs
  *   Number of identifiers
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Insertion done</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>No association found in Table</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failure</dd>
  *   </dl>
  */
  virtual HRESULT Size(unsigned int & oNumberOfPLMIDs) const = 0;

  /**
  * Enumerate identifiers and values in the Table
  *
  * @param ioHiddenKey
  *   Internal Identifier (input-Ouput) for enumeration
  *   Start with ZERO (0) as initial first value
  *
  * @param oIdentifier
  *   Value of identifier
  *
  * @param oValue
  *   Applicative Value
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Result found</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>No Result, End of Enumerate</dd>
  *   </dl>
  */
  virtual  HRESULT Next(unsigned int & ioHiddenKey, CATPLMID * oIdentifier, CATUINTPTR & oValue) const = 0;

  /**
  * Visit identifiers and values in the Table
  *
  * @param ioHiddenKey
  *   Internal Identifier (input-Ouput) for enumeration
  *   Start with ZERO (0) as initial first value
  *
  * @param oIdentifier
  *   Value of identifier
  *
  * @param oValue
  *   Applicative Value
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Result found</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>No Result, End of Enumerate</dd>
  *   </dl>
  */
  virtual  HRESULT Visit(CATPLMIDHashTableVisitor & iVisitor) const = 0;

  /**
  * Insert an identifier in the Table   
  *
  * @param iIdentifier
  *   Value of identifier
  *
  * @param iValue
  *   Applicative Value
  *
  * @param iKeepValueOnAlreadyInserted
  *   Keep Applicative Value on already inserted Id
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Insertion done</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failure</dd>
  *   </dl>
  */
  virtual  HRESULT Insert(const CATPLMID & iIdentifier, const CATUINTPTR iValue, const CATBoolean iKeepValueOnAlreadyInserted = FALSE) = 0;

  /**
  * Remove an identifier in the Table
  *
  * @param iIdentifier
  *   Value of identifier
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Remove done</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>No association found in Table</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failure</dd>
  *   </dl>
  */
  virtual  HRESULT RemoveById(const CATPLMID &iIdentifier ) = 0;

  /**
  * Remove all identifiers in the Table
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Insertion done</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>No association found in Table</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failure</dd>
  *   </dl>
  */
  virtual  HRESULT RemoveAll() = 0;

};

CATDeclareHandler( CATPLMIDHashTable, CATBaseUnknown );

/**
* @param oTable [CATBaseUnknown#Release]
*   Handle on value of AssociationTable 
*   Release() after usage the returned value of oTable, if it has succeeded.
*   Last Release() will lead to remove all
*
* @param iEstimatedPopulation
*   Estimated number of associations 
*
* @return
*      S_OK     request succeeded <br>
*      E_FAIL   if request failed for unknown reason<br>
*/
extern ExportedByCATPLMIdentificationAccess \
HRESULT CATPLMCreatePLMIDHashTable(CATPLMIDHashTable  ** oTable, 
                                   int  iEstimatedPopulation = 1024 );

#endif
