// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATKeybdEvent_H
#define CATKeybdEvent_H

#include "CATVisFoundation.h"


#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
#include <X11/Xlib.h>
#include <Xm/Xm.h>
#endif

#include "CATNotification.h"
#include "CATDataType.h"
#include "CATKeybdEventType.h" // def of CATKeyCode, CATModifier

class ExportedByCATVisFoundation CATKeybdEvent : public CATNotification
{
  CATDeclareClass;

public:

  /* obsolete: do not use */
  CATKeybdEvent ( void);



  //Constructor for virtual key code
  CATKeybdEvent(CATKeybdType iType, CATUINT32 iKey, CATUINT32 iModifier, CATUINT32 iTime);
  //Constructor for ASCII char code
  CATKeybdEvent(CATUINT32 iCharCode, CATUINT32 iModifier, CATUINT32 iTime, CATKeybdType iType = CATPress);
  //Constructor for RecordReplay : with CATKeycode
  CATKeybdEvent(CATKeyCode code, CATModifier mod, CATKeybdType type, CATUINT32 iTime, CATModifier exclude);

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
  CATKeybdEvent ( XEvent*);
#endif

  

   //These constructors are used for comparison with another CATKeyBdEvent
   // if one of the two events is a mask event ( created for test purpose
   // and thus not time stamped ) then we test if the specified conditions
   // are matched by the other event 
   // example
   //
   // OnEvent (..., CATKeybdEvent& Event)
   //  {
   //    CATKeybdEvent maskEvent(F1, Shift, Control ) // Shift+F1 but not Crtl,Shift + F1
   //  if (maskEvent & Event)
   //   { // it is a Shift F1 event
   //    ...... code here
   //   }
  CATKeybdEvent ( CATKeyCode code, CATModifier mod, CATKeybdType type = CATPress, CATModifier exc = CATNone); 
  CATKeybdEvent ( char* str, CATModifier mod, CATKeybdType type = CATPress, CATModifier exc = CATNone );
 ~CATKeybdEvent ( void); 

  
  CATULONG32    _time;       
  char*         _string;    //obsolete: do not use it
  CATKeyCode    _key;       //don't use it directly, use GetKeyCode() instead.
  CATModifier   _modifiers; //don't use it directly, use GetModifier() instead.
  CATModifier   _exclude;	// modifiers to be excluded from the comparison of 2 events (cf. operator &)
  char          _buffer[32];//obsolete: do not use it
  int           _type;		// Press or Release

  int operator &  ( CATKeybdEvent& );

  void Print ( void);

  inline void SetKeyCodeType(int i_keyCodeType){_keyCodeType = i_keyCodeType;}
  inline void SetCharCode(CATUINT32 i_charCode){_charCode = i_charCode;}
  inline void SetVKCode(CATUINT32 i_VKCode){_VKCode = i_VKCode;}
  inline void SetRepeat(int iRepeat) { _repeat = iRepeat; }
  // GetKeyCodeType returns 0=character or 1=keycode;
  inline int         GetKeyCodeType() const{return _keyCodeType;} 

  // GetCharCode returns ascii code of a key
  inline CATUINT32   GetCharCode() const   {return _charCode;}    // unicode of character 

  // GetKeyCode gives CATIA code value for each key : this translation is done in InitKeyCode ()
  // CATIA code is meant to be the same independently of the OS
  inline CATKeyCode  GetKeyCode() const    {return _key;}   

  // GetModifier : 
  // _modifiers is a binairy sum of the codes for CATControl, CATShift, CATAlt, CATNumLock, CATScrollLock
  // (in case these keys are active in the KeyboardState)
  // the value of modifiers is computed in CATWindowsDrawingArea
  // _modifiers are positioned in the constructor of this class
  // GetModifier enables a listener to know if there is a combination of keyboard keys participating together
  // in the present event
  inline CATModifier GetModifier() const   {return _modifiers;}

  // GetVKCode :
  // gives a code for a key. These code is specific to Windows OS
  inline CATUINT32   GetVKCode() const     {return _VKCode;}

  // IsRepeat : 1 : holding down the key . 0 : otherwise
  // CATKeybdType _type is used to describe the state of the key : CATPress or CATRelease)
  inline int         IsRepeat() const      {return _repeat;}

  // Queries describing the event :
  inline int        IsPressKey() const     {return _type==CATPress; }
  inline int        IsReleaseKey () const  {return _type==CATRelease; }
  inline int        IsKeyCode () const     {return _keyCodeType==1; }
  inline int        IsChar() const         {return _keyCodeType==0; }
  static int  GetKeyFromCATKeyCode(CATKeyCode ikeycode);

  static CATKeyCode  GetCATKeyCodeFromVkCode(int iVKcode);
 

private:

#if defined (_LINUX_SOURCE) && defined (_GTK_SOURCE)
   static int GetGdkKeySymFromCATKeyCode(CATKeyCode ikeycode);
#endif
#if defined (_LINUX_SOURCE) && !defined (_GTK_SOURCE)
	static int  GetKeySymFromCATKeyCode(CATKeyCode ikeycode);
#endif  
#if defined (_WINDOWS_SOURCE)
	static int  GetVkeyFromCATKeyCode(CATKeyCode ikey);
#endif
#if defined(_COCOA_SOURCE) && defined (_DARWIN_SOURCE) 
    CATKeyCode InitNSKeyCode(CATUINT32 ikey);
#endif
    
#if defined (_WINDOWS_SOURCE) || defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE) || defined (_GTK_SOURCE)
   CATKeyCode InitKeyCode(CATUINT32 ikey);
#else
   CATKeyCode InitKeyCode(KeySym ikey);
#endif


   CATUINT32 _charCode;			 // unicode of character
   int       _keyCodeType;		// 0=character; 1=keycode;
   CATUINT32 _VKCode;			// virtual key code
   int       _repeat;			// 1 : holding down the key
  // CATModifier   _exclude;		// modifiers to be excluded from the comparison of 2 events (cf. operator &)
};

#endif
