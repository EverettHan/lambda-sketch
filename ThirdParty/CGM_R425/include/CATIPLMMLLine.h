//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATIPLMMLLine.h
//  Define  the  CATIPLMMLLine interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
//
// Usage  notes:
// Modeler language (ML) describes navigation on Modeler level (To sum up, we
// recall that it exists 3 different levels: Core Level, Modeler Level, Custo Level)
// Execution this navigation and creation of a table containing datas extracted from database is made using
// both API CATIPLMMLEngine and CATPLMMLEngineParameters class.
//
// You can reduce the size of the table (and free memory...) using method
// void SetFilter( CATIPLMMLFilterFunction* ipFilterFunc = NULL) on class CATPLMMLEngineParameters.
// This function is called for each line of the table. Then the line is kept or not. So we need to provide
// a way to retrieve informations stored by each line. This job is made using the current API.
//
// eg for a filter method using CATIPLMLine:
// class ClashOnly : public CATIPLMMLFilterFunction
// {
// public:
//   ClashOnly():CATIPLMMLFilterFunction(){}
//   ~ClashOnly(){}
//
//   HRESULT FilterFunction(CATIPLMMLLine* ipLine,CATBoolean & oIsLineToBeDeleted)
//   {
//     oIsLineToBeDeleted = TRUE;
//     if(ipLine == NULL){cout<<"*** ERROR *** ipLine == NULL"<<endl;return E_FAIL;}
//
//     CATOmxKeyString attrKey;
//     CATOmxAny attrValue;
//     int mask;
//     HRESULT rc = ipLine->GetAttributeValue("METRIC.V_Itf_Type",1,attrKey,attrValue,mask);
//     if(FAILED(rc)){cout<<"*** ERROR *** CATIPLMMLLine::GetValue()"<<endl;return E_FAIL;}
//
//     int valueI;
//     CATOmxKeyString valueS;
//     rc = attrValue.GetEnum(valueS,valueI);
//     if(FAILED(rc)){cout<<"*** ERROR *** CATOmxAny::GetEnum()"<<endl;return E_FAIL;}
//     if(valueI != 1)
//       oIsLineToBeDeleted = TRUE;
//     else
//       oIsLineToBeDeleted = FALSE;
//     return S_OK;
//   }
// };
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 

#ifndef CATIPLMMLLine_H
#define CATIPLMMLLine_H

#include "CATPLMModelerLanguage.h"

#include "CATOmxSharable.h"

#include "CATOmxArray.h"
#include "CATOmxKeyString.h"
#include "CATOmxCollecManager.h"

#include "CATPLMMLRelationStatus.h"
#include "CATPLMMLRelationSynchroStatus.h"
#include "CATPLMMLPairAliasOrTypeNameObjPos.h"
#include "CATPLMMLListPairAliasOrTypeNameObjPos.h"

#include "CATLISTV_Declare.h"
class CATLISTV(CATPLMID);

class CATPLMMLLineNode;
class CATString;
class CATOmxAny;
class CATOmxKeyString;
class CATIPLMError;
class CATPLMID;
class CATPLMTypeHArray;
class CATPLMTypeHSet;
class CATPLMTypeH;
class CATComponentId;
class CATIPLMMLDicoNavNode;
class CATPLMMLRelationValue;
class CATPLMMLLineNodeOfTree;

class ExportedByCATPLMModelerLanguage CATIPLMMLLine : public CATOmxSharable
{
  friend class CATPLMMLTable;
  friend class CATPLMMLLineBuilderVisitor;
public:
  CATIPLMMLLine();

  virtual ~CATIPLMMLLine();

