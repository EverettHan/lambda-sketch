#ifndef CATIPLMIDAssociationSet_H
#define CATIPLMIDAssociationSet_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U3
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
* As so far CATPLMID class is dedicated for identifier of Repository on simple object
*
*/
#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"
#include "CATPLMID.h"
#include "CATDataType.h"
#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentificationAccess IID IID_CATIPLMIDAssociationSet;
#else
extern "C" const IID IID_CATIPLMIDAssociationSet ;
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
class ExportedByCATPLMIdentificationAccess CATIPLMIDAssociationSet : public CATBaseUnknown
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
     virtual  HRESULT SearchById(const CATPLMID &iKey,
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
                                      CATPLMID *oKey,
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
  virtual  HRESULT Associate(const CATPLMID & iKey,
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
  virtual  HRESULT RemoveById(const CATPLMID &iKey ) = 0;

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
                           CATPLMID *oKey,
                           CATBaseUnknown ** oCBU,
                           CATULONGPTR    * oApplicativeValue = NULL ) const = 0;

    
};


/**
* @param oTable
*   Handle on value of AssociationSet 
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
extern ExportedByCATPLMIdentificationAccess HRESULT CATPLMCreatePLMIDAssociationSet(CATIPLMIDAssociationSet  ** oTable, 
                                                                     int  iEstimatedPopulation = 1024,
                                                                     const CATBoolean  iWithApplicativeValue = FALSE);

#endif
