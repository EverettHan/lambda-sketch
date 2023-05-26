#ifndef CAT4x4Matrix_H
#define CAT4x4Matrix_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATMathDirectionf.h"
#include "CATMathVectorf.h"
#include "CATMathPointf.h"
#include "CATMathDirection.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"
#include <string.h>

class CATMathAxis;
class CATStreamer;

/** Class to create a 3D matrix.
 * <b>Role</b>: This object manages matrix transformations appliables to 3D
 * elements, in the homogeneous coordinate system, enabling so translations 
 * and rotations to be viewed as matrix operations.<br> 
 * The CAT4x4Matrix is commonly used to define the transformation that is to
 * be applied to CAT3DBagRep objects. 
 */
class ExportedBySGInfra CAT4x4Matrix : public CATBaseUnknown
{
  
  friend class CATMarshallable4x4Matrix;
  friend class SGCGRStreamerFor4x4Matrix;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;
  
  
  public:
    
    /** Constructs an identity 3D matrix. */
    CAT4x4Matrix (void);

    /** Constructs an 3D matrix from an other 3D matrix. */
    CAT4x4Matrix (const CAT4x4Matrix &);


    /** Constructs a 3D matrix from axis.
     * @param iAxis
     * The axis.
     */
    CAT4x4Matrix (const CATMathAxis &iAxis);

    /** Constructs a 3D matrix from 4 vectors.
     * @param iU
     * The first vector.
     * @param iV
     * The second vector.
     * @param iW
     * The third vector.
     * @param iTra
     * The fourth vector (Translation).
     */
    CAT4x4Matrix (const CATMathVectorf &iU, const CATMathVectorf &iV, const CATMathVectorf &iW, const CATMathVectorf &iTra); 
    
    /** Constructs a 3D matrix from 4 vectors.
     * @param iU
     * The first vector.
     * @param iV
     * The second vector.
     * @param iW
     * The third vector.
     * @param iTra
     * The fourth vector (Translation).
     */
    CAT4x4Matrix (const CATMathVector &iU, const CATMathVector &iV, const CATMathVector &iW, const CATMathVector &iTra); 

    /** Constructs a 3D translation matrix from a translation vector.
     * @param iTra
     * The translation vector.
     */
    CAT4x4Matrix (const CATMathVectorf &iTra);  

    /** Constructs a 3D matrix from a float array and a translation
     * vector.
     * @param iRot
     * The rotation float array.
     * @param iTra
     * The translation vector.
     */
    CAT4x4Matrix (const float **iRot,                   // 3x3 Rotation matrix
		  const CATMathVectorf &iTra);          // Translation vector

    /** Constructs a 3D matrix from a rotation and angle vector and an invariant
     * point.
     * @param iRot
     * The rotation and angle vector.
     * @param iInv
     * the invariant point.
     */
    CAT4x4Matrix (const CATMathVectorf &iRot,         // Rotation axis and angle
		  const CATMathPointf  &iInv);        // Invariant point

    /** Constructs a 3D matrix from a translation vector, a rotation and angle
     * vector and an invariant point.
     * @param iTra
     * The translation vector.
     * @param iRot
     * The rotation and angle vector.
     * @param iInv
     * the invariant point.
     */
    CAT4x4Matrix (const CATMathVectorf &iTra,         // Translation vector
		  const CATMathVectorf &iRot,         // Rotation axis and angle
		  const CATMathPointf  &iInv);        // Invariant point

    /** Destructor. */
    virtual ~CAT4x4Matrix (void);

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
    CAT4x4Matrix & operator *= (const CAT4x4Matrix & iMatrix);

    /**
     * Assignment operator.
     * @param iMatrix
     *   The matrix to assign to the current one
     * @return 
     *   The matrix resulting from the assignment
     */
    CAT4x4Matrix & operator  = (const CAT4x4Matrix & iMatrix);
    
    /**
     * Multiplication operator.
     * @param iMatrix
     *   The matrix to multiply with the current one
     * @return
     *   The matrix resulting from the multiplication
     */
    CAT4x4Matrix   operator  * (const CAT4x4Matrix & iMatrix) const;

