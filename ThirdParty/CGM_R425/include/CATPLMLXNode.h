/* -*-c++-*- */
#ifndef CATPLMLXNode_H
#define CATPLMLXNode_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMLXNode" Light XML Node
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//
#include "CATUnicodeString.h"
#include "CATPLMModelBuilder.h"
#include "CATISAXContentHandler.h"
#include "CATOmxArray.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATPLMOmxCollections.h"
#include "CATOmxVector.h"
#include "CATOmxSR.h"

class CATPLMUTXPrinter;
class CATIXMLPPWriter_var;

class ExportedByCATPLMModelBuilder CATPLMLXNode : public CATBaseUnknown
{
  friend class CATPLMLXContentHandler;

  CATDeclareClass;

public:
  enum class CATPLMUTXMLNExistency { Mandatory, Optional };
  enum class CATPLMUTXType { Document, Tag, Processing, Comment, Data, ALL };

  CATPLMLXNode(CATPLMUTXType iType = CATPLMUTXType::Document, CATBoolean iWithSubsitution = FALSE);
  CATPLMLXNode(const CATPLMLXNode&);
  CATPLMLXNode& operator=(const CATPLMLXNode&);
  ~CATPLMLXNode();

  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  void CleanRecursively();

  CATOmxSR<CATPLMLXNode> AddNode(CATPLMUTXType iType, const char* iTag = NULL, const char* iValue = NULL);
  HRESULT AddNode(CATOmxSR<CATPLMLXNode> iNode);
  void SetValues(const CATUnicodeString& iTag, const CATUnicodeString& iValue);
  void AddAttribute(const CATUnicodeString& iTag, const CATUnicodeString& iValue);

  static CATOmxSR<CATPLMLXNode> Load(const CATUnicodeString& iFile, CATBoolean iWithSubsitution);
  static CATOmxSR<CATPLMLXNode> LoadStream(const CATUnicodeString& iStream, CATBoolean iWithSubsitution);

  HRESULT Save(const CATUnicodeString& iFile) const;

  CATPLMUTXType             GetType() const;
  const CATUnicodeString& GetTag() const;
  const char* GetValue(CATPLMUTXMLNExistency iExistency = CATPLMUTXMLNExistency::Mandatory) const;
  const char* GetAttrValue(const char* iAttrName, CATPLMUTXMLNExistency iExistency = CATPLMUTXMLNExistency::Mandatory) const;
  HRESULT                   Next(int& ioIndice, CATOmxSR<CATPLMLXNode>& oNode, CATPLMUTXType iFilter = CATPLMUTXType::ALL) const;

  int GetNumberOfAttributes() const;
  HRESULT GetAttributeAt(int iIndex, CATUnicodeString& oAttrName, CATUnicodeString& oAttrValue) const;

  HRESULT IsEqual(const CATOmxSR<CATPLMLXNode> iNode, CATOmxSR<CATPLMLXNode>& oErrorNode1, CATOmxSR<CATPLMLXNode>& oErrorNode2) const;
  HRESULT Dump(CATUnicodeString& oString);

private:
  HRESULT SaveNode(CATIXMLPPWriter_var ioWriter) const;
  void Substitute(CATUnicodeString& ioString);
  CATBoolean SmartCompare(const CATUnicodeString& iStr1, const CATUnicodeString& iStr2) const;
  void           SetFather(CATPLMLXNode*);
  HRESULT IsEqual(const CATOmxSR<CATPLMLXNode> iNode) const;

  CATPLMUTXType        type;
  CATUnicodeString   tag;
  CATUnicodeString   value;

  CATOmxArray<CATPLMPairCUSCUS> attrs;
  CATOmxVector<CATPLMLXNode> nodes;
  CATOmxSR<CATPLMLXNode> father;
  CATBoolean withSubstitution;
};

class CATPLMLXContentHandler : public CATISAXContentHandler
{
private:
  CATOmxSR<CATPLMLXNode> rootNode, currentNode, previousNode;
  CATBoolean underParsing, parsingFirstNode, withSubstitution;
public:
  CATPLMLXContentHandler(CATBoolean iWithSubsitution);
  ~CATPLMLXContentHandler();

  CATOmxSR<CATPLMLXNode> GetRootNode();
  CATPLMLXNode::CATPLMUTXType GetElementType(const CATUnicodeString&);

  HRESULT StartDocument();
  HRESULT EndDocument();
  HRESULT StartElement(
    const CATUnicodeString& iURI,
    const CATUnicodeString& iLocalName,
    const CATUnicodeString& iQualifiedName,
    const CATISAXAttributes_var& iAttributes);
  HRESULT EndElement(
    const CATUnicodeString& iURI,
    const CATUnicodeString& iLocalName,
    const CATUnicodeString& iQualifiedName);
  HRESULT Characters(
    const CATUnicodeString& iCharacters);
  HRESULT IgnorableWhiteSpace(
    const CATUnicodeString& iCharacters);
  HRESULT ProcessingInstruction(
    const CATUnicodeString& iTarget,
    const CATUnicodeString& iData);
  HRESULT SetDocumentLocator(
    const CATISAXLocator_var& iLocator);
  HRESULT StartPrefixMapping(
    const CATUnicodeString& iPrefix,
    const CATUnicodeString& iURI);
  HRESULT EndPrefixMapping(
    const CATUnicodeString& iPrefix);
  HRESULT SkippedEntity(
    const CATUnicodeString& iName);
};


template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMLXNode>::manager();

#endif
