#ifndef CATVidDialogModificationNotif_H
#define CATVidDialogModificationNotif_H

// COPYRIGHT DASSAULT SYSTEMES 2004

//===========================================================================
//  Inheritance:
//  ------------
//            CATNotification  ( System Framework)
//               CATBaseUnknown (System Framework).
//
//===========================================================================

// System Framework 
#include "CATNotification.h" // to derive from 
// Local framework
#include "VisuDialog.h" // Needed to export the class 

enum CATVidDialogModificationType {VidExtract, VidInsert, VidMinimized, VidMaximized};

class ExportedByVisuDialog CATVidDialogModificationNotif : public  CATNotification
{
  // Used in conjunction with CATImplementClass in the .cpp file 
  CATDeclareClass;
public :
  
  CATVidDialogModificationNotif (CATVidDialogModificationType i_type) ;
  CATVidDialogModificationNotif(const CATVidDialogModificationNotif &iObjectToCopy);

  virtual ~CATVidDialogModificationNotif();
  void SetModificationType(CATVidDialogModificationType i_type);
  CATVidDialogModificationType GetModificationType();
  
protected:
  CATVidDialogModificationType _type;
};

#endif
