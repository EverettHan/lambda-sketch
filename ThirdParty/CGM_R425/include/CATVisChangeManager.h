#ifndef CATVisChangeManager_H
#define CATVisChangeManager_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "SGInfra.h"

#include "CATVizBaseCodeExtension.h"
#include "list.h"

class CATVisAspect;

class CATBaseUnknown;
class CATUnicodeString;
class VisIChangeObserver;

/**
 * This class defines the change manager. 
 * This object is listening to modification information (ie aspects) emitted by objects (ie subjects).
 * This class is meant to be used in conjunction with @href CATVisAspect.
 */
class ExportedBySGInfra CATVisChangeManager : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATVisChangeManager);

public:

  /**
   * Call this method to retrieve the @href CATVisChangeManager singleton.
   */
  static CATVisChangeManager* GetChangeManager();

  /**
   * Call this method to register a subject as emitter of modification information.
   * Input subject lifecycle is managed through used of a @href CATSysWeakRef.
   */
  virtual HRESULT Register(CATBaseUnknown* ipSubject) = 0;

  /**
   * Call this method to register a subject as emitter of modification information.
   * No management of the input subject lifecycle is performed.
   */
  virtual HRESULT Register(void* ipSubject) = 0;

  /**
   * Call this method to unregister an already registered subject. 
   * It won't be able to emit any new modification information.
   */
  virtual HRESULT Unregister(CATBaseUnknown* ipSubject) = 0;

  /**
   * Call this method to unregister an already registered subject. 
   * It won't be able to emit any new modification information.
   */
  virtual HRESULT Unregister(void* ipSubject) = 0;

  /**
   * Call this method to create an aspect associated to an already registered subject. 
   * An aspect it defined by its name and a method name, used as identifiers.
   */
  virtual CATVisAspect* CreateAspect(CATBaseUnknown* ipSubject, const CATUnicodeString& iAspectName, const CATUnicodeString& iMethodName) = 0;

  /**
   * Call this method to create an aspect associated to an already registered subject. 
   * An aspect it defined by its name and a method name, used as identifiers.
   */
  virtual CATVisAspect* CreateAspect(void* ipSubject, const CATUnicodeString& iAspectName, const CATUnicodeString& iMethodName) = 0;


protected:

  /**
   * Constructor.
   * This method is set as protected so that only inheriting classes can call it.
   */
  CATVisChangeManager();

  /**
   * Destructor.
   * This object is a singleton. It will be destroyed at the end of the application.
   */
  ~CATVisChangeManager();

  /**
   * This object is called to instanciate the @href CATVisChangeManager singleton.
   */
  virtual CATVisChangeManager* RetrieveChangeManager() = 0;

private:

  static CATVisChangeManager* _spChangeManager;
  static CATBoolean _sbChangeManagerDestroyed;

  /**
   * Copy not allowed.
   */
  CATVisChangeManager(const CATVisChangeManager&);
  CATVisChangeManager& operator=(const CATVisChangeManager&);


private:
  virtual list<VisIChangeObserver> GetObservers() = 0;
  friend class AccessObserverOfVisEChangeManager;
};

#endif // #ifndef CATVisChangeManager_H
