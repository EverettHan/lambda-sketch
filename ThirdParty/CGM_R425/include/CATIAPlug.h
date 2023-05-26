/* CATIAPlug.h : COPYRIGHT DASSAULT SYSTEMES 1995 */
/**
* @level Private 
* @usage U1
*/
#ifndef CATIAPlug_h
#define CATIAPlug_h

/*******************************************
 * THIS CODE MUST BE THE SAME IN V5 AND V6 *
 *     PLEASE REPORT MODIFICATIONS         *
 *******************************************/

#include "CATObject.h"
#include "AC0CATPL.h"
#include "CATIOmbPlug.h"
#include "CATBooleanDef.h"
#include "CATOmxIter.h"
#include "CATOmxArray.h"
#include "CATUnicodeString.h"
#include "CATOmxSR.h"
#include "CATUuid.h"

class CATIAPlug ;
class CATDocument ;
class CATIAEntity ;
class CATIAEnable;
class CATStreamArea;

ExportedByAC0CATPL extern void synchronize( CATIAPlug* plug, CATIAEntity*const entity ) ;

class CATOmcISData;

class ExportedByAC0CATPL CATIAPlug : public CATIOmbPlug
{
public:
  static CATMetaClass* MetaObject();
private:
  static CATBaseUnknown* CreateItSelf();
  static const CLSID& __stdcall ClassId();	
  static const char* __stdcall ClassName();	
  static CATIAPlug* CreateCATIAPlug(const char* type, const char* superType=NULL, CATBoolean iTestContType=TRUE);
public:
  virtual ~CATIAPlug () ;

  virtual int IsNull() const ;

  //ACHTUNG, arguments are totally  ridiculous (const int/const char* const ....), but some *%#!!?? use this directly instead of CATIACreateRootContainer...
  static CATIAPlug* CreateContainer(const CATClassId Type,CATIAPlug* const father,const int AggregateToFather=1,const CATClassId SType="",CATDocument* iDoc=NULL,int iAsRootContainer=0,int iCreateNotLoaded=0);

  //  Petit service pour CCP dedie a la copie d'un paquet d'entites
  // ---------------------------------------------------------------
  int Copy( const int& nbelt,CATIAPlug* const tab_Plug[],CATIAPlug*       tab_dupPlug[] ) ;

  // --------------------------------------------------------
  //  La cle d'adressage des entites du modeleur de donnees,
  //  dont la classe est amener a se developper par ...
  // --------------------------------------------------------
  CATIAEntity* GetEntity() ;

  //  services dedies a une synchro interne avec le modeleur de donnees
  // -------------------------------------------------------------------
  void Synchronise( CATIAEntity*const associate = NULL ) ;

  //CATIOmbPlug implementation
  virtual CATDocument* GetDocument() const;
  virtual HRESULT SetDocument(CATDocument* iDoc);
  virtual CATIOmbPlug_var GetParentContainer();

  virtual HRESULT __stdcall QueryInterface(const IID &iIID,void **oPPV);
  virtual CATBaseUnknown* QueryInterface(CATClassId iInterface) const;
  virtual ULONG   __stdcall AddRef();
  virtual ULONG   __stdcall Release();

  static CATMetaClass* CATCompoundContMetaObject();
  static CATMetaClass* CAT_ModelMetaObject();
  static CATMetaClass* CATContainerMetaObject();
  static CATMetaClass* CATElementMetaObject();

  static const char* const UnknownObjectType;

  enum ContainerType
  {
    UnknownContType = 0x0,
    V4 = 0x1,
    Applicative = 0x2,
    CAT_Model = V4 | 0x4,
    Root = V4 | 0x8,
    DirectRootChild = V4 | 0x10,
    DirectCompoundChild = Applicative | 0x20,
    Compound = DirectRootChild | 0x40,
  };

  ContainerType GetContainerType() const;

  LoadState GetLoadState() const;
  void SetLoadState(LoadState state);

