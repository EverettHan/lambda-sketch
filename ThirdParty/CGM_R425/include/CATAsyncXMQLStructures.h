#ifndef CATAsyncXMQLStructures_H
#define CATAsyncXMQLStructures_H

#include "CATPLMxMQL.h"

#include "CATAsyncXMQLTypes.h"
#include "CATAsyncXMQLCollections.h"

#include "CATOmxOSet.h"
#include "CATOmxAny.h"
#include "CATOmxKeyString.h"

#include "CATA5Parser.h"
#include "CATPLMQueryFilterEnum.h"
#include "CATBinary.h"
#include "CATxMQLProcedure.h"
#include "CATOmxJsonObject.h"
#include "CATAsyncBasicTypes.h"

class CATAsyncXMQLRequest;

namespace xMQLRequest
{
  // xMQLRequest::UTypeArgs
  // -------------------------------------
  struct UTypeArgs
  {
    CATUnicodeString Single;
    CATAsyncXMQLMultiStringMap Multi;
  };

  // xMQLRequest::UArrayArgs
  // -------------------------------------
  struct UArrayArgs
  {
    CATOmxArray<CATUnicodeString> Single;
    CATAsyncXMQLMultiStringArrayMap Multi;
  };

  // xMQLRequest::UuidList
  // -------------------------------------
  class UuidList : public CATOmxArray<CATUuid>
  {
    friend class ::CATAsyncXMQLRequest;
    mutable ListId _listId;
  public:
    int GetId() const { return _listId; }
    UuidList() : _listId(0) {};
  };

  // xMQLRequest::FileInfo
  // -------------------------------------
  struct FileDescriptor
  {
    CATUnicodeString Format;
    CATUnicodeString Filename;
    CATUnicodeString CorrelationId;
  };

  struct BOProxy : FileDescriptor
  {
    CATUnicodeString PhysicalID;
    CATUnicodeString Path;
  };

  struct FileInfo : FileDescriptor
  {
    CATUnicodeString Url;
  };

  // xMQLRequest::ScriptContent
  // -------------------------------------
  struct ScriptContent
  {
    CATBoolean File;
    CATUnicodeString Content;
    CATOmxKeyValueBlock Params;
    ScriptContent() :File(FALSE) {}
  };

  // xMQLRequest::Multi
  // -------------------------------------
  class ExportedByCATPLMxMQL Multi
  {
    int _size;
    int _maxSize;
    Args* _args;

  public:
    Multi();
    Multi(const Multi&);
    virtual ~Multi();
    Multi& operator=(const Multi&);
    void Append(const Args& iArgs);
    const Args& operator[](int i) const;
    Args& GetW(int i);
    int Size() const { return _size; }
    bool IsEmpty() const { return !Size(); }
    void SortByOidsCount();
  };

  // xMQLRequest::Elem
  // -------------------------------------
  struct Elem
  {
    Elem();
    const CATUuid* Oid;
    const CATOmxArray<CATUuid>* OidsList;
    const CATOmxOSet<CATUuid>* OidsSet;
    Args* xMQLArgs;
    ListId Id;
  };

  // xMQLRequest::StoreInfos
  // -------------------------------------
  class ExportedByCATPLMxMQL StoreInfos
  {
    CATOmxAny _StoreInfos; // CATOmxArray
  public:

    StoreInfos() { _StoreInfos.BuildDefaultValue(omx_any, TRUE); }

    CATOmxAny GetAsAny() const
    {
      return _StoreInfos;
    }

    void AddData(const CATUnicodeString& iStore,
      const CATUnicodeString& iLocation,
      const CATOmxArray<xMQLRequest::FileInfo>& iFileInfos);

    void AddData(const CATUnicodeString& iStore,
      const CATOmxArray<xMQLRequest::BOProxy>& iBOProxys);
  };

  // xMQLRequest::Args
  // -------------------------------------
  struct ExportedByCATPLMxMQL Args
  {
    Args();

    // -- Methods --
    int OidsCount() const;

    /*
    * Returns the CsvRow Definition.
    * Returned pointer is NOT addrefed.
    * May return NULL.
    */
    CATA5::CsvRowDefinition* GetCsvRowDefinition() const;

