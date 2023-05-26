#ifndef __CATOmxAbstractStackCursor_h__
#define __CATOmxAbstractStackCursor_h__
#include "CATOmxSharable.h"
#include "CATOmxPortability.h"
#include "CATOmxKeyString.h"
/** A stack abstraction.
 */
class CATOmxAbstractStackCursor : public CATOmxSharable {
public:
  enum MoveOperation { Down, Up, Top, Bottom, Caller = Down, Callee = Up, Main = Bottom };
  /** Cursor ID. */
  virtual CATOmxKeyString CursorType() const = 0;
  /** Return the stack size. */
  virtual unsigned int GetStackSize() const = 0;
  /** Move cursor to the top of stack.*/
  virtual HRESULT MoveCursor(MoveOperation iOp = Caller) = 0;
  /** StackElement description.*/
  struct StackItem {
    unsigned int depth; // depth in stack (0 is topmost callee)
    unsigned int line;  // source code line 
    void* address; // program counter adress
    CATOmxKeyString symbol; // nearest symbol
    CATOmxKeyString module; // module  
    CATOmxKeyString source; // source file (if known)
    CATULONG64 start;  // symbol start at
    CATULONG64 offset; // offset
    CATULONG64 len;    // symbol size
    StackItem() : depth(0), line(0), start(0), offset(0), len(0), address(0) {}
  };

  /** Current position in stack.*/
  virtual unsigned int Depth() const = 0;
  /** Return current stack data.*/
  virtual unsigned int GetInfo(StackItem&) const = 0;
  /** Return module information. */
  virtual HRESULT GetModuleInfo(CATOmxKeyString& iName, void*& oBaseAddress, unsigned int oSize) const = 0;

};

#endif
