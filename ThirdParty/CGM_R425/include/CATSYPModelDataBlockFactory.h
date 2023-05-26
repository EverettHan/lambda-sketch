#ifndef CATSYPModelDataBlockFactory_H
#define CATSYPModelDataBlockFactory_H

#include <CATStyleProcessor.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATSYPArray.h>
#include <CATSYPHashMap.h>

class CATSYPModelTag;
class CATSYPModelProperty;

/**
* Describes a model factory, used to represent a data block factory.
*/
class ExportedByCATStyleProcessor CATSYPModelDataBlockFactory
{
public:
  /** @return the factory name*/
  const CATUnicodeString& GetFactoryName() const;
  
  /** Gets the origin of the resource, i.e its file, and a flag indicating if the returned path is relative or absolute.*/
  void GetResourceOrigin(CATUnicodeString& o_resourceFilePath, int& o_resourceFullPathFlag) const;

  /** @return the properties of the object, for modification purpose */
  INLINE const CATSYPDynArray<CATSYPModelProperty*>& GetProperties() const
  {
    return _properties;
  }
  /** @return the properties of the object */
  INLINE CATSYPDynArray<CATSYPModelProperty*>& GetProperties()
  {
    return _properties;
  }

  /** @return the version number. Default is 0. */
  const int& GetVersion() const;
  /** Sets the version number. Default is 0. */
  void SetVersion(int& i_version);
  
  ~CATSYPModelDataBlockFactory();
private:
  CATSYPModelDataBlockFactory(const CATUnicodeString& i_factoryName, const int& i_version);

  /**
  * Clean all the properties on the tag.
  */
  void CleanProperties();

  /**
  * Remove all properties whitout delete them.
  */
  void RemoveAllProperties();

  void SetResourceOrigin(const CATUnicodeString& i_resourceFilePath, int i_resourceFullPathFlag);
  /** Copy Constructor */
  CATSYPModelDataBlockFactory(const CATSYPModelDataBlockFactory &i_toCopy);
  /** Operator = */
  CATSYPModelDataBlockFactory& operator = (const CATSYPModelDataBlockFactory &i_toCopy);

  /** Sets the factory name*/
  void SetFactoryName(const CATUnicodeString& i_factoryName);
   
private:
  CATUnicodeString _factoryName;
  CATSYPDynArray<CATSYPModelProperty*> _properties;

  CATUnicodeString _resourceFilePath;
  int _resourceFullPathFlag;
  int _version;

  friend class CATSYPStyleProcessor;
  friend class CATSYPSaxModelBuilder;
  friend class VIDDesignController;
};

template <> struct CATSYPHashMapHasher<const CATSYPModelDataBlockFactory*> 
{
public:
  int ComputeHash(const CATSYPModelDataBlockFactory* const& i_key)
  {
#ifdef PLATEFORME_DS64
    return (unsigned int) ( ((CATUINTPTR) i_key) >> 3 );
#else
    return (unsigned int) ( ((CATUINTPTR) i_key) >> 2 );
#endif
  }
};

#endif
