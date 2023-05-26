#ifndef __CATPLMDataSet__
#define __CATPLMDataSet__

/**
* @level Private
 * @usage U1
 */

#include "ExportedByCATPLMIdentification.h"
#include "CATBaseUnknown.h"
#include <time.h>
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"
#include "CATIAV5Level.h"
#include "TagdbSpecializations.h"
#include "CATPLMIDCollections.h"
#include "CATOmxArray.h"

class CATOxDataSetBuilder;
class CATOxObjectIdentifier;
class CATOxDataSetEnumerator;
class CATPLMID;
class CATXPLMStreamableListOfString;
class CATPLMTypeH;
class DSYSysScrambling;


class ExportedByCATPLMIdentification CATPLMDataSet : public CATBaseUnknown
{
  friend class CATXPLMDataSetManager;
  friend class CATOxDataSetEnumerator;

  /**
   * Tout dataset a 2 attributs :
   *   - creationDate qui donne la date de creation du DataSet
   *   - mutable (BOOL) qui indique si le dataSet est mutable ou non.
   *
   * Pour chaque objet, le CATPLMDataSet stocke :
   * de facon obligatoire :
   *   - son PLMID
   *   - si le type de l'objet est un port ou une connection, le PLMID de son aggregeant
   *   - si le type de l'objet est une instance, le PLMID de son aggregeant et le PLMID de la reference dont il est instancie
   *   - son identifierset
   *   - Additional Information: Cet attribut est un attribut qui n'existe pas dans le dictionnaire PLM.Son type est CATListOfCATUnicodeString
   * de facon optionnelle :
   *   - un ensemble d'attribut PLM et leur valeur
   */

public:

  /**
   * Returns if the DataSet is mutable or not.
   * If not AddAdditionalInformationToAllObjectBelongingToThisDataset,ImportDataFromDataSet,ImportObjectRejectedByBriefcaseTransaction,RemoveObjectIdentifiedBy
   * will return E_FAIL
   */
  CATBoolean Mutable();

  /**
   * Renvoit la date de creation exprimee en milliseconds depuis le 1er janvier 1970
   */
  time_t CreationDate();

  /**
   * Ajoute la valeur iValue a la valeur de l'attribut "Additional Information" de tous les objets du DataSet
   * Sachant que cet attribut est une liste de CATUnicodeString, on append a cette liste la valeur identifiee par iValue
   * Si l'operation est un succes, l'effet est directe dans la persistance du CATPLMDataSet
   */
  HRESULT AddAdditionalInformationToAllObjectBelongingToThisDataset(const CATUnicodeString& iValue);

  /**
   * Importe les données du dataSet identifie par iDataSet
   * On sort en E_FAIL si pour un PLMID present dans le dataset recepteur et le dataset importe identifie par IDataSet, la valeur d'un attribut PLM est differente dans les 2 datasets
   * Sinon :
   *  La fonction recopie
   *    pour tout objet non present dans le dataset recepteur, l'ensemble de ses valeurs provenant du dataset importe.
   *    pour tout objet present dans le dataset recepteur, merge les additionals informations et ajoute les valeurs des attributs plm non present dans le dataset recepteur
   * Si l'operation est un succes, l'effet est directe dans la persistance du CATPLMDataSet
   */
  HRESULT ImportDataFromDataSet(CATPLMDataSet* iDataSet);

  /**
   * Detruit tous les objets (ainsi que leur aggreges) identifies par la liste des CATOxObjectIdentifier
   * Si l'operation est un succes, l'effet est directe dans la persistance du CATPLMDataSet
   */
  HRESULT RemoveObjectIdentifiedBy(const CATOmxArray<CATOxObjectIdentifier> & iIdentifiersForObjects);

  /**
   * Enumere toutes les references contenues dans le dataset
   * Le resultat renvoye est un CATOxDataSetEnumerator
   */
  HRESULT EnumerateReferencesContained(CATOxDataSetEnumerator *& oEnumerator);

private:

  CATPLMDataSet(const CATUnicodeString & iLocation);
  virtual ~CATPLMDataSet();

  // iBuilder peut etre nul, dans ce cas on cree un dataset vide,
  // dans lequel on pourra en importer un autre
  static HRESULT CreateDataSet(CATBoolean iIsMutable,
    const CATUnicodeString & iName,
    CATOxDataSetBuilder * iBuilder,
    CATPLMDataSet *& oDataSet);
  static HRESULT OpenDataSet(const CATUnicodeString & iName,
    CATPLMDataSet *& oDataSet,
    CATBoolean iTransient = FALSE);
  static CATBoolean IsLocationAppropriateForCreation(const CATUnicodeString & iLocation);
  static CATBoolean IsValidDataSet(const CATUnicodeString & iName);
  static HRESULT CopyDataSet(const CATUnicodeString & iSourceName, const CATUnicodeString & iDestName);
  static HRESULT DeleteDataSet(const CATUnicodeString & iName);

  void SetConcurrentLock();
  void ReleaseConcurrentLock();
  CATBoolean IsLockedForConcurrentAccess();

  HRESULT InitDB();
  HRESULT InitFromBuilder(CATOxDataSetBuilder * iBuilder);

  CATUnicodeString CreateKeyForPLMID(const CATPLMID & iPLMID);
  CATUnicodeString AppendPLMIDToRecord(const CATPLMID & iPLMID, const CATUnicodeString& iRecord);
  CATUnicodeString AddKeyToRecord(const CATUnicodeString& iKey, const CATUnicodeString& iRecord);
  CATUnicodeString MergePLMIDRecords(const CATUnicodeString& iRecord1, const CATUnicodeString& iRecord2);
  HRESULT ComputeIdSetValuesForRecord(CATPLMIDToArrayUnicodeStringMapIter & PLMIDiter, CATXPLMStreamableListOfString & oListOfValues);
  HRESULT AddRecordToAggregationTree(CATOxDataSetBuilder * iBuilder, CATPLMIDToArrayUnicodeStringMapIter & iPLMIDiter);
  HRESULT AddRecordToCoreInfoTree(CATOxDataSetBuilder * iBuilder, CATPLMIDToArrayUnicodeStringMapIter & iPLMIDiter);
  int GetNextInfoId();

  HRESULT CheckImportedDataConsistency(CATPLMDataSet *iDataSet, CATLISTV(CATUnicodeString) & oNewData,
    CATLISTV(CATUnicodeString) & oExistingData);
  HRESULT RemoveObject(const char * Key);

  CATUnicodeString _DataSetLocation;
  CATUnicodeString _CoreInfoDBLocation;
  TagdbStrBlb _CoreInfoDB;
  CATUnicodeString _AggregationDBLocation;
  TagdbStrBlb _AggregationDB;
  CATUnicodeString _AddInfoDBLocation;
  TagdbStrBlb _AddInfoDB;
  CATUnicodeString _AddInfoValueDBLocation;
  TagdbStrBlb _AddInfoValueDB;

  CATUnicodeString _MutableLocation;
  CATUnicodeString _DBConcurrentAccessLockLocation;

  time_t _CreationDate;
  CATBoolean _Mutable;
  CATBoolean _DBInitialized;
  CATBoolean _Transient;

  DSYSysScrambling * _Scrambler;
  CATUnicodeString _ScramblingKey;

  CATUnicodeString Scramble(const CATUnicodeString & iString);
  CATUnicodeString Unscramble(const CATUnicodeString & iString);


};
#endif 
