#ifndef CATColorManager_H
#define CATColorManager_H
//
// CATIA Version 5 Release 18 Framework Visualization
// Copyright Dassault Systemes 2007
//------------------------------------------------------------------------------
// Abstract : 	basic class which allows to manage the current color
// ----------   
//	
//------------------------------------------------------------------------------
// Usage :	is used by application which wants to apply the current color
// -------      
//
//------------------------------------------------------------------------------
// Main methods :  GetColorManager()
// --------------
//------------------------------------------------------------------------------
// Class :	CATColorManager
// -------        CATCommand (System)
//------------------------------------------------------------------------------

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATVisColorChooser.h"
#include "CATCommand.h"

class CATVisColorManager;


/**
 * Class to manage color definition, modification and application.
 * <b>Role</b>:
 * This static object allows to define, to modify and to apply color in applications.
 * <br>All applicative color chooser plug-ins should use this class to transmit
 * the results of their interactions.
 */

class ExportedByCATVisColorChooser CATColorManager : public CATCommand
{
   CATDeclareClass ;

//------------------------------------------------------------------------------

public:

 /**
   * Event sent when the current defined color is changed.
	* <br><b>Role:</b><br>this event is sent by the CATColorManager.
	* <br>Sample of callback:
	* <pre>
   *  ::AddCallback(this,
   *                CATColorManager::GetColorManager(),
	*	              CATColorManager::CURRENT_COLOR_CHANGED(),
	*	              (CATSubscriberMethod)&MyClass::MyCBMethod,
	*	              NULL);
	* </pre>
	*/
   CATDeclareCBEvent(CURRENT_COLOR_CHANGED);
 /**
   * Event sent when the new color is changed.
	* <br><b>Role:</b><br>this event is sent by the CATColorManager.
	* <br>Sample of callback:
	* <pre>
   *  ::AddCallback(this,
   *                CATColorManager::GetColorManager(),
	*	              CATColorManager::NEW_COLOR_CHANGED(),
	*	              (CATSubscriberMethod)&MyClass::MyCBMethod,
	*	              NULL);
	* </pre>
	*/
   CATDeclareCBEvent(NEW_COLOR_CHANGED);

 /**
   * Returns the CATColorManager pointer.
   */
   static  CATColorManager * GetColorManager();

 /**
   * Returns the current defined color.
   * The legal value for R, G, B color components is in [0, 1].
   */
   virtual HRESULT GetCurrentColorRGB(float * oR, float * oG, float * oB) = 0;
 /**
   * Sets the current defined color.
   * The legal value for R, G, B color components is in [0, 1].
   */
   virtual HRESULT SetCurrentColorRGB(const float iR, const float iG, const float iB) = 0;

 /**
   * Returns the new defined color.
   * The legal value for R, G, B color components is in [0, 1].
   */
   virtual HRESULT GetNewColorRGB(float * oR, float * oG, float * oB) = 0;
 /**
   * Sets the new defined color.
   * The legal value for R, G, B color components is in [0, 1].
   */
   virtual HRESULT SetNewColorRGB(const float iR, const float iG, const float iB) = 0;

//------------------------------------------------------------------------------
protected:

   virtual ~CATColorManager();

//------------------------------------------------------------------------------
private:

   friend class CATVisColorManager;

private:

   CATColorManager();
   CATColorManager(const CATColorManager &);               // no copy constructor
   CATColorManager& operator = (const CATColorManager &);  // no equal operator
};

#endif
