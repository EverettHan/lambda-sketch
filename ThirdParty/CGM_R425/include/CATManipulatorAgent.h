#ifndef CATManipulatorAgent_h
#define CATManipulatorAgent_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATCommand.h"

typedef CATULONG64 CATDlgEngBehavior;

#include "CATLISTP_CATBaseUnknown.h"

class CATBaseUnknown;
class CATPathElement;
class CATFrmEditor;

class ExportedByCATAfrSelection CATManipulatorAgent : public CATCommand
{

  CATDeclareClass;

public:
  CATManipulatorAgent(CATBaseUnknown * Element);
  virtual ~CATManipulatorAgent();

  CATBaseUnknown * GetElement();
  void UpdateManipulators();
  void AddManipulator(CATBaseUnknown * Manipulator, int DeclareToISO=1);
  void DeleteManipulator(CATBaseUnknown * Manipulator);
  CATLISTP(CATBaseUnknown) * GetManipulatorList();
    
  CATLISTP(CATBaseUnknown) * GetAgentList();
  void SetAgentList(CATLISTP(CATBaseUnknown) * AgentList);

  // Temporary - for migration compatibility : do not use
  virtual void SetBehavior (CATDlgEngBehavior Behavior );
  virtual void SetUndoTitle(const CATUnicodeString& text);

  // Don't forget to call the mother class method if you override this method
  virtual void Clean();

  // Ovveride this method to perform specific action before this class is submitted to 
  // CATCommandDeletion.
  // Default implementation of this method has no effect.
  virtual void BeforeDeletion();
    
private:

  CATLISTP(CATBaseUnknown) * _ManipulatorList;
  CATLISTP(CATBaseUnknown) * _AgentList;
  CATBaseUnknown * _Element;
  CATFrmEditor * _editor;
};

#endif
