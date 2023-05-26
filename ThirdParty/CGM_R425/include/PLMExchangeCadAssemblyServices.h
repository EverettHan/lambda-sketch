//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef PLMExchangeCadAssemblyServices_H
#define PLMExchangeCadAssemblyServices_H
// COPYRIGHT DASSAULT SYSTEMES 2014
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience 
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class that enables to define navigate xCAD assembly structure (Designer Central data).
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  November 2014  (JLM) Code required by Import command of SW data stored in DEC.
//
// ****************************************************************

// --- Header that need to be referenced

// -- PLMExchangeServices
#include "PLMExchangeGlobalServices.h"                // PLMExchangeGlobalServices.m

// -- SpecialAPI
#include "CATSysErrorDef.h"

// -- System
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"

//-- CATPLMServices
#include "CATPLMType.h"
#include "CATPLMID.h"
#include "CATPLMTypeId.h"
#include "CATPLMQueryFilterEnum.h"
#include "CATListPtrCATPLMType.h" 

// -- CATVirtualVaultSystem
#include "CATVVSUrl.h"
#include "CATListOfCATVVSUrl.h"

// -- Forward declaration
class CATIPLMQueryFilter   ;
class CATIPLMCompStatement ;

/**
  * Class Providing services to manage access to Designer Central objects.
  */
//-----------------------------------------------------------------------

class ExportedByPLMExchangeGlobalServices PLMExchangeCadAssemblyServices
{
   public:

    /** 
      * Object type filters:
      * 
      * @param COMPONENT_FAMILY
      *   Component Family.
      * @param ASSEMBLY_FAMILY
      *   Assembly Family.
      * @param COMPONENT_INSTANCE
      *   Component Instance.
      * @param ASSEMBLY_INSTANCE
      *   Assembly Instance.
      */
      enum PLMExchangeCadTypes
      {
        COMPONENT_FAMILY     = 0x00000001
      , ASSEMBLY_FAMILY      = 0x00000002
      , COMPONENT_INSTANCE   = 0x00000004
      , ASSEMBLY_INSTANCE    = 0x00000008
      } ;

    /** 
      * Get list of assembly components and MCAD documents.
      *
      * @param iInputList [in]
      *   The list of Root to be navigated.
      *
      * @param olstPlmId [out]
      *   List of objects inExpandThe list of Subtypes.
      *
      * @param inOutputFilter [in]
      *   Define set of object types expected (mask of bits).
      *   <p> Possible values:</tt>
      *   <dl>
      *   <dt>COMPONENT_FAMILY</dt>    <dd>Component Family.</dd>
      *   <dt>ASSEMBLY_FAMILY</dt>     <dd>Assembly Family.</dd>
      *   <dt>COMPONENT_INSTANCE</dt>  <dd>Component Instance.</dd>
      *   <dt>ASSEMBLY_INSTANCE</dt>   <dd>Assembly Instance.</dd>
      *   </dl>
      *
      * @return
      *  <ul>
      *     <li><code>S_OK</code> if the method succeeds.</li>
      *     <li><code>E_FAIL</code> Otherwise.</li>
      *  </ul>
      */
      static HRESULT ExpandAssemblyStructure( const CATLISTV(CATPLMID) & iInputList 
                                            , CATLISTV(CATPLMID)       & olstPlmId 
                                            , int                        inOutputFilter = COMPONENT_FAMILY | ASSEMBLY_FAMILY ) ;

    /** 
      * Get list of assembly components and MCAD documents.
      *
      * @param iInputList [in]
      *   The list of Root to be navigated.
      *
      * @param inOutputFilter [in]
      *   Define set of object types expected (mask of bits).
      *   <p> Possible values:</tt>
      *   <dl>
      *   <dt>COMPONENT_FAMILY</dt>    <dd>Component Family.</dd>
      *   <dt>ASSEMBLY_FAMILY</dt>     <dd>Assembly Family.</dd>
      *   <dt>COMPONENT_INSTANCE</dt>  <dd>Component Instance.</dd>
      *   <dt>ASSEMBLY_INSTANCE</dt>   <dd>Assembly Instance.</dd>
      *   </dl>
      *
      * @param olstPlmId [out]
      *   List of objects inExpandThe list of Subtypes.
      *
      * @param olstName [out]
      *   Name strings.
      *
      * @param olstTitle [out]
      *   Title strings.
      *
      * @param olstRevision [out]
      *   Revision strings.
      *
      * @return
      *  <ul>
      *     <li><code>S_OK</code> if the method succeeds.</li>
      *     <li><code>E_FAIL</code> Otherwise.</li>
      *  </ul>
      */
      static HRESULT ExpandAssemblyStructure( const CATLISTV(CATPLMID) & iInputList 
                                            , int                         inOutputFilter
                                            , CATLISTV(CATPLMID)        & olstPlmId 
                                            , CATListOfCATUnicodeString & olstName
                                            , CATListOfCATUnicodeString & olstTitle
                                            , CATListOfCATUnicodeString & olstRevision ) ;

