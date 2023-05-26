#ifndef __ForOleDbg
#define __ForOleDbg


// COPYRIGHT DASSAULT SYSTEMES 2000

/* for debugging purpose */

#include "JS0CORBA.h"

class CATBaseUnknown;

ExportedByJS0CORBA int AddPointerForDebug(CATBaseUnknown *pt, int levmin = 0, int levmax = 50);
ExportedByJS0CORBA int RemovePointerForDebug(CATBaseUnknown *pt);

struct ChainExtension;
class CATMetaClass;
class CATTrace;
struct IUnknown;
ExportedByJS0CORBA ChainExtension * ScanChainExtension(ChainExtension*ptchaine, short SelectedField, CATMetaClass **ptptmeta, IUnknown**ptptext,short*ptfield);
ExportedByJS0CORBA void DumpChainExtension(CATBaseUnknown*ptobj,CATTrace& Tracer);
ExportedByJS0CORBA void ScanChainExtension(ChainExtension* chaine,CATTrace& Tracer);
ExportedByJS0CORBA ChainExtension* GetChainExtension(CATBaseUnknown*);

#endif