    /**
     * Multiplies a matrix by a space point.
     * <br><b>Role:</b>
     * The 3x3 submatrix is multiplied by the point coordinate triplet
     * and the matrix translation vector is added to the multiplication result
     * @param iPoint
     *   The point whose coordinate triplet is to be multiplied by the matrix
     * @return
     *   The point resulting from the multiplication
     */
    CATMathPointf     operator * (const CATMathPointf & iPoint) const;

    /**
     * Multiplies a matrix by a space point.
     * <br><b>Role:</b>
     * The 3x3 submatrix is multiplied by the point coordinate triplet
     * and the matrix translation vector is added to the multiplication result
     * @param iPoint
     *   The point whose coordinate triplet is to be multiplied by the matrix
     * @return
     *   The point resulting from the multiplication
     */
    CATMathPoint     operator * (const CATMathPoint & iPoint) const;

    /**
     * Multiplies a matrix by a space vector.
     * <br><b>Role:</b>
     * The 3x3 submatrix is multiplied by the vector component triplet
     * and the matrix translation vector is added to the multiplication result
     * @param iVector
     *   The vector whose component triplet is to be multiplied by the matrix
     * @return
     *   The vector resulting from the multiplication
     */
    CATMathVectorf    operator * (const CATMathVectorf & iVector) const;

    /**
     * Multiplies a matrix by a space vector.
     * <br><b>Role:</b>
     * The 3x3 submatrix is multiplied by the vector component triplet
     * and the matrix translation vector is added to the multiplication result
     * @param iVector
     *   The vector whose component triplet is to be multiplied by the matrix
     * @return
     *   The vector resulting from the multiplication
     */
    CATMathVector    operator * (const CATMathVector & iVector) const;

    /**
     * Multiplies a matrix by a space direction.
     * <br><b>Role:</b>
     * The 3x3 submatrix is multiplied by the direction component triplet
     * and the matrix translation vector is added to the multiplication result
     * @param iDirection
     *   The direction whose component triplet is to be multiplied by the matrix
     * @return
     *   The direction resulting from the multiplication
     */
    CATMathDirectionf operator * (const CATMathDirectionf & iDirection) const;

    /**
     * Multiplies a matrix by a space direction.
     * <br><b>Role:</b>
     * The 3x3 submatrix is multiplied by the direction component triplet
     * and the matrix translation vector is added to the multiplication result
     * @param iDirection
     *   The direction whose component triplet is to be multiplied by the matrix
     * @return
     *   The direction resulting from the multiplication
     */
    CATMathDirection operator * (const CATMathDirection & iDirection) const;

    /** Sets the 3D matrix translation from a vector.
     * @param iTra
     * The translation vector.
     * @param w
     * Do not use this parameter.
     */
    void SetTranslation (const CATMathVectorf & iTra, const float w = 1.f);

    /** Sets the 3D matrix translation from a vector.
     * @param iTra
     * The translation vector.
     * @param w
     * Do not use this parameter.
     */
    void SetTranslation (const CATMathVector & iTra, const float w = 1.f);

    /** Gets the 3D matrix translation vector.
     * @param oTra
     * The returned translation vector.
     */
    void GetTranslation (CATMathVectorf & oTra) const;  
    
    /** Gets the 3D matrix translation vector.
     * @param oTra
     * The returned translation vector.
     */
    void GetTranslation (CATMathVector & oTra) const;  

    /** Gets the 3D matrix components.
     * @param oU
     * The returned U rotation vector.
     * @param oV
     * The returned V rotation vector.
     * @param oW
     * The returned W rotation vector.
     * @param oTra
     * The returned translation point.
     */
    void GetComponents (CATMathVectorf &oU, CATMathVectorf &oV, CATMathVectorf &oW, CATMathPointf &oT) const;

    /** Gets the 3D matrix components.
     * @param oU
     * The returned U rotation vector.
     * @param oV
     * The returned V rotation vector.
     * @param oW
     * The returned W rotation vector.
     * @param oTra
     * The returned translation point.
     */
    void GetComponents (CATMathVector &oU, CATMathVector &oV, CATMathVector &oW, CATMathPoint &oT) const;

    /** Gets the 3D matrix components.
     * @param oU
     * The returned U rotation direction.
     * @param oV
     * The returned V rotation direction.
     * @param oW
     * The returned W rotation direction.
     * @param oTra
     * The returned translation point.
     */
    void GetComponents (CATMathDirectionf &oU, CATMathDirectionf &oV, CATMathDirectionf &oW, CATMathPointf &oT) const;

