#ifndef CATICAfrForm_H
#define CATICAfrForm_H

// COPYRIGHT DASSAULT SYSTEMES 2011/05/18

#include "CATAfrItf.h"
#include "CATICAfrComponent.h"
#include "CATUnicodeString.h"
#include "CATCAfrEnum.h"

extern ExportedByCATAfrItf  IID IID_CATICAfrForm ;

//-----------------------------------------------------------------------------
/**
* Interface representing a form.
*/
class ExportedByCATAfrItf CATICAfrForm: public CATICAfrComponent
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


    /**
    * Returns a decorator of the form
    */
    virtual CATCAfrEnum::Decorator GetDecorator () const = 0;

    /**
    * Returns the labels Crop Policy.
    */
    virtual CATCAfrEnum::CropPolicy GetLabelsCropPolicy () const = 0;

    /**
    * Returns the introspectable object from type late.
    */
    virtual HRESULT GetIntroObjectFromTypeLate( CATBaseUnknown** opiObject ) = 0;

    /**
    * Display the element by the id.
    */
    virtual HRESULT DisplayElement( const CATString& iElementId ) = 0;
};
#endif
