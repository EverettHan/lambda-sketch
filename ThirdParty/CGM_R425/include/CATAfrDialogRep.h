/* -*-c++-*- */
#ifndef CATAfrDialogRep_H
#define CATAfrDialogRep_H
// COPYRIGHT DASSAULT SYSTEMES  1997
//=============================================================================
//
// CATAfrDialogRep:
//
//=============================================================================
// Usage Notes:
//
// Utilisee pour definir la repesentation sous forme de CATDialog d'un objet.
// Cette entite est utilisee entre autre par l'interface CATIAfrDialog.
//
//=============================================================================
// Inheritance : CATAfrDialogRep
//                 CATBaseUnknown (System FW)
//
//=============================================================================
// Mars 98   Creation                                        F. KLEIN (fkn)
//=============================================================================
#include "CATBaseUnknown.h"
#include "CATAfrFoundation.h"

class CATDialog;

/**
 * Classe abstraite definissant le comportement de la representation d'un objet dans une
 * toolbar.
 * Cet objet est associe a l'interface @href CATIAfrDialog.
 * Elle permet a un objet qui utilise une de ces representation de savoir de quel objet il 
 * manipule la representation.
 * La representation est de type CATDialog et peut etre composee de plusieurs widgets.
 * Les CATDialogs associes ne sont pas consideres comme des agregats de cette representation
 * et en aucun cas une CATAfrDialogRep ne peut controler leur cycle de vie.
 */
class ExportedByCATAfrFoundation CATAfrDialogRep : public CATBaseUnknown
{
  public:

    CATDeclareClass;

/**
 * Renvoi l'element modele dont cet objet est la representation.
 * @return 
 * Un <tt>CATBaseUnknown * </tt>, l'element modele recherche. Aucun comptage de reference n'est
 * effectue sur le pointeur retourne. Cette donnee doit avoir une duree de vie superieure a la
 * representation.
 */
    virtual CATBaseUnknown * GetModelID() const = 0;

/**
 * Definit l'element modele dont cet objet est une representation. Une <tt>CATAfrDialogRep</tt>
 * ne peut etre la representation que d'un seul element. Utiliser <tt>SetModelID</tt> n'a
 * de sens que dans un contexte de reutilisation d'une <tt>CATAfrDialogRep</tt> et n'a que tres
 * peu d'influence sur la representation elle meme.
 * @param <tt>CATBaseUnknown * iModelId</tt>
 * [in] L'element modele qui doit etre associe a la representation.
 */
    virtual void SetModelID( CATBaseUnknown * ) = 0;

/**
 * Renvoi le nombre de <tt>CATDialog</tt> assiocies a la representation.
 * @return 
 * Un <tt>int</tt>, le nombre de widgets associe a la representation.
 */
    virtual int GetDlgCount() const = 0;

/**
 * Renvoi le @href CATDialog indexe <tt>iIndex</tt> associe a la representation.
 * @param <tt>int iIndex</tt>
 * [in] L'indexe du widget recherche. Cet index doit etre compris entre 1 et la
 * valeur retournee par la methode <tt>GetDlgCount</tt>.
 * @return 
 * Un <tt>CATDialog</tt>, le sous element <tt>iIndex</tt> de la representation.
 * Un e <tt>CATAfrDialogRep</tt> se decompose en sous element de facon a pourvoir gerer la
 * mise en forme de la tollbar correctement. En effet, si une representation n'etait 
 * en fait qu'un @href CATDlgFrame, alors la toolbar s'en trouverait rigidifiee et
 * ne pouurrait pas se recalculer en fonction de sa position dans la fenetre principale
 * de l'application.
 */
    virtual CATDialog * GetDialog( int iIndex ) const = 0;

/**
 * Renvoi le pere au sens @href CATDialog de tous les <tt>CATDialog</tt> qui constituent la rep.
 * <b>NOTE : </b><i>Il n'y a pas de moyen de verifier la validite du parent associer aux
 * <tt>CATDialog</tt> qu'on ajoute a  une Rep car il faut passer le parent d'un CATDialog lors
 * de sa construction. Il est donc important de ne pas associer differents parents aux 
 * <tt>CATDialog</tt> associes a une <tt>CATAfrDialogRep</tt>. La notion de parent sert simplement a
 * retrouver la hierarchie des reps lorsqu'on ajoute des <tt>CATDialog</tt> a une
 * <tt>CATAfrDialogRep</tt> dans un contexte de multirepresentation.</i>
 * @return 
 * Un <tt>CATDialog</tt> representant le pere des widgets associes a la representation. Cette valeur
 * de retour peut etre nulle si aucun widget n'est associe a cette representation.
 */
    virtual CATDialog * GetParent() const = 0;

};

#endif
