#ifndef CATStreamArea_H
#define CATStreamArea_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Level L1
  * @CAA2Usage U1
  */


#include "AC0XXLNK.h"
#include "CATBoolean.h"
#include "CATDataType.h"

/**
* Class to define an area.
*/


class ExportedByAC0XXLNK CATStreamArea
{
  public :
  /**
   * Constructs an empty area.
   */
  CATStreamArea();
  virtual ~CATStreamArea();
  
  /** 
  * Assigns an area to an another one.
  * @param iArea
  *	       area to assign to this.
  */
  void Put(void* iArea);
  /** @nodoc */
  virtual void* Get();
  
  /** 
  * returns size of the area.
  */
  CATULONG32  length();
  /** @nodoc */
  void          length(CATULONG32  length);

  /** @nodoc */
  virtual CATBoolean IsMultipleArea();

  protected :
  CATBoolean     _multipleArea;

  CATULONG32   _length;
  void *         _area;
};

#ifndef CATStreamArea_Enable_CATMultipleStreamArea
#define CATStreamArea_Enable_CATMultipleStreamArea
#endif

#endif