    /** Sets the 3D matrix components.
     * @param iU
     * The U rotation vector.
     * @param iV
     * The V rotation vector.
     * @param iW
     * The W rotation vector.
     * @param iTra
     * The translation point.
     */
    void SetComponents (const CATMathVectorf &iU, const CATMathVectorf &iV, const CATMathVectorf &iW, const CATMathPointf &iT);

    /** Sets the 3D matrix components.
     * @param iU
     * The U rotation vector.
     * @param iV
     * The V rotation vector.
     * @param iW
     * The W rotation vector.
     * @param iTra
     * The translation point.
     */
    void SetComponents (const CATMathVector &iU, const CATMathVector &iV, const CATMathVector &iW, const CATMathPoint &iT);

    /** Sets the 3D matrix components.
     * @param iU
     * The U rotation direction.
     * @param iV
     * The V rotation direction.
     * @param iW
     * The W rotation direction.
     * @param iTra
     * The translation point.
     */
    void SetComponents (const CATMathDirectionf &iU, const CATMathDirectionf &iV, const CATMathDirectionf &iW, const CATMathPointf &iT);

    /** Sets the 3D matrix components.
     * @param iU
     * The U rotation direction.
     * @param iV
     * The V rotation direction.
     * @param iW
     * The W rotation direction.
     * @param iTra
     * The translation point.
     */
    void SetComponents (const CATMathDirectionf &iU, const CATMathDirectionf &iV, const CATMathDirectionf &iW, const CATMathPoint &iT);

    /** Sets the 3D matrix components.
     * @param iU
     * The U rotation direction.
     * @param iV
     * The V rotation direction.
     * @param iW
     * The W rotation direction.
     * @param iTra
     * The translation point.
     */
    void SetComponents (const CATMathDirection &iU, const CATMathDirection &iV, const CATMathDirection &iW, const CATMathPoint &iT);

    /** Sets all elements of the 3D matrix.
     * @param iValues
     * Array of 16 floats (4 floats for 1st column, 4 floats for 2nd column, ...)
     */
     void SetElements(float *iValues);
    
    /** Sets all elements of the 3D matrix.
     * @param iValues
     * Array of 16 doubles (4 doubles for 1st column, 4 doubles for 2nd column, ...)
     */
     void SetElements(double *iValues);

     /** Sets one element of the 3D matrix.
     * @param iRow
     * The row indice.
     * @param iCol
     * The column indice.
     * @param iValue.
     * The value of the rowth and columnth element to be set.
     * @param iUpdateDeterminantAndScaling.
     * Compute the determinant and the scaling of the matrix if set to 1.
     */
    inline void SetElement( int iRow, int iCol, double iValue, int iUpdatesDeterminantAndScaling=1);

    /** Gets the inverted 3D matrix.
     * @param oMatrix
     * The returned inverted matrix.
     */
    void GetInvertedMatrix (CAT4x4Matrix & oMatrix) const;

    /** Gets the determinant of the 3D matrix.
     * @return
     * The value of the determinant.
     */
    inline double GetDeterminant (void) const;
    

    /** Gets the 3D matrix elements.
     * @param ioMatrix
     * An array of 16 double to be filled with the matrix elements (4 double for 1st column, 4 double for 2nd column, ...)
    */
    void GetMatrix(double ioMatrix[16]) const;
    
    /** Gets the 3D matrix elements.
     * @param ioMatrix
     * An array of 16 float to be filled with the matrix elements (4 float for 1st column, 4 float for 2nd column, ...)
     * Be aware that the internal data of a matrix are double.
    */
    void GetMatrixInFloat(float ioMatrix[16]) const;

    /**
     * Gets the biggest eigen value of the 3D matrix.
     * Useful to transform bounding spheres when having non-uniform scaling
     * @return
     * The value of the scaling factor of the 3D matrix.
     */
    double GetScaling (void) const;

    /** Indicates if the 3D matrix is an identity matrix.
     * @return
     * The status of the 3D matrix.
     */
    int IsIdentity (void) const;
    
    /** Multiplies the 3D matrix by a direction.
     * @param ioDirection
     * The direction multiply by the matrix and the returned direction.
     */
    inline void multiply (CATMathDirectionf & ioDirection) const;

