// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIAfrGridWrapper.h
// Define the CATIAfrGridWrapper interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jul 2009  Creation: Code generated by the CAA wizard  LD3
//===================================================================
#ifndef CATIAfrGridWrapper_H
#define CATIAfrGridWrapper_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrGridWrapper;
#else
extern "C" const IID IID_CATIAfrGridWrapper ;
#endif

//------------------------------------------------------------------

class CATCommand;
class CATString;
/**
* Interface representing the layout grid to contain widget.
*
* <br><b>Role</b>: Provide methods to attach a wrapped widget in a wrapped grid.
* It is useful to attach the button and combo of PLM Bar in a single grid
*
* Do not implement the CATIAfrGridWrapper interface outside of @href CATAfrGridWrapper class
* Do not use the CATIAfrGridWrapper interface outside of @href CATAfrGridWrapper class
*/
class ExportedByCATAfrItf CATIAfrGridWrapper: public CATBaseUnknown
{
  CATDeclareInterface;

  public:



    /**
    *  Instanciate the grid.
    *  @param iParent
    *     the parent command
    *  @param name
    *     the Grid name
    *  @param mode
    *     the representation mode (Ex: 0 -> Dialog, 1 -> VID, ...)
    */
    virtual void InstanciateGrid(CATCommand * iParent,const CATString&  name, int mode)= 0;

    /**
    *  Destroy the grid
    */
    virtual void DestroyGrid()= 0;


   /**
    *  Set a specific constraints for a widget.
    *  @param iWidget
    *     the widget to add with the defined constraints
    */
    virtual void GridWrapperSetConstraints(CATCommand * iWidget)=0;

   /**
    *  Get the original layout grid (Ex: @href CATVidLayGrid).
    */
    virtual CATCommand * GridWrapperGetOriginalGrid()=0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif