//----------------------------------------------------------------------------
//	CATMMIDrawPrimitive.h
//----------------------------------------------------------------------------
//	MMI drawing primitive definitions
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2002
//----------------------------------------------------------------------------
#ifndef CATMMIDrawPrimitive_H
#define CATMMIDrawPrimitive_H

#include "CATMMediaImageDef.h"		// CATMMIColor

struct CATMMIVertex2
{
	double	_x,_y;		//	2d position
	double	_u,_v;		//	Texture mapping
	CATMMIColor _Color;	//	vextex color
};

struct CATMMIVertex3
{
	double	_x,_y,_z;	//	3d position
	double	_u,_v;		//	Texture mapping
	CATMMIColor _Color;	//	vextex color
};


// --- Draw Primitive Flags ---
enum
{
	MMI_DPF_Mode3D			= 0x80000000,	// 2D = 0, 3D = 1
	MMI_DPF_All2dClipIn		= 0x40000000,	// all vextex inside 2d clipping zone
	MMI_DPF_All2dClipOut	= 0x20000000,	// all vextex outside 2d clipping zone

	MMI_DPF_Gouraud			= 0x00000001,	// Shading : 0= Flat, 1= Gouraud
	MMI_DPF_Textured		= 0x00000002,	// Texture : 0= Off,  1= On
	MMI_DPF_Fogged			= 0x00000004	// Fogged  : 0= Off,  1= On
};

// --- Shading Types ---
enum CATMMIShading
{
	MMI_SHD_Flat		= 0,
	MMI_SHD_FlatTex		= MMI_DPF_Textured,
	MMI_SHD_Gouraud		= MMI_DPF_Gouraud,
	MMI_SHD_GouraudTex	= MMI_DPF_Gouraud + MMI_DPF_Textured
};

// --- definition ---
struct CATMMIDrawPrimitive
{
protected:
	uint _Flags;	// Internal
	
	// --- global access ---
	uint GetFlags() const				{ return _Flags; }
	void SetFlags(const uint iFlags)	{ _Flags = iFlags; }

	// --- bit access ---
	int HasFlag(const uint iFlag) const	{ return ((_Flags & iFlag) != 0); }
	void SetFlag(const uint iFlag)		{ _Flags |= iFlag; }
	void UnsetFlag(const uint iFlag)	{ _Flags &= ~iFlag; }
	void SetFlag(const uint iFlag, const int ibYes)	{ ibYes ? SetFlag(iFlag) : UnsetFlag(iFlag); }

public:
	CATMMIDrawPrimitive(const CATMMIShading iShading=MMI_SHD_Flat) : _Flags(iShading) {}

	// --- 3DPrimitive ---
	int Is2D() const { return !Is3D(); }
	int Is3D() const { return HasFlag((uint)MMI_DPF_Mode3D); }

	// --- All2dClipIn	---
	int IsAll2dClipIn() const	{ return HasFlag((uint)MMI_DPF_All2dClipIn); }
	void SetAll2dClipIn(const int ibYes=1) { SetFlag((uint)MMI_DPF_All2dClipIn, ibYes); }

	// --- All2dClipOut --	
	int IsAll2dClipOut() const	{ return HasFlag((uint)MMI_DPF_All2dClipOut); }
	void SetAll2dClipOut(const int ibYes=1) { SetFlag((uint)MMI_DPF_All2dClipOut, ibYes); }

	// --- Shading ---
	int IsGouraud() const	{ return HasFlag((uint)MMI_DPF_Gouraud); }
	int IsFlat() const		{ return !HasFlag((uint)MMI_DPF_Gouraud); }
	void SetGouraud()		{ SetFlag((uint)MMI_DPF_Gouraud); }
	void SetFlat()			{ UnsetFlag((uint)MMI_DPF_Gouraud); }

	// --- Textured ---
	int IsTextured() const	{ return HasFlag((uint)MMI_DPF_Textured); }
	void SetTextured()		{ SetFlag((uint)MMI_DPF_Textured); }

	// --- Fogged ---
	int IsFogged() const	{ return HasFlag((uint)MMI_DPF_Fogged); }
	void SetFogged()		{ SetFlag((uint)MMI_DPF_Fogged); }
};

// --- 2D primitives ---
struct CATMMIPoint2DP : public CATMMIDrawPrimitive
{
	CATMMIPoint2DP() : CATMMIDrawPrimitive(MMI_SHD_Flat) {}

	double		_x0,_y0;
	CATMMIColor _Color;
};

struct CATMMIRectangle2DP : public CATMMIDrawPrimitive
{
	CATMMIRectangle2DP() : CATMMIDrawPrimitive(MMI_SHD_Flat) {}

	double		_x0,_y0;
	double		_x1,_y1;
	CATMMIColor _Color;
	int			_bSolid;
};

struct CATMMITriangle2DP : public CATMMIDrawPrimitive
{
	CATMMITriangle2DP(const CATMMIShading iShading=MMI_SHD_Flat) : CATMMIDrawPrimitive(iShading) {}

	CATMMIVertex2	_v0;
	CATMMIVertex2	_v1;
	CATMMIVertex2	_v2;
};

struct CATMMIQuad2DP : public CATMMIDrawPrimitive
{
	CATMMIQuad2DP(const CATMMIShading iShading=MMI_SHD_Flat) : CATMMIDrawPrimitive(iShading) {}

	CATMMIVertex2	_v0;
	CATMMIVertex2	_v1;
	CATMMIVertex2	_v2;
	CATMMIVertex2	_v3;
};

/*
// --- 3D primitives ---
struct CATMMITriangle3DP : public CATMMIDrawPrimitive
{
	CATMMITriangle3DP() {}//: CATMMIDrawPrimitive(CATMMIDrawPrimitive::3DPrimitive) {}

	CATMMIVertex3	_v0;
	CATMMIVertex3	_v1;
	CATMMIVertex3	_v2;
};

// --- 3D quadrilateral ---
struct CATMMIQuad3DP : public CATMMIDrawPrimitive
{
	CATMMIQuad3DP(){}// : CATMMIDrawPrimitive(3DPrimitive) {}

	CATMMIVertex3	_v0;
	CATMMIVertex3	_v1;
	CATMMIVertex3	_v2;
	CATMMIVertex3	_v3;
};
*/

#endif // CATMMIDrawPrimitive
