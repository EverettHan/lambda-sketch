#ifndef CATIPLMIDAssociationTable_H
#define CATIPLMIDAssociationTable_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Private
 * @usage U3
 * @see #CATPLMRepositoryName #CATProxySpace #CATComponentId
 * @deprecated V5R17
 */
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

/**
* Project PLM Integration
*
* Usage  : Simple associative Table (for short transaction usage)
*          to manage associations between Identifier and Object on vocabulary of PLM Integration
*
* Suitable for Quick access (CPU performance), memory consumption may be problematic
*    as two internal Hash Tables are internally managed to provide these fast answers
*
* As so far CATPLMIdentifier class is dedicated for identifier of Repository on simple object
* that is not yet adressed by ID here is : not saved entity (dummy ID) and complex ID of reference (path of ID) 
*
* One Sample is given in ODT with one million Objects and ID
*   CATPLMIdentification.tst\CATIPLMIDAssociationTable.m
*
*    Create Objects        (  0.93 s      +  95 Meg ) CreateCartesianPoint
*    Create IDS            ( 20 s         + 207 Meg ) AutoGenerateDummy
*
*    Associate             (  1.4  s      +  33 Meg )    // OLD PLMID  (  3    s      + 213 Meg )
*    Next                  (  0.4  s                )    // OLD PLMID  (  4    s                )
* 
*    SearchById            (  0.6  s                )    // OLD PLMID  (  0.75 s                )  
*    SearchByAddress       (  0.5  s                )    // OLD PLMID  (  4    s                ) 
*
*    RemoveBy              (  2    s      -  33 Meg )    // OLD PLMID  (  4    s      - 213 Meg )  
*
*
* ==>  Memory ressources  ->   ~ 200 octets / (objects,ID)   ~= taille 
* ==>  CPU    ressources  ->   ~ 1 MHz 
*/
#include "ExportedByCATPLMIdentification.h"
#include "CATBoolean.h"
#include "CATPLMIdentifier.h"
#include "CATDataType.h"
#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentification IID IID_CATIPLMIDAssociationTable;
#else
extern "C" const IID IID_CATIPLMIDAssociationTable ;
#endif

class CATPLMID;

/**
* Interface to manage { ( Id, Object ) }; checking unicity 
*   1) At most one key    for a given object
*   2) At most one object for a given key
* 
* Hidden implementation is about a two tables  :
*    (hash by address    AND     hash by physical identifier)
*
* Main functionnalities are about :
*
*    Edition
*       Associate( iIdentifier, iCBU )
*       RemoveById( iIdentifier )
*       RemoveByCBU( iCBU )
*       RemoveAll()
*
*    Browse
*      SearchById( iIdentifier, oExist, oCBU )
*      SearchByAddress( iCBU, oIdentifier )
*      Next( iCBU, oIdentifier )
*
*    Statistics
*       Size()
*
* Complementary specification is about :
*    Autonomeous Table (no coupling with Session mechanism)
*    Implementation if kept inside with the AddRef() 
*    Returned value for object are given with an AddRef()
*
*/
class ExportedByCATPLMIdentification CATIPLMIDAssociationTable : public CATBaseUnknown
{
  CATDeclareInterface;

  public:

     
     /**
     * Search if a key is already associated in the SimpleTos
     *
     * @param iKey
     *   Value of identifier
     *
     * @param oCBU
     *   Address of object found
     *   Release() after usage the returned value of oCBU, if it has succeeded.
     *
     * @param oApplicativeValue
     *   RFU
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
     virtual  HRESULT SearchById(const CATPLMIdentifier &iKey,
                                 CATBaseUnknown ** oCBU,
                                 CATULONGPTR    * oApplicativeValue = NULL ) const = 0;
     
   
     /**
     * Search if a key is already associated in the SimpleTos
     *
	 * @param iCBU
     *   Address of object found
     *
     * @param oKey
     *   Value of identifier
     *
     * @param oApplicativeValue
     *   RFU
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
     virtual  HRESULT SearchByAddress(CATBaseUnknown * iCBU,
                                      CATPLMIdentifier *oKey,
                                      CATULONGPTR    * oApplicativeValue = NULL) const = 0;


  /** 
  *     E D I T I N G
  *
  */


  /**
  * Generate an association between an identifier and a given object   
  * Request failed if Identifier or Object is already managed in the Table   
  *
  * @param iKey
  *   Value of identifier
  *
  * @param iCBU
  *   Address of object 
  *
  * @param iApplicativeValue
  *   RFU
  *
  * @param iKeepValueOnAlreadyInserted
  *   Keep value on already inserted
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
  virtual  HRESULT Associate(const CATPLMIdentifier & iKey,
                             CATBaseUnknown         * iCBU,
                             const CATULONGPTR        iApplicativeValue = 0,
                             const CATBoolean iKeepValueOnAlreadyInserted = FALSE) = 0;


  /**
  * Remove an association in the Table
  *
  * @param iKey
  *   Value of identifier
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
  virtual  HRESULT RemoveById(const CATPLMIdentifier &iKey ) = 0;

  /**
  * Remove an association in the Table
  *
  * @param iCBU
  *   Value of Object
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
  virtual  HRESULT RemoveByCBU(CATBaseUnknown * iCBU) = 0;


  /**
  * Remove all associations in the Table
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

   /**
    * Determines the number of associations in the Table
    *
    * @param oNumberOfAssociations
    *   Number of Associations
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

   virtual  HRESULT Size(unsigned int & oNumberOfAssociations) const = 0;


    /**
     * Determines the number of associations in the Table
     *
     * @param ioHiddenKey
     *   Internal Key (input-Ouput) for enumeration
     *   Start with ZERO (0) as initial first value
     *
     * @param oKey
     *   Value of identifier
     *
     * @param oCBU
     *   Address of object found
     *   Release() after usage the returned value of oCBU, if it has succeeded.
     *
     * @param oApplicativeValue
     *   RFU
     *
     * @return
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *     <dd>Result found</dd>
     *     <dt>S_FALSE</dt>
     *     <dd>No Result</dd>
     *     <dt>E_FAIL</dt>
     *     <dd>Failure</dd>
     *   </dl>
     */
     virtual  HRESULT Next(unsigned int & ioHiddenKey,
                           CATPLMIdentifier *oKey,
                           CATBaseUnknown ** oCBU,
                           CATULONGPTR    * oApplicativeValue = NULL ) const = 0;

    
};


/**
* @param oTable
*   Handle on value of AssociationTable 
*   Release() after usage the returned value of oSimpleTos, if it has succeeded.
*   Last Release() will lead to 
*
* @param iEstimatedPopulation
*   Estimated number of associations 
*
* @param iWithApplicativeValue
*   With ApplicativeValue
*
* @return
*      S_OK     request succeeded <br>
*      E_FAIL   if request failed for unknown reason<br>
*/
extern ExportedByCATPLMIdentification HRESULT CATPLMCreatePLMIDAssociationTable(CATIPLMIDAssociationTable  ** oTable, 
                                                                     int  iEstimatedPopulation = 1024,
                                                                     const CATBoolean  iWithApplicativeValue = FALSE);

#endif