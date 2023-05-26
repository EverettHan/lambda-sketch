/* -*-c++-*- */
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2004
//------------------------------------------------------------------------------
//
//  New V5R201 VCS : PROVISOIRE: EN ATTENDANT CONVERSION DOCID<->PLMID de TCX
// 
//------------------------------------------------------------------------------
// 04/09/21 Creation                                                         VCS
//------------------------------------------------------------------------------
#ifndef CATPLMDocEnvToolBox_H
#define CATPLMDocEnvToolBox_H

/**
* @level Private
* @usage U1
*/

#include "sequence_octet.h"
#include "IUnknown.h"

#include "CATOmbTransientServices.h"

// CATPLMIdentification
class CATPLMRepositoryName;

// ObjectModelerBase
#include "CATOmbStreamDescriptorFormat.h"

// Ajout VCS pour methodes provisoire Marshalling/Unmarshalling
//#include "CATBaseUnknown.h"
#include "CATString.h"
class CATPLMID;

class CATIDocId;
class CATIDocEnvironment;
class CATUnicodeString;
//class CATPLMID;
class CATPLMTypeId;
class CATBaseUnknown;
class CATDocument;
class CATComponentId;
class CATPLMID_RepositoryLocation;
class CATPLMID_Any;
class CATPLMID_Simple;
//------------------------------------------------------------------------------

/**
* Services to perform conversions betweeen PLMId and DocId identifiers.
* <br><b>Role:</b> Converts a PLMId Identifier into a DocId.
* <br> To be used in a PLM context before calling CATIDocEnvironment and CATIDocDescriptor
* <br> protocols.
* <br> Warning: first implemented ONLY FOR ENOVIA
* <br>
*/

class ExportedByCATOmbTransientServices CATPLMDocEnvToolBox
{
public:
  //------------------------------------------------------------------------------
  // generic services
  // (Enovia implementation, to be extended to other repositories)
  //------------------------------------------------------------------------------

  /**
  * DEPRECATED, use GetDocIdFromComponentId
  * Gets the document identifier from its PLMID
  * <br><b>Role:</b> Converts a document PLMID
  * <br> into its document identifier in the matching repository (DocEnv).
  * @param iPLMId
  *     PLMID of the document typed component in a PLM repository
  * @param iExtension
  *     Extension of this document  (CATPart, CATProduct, ...)
  * @param opDocId
  *     pointer thru CATIDocId interface to created DocId
  * @return
  *		 S_OK : conversion successfully done
  * <br> E_FAIL : conversion failed
  */
  static HRESULT GetDocIdFromPLMId(const CATPLMID & iPLMId, const CATUnicodeString & iExtension, CATIDocId * & opDocId);

  /**
  * DEPRECATED, use GetDocIdFromComponentId
  * Gets the document identifier from its PLMID
  * <br><b>Role:</b> Converts a document PLMID
  * <br> into its document identifier in the matching repository (DocEnv).
  * @param iPLMId
  *     PLMID of this document typed component in a PLM repository
  * @param iFormat
  *     Format of the StreamDescriptor related to this document
  *     (describes the nature of data, as specification/results, constituing this document)
  * @param iRole
  *     Role of the StreamDescriptor related to this document
  *     has no sense for authoring format: not taken into account
  *     (describes the building parameter that discriminates it among all those with same Format/Extension)
  * @param iExtension
  *     Extension of this document  (CATPart, CATProduct, ...)
  * @param opDocId
  *     pointer thru CATIDocId interface to created DocId
  * @return
  *		 S_OK : conversion successfully done
  * <br> E_FAIL : conversion failed
  */
  static HRESULT GetDocIdFromPLMId(const CATPLMID & iPLMId, const CATOmbStreamDescriptorFormat & iFormat,
    const CATUnicodeString & iRole, const CATUnicodeString & iExtension,
    CATIDocId * & opDocId);

  /**
  * Builds a CATIDocId to identify a SD (in session), result cannot be persisted, do not use.
  */
  static HRESULT GetDocIdFromComponentId(const CATComponentId& iPLMId, const CATOmbStreamDescriptorFormat & iFormat, const CATUnicodeString & iRole, const CATUnicodeString & iExtension, CATIDocId * & opDocId);

  /**
  * Builds a CATIDocId to identify a SD (in session), result cannot be persisted, do not use.
  */
  static HRESULT GetDocIdFromProxySpaceAndPLMId(const class CATProxySpace& iSpace, const CATPLMID & iPLMId, const CATOmbStreamDescriptorFormat & iFormat, const CATUnicodeString & iRole, const CATUnicodeString & iExtension, CATIDocId * & opDocId);

