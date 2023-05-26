/**
* @level Protected
* @usage U1
*/

#ifndef CATCkeDictionaryIndex_H
#define CATCkeDictionaryIndex_H

// System
#include "CATHashDico.h"
#include "CATListPV.h"
#include "CATString.h"
#include "CATUnicodeString.h"
// ObjectModelerCollection
#include "CATOmxAutoPtr.h"
#include "CATOmxSR.h"
// LiteralFeatures
#include "CATLifDictionary.h"

class CATBaseUnknown_var;
class CATCkeDictionaryIndexVisitor;
class CATCkeDictionaryIndexElement;
class CATICkeDictionaryIndexElementAccessor;
class CATCkeDictionaryIndexImpl;

/**********************************************************************
* Classe d'index des dictionnaires Knowledge
*
* - adhesion a CATICkeDictionaryIndexFill    => remplissage de l'index
* - adhesion a CATICkeDictionaryIndexVisitor => utilisation
***********************************************************************/
class ExportedByCATLifDictionary CATCkeDictionaryIndex
{
public:

  /**
  * Les valeurs numeriques ne doivent jamais etre changees
  */
  enum predefined_types
  {
    unknown = 0,
    type = 1, /* vue CATIType */
    function = 2, /* vue CATICkeSignature */
    subprocess = 3,
    reusable_dialog = 4,
    type_editor = 5
  };

  /************************************
  * Classe de cle pour la table d'index
  *************************************/
  class ExportedByCATLifDictionary keyIndexElement
  {
    CATString _iIndexName;
    predefined_types _iType;

  public:
    keyIndexElement(const CATString &, predefined_types);

    const CATString & getIndexName() const { return _iIndexName; };
    predefined_types getType() const { return _iType; };

    int sortCompare(const keyIndexElement &) const;
    CATString toString() const;
  };

public:
  //-------------------
  //
  //-------------------
  CATCkeDictionaryIndex();
  virtual ~CATCkeDictionaryIndex();

  // Parcours non modifiant de l'index
  void traverse(CATCkeDictionaryIndexVisitor & aVisitor) const;

  // returns Addref-ed object
  CATOmxSR<CATCkeDictionaryIndexElement> AddIndex(keyIndexElement const & iKey);
  CATOmxSR<CATCkeDictionaryIndexElement> FindIndex(keyIndexElement const & iKey);

  int removeIdx(CATCkeDictionaryIndexElement * pEltIdx);

  CATOmxSR<CATICkeDictionaryIndexElementAccessor> BuildAccessor(const CATString & accName);

  int getVersion() const;

  void dump() const;
  void save(CATUnicodeString fileName) const;
  int load(CATUnicodeString fileName = CATUnicodeString());
  int generate(CATListOfCATUnicodeString restrictionPaths);

private:
  CATOmxAutoPtr<CATCkeDictionaryIndexImpl> m_implementation;

public:
  /* Do no use, use AddIndex instead */ CATCkeDictionaryIndexElement * addIdx(const keyIndexElement & iKey);   /* Do no use, use AddIndex instead */
  /* Do no use, use FindIndex instead */ CATCkeDictionaryIndexElement * findIdx(const keyIndexElement & iKey); /* Do no use, use FindIndex instead */
};

#endif
