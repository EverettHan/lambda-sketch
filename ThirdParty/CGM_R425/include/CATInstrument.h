#ifndef CATInstrument_H  
#define  CATInstrument_H  
//

// COPYRIGHT DASSAULT SYSTEMES 2000

// Uncomment the following line 
//#define _CAT_DEBUG
#ifdef CNEXT_DEBUG
#define _CAT_DEBUG
#endif
class CATInstrument
{
public:
  enum KindClass
    {
      KC_FreeMemory,
	 KC_Reserved, // Pour usage interne des outils
      KC_CATBaseUnknown = 0x10,
	 KC_CATBaseUnknown_var,
      KC_CATUnicodeString,
      KC_CATInterUnicodeString,
      KC_CATString,
      KC_CallbackStruct,
      KC_CATHashTable, // c'est possible aujourd'hui.
      KC_CATCollecRoot,
      KC_UnknownObject =0xff
    };
    enum DumpMode 
    {
      Delta = 0x1, 
      All = 0x2, 
      Short = 0x4, 
      Stats = 0x10
    };

   virtual void  AddPointer(void *RObj,CATInstrument::KindClass EnumType, const char *iFacClassName=0)=0;
   virtual void RemovePointer(void *RObj,CATInstrument::KindClass EnumType,const char *iFacClassName=0)=0;
   virtual void Start(const char *iFacDebugString=0)=0;
   virtual void Stop(const char *iFacDebugString)=0;
   virtual void Dump(DumpMode flags,const char *iFacDebugString=0) = 0;
};

//----------------------------------------------------------------
#ifndef _CAT_DEBUG
//====================================
// instrumentation du constructeur
//====================================
#define CATINSTRUM_CONST( TypeDeClass)

//====================================
// instrumentation du destructeur
//====================================
#define CATINSTRUM_DEST( TypeDeClass)


// end of normal version
//----------------------------------------------------------------
#else
#include <stdlib.h>

#include "CATDebugMemory.h"

//=============================================
// instrumentation du constructeur (type connu)
//============================================
#define CATINSTRUM_CONST( TypeDeClass) \
  CATDebugMemory::AddPointer(this, CATInstrument::KC_##TypeDeClass,NULL); 

//==============================================
// instrumentation du destructeur (type connu)
//============================================== 
#define CATINSTRUM_DEST( TypeDeClass) \
  CATDebugMemory::RemovePointer(this, CATInstrument::KC_##TypeDeClass,NULL); 

//====================================
// instrumentation du constructeur type nouveau
//====================================
#define CATINSTRUM_CONST_UNK( TypeDeClass) \
  CATDebugMemory::AddPointer(this, CATInstrument::KC_UnknownObject,#TypeDeClass); 
//====================================
// instrumentation du destructeur type nouveau
//====================================
#define CATINSTRUM_DEST_UNK( TypeDeClass) \
CATDebugMemory::RemovePointer(this, CATInstrument::KC_UnknownObject,#TypeDeClass);

// end of debug version
//----------------------------------------------------------------

#endif
#endif
