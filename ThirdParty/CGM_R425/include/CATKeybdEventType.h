// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATKeybdEventType_H
#define CATKeybdEventType_H

typedef unsigned int CATModifier;
typedef unsigned int CATKeyCode;

enum // modifier flags
{
  CATNone       = 0x00000000,
  CATControl    = 0x00000001,
  CATShift      = 0x00000002,  
  CATAlt        = 0x00000004, 
  CATCapsLock   = 0x00000008,  
  CATNumLock    = 0x00000010,
  CATScrollLock = 0x00000020,
  CATPause      = 0x00000040,
  CATMeta       = 0x00000080,
  CATButton1    = 0x00000100,   
  CATButton2    = 0x00000200,
  CATButton3    = 0x00000400,
  CATButton4    = 0x00000800,
  CATButton5    = 0x00001000,

  // Combos
  CATAnyButton  = 0x00001f00
} ;

//enum CATKeyCode// keys keyodes
enum
{

  CATKeyCode_None       = 0x00000000,

  CATF1  = 0x00010000, // VK_F1
  CATF2  = 0x00020000, // VK_F2
  CATF3  = 0x00030000, // VK_F3
  CATF4  = 0x00040000, // VK_F4
  CATF5  = 0x00050000, // VK_F5
  CATF6  = 0x00060000, // VK_F6
  CATF7  = 0x00070000, // VK_F7
  CATF8  = 0x00080000, // VK_F8
  CATF9  = 0x00090000, // VK_F9
  CATF10 = 0x000a0000, // VK_F10
  CATF11 = 0x000b0000, // VK_F11
  CATF12 = 0x000c0000, // VK_F12
  CATF13 = 0x000d0000, // VK_F13
  CATF14 = 0x000e0000, // VK_F14
  CATF15 = 0x000f0000, // VK_F15
  CATF16 = 0x00110000, // VK_F16
  CATF17 = 0x00120000, // VK_F17
  CATF18 = 0x00130000, // VK_F18
  CATF19 = 0x00140000, // VK_F19
  CATF20 = 0x00150000, // VK_F20
  CATF21 = 0x00160000, // VK_F21
  CATF22 = 0x00170000, // VK_F22
  CATF23 = 0x00180000, // VK_F23
  CATF24 = 0x00190000, // VK_F24

   
 // CATKeyCode_Esc       = 0x00100000, // VK_ESCAPE 
  CATEsc		       = 0x00100000, // VK_ESCAPE 
  //CATKeyCode_Insert    = 0x00200000, // VK_INSERT 
  CATInsert    = 0x00200000, // VK_INSERT 
 // CATInsert			   = 0x00200000, // VK_INSERT 
  //CATKeyCode_Home      = 0x00300000, // VK_HOME
   CATHome      = 0x00300000, // VK_HOME
  //CATKeyCode_PageUp    = 0x00400000, // VK_PRIOR
  CATPageUp			   = 0x00400000, // VK_PRIOR
  //CATKeyCode_Del       = 0x00500000, // VK_DELETE
  CATDel			   = 0x00500000, // VK_DELETE
  //CATKeyCode_End       = 0x00600000, // VK_END 
  CATEnd       = 0x00600000, // VK_END 
  //CATKeyCode_PageDown  = 0x00700000, // VK_NEXT
  CATPageDown		   = 0x00700000, // VK_NEXT
 // CATKeyCode_Up        = 0x00800000, // VK_UP
  CATUp				   = 0x00800000, // VK_UP
  //CATKeyCode_Left      = 0x00900000, // VK_LEFT
  CATLeft              = 0x00900000, // VK_LEFT
  //CATKeyCode_Down      = 0x00a00000, // VK_DOWN
  CATDown			   = 0x00a00000, // VK_DOWN
 // CATKeyCode_Right     = 0x00b00000, // VK_RIGHT 
  CATRight			   = 0x00b00000, // VK_RIGHT 

