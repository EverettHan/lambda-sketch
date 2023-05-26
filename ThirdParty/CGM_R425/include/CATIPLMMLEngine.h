//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATIPLMMLEngine.h
//  Define  the  CATIPLMMLEngine  interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
//
// Usage  notes:
// Execution of a navigation described using Modeler language (ML) grammar 
// and creation of a table containing datas extracted from database.
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 


#ifndef CATIPLMMLEngine_H
#define CATIPLMMLEngine_H

#include "CATUnicodeString.h"               // System PublicInterfaces
#include "CATListOfCATString.h"             // System PublicInterfaces

#include "CATIPLMMLEngineBase.h"            // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMModelerLanguage.h"          // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLOptions.h"                // CATPLMModelerLanguage ProtectedInterfaces


class CATError;
class CATPLMMLNodeInfoIterator;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerLanguage IID IID_CATIPLMMLEngine;
#else
extern "C" const IID IID_CATIPLMMLEngine ;
#endif

class ExportedByCATPLMModelerLanguage CATIPLMMLEngine : public CATIPLMMLEngineBase
{
  // odt
  friend class TSTCATPLMMLGetRelationValue2_1;friend class TSTCATPLMMLGetRelationValue2_2;friend class TSTCATPLMMLGetRelationValue1;friend class TSTCATPLMMLCusto;friend class TSTCATPLMMLError;friend class TstCATPLMMLParseAndExecute;friend class TSTCATPLMMLExtMultiCustoEnrichAllCusto;friend class TSTCATPLMMLIRPCER;friend class TSTCATPLMMLUIDebugDlg;friend class TSTCATPLMMLMultiCustoEnrichAllCusto;friend class TstCATPLMMLSession;friend class TSTCATPLMMLReadFileInRTV;

  // real user
  friend class CATAdpMLCompleterImpl;                           // Lock, Unlock...MIGRATION REQUESTED ON CATIPLMMLEngineRestricted
  friend class CATPLMQETaskML;                                  // Dinde of FBN   MIGRATION REQUESTED ON CATIPLMMLEngineRestricted
  friend class CATSedNavItfServices;                            // Simulia

  CATDeclareInterface;
public:
  
  /**
  * <br><b>Role</b>: Validation of the input string value passed as argument regarding Modeler language grammar.
  *
  * @param iFileNameWithoutExtensionName
  *  We should find this file in <your Fw>\resources\ML. You should promote your file in <Your Fw>\resources\ML.
  *  DON T FORGET TO DO mkrtv!!!!!!!!!!
  *  Name of the file containing the description of the ML without the extension ".ml".
  * @param iOptions
  *  engine options
  * @param opError out. 
  *  Don't forget to delete this pointer if necessary.
  *  Don't do new CATError...we do it for you if necessary.
  *  error describing which rule of Modeler language grammar has been violated.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT Init( const CATPLMMLOptions& iOptions,
                        const CATUnicodeString& iFileNameWithoutExtensionName,
                        CATError* & opError ) = 0;

  /**
  * <br><b>Role</b>: Execution of the navigation.
  * @param iParam
  *  Object containing roots of the navigation (instantiated model level)
  *  Different custo added on each node of the navigation (custo used to filter or enrich existing node).
  * @param opError [out,CATBaseUnknown#Release]
  *  Don't do new CATError...we do it for you if necessary.
  *  Error describing the problem during the execution of the query or during the the table build.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT Execute(  const CATPLMMLEngineParameters& iParam,
                            CATError*& opError ) = 0;

protected:

  /*********************************************************************************************
   *********************************************************************************************
   *********************************************************************************************
   SPECIFIC PROTECTION FOR THE FOLLOWING SERVICES:
   ML generator could be created...
   *********************************************************************************************
   *********************************************************************************************
   *********************************************************************************************/

  /**
  * We share the same index as the one used for GetAttributeValue(...iObjectPosition...)
  *
  * <br><b>Role</b>: Returns status of the relation: synchronized or not, broken or not.
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  *
  * <aliasNodeName1> is the pointing object.
  * <aliasNodeName2> is the pointed object.
  *
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * So, at the end, we have for each instance of <aliasNodeName1>, two instances of <aliasNodeName2>:
  * <instance 1 of aliasNodeName1> -[<first instance of relationName>]>  <first  Instance of aliasNodeName2>
  * <instance 1 of aliasNodeName1> -[<first instance of relationName>]>  <second Instance of aliasNodeName2>
  * <instance 2 of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance 2 of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iObjectPosition = 1 , then oIndex == 1
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iObjectPosition = 2 , then oIndex == 2
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iObjectPosition = 3 , then oIndex == 1
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iObjectPosition = 4 , then oIndex == 2
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param iObjectPosition
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oRelIndex
  *  oRelIndex: Number stored on the semantic relation. Number computed when the relation is created. Current method retrieves this value.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelIndex(  const CATString & iRelIdentifier,
                                int iLineNb,
                                int iObjectPosition,
                                CATULONG32& oRelIndex) = 0;

  /**
  *
  * <br><b>Role</b>: Returns status of the relation: synchronized or not, broken or not.
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  *
  * <aliasNodeName1> is the pointing object.
  * <aliasNodeName2> is the pointed object.
  *
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * So, at the end, we have for each instance of <aliasNodeName1>, two instances of <aliasNodeName2>:
  * <instance 1 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance 1 of aliasNodeName1> -[<first instance of relationName>]> <second Instance of aliasNodeName2>
  * <instance 2 of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance 2 of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointing == 1, iPositionRelation = 1 , then oIndex == 1
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointing == 1, iPositionRelation = 2 , then oIndex == 2
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointing == 2, iPositionRelation = 1 , then oIndex == 1
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointing == 2, iPositionRelation = 2 , then oIndex == 2
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param iPositionPointing
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param iPositionRelation
  *  The index of the iPositionRelation. iObjectNb starts at 1.
  * @param oIndex
  *  oRelIndex: Number stored on the semantic relation. Number computed when the relation is created. Current method retrieves this value.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelIndex( const CATString & iRelIdentifier,
                               int iLineNb,
                               int iPositionPointing,
                               int iPositionRelation,
                               CATULONG32& oRelIndex) = 0;

};

CATDeclareHandler( CATIPLMMLEngine, CATBaseUnknown );

#endif