  /**
  * PBV : Le 29-03-2012 : Tentative pour rendre ce code moins débile et poser les limites de son utilisation.
  *
  *       Tentative de récupération du PLMID à partir d'un DOCID.
  *       Ce call ne devrait être utilisé que par les internes d'OMB et ne pas être exposé comme c'est la cas aujourd'hui.
  *       L'implementation du docenv est une catastrophe !!!
  *
  *       Cette methode ne marche vraiment que si le lien et resolu. Ne pas l'utiliser dans les autres cas.
  *       Comme le DOCID n'embarque pas l'intégralité du PLMID, c'est en fait la vue relationnelle qui va devoir retourner un resultat intelligent.
  *       Methode à supprimer lorsque les liens seront passés sur relations.
  *
  * @param iPointingComponent
  *        Composant pointant permettant de faire le lien avec le vue relationnelle.
  *        Si non présent, l'implementation fonctionne au petit bonheur la chance.
  * @param ipDocId
  *        DocId a traiter
  * @param oPLMID
  *        Resultat de la recherche
  *
  * @return
  *     S_OK;
  *     E_FAIL
  *     HR_CONVERT_DocToPLMIdEmptyInputIdError
  *
  *        Le champs identifier du Docid est vide.
  *
  *     HR_CONVERT_DocToPLMIdConvertIdToSeqOctetError
  *
  *        Le champs identifier du Docid ne peut pas etre exploité.
  *
  *     HR_CONVERT_DocToPLMIdIdentifierCannotBeCompletedFromSpace
  *
  *        En présence de ce HR, un PLMID est quand même retourné mais il n'a pas été complèté car l'info n'est pas disponible.
  *        Plusieurs raisons à celà :
  *           - Cette convertion est réalisée hors session
  *           - Le docid a été recupérer via une sequence non à jour stockée dans le cache des liens.
  */
  static HRESULT GetComponentIdAndPLMIDFromProxySpaceAndDocId(CATProxySpace& ioSpace, CATIDocId* ipDocId, CATPLMID& oPLMID, CATComponentId & oCID);

  // ---------------------------------------------------------------------------------------------------
  // Methode suicidaire a ne pas utiliser en presence de multiples spaces authoring
  // ----------------------------------------------------------------------------------------------------
  static HRESULT GetPLMIdFromDocId(CATIDocId * ipDocId, CATPLMID & oPLMId);

  static HRESULT GetComponentIdFromDocId(CATIDocId * ipDocId, CATComponentId & oCID);
  /**
  * Analyses the format eventually described in a document link identifying sequence
  * <br><b>Role:</b> discriminates Authoring/secondary format in a document link identifying sequence
  * <br> Be careful: Input sequence MUST be a valid PLM link identifying sequence
  * <br> (check this before when necessary)
  * @param iSequence
  *     sequence of bytes describing the Identifier field of the CATDocId object embbeded in a given link
  * @return
  *		 S_OK : sequence is associated to a Stream descriptor Primary Format (Authoring)
  *    S_FALSE  : sequence is associated to a Stream descriptor Secondary Format
  * <br> E_FAIL : analysis failed or severe mismatch encountered: no conversion possible
  * <br> customized E_FAIL code HR_CONVERT_DocToPLMIdConvertIdToSeqOctetError : input DocId badly formatted
  * <br> customized E_FAIL code HR_CONVERT_DocToPLMIdEmptyInputIdError : input DocId badly formatted.
  */

  static HRESULT IsAssociatedToAuthoringStreamDescriptor(const CATUnicodeString& iDocIdIdentifierField);

  /**
  * Gets a PLM encoded Repository type from the DocEnv encoded one
  * <br><b>Role:</b> Gets the PLM encoded Repository type from the DocEnv encoded one.
  * @param ipDocEnv
  *     pointer on DocEnvironment
  * @param oProviderName
  *     Provider type name matching this DocEnvironment
  * @return
  *	   S_OK    : Match found
  * <br> S_FALSE : no associated provider matching this DocEnvironment
  * <br> E_FAIL  : Match failed (output is then useless)
  */
  static HRESULT GetProviderFromDocEnv(CATIDocEnvironment* ipDocEnv, CATPLMRepositoryName & oProviderName);

  /**
  * Gets a DocEnv encoded Repository type from the PLM encoded one
  * <br><b>Role:</b> Gets the DocEnv encoded Repository type from the PLM encoded one.
  * @param iProviderName
  *     Provider type name
  * @param opDocEnv
  *     pointer on DocEnvironment matching this Provider type name
  *     (this pointer MUST be released after use to avoid memory leaks)
  * @return
  *		 S_OK : Match found
  * <br> E_FAIL : Match failed (output is then useless)
  */
  static HRESULT GetDocEnvFromProvider(const CATPLMRepositoryName & iProviderName, CATIDocEnvironment* & opDocEnv);

  /**
  * Retrives a PLMID from a CATBaseUnknown.
  * <br><b>Role:</b> Converts an  Enovia V5 global identifier into its PLMID.
  * @param iCI
  *     CATBaseUnknown
  * @param oPLMId
  *     PLMID of the CATBaseUnknown
  * @return
  *		 S_OK : conversion successfully done
  * <br> E_FAIL : conversion failed
  */

  static HRESULT GetPLMID(const CATBaseUnknown* iCI, CATPLMID& oPLMID);


  /**
  * Gets a DocEnv Repository Name type from the PLM encoded one
  * <br><b>Role:</b> Gets the DocEnv encoded Repository type from the PLM encoded one.
  * @param iProviderName
  *     Provider type name
  * @param oDocEnvName
  *     DocEnvironment name matching this Provider type name
  * @return
  *		 S_OK : Match found
  * <br> E_FAIL : Match failed (output is then useless)
  */
  static HRESULT ProviderToDocEnvName(const CATPLMRepositoryName & iProviderName, CATUnicodeString & oDocEnvName);

  CATPLMDocEnvToolBox() = delete;
  CATPLMDocEnvToolBox(CATPLMDocEnvToolBox const &) = delete;
  CATPLMDocEnvToolBox& operator=(CATPLMDocEnvToolBox const &) = delete;
};

//-----------------------------------------------------------------------

#endif
