#ifndef CATIWorkbenchInitialization_h
#define CATIWorkbenchInitialization_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */


#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIWorkbenchInitialization;
#else
extern "C" const IID IID_CATIWorkbenchInitialization;
#endif
/**
 * Interface to do some initializations before starting a workbench. 
 * <b>Role</b>:
 *   This interface is called whenever the given workbench becomes the current one.
 *   <br>
 *   You implement it using an extension of a late type made of the workbench identifier
 *   suffixed by <b>_init</b>, such as <tt>MyWorkbench_init</tt> for 
 *   the MyWorkbench workbench.
 *   <br><br>This interface contains a method @href #Init called when the workbench 
 *    becomes the current one, and a method @href #Dispose called when this workbench 
 *    is exited.
 *   <br>Suppose you launch the workbench A and after the B. The sequence of calls is:
 *   <ul>
 *   <li>Launch A</li>
 *   <li>workbenchA <tt>Init</tt> is called </li>
 *   <br>You are in the workbench A
 *   <li>Launch B</li>
 *   <li>workbenchA <tt>Dispose</tt> is called </li>
 *   <li>workbenchB <tt>Init</tt> is called </li>
 *   <br>You are in the workbench B
 *   </ul>
 *   <b>Caution</b>  
 *   <br><b>Any command of a workbench is accessible from any other workbench of
 *   the same workshop.</b>
 *   <br>You have two means to launch a command which is initially defined in an
 *    another workbench:
 *    <ul>
 *    <li>Thanks to the Power Input</li>
 *    <li>Thanks to the Tools/Customize command, you can drag/drop a command in 
 *     any toolbar or menu</li>
 *    </ul>
 *    So a command must not expect that the method <tt>Init</tt> of its 
 *    original workbench has been executed when the command is launched.
 *    <br>This interface must thus be used to do visualization effets, such as create 
 *    a viewer, change the visualization mode, but never create data in the model.
*/
class ExportedByCATAfrItf CATIWorkbenchInitialization : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
	/** 
	 * Method called when the workbench becomes the current one.
	 */
  virtual void Init () = 0;
	/** 
	 * Method called when the workbench is exited.
	 */
  virtual void Dispose () = 0;

};
/** @nodoc */
CATDeclareHandler(CATIWorkbenchInitialization, CATBaseUnknown);

#endif
