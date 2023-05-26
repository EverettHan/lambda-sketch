#ifndef CATIComponentIdSimpleHashTable_H
#define CATIComponentIdSimpleHashTable_H
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
*/
/**
 * @level Private
 * @usage U1       
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"

class CATComponentId;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATIComponentIdSimpleHashTable;
#else
extern "C" const IID IID_CATIComponentIdSimpleHashTable ;
#endif


 /**
 * Strategy of insertion.
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATComponentIdComplexId_KeepSame</tt>              <dd>Keep as it it.
 * @param <tt>CATComponentIdComplexId_SplitIntoElementary</tt>   <dd>Insert As elementary Path.
 * </dl>
 */
enum CATComponentIdComplexId_Strategy 
{
  CATComponentIdComplexId_KeepSame,
  CATComponentIdComplexId_SplitIntoElementary 
};

/**
* Managing set of simple and complex component ids.
*/
class ExportedByCATPLMTos CATIComponentIdSimpleHashTable : public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Search if an Handle is already associated (by physical Handle)
  *
  * @param iHandle
  *   Value of Handle
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
  virtual  HRESULT FindHandle(const CATComponentId & iHandle) const = 0;

  /**
  * Determines the number of Handles in the Table
  *
  * @param oNumberOfHandles
  *   Number of Handles
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Succeeded</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failure</dd>
  *   </dl>
  */
  virtual  HRESULT NumberOfHandles(unsigned int & oNumberOfHandles) const = 0;

  /**
  * Enumerate Handles in the Table
  *
  * @param ioHiddenKey
  *   Internal Handle (input-Ouput) for enumeration
  *   Start with ZERO (0) as initial first value
  *
  * @param oHandle
  *   Value of Handle
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
  virtual  HRESULT NextHandle(unsigned int   & ioHiddenKey, CATComponentId & oHandle ) const = 0;

  /** 
  *     E D I T I N G
  *
  */

  /**
  * Insert an Handle in the Table   
  *
  * @param iHandle
  *   Value of Handle
  *
  * @param iValue
  *   Applicative Value
  *
  * @param iKeepValueOnAlreadyInserted
  *   Keep value on already inserted
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Insertion done</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>Already Inserted</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failure</dd>
  *   </dl>
  */
  virtual  HRESULT InsertHandle(const CATComponentId & iHandle  ) = 0;

  /**
  * Remove an Handle in the Table
  *
  * @param iHandle
  *   Value of Handle
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
  virtual  HRESULT RemoveHandle(const CATComponentId &iHandle ) = 0;

  /**
  * Remove all Handles in the Table
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>RemoveAll done</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failure</dd>
  *   </dl>
  */
  virtual  HRESULT RemoveAllHandles() = 0;
    
};

CATDeclareHandler( CATIComponentIdSimpleHashTable, CATBaseUnknown );

/**
* @param oTable
*   Handle on value of AssociationTable 
*   Release() after usage the returned value of oTable, if it has succeeded.
*   Last Release() will lead to remove all
*
* @param iStrategy
*    strategy
*
* @param iEstimatedPopulation
*   Estimated number of associations 
*
* @return
*      S_OK     request succeeded <br>
*      E_FAIL   if request failed for unknown reason<br>
*/
extern ExportedByCATPLMTos \
HRESULT CATPLMCreateComponentIdHashTable(CATIComponentIdSimpleHashTable  ** oTable, 
                                         CATComponentIdComplexId_Strategy strategy = CATComponentIdComplexId_KeepSame,
                                         int  iEstimatedPopulation = 1024 );

#endif
