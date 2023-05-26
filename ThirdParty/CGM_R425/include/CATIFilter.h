/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2010
#ifndef _CATIFilter_h
#define _CATIFilter_h

#include "CATBaseUnknown.h"

/**
 * Interface for visualization filter under Tools->Visu filters.
 * <br> The new methodology to show/ do not show a visualization filter is as following:
 * <ul>
 * for a class MyClass write a class <tt>MyClassExtIFilter</tt> subclassed from 
 * <tt>CATExtIFilter</tt> and defined as an extension of <tt>MyClass</tt>. 
 * override the VisuFilterRequired and return FALSE if you do not want to show visualizaton filter 
 * for your object. By default visualizaton filter is visible for all.
 * </ul>
 */

#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIFilter;
#else
extern "C" const IID IID_CATIFilter;
#endif


class ExportedByCATInteractiveInterfaces CATIFilter : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
	/**
    * @nodoc 
    * return a FALSE from your overridden method if you do not want to show visualizaton filter
    */
    virtual CATBoolean VisuFilterRequired() = 0;

};
CATDeclareHandler(  CATIFilter, CATBaseUnknown ) ;

#endif
