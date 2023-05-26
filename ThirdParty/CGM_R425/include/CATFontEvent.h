// COPYRIGHT DASSAULT SYSTEMES 2009
#ifndef CATFontEvent_H
#define CATFontEvent_H

#include "SGInfra.h"
#include "CATTimeStampedEvent.h"
#include "CATUnicodeString.h"

class CATFont;

/**
* Class notification for CATFont events.
*/
//===============================================================================
class ExportedBySGInfra CATFontEvent : public CATTimeStampedEvent
{
   CATDeclareClass;

public :

   /** @nodoc */
   CATFontEvent(CATUnicodeString iFontName, CATFont * iFont = NULL); 
   /** @nodoc */
   virtual ~CATFontEvent();

   /** @nodoc */
   CATUnicodeString & GetFontName();
   /** @nodoc */
   CATFont * GetFont();   

private :

   CATUnicodeString _fontName;
   CATFont *        _font;
};

//===============================================================================
#endif
