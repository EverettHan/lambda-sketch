#ifndef _CATGMPOLYTRACES_H
#define _CATGMPOLYTRACES_H

#include "GMPolyTopTools.h"

#include "stdio.h"
#include "stdarg.h"

#include "CATUnicodeString.h"

// DUMP CGMObject : <varnam> <typ>(T<tag>)
#define GMPOLYDUMPCGM(varnam) \
  GMPOLYTRA("%s : %s(T%d)\n",#varnam,varnam?varnam->IsA():"Unknown",varnam?varnam->GetPersistentTag():0)

// WMNXLATOR4EVER

int GMPolyVsnprintf(char *s,unsigned int n,const char *format,va_list ap);

/** @nodoc */ #define GMPOLY_MAXFORMATBUFFERSIZE 10000

#define FormatToCusMAC(str) \
  CATUnicodeString str; \
  if (iFormat) \
  { \
    va_list ap; \
    va_start(ap,iFormat); \
    str = FormatToCusVA(iFormat,ap); \
    va_end(ap); \
  }

ExportedByGMPolyTopTools CATUnicodeString GMPOLYTRAINDENT();

ExportedByGMPolyTopTools void GMPOLYTRA(const char* iFormat=NULL,...); // FSV4/XLATOR4EVER
ExportedByGMPolyTopTools void GMPOLYTRA(int iLevel, const char* iFormat=NULL,...); // FSV4/XLATOR4EVER

ExportedByGMPolyTopTools void GMPOLYSTA(const char* iFormat=NULL,...); // FSV4/XLATOR4EVER
ExportedByGMPolyTopTools void GMPOLYSTA(int iLevel, const char* iFormat=NULL,...); // FSV4/XLATOR4EVER

ExportedByGMPolyTopTools void GMPOLYEND(const char* iFormat=NULL,...); // FSV4/XLATOR4EVER
ExportedByGMPolyTopTools void GMPOLYEND(int iLevel, const char* iFormat=NULL,...); // FSV4/XLATOR4EVER

ExportedByGMPolyTopTools void GMPOLYTRANI(const char* iFormat,...); // Ben oui, histoire de factoriser le test de trace active et le cgmout
ExportedByGMPolyTopTools void GMPOLYTRANI(int iLevel, const char* iFormat,...);

//WMN20190522 enfin, je comprends pourquoi les aller/retours entre ... et va_list ne marchent pas :
//WMN20190522 http://c-faq.com/varargs/handoff.html
// Using "..." allows for no parameters inside iFormat
// but requires building an explicit va_list to pass it to another function
// WARNING : ... and va_list are not equivalent !!!
//           ... can be turned into va_list, but a va_list can not become ...
//           once we have a va_list, all subsequent calls must be done with functions taking va_lists.

class CATUnicodeString;
ExportedByGMPolyTopTools CATUnicodeString FormatToCus(const char* iFormat,...);
ExportedByGMPolyTopTools CATUnicodeString FormatToCusVA(const char* iFormat,va_list ap);

class ExportedByGMPolyTopTools CATGMPolyTraces
{
public:
  CATGMPolyTraces();
  ~CATGMPolyTraces();

public:
  static void CATGMPolyTraces_Init();

private:
  static int CATGMPolyTraces_DeleteAtExit();

private:
  static CATGMPolyTraces* _GMPolyTraces;

};

#endif
