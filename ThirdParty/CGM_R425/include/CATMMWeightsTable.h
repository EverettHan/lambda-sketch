//----------------------------------------------------------------------------
//	CATMMWeightsTable.h
//----------------------------------------------------------------------------
//	Creation by O1X
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2012
//----------------------------------------------------------------------------
#ifndef CATMMWeightsTable_H
#define CATMMWeightsTable_H

#include "CATDataType.h"
#include "CATMMediaRasterProcessor_Base.h"

class CATMMGenericFilter;
//
//Filter weights table.<br>
//This class stores contribution information for an entire line (row or column).

class ExportedByCATMMediaRasterProcessor_Base CATMMWeightsTable
{
/** 
  Sampled filter weight table.<br>
  Contribution information for a single pixel
*/
typedef struct {
	/// Normalized weights of neighboring pixels
	double *Weights;
	/// Bounds of source pixels window
	int Left, Right;   
} Contribution;  

private:
	/// Row (or column) of contribution weights 
	Contribution *m_WeightTable;
	/// Filter window size (of affecting source pixels) 
	CATLONG32 m_WindowSize;
	/// Length of line (no. of rows / cols) 
	CATLONG32 m_LineLength;

public:
	/** 
	Constructor<br>
	Allocate and compute the weights table
	@param pFilter Filter used for upsampling or downsampling
	@param uLineSize Length (in pixels) of the destination line buffer
	@param uSrcSize Length (in pixels) of the source line buffer
	*/
	CATMMWeightsTable(CATMMGenericFilter *pFilter,  CATLONG32 uDstSize,  CATLONG32 uSrcSize);

	/**
	Destructor<br>
	Destroy the weights table
	*/
	~CATMMWeightsTable();

	/** Retrieve a filter weight, given source and destination positions
	@param dst_pos Pixel position in destination line buffer
	@param src_pos Pixel position in source line buffer
	@return Returns the filter weight
	*/
	double getWeight(int dst_pos, int src_pos) {
		return m_WeightTable[dst_pos].Weights[src_pos];
	}

	/** Retrieve left boundary of source line buffer
	@param dst_pos Pixel position in destination line buffer
	@return Returns the left boundary of source line buffer
	*/
	int getLeftBoundary(int dst_pos) {
		return m_WeightTable[dst_pos].Left;
	}

	/** Retrieve right boundary of source line buffer
	@param dst_pos Pixel position in destination line buffer
	@return Returns the right boundary of source line buffer
	*/
	int getRightBoundary(int dst_pos) {
		return m_WeightTable[dst_pos].Right;
	}
};


#endif
