/* -*-C++-*- */

#ifndef CATCVMContainer_H
#define CATCVMContainer_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMContainer
//
// Collaborative Variational Modelling (CVM) Container class
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2006    Creation                         Alex State
// 07:08:20 FDN refonte de la gestion des attr ref : on a maintenant une liste statique commune
//              a tous les containers, contenant les attr ref (_AttrRefList dans CATCVMContainer.cpp)
//              Chaque container peut cependant demander quels sont les attr ref qu'il utilise
//              grace aux listes _UseCountValue et _UseCountContainer de CATCVMAttrRef.h
//              Un Usecount global (_UseCount) est aussi disponible dans CATCVMAttrRef.h
//              Par ailleurs, _UnstreamedRef contient temporairement les attr ref lues dans l'unstream
//              (duree de vie = celle de l'unstream)
//===================================================================
#include "CATBaseUnknown.h"

#include "CATCVMSysObjects.h"
#include "CATCVMSession.h"

#include "CATBoolean.h"
#include "ListPOfCATCVMSystem.h"
#include "ListPOfCATCVMRelation.h"
#include "ListPOfCATCVMObject.h"
#include "ListPOfCATCVMAttrRef.h"
#include "CATCVMAttributeDef.h"
#include "CATCVMDef.h"
#include "CATDataType.h"
#include "CATCGMNewArray.h"
#include "CATErrorDef.h"

class CATCVMObject;
class CATCGMStream;
class CATCVMSysStream;
class CATCVMColorRef;
class CATCVMComponent;
class CATSysSimpleHashTable;
class CATCVMReference;

class ExportedByCATCVMSysObjects CATCVMContainer : public CATBaseUnknown
{
  //------------------------------------------------------------------------------
  // Component declaration for ObjectModeler
  //------------------------------------------------------------------------------
public:
  CATDeclareClass;

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
protected:
  CATCVMContainer(CATBaseUnknown *iFederator = NULL);

  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
protected:
  virtual ~CATCVMContainer();

  //------------------------------------------------------------------------------
  // Clean up
  //------------------------------------------------------------------------------
public:
    //modif JMA : virtual
  virtual void CleanUp();

  CATBoolean IsDirty();
  void SetDirtyState(CATBoolean iIsDirty=FALSE);
  void AddDirtyValue(CATLONG32  iDirty_increment);

  //------------------------------------------------------------------------------
  // Create new container of same type as this
  //------------------------------------------------------------------------------
public:
  virtual CATCVMContainer *CreateNewContainerOfSameType(CATCVMReference *iFederator);

  //------------------------------------------------------------------------------
  // Get the number of systems
  //------------------------------------------------------------------------------
public:
  int GetNbSystems();

  //------------------------------------------------------------------------------
  // Get the system for a given index
  //------------------------------------------------------------------------------
public:
  CATCVMSystem *GetSystem(int iIndex);

  //------------------------------------------------------------------------------
  // Add a system
  //------------------------------------------------------------------------------
public:
  void AddSystem(CATCVMSystem *iSystem, CATBoolean IsNew=FALSE );

  //------------------------------------------------------------------------------
  // Remove a system
  //------------------------------------------------------------------------------
public:
  void RemoveSystem(int iIndex);

  //------------------------------------------------------------------------------
  // Remove a system
  //------------------------------------------------------------------------------
public:
  void RemoveSystem(CATCVMSystem *iSystem);

  //------------------------------------------------------------------------------
  // Get all the relations under all systems
  //------------------------------------------------------------------------------
public:
  void GetAllRelations(ListPOfCATCVMRelation &oRelationList, CATBoolean iOnlyActive);

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);
public:
  virtual CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Set re-use component
  //------------------------------------------------------------------------------
public:
  HRESULT SetReuseComponent(CATCVMComponent *iReuseComponent);

  //------------------------------------------------------------------------------
  // Get re-use component
  //------------------------------------------------------------------------------
