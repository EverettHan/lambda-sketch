/**
 * @fullreview SCA-ERS 11:04:04
 * @error MISC Y pas de constructeur par copie, par defaut et pas d'operateur =
 * @error MISC Y il manque des class xxx
 * @error MISC Y 2 groupes de protected a la suite
*/
#ifndef CATCommandHeaderWithSDORep_H
#define CATCommandHeaderWithSDORep_H
// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATCommandHeaderWithSDORep :
//
//=============================================================================
// Usage Notes : Private
//
// Usage interne au CATCommandHeaderWithSDO dans CreateToolbarRep.
//
//=============================================================================
// Inheritance: CATCommandHeaderWithSDORep
//                 CATCmdRep (ApplicationFrame FW)
//                    CATCommand (Systezm FW)
//=============================================================================
// Aout 98   Creation                                        F. KLEIN (fkn)
//=============================================================================
#include "CATCmdRep.h"

#include "CATListOfCATAfrDialogRep.h"
#include "CATListOfCATCommand.h"

#include "CATAfrFoundation.h"

class CATListPtrCATBaseUnknown;
class CATBaseUnknown;
class CATDialog;
class CATAfrDialogRep;

/**
 * Classe associee au objets de type @href CATCommandHeaderWithSDO afin de definir une representation
 * aux objets inseres dans le Set of Dialog Objects (SDO).
 * Cette Rep doit etre cree dans la methode CATRCmdAccess::CreateXXXRep du CmdAccess qui lui est 
 * associe.
 * Cette Objet controle le cycle de vie des reps et des objets de dialogue (voir @href CATDialog)
 * qui sont associes a la representation du Header qu'il represente. Les deux methodes publiques 
 * <tt>AddRep()</tt> et <tt>RemoveRep()</tt> servent a mettre a jour dynamiquement la
 * representation du Header. En effet, des elements peuvent etre ajoutes au SDO a tout moment.
 * Cependant, ce ne sont pas les <tt>CATCommandHeaderWithSDORep</tt> qui decident de representer
 * un objet, le message <tt>AddRep</tt> ou <tt>RemoveRep</tt> doit venir du Header associer a cet
 * objet.
 * De la meme facon que @href CATCommandHeaderWithSDO, le IID qu'utilise cet objet pour representer
 * les elements du SDO doit etre un IID d'interface derivant de CATIAfrDialog.
 */
class ExportedByCATAfrFoundation CATCommandHeaderWithSDORep : public CATCmdRep
{
  CATDeclareClass;

public:


/**
 * Construit une representation de @href CATCmdHeader a partir d'un acces d'un widget parent ainsi
 * que d'un <tt>GUID</tt> d'interface derivant de @href CATIAfrDialog.
 */
  CATCommandHeaderWithSDORep( CATCmdAccess *, CATCommand *, const IID & );
  virtual ~CATCommandHeaderWithSDORep();

/**
 * Ajoute les representations d'une liste d'elements qui adherent a CATIAfrDialog a la
 * representation.
 * @param <tt>const CATListPtrCATBaseUnknown * iElems</tt>
 * [in] Une liste de pointeur sur <tt>CATBaseUnknown</tt>.
 */
  void AddRep( const CATListPtrCATBaseUnknown & iElems );

/**
 * Supprime l'ensemble des representations associes a une liste d'element. Cette methode provoque
 * la destruction physique de toutes les @href CATAfrDialogRep ainsi que de tous les @href CATDialog
 * qui constituent les representations des elements de <tt>iElems</tt>.
 * @param <tt>const CATListPtrCATBaseUnknown * iElems</tt>
 * [in] Une liste de pointeur sur <tt>CATBaseUnknown</tt>.
 */
  void RemoveRep( const CATListPtrCATBaseUnknown & iElems );


/**
 * Met a jour la representation d'un ensemble d'element adherant a @href CATIAfrDialog.
 * La mise a jour s'opere par l'intermediaire de @href CATIAfrDialog#UpdateRep.
 * @param <tt>const CATListPtrCATBaseUnknown * iElems</tt>
 * [in] Une liste de pointeur sur <tt>CATBaseUnknown</tt>.
 */
  void UpdateRep( const CATListPtrCATBaseUnknown & iElems );

  
  CATLISTP(CATAfrDialogRep)         _lpSDOElemRep;

protected:

/**
 * Renvoi la representation @href CATIAfrDialog d'un objet donne en utilisant l'IID d'interface
 * associe a cet objet.
 * @param <tt>CATBaseUnknown * iModelID</tt>
 * [in] L'objet dont on veut construire une representation.
 * @param <tt>CATDialog * iParent</tt>
 * [in] Le pere au sens @href CATDialog de la representation de <tt>iModelID</tt>.
 * @return 
 * Un <tt>CATAfrDialogRep *</tt> referencant la representation de <tt>iModelID</tt>.
 */
  CATAfrDialogRep * GetRep( CATBaseUnknown * iModelID, CATDialog * iParent ) const;


/**
 * Detruit physiquement les @href CATDialog associes a une @href CATAfrDialogRep. Cette destruction est differee
 * par des @href CATCommand#RequestDelayedDestruction.
 */
  void RequestDlgDestructionInRep( CATAfrDialogRep * iRep );

/**
 * Invalide au sens @href CATIAfrDialog#InvalidateRep la representation passee en argument.
 */
  void InvalidateDlgRep( const CATAfrDialogRep * iRep );
  
  const IID                 & _IID; 

  // La Liste de Rep Dialog crees par les differents objets du SDO afin de pouvoir
  // gerer l'ajout et le retrait dynamiques des elements de SDO.
  CATLISTP(CATCommand)              _lpRepSeparator;

private:
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCommandHeaderWithSDORep ();
  CATCommandHeaderWithSDORep (const CATCommandHeaderWithSDORep &);
  CATCommandHeaderWithSDORep & operator= (const CATCommandHeaderWithSDORep &);

};
#endif
