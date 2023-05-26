#ifndef __CATOxDataSetEnumerator__
#define __CATOxDataSetEnumerator__
/**
* @level Private
* @usage U1
*/

#include "ExportedByCATPLMIdentification.h"

// System
#include "CATBaseUnknown.h"
#include "Tagdb.h"
#include "CATPLMDataSet.h"
#include "CATPLMTypeH.h"
#include "CATLISTV_CATPLMID.h"
#include "CATIAV5Level.h"

class CATUnicodeString;
class CATString;
class CATListValCATUnicodeString;
class CATOxObjectIdentifier;
class CATIAdpType;
class CATXPLMStreamableCoreInformation;

/**
 * Un CATOxDataSetEnumerator represente un iterateur d'objet sur un dataSet
 * Il permet d'acceder pour chaque objet :
 *   - son type
 *   - les attributs PLM que le dataset contient pour cet objet
 *   - son IdentifierSet
 *   - son champ AdditionalInformations
 * Il n'est pas initialise sur un objet : toutes les methodes d'introspection rendent null tant que
 *   la methode Next n'a pas ete appelee.
 * La methode Next permet de faire que l'objet suivant devienne l'objet courant.
 * Si l'iterateur est vide alors toutes les methodes d'introspection de l'objet courant rendent null.
 */
class ExportedByCATPLMIdentification CATOxDataSetEnumerator : public CATBaseUnknown
{
	public :
	
	/**
	 * Permet de passer a l'objet suivant comme objet courant de l'iterateur
	 * Renvoit S_FALSE s'il n'y a plus d'objet suivant et reste positionne sur l'objet courant.
	 */
	HRESULT Next() ;
	
	/**
	 * Renvoit le type plm de l'objet courant sous la forme CATAdpType
	 * Renvoit NULL si aucun objet n'est courant
	 */
	CATIAdpType*	Type() ;
	
	/**
	 * Renvoit l'identifierSet de l'objet courant
	 * Renvoit NULL si aucun objet n'est courant
	 */
	CATOxObjectIdentifier* Identifier() ;
	

	/**
	 * Renvoit les additionals informations de l'objet courant
	 * Renvoit NULL si aucun objet n'est courant	 
	 */
	CATListOfCATUnicodeString* AdditionalInformation() ;

  virtual ~CATOxDataSetEnumerator();

  CATPLMID GetReferencePLMID();
  CATLISTV(CATPLMID) GetAggregatedPLMIDs();

private:
  CATPLMDataSet *_DataSet;
  TagdbItrStrBlb * _Iterator;
  TagdbStringKey * _CurrentKey;
  CATIAdpType * _CurrentType;
  CATPLMTypeH _CurrentTypeH;
  CATXPLMStreamableCoreInformation * _CurrentCoreInfo;
  CATListOfCATUnicodeString _CurrentListOfUKs;

  friend class CATPLMDataSet;
  CATOxDataSetEnumerator(CATPLMDataSet * ipDataSet);

 
};

#endif		