    /** Multiplies the 3D matrix by a direction.
     * @param ioDirection
     * The direction multiply by the matrix and the returned direction.
     */
    inline void multiply (CATMathDirection & ioDirection) const;

    /** Multiplies the 3D matrix by a vector.
     * @param ioVector
     * The vector multiply by the matrix and the returned vector.
     */
    inline void multiply (CATMathVectorf & ioVector) const;

    /** Multiplies the 3D matrix by a vector.
     * @param ioVector
     * The vector multiply by the matrix and the returned vector.
     */
    inline void multiply (CATMathVector & ioVector) const;

    /** Multiplies the 3D matrix by a point.
     * @param ioPoint
     * The point multiply by the matrix and the returned point.
     */
    inline void multiply (CATMathPointf & ioPoint) const;

    /** Multiplies the 3D matrix by a point.
     * @param ioPoint
     * The point multiply by the matrix and the returned point.
     */
    inline void multiply (CATMathPoint & ioPoint) const;

    /** Multiplies the 3D matrix by a point represented by coordinates.
    * @param ioX
    * X coordinate of point
    * @param ioY
    * Y coordinate of point
    * @param ioZ
    * Z coordinate of point
    * matrix applied on ioX, ioY, ioZ and returned.
    */
    inline void multiply(double & ioX, double& ioY, double& ioZ) const;

    /** Multiplies a 3D matrix by another 3D matrix.
     * @param iMatrix1
     * The first 3D matrix. 
     * @param iMatrix2
     * The second 3D matrix. 
     */
    inline void multiply (const CAT4x4Matrix &iMatrix1, const CAT4x4Matrix &iMatrix2);

    /** Computes an Inversed, Transposed with the third column normalized 
     * 3D matrix.
     * @param oMatrix
     * The components of the resultant 3D matrix.
     */
    void ComputeInverseTransposeThirdColumnNormalized( float * oMatrix ) const;

	/**
	Compares 2 matrix
	@return TRUE if the matrix are equal, FALSE else
	*/
	CATBoolean IsEqualTo(const CAT4x4Matrix &iMatrix) const;

	/** Get one element of the 3D matrix.
	* @param iRow
	* The row indice.
	* @param iCol
	* The column indice.
	* @return The value of the rowth and columnth element. 0.0 if iRow or ICol are invalid.	
	*/
	double GetElement(int iRow, int iCol) const;

  /**
  * This function assumes the matrix is a Translation * Rotation * Scale, matrix
  * Scale can be non-uniform, it returns the normalization value across a single axis
  * stored in the matrix.
  * @param iAxis
  * Pass 0 for X axis, 1 for Y axis and 2 for Z axis.
  */
  inline double GetScaleAlongAxis(int iAxis) const;

//------------------------------------------------------------------------------
  private:

    /** @nodoc */
    void SetRotation (const CATMathDirectionf &, const CATMathPointf &, const float &);

    /** @nodoc */
    void ComputeScaling();

    /** @nodoc */
    void ComputeDeterminant();
  
	  /** @nodoc */
	  void Compare() const;

    mutable float * matrix;
    double matrixd[4][4];
    double _determinant;
    mutable double _scaling;
};

//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************

inline void CAT4x4Matrix::multiply (CATMathDirectionf &direction) const
{
 double x = direction.x;
 double y = direction.y;
 double z = direction.z;
 
 direction.x = (float)(matrixd[0][0] * x + matrixd[1][0] * y + matrixd[2][0] * z);
 direction.y = (float)(matrixd[0][1] * x + matrixd[1][1] * y + matrixd[2][1] * z);
 direction.z = (float)(matrixd[0][2] * x + matrixd[1][2] * y + matrixd[2][2] * z);

 if ( _scaling != 1.0 ) 
 {
  direction.Normalize();
 }
}

inline void CAT4x4Matrix::multiply (CATMathDirection &direction) const
{
 double x = direction.GetX();
 double y = direction.GetY();
 double z = direction.GetZ();
 
 direction.SetCoord(matrixd[0][0] * x + matrixd[1][0] * y + matrixd[2][0] * z,
                    matrixd[0][1] * x + matrixd[1][1] * y + matrixd[2][1] * z,
                    matrixd[0][2] * x + matrixd[1][2] * y + matrixd[2][2] * z);

 if ( _scaling != 1.0 ) 
 {
  direction.Normalize();
 }
}

