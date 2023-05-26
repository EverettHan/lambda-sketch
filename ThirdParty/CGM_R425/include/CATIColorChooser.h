//===================================================================
// COPYRIGHT Dassault Systemes 2007
//===================================================================

#ifndef CATIColorChooser_H
#define CATIColorChooser_H

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATVisColorChooser.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATDlgFrame;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisColorChooser IID IID_CATIColorChooser;
#else
extern "C" const IID IID_CATIColorChooser ;
#endif

//------------------------------------------------------------------

/**
 * Interface to implement the color chooser plug-in.
 * <b>Role</b>:
 * This interface allows to add applicative color chooser plug-in to the color editor panel.
 * <br>It should be derived and plug-in should provide
 * an extension of the color editor panel (CATVisColorEditorPanel)
 */
class ExportedByCATVisColorChooser CATIColorChooser: public CATBaseUnknown
{
   CATDeclareInterface;

   public:

    /**
     * Returns the name of the color chooser plug-in.
     */
     virtual CATUnicodeString & GetColorChooserName() = 0;

    /**
     * Returns the frame of the color chooser plug-in.
     */
     virtual CATDlgFrame * GetColorChooserFrame() = 0;

  // --------------------------------------------------------------
};

#endif
