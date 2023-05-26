#ifndef CATHLRTransformation_H
#define CATHLRTransformation_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRTransformation : 
//
/** Transformation applied to the mathematical object in the HLR
 *
 * <BR> The transformation is stocked as and array of double , order
 * by column. Some added useful datas are given, as the scale and if the
 * transformation is saving the canonicity.
 */
//  
//=============================================================================
// Abstract Class     : No
// Template Code      : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Oct. 97 JCH Creation            
// Jun. 99 HKL Added the MathBox transformation method
//             Added inverse transformation data
// Apr. 01 TPG Added the DeterminantSign method
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

class CATMathDirection; 
class CATMathPoint;
class CATMathTransformation;
class CATMathVector; 
class CATMathBox; 

// System
#include "CATBoolean.h"

class ExportedByHLRModele CATHLRTransformation
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Default constructor : the identity
 */
  CATHLRTransformation();

/** Constructor from a CATMathTransformation
 */
  CATHLRTransformation(const CATMathTransformation & iTransfo);

/** Copy-constructor
 */
  CATHLRTransformation(const CATHLRTransformation & iTransfo);

  // Enumeration of the transformation type
  enum TransformationType
  {
    Identity = 1<<0,
    NonIsometry = 1<<1,
    Translation = 1<<2,
    Rotation = 1<<3
  };

//=============================================================================
// SET AND GET METHODS
//=============================================================================
/** Getting the array of doubles that defines the transformation.
 * <BR> The returned datas belongs to the transformation and must not be deleted.
 * The array's format is column after column, the last one defining the 
 * translation
 */
  inline const double * GetMatrixValues() const;
  inline const double * GetInverseMatrixValues() const;

/** Getting the scale of the transformation
 */
  inline double GetScale() const;

/** Getting the determinant sign of the transformation
 */
  inline int GetDeterminantSign() const;

//------------------------------------------------------------
// STATIC METHODS
//------------------------------------------------------------
/** Transforms the given datas if the pointer iTransfo is non NULL.
 */
  static void Apply(const CATHLRTransformation * iTranso, CATMathPoint     & ioPoint);
  static void Apply(const CATHLRTransformation * iTranso, CATMathVector    & ioVector);
  static void Apply(const CATHLRTransformation * iTranso, CATMathDirection & ioDirection);
  static void Apply(const CATHLRTransformation * iTranso, CATMathBox       & ioBox);

  static void ApplyInverse(const CATHLRTransformation * iTranso, CATMathPoint     & ioPoint);
  static void ApplyInverse(const CATHLRTransformation * iTranso, CATMathVector    & ioVector);
  static void ApplyInverse(const CATHLRTransformation * iTranso, CATMathDirection & ioDirection);

  void AddTransformationType(TransformationType iTransfoType);
  void RemoveTransformationType(TransformationType iTransfoType);

  CATBoolean IsTransformationType(TransformationType iTransfoType) const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
  int _TransfoType;

// Array of values
  double _MatrixArray[12];
  double _InverseMatrixArray[12];

// Scale of the transformation ( computed at the construction ) 
  double _Scale;

// Determinant sign of the transformation ( computed at the construction ) 
  int _DeterminantSign;
};

//=============================================================================
// INLINE IMPLEMENTATION
//=============================================================================
inline const double * CATHLRTransformation::GetMatrixValues() const
{
  return _MatrixArray;
}

inline const double * CATHLRTransformation::GetInverseMatrixValues() const
{
  return _InverseMatrixArray;
}

inline double CATHLRTransformation::GetScale() const
{
  return _Scale;
}

inline int CATHLRTransformation::GetDeterminantSign() const
{
  return _DeterminantSign;
}

#endif
