// COPYRIGHT Dassault Systemes 2009
#ifndef CATIListComboEditModel_H
#define CATIListComboEditModel_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATListOfCATUnicodeString.h>


extern ExportedByCATViewItf IID IID_CATIListComboEditModel;

/*
 * CATIListComboEditModel. 
 *   Interface to modify the model in a list view
 *   with a Combo Box.
 */
class ExportedByCATViewItf CATIListComboEditModel: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	  /**
       * Gets the lines of the ComboBox in order to edit a cell.
	   * @param iObj The object to edit
	   * @param iColID The column ID of the object to edit
	   * @param oDropList The lines for the Combo
	   * @param oIsEditable Determines whether the Combo Box might be edited by keyboard entry
       * @return S_OK A Combo Box should be used instead of a Text Editor
       *         E_FAIL A Combo Box won't be used
       */
      virtual HRESULT GetDropList( const CATBaseUnknown_var& iObj, 
								   const CATString& iColID,
								   CATListOfCATUnicodeString& oDropList,
								   CATBoolean& oIsEditable )=0;

};

CATDeclareHandler( CATIListComboEditModel, CATBaseUnknown );


#endif
