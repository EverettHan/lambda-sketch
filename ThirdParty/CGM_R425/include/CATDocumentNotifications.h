/* -*-c++-*- */
//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999-2002
//===========================================================================
//
// class CATDocumentNotifications
//
//===========================================================================
//
// Usage Notes:
//   
//
//===========================================================================
// Feb. 99   Creation                                   Benoit Paget
// Nov. 1999 Modification                             OGM
//           Ajout de CATInitializeDocumentNotification
// Nov. 2002 Modification                             RJA
//           Ajout des notifs CATLoadContainerNotification et CATUnLoadContainerNotification (necessaires au plan BRep Mode)
//===========================================================================
#ifndef CATDocumentNotifications_H
#define CATDocumentNotifications_H

/**
* @level Protected 
* @usage U1
*/

#include "AC0XXLNK.h"
#include "CATIAV5Level.h"
#include "CATNotification.h"
#include "CATUnicodeString.h"
#include "CATDocument.h"
#include "CATIContainer.h"

class CATUuidTable;

class ExportedByAC0XXLNK CATOmbBaseNotification : public CATNotification
{
public:
  inline CATOmbBaseNotification() {}
  virtual int IsAKindOf(const char *) const;
  virtual const char* IsA() const=0;
  virtual ~CATOmbBaseNotification();
private:
  CATOmbBaseNotification(const CATOmbBaseNotification&);
  CATOmbBaseNotification& operator=(const CATOmbBaseNotification&);
};

class ExportedByAC0XXLNK CATDocumentNotification : public CATOmbBaseNotification
{
public:
  CATDocumentNotification():_document(NULL) {}
  virtual ~CATDocumentNotification();
  virtual const char* IsA() const;
  static  const char* ClassName();
  void    FeedDocument(CATDocument * iDocument);
  CATDocument * GiveDocument();

protected :      
  CATDocument * _document;
private:
  CATDocumentNotification(const CATDocumentNotification&);
  CATDocumentNotification& operator=(const CATDocumentNotification&);
};

#ifdef __OMB_EXPORT_USELESS_NOTIFICATIONS_SYMBOLS__
#define CATOmbDeclareNotificationWithoutDefaultConstructor(OmbNotificationName)\
public:\
  virtual ~OmbNotificationName();\
  virtual const char* IsA() const;\
  static  const char* ClassName();\
  virtual int IsAKindOf(const char *) const;\
private:\
  OmbNotificationName(const OmbNotificationName&);\
  OmbNotificationName& operator=(const OmbNotificationName&)
#else
#define CATOmbDeclareNotificationWithoutDefaultConstructor(OmbNotificationName)\
public:\
  virtual ~OmbNotificationName();\
  virtual const char* IsA() const;\
  static  const char* ClassName();\
private:\
  OmbNotificationName(const OmbNotificationName&);\
  OmbNotificationName& operator=(const OmbNotificationName&)
#endif

#define CATOmbDeclareNotification(OmbNotificationName)\
public:\
  OmbNotificationName();\
  CATOmbDeclareNotificationWithoutDefaultConstructor(OmbNotificationName)

#ifndef CATIAR213
class ExportedByAC0XXLNK CATCreateDocumentNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATCreateDocumentNotification);
};
#endif

class ExportedByAC0XXLNK CATBeforeDocInitNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATBeforeDocInitNotification);
};


class ExportedByAC0XXLNK CATAfterDocInitNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATAfterDocInitNotification);
};


class ExportedByAC0XXLNK CATInitializeDocumentNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATInitializeDocumentNotification);
};


class ExportedByAC0XXLNK CATRemoveDocumentNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATRemoveDocumentNotification);
};


class ExportedByAC0XXLNK CATLinkAdditionNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATLinkAdditionNotification);
};


class ExportedByAC0XXLNK CATLinkDeletionNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATLinkDeletionNotification);  
};


class ExportedByAC0XXLNK CATNameModificationNotification : public CATDocumentNotification
{
public:
  CATNameModificationNotification();
  CATNameModificationNotification(const CATNameModificationNotification&);
  CATNameModificationNotification& operator=(const CATNameModificationNotification&);
  virtual ~CATNameModificationNotification();
  virtual const char* IsA() const;
  static  const char* ClassName();
#ifdef __OMB_EXPORT_USELESS_NOTIFICATIONS_SYMBOLS__
  virtual int IsAKindOf(const char *) const;
#endif
  void FeedOldName(const CATUnicodeString& iOldName);
  void FeedNewName(const CATUnicodeString& iNewName);
  CATUnicodeString GiveOldName();
  CATUnicodeString GiveNewName();

protected :      
  CATUnicodeString _oldName;
  CATUnicodeString _newName;
};

#ifndef CATIAR213
class ExportedByAC0XXLNK CATEditorModificationNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATEditorModificationNotification); 
};
#endif

class ExportedByAC0XXLNK CATOmbContainerNotification: public CATDocumentNotification
{
protected: 
  CATIContainer_var _cont;
public:
  CATOmbContainerNotification();
  void FeedContainer(CATBaseUnknown *iCont);
  CATIContainer * GiveContainer();
  virtual ~CATOmbContainerNotification();
private:
  CATOmbContainerNotification(const CATOmbContainerNotification&);
  CATOmbContainerNotification& operator=(const CATOmbContainerNotification&);
};

class ExportedByAC0XXLNK CATContCreationNotification : public CATOmbContainerNotification
{
  CATOmbDeclareNotification(CATContCreationNotification); 
#ifdef __OMB_EXPORT_USELESS_NOTIFICATIONS_SYMBOLS__
public:
  CATIContainer* GiveContainer();
#endif
};