  //CATKeyCode_Backspace = 0x00c00000, // VK_BACK
  CATBackspace = 0x00c00000, // VK_BACK
  //CATKeyCode_Tab       = 0x00d00000, // VK_TAB
  CATTab       = 0x00d00000, // VK_TAB
  //CATKeyCode_Enter     = 0x00e00000, // VK_RETURN
  CATEnter     = 0x00e00000, // VK_RETURN
  
  //CATKeyCode_Space     = 0x00f00000, // VK_SPACE
  CATSpace			   = 0x00f00000, // VK_SPACE

  CATKeyCode_ShiftKey     = 0x01000000,  // VK_SHIFT 
  CATKeyCode_ControlKey   = 0x02000000,  // VK_CONTROL // CTRL key
  CATKeyCode_AltKey       = 0x03000000,  // VK_MENU    // ALT key
  CATKeyCode_CapsLockKey  = 0x04000000,  // VK_CAPITAL // CAPS LOCK key
  CATKeyCode_Clear        = 0x05000000,  // VK_CLEAR      // CLEAR Key
  CATKeyCode_PauseKey     = 0x06000000,  // VK_PAUSE      // PAUSE key
  CATKeyCode_Kana         = 0x07000000,  // VK_KANA       // IME Kana mod
  CATKeyCode_Hanguel      = 0x08000000,  // VK_HANGUEL    // IME Hanguel mode (maintained for compatibility; use VK_HANGUL)
  CATKeyCode_Hangul       = 0x09000000,  // VK_HANGUL     // IME Hangul mode
  CATKeyCode_Junja        = 0x0a000000,  // VK_JUNJA      // IME Junja mode
  CATKeyCode_Final        = 0x0b000000,  // VK_FINAL      // IME final mode
  CATKeyCode_Hanja        = 0x0c000000,  // VK_HANJA      // IME Hanja mode
  CATKeyCode_Kanji        = 0x0e000000,  // VK_KANJI      // IME Kanji mode
  
  CATKeyCode_Convert      = 0x0f000000,  // VK_CONVERT    // IME convert
  // following  CATF24 = 0x00190000, // VK_F24
  CATKeyCode_NonConvert   = 0x01a00000,  // VK_NONCONVERT // IME nonconvert
  CATKeyCode_Accept       = 0x01b00000,  // VK_ACCEPT     // IME accept
  CATKeyCode_ModeChange   = 0x01c00000,  // VK_MODECHANGE // IME mode change request
  CATKeyCode_Select       = 0x01d00000,  // VK_SELECT     // SELECT key
  CATKeyCode_Print        = 0x01e00000,	 // VK_PRINT      // PRINT key
  CATKeyCode_Execute      = 0x01f00000,  // VK_EXECUTE    // EXECUTE key
  CATKeyCode_Snapshot     = 0x02100000,  // VK_SNAPSHOT   // PRINT SCREEN key
  
  CATKeyCode_Help         = 0x02200000,  // VK_HELP       // HELP key
  CATKeyCode_LWin         = 0x02300000,  // VK_LWIN       // Left Windows key (Natural keyboard) 
  CATKeyCode_RWin         = 0x02400000,  // VK_RWIN       // Right Windows key (Natural keyboard)
  CATKeyCode_Apps         = 0x02500000,  // VK_APPS       // AppliCATKeyCode_ions key (Natural keyboard)
  CATKeyCode_Sleep    = 0x02600000,  // VK_SLEEP      // Computer Sleep key

