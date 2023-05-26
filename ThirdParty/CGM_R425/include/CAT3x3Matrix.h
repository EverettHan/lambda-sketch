#ifndef CAT3x3Matrix_H
#define CAT3x3Matrix_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//******************************************************************************
//  CATIA Version 5 Release 1 Framework VFW2
//  Copyright Dassault Systemes 1997
//******************************************************************************
//  Abstract:
//  ---------
//    This object manages matrix transformations appliables to 2D elements, in
//    the homogeneous coordinate system, enabling so translations to be viewed
//    as matrix operations.
//    The CAT3x3Matrix is commonly used to define the transformation that is to
//    be applied to CAT2DBagRep objects.
//
//******************************************************************************
//  Usage:   
//  ------
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3x3Matrix
//                  CATBaseUnknown (SYSTEM framework) 
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************

#include "SGInfra.h"
#include "CATBaseUnknown.h"

class CATMathPoint2Df;
class CATMathVector2Df;
class CATMathDirection2Df;
class CATMathAxis2D;
class CATStreamer;


/** Class to create a 2D matrix.
 * <b>Role</b>: This object manages matrix transformations appliables to 2D
 * elements, in the homogeneous coordinate system, enabling so translations 
 * to be viewed as matrix operations.<br> 
 * The CAT3x3Matrix is commonly used to define the transformation that is to
 * be applied to CAT2DBagRep objects. 
 */
class ExportedBySGInfra CAT3x3Matrix : public CATBaseUnknown
{
  friend class SGCGRStreamerFor3x3Matrix;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;

  public:
    
    /** Constructs an identity 2D matrix. */
    CAT3x3Matrix (void);

    /** Constructs a 2D matrix from axis.
     * @param iAxis
     * The axis.
     */
    CAT3x3Matrix (const CATMathAxis2D &iAxis);

    /** Constructs a 2D matrix from 3 vectors.
     * @param iU
     * The fisrt vector.
     * @param iV
     * The second vector.
     * @param iTra
     * The fourth vector (Translation).
     */
    CAT3x3Matrix (const CATMathVector2Df &iU, const CATMathVector2Df &iV, const CATMathPoint2Df &iTra); 

    /** Constructs a 2D translation matrix from a translation vector.
     * @param iTra
     * The translation vector.
     */
    CAT3x3Matrix (const CATMathVector2Df &iTra);  

    /** Constructs a 2D matrix from a float array and a translation vector.
     * @param iMat2x2
     * The 2x2 float array.
     * @param iTra
     * The translation vector.
     */
    CAT3x3Matrix (const float iMat2x2[2][2], const CATMathPoint2Df &iTra);

    /** Destructor. */
    virtual ~CAT3x3Matrix (void);

    /** @nodoc
     * Streaming
     */
    virtual void Stream(CATStreamer& str,int savetype=0);

    /** @nodoc
     * Unstreaming
     */
    virtual void UnStream(CATStreamer& str);
    
    /**
     * Multiplication assignment operator.
     * @param iMatrix
     *   The matrix to multiply with the current one
     * @return
     *   The matrix resulting from the multiplication
     */
    CAT3x3Matrix & operator *= (const CAT3x3Matrix & iMatrix);

    /**
     * Assignment operator.
     * @param iMatrix
     *   The matrix to assign to the current one
     * @return 
     *   The matrix resulting from the assignment
     */
    CAT3x3Matrix & operator  = (const CAT3x3Matrix & iMatrix);

    /**
     * Multiplication operator.
     * @param iMatrix
     *   The matrix to multiply with the current one
     * @return
     *   The matrix resulting from the multiplication
     */
    CAT3x3Matrix   operator  * (const CAT3x3Matrix & iMatrix) const;
    
    /**
     * Multiplies a matrix by a 2D point.
     * <br><b>Role:</b>
     * The 2x2 submatrix is multiplied by the point coordinate doublet
     * and the matrix translation vector is added to the multiplication result
     * @param iPoint
     *   The point whose coordinate doublet is to be multiplied by the matrix
     * @return
     *   The point resulting from the multiplication
     */
    CATMathPoint2Df     operator * (const CATMathPoint2Df & iPoint) const;

    /**
     * Multiplies a matrix by a 2D vector.
     * <br><b>Role:</b>
     * The 2x2 submatrix is multiplied by the vector component doublet
     * and the matrix translation vector is added to the multiplication result
     * @param iVector
     *   The vector whose component doublet is to be multiplied by the matrix
     * @return
     *   The vector resulting from the multiplication
     */
    CATMathVector2Df    operator * (const CATMathVector2Df & iVector) const ;

    /**
     * Multiplies a matrix by a 2D direction.
     * <br><b>Role:</b>
     * The 2x2 submatrix is multiplied by the direction component doublet
     * and the matrix translation vector is added to the multiplication result
     * @param iDirection
     *   The direction whose component doublet is to be multiplied by the matrix
     * @return
     *   The direction resulting from the multiplication
     */
    CATMathDirection2Df operator * (const CATMathDirection2Df & iDirection) const ;

    /** Gets the 2D matrix translation vector.
     * @return
     * The returned translation vector.
     */
    CATMathVector2Df GetTranslation (void)   const;

    /** Gets the 2D matrix translation vector.
     * @param oTra
     * The returned translation vector.
     */
    void GetTranslation (CATMathVector2Df & oTra) const;  

    /** Sets the 2D matrix translation from a vector.
     * @param iTra
     * The translation vector.
     */
    void SetTranslation (const CATMathVector2Df & iTra);
    
    /** Gets the 2D matrix components.
     * @param oU
     * The returned U rotation vector.
     * @param oV
     * The returned V rotation vector.
     * @param oTra
     * The returned translation point.
     */
    void GetComponents (CATMathVector2Df &oU, CATMathVector2Df &oV, CATMathPoint2Df &oTra) const;

    /** Sets the 2D matrix components.
     * @param iU
     * The U rotation vector.
     * @param iV
     * The V rotation vector.
     * @param iTra
     * The translation point.
     */
    void SetComponents (const CATMathVector2Df &iU, const CATMathVector2Df &iV, const CATMathPoint2Df &iTra);

    /** Gets the inverted 2D matrix.
     * @return 
     * The returned inverted matrix.
     */
    CAT3x3Matrix GetInvertedMatrix (void) const;

    /** Gets the inverted 2D matrix.
     * @param oMatrix
     * The returned inverted matrix.
     */
    void GetInvertedMatrix (CAT3x3Matrix &) const;


    /** Gets the determinant of the 2D matrix.
     * @return
     * The value of the determinant.
     */
    inline float GetDeterminant (void) const;

    /** Gets the 2D matrix components.
     * @return
     * The float pointer of the 2D matrix components.
     */
    inline float * GetMatrix (void) const; 

    /** Gets the scaling factor of the 2D matrix.
     * @return
     * The value of the scaling factor of the 3D matrix.
     */
    inline float GetScaling (void) const;

    /** Indicates if the 2D matrix is an identity matrix.
     * @return
     * The status of the 2D matrix.
     */
    int IsIdentity (void) const;
    
    
  private:

    /** @nodoc */
    void ComputeScaling();

    /** @nodoc */
    void ComputeDeterminant();
  
    float matrix[4][4];
    float _determinant;
    float _scaling;
};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline float * CAT3x3Matrix::GetMatrix() const
{
 return (float *) &matrix[0][0];
}

inline float CAT3x3Matrix::GetDeterminant() const
{
 return (_determinant);
}

inline float CAT3x3Matrix::GetScaling() const
{
 return (_scaling);
}


#endif
