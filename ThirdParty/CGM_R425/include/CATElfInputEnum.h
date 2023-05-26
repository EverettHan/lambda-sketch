#ifndef CATElfInputEnum_H
#define CATElfInputEnum_H



/** =============================================================
  * COPYRIGHT DASSAULT SYSTEMES 1999
  * =============================================================
  *
  * Definition of enumerations (used by ...) :
  * - CATElfPreproCategory (CATElfInputTable, CATElfCollectorXxx)
  * - CATElfPreproType     (CATElfInputTable, CATElfCollectorXxx)
  * 
  */

#include "CATELFMathKernel.h"    // exportedBy

#include "CATBaseUnknown.h"  
#include "CATUnicodeString.h"  

enum CATElfValue  // cf. analogue CATSamValue mais avec garantie sur la taille
{
    CATElfValueInteger4,
    CATElfValueReal4,
    CATElfValueReal8,
    CATElfValueChar4,
    CATElfValueChar1,
    CATElfValueString,
    CATElfValueInteger4Ptr,
    CATElfValueReal4Ptr,
    CATElfValueReal8Ptr,
    CATElfValueChar1Ptr,
    CATElfValueChar1PtrPtr,
    CATElfValueCATMathComplexf,
    CATElfValueCATMathComplex,
/*    CATElfValueCATMathComplexfPtr,
    CATElfValueCATMathComplexPtr,*/
    CATElfValueLast
} ;


enum CATElfPreproCategory
{
    PreproCategoryMesh     , 
    PreproCategoryAxis     ,
    PreproCategoryMaterial ,
    PreproCategoryProperty ,
    PreproCategoryRestraint,
    PreproCategoryLoad     ,
    PreproCategoryMass     ,
    PreproCategoryLast
} ;

enum CATElfPreproType
{
    PreproTypeEntity,
    PreproTypeCharac,
    PreproTypeLast
} ;

// Cet enum est cree pour ne pas avoir a creer des tableaux a
// nombre d'entree variable pour la selection de la version du
// CharacCollector . (Temporaire)

enum CATElfCollectorType  // cf. Category de la version
{
    CollectorTypeGroup, // Prepro : Material,Axis,Property,Restraint,Load,Mass
    CollectorTypeApply, // Node or Element
    CollectorTypeNone
} ;

enum CATElfMatrixStorageType
{ 
	StorageFrontal,
	StorageSkyline,
	StorageLast
};

enum CATElfMatrixShape
{ 
	ShapeRectangular,
	ShapeSquare,
	ShapeUpperTriangular,
	ShapeLowerTriangular,
	ShapeDiagonal,
	ShapeLast
};

enum CATElfMatrixProperty
{ 
	PropertySymmetric,
	PropertyAntiSymmetric,
	PropertyHermitian,
	PropertyAntiHermitian,
	PropertyAny, 
	PropertyLast
};

enum CATElfMatrixType
{
	DenseMatrix,
	SparseMatrix,
	ByBlocMatrix,
	MatrixTypeLast
};

ExportedByCATELFMathKernel const char* CATElfEnumString(CATElfValue          iValue) ;
ExportedByCATELFMathKernel const char* CATElfEnumString(CATElfPreproCategory iValue) ;
ExportedByCATELFMathKernel const char* CATElfPreproCategoryName(CATElfPreproCategory iValue) ;

ExportedByCATELFMathKernel const char* CATElfMatrixTypeName(CATElfMatrixType iValue) ;
ExportedByCATELFMathKernel const char* CATElfMatrixPropertyName(CATElfMatrixProperty iValue);
ExportedByCATELFMathKernel const char* CATElfMatrixShapeName(CATElfMatrixShape iValue);
ExportedByCATELFMathKernel const char* CATElfMatrixStorageTypeName(CATElfMatrixStorageType iValue);

ExportedByCATELFMathKernel HRESULT CATElfMatrixTypeEnum(CATUnicodeString iStringNLS,CATElfMatrixType oValue) ;
ExportedByCATELFMathKernel HRESULT CATElfMatrixPropertyEnum(CATUnicodeString iStringNLS,CATElfMatrixProperty oValue);
ExportedByCATELFMathKernel HRESULT CATElfMatrixShapeEnum(CATUnicodeString iStringNLS,CATElfMatrixShape oValue);
ExportedByCATELFMathKernel HRESULT CATElfMatrixStorageTypeEnum(CATUnicodeString iStringNLS,CATElfMatrixStorageType oValue);
ExportedByCATELFMathKernel HRESULT CATElfValueEnum(CATUnicodeString iStringNLS,CATElfValue oValue);

// donne la taille du CATElfValue
ExportedByCATELFMathKernel int GetElfiniSizeOf(CATElfValue iElfValueType) ;
ExportedByCATELFMathKernel CATElfValue GetPointedType(CATElfValue iElfValueType) ;


#endif
