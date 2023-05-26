/**
 * @fullreview SCA-ERS 02:04:18
 * @error MISC Y manque 2 class xxx
 * @error MISC Y pas de constructeur par defaut, par copie et pas d'operateur =
*/
#ifndef CATAfrDialogBagRep_H
#define CATAfrDialogBagRep_H
// COPYRIGHT DASSAULT SYSTEMES 1999
//===================================================================
//
// CATAfrDialogBagRep.h
// Header definition of CATAfrDialogBagRep
//
//===================================================================
// Usage notes : Protected.
//===================================================================
//  Jan. 1999  Creation                             F. KLEIN (FKN)
//===================================================================
#include "CATAfrDialogRep.h"
#include "CATAfrFoundation.h"

class CATBaseUnknown;
class CATDialog;

/**
 * Classe definit un composite de CATAfrDialogRep, c'est a dire un <tt>CATAfrDialogRep</tt> composee de
 * <tt>CATAfrDialogRep</tt>.
 */
class ExportedByCATAfrFoundation CATAfrDialogBagRep: public CATAfrDialogRep
{
  CATDeclareClass;

  public:

/**
 * Construit une representation a partir d'un element modele, d'un @href CATDialog parent
 * et du nombre d'enfants prevu pour la representation.
 * @param <tt> CATBaseUnknown * iModelId</tt>
 * [in] L'element dont la <tt>CATAfrDialogBagRep</tt> est la representation.
 * @param <tt>CATDialog * iParent</tt>
 * [in] Le @href CATDialog parent des widgets associes a la representation.
 * @param <tt>int iChildCnt</tt>
 * [in] Le nombre de @href CATAfrDialogRep associees a la representation. Cette valeur est indicative et sert
 * a minimiser le nombre d'allocations necessaire au referencement par la representation
 * des representations qui la compose.
 */
    CATAfrDialogBagRep( CATBaseUnknown * iModelId, CATDialog * iParent, int iChildCnt=1 );

/**
 * Le destructeur ne propage pas la destruction de la representation composite a ses representations filles.
 * Voir la methode <tt>DestroyAllChildReps</tt>.
 */
    virtual ~CATAfrDialogBagRep();
  
/**
 * Voir @href CATAfrDialogRep#GetModelID.
 */
    CATBaseUnknown * GetModelID() const;

/**
 * Voir @href CATAfrDialogRep#SetModelID.
 */
    void SetModelID( CATBaseUnknown * iModelId );

/**
 * Ajoute une representation fille a la representation.
 * @param <tt>CATAfrDialogRep * iChildRep</tt>
 * [in] Un <tt>CATAfrDialogRep</tt> qui represente une sous partie de la representation. Il est imperatif
 * que la representation inseree comme fille de la representation composite ait le meme parent dialog.
 * Par contre, l'identifiant model associe (voir la methode <tt>GetModelID)</tt>) n'a pas a etre 
 * identique.
 * @return 
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> L'ajout s'est bien passe.
 * <dt> <tt>S_FALSE</tt>  <dd> La representation ajoutee n'est pas compatible avec des representations
 * ajoutees precedemment. Dans ce cas, l'operation est sans effet sur la representation composite.
 * </dl>
 */
    HRESULT AddChildRep( CATAfrDialogRep * iChildRep );

/**
 * Retourne le nombre d'enfant de la representation composite.
 * @return 
 * Un <tt>int</tt> representant le nombre d'enfant associes a la representation.
 */
    int GetChildCount();

/**
 * Renvoi une sous representation de la representation composite.
 * @param <tt>int iIndex</tt>
 * [in] L'indexe de la representation que l'on veut recuperer. Cet index est compris entre 1 et
 * la valeur retournee par la methode <tt>GetChildCount</tt>.
 * @return 
 * Un <tt>CATAfrDialogRep * </tt>
 */
    CATAfrDialogRep * GetChild( int iIndex );

/**
 * Detruit toute les representation fille de cette representation composite.
 */
    void DestroyAllChildReps();

/**
 * Voir @href CATAfrDialogRep#GetDlgCount. Les widgets sont indexes en commencant par la representation feuille
 * la plus a gauche de l'arbre que compose le composite. Cette implementation n'est absolument pas prevu
 * pour optimiser le scan des elements. En effet, la structure de l'arbre des representation n'a aucune
 * raison d'etre profond.
 */
    int GetDlgCount() const;

/**
 * Voir @href CATAfrDialogRep#GetDialog. Meme remarque que pour la methode <tt>GetDlgCount</tt>.
 */
    CATDialog * GetDialog(int) const;

/**
 * Voir @href CATAfrDialogRep#GetParent.
 */
    CATDialog * GetParent() const;

  protected:

    CATBaseUnknown  * _pModelElem;
    CATAfrDialogRep      ** _lpChildren;
    CATDialog       * _pParent;
    int               _Size, _MemSize, _WidgetSz;

  private:
    // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CATAfrDialogBagRep ();
    CATAfrDialogBagRep (const CATAfrDialogBagRep &);
    CATAfrDialogBagRep & operator= (const CATAfrDialogBagRep &);

};

#endif
