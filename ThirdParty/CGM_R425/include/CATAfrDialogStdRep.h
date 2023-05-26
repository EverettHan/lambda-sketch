/**
 * @fullreview SCA-ERS 02:04:18
 * @error MISC Y manque 2 class xxx
 * @error MISC Y pas de constructeur par defaut, par copie et pas d'operateur =
*/
#ifndef CATAfrDialogStdRep_H
#define CATAfrDialogStdRep_H
// COPYRIGHT DASSAULT SYSTEMES 1999
//===================================================================
//
// CATAfrDialogStdRep.h
// Header definition of CATAfrDialogStdRep
//
//===================================================================
// Usage notes : Protected.
//===================================================================
//  Jan 1999  Creation                              F. KLEIN (FKN)
//===================================================================
#include "CATAfrDialogRep.h"
#include "CATAfrFoundation.h"

class CATBaseUnknown;
class CATDialog;

/**
 * Classe definissant le comportement de la representation d'un objet dans une toolbar.
 * Cet objet est associe a l'interface @href CATIAfrDialog. Il s'agit d'une rep
 * standard par opposition aux representations composites de type @href CATAfrDialogBagRep.
 */
class ExportedByCATAfrFoundation CATAfrDialogStdRep : public CATAfrDialogRep
{
  CATDeclareClass;

  public:

/**
 * Construit une representation a partir d'un element modele, d'un @href CATDialog parent
 * et du nombre de widget necessaire a la representation.
 * @param <tt> CATBaseUnknown * iModelId</tt>
 * [in] L'element dont la <tt>CATAfrDialogStdRep</tt> est la representation.
 * @param <tt>CATDialog * iParent</tt>
 * [in] Le @href CATDialog parent des widgets associes a la representation.
 * @param <tt>int iDlgCnt</tt>
 * [in] Le nombre de widget associe a la representation. Cette valeur est indicative et sert
 * a minimiser le nombre d'allocations necessaire au referencement par la representation
 * des widgets qui la compose.
 */
    CATAfrDialogStdRep( CATBaseUnknown * iModelId, CATDialog * iParent, int iDlgCnt=1 );
    virtual ~CATAfrDialogStdRep();
  
/**
 * Voir @href CATAfrDialogRep#GetModelID.
 */
    CATBaseUnknown * GetModelID() const;

/**
 * Voir @href CATAfrDialogRep#SetModelID.
 */
    void SetModelID( CATBaseUnknown * iModelId );

/**
 * Ajoute un widget a la representation.
 * @param <tt>CATDialog * iWidget</tt>
 * [in] Un <tt>CATDialog</tt> qui represente une sous partie de la representation. Cette methode
 * est totalement independante de la gestion equivalente proposee par le FW Dialog. En effet, ces
 * representations sont une surcouche introduite pour gerer une visu de type toolbar, mais comme 
 * les <tt>CATDialog</tt> ne peuvent pas etre construit sans un parentage explicite, le resultat
 * obtenu, au sens panel, a une mise en forme independante de l'ordre des <tt>AddDialog</tt>
 * effectues.
 */
    void AddDialog( CATDialog * iWidget );

/**
 * Voir @href CATAfrDialogRep#GetDlgCount.
 */
    int GetDlgCount() const;

/**
 * Voir @href CATAfrDialogRep#GetDialog.
 */
    CATDialog * GetDialog(int) const;

/**
 * Voir @href CATAfrDialogRep#GetParent.
 */
    CATDialog * GetParent() const;

  protected:

    CATBaseUnknown  * _pModelElem;
    CATDialog      ** _lpDialog;
    CATDialog       * _pParent;
    int               _Size, _MemSize;

  private:
    // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CATAfrDialogStdRep ();
    CATAfrDialogStdRep (const CATAfrDialogStdRep &);
    CATAfrDialogStdRep & operator= (const CATAfrDialogStdRep &);

};

#endif
