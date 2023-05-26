#ifndef CATMarsh3DBox_H
#define CATMarsh3DBox_H
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002-2005
/**
* @level Private
* @usage U1
*/

#include "CATListOfInt.h"
#include "MathMarsh.h"

#include "CATBoolean.h"

/**
* <br><b>Role</b>: Box (or Voxel) for MarshMallow
* <p>
*  Class to describe boxes and identify them in 3D space
*  Used in order to optimize Evaluation in Marshmallow.
*
*
* @level private
* @usage U1
*/
class CATMarsh3DBox
{
public:
	
	CATMarsh3DBox(const int iID, const int iSubdivideOrder, const CATBoolean iBoxAutoCheck = TRUE);
	~CATMarsh3DBox();

  inline CATBoolean IsUnValid() const {return _XI == -501;}

	int AppendIndexPoint(const int iIndex);
	int AppendIndexPointWithCheck(const int iIndex);
	int ReplaceIndexPoint(const int iFromIndex, const int iToIndex);
	inline void GetCoord(int oCoord[]) const {oCoord[0]=_XI; oCoord[1]=_YI; oCoord[2]=_ZI;}
	int   GetID() const {return _ID;}
	inline const CATListOfInt& GetListofIndexes() const {return _TheIndexes;}

	static int GetIdFromPoint(const double ix, const double iy, const double iz, 
															 const int iSubdivideOrder);

	ExportedByMathMarsh static int GetAdjacentId(const double ix, const double iy, const double iz, 
															                  const int iSubdivideOrder, int oAdjacentId[27], int& oNumberOfAdjacentID);

	/** 
	* <br><b>Role</b>: From a ID box gives the ID list of the adjacent Boxes (with itself)
	*
	* @param ID [inout]
	*   The parameter role...
	* @param iSubdivideOrder [in]
	*   The number of sudvision (the same inX/Y/Z)
	* @param oAdjacentId[27] [out]
	*   The result IDs
	* @param oNumberOfAdjacentID [out]
	*   The number of adjacent ID
	*
	* @return
	*		0 : if all is OK
	*   >0: if an error occurs
	*/
	static int GetAdjacentId(const int ID, const int iSubdivideOrder, 
		                       int oAdjacentId[27], int& oNumberOfAdjacentID);

	/** 
	
	* <br><b>Role</b>: From a Box ID get the X,Y,Z (interger) coordinates
	*
	* @param iID [in]
	*   The ID 
	* @param iSubdivideOrder [in]
	*   The number of sudvision (the same inX/Y/Z)
	* @param oIX [out]
	*   The rank in X
	* @param oIY [out]
	*   The rank in Y
	* @param oIZ [out]
	*   The rank in Z
	*
	* @return
	*   0 : if all is OK
	*   >0: if an error occurs
	*/
	static int GetIndexesFromId( const int iID, 
															 const int iSubdivideOrder, int& oIX, int& oIY, int& oIZ);

private :
	CATListOfInt _TheIndexes;
	int _XI, _YI, _ZI, _ID;
};

#endif


