#ifndef __CATOmxStackDumper_h__
#define __CATOmxStackDumper_h__
#include "CATOmxKernel.h"
#include "CATOmxSR.h"
#include <stdio.h> //for FILE
class CATOmxAbstractStackCursor;
class CATOmxTextStream;
class CATOmxAny;
class ExportedByCATOmxKernel CATOmxStackDumper {
  CATOmxSR<CATOmxAbstractStackCursor> cursor;
public:
  CATOmxStackDumper(CATOmxAbstractStackCursor *iCursor) : cursor(iCursor) {}
  CATOmxStackDumper(CATOmxStackDumper &iDump) : cursor(iDump.cursor) {}
  /** Empty stack.*/
  CATOmxStackDumper() {}
  /** Get a stack using the specified sampler.*/
  CATOmxStackDumper &GetStack(const char *sampler=0);
  /** Get the underlying cursor.*/ 
  CATOmxAbstractStackCursor *GetCursor() const ;
  /** Dump the stack into out, using the specified format. */
  void Dump(CATOmxTextStream &out,const char *format=" [{{depth}}] {{address}} {{symbol}}\n")  ;
  /** Export the stack into a variant [ [ address symbol library] * ]. */
  void ToVariant(CATOmxAny &out) ;
  /** @nodoc Legacy code use GetStack().Dump(osm," {{symbol}}\n") instead. */
  void PrintCallStack(FILE * out);
};
#endif