inline void CAT4x4Matrix::multiply (CATMathPointf &point) const
{
 double x = point.x;
 double y = point.y;
 double z = point.z;
 
 point.x = (float)(matrixd[0][0] * x + matrixd[1][0] * y + matrixd[2][0] * z + matrixd[3][0]);
 point.y = (float)(matrixd[0][1] * x + matrixd[1][1] * y + matrixd[2][1] * z + matrixd[3][1]);
 point.z = (float)(matrixd[0][2] * x + matrixd[1][2] * y + matrixd[2][2] * z + matrixd[3][2]);
}

inline void CAT4x4Matrix::multiply (CATMathPoint &point) const
{
 double x = point.GetX();
 double y = point.GetY();
 double z = point.GetZ();
 
 point.SetCoord( matrixd[0][0] * x + matrixd[1][0] * y + matrixd[2][0] * z + matrixd[3][0], 
                 matrixd[0][1] * x + matrixd[1][1] * y + matrixd[2][1] * z + matrixd[3][1],
                 matrixd[0][2] * x + matrixd[1][2] * y + matrixd[2][2] * z + matrixd[3][2]);
}

inline void CAT4x4Matrix::multiply (CATMathVectorf &vector) const
{
 double x = vector.x;
 double y = vector.y;
 double z = vector.z;
 
 vector.x = (float)(matrixd[0][0] * x + matrixd[1][0] * y + matrixd[2][0] * z);
 vector.y = (float)(matrixd[0][1] * x + matrixd[1][1] * y + matrixd[2][1] * z);
 vector.z = (float)(matrixd[0][2] * x + matrixd[1][2] * y + matrixd[2][2] * z);
}

inline void CAT4x4Matrix::multiply (CATMathVector &vector) const
{
 double x = vector.GetX();
 double y = vector.GetY();
 double z = vector.GetZ();
 
 vector.SetCoord( matrixd[0][0] * x + matrixd[1][0] * y + matrixd[2][0] * z,
                  matrixd[0][1] * x + matrixd[1][1] * y + matrixd[2][1] * z,
                  matrixd[0][2] * x + matrixd[1][2] * y + matrixd[2][2] * z);
}

inline void CAT4x4Matrix::multiply(double& ioX, double& ioY, double& ioZ) const
{
    double tX = matrixd[0][0] * ioX + matrixd[1][0] * ioY + matrixd[2][0] * ioZ + matrixd[3][0];
    double tY = matrixd[0][1] * ioX + matrixd[1][1] * ioY + matrixd[2][1] * ioZ + matrixd[3][1];
    double tZ = matrixd[0][2] * ioX + matrixd[1][2] * ioY + matrixd[2][2] * ioZ + matrixd[3][2];
    ioX = tX;
    ioY = tY;
    ioZ = tZ;
}


inline double CAT4x4Matrix::GetDeterminant() const
{
 return (_determinant);
}

inline void CAT4x4Matrix::SetElement( int iRow, int iCol, double value, int update)
{
  if(iRow > 3 || iCol > 3) return;
  //matrix[column][row] = (float)value; // R8Z: previous impl was misleading: rows & cols were inversed from definition...
  matrixd[iRow][iCol] = value;
  if (update)
  {
    ComputeDeterminant();
    ComputeScaling();
  }
}

