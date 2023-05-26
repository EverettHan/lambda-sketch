#pragma once

/****************************************************************************
	MsoTLC.h

 	Copyright (c) 1994-1997 Microsoft Corporation

	This header is a C version of the generated file msotl.h (the Office
	OLE Automation TypeLib interfaces) which wraps it and allows it to be used
	from C, because mktyplib doesn't generate a valid C (C++ only) header.
****************************************************************************/

#ifndef MSOTLC_H
#define MSOTLC_H


// MkTypLib doesn't generate typedefs for the interface structs
typedef struct CommandBars CommandBars;
typedef struct CommandBar CommandBar;
typedef struct CommandBarControl CommandBarControl;
typedef struct CommandBarControls CommandBarControls;
typedef struct  Adjustments Adjustments;
typedef struct  CalloutFormat CalloutFormat;
typedef struct  _Color _Color;
typedef struct  ConnectorFormat ConnectorFormat;
typedef struct  FillFormat FillFormat;
typedef struct  GroupShapes GroupShapes;
typedef struct  LineFormat LineFormat;
typedef struct  Node Node;
typedef struct  Nodes Nodes;
typedef struct  PictureFormat PictureFormat;
typedef struct  ShadowFormat ShadowFormat;
typedef struct  Shape Shape;
typedef struct  ShapeRange ShapeRange;
typedef struct  Shapes Shapes;
typedef struct  TextEffectFormat TextEffectFormat;
typedef struct  TextFrame TextFrame;
typedef struct  ThreeDFormat ThreeDFormat;

// Declaring a coclass emits a "class" declaration.
#define class struct

// Now include the MkTypLib-generated header
#include <msotl.h>


#endif // MSOTLC_H
