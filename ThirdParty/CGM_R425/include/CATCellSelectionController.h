// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCellSelectionController.h
// Header definition of CATCellSelectionController
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//===================================================================
#ifndef CATCellSelectionController_H
#define CATCellSelectionController_H

#include "CATView.h"
#include "CATListViewController.h"
#include "CATString.h"
#include "CATBaseUnknown.h"

class CATListView;

//-----------------------------------------------------------------------

/**
 * A list controller to support list cells selection
*/
class ExportedByCATView CATCellSelectionController: public CATListViewController
{
  CATDeclareClass;

  public:

     // Standard constructors and destructors
     // -------------------------------------
     CATCellSelectionController (CATListView* iView);
     virtual ~CATCellSelectionController ();

     // Copy constructor and equal operator
     // -----------------------------------
     CATCellSelectionController (CATCellSelectionController &);
     CATCellSelectionController& operator=(CATCellSelectionController&);

      /** Checks if a cell is selected
       * @param iObj Object to check
       * @param iColID [in]
       *   ID of the column containing the cell.
       * @return 0 if the cell is unselected
       *         1 if the cell is selected
       */
     virtual int IsSelected( CATBaseUnknown_var iNode, const CATString& iColID);

      /** Checks if a cell is pre-selected
       * @param iObj Object to check
       * @param iColID [in]
       *   ID of the column containing the cell.
       * @return 0 if the cell is unselected
       *         1 if the cell is selected
       */
     virtual int IsPreSelected( CATBaseUnknown_var iNode, const CATString& iColID );

      /** Checks if a cell is selected in a column
       * @param iColID [in]
       *   ID of the column containing the cell.
       * @return 0 if the cell is unselected
       *         1 if the cell is selected
       */
     virtual int ACellIsSelectedInTheColumn( const CATString& iColID );

     /**
      * Is called when a cell is selected
      */
     virtual void OnSelect( CATBaseUnknown_var iNode, const CATString& iColID );

     /**
      * Is called when mouse over cell
      */
     virtual void OnMoveOver( CATBaseUnknown_var iNode, const CATString& iColID );
     
     /**
      * Is called when contextual menu request
      */
     virtual void OnCellContext( CATBaseUnknown_var iNode, const CATString& iColID );

     /**
      * Retrieve a list of all currently selected cells.  Currently, only cells from a
      * single column may be selected.  This is appropriate to the Sheet Editor application,
      * but heterogenous cell selection may be desired in other applications.  If the need arises,
      * we may modify this class, or create a separate selection controller which can support
      * multiple cells chosen from different columns.
      */
     virtual void GetSelectedCells( CATListOfCATBaseUnknown_var &oSelection, CATString& oColID );
     /* move to edit support
     virtual void OnActivate( CATBaseUnknown_var iNode );
     */

  protected:

     CATString _SelectedCol;
     CATString _PreSelectedCol;
     CATListOfCATString _ColumnsWithSelectedCells;

};

//-----------------------------------------------------------------------

#endif
