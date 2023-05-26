/* -*-c++-*- */
#ifndef CATImportSettingBehavior_h
#define CATImportSettingBehavior_h
/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************
// COPYRIGHT DASSAULT SYSTEMES   2000

/**
 *   The behavior regarding the 'Keep link with the selected object' setting.
 *   <br><b>Legal values</b>: <ul>
 *   <li><tt>UseSettingValue</tt>: the setting value is used for the treatment.</li>
 *   <li><tt>NoKeepLinkValue</tt>: overrides the setting value in order to create no link with the selected element.</li>
 *   <li><tt>KeepLinkValue</tt>: overrides the setting value in order to create the link with the selected element.</li>
 *   <li><tt>KeepAssociativityValue</tt>: overrides the setting value in order to create no link with the selected element but keep associativity.</li></ul>
 */

enum CATImportSettingBehavior { UseSettingValue=-1, NoKeepLinkValue=0, KeepLinkValue=1, KeepAssociativityValue=2};

#endif
