/**
 * @level Protected
 * @usage U1
 */
#ifndef CATFmuFileAdminFrame_H
#define CATFmuFileAdminFrame_H

#ifndef _DS_COMPUTE_SERVER

#include "ExportedByCATFmuFileAdminUI.h"
#include "CATDlgFrame.h"

class CATIFmuFileAdminSettingAtt;
class CATIAFileAdminSettingAtt;
class CATDlgCheckButton;
class CATDlgLock;
/**
 * This class builds necessary Dialogframe for File administration in upperCase/lockedUpperCase mode.
 * It takes input from the frame for doing so.
 * Further depending on the mode selected it sets the respective assosiated dialog frame.
 */
class ExportedByCATFmuFileAdminUI CATFmuFileAdminFrame : public CATDlgFrame
{
   DeclareResource(CATFmuFileAdminFrame,CATDlgFrame)

public:
   CATFmuFileAdminFrame ( CATDialog * father, const CATString & name );
   ~CATFmuFileAdminFrame ( );

   void Build ();
   void ValueSettings ();

   void SetDefault         ( );

private:
   void ManageFileAdmin    ( CATCommand *, CATNotification *, CATCommandClientData );

   CATDlgCheckButton          * _upper_case_mode;
   CATIFmuFileAdminSettingAtt * _FileAdminAttr;
   CATIAFileAdminSettingAtt   * _FileAdminAttrVB;
};
#endif
#endif