  /**
  * <br><b>Role</b>: Return the number of objets for a given column.
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve <attrName> on all nodes.
  * Suppose we have at the end the following line:
  * <aliasNodeName1>.<attrName> | <aliasNodeName2>.<attrName>
  * ----------------------------|----------------------------
  *      <attrNameValue>        | <attrNameValue1> <attrNameValue2>
  *
  * if iColumnName == <aliasNodeName1>.<attrName> then oNbOfObjects == 1: <attrNameValue>
  * if iColumnName == <aliasNodeName2>.<attrName> then oNbOfObjects == 2: <attrNameValue1> and <attrNameValue2>
  *
  * @param iAttrIdentifier
  *  Formalism for iAttrIdentifier:
  *  <aliasOrTypeName>.<attr>,
  *  <aliasOrTypeName>::<custoTypeName>.<attrName>,
  *  <aliasOrTypeName>.Ext(<typeNameExt>).<attr>,
  *  <aliasOrTypeName>::<custoTypeName>.Ext(<typeNameExt>).<attr>
  *  <aliasOrTypeName>,<attr>... are defined in the navigation written in ML.
  * @param oNbOfObjects
  *  Number of objects for a given line and a given column.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetNbOfObjects( const CATString & iAttrIdentifier,
                                  int & oNumberOfObjects) = 0;

  /**
  *
  * <br><b>Role</b>:
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve plmid on all nodes.
  * Suppose we have at the end the following table:
  * <aliasNodeName1>.plmid | <aliasNodeName2>.plmid
  * -----------------------|------------------------------
  *    <plmidValue1>       | <plmidValue11> <plmidValue12>
  *
  * if iAliasOrTypeName == <aliasNodeName1> oNbOfObjPlmid = 1.
  * if iAliasOrTypeName == <aliasNodeName2> oNbOfObjPlmid = 2.
  *
  * @param iAliasOrTypeNameIdentifier
  *  Formalism for iAliasOrTypeNameIdentifier:
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param oNbOfObjPlmid
  *  Number of plmid for the given column.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetNbOfPlmid( const CATString & iAliasOrTypeName,
                                int&  oNbOfObjPlmid ) = 0;

  /**
  *
  * <br><b>Role</b>:
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve plmid on all nodes.
  * Suppose we have at the end the following table:
  * <aliasNodeName1>.plmid | <aliasNodeName2>.plmid
  * -----------------------|------------------------------
  *    <plmidValue1>       | <plmidValue11> <plmidValue12>
  *
  * if iAttrIdentifier == <aliasNodeName1> iObjectNb = 1, then oPlmid == <plmidValue11>.
  * if iAttrIdentifier == <aliasNodeName1> iObjectNb = 2, then oPlmid == <plmidValue12>.
  *
  * @param iAliasOrTypeNameIdentifier
  *  Formalism for iAliasOrTypeNameIdentifier:
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iObjectNb
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oPlmid
  *  Value of plmid researched.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetPlmid( const CATString & iAliasOrTypeName,
                            int iObjectNb,
                            CATPLMID & oPlmid) = 0;

  /**
  *
  * <br><b>Role</b>:
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve plmid on all nodes.
  * Suppose we have at the end the following table:
  * line number|<aliasNodeName1>               | <aliasNodeName2>
  * -----------|-------------------------------|------------------------------
  *     XXX    |   <plmidValueX1> <ext1>       | <plmidValueX21> <ext2>, <plmidValueX22> <ext3>
  *
  * if iAliasOrTypeName == <aliasNodeName1> iObjectNb = 1, then olType == <ext1>.
  * if iAliasOrTypeName == <aliasNodeName2> iObjectNb = 2, then olType == <ext3>.
  * @param iAliasOrTypeName
  * 
  * @param iObjectNb
  * 
  * @param olType
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT ListExtension(  const CATString & iAliasOrTypeName,
                                    int iObjectNb,
                                    CATPLMTypeHSet& olType) = 0;

  /*
   * @Deprecated 
  */
  virtual HRESULT ListExtension(  const CATString & iAliasOrTypeName,
                                    int iObjectNb,
                                    CATPLMTypeHArray& olType) = 0;

