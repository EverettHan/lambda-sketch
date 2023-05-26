//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATIPLMMLEngineBase.h
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
// Grammar of this language is described in a wiki:
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
// There are two characterictic node in the navigation described using ML grammar:
// 1-The root of the navigation (it is the first element of the navigation).
// eg:
// Suppose you have the following navigations:
// REF-[PointedSCA208]!>SCA-[Owner]>METRIC-[LinkMetric]!>CONTEXT-[LinkRootContextToSCA]>REFINST
// SCA-[PointedOccurences]>TARGET
// The root of the navigation is REF
// 
// 2-The primary key.
// Object used in the [LINES] block is the PrimaryKey.
// We will have one instance of Primary Key per line in the table generated.
// eg:
// Suppose you have the following block in the string describing the navigation 
// and using the Modeler language grammar:
// [LINES]
// CONTEXT.PLMID
// The primary key is CONTEXT
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 


#ifndef CATIPLMMLEngineBase_H
#define CATIPLMMLEngineBase_H

#include "CATBaseUnknown.h"                 // System PublicInterfaces
#include "CATUnicodeString.h"               // System PublicInterfaces
#include "CATListOfCATString.h"             // System PublicInterfaces

#include "CATPLMModelerLanguage.h"                  // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLRelationStatus.h"                 // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLRelationSynchroStatus.h"          // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLOptions.h"                        // CATPLMModelerLanguage ProtectedInterface
#include "CATPLMMLPairAliasOrTypeNameObjPos.h"      // CATPLMModelerLanguage ProtectedInterfaces
#include "CATPLMMLListPairAliasOrTypeNameObjPos.h"  // CATPLMModelerLanguage ProtectedInterfaces

#include "CATOmxArray.h"
#include "CATOmxKeyString.h"

#include "CATPLMMLOmxCollection.h"

#include "CATLISTV_Declare.h"
class CATLISTV(CATPLMID);

class CATPLMID;
class CATError;
class CATPLMMLEngineParameters;
class CATOmxAny;
class CATString;
class CATOmxKeyString;
class CATIPLMMLFilterFunction;
class CATPLMMLNodeInfoIterator;
class CATPLMTypeHArray;
class CATPLMTypeHSet;

class ExportedByCATPLMModelerLanguage CATIPLMMLEngineBase : public CATBaseUnknown
{
public:

  /**
  * Retrieve informations on all nodes that have been used in ML to describe the navigation.
  * ORDER CAN CHANGE AT ANY TIME!
  * ORDER CAN CHANGE AT ANY TIME!
  * ORDER CAN CHANGE AT ANY TIME!
  *
  * <br><b>Role</b>: Retrieve informations on all nodes that have been used in ML to describe the navigation.
  * Order can change at any time!
  *
  * @param oListAlias
  *  informations on nodes used in ML to describe the navigation.
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT ListNode(CATPLMMLNodeInfoIterator& oIterator) = 0;

  /**
  * <br><b>Role</b>: 
  * @param ipPostFilteringFunc
  *   AFTER execution of query, ability given to filter lines of table generated using current method.
  * 
  * AddRef is made on this object.
  */
  virtual HRESULT ApplyPostFiltering(CATIPLMMLFilterFunction* ipPostFilteringFunc) = 0;

  /**
  *
  * <br><b>Role</b>: Return the number of lines of the table generated.
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 1 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve <attrName> on all nodes.
  * Suppose we have at the end the following table:
  * line number| <aliasNodeName1>.<attrName> | <aliasNodeName2>.<attrName>
  * -----------| ----------------------------|----------------------------
  *     1      |        <attrNameValue>      |      <attrNameValue1>
  *     2      |        <attrNameValue>      |      <attrNameValue1>
  *
  * GetNbOfLines returns 2

  * @return
  *  The index of the line. iLineNb starts at 1.
  * 
  */
  virtual int GetNbOfLines() = 0;

  /*********************************************************************************************
   *********************************************************************************************
   *********************************************************************************************
   * Ability to retrieve attributes and plmid stored on each object using service:
   * GetAttributeValue(...)
   * GetPlmid(...)
  *********************************************************************************************
  *********************************************************************************************
  *********************************************************************************************/