  CATKeyCode_Numpad0      = 0x02700000,  // VK_NUMPAD0    // Numeric keypad 0 key
  CATKeyCode_Numpad1      = 0x02800000,  // VK_NUMPAD1    // Numeric keypad 1 key
  CATKeyCode_Numpad2      = 0x02900000,  // VK_NUMPAD2    // Numeric keypad 2 key
  CATKeyCode_Numpad3      = 0x02a00000,  // VK_NUMPAD3    // Numeric keypad 3 key
  CATKeyCode_Numpad4      = 0x02b00000,  // VK_NUMPAD4    // Numeric keypad 4 key
  CATKeyCode_Numpad5      = 0x02c00000,  // VK_NUMPAD5    // Numeric keypad 5 key
  CATKeyCode_Numpad6      = 0x02d00000,  // VK_NUMPAD6    // Numeric keypad 6 key
  CATKeyCode_Numpad7      = 0x02e00000,  // VK_NUMPAD7    // Numeric keypad 7 key
  CATKeyCode_Numpad8      = 0x02f00000,  // VK_NUMPAD8    // Numeric keypad 8 key
  CATKeyCode_Numpad9      = 0x03100000,  // VK_NUMPAD9    // Numeric keypad 9 key
  CATKeyCode_Multiply     = 0x03200000,  // VK_MULTIPLY   // Multiply key
  CATKeyCode_Add          = 0x03300000,  // VK_ADD        // Add key
  CATKeyCode_Separator    = 0x03400000,  // VK_SEPARATOR  // Separator key
  CATKeyCode_Subtract     = 0x03500000,  // VK_SUBTRACT   // Subtract key
  CATKeyCode_Decimal      = 0x03600000,  // VK_DECIMAL    // Decimal key
  CATKeyCode_Divide       = 0x03700000,  // VK_DIVIDE     // Divide key
  CATKeyCode_Numlock      = 0x03800000,  // VK_NUMLOCK    // NUM LOCK key
  CATKeyCode_Scroll       = 0x03900000,  // VK_SCROLL     // SCROLL LOCK key

