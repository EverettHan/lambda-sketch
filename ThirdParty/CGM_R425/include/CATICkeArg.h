#ifndef CATICkeArg_h
#define CATICkeArg_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */


/*  CAA2Reviewed by FRH */

// module declaration
#include "CATLifSpecs.h"

// inherited from
#include "CATBaseUnknown.h"

// forwards
#include "CATICkeRelationForwards.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeArg;
#else
extern "C" const IID IID_CATICkeArg;
#endif


/**   
 * Interface to manage signatures formal arguments.
 * <b>Role</b>: An argument belongs to a signature.<br>
 * It describes the type of parameters that will be given to the Knowledge function at runtime.<br>
 * It is used to check syntax validity.<br>
 * <br>Example: in signature "sin (x:In Real)" the only argument is "x: In Real".<br> 
 * this interface is mono implemented.<br>
 * Arguments are created by @href CATICkeFunctionFactory#CreateArg.<br>
 * Knowledge expressions and Knowledge functions have a signature that has arguments.<br>
 * @see CATICkeSignature, CATICkeFunctionFactory, CATICkeFunction
 */
class ExportedByCATLifSpecs CATICkeArg: public CATBaseUnknown
{

public :

/** Enum describing the argument mode. 
 *  It explains if parameter will be read or written
 */
enum Mode
{
 Undefined	= 0,  // undefined (do not use)
 In	     	= 1,  // parameter in input 
 Out		= 2,  // parameter in output
 InOut		= 3   // parameter in input AND output (do not use)
};
  


/**
 * Returns the name of the argument.<br>
 * Example: "x"
 */
virtual CATUnicodeString   Name    () const =0;

/**
 * Renames the argument.
 * @param  iNewName new name to be given to the argument <br>
 * Note that this method is supposed to be used only at the definition stage of an argument. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void               Rename    (const CATUnicodeString  &iNewName) =0;

/**
 * Returns the string to be shown to the user to describe the argument.<br> 
 * Use it whenever you want to show an argument to the user (instead of name).<br>
 * Example: " x : In Real".<br>
 */
virtual CATUnicodeString   Show    () const =0; 



/**
 * Returns the Knowledge type of the argument.<br>
 * Example: Real
 */
virtual CATICkeType_var Type    () const =0;


/**
 * Returns the mode of the argument.
 * <br><b>Legal values</b>: the mode can be either
 * <tt>In</tt> when parameter will be used as an input.
 * <tt>Out</tt> when parameter will be used as an output.
 */
virtual CATICkeArg::Mode GetMode    () const = 0;

/**
 * Sets the mode of the argument.
 * @param  iMode mode of the argument.<br>
 * <li> In : for a parameter in input</li>
 * <li> Out : for a parameter in output</li>
 * <li> InOut : for a parameter in output and input</li>  
 * Note that this method is supposed to be used only at the definition stage of an argument. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void    SetMode (const CATICkeArg::Mode iMode) = 0;


private:

  // 2 define ClassName
  CATDeclareInterface;


}; 

CATDeclareHandler(CATICkeArg,CATBaseUnknown);

#endif