  /**
  *
  * <br><b>Role</b>:
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve plmid on all nodes.
  * Suppose we have at the end the following table:
  * line number|<aliasNodeName1>.plmid | <aliasNodeName2>.plmid
  * -----------|-----------------------|------------------------------
  *     1      |   <plmidValue1>       | <plmidValue11> <plmidValue12>
  *     2      |   <plmidValue2>       | <plmidValue21> <plmidValue22>
  *
  * if iAliasOrTypeName == <aliasNodeName1> and iLineNb == 1 , oNbOfObjPlmid = 1.
  * if iAliasOrTypeName == <aliasNodeName2> and iLineNb == 2 , oNbOfObjPlmid = 2.
  *
  * @param iAliasOrTypeName
  *  Formalism for iAliasOrTypeName:
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param oNbOfObjPlmid
  *  Number of plmid for a given object.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetNbOfPlmid( const CATString & iAliasOrTypeName,
                                int iLineNb,
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
  * if iAttrIdentifier == <aliasNodeName1> iObjectNb = 1, then olType == extType1, extType2.
  * if iAttrIdentifier == <aliasNodeName1> iObjectNb = 2, then olType == extType3.
  * @param iAliasOrTypeName
  * 
  * @param iObjectNb
  * 
  * @param olType
  *  list of extension found on object
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetPlmid( const CATString & iAliasOrTypeName,
                            int iLineNb,
                            int iObjectPosition,
                            CATPLMID & oPlmid ) = 0;

  /**
  *
  * <br><b>Role</b>:
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we have at the end the following table:
  * line number|<aliasNodeName1>               | <aliasNodeName2>
  * -----------|-------------------------------|------------------------------
  *     1      |   <plmidValue11> <ext3>       | <plmidValue21>
  *     2      |   <plmidValue12> <ext4, ext5> | <plmidValue22>
  *
  * if iAliasOrTypeName == <aliasNodeName1> and iLineNb == 1 , iObjectNb = 2, then olType == <ext3>.
  * if iAliasOrTypeName == <aliasNodeName1> and iLineNb == 2 , iObjectNb = 1, then olType == <ext4, ext5>.
  *
  * @param iAliasOrTypeName
  *  Formalism for iAliasOrTypeName:
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param iObjectPosition
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param olType
  *  List of extension on object.
  *  NO ORDER, NO ORDER, NO ORDER, NO ORDER: In example given above, you can retrieve <ext4, ext5> or <ext5, ext4>
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT ListExtension( const CATString & iAliasOrTypeName,
                                 int iLineNb,
                                 int iObjectNb,
                                 CATPLMTypeHSet& oTypeSet) = 0;

  /*
   * @Deprecated 
  */
  virtual HRESULT ListExtension( const CATString & iAliasOrTypeName,
                                 int iLineNumber,
                                 int iObjectNb,
                                 CATPLMTypeHArray& olType) = 0;


