#ifndef __CATIAfrPaletteSingleton_h
#define __CATIAfrPaletteSingleton_h

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"

class CATCmdContainer;
class CATDialog;

extern ExportedByCATAfrFoundation IID IID_CATIAfrPaletteSingleton;


/**
 * @nodoc
 * Interface allowing interface implementation delegation
 * on an object
 */
class ExportedByCATAfrFoundation CATIAfrPaletteSingleton : public CATBaseUnknown
{
	
  CATDeclareInterface;
  
public:

	/**
	 * @nodoc
	 * Instanciates the Palette singleton if possible
	 */
  virtual CATCmdContainer *GetPaletteSingleton () = 0;

	/**
	 * @nodoc
	 * Displays or Hides the Palette depending of its content
	 */
  virtual void CheckVisibility() = 0;

	/**
	 * @nodoc
	 * Displays the Palette
	 */
  virtual int  Show(CATDialog * parent) = 0;

};

#endif
