//===================================================================
// COPYRIGHT Dassault Systèmes 2014-06-05
//===================================================================
//
// Type definitions for anything related to 2D rendering.
//
//===================================================================
// 2014-06-05 Creation: D6K
//===================================================================

#ifndef CATMM2DTypes_H
#define CATMM2DTypes_H

namespace CATMM2D {

/**
 * Available vector image file formats.
 */
enum VectorType {
	SVG = 0,
	PS,
	HPGL2,
	CGM,
	DSVG,
	UNKNOWN_TYPE
};
/**
 * Dimensions for any rectangle surface.
 */
template<class T>
struct Size {
	Size()
		: width(0), height(0) {}
	Size(const T i_width, const T i_height)
		: width(i_width), height(i_height) {}
	Size(const Size<T>& i_size)
		: width(i_size.width), height(i_size.height) {}
	Size& operator=(const Size<T>& i_size)
	{ width = i_size.width; height = i_size.height; return *this; }
	bool operator==(const Size<T>& i_size)
	{ return width == i_size.width && height == i_size.height; }
	bool operator!=(const Size<T>& i_size)
	{ return !operator==(i_size); }

	T width, height;
};
/**
 * Margins for any document.
 */
template<class T>
struct Margins {
	Margins()
		: top(0), bottom(0), left(0), right(0) {}
	Margins(const T i_top, const T i_bottom, const T i_left, const T i_right)
		: top(i_top), bottom(i_bottom), left(i_left), right(i_right) {}
	Margins(const Margins<T>& i_margins)
		: top(i_margins.top), bottom(i_margins.bottom), left(i_margins.left), right(i_margins.right) {}
	Margins& operator=(const Margins<T>& i_margins)
	{ top = i_margins.top; bottom = i_margins.bottom; left = i_margins.left; right = i_margins.right; return *this; }
	bool operator==(const Margins<T>& i_margins)
	{ return top == i_margins.top && bottom == i_margins.bottom && left == i_margins.left && right == i_margins.right; }
	bool operator!=(const Margins<T>& i_margins)
	{ return !operator==(i_margins); }

	T top, bottom, left, right;
};
/**
 * Rectangle area: position and size.
 */
template<class T>
struct Rect {
	Rect()
		: x(0), y(0), width(0), height(0) {}
	Rect(const Rect& i_rect)
		: x(i_rect.x), y(i_rect.y), width(i_rect.width), height(i_rect.height) {}
	Rect(const int i_width, const int i_height)
		: x(0), y(0), width(i_width), height(i_height) {}
	Rect(const int iX, const int iY, const int i_width, const int i_height)
		: x(iX), y(iY), width(i_width), height(i_height) {}

	T x, y, width, height;
};
/**
 * Color channels.
 * TODO
 */

}

#endif // CATMM2DTypes_H
