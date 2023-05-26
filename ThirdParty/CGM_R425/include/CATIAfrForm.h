#ifndef CATIAfrForm_H
#define CATIAfrForm_H

// COPYRIGHT DASSAULT SYSTEMES 2011/05/18

#include "CATAfrItf.h"
#include "CATICAfrComponent.h"
#include "CATUnicodeString.h"

extern ExportedByCATAfrItf  IID IID_CATIAfrForm ;

//-----------------------------------------------------------------------------
/**
* NODOC Don't use see the interface CATICAfrForm
*/
class ExportedByCATAfrItf CATIAfrForm: public CATICAfrComponent
{
  CATDeclareInterface;

  public:



    ///**
    //* @return the visibility Flag of the form
    //*   <br>
    //* The visibility Flag of the form can be:
    //*   <dl>
    //*   <dt><tt>FALSE</tt><dd> not display the visibility,
    //*   <dt><tt>TRUE</tt><dd> the visibility is displayed.
    //*   </dl>
    //*/
    //virtual const CATBoolean GetVisibility() const = 0;

    /**
    * @return the grid Flag of the form
    *   <br>
    * The grid Flag of the form can be:
    *   <dl>
    *   <dt><tt>FALSE</tt><dd> not display the grid,
    *   <dt><tt>TRUE</tt><dd> the grid is displayed.
    *   </dl>
    */
    virtual const CATBoolean GetGridFlag() const = 0;

    /**
    * @return the alternate background Flag of the form
    *   <br>
    * The alternate background Flag of the form can be:
    *   <dl>
    *   <dt><tt>FALSE</tt><dd> not display the alternate background,
    *   <dt><tt>TRUE</tt><dd> the alternate background is displayed.
    *   </dl>
    */
    virtual const CATBoolean GetAlternateBackgroundFlag() const = 0;

    /**
    * Returns a flag that enable to set Decorator Expand mode
    */
    virtual const CATBoolean GetDecoratorExpandFlag() const = 0;

    enum Decorator
    {
      Undef          = 0, 
      Separator      = 1, 
      Expander       = 2, 
      GroupBox       = 3, 
      Frame          = 4, 
      TabPage        = 5, 
      Left_TabPage   = 6, 
      ScrollableArea = 7
    };

    /**
    * Returns a decorator of the form
    */
    virtual CATIAfrForm::Decorator GetDecorator () const = 0;

    enum CropPolicy
    {
      NoCrop       = 0, 
      CropCut      = 1, 
      CropWithDots = 2
    };

    /**
    * Returns the labels Crop Policy.
    */
    virtual CATIAfrForm::CropPolicy GetLabelsCropPolicy () const = 0;

};
#endif