class ExportedByAC0XXLNK CATContDeletionNotification : public CATOmbContainerNotification
{
  CATOmbDeclareNotification(CATContDeletionNotification); 
};

class ExportedByAC0XXLNK CATContUserIdModificationNotification : public CATOmbContainerNotification
{
  CATOmbDeclareNotification(CATContUserIdModificationNotification);
public:
  CATContUserIdModificationNotification(const CATUnicodeString& iOldUserId, const CATUnicodeString& iNewUserId);

  CATUnicodeString GetOldUserId();
  CATUnicodeString GetNewUserId();
#ifdef __OMB_EXPORT_USELESS_NOTIFICATIONS_SYMBOLS__
  CATIContainer* GiveContainer();
#endif
protected :      
  CATUnicodeString _oldUserId;
  CATUnicodeString _newUserId;
};

#ifndef CATIAR213
class ExportedByAC0XXLNK CATDocEnvModificationNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATDocEnvModificationNotification);
public:
  CATDocEnvModificationNotification(const CATUnicodeString& iOldEnv, const CATUnicodeString& iNewEnv);

  CATUnicodeString GetOldDocEnv();
  CATUnicodeString GetNewDocEnv();

protected :      
  CATUnicodeString _oldDocEnv;
  CATUnicodeString _newDocEnv;
};

class ExportedByAC0XXLNK CATWSLoadEnoviaDocNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATWSLoadEnoviaDocNotification);

};
#endif

class ExportedByAC0XXLNK CATLoadContainerNotification : public CATOmbContainerNotification
{
  CATOmbDeclareNotification(CATLoadContainerNotification);  

#ifdef __OMB_EXPORT_USELESS_NOTIFICATIONS_SYMBOLS__
public:
  CATIContainer* GiveContainer();
#endif
};

#ifndef CATIAR213
class ExportedByAC0XXLNK CATUnLoadContainerNotification : public CATOmbContainerNotification
{
  CATOmbDeclareNotification(CATUnLoadContainerNotification);  
};

class ExportedByAC0XXLNK CATFirstModificationNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATFirstModificationNotification);    
};

class ExportedByAC0XXLNK CATFirstLocalModificationNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATFirstLocalModificationNotification);   
};

class ExportedByAC0XXLNK CATFirstSynchronizationModificationNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATFirstSynchronizationModificationNotification);      
};
#endif

class ExportedByAC0XXLNK CATReplaceUUIDsNotification : public CATDocumentNotification
{
  CATOmbDeclareNotificationWithoutDefaultConstructor(CATReplaceUUIDsNotification);   
public:
  CATReplaceUUIDsNotification(CATLISTP(CATDocument) *ipListOfDocuments, CATUuidTable* ipUuidTable);

  CATLISTP(CATDocument)* GetListOfDocuments();
  CATUuidTable* GetUuidTable();

protected:
  CATLISTP(CATDocument)* _listOfDocuments;
  CATUuidTable* _uuidTable;
};

#ifndef CATIAR213
// This callback will be removed in R17SP1
// Do not use
class ExportedByAC0XXLNK CATOmbEV5BeforeNewIdentNotification : public CATDocumentNotification
{
  CATOmbDeclareNotificationWithoutDefaultConstructor(CATOmbEV5BeforeNewIdentNotification);
public:
  CATOmbEV5BeforeNewIdentNotification(CATLISTP(CATDocument) *ipListOfDocuments);
  CATLISTP(CATDocument)* GetListOfDocuments();
protected:
  CATLISTP(CATDocument)* _listOfDocuments;  
};
#endif

/* DOCUMENT DEBUG TOOL ONLY*/
// BES : Notifies the document debug tool that an error occured and gives the HR
// or the specs list of error messages. 
// Internal service
// Do not use
class ExportedByAC0XXLNK CATErrorNotification : public CATDocumentNotification
{
  CATOmbDeclareNotification(CATErrorNotification);
public:
  void    FeedHresult(HRESULT HR);
  HRESULT GiveHresult();
  void    FeedStorageName(const CATUnicodeString& StorageName);
  const CATUnicodeString& GiveStorageName();
  void FeedErrorMessage(const CATUnicodeString& ErrorMessage);
  const CATUnicodeString& GiveErrorMessage() const;

protected :      
  CATUnicodeString _ErrorMessage;
  HRESULT  _HR;
  CATUnicodeString _StorageName;
};


/* DOCUMENT DEBUG TOOL ONLY*/
// BHG : Notifies the save operation of a container has succeded or failed
// Internal service
// Do not use
class ExportedByAC0XXLNK CATSaveContainerNotification : public CATOmbContainerNotification
{  
  CATOmbDeclareNotificationWithoutDefaultConstructor(CATSaveContainerNotification);  
public:
  typedef enum {E_CATINewStream = 0, E_CATIStream = 1, E_StorePrjectFlag = 2, E_SaveStgProperty = 3, E_Fail = 4} t_statut;

public:
  CATSaveContainerNotification(t_statut iStatut);
  t_statut GiveSaveStatut();

private:
  t_statut _SaveStatut;

};

#ifndef CATIAR213
// VCS 10/01/08 Correction Ko ODTs FTA RecEpdWarmSt* Add CATWSLoadContainerNotification	
class ExportedByAC0XXLNK CATWSLoadContainerNotification : public CATLoadContainerNotification
{
  CATOmbDeclareNotification(CATWSLoadContainerNotification);
public:
#ifndef __OMB_EXPORT_USELESS_NOTIFICATIONS_SYMBOLS__
  virtual int IsAKindOf(const char* ) const;
#endif
};
#endif

#endif
