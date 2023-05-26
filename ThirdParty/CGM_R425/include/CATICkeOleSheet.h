// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATICkeOleSheet.h:
//
//=============================================================================
// Usage Notes:
//
// see below
//
// 
//
//
//=============================================================================
// 08/06/98   Creation                                   T. Videcoq
//=============================================================================

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */

/*  CAA2Reviewed by FRH */

 /**
 * This interface is an encapsulation of an array of arrays (a sheet) of strings contained in a file.
 *
 * The file has to be an excel or a lotus sheet file. Its format has to be :
 * <table frame="border">
 * <tr><td>string<sub>1,1</sub></td><td>string<sub>1,2</sub></td><td>...</td></tr>
 * <tr><td colspan="3">(n-2 lines)</td></tr>
 * <tr><td>string<sub>n,1</sub></td><td>string<sub>n,2</sub></td><td>...</td></tr>
 * </table><br>
 * Empty strings are allowed, but not in the first row because the number of
 * columns is computed using the first row, except if you use the forceWidth
 * argument of the @href CATICkeSheet#UpdateLocalCopy method.<br>
 *
 * To create a CATICkeOleSheet, use the @href CATICkeRelationFactory#CreateSheet method
 * with an excel or a lotus file path as argument.
 *
 * @see CATIDesignTable, CATICkeSheet, CATICkeTextSheet
*/


#ifndef CATICkeOleSheet_H
#define CATICkeOleSheet_H

#include "KnowledgeItf.h"

#include "CATICkeSheet.h"

#include "CATICkeRelationForwards.h"
#include "CATEventSubscriberTypedefs.h"

class CATCommand;

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeOleSheet;
#else
extern "C" const IID IID_CATICkeOleSheet;
#endif

class ExportedByKnowledgeItf CATICkeOleSheet : public CATICkeSheet
{
	CATDeclareInterface;

public:
    /**
    * @nodoc to be replaced by a better service
	* Sets the ole file source of the sheet.
	* @param theSheet
	* the CATBaseUnknown containing the link to the file
	*/
	virtual void SetOleSource(const CATBaseUnknown_var &theSheet) = 0;

	/**
    * @nodoc to be replaced by a better service
	* @return the CATBaseUnknown containing the link to the ole source.
	* Returns NULL_var under Unix or if no file was associated to this object
	*/
	virtual const CATBaseUnknown_var GetOleSource() const = 0;

	/**
	* Returns the notification associated with the modification of the OLE doc.
	* The notification is sent when the OLE doc. has been modified, and Ole doc viewer closed
	* (the sheet can't be parsed if Ole doc. is opened and sends notifications to CATIA)
	*/
	virtual CATCallbackEvent GetOleModifyAndCloseNotification() = 0;

	/**
	* Sets the index of the sheet in the workbook. This method has to be called before any call of CATICkeSheet::UpdateLocalCopy
	* @param index
	* index of the sheet in the workbook. Minimum value : 1 
	*/
	virtual void SetSheetIndex(int index) = 0;

	/**
	* Returns the index of the sheet in the workboook where data has to be found.
	*/
	virtual int GetSheetIndex() = 0;

	/**
    * @nodoc to be exposed
	* Indicates if auto formatting has to be done on SetCell. 
	* @param mode
	* 1 for autoformat active, 0 else
	*/
	virtual void SetAutoFormatMode(int mode) = 0;

	/**
	* @nodoc to be suppressed
	* Do not use! Internal use only.
	*/
	virtual void ActivateOleNotifications() = 0;
};
CATDeclareHandler(CATICkeOleSheet,CATICkeSheet);

#endif
