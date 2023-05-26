#ifndef CATGROUPPOLICY_INCLUDE
#define CATGROUPPOLICY_INCLUDE
// Copyright DASSAULT SYSTEMS 2000
//-----------------------------------------------------------------------------
// Abstract:	CATGroupPolicy  Get the Group Policies status
//-----------------------------------------------------------------------------
//
// Recuperation des polices comportementales specifiee par le systeme (enfin, par W2000)
// car sur les autres OS, on rend systematiquement NotActivated.
//
// Utilisation: 
// Par une methode statique CATGroupPolicy::Get ( Key )
// Au premier appel de la methode Get, la methode privee Make est appelee et charge l'ensemble des polices comportementales.
// //En fin de session, faire une appel explicite a la methode CATGroupPolicy::UnMake () <-- Pas Vraiment Utile

#include "JS0LIB.h"

class ExportedByJS0LIB CATGroupPolicy {

public:

   ~CATGroupPolicy ();

   // Pour sortir proprement. (Pas vraiment utilile)
   static void UnMake ();

   // Available Group Policies (among the 10 Windows 2000 is specifying)
   typedef enum {
      Remove_Run_menu                                = 1 << 0,
      Hide_these_specified_drives                    = 1 << 1,
      Run_only_allowed_Windows_Application           = 1 << 2,
      Remove_Map_Network_Drive                       = 1 << 3,
      No_Entire_Network_in_My_Network_Places         = 1 << 4,
      Do_not_keep_history_of_recently_open_documents = 1 << 5,
      Disable_Remove_the_Shut_Down_command           = 1 << 6,
      Hide_Common_Dialog_places_Bar                  = 1 << 7,
      Hide_Common_Dialog_Back_button                 = 1 << 8,
      Remove_Common_Dialog_MRU_dropdown              = 1 << 9
   } Policy;

   // Group Policy Status (for all of the 10 group policies defined by Windows 2000)
   typedef enum {
      NotSuchPolicy = -2,
      NotApplicable = -1,
      NotActivated  = 0,
      Activated     = 1
   } PolicyStatus;

   static const CATGroupPolicy::PolicyStatus Get ( const CATGroupPolicy::Policy policy );
   static const CATGroupPolicy::PolicyStatus Get_HiddenDrives ( unsigned int & val );

   protected :

   CATGroupPolicy ();  // Pour pouvoir etre tester par une classe derivee CATGroupPolicyTest

   static CATGroupPolicy::PolicyStatus I_Remove_Run_menu                               ;
   static CATGroupPolicy::PolicyStatus I_Hide_these_specified_drives                   ;
   static CATGroupPolicy::PolicyStatus I_Run_only_allowed_Windows_Application          ;
   static CATGroupPolicy::PolicyStatus I_Remove_Map_Network_Drive                      ;
   static CATGroupPolicy::PolicyStatus I_No_Entire_Network_in_My_Network_Places        ;
   static CATGroupPolicy::PolicyStatus I_Do_not_keep_history_of_recently_open_documents;
   static CATGroupPolicy::PolicyStatus I_Disable_Remove_the_Shut_Down_command          ;
   static CATGroupPolicy::PolicyStatus I_Hide_Common_Dialog_places_Bar                 ;
   static CATGroupPolicy::PolicyStatus I_Hide_Common_Dialog_Back_button                ;
   static CATGroupPolicy::PolicyStatus I_Remove_Common_Dialog_MRU_dropdown             ;

   static int Make_not_done;

   static unsigned int Drives;

   private :
   static int Make ();

};
#endif
