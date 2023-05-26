#ifndef __CATFmuPreferences_H
#define __CATFmuPreferences_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2006
//=============================================================================
/**
 * @level Protected
 * @usage U1
 */
#include "CATUnicodeString.h"
#include "ExportedByCATFmuTools.h"

class CATDialog;
class CATString;
/**
 * This class is used to get, set and release the data associated with OpenSavePreferences. 
 */
class ExportedByCATFmuTools CATFmuPreferences
{

   public :
   /**
    * First Static method to Get the data associated to a 'class' of an object. 
	*/
   static void GetAnchor     ( CATUnicodeString iPKey, CATFmuPreferences ** oAnchor );
   /**
    * First Static method to Release the data associated to a 'class' of an object.
	*/
   static void ReleaseAnchor ( CATFmuPreferences * oAnchor );
   /**
    * Final Cleanup (Automatic in Record Replay mode)
	*/
   static int  Unmake        ( int irc ); // 
   /**
    * Computes the key using iParent and iName to return oKey
	*/
   static void ComputeKey    ( CATDialog* iParent, const CATString& iName, CATUnicodeString & oKey );
   
   enum PreferenceType
   {
      PT_Undef = 0,
      PT_LastFullFileName,
      PT_LastLocation,
      PT_LastExtension,
      PT_LastWidth,
      PT_LastHeight,
      PT_LastDetailMode,
      PT_LastDetailNameWidth,
      PT_LastDetailTypeWidth,
      PT_LastDetailSizeWidth,
      PT_LastDetailTimeWidth,
      PT_LastCompactNameWidth
   };
   
   /**
    * Class method to Set the Preference's type of an object
	* Adding, Getting and Cleaning items on a Storage
	*/
   void SetPreference ( PreferenceType iKey, CATUnicodeString   iValue );
   /**
    * Class method to Get the Preference's type of an object
	* Adding, Getting and Cleaning items on a Storage
	*/
   void GetPreference ( PreferenceType iKey, CATUnicodeString & oValue );
   /**
    * Class method to Set the Preference's type of an object
	* Adding, Getting and Cleaning items on a Storage
	*/
   void SetPreference ( PreferenceType iKey, int                iValue );
   /**
    * Class method to Get the Preference's type of an object
	* Adding, Getting and Cleaning items on a Storage
	*/
   void GetPreference ( PreferenceType iKey, int              & oValue );

   private :
   CATFmuPreferences ( CATUnicodeString iPKey );
   ~CATFmuPreferences ();
   void Write ( );


   // Anchor List Management
   static CATFmuPreferences  * __anchor;
   CATFmuPreferences         * __next;
   static int                  __nb;
   static int                  __OnceOnly;
   
   // Inside Anchor Management
   CATUnicodeString _PKey;
   CATUnicodeString _LastFullFileName;
   CATUnicodeString _LastLocation;
   CATUnicodeString _LastExtension;
   int              _LastWidth;
   int              _LastHeight;
   int              _LastDetailMode;
   int              _LastDetailNameWidth;
   int              _LastDetailTypeWidth;
   int              _LastDetailSizeWidth;
   int              _LastDetailTimeWidth;
   int              _LastCompactNameWidth;

};

#endif