  CATKeyCode_LMenu        = 0x03a00000,  // VK_LMENU				// Left MENU key
  CATKeyCode_RMenu        = 0x03b00000,  // VK_RMENU				// Right MENU key
  CATKeyCode_BROWSER_BACK        = 0x03c00000,  // VK_BROWSER_BACK		// Browser Back key
  CATKeyCode_BROWSER_FORWARD     = 0x03d00000,  // VK_BROWSER_FORWARD	// Browser Forward key
  CATKeyCode_BROWSER_REFRESH     = 0x03e00000,  // VK_BROWSER_REFRESH	// Browser Refresh key
  CATKeyCode_BROWSER_STOP        = 0x03f00000,  // VK_BROWSER_STOP		// Browser Stop key
  CATKeyCode_BROWSER_SEARCH      = 0x04100000,  // VK_BROWSER_SEARCH	// Browser Search key 
  CATKeyCode_BROWSER_FAVORITES   = 0x04200000,  // VK_BROWSER_FAVORITES // Browser Favorites key
  CATKeyCode_BROWSER_HOME        = 0x04300000,  // VK_BROWSER_HOME		// Browser Start and Home key
  CATKeyCode_VOLUME_MUTE	     = 0x04400000,  // VK_VOLUME_MUTE		// Volume Mute key
  CATKeyCode_VOLUME_DOWN         = 0x04500000, // VK_VOLUME_DOWN		// Volume Down key
  CATKeyCode_VOLUME_UP           = 0x04600000, // VK_VOLUME_UP			// Volume Up key
  CATKeyCode_MEDIA_NEXT_TRACK    = 0x047600000, // VK_MEDIA_NEXT_TRACK	// Next Track key
  CATKeyCode_MEDIA_PREV_TRACK    = 0x04800000, // VK_MEDIA_PREV_TRACK  // Previous Track key
  CATKeyCode_MEDIA_STOP          = 0x04900000, // VK_MEDIA_STOP		// Stop Media key
  CATKeyCode_MEDIA_PLAY_PAUSE    = 0x04a00000, // VK_MEDIA_PLAY_PAUSE	// Play/Pause Media key
  CATKeyCode_LAUNCH_MAIL         = 0x04b00000, // VK_LAUNCH_MAIL		// Start Mail key
  CATKeyCode_LAUNCH_MEDIA_SELECT = 0x04c00000, // VK_LAUNCH_MEDIA_SELECT	// Select Media key
  CATKeyCode_LAUNCH_APP1         = 0x04d00000, // VK_LAUNCH_APP1			// Start Application 1 key
  CATKeyCode_LAUNCH_APP2         = 0x04e00000, // VK_LAUNCH_APP2			// Start Application 2 key
  CATKeyCode_OEM_1               = 0x04f00000, // VK_OEM_1				// Used for miscellaneous characters; it can vary by keyboard.
							// For the US standard keyboard, the ';:' key 
  CATKeyCode_OEM_PLUS            = 0x05100000, // VK_OEM_PLUS			// For any country/region, the '+' key
  CATKeyCode_OEM_COMMA           = 0x05200000, // VK_OEM_COMMA			// For any country/region, the ',' key
  CATKeyCode_OEM_MINUS           = 0x05300000, // VK_OEM_MINUS			// For any country/region, the '-' key
  CATKeyCode_OEM_PERIOD          = 0x05400000, // VK_OEM_PERIOD		// For any country/region, the '.' key
  CATKeyCode_OEM_2               = 0x05500000, // VK_OEM_2				// Used for miscellaneous characters; it can vary by keyboard.
							// For the US standard keyboard, the '/?' key 
  CATKeyCode_OEM_3               = 0x05600000, // VK_OEM_3				// Used for miscellaneous characters; it can vary by keyboard. 
  CATKeyCode_OEM_4               = 0x05700000, // VK_OEM_4				// Used for miscellaneous characters; it can vary by keyboard. 
							// For the US standard keyboard, the '[{' key
  CATKeyCode_OEM_5               = 0x05800000, // VK_OEM_5				// Used for miscellaneous characters; it can vary by keyboard. 
							// For the US standard keyboard, the '\|' key
  CATKeyCode_OEM_6               = 0x05900000, // VK_OEM_6				// Used for miscellaneous characters; it can vary by keyboard. 
							// For the US standard keyboard, the ']}' key
  CATKeyCode_OEM_7               = 0x05a00000, // VK_OEM_7				// Used for miscellaneous characters; it can vary by keyboard. 
							// For the US standard keyboard, the 'single-quote/double-quote' key
  CATKeyCode_OEM_8               = 0x05b00000, // VK_OEM_8				// Used for miscellaneous characters; it can vary by keyboard.
  CATKeyCode_OEM_102             = 0x05c00000, // VK_OEM_102			// Either the angle bracket key or the backslash key on the RT 102-key keyboard
  CATKeyCode_PROCESSKEY         = 0x05d00000, // VK_PROCESSKEY		// IME PROCESS key
  CATKeyCode_PACKET	         = 0x05e00000, // VK_PACKET			// Used to pass Unicode characters as if they were keystrokes. 
							// The VK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods.
							// For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN, and WM_KEYUP
  CATKeyCode_ATTN   	         = 0x05f00000, // VK_ATTN				// Attn key
  CATKeyCode_CRSEL   	         = 0x06100000, // VK_CRSEL				// CrSel key
  CATKeyCode_EXSEL  	         = 0x06200000, // VK_EXSEL				// ExSel key
  CATKeyCode_EREOF   	         = 0x06300000, // VK_EREOF				//Erase EOF key
  CATKeyCode_PLAY   	         = 0x06400000, // VK_PLAY				// Play key
  CATKeyCode_ZOOM  	         = 0x06500000, // VK_ZOOM				// Zoom key
  // CAT_ATTN   	         = 0x05e00000, // VK_NONAME			// Reserved 
  CATKeyCode_PA1   	         = 0x06700000, // VK_PA1				// PA1 key
  CATKeyCode_OEM_CLEAR   	     = 0x06800000, // VK_OEM_CLEAR			// Clear Key
  CATKeyCode_Equals              = 0x06900000,

