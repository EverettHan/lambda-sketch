#ifndef CATVisAspect_H
#define CATVisAspect_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "SGInfra.h"

#include "CATBaseUnknown.h"
#include "CATErrorDef.h"
#include "CATUnicodeString.h"
#include "list.h"

class CATPathElement;
class CATRepPath;
class CATPickPath;
class CATNotification;

/**
 * This class defines an aspect.
 * This aspect may contain several information, which can take one of the forms provided.
 * This class is meant to be used in conjunction with @href CATVisChangeManager.
 */
class ExportedBySGInfra CATVisAspect : public CATBaseUnknown
{
  CATDeclareClass;

public:

  /**
   * Destructor.
   */
  virtual ~CATVisAspect();

  /**
   * Call this method to retrieve the aspect identifiers. An aspect is define by a name and a method.
   */
  virtual HRESULT GetIdentifiers(CATUnicodeString& oName, CATUnicodeString& oMethod) = 0;

  /**
   * Call this method to add an integer information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, int iValue) = 0;

  /**
   * Call this method to add a double information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, double iValue) = 0;  

  /**
   * Call this method to add a string information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, const CATUnicodeString& iValue) = 0;

  /**
   * Call this method to add an object information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, const CATBaseUnknown* iValue) = 0;

  /**
   * Call this method to add a @href CATPathElement information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, const CATPathElement* iValue) = 0;

  /**
   * Call this method to add an @href IID list information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, const list<IID>* iValue) = 0;

  /**
   * Call this method to add a @href CATRepPath information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, const CATRepPath* iValue) = 0;

  /**
   * Call this method to add a @href CATPickPath information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, const CATPickPath* iValue) = 0;

  /**
   * Call this method to add a @href CATNotification information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, const CATNotification* iValue) = 0;

  /**
   * Call this method to add an undefined information in the aspect description.
   */
  virtual HRESULT AddInformation(const CATUnicodeString& iName, const CATUnicodeString& iType, const void* iValue) = 0;

  /**
   * Call this method to publish the information associated to the aspect.
   * When this method is called, the content of the aspect is locked and the aspect is destroyed. The caller has to set it to NULL.
   */
  virtual HRESULT PublishInformation() = 0;

protected:

  /**
   * Constructor.
   * This method is set as protected so that only inheriting classes can call it.
   */
  CATVisAspect(const CATUnicodeString& iName, const CATUnicodeString& iMethod);

private:

  /**
   * Copy not allowed.
   */
  CATVisAspect();
  CATVisAspect(const CATVisAspect&);
  CATVisAspect& operator=(const CATVisAspect&);
};

#endif // #ifndef CATVisAspect_H
