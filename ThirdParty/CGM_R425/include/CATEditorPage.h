#ifndef CATEditorPage_h
#define CATEditorPage_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */
//

#include "CATAfrProperties.h"
#include "PropertyMode.h"
#include "CATDlgContainer.h"

/**
* Class to define/get state of the TabPage for the properties editors .
*/

class ExportedByCATAfrProperties CATEditorPage: public CATDlgContainer
{
public:

	/**
	* Constructs a CATEditor .
	* @param iParent
	*        dialog parent of the object.
	* @param iName
	*        name of the object.
	*/
	CATEditorPage(CATDialog *iParent, const CATString& iName);
  ~CATEditorPage();

	/**
	* Sets the state of the tabpage.
	* @see ModeYesNo
	* @param iMode
	*        Yes if the tabpage has been modified
	*         <br> else, No.
	*/
  void SetPageModification(ModeYesNo iMode);
  
	/**
	*	@nodoc
	*/
  ModeYesNo SetBuildMode();

	/**
	*	@nodoc
	*/
  ModeYesNo GetPageModification();

	/**
	*	@nodoc
	*/
  ModeYesNo IsBuilt();

	/**
	* Sets built state to the tabpage .
  */
  void SetBuilt();

private:

  ModeYesNo _build, _change;

};

#endif
