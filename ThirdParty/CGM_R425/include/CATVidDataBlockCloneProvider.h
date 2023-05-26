#ifndef CATVidDataBlockCloneProvider_H
#define CATVidDataBlockCloneProvider_H

#include "VisuDialog.h"
#include "CATVidAbstractCloneProvider.h"

/**
 * This class is able to clone data-blocks.
 *
 * @see CATVidAbstractCloneProvider
 */
class ExportedByVisuDialog CATVidDataBlockCloneProvider : public CATVidAbstractCloneProvider
{
  CATDeclareClass;

public:
  /**
   * Constructor.
   */
  CATVidDataBlockCloneProvider();
  /**
   * Creates a clone from the input data-block.
   *
   * @param i_spObject data to clone. Must be a @ref CATSYPDataBlock from
   * the factory given in the constructor of the class.
   *
   * @return a new data-block instance, as created from the factory given in 
   * the constructor of the class and having the same values than the input 
   * data-block.
   */
  virtual CATBaseUnknown_var Clone(const CATBaseUnknown_var & i_spObject);

protected:
  /** Destructor. */
  virtual ~CATVidDataBlockCloneProvider();

private:
  /** Copy-constructor. */
  CATVidDataBlockCloneProvider (CATVidDataBlockCloneProvider &);
  /** Assignment operator. */
  CATVidDataBlockCloneProvider& operator=(CATVidDataBlockCloneProvider&);
};

//-----------------------------------------------------------------------------
#endif
