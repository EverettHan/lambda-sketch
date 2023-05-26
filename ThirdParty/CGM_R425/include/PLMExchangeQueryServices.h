//=======================================================================================
//** WARNING: YWE 19:03:12 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
//===================================================================
// COPYRIGHT Dassault Systemes 2014-2015
//===================================================================
// PLMExchangeQueryServices.cpp
// Header definition of class PLMExchangeQueryServices
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014/05/13 Creation: Code generated by the 3DS wizard    H9M
//===================================================================

#ifndef PLMExchangeQueryServices_H
#define PLMExchangeQueryServices_H

// SpecialAPI
#include "CATSysErrorDef.h"
#include "CATIAV5Level.h"

// System
#include "CATListOfCATUnicodeString.h"                // CO0LSTST.m
#include "CATListOfInt.h"                             // CO0RCINT.m
#include "CATString.h"                                // JS0STR.m

// KnowledgeInterfaces
#include "CATListValCATIType.h"                       // CATLifSpecs.m  
#include "CATListOfCATIValue.h"                       // CATLifSpecs.m  
#include "CATAttributeInfos.h"                        // CATLifSpecs.m

// PLMExchangeServices
#include "PLMExchangeGlobalServices.h"                // PLMExchangeGlobalServices.m

// -- Forward declaration
class CATListPtrCATIAdpPLMIdentificator ;
class CATIPLMCompRecordReadSet          ;

// -- Activate or not access to attribute on Custo types
#ifndef CATIAR418
#define Retrieve_Attribute_For_Custo_Type 
#endif
/**
  * Class enabling to provide services to retrieve data that needs Query operations.
  */
class ExportedByPLMExchangeGlobalServices PLMExchangeQueryServices
{
   public:

    /** 
      * <b>ValueType:</b> Define the different type possible for an attribute value. 
      * <dl>
      * <dt>ValueType_Boolean:</dt> <dd>CATBoolean.</dd> 
      * <dt>ValueType_Integer:</dt> <dd>int.</dd>
      * <dt>ValueType_Float:</dt>   <dd>double.</dd>
      * <dt>ValueType_String:</dt>  <dd>CATUnicodeString.</dd>
      * <dt>ValueType_Date:</dt>    <dd>CATTime</dd>
      * </dl>
      */
      enum ValueType
      {
        ValueType_Boolean = 0x00000001
      , ValueType_Integer = 0x00000002
      , ValueType_Float   = 0x00000004
      , ValueType_String  = 0x00000008
      , ValueType_Date    = 0x00000020   
      } ;

    /** 
      * Retrieves Subtypes of the type "Document".
      *
      * @param oListOfDocsSubTypes [out]
      *   The list of Subtypes.
      *
      * @return
      *  <ul>
      *     <li><code>S_OK</code> if the method succeeds.</li>
      *     <li><code>E_FAIL</code> Otherwise.</li>
      *  </ul>
      */
      static HRESULT RetrieveDocsSubTypes( CATListOfCATUnicodeString & oListOfDocsSubTypes ) ;

#ifdef  Retrieve_Attribute_For_Custo_Type 
    /** 
      * Retrieves attributes of Document Customization type.
      *
      * @param iStrCustoType [in]
      *        The Document Customization type
      *
      * @param oListOfAttrNames [out]
      *        The list of attributes names
      *
      * @param oListOfAttrTypes [out]
      *        The list of attributes types
      *
      * @param oListOfAttrValues [out]
      *        The list of attributes values (if any)
      *
      * @return
      *  <ul>
      *     <li><code>S_OK</code> if the method succeeds.</li>
      *     <li><code>E_FAIL</code> Otherwise.</li>
      *  </ul>
      */
      static HRESULT RetrieveCustoTypeAttributes( const CATUnicodeString    & iStrCustoType
                                                , CATListOfCATUnicodeString & oListOfAttrNames
                                                , CATListOfInt              & oListOfAttrTypes
                                                , CATListOfCATIValue        & oListOfAttrValues ) ;
#endif //Retrieve_Attribute_For_Custo_Type 