public:
  CATCVMComponent *GetReuseComponent();

  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  void Dump(ostream * iStream=0L) const;
  // iUnfold : 0 = reuse dump, 1 = unfold dump
  void GraphDump(ostream * iStream=0L, ListPOfCATCVMObject * iHighLight=0, int iUnfold=0) const;
  
  //------------------------------------------------------------------------------
  // Attribute Ref APIs
  //------------------------------------------------------------------------------
  // Get nb of attribute references that are used
  // ioListOfUsed : Optional list to fill with the used attribute references (the list is reseted each time)
  // iType        : Optional type of the attribute we are looking for
  CATULONG32      GetNbAttributeRefUsed(ListPOfCATCVMAttrRef * ioListOfUsed=NULL, CATCVMAttributeType iType=CATCVMAttrUnknownType);
  // Get nb of all attribute references
  CATULONG32      GetNbAttributeRef();
  
  void AddAttributeRefReadInUnstream(CATCVMAttrRef * iRef);
  CATCVMAttrRef * GetAttributeRefFromPosInUnstream(CATULONG32 iPos);
  // Get all objects used by an attribute reference in the container
  CATULONG32      GetNbCVMObjectsUsedByAttributeRef(CATCVMAttrRef * iAttrRef, ListPOfCATCVMObject * ioListOfObjects);
  // Erase from the list all unused attribute references
  CATULONG32      PurgeUnusedAttributes();
  // Copy attributes ref from a container to an other container to the current one
  // This copy includes comparision in order to avoid duplicata
  // returns the number of attribute refs added
  CATULONG32      CopyAttrRefFromContainer(CATCVMContainer * iFromContainer);

  CATULONG32      GetCVMAttrRefListSize();
  void            GetCVMAttrRefList(ListPOfCATCVMAttrRef &oCVMAttrRefList);
  CATCVMAttrRef * GetSameCVMAttrRef(CATCVMAttrRef * iAttrRef);
  CATCVMAttrRef * GetAttrRefFromID(CATUnicodeString iID);
  void            AddAttributeRef(CATCVMAttrRef * iAttrRef); 
  CATBoolean      RemoveAttributeRef(CATCVMAttrRef * iAttrRef); // DO NOT USE EXEPT CVM PEOPLE !!!
 // Deprecated
  CATCVMColorRef * GetDefaultColor();

  
  //------------------------------------------------------------------------------
  // Get new tag
  //------------------------------------------------------------------------------
public:
  CATULONG32 GetNewTag();

  //------------------------------------------------------------------------------
  // Stream/Unstream
  //------------------------------------------------------------------------------
public:
  virtual void    Stream( CATCVMSysStream* Str,CATBoolean iDebug=FALSE)   = 0 ;
  virtual void    UnStream( CATCVMSysStream* Str, CATBoolean iSuppressMainComponent=FALSE,
                            CATBoolean iKarcherIsolatedVertices=FALSE) = 0 ;

  CATCVMObject* CreateCVMObjectFromStream (CATCVMSysStream* Str);
  CATCVMObject* FindObjectFromTag (CATULONG32 iTag);


//------------------------------------------------------------------------------
  // the containers are chained (only CVMGeocontainer)
  //------------------------------------------------------------------------------
  virtual void SetNext(CATCVMContainer* next );
  virtual void SetPrev(CATCVMContainer* previous);

  virtual CATCVMContainer* GetNext (CATCVMContainer* container = NULL);
  virtual CATCVMContainer* GetPrev(CATCVMContainer* container = NULL);

  virtual void AddContainer(CATCVMContainer* icontainertoadd, CATCVMContainer* iContainerNext = NULL);
  virtual void RemoveContainer(CATCVMContainer* icontainertoremove);


protected :
  virtual CATCVMObject * CreateObjectfromType (int iType);
  virtual CATCVMAttrRef * CreateAttrRefFromType (CATULONG32 iType);
  virtual CATULONG32 GetMyAttrRefList(ListPOfCATCVMAttrRef * ioListe);

  //CATULONG32 GetPosInList(CATCVMAttrRef * iAttrRef);
  CATULONG32 ReorderAttributes(int deprecated, CATBoolean iPurgeUnused = TRUE);

public : 
  int AppendHashRef (CATCVMReference * iRef);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
protected :

  CATULONG32                _MaxTag;
  CATCVMComponent         * _ReuseComponent;
  CATSysSimpleHashTable   * _pReferenceHashTable;

private:

  CATCVMContainer         * _Next;
  CATCVMContainer         * _Prev;

  CATCVMSession           * _CVMSession;
  ListPOfCATCVMSystem       _SystemList;
  CATCVMColorRef          * _DefaultColor;
  ListPOfCATCVMAttrRef      _UnstreamedRef;// List of all the Attribute Ref read in unstream
  CATBaseUnknown          * _Federator;
  
  CATLONG32                 _DirtyValue;
  CATBoolean                _DirtyState;
};
#endif
