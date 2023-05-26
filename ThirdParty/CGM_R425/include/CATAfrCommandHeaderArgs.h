// COPYRIGHT Dassault Systemes 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATAfrCommandHeaderArgs_H
#define CATAfrCommandHeaderArgs_H

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATListOfCATAfrCommandHeaderArg.h"
#include "CATAfrCommandHeaderArg.h"

/**
* Class representing an argument list.
*
* <br><b>Role</b>: Argument list for a command header to pass to its command.
* <br>The command may use @href CATAfrCommandHeaderServices#CATAfrGetArguments in its constructor to get the argument list.
*/

class CATAfrCommandHeaderArgsIterator;

class ExportedByCATAfrFoundation CATAfrCommandHeaderArgs: public CATBaseUnknown
{
  CATDeclareClass;

  friend class CATAfrCommandHeaderArgsIterator;


  public:

    /**
     * Constructs an empty argument list.
     */
    CATAfrCommandHeaderArgs ();

    virtual ~CATAfrCommandHeaderArgs ();

    /**
     * Constructs an argument list by copying another one.
     */
    CATAfrCommandHeaderArgs (const CATAfrCommandHeaderArgs &);

    /**
     * Sets an argument list to the contents of another one.
     */
    CATAfrCommandHeaderArgs& operator=(const CATAfrCommandHeaderArgs&);

    /**
     * Returns an iterator.
     * <br>Remember to Release the iterator after use.
     * @return 
     *  The iterator.
     */
    CATAfrCommandHeaderArgsIterator * CreateIterator();

    /**
     * Remove an argument from its Id.
     * <br>It will return an error if no argument has this Id.
     * <br>Special notice on removal: if several iterators concurrently scan the same argument list,
     * removing an argument in one iterator might impact the scan in the others.
     * Next, Remove and Set methods of these iterators will have to check the current element still exists
     * before doing their job and return an error if it does not exist. As soon as an iterator removes an argument,
     * all the other existing iterators that reference this argument as the current element become unusable
     * until you call its First method again.
     * @param 
     *  The identifier of the argument to remove.
     */
    HRESULT Remove (const CATString iId);

    /**
     * Remove all arguments to empty the list.
     */
    void RemoveAll ();

    /**
     * Changes the value of an argument from its Id or creates the argument if it does not exist.
     * An argument can be created only at the end of the existing list.
     * Set will return an error if the new value type is not compatible with the old value type, i.e.
     * if types are not the same
     * or if modes are not the same.
     */
    HRESULT Set (const CATString iId, const CATBaseUnknown_var iValue, const CATAfrCommandHeaderArg::ArgumentMode iMode = CATAfrCommandHeaderArg::In);

    /**
     * Get the number of stored arguments.
     * @return
     *  The number of stored arguments inside the CATAfrCommandHeaderArgs.
     */
    int GetArgsCount() const;

    /**
     * Returns the list of arguments as a CATBaseUnknown_var.
     * This member function is dedicated to internal use.
     * @return
     *  The list of arguments converts to a CATBaseUnknown_var.
     */
    CATBaseUnknown_var GetItems();


  private:

    CATListOfCATAfrCommandHeaderArg _ArgList;
};

#endif