  LoadState GetRecursiveLoadState() const;
  void SetRecursiveLoadState(LoadState state);

  HRESULT LoadV4Container();

  virtual CATOmxIter<CATIOmbPlug> GetSubContainers() const;

  inline CATOmxIter<CATIAPlug> GetAggregatedContainers() const {return GetAggregatedElements(TRUE);}

  CATOmxIter<CATIAPlug> GetAggregatedElements(CATBoolean iOnlyContainer=FALSE) const;

  CATOmxIter<CATIAPlug> RecursivelyGetAggregatedContainers(CATBoolean iIncludeThis=FALSE,CATBoolean iSkipCompoundChildren=FALSE) const;

  CATIAPlug* GetParent() const;

  inline CATBoolean IsAContainer() const {return m_isAContainer==1;}

  inline CATOmxArray<CATUnicodeString> GetStoredProjectFlags() const {return m_storedProjectFlags;}
  void SetStoredProjectFlags(CATOmxArray<CATUnicodeString>& iProjectFlags);

  CATOmxSR<CATOmcISData> GetISData() {return m_ISData;}
  inline void SetISData(const CATOmcISData* ISData) {m_ISData = ISData;}

  enum PersistencyExitType {BeforeLoad,AfterLoad,BeforeSave,AfterSave};

  CATBoolean CallPersistencyExit(PersistencyExitType type);

  static CATOmxSR<CATIAPlug> GetDocumentRootContainer(CATDocument* iDoc);

  HRESULT CATIStreamContainer(CATStreamArea*& area,CATOmxSR<CATError>& oError);
  HRESULT CATIUnstreamContainer(CATStreamArea& area,CATOmxSR<CATError>& oError);

  void ReportStreamErrorForDebug(CATBoolean iLoad,HRESULT hr,CATError* error);
  void ReportStreamErrorForDebug(CATBoolean iLoad, HRESULT hr, const CATUnicodeString& error);

  HRESULT GetUuid(CATUuid& oUuid) const;
  

  inline CATBoolean HasNoStorage() const {return m_hasNoStorage;}
  inline void SetHasNoStorage(CATBoolean val) {m_hasNoStorage = val;}
  HRESULT RegisterForRemove();
  inline virtual CATBoolean IsUnderRemove() const {return m_registeredForRemove ? TRUE : FALSE;}
  virtual HRESULT OnDocumentStreamStart();
  // return S_FALSE if no rollback necessary
  virtual HRESULT OnDocumentStreamEnd(CATBoolean iErrorOccurred);
private:
  CATOmxSR<CATOmcISData> m_ISData;
  CATOmxSR<CATOmcISData> m_ISDataForRollback;
  CATDocument* m_document;
  CATIAEntity*  _CatiaEntity;
  CATOmxArray<CATUnicodeString> m_storedProjectFlags;
  CATOmxArray<char> m_stream;

#ifdef _WINDOWS_SOURCE
#pragma pack(push,1) // optimize packing
#endif
  ContainerType m_containerType:8;
  LoadState m_loadState:4;
  LoadState m_recursiveLoadState:4;
  unsigned int m_isAContainer:1;
  unsigned int m_hasNoStorage:1;
  unsigned int m_creationTagForCGRContDelete:1;
  unsigned int m_registeredForRemove:1;
  unsigned int m_padding:12;
  unsigned int m_tag;//debug only !
#ifdef _WINDOWS_SOURCE
#pragma pack(pop) // optimize packing
#endif

private :
  ContainerType ComputeContainerType() const;
  friend class CATIAEnable;
  CATIAPlug(const char* type,const char* superType) ;
  CATIAPlug();
  CATIAPlug(const CATIAPlug& );
  CATIAPlug& operator= (const CATIAPlug& from);
  static CATIAPlug* CreateContainerForLoad( const char*  Type,CATIAPlug* father,CATBoolean AggregateToFather,const char* SType,CATDocument* iDoc);

} ;

#endif
