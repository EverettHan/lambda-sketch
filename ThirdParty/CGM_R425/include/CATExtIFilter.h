
#ifndef _CATExtIFilter_h
#define _CATExtIFilter_h

#include "CATBaseUnknown.h"
#include "CATInteractiveInterfaces.h"


/**
  * Adapter class for the CATIFilter interface.
  *
  * To implement the interface <tt>CATIFilter</tt> for a class <tt>MyClass</tt>,
  * write a class <tt>MyClassExtIFilter</tt> subclassed from 
  * <tt>CATExtIFilter</tt> and defined as an extension of <tt>MyClass</tt>. 
  * something like   CATImplementClass(MyClassExtIFilter,ExtentionType,CATExtIFilter, MyClass)
  * In <tt>MyClassCATExtIFilter</tt> if wants that visualization should not be shown for object of MyClass 
  * type then override VisuFilterRequired method and return FALSE.
  * @see CATIFilter 
  */

class ExportedByCATInteractiveInterfaces CATExtIFilter : public CATBaseUnknown
{
  CATDeclareClass;

  public:
	  CATExtIFilter();
	  virtual ~CATExtIFilter();

	/**
    * @nodoc 
    * return a FALSE from your overridden method if you do not want to show visualizaton filter
    */
	  virtual CATBoolean VisuFilterRequired();

};

#endif
