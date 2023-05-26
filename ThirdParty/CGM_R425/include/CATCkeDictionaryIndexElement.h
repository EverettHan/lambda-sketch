/**
* @level Protected
* @usage U1
*/

#ifndef CATCkeDictionaryIndexElement_H
#define CATCkeDictionaryIndexElement_H

// System
#include "CATListOfCATString.h"
#include "CATString.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxCxxPortability.h"
#include "CATOmxPortability.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"
#include "sequence_octet.h"
// LiteralFeatures
#include "CATCkeDictionaryIndex.h"
#include "CATLifDictionary.h"

class CATCkeDictionaryIndexVisitor;
class CATICkeDictionaryIndexElementAccessor;
class CATCkeSharedListOfCATString;

/*************************
* Element d'index
**************************/
class ExportedByCATLifDictionary CATCkeDictionaryIndexElement : public CATOmxSharable
{
public:

  CATCkeDictionaryIndexElement(const CATCkeDictionaryIndex::keyIndexElement & iKey);
  ~CATCkeDictionaryIndexElement() OMX_Cxx11_OVERRIDE;
  void setVersion(int);
  void Remove(); // seul l'index est autorise a detruire un element

  int IsNull() const;

  // Compare : 0 if both elements designate the same element
  int sortCompare(const CATCkeDictionaryIndexElement &) const;

  // accesseurs
  const CATCkeDictionaryIndex::keyIndexElement & getKey() const;
  const CATListOfCATString & getRepositories() const;
  const CATListOfCATString & getPhysicalRepositories() const;
  const SEQUENCE(octet) & getBlob() const;
  CATOmxSR<CATICkeDictionaryIndexElementAccessor> GetAccessorSR() const;
  CATBaseUnknown_var getTypeExtension() const;
  const char * getTypeExtensionAsString() const;
  int getVersion() const;

  // valuateurs
  CATCkeDictionaryIndexElement & addRepository(const CATString & iRepository);
  CATCkeDictionaryIndexElement & addPhysicalRepository(const CATString & iRepository);
  CATCkeDictionaryIndexElement & setBlob(const SEQUENCE(octet) & blob);
  CATCkeDictionaryIndexElement & setAccessor(CATICkeDictionaryIndexElementAccessor * pAccessor);
  CATCkeDictionaryIndexElement & setAccessorName(const CATString & strName);
  CATCkeDictionaryIndexElement & setTypeExtension(const CATBaseUnknown_var & iType);
  CATCkeDictionaryIndexElement & setTypeExtensionFromStream(const CATString & iStream);

  // pour le visiteur
  void accept(CATCkeDictionaryIndexVisitor & aVisitor);

  // Pour la sauvegarde dans un fichier (une ligne par element d'index)
  CATString toString() const;
  static int fromString(const CATString & uneLigne, int streamVersion, CATCkeDictionaryIndex & anIdx);

private:
  int m_isNull;
  CATCkeDictionaryIndex::keyIndexElement m_key;        // Cle
  int m_version;                                       // Version de l'index ou a ete recupere cet element
  enum { isInstalled, isNotInstalled, unknown } m_installationStatus;// Is the element installed

  //HACK, "null" is defined as a macro in some horrible knowledge headers, this causes errors in CATOmxKeyString.h
#ifdef __CATCkeDictionaryIndexElement_Implement
  CATOmxSR<CATCkeSharedListOfCATString> m_repositories;                   // Noms des endroits logiques ou l'on peut trouver cet objet
  CATOmxSR<CATCkeSharedListOfCATString> m_physicalRepositories;          // Noms des endroits physiques ou l'on peut trouver cet objet
  CATOmxArray<octet> m_blob1, m_blob2;                   // Info utilisateur sur cet objet
  mutable CATOmxSR<CATICkeDictionaryIndexElementAccessor> m_accessor; // Accesseur
  CATOmxKeyString m_accessorType;								// Late type de l'accesseur
  CATOmxKeyString m_typeExtensions;							// infos CATITypeExtension (R209)
#else
  void * m_placeHolder[7];
#endif

  CATCkeDictionaryIndexElement(CATCkeDictionaryIndexElement const &) OMX_Cxx11_DELETE;
  CATCkeDictionaryIndexElement & operator= (CATCkeDictionaryIndexElement &) OMX_Cxx11_DELETE;

public:
  /* Do not use. */ CATICkeDictionaryIndexElementAccessor * getAccessor() const; // Deprecated method, DO NOT USE ! Use GetAccessorSR instead.
};

#endif
