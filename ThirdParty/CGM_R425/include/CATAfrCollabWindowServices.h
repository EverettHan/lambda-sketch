//===================================================================
// COPYRIGHT Dassault Systemes 2010/04/14
//===================================================================
// CATAfrCollabWindowServices
//  
//===================================================================
//
// Usage notes: Do not use, reserved for ApplicationFrame internal use
//
//===================================================================
//  2011/10/10 Creation: - proto OST
//===================================================================
#ifndef CATAfrCollabWindowServices_H
#define CATAfrCollabWindowServices_H

#include "CATAfrItf.h"

class ExportedByCATAfrItf CATAfrCollabWindowServices
{
public:

  static void CollaborateNextWindow(int collab) ;
  static void ResetNextWindowCollaborationDefault() ;
  static int  IsNextWindowCollaborated() ;

private:
  //friend class CATAfrCollabFrmWindow ;
  static int is_next_window_collaborated ;
};

//-----------------------------------------------------------------------

#endif
