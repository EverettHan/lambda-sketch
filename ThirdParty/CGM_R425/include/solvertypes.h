// ********************************************************
//
// Aditional types for 2D Dimentional Constraint Manager
//
// ********************************************************

#ifndef SOLVERTYPES_H
#define SOLVERTYPES_H

typedef enum SOLVER_alignment {
	SOLVER_ALIGNMENT_NOT_SPECIFIED,
	SOLVER_ALIGNMENT_ALIGN,
	SOLVER_ALIGNMENT_ANTI_ALIGN
} SOLVER_alignment;

typedef enum SOLVER_half_space {
	SOLVER_HALF_SPACE_NOT_SPECIFIED,
	SOLVER_HALF_SPACE_POSITIVE,
	SOLVER_HALF_SPACE_NEGATIVE
} SOLVER_half_space;

typedef enum DCM_curve_type {
  DCM_curve_type_unknown,
	DCM_curve_type_offset,
	DCM_curve_type_conic,
  DCM_curve_type_connect,
  DCM_curve_type_clothoid
	} DCM_curve_type;

#endif