inline void CAT4x4Matrix::multiply (const CAT4x4Matrix &m1,  const CAT4x4Matrix &m2 ) 
{
 double result[4][4];

 result[0][0] = m1.matrixd[0][0]*m2.matrixd[0][0] + m1.matrixd[0][1]*m2.matrixd[1][0] + m1.matrixd[0][2]*m2.matrixd[2][0] + m1.matrixd[0][3]*m2.matrixd[3][0];
 result[1][0] = m1.matrixd[1][0]*m2.matrixd[0][0] + m1.matrixd[1][1]*m2.matrixd[1][0] + m1.matrixd[1][2]*m2.matrixd[2][0] + m1.matrixd[1][3]*m2.matrixd[3][0];
 result[2][0] = m1.matrixd[2][0]*m2.matrixd[0][0] + m1.matrixd[2][1]*m2.matrixd[1][0] + m1.matrixd[2][2]*m2.matrixd[2][0] + m1.matrixd[2][3]*m2.matrixd[3][0];
 result[3][0] = m1.matrixd[3][0]*m2.matrixd[0][0] + m1.matrixd[3][1]*m2.matrixd[1][0] + m1.matrixd[3][2]*m2.matrixd[2][0] + m1.matrixd[3][3]*m2.matrixd[3][0];

 result[0][1] = m1.matrixd[0][0]*m2.matrixd[0][1] + m1.matrixd[0][1]*m2.matrixd[1][1] + m1.matrixd[0][2]*m2.matrixd[2][1] + m1.matrixd[0][3]*m2.matrixd[3][1];
 result[1][1] = m1.matrixd[1][0]*m2.matrixd[0][1] + m1.matrixd[1][1]*m2.matrixd[1][1] + m1.matrixd[1][2]*m2.matrixd[2][1] + m1.matrixd[1][3]*m2.matrixd[3][1];
 result[2][1] = m1.matrixd[2][0]*m2.matrixd[0][1] + m1.matrixd[2][1]*m2.matrixd[1][1] + m1.matrixd[2][2]*m2.matrixd[2][1] + m1.matrixd[2][3]*m2.matrixd[3][1];
 result[3][1] = m1.matrixd[3][0]*m2.matrixd[0][1] + m1.matrixd[3][1]*m2.matrixd[1][1] + m1.matrixd[3][2]*m2.matrixd[2][1] + m1.matrixd[3][3]*m2.matrixd[3][1];

 result[0][2] = m1.matrixd[0][0]*m2.matrixd[0][2] + m1.matrixd[0][1]*m2.matrixd[1][2] + m1.matrixd[0][2]*m2.matrixd[2][2] + m1.matrixd[0][3]*m2.matrixd[3][2];
 result[1][2] = m1.matrixd[1][0]*m2.matrixd[0][2] + m1.matrixd[1][1]*m2.matrixd[1][2] + m1.matrixd[1][2]*m2.matrixd[2][2] + m1.matrixd[1][3]*m2.matrixd[3][2];
 result[2][2] = m1.matrixd[2][0]*m2.matrixd[0][2] + m1.matrixd[2][1]*m2.matrixd[1][2] + m1.matrixd[2][2]*m2.matrixd[2][2] + m1.matrixd[2][3]*m2.matrixd[3][2];
 result[3][2] = m1.matrixd[3][0]*m2.matrixd[0][2] + m1.matrixd[3][1]*m2.matrixd[1][2] + m1.matrixd[3][2]*m2.matrixd[2][2] + m1.matrixd[3][3]*m2.matrixd[3][2];
 
 result[0][3] = m1.matrixd[0][0]*m2.matrixd[0][3] + m1.matrixd[0][1]*m2.matrixd[1][3] + m1.matrixd[0][2]*m2.matrixd[2][3] + m1.matrixd[0][3]*m2.matrixd[3][3];
 result[1][3] = m1.matrixd[1][0]*m2.matrixd[0][3] + m1.matrixd[1][1]*m2.matrixd[1][3] + m1.matrixd[1][2]*m2.matrixd[2][3] + m1.matrixd[1][3]*m2.matrixd[3][3];
 result[2][3] = m1.matrixd[2][0]*m2.matrixd[0][3] + m1.matrixd[2][1]*m2.matrixd[1][3] + m1.matrixd[2][2]*m2.matrixd[2][3] + m1.matrixd[2][3]*m2.matrixd[3][3];
 result[3][3] = m1.matrixd[3][0]*m2.matrixd[0][3] + m1.matrixd[3][1]*m2.matrixd[1][3] + m1.matrixd[3][2]*m2.matrixd[2][3] + m1.matrixd[3][3]*m2.matrixd[3][3];

 memcpy(matrixd,result,16*sizeof(double));

 _determinant = m1._determinant * m2._determinant;
 _scaling     = m1._scaling * m2._scaling; 
 //CopyDoubleToFloat();
}

inline double CAT4x4Matrix::GetScaleAlongAxis(int iAxis) const
{
  return sqrt(
    matrixd[iAxis][0] * matrixd[iAxis][0] +
    matrixd[iAxis][1] * matrixd[iAxis][1] +
    matrixd[iAxis][2] * matrixd[iAxis][2]);
}

#endif