   CATKeyCode_0                 = 0x30, // 0 key
   CATKeyCode_1                 = 0x31, // 1 key
   CATKeyCode_2                 = 0x32, // 2 key
   CATKeyCode_3                 = 0x33, // 3 key
   CATKeyCode_4                 = 0x34, // 4 key
   CATKeyCode_5                 = 0x35, // 5 key
   CATKeyCode_6                 = 0x36, // 6 key
   CATKeyCode_7                 = 0x37, // 7 key
   CATKeyCode_8                 = 0x38, // 8 key
   CATKeyCode_9                 = 0x39, // 9 key
   CATKeyCode_A                 = 0x41, // A key
   CATKeyCode_B                 = 0x42, // B key
   CATKeyCode_C                 = 0x43, // C key
   CATKeyCode_D                 = 0x44, // D key
   CATKeyCode_E                 = 0x45, // E key
   CATKeyCode_F                 = 0x46, // F key
   CATKeyCode_G                 = 0x47, // G key
   CATKeyCode_H                 = 0x48, // H key
   CATKeyCode_I                 = 0x49, // I key
   CATKeyCode_J                 = 0x4A, // J key
   CATKeyCode_K                 = 0x4B, // K key
   CATKeyCode_L                 = 0x4C, // L key
   CATKeyCode_M                 = 0x4D, // M key
   CATKeyCode_N                 = 0x4E, // N key
   CATKeyCode_O                 = 0x4F, // O key
   CATKeyCode_P                 = 0x50, // P key
   CATKeyCode_Q                 = 0x51, // Q key
   CATKeyCode_R                 = 0x52, // R key
   CATKeyCode_S                 = 0x53, // S key
   CATKeyCode_T                 = 0x54, // T key
   CATKeyCode_U                 = 0x55, // U key
   CATKeyCode_V                 = 0x56, // V key
   CATKeyCode_W                 = 0x57, // W key
   CATKeyCode_X                 = 0x58, // X key
   CATKeyCode_Y                 = 0x59, // Y key
   CATKeyCode_Z                 = 0x5A, // Z key
  
  //******************************************** VK_BACK       // BACKSPACE key
  //******************************************** VK_TAB        // Tab key
  //******************************************** VK_RETURN     // ENTER Key
  //****************************************** VK_ESCAPE     // ESC key
  

  //**************************************** VK_SPACE      // SPACEBAR
  //**************************************** VK_PRIOR      // PAGE UP key
  //**************************************** VK_NEXT       // PAGE DOWN key
  //**************************************** VK_END        // END key
  //**************************************** VK_HOME       // HOME key
  //**************************************** VK_LEFT       // LEFT ARROW key
  //**************************************** VK_UP         // UP ARROW key
  //**************************************** VK_RIGHT      // RIGHT ARROW key
  //**************************************** VK_DOWN       // DOWN ARROW key
  
  //***************************************** VK_INSERT     // INS key
  //***************************************** VK_DELETE     // DEL key
  //  VK_A 
  

    //CATKeyCode_Other     = 0x80000000
	CATOther     = 0x80000000

} ;

enum CATKeybdType// CATPress ou CATRelease
{
  CATUnspecified = 0,
  CATPress,
  CATRelease,
  CATRepeatPress
};

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))

#include <X11/Xlib.h>
#include <Xm/Xm.h>

#define ModifierPossibleTranslation 12
static unsigned int _ModifiersTranslationTable[ModifierPossibleTranslation][2] =
{
  { ControlMask , CATControl    },
  { ShiftMask   , CATShift      },
  { LockMask    , CATCapsLock   },
  { Mod1Mask    , CATAlt        },
  { Mod2Mask    , CATControl    },
  { Mod3Mask    , CATNumLock    },
  { Mod4Mask    , CATMeta       },
  { Button1Mask , CATButton1    },
  { Button2Mask , CATButton2    },
  { Button3Mask , CATButton3    },
  { Button4Mask , CATButton4    },
  { Button5Mask , CATButton5    }
};

#endif

#endif