  /**
  * <br><b>Role</b>: Return the number of objets for a given line and a given column.
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve <attrName> on all nodes.
  * Suppose we have at the end the following table:
  * <aliasNodeName1>.<attrName> | <aliasNodeName2>.<attrName>
  * ----------------------------|----------------------------
  *         <attrNameValue>     | <attrNameValue1> <attrNameValue2>
  *
  * if iColumnName == <aliasNodeName1>.<attrName> and iLineNb == 1 , then oNbOfObjects == 1: <attrNameValue>
  * if iColumnName == <aliasNodeName2>.<attrName> and iLineNb == 1 , then oNbOfObjects == 2: <attrNameValue1> and <attrNameValue2>
  *
  * @param iColumnName
  *  Formalism for iColumnName:
  *  <aliasOrTypeName>.<attr>,
  *  <aliasOrTypeName>::<custoTypeName>.<attrName>,
  *  <aliasOrTypeName>.Ext(<typeNameExt>).<attr>,
  *  <aliasOrTypeName>::<custoTypeName>.Ext(<typeNameExt>).<attr>
  *  <aliasOrTypeName>,<attr>... are defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the line. iLineNb starts at 1.
  * @param oNbOfObjPerColumn
  *  Number of objects for a given line and a given column.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetNbOfObjects( const CATString & iColumnName,
                                  int iLineNb,
                                  int & oNbOfObjPerColumn ) = 0;

  /**
  *
  * <br><b>Role</b>: Returns value of attribute.
  * Example given: 
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2> (we talk about cardinality).
  * Suppose we only want to retrieve <attrName> on all nodes.
  * Suppose we have at the end the following table:
  * line number| <aliasNodeName1>.<attrName> | <aliasNodeName2>.<attrName>
  * -----------| ----------------------------|-------------------------------------
  *     1      |        <attrNameValue1>     | <attrNameValue11>, <attrNameValue12>
  *     2      |        <attrNameValue2>     | <attrNameValue21>, <attrNameValue22>
  *
  * if iAttrIdentifier == <aliasNodeName2>.<attrName>, if iLineNb == 2 , if iNbOfObjects == 2, then oAttrValue == <attrNameValue22>.
  *
  * @param iAttrIdentifier
  *  Formalism for iColumnName:
  *  <aliasOrTypeName>.<attr>,
  *  <aliasOrTypeName>::<custoTypeName>.<attrName>,
  *  <aliasOrTypeName>.Ext(<typeNameExt>).<attr>,
  *  <aliasOrTypeName>::<custoTypeName>.Ext(<typeNameExt>).<attr>.
  *  <aliasOrTypeName>,<attr>... defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param iObjectPosition
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oAttrValue
  *  The value of the attribute.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetAttributeValue(  const CATString & iColumnName,
                                      int iLineNb,
                                      int iObjectPosition,
                                      CATOmxKeyString & oAttrKey,
                                      CATOmxAny & oAttrValue ) = 0;


  /*********************************************************************************************
   *********************************************************************************************
   *********************************************************************************************
   * Ability to retrieve relations between objects using the following services:
   * GetNbOfRel(...)
   * GetRelStatus(...)
   * GetRelPointedComp(...).
   *
   * Suppose you have the following model:
   * POINTING1------>POINTED1.1      1
   *         |------>POINTED1.2      2
   *
   * POINTING2------>POINTED2.1      3
   *         |------>POINTED2.2      4
   *
   * POINTING3------>POINTED3.1      5
   *         |------>POINTED3.2      6
   *
   * Suppose you have the following table:
   * POINTING1, POINTING2, POINTING3 | POINTED1.1, POINTED1.2, POINTED2.1, POINTED2.2, POINTED3.1, POINTED3.2
   *
   * Suppose you have a path of instances between POINTING object and POINTED object.
   * To retrieve this path of instance, use GetRelPointedComp(...).
   * Notice: GetPlmid never return a complex plmid, it only returns the simple plmid stored by the object (POINTING or POINTED) or a list of simple id if you have more than one object per column.
   *
   * You have to different ways to retrieve the path of instances and the status :
   * Use the absolute position (1,2,3,4,5,6) with GetRelStatus and GetRelPointedComp.
   * or 
   * Use a mix iPositionPointing (1, 2, 3) (number of POINTING object) and iPositionRelation (1,2) (number of POINTED object per POINTING object) with GetRelStatus and GetRelPointedComp.
  *********************************************************************************************
  *********************************************************************************************
  *********************************************************************************************/