    /*
    * Sets the CsvRow Definition.
    */
    void SetCsvRowDefinition(CATA5::CsvRowDefinition* ipCsvRowDefinition);

    void SetObjectIdsList(const UuidList& iObjectIdsList);

    const UuidList& GetObjectIdsList() const;

    xMQLRequest::UuidList& ModifyObjectIdsList();

    /*
    * Return true if this Args supports PPrime:
    *   - Basic or Expand query
    *   - Types from Product modeler (IsKindOf(VPMReference) or IsKindOf(VPMInstance))
    */
    bool IsPPrimeSupported() const;

    // -- Data struct args --
    // Generic XMQL args
    EMode Mode; // Default: Print
    EType Type; // Default: NoType
    ETypeOfOwnerOfPath TypeOfOwnerOfPath;
    ESearchMode SearchMode; // Default: QueryOnServer
    CATOmxKeyString ObjectsType;
    CATOmxArray<CATUnicodeString> Vaults;
    CATUnicodeString Body;
    CATOmxArray<CATOmxUTF8String> _listRoleCategoryFilter;
    UTypeArgs WhereClause;
    CATOmxArray<CATUnicodeString> OrderByClauses;
    UArrayArgs SelectClause;
    UArrayArgs SelectClauseOfPathType;
    // Specific Expand XMQL args
    int ExpandLevel; // Default: 0
    ExpandDirection::Mode ExpandDir; // Default: Defaults
    CATAsyncXMQLMultiStringSetBoolPairMap NavTypes;
    // Specific structure for Decorate using Iterative Filter
    CATAsyncXMQLMultiIterModeStringSetHMapHMap IterativeFilterTypesForDecorate;
    CATOmxArray<CATUuid> RootPath;
    CATOmxArray<CATBinary> ConfigFiltersBin;
    UuidList FixedPointsList;
    // Specific FCS ticket (only checkout) and MassiveLink
    CATUnicodeString MCSUrl;
    StoreInfos Stores;
    // Specific FlatTable
    CATOmxKeyString FlatTableName;
    // Template Content
    ScriptContent TemplateContent;
    // Multi requests argument
    Multi MultiRequests;
    // Specific Query Path XMQL args (here for data padding)
    CATOmxArray<CATOmxKeyString> lPathType;
    UuidList PathFilterObjIdsList;
    EPathFilter PathFilter; // Default: NoFilter
    CATUnicodeString Dump; // Default: "|"

    // Attribute related to WipMid (JSProcedure)
    CATxMQLProcedure Procedure; // Procedure to call (name + version)
    CATOmxJsonObject JsonParams; // Key -> param name, Value -> JSON

    // -- Boolean flags, for struct data aligment --
    // Generic XMQL args
    CATBoolean ArchiveVault; // Default: FALSE
    CATBoolean Escape; // Default: FALSE
    // Specific Expand XMQL args
    CATBoolean PreventDuplicates; // Default: FALSE
    CATBoolean StaticMapping; // Default: FALSE
    // Specific Query Path XMQL args
    // Bypass for "dump tcl" bug -> remove this attribute when the MQL bug has been fixed.
    CATBoolean NotSubstitute; // Default: FALSE
    // Specific FCS ticket (only checkout)
    CATBoolean TicketZipped; // Default: FALSE
    CATUnicodeString view;

    // Result format
    CATAsyncAnswer_Type answerFormat;

    // Temporary for Repository investigation....
    CATOmxArray<CATUnicodeString> PParams;
    CATOmxArray<CATUnicodeString> PValues;
    CATUnicodeString PAnyParam;
    CATOmxAny PAnyValue;

  private:
    // TCL/Json result format
    CATOmxSR<CATA5::CsvRowDefinition> spCsvRowDefinition;
    // 
    UuidList _ObjectIdsList;

#ifndef CATIAR420
  public:
    // DEPRECATED ATTRIBUTES: DO NOT USE THEM
    CATOmxSR<CATA5::CsvRowDefinition> spTCLDefinition; // TODO CME4: DEPRECATED, USE GetCsvRowDefinition/SetCsvRowDefinition INSTEAD, WILL BE REMOVED SOON. 17/01/2018: ONLY USED BY EXTERNAL FW VisuPLMHelpers.
    UuidList ObjectIdsList;
#endif
  };
};
#endif
