// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATICellSelectionController.h
// Define the CATICellSelectionController interface
//
//===================================================================
//
// Usage notes:
//   Interface that should be implemented for support of individual
//   cell selection/pre-selection in a CATListView.
//   In order to enable cell selection on a CATListView, simply make
//   sure the controller specified for the CATListView implements this
//   interface.  A standard implementation of this inteface is
//   provided in module CATView, by class CATCellSelectionController.
//   That implementation should be sufficient for most usages.
//
//===================================================================
//
//===================================================================
#ifndef CATICellSelectionController_H
#define CATICellSelectionController_H

#include "CATViewItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"

extern ExportedByCATViewItf IID IID_CATICellSelectionController;

//------------------------------------------------------------------

/**
 * CATICellSelectionController. Interface to manage cell selection.
 **/
class ExportedByCATViewItf CATICellSelectionController: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

      /** Checks if a cell is selected
       * @param iObj Object to check
       * @param iColID [in]
       *   ID of the column containing the cell.
       * @return 0 if the cell is unselected
       *         1 if the cell is selected
       */
    virtual int IsSelected( CATBaseUnknown_var iNode, const CATString& iColID)=0;

          /** Checks if a cell is pre-selected
       * @param iObj Object to check
       * @param iColID [in]
       *   ID of the column containing the cell.
       * @return 0 if the cell is unselected
       *         1 if the cell is selected
       */
     virtual int IsPreSelected( CATBaseUnknown_var iNode, const CATString& iColID )=0;

      /** Checks if a cell is selected in a column
       * @param iColID [in]
       *   ID of the column containing the cell.
       * @return 0 if the cell is unselected
       *         1 if the cell is selected
       */
     virtual int ACellIsSelectedInTheColumn( const CATString& iColID )=0;

     /**
      * Is called when a cell is selected
      */
     virtual void OnSelect( CATBaseUnknown_var iNode, const CATString& iColID )=0;

     /**
      * Is called when mouse over cell
      */
     virtual void OnMoveOver( CATBaseUnknown_var iNode, const CATString& iColID )=0;
};

CATDeclareHandler( CATICellSelectionController, CATBaseUnknown );
//------------------------------------------------------------------

#endif