    /**
      * Download first files associated to a list of documents in a specified directory.
      *
      * @param ilstDocumentPdmId [in]
      *   List of PDM Id of CAD documents to be downloaded.
      * 
      * @param iusFilePath [in]
      *   The directoy where download will be done.
      * 
      * @param olstDocumentPdmId [out]
      *   List of PDM Id of CAD documents downloaded.
      * 
      * @param olstFileNames [out]
      *   List of file names downloaded.
      *
      * @return
      *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>if method is successful.</dd>
      *   <dt>E_FAIL</dt>  <dd>if there is any problem.</dd>
      *   </dl>
      */
      static HRESULT DownloadFirstFileFromDocument( const CATLISTV(CATPLMID)  & ilstDocumentPdmId
                                                  , const CATUnicodeString    & iusFilePath
                                                  , CATLISTV(CATPLMID)        & olstDocumentPdmId
                                                  , CATListOfCATUnicodeString & olstFileNames      ) ;

   private:

    /**
      * Create and define the select clause for a PLMQL statement.
      *
      * @param iListTypeToQuery [in]
      *   The list of type involved in this query.
      *
      * @param iListOfAttr      [in]
      *   The list of attribute to be in the result.
      *
      * @param iQueryMode       [in]
      *   Definition of the query modes.
      *   <p> Possible values:</tt>
      *   <dl>
      *   <dt>BASIC_QUERY</dt>    <dd>Query by attributes.</dd>
      *   <dt>EXPAND_QUERY</dt>   <dd>Query by object, returns all children.</dd>
      *   <dt>OPEN_QUERY</dt>     <dd>Query by object, returns all objects informations.</dd>
      *   <dt>MATURITY_QUERY</dt> <dd>Internal use, no documentation available.</dd>
      *   <dt>VALIDITY_QUERY</dt> <dd>Internal use, no documentation available.</dd>
      *   </dl>
      *
      * @param ilStreamDescriptor [in]
      *   To request or not stream descriptor.
      *
      * @param opStatement      [out]
      *   .
      *
      * @param opQueryFilter    [out]
      *   .
      *
      * @return
      *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>if method is successful.</dd>
      *   <dt>E_FAIL</dt>  <dd>if there is any problem.</dd>
      *   </dl>
      */
      static HRESULT _CreateAndDefineSelectClause( const CATLISTP(CATPLMType) & iListTypeToQuery
                                                 , const CATListOfCATString   & iListOfAttr
                                                 , QueryMode                    iQueryMode 
                                                 , CATBoolean                   ilStreamDescriptor
                                                 , CATIPLMCompStatement      *& opStatement
                                                 , CATIPLMQueryFilter        *& opQueryFilter   ) ;

    /**
      * Create and define the select clause for a PLMQL statement.
      *
      * @param ilstVaultUrl     [in]
      *   .
      *
      * @param ilstTypeLate    [in]
      *   .
      *
      * @param ilstMarkStamp   [in]
      *   .
      *
      * @param lstPersistencyType     [in]
      *   .
      *
      * @param lstPersistencyName    [in]
      *   .
      *
      * @param lstFormat   [in]
      *   .
      * 
      * @param iusFilePath [in]
      *   The directoy where download will be done.
      * 
      * @param olstFileNames [in]
      *   List of file names downloaded.
      *
      * @return
      *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>if method is successful.</dd>
      *   <dt>E_FAIL</dt>  <dd>if there is any problem.</dd>
      *   </dl>
     */
      static HRESULT _DownloadStreamsUsingCache( CATLISTP(CATVVSUrl)       & ilstVaultUrl 
                                               , CATListOfCATUnicodeString & ilstTypeLate
                                               , CATListOfCATUnicodeString & ilstMarkStamp 
                                               , CATListOfCATUnicodeString & lstPersistencyType 
                                               , CATListOfCATUnicodeString & lstPersistencyName 
                                               , CATListOfCATUnicodeString & lstFormat 
                                               , const CATUnicodeString    & iusFilePath
                                               , CATListOfCATUnicodeString & olstFileNames ) ;

} ;
//-----------------------------------------------------------------------
#endif

 