  /**
  *
  * <br><b>Role</b>: Returns Number of relations hold by pointing object.
  * Suppose we have executed the following navigation between <aliasNodeName1> and <aliasNodeName2> using the SR <relationName>.
  * <aliasNodeName1>-[<relationName>]><aliasNodeName2> (metamodel level)
  *
  * <aliasNodeName1> is the pointing object.
  * <aliasNodeName2> is the pointed object.
  *
  * Suppose <aliasNodeName1> always has 2 <aliasNodeName2>.
  * Suppose that for each line , we always have two instances of <aliasNodeName1>.
  *
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance1 of aliasNodeName1> -[<second instance of relationName>]> <second Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<second instance of relationName>]> <second Instance of aliasNodeName2>

  * In this example, GetNbOfRel returns: oNbOfRelation == 4
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  or
  *  <aliasOrTypeNamePointed>.<RelationName>!.<aliasOrTypeNamePointing>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param oNbOfRelation
  *  Number of relation hold by pointing object.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetNbOfRel( const CATString & iRelIdentifier,
                              int iLineNb,
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
  * Suppose that for each line , we always have two instances of <aliasNodeName1>.
  *
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]>  <first  Instance of aliasNodeName2>
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]>  <second Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * Suppose <first instance of relationName> is "synchronised" and "solved"
  * Suppose <second instance of relationName> is "not synchronised" and "broken"
  * Suppose <third instance of relationName> is "synchronised" and "solved"
  * Suppose <fourth instance of relationName> is "not synchronised" and "broken"
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, iObjectPosition = 1 , then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, iObjectPosition = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, iObjectPosition = 3 , then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, iObjectPosition = 4 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  or
  *  <aliasOrTypeNamePointed>.<RelationName>!.<aliasOrTypeNamePointing>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param iObjectPosition
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelStatus( const CATString & iRelIdentifier,
                                int iLineNb,
                                int iObjectPosition,
                                CATPLMMLRelationStatus & oRelationStatus,
                                CATPLMMLRelationSynchroStatus & oRelationSynchroStatus) = 0;

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
  * Suppose that for each line , we always have two instances of <aliasNodeName1>.
  *
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]>  <first  Instance of aliasNodeName2>
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]>  <second Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * Suppose <first instance of relationName> is "synchronised" and "solved"
  * Suppose <second instance of relationName> is "not synchronised" and "broken"
  * Suppose <third instance of relationName> is "synchronised" and "solved"
  * Suppose <fourth instance of relationName> is "not synchronised" and "broken"
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, iObjectPosition = 1 , then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, iObjectPosition = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, iObjectPosition = 3 , then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, iObjectPosition = 4 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  or
  *  <aliasOrTypeNamePointed>.<RelationName>!.<aliasOrTypeNamePointing>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param iObjectPosition
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param oListPlmid
  *  Suppose we have:
  *  A-A1-A2-A3-B
  *  Suppose A is the owner of the relation (Pointing object)
  *  Suppose B is not the owner of the relation (Pointed object)
  *  if <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>, we return A1-A2-A3-B
  *  if <aliasOrTypeNamePointed>.<RelationName>!.<aliasOrTypeNamePointing>, we return A3-A2-A1-A
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelPointedComp(  const CATString & iRelIdentifier,
                                      int iLineNb,
                                      int iObjectPosition,
                                      CATLISTV(CATPLMID) & oListPlmid) = 0;

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
  * Suppose that for each line , we always have two instances of <aliasNodeName1>.
  *
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance1 of aliasNodeName1> -[<second instance of relationName>]> <second Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<second instance of relationName>]> <second Instance of aliasNodeName2>
  * iPositionPointing = 1 gives oNbOfRelation == 2
  * iPositionPointing = 2 gives oNbOfRelation == 2
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  or
  *  <aliasOrTypeNamePointed>.<RelationName>!.<aliasOrTypeNamePointing>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
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
                              int iLineNb,
                              int iPositionPointing,
                              int & oNbOfRelation) = 0;

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
  * Suppose that for each line , we always have two instances of <aliasNodeName1>.
  *
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]> <second Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * Suppose <first instance of relationName> is "synchronised" and "solved"
  * Suppose <second instance of relationName> is "not synchronised" and "broken"
  * Suppose <third instance of relationName> is "synchronised" and "solved"
  * Suppose <fourth instance of relationName> is "not synchronised" and "broken"
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, if iPositionPointing == 1, iPositionRelation = 1, then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, if iPositionPointing == 1, iPositionRelation = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, if iPositionPointing == 2, iPositionRelation = 1, then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, if iPositionPointing == 2, iPositionRelation = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  or
  *  <aliasOrTypeNamePointed>.<RelationName>!.<aliasOrTypeNamePointing>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
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
  virtual HRESULT GetRelStatus( const CATString & iRelIdentifier,
                                int iLineNb,
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
  * Suppose that for each line , we always have two instances of <aliasNodeName1>.
  *
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]> <first  Instance of aliasNodeName2>
  * <instance1 of aliasNodeName1> -[<first instance of relationName>]> <second Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<third instance of relationName>]>  <third  Instance of aliasNodeName2>
  * <instance2 of aliasNodeName1> -[<fourth instance of relationName>]> <fourth Instance of aliasNodeName2>
  *
  * Suppose <first instance of relationName> is "synchronised" and "solved"
  * Suppose <second instance of relationName> is "not synchronised" and "broken"
  * Suppose <third instance of relationName> is "synchronised" and "solved"
  * Suppose <fourth instance of relationName> is "not synchronised" and "broken"
  *
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, if iPositionPointing == 1, iPositionRelation = 1, then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, if iPositionPointing == 1, iPositionRelation = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, if iPositionPointing == 2, iPositionRelation = 1, then oRelationSynchroStatus == "synchronised" and oRelationStatus == "solved"
  * if iRelIdentifier == <aliasNodeName1>.<relationName>.<aliasNodeName2>, if iLineNb == 1, if iPositionPointing == 2, iPositionRelation = 2 , then oRelationSynchroStatus == "not synchronised" and oRelationStatus == "broken"
  *
  * @param iRelIdentifier
  *  Formalism for iRelIdentifier:
  *  <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>
  *  or
  *  <aliasOrTypeNamePointed>.<RelationName>!.<aliasOrTypeNamePointing>
  *  <aliasOrTypeNamePointing>, <RelationName>, <aliasOrTypeNamePointed> defined in the navigation written in ML.
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
  * @param iPositionPointing
  *  The index of the iObjectNb. iObjectNb starts at 1.
  * @param iPositionRelation
  *  The index of the iPositionRelation. iObjectNb starts at 1.
  * @param oListPlmid
  *  Suppose we have:
  *  A-A1-A2-A3-B
  *  Suppose A is the owner of the relation (Pointing object)
  *  Suppose B is not the owner of the relation (Pointed object)
  *  if <aliasOrTypeNamePointing>.<RelationName>.<aliasOrTypeNamePointed>, we return A1-A2-A3-B
  *  if <aliasOrTypeNamePointed>.<RelationName>!.<aliasOrTypeNamePointing>, we return A3-A2-A1-A
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelPointedComp(  const CATString & iRelIdentifier,
                                      int iLineNb,
                                      int iPositionPointing,
                                      int iPositionRelation,
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
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
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
  virtual HRESULT GetPathFromRoot(  const CATString& iIdentifier,
                                    int iLineNb,
                                    int iObjectNb,
                                    CATLISTV(CATPLMID)& oListPlmid ) = 0;

  /**
  *
  * <br><b>Role</b>: Returns the list of Pair (name of column, position of Object in column)
  * Be careful! Suppose you have two nodes and a relation between these 2 nodes: SCA-[PointedOccurences]>TARGET.
  * Suppose you have a path of instance to cross to go from SCA to TARGET. oLPairAliasOrTypeNameObjPos only contains pair (SCA,position of object) and
  * pair (TARGET,position of object) (the real node).
  *
  * @param iIdentifier
  *  Formalism for iIdentifier: <aliasOrTypeName>
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iLineNb
  *   The index of the iLineNb. iLineNb starts at 1.
  * @param iObjectNb
  *   The index of the iObjectNb. iObjectNb starts at 1.
  * @param oLPairAliasOrTypeNameObjPos
  *   list of pair (iIdentifier,position of object)
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetPathFromRoot(  const CATString& iIdentifier,
                                      int iLineNb,
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
  * @param iLineNb
  *  The index of the iLineNb. iLineNb starts at 1.
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
  virtual HRESULT GetPathFromKey( const CATString& iIdentifier,
                                  int iLineNb,
                                  int iObjectNb,
                                  CATLISTV(CATPLMID)& oListPlmid ) = 0;

  /**
  *
  * <br><b>Role</b>: Returns the list of Pair (name of column, position of Object in column)
  * Be careful! Suppose you have two nodes and a relation between these 2 nodes: SCA-[PointedOccurences]>TARGET.
  * Suppose you have a path of instance to cross to go from SCA to TARGET. oLPairAliasOrTypeNameObjPos only contains pair (SCA,position of object) and
  * pair (TARGET,position of object) (the real node).
  *
  * @param iIdentifier
  *  Formalism for iIdentifier: <aliasOrTypeName>.
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iLineNb
  *   The index of the iLineNb. iLineNb starts at 1.
  * @param iObjectNb
  *   The index of the iObjectNb. iObjectNb starts at 1.
  * @param oLPairAliasOrTypeNameObjPos
  *   List of plmid crossed to go from Key to iIdentifier.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetPathFromKey( const CATString& iIdentifier,
                                  int iLineNb,
                                  int iObjectNb,
                                  CATPLMMLListPairAliasOrTypeNameObjPos& oLPairAliasOrTypeNameObjPos ) = 0;

};

#endif
