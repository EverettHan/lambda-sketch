//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2013/07/01
//===================================================================
#ifndef CATVisRectPacker_H
#define CATVisRectPacker_H

#include "SGInfra.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "vector.h"
//-----------------------------------------------------------------------

class ExportedBySGInfra CATVisRectPacker
{
		struct Rect { 
			int _x; int _y; int _w; int _h;
			Rect(int x =0, int y =0, int w =0, int h =0) : _x(x), _y(y), _w(w), _h(h) {}
			CATBoolean empty() { return _w == 0 || _h == 0; }
		};
	public:
		CATVisRectPacker();
		~CATVisRectPacker();
		void Reserve(unsigned int n);
		void Reset(int width, int height);
		CATBoolean Pack(int iW, int iH, int* oPos);
		int Width() const;
		int Height() const;
	private:
		vector<Rect> _avail;
		int _width;
		int _height;
	};
//-----------------------------------------------------------------------

#endif // CATVisRectPacker_H
