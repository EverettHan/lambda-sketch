#ifndef CATVidMdlDnDData_H
#define CATVidMdlDnDData_H

#include "VisuDialog.h"
#include "CATVidDnDData.h"
#include "CATSYPArray.h"
#include "CATVidMdlIndex.h"

/**
 * Data container for drag-and-drop inside model/view. Add the information
 * of which items have been dragged.
 */
class ExportedByVisuDialog CATVidMdlDnDData: public CATVidDnDData
{
  CATDeclareClass;

public:
  /** 
   * Constructor. Will take a copy of the input list.
   *
   * @param i_indexes the indexes of items dragged.
   */
  CATVidMdlDnDData(const CATSYPDynArray<CATVidMdlIndex> & i_indexes);
  /** Destructor. */
  virtual ~CATVidMdlDnDData();
  /** @return the number of items dragged. */
  int GetDraggedIndexesNb();
  /** 
   * @param i_i stands for the <tt>i_i</tt>-thitem index. Must be in 
   * <tt>[0, GetDraggedIndexesNb() - 1]</tt>.
   *
   * @return the index of the i-th item dragged. 
   */
  const CATVidMdlIndex & GetDraggedIndex(int i_i) const;
  /** @return indexes of the items dragged in the model. */
  const CATSYPDynArray<CATVidMdlIndex> & GetDraggedIndexes();

private:
  /** Copy constructor. */
  CATVidMdlDnDData (CATVidMdlDnDData &);
  /** Assignment operator. */
  CATVidMdlDnDData& operator=(CATVidMdlDnDData&);

private:
  CATSYPDynArray<CATVidMdlIndex> _DraggedIndexes;
};

//-----------------------------------------------------------------------------

#endif
