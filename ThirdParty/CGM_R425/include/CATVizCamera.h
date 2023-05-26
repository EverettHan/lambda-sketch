#ifndef CATVizCamera_H 
#define CATVizCamera_H
// COPYRIGHT DASSAULT SYSTEMES 2005
//------------------------------------------------------------------------------
// Abstract: Implementation of CATICamera
//------------------------------------------------------------------------------
// Usage:    Internal use only
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATViewerUtility.h"

/**
* Implementation class of the CATICamera interface.
* <b>Role</b>:This implementation class (can not be instanciated) provides 
* the basic methods to manage the name and the type of a camera.
* @see CATICamera
*/
class ExportedByCATVisFoundation CATVizCamera: public CATBaseUnknown
{
   //------------------------------------------------------------------------------
   CATDeclareClass;

public:


   // Destructor
   // ----------
   virtual ~CATVizCamera();

   // CATICamera data
   // Camera name
   /**
   * Returns the name of a camera.
   */
   virtual CATUnicodeString & GetName();

   /**
   * Changes the name of a camera.
   * @param iName
   *    New name of the camera.
   */
   virtual void             SetName(const CATUnicodeString & iName);

   // Camera Type
   /**
   * Returns the type of a camera. 
   * @see CATCameraType
   */
   virtual CATCameraType    GetType();

   // Camera auto reframe
  /**
   * Returns the automatic reframe ability status.
   * @return
   *   <li><tt>0</tt> no automatic reframe</li>
   *   <li><tt>1</tt> automatic reframe</li>.
   */
   virtual int GetReframe() const;

  /**
   * Sets or unsets the automatic reframe ability.
   * @param iReframe
   *   Automatic reframe ability.
   *   <br><b> Legal values</b>:
   *   <li><tt>0</tt> no automatic reframe</li>
   *   <li><tt>1</tt> automatic reframe</li>.
   */
   virtual void SetReframe(const int iReframe);

protected:

   /** nodoc */
   CATCameraType            _cameraType;

   // Protected Constructor
   // ---------------------
   /** nodoc */
   CATVizCamera(CATUnicodeString name, CATCameraType type);

private:

   CATUnicodeString         _cameraName;
   int                      _isReframe;
}; 
#endif