    /** 
      * Retrieves attribute name for a given type. (Preview panel usage)
      *
      * @param iAttributeId [in]
      *        The Attribute Id chosen in the file CATPLM3DXMLIdFrm.CATNls
      *
      * @param iType [in]
      *        Component type
      *
      * @param oAttributeName [out]
      *        Current attribute name. It returns the VPLM corresponding attribute if type was NULL.
      */
      static void GetAttributeName( const CATString & iAttributeId , const CATIType_var & iType , CATUnicodeString & oAttributeName ) ;

    /** 
      * Retrieves Mapped attribute Id.
      *
      * @param iAttributeId [in]
      *        The Attribute Id chosen in the file CATPLM3DXMLIdFrm.CATNls or attribute name before Basic attribute convergence in R2015x or after it.
      *
      * @param oMappedAttributeId [out]
      *        Current attribute Id. 
      *
      * @return
      *  <ul>
      *     <li><code>S_OK</code> if the method succeeds.</li>
      *     <li><code>E_FAIL</code> Otherwise.</li>
      *  </ul>
      */
      static HRESULT GetMappedAttributeId( const CATString & iAttributeId , CATString & oMappedAttributeId ) ;

    /**
      * GetObjectAttributeValue Method to Get given attribute value.
      *
      * <br><b>Role</b>:  Method internally doing server query and fetching given attribute values.
      *
      * @param iptrListOfPLMComponents [In]
      *  Input list of PLM component object.
      *
      * @param iusAttributeName  [In]
      *  Name of the attribute to get value.
      *
      * @param ousListOfAttributeValues  [Out]
      *  list of attribute values for each object.
      *
      * @return
      *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>If the method succeeds.</dd>
      *   <dt>E_FAIL</dt>  <dd>If server query fails.</dd>
      */  
      static HRESULT GetObjectAttributeValue(CATListPtrCATIAdpPLMIdentificator & iptrListOfPLMComponents, CATUnicodeString & iusAttributeName, CATListOfCATUnicodeString & ousListOfAttributeValues);

    /**
      * CreateAndExecuteQueryForAttribute Method to create and execute server query.
      *
      * <br><b>Role</b>:  Method creates query statement for attrinute value and execute.
      *
      * @param iptrListOfPLMComponents [In]
      *  Input list of PLM component object.
      *
      * @param iusAttributeName  [In]
      *  Name of the attribute to get value. V_discipline is forbidden when isAllKindOfObject is set to true. We recommend 
      *  to pass attribute such as cestamp which is common to all object while passing isAllKindOfObject = TRUE
      *
      * @param opPLMRecordReadSet  [Out, IUnknown#Release]
      *  Record set returned by query.
      *
#ifdef CATIAR420
      * @param isAllKindOfObject  [In]
      *  Added Flag to support all kind of Object
      *  DEFAULT is FALSE to keep old behavior
      *
#endif
      * @return
      *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>If the method succeeds.</dd>
      *   <dt>E_FAIL</dt>  <dd>If any error occured during processing.</dd>
      *   </dl>
      */
#ifdef CATIAR420
	  static HRESULT CreateAndExecuteQueryForAttribute(CATListPtrCATIAdpPLMIdentificator & iptrListOfPLMComponents, CATUnicodeString & iusAttributeName, CATIPLMCompRecordReadSet *& opPLMRecordReadSet, CATBoolean isAllKindOfObject = FALSE);
#else
	  static HRESULT CreateAndExecuteQueryForAttribute(CATListPtrCATIAdpPLMIdentificator & iptrListOfPLMComponents, CATUnicodeString & iusAttributeName, CATIPLMCompRecordReadSet *& opPLMRecordReadSet);
#endif
   private:

    /** 
      * Retrieves all the sub types for a given type in a recursive manner.
      *
      * @param ispType [in]
      *        input type for which all the related subtypes needs to be retrived.
      *
      * @param oListOfSubTypes [out]
      *        Output list of subtypes retrived for the given type.   
      */
      static void _getAllSubTypes(const CATIType_var & ispType , CATListValCATIType_var & oListOfSubTypes);

#ifdef  Retrieve_Attribute_For_Custo_Type 
    /** 
      * Retrieves the type of an attribute
      *
      * @param iInfo [in]
      *        Attribute info.
      *
      * @param oAttributeType [out]
      *        Attribute type.   
      */
      static void _getAttributeInfoType( CATAttributeInfos & iInfo , ValueType & oAttributeType ) ;
#endif // Retrieve_Attribute_For_Custo_Type 
} ;
//-----------------------------------------------------------------------
#endif