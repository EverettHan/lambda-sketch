/**
@file

This file introduce some enums useful for all
other modules.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkKernelEnums_h)
#define __vkKernelEnums_h

namespace VKernel {

/**
Priority of the loading/setready management.
*/
enum EStorePriority
{
	eLowestPriority		= 0,
	eNormalPriority		= 7,
	eHighestPriority	= 15
};

/**
Comparison Operators
*/
enum EComparisonOp
{
	eEqual,
	eLessThan,
	eLessOrEqual,
	eGreaterThan,
	eGreaterOrEqual
};

/**
Comparison Operators
*/
enum ESetOperation
{
	eUnion,
	eIntersection,
	eSubtraction,
	eExclusion
};

/**
Defines an alignment.
*/
enum EAlignment
{
	// Invalid alignment.
	eInvalidAlignment = -1,

	// Near.
	eNear		= 0,

	// Center.
	eCenter		= 1,

	// Far.
	eFar		= 2,

	// Justified.
	eJustify	= 3
};


} // end namespace VKernel

#endif