  /**
  *
  * <br><b>Role</b>: Returns value of attribute.
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve <attrName> on all nodes.
  * Suppose we have at the end the following table:
  *  <aliasNodeName1>.<attrName> | <aliasNodeName2>.<attrName>
  * -----------------------------|-------------------------------------
  *         <attrNameValue1>     | <attrNameValue11>, <attrNameValue12>
  *
  * if iAttrIdentifier == <aliasNodeName2>.<attrName>, if iNbOfObjects == 2, then oAttrValue == <attrNameValue12>.
  *
  * @param iAttrIdentifier
  *  Formalism for iColumnName:
  *  <aliasOrTypeName>.<attr>,
  *  <aliasOrTypeName>::<custoTypeName>.<attrName>,
  *  <aliasOrTypeName>.Ext{<typeNameExt>}.<attr>,
  *  <aliasOrTypeName>::<custoTypeName>.Ext(<typeNameExt>).<attr>.
  *  <aliasOrTypeName>,<attr>... defined in the navigation written in ML.
  * @param iNbOfObjects
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oAttrValue
  *  The value of the attribute.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetAttributeValue(  const CATString & iAttrIdentifier,
                                      int iObjectNb,
                                      CATOmxKeyString & oAttrKey,
                                      CATOmxAny & oAttrValue,
                                      int & oMask) = 0;

  /**
  *
  * <br><b>Role</b>: Returns Number of relations hold by pointing object.
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  *
  * <aliasNodeName1> is the pointing object.
  * <aliasNodeName2> is the pointed object.
  *
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * So, at the end, we have for each instance of <aliasNodeName1>, two instances of <aliasNodeName2>:
  * <instance of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<first instance of relationName>]> <second Instance of aliasNodeName2>
  * oNbOfRelation == 2
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeName>.<RelationName>
  *  <aliasOrTypeName>,<RelationName> defined in the navigation written in ML.
  * @param iPositionPointing
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oNbOfRelation
  *  Number of relation hold by pointing object.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetNbOfRel( const CATString & iRelIdentifier,
                              int iPositionPointed,
                              int & oNbOfRelation) = 0;

  /**
  *
  * <br><b>Role</b>: Returns status of the relation: synchronized or not, broken or not
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * So, at the end, we have for each instance of <aliasNodeName1>, two instances of <aliasNodeName2>:
  * <instance of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<first instance of relationName>]> <second Instance of aliasNodeName2>
  * Suppose <first instance of relationName> is "synchronised" and "solved"
  * Suppose <second instance of relationName> is "not synchronised" and "broken"
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointed == 1, then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointed == 2, then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeName>.<RelationName>
  *  <aliasOrTypeName>,<RelationName> defined in the navigation written in ML.
  * @param iPositionPointed
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oRelationStatus
  *  The relation status searched.
  * @param oRelationSynchroStatus
  *  The sync relation status searched.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelStatus( const CATString &iRelIdentifier,
                                int iPositionPointing,
                                int iPositionRelation,
                                CATPLMMLRelationStatus & oRelationStatus,
                                CATPLMMLRelationSynchroStatus & oRelationSynchroStatus) = 0;

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
  * <instance of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<first instance of relationName>]> <second Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * Suppose <first instance of relationName> is "synchronised" and "solved"
  * Suppose <second instance of relationName> is "not synchronised" and "broken"
  * Suppose <third instance of relationName> is "synchronised" and "solved"
  * Suppose <fourth instance of relationName> is "not synchronised" and "broken"
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointing == 1, iPositionRelation = 1, then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointing == 1, iPositionRelation = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointing == 2, iPositionRelation = 1, then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, if iPositionPointing == 2, iPositionRelation = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iPositionPointing
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param iPositionRelation
  *  The index of the iPositionRelation. iObjectNb starts at 1.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelPointedComp(  const CATString & iRelIdentifier,
                                      int iPositionPointing,
                                      int iPositionRelation,
                                      CATLISTV(CATPLMID) & oListPlmid) = 0;

  /*
  * <br><b>Role</b>: Returns Number of relations hold by pointing object.
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  *
  * <aliasNodeName1> is the pointing object.
  * <aliasNodeName2> is the pointed object.
  *
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose that for each line , we always have two instances of <aliasNodeName1>.
  * So, at the end, we have for each instance of <aliasNodeName1>, two instances of <aliasNodeName2>:
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance1 of aliasNodeName1> -[<second instance of relationName>]> <second Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<second instance of relationName>]> <second Instance of aliasNodeName2>
  * oNbOfRelation == 4
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeName>.<RelationName>
  *  <aliasOrTypeName>,<RelationName> defined in the navigation written in ML.
  * @param oNbOfRelation
  *  Number of relation hold by pointing object.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetNbOfRel( const CATString & iRelIdentifier,
                              int & oNbOfRelation) = 0;

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
  * <instance of aliasNodeName1> -[<first instance of relationName>]>  <first  Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<first instance of relationName>]>  <second Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * Suppose <first instance of relationName> is "synchronised" and "solved"
  * Suppose <second instance of relationName> is "not synchronised" and "broken"
  * Suppose <third instance of relationName> is "synchronised" and "solved"
  * Suppose <fourth instance of relationName> is "not synchronised" and "broken"
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iAbsolutePosition = 1 , then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iAbsolutePosition = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iAbsolutePosition = 3 , then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iAbsolutePosition = 4 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeName>.<RelationName>
  *  <aliasOrTypeName>,<RelationName> defined in the navigation written in ML.
  * @param iAbsolutePosition
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oRelationStatus
  *  The relation status searched.
  * @param oRelationSynchroStatus
  *  The sync relation status searched.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelStatus( const CATString & iRelIdentifier,
                                int iAbsolutePosition,
                                CATPLMMLRelationStatus & oRelationStatus,
                                CATPLMMLRelationSynchroStatus & oRelationSynchroStatus) =0;

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
  * <instance of aliasNodeName1> -[<first instance of relationName>]>  <first  Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<first instance of relationName>]>  <second Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * Suppose <first instance of relationName> is "synchronised" and "solved"
  * Suppose <second instance of relationName> is "not synchronised" and "broken"
  * Suppose <third instance of relationName> is "synchronised" and "solved"
  * Suppose <fourth instance of relationName> is "not synchronised" and "broken"
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iAbsolutePosition = 1 , then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iAbsolutePosition = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iAbsolutePosition = 3 , then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>, if iLineNb == 1, iAbsolutePosition = 4 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iAbsolutePosition
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelPointedComp(  const CATString & iRelIdentifier,
                                      int iAbsolutePosition,
                                      CATLISTV(CATPLMID) & oListPlmid) = 0;

  /**
  *
  * <br><b>Role</b>: Returns the list of plmid crossed to go from Root to iIdentifier.
  * Be careful! Suppose you have two nodes and a relation between these 2 nodes: SCA-[PointedOccurences]>TARGET.
  * Suppose you have a path of instance to cross to go from SCA to TARGET. oListPlmid only contain PLMID of SCA and
  * PLMID of TARGET (the real node).
  *
  * @param iIdentifier
  *  Formalism for iIdentifier: <aliasOrTypeName>
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iObjectNb
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oListPlmid
  *  List of plmid crossed to go from Root to iIdentifier.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetPathFromRoot(  const CATString & iIdentifier,
                                    int iObjectNb,
                                    CATLISTV(CATPLMID) & oListPlmid) = 0;

  virtual HRESULT GetPathFromRoot(  const CATString & iAliasOrTypeName,
                          int iObjectNb,
                          CATPLMMLListPairAliasOrTypeNameObjPos& oLPairAliasOrTypeNameObjPos) = 0;

  /**
  *
  * <br><b>Role</b>: Returns the list of plmid crossed to go from Key to iIdentifier.
  * Be careful! Suppose you have two nodes and a relation between these 2 nodes: SCA-[PointedOccurences]>TARGET.
  * Suppose you have a path of instance to cross to go from SCA to TARGET. oListPlmid only contain PLMID of SCA and
  * PLMID of TARGET (the real node).
  *
  * @param iIdentifier
  *  Formalism for iIdentifier: <aliasOrTypeName>.
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iObjectNb
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oListPlmid
  *   List of plmid crossed to go from Key to iIdentifier.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetPathFromKey( const CATString & iIdentifier,
                                  int iObjectNb,
                                  CATLISTV(CATPLMID) & oListPlmid) = 0;

  virtual HRESULT GetPathFromKey( const CATString & iAliasOrTypeName,
                        int iObjectNb,
                        CATPLMMLListPairAliasOrTypeNameObjPos& oLPairAliasOrTypeNameObjPos) = 0;

private:
  virtual int Append( CATIPLMMLDicoNavNode* ipNode,
                      CATComponentId& iRealComp) = 0;

  virtual int Append( const CATString & iAliasOrTypeNamePointing,
            const CATString & iNodeAlias,
            const CATString & iAliasOrTypeNamePointed,
            int iPosPointing,
            int iPosPointed,
            CATPLMMLRelationValue & iRelVal) = 0;

  virtual HRESULT Append (  CATPLMMLLineNodeOfTree* iPreviousNode,
                  CATPLMMLLineNodeOfTree* ipNewNode) = 0;

  virtual HRESULT GetAttributeValue(  const CATString &iAttrIdentifier,
                            int iObjectNb,
                            CATPLMTypeH& oType,
                            CATPLMTypeH& oTypeExt,
                            CATOmxKeyString & oAttrKey,
                            CATOmxAny & oAttrValue,
                            int & oMask)=0;

  virtual HRESULT GetRelIndex(  const CATString & iRelIdentifier,
                      int iAbsolutePosition,
                      CATULONG32& oIndex)=0;

  virtual HRESULT GetRelIndex(  const CATString & iRelIdentifier,
                      int iPositionPointing,
                      int iPositionRelation,
                      CATULONG32& oIndex)=0;

  CATIPLMMLLine(const CATIPLMMLLine&);

  CATIPLMMLLine& operator=(const CATIPLMMLLine&);
};

template <> ExportedByCATPLMModelerLanguage CATOmxCollecManager & CATOmxDefaultCollecManager <CATIPLMMLLine*>::manager();

#endif
