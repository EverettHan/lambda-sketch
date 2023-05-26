#ifndef CATSGTransformMatrix44_H
#define CATSGTransformMatrix44_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATSGGenVec4.h"

namespace CATSG {
    /**
    DISCLAIMER !! This is vkTransformMatrix44 from VIAMPFoundation !!
    We need only a few things from VIAMPFoundation, so a small duplication seems a good trade off
    to avoid higher complexity in dependency hell. Besides that prerequisite might not be authorized for me all the time
    and it would be absurd to rewrite....
    */

    /**
    Transformation matrix.

    This file defines a 4x4 double matrix class
    which is frequently used to represent 3D affine transformations
    such as rotations , translations and scales.
    It can also be used to store projection matrices

    Such matrices must be in the form
    <pre>
    [  Rot   Rot    Rot    0  ]
    [  Rot   Rot    Rot    X  ]
    [  Rot   Rot    Rot    X  ]
    [  XPos  YPos   ZPos   X  ]
    </pre>

    This restriction allows us to store additional information
    about this matrix such as if it is
    - Orthogonal
    - Orthonormal
    - The identity matrix
    - Uniformly Scaled
    - Has a translation part
    - Has a rotation part
    Which can provide very important optimizations for matrix operations

    @see vkMatrix44, vkTransformPRS
    */
    class ExportedBySGComposites CATSGTransformMatrix44
    {
    public:

        CATSGTransformMatrix44();//identity matrix
        CATSGTransformMatrix44(bool iPlaceHolder);//uninitialized

        CATSGTransformMatrix44(const CATSGDVec3& iRight, const CATSGDVec3& iUp, const CATSGDVec3& iDirection, const CATSGDVec3& iPosition);

        CATSGTransformMatrix44& Create(const CATSGDVector& iRight, const CATSGDVector& iUp, const CATSGDVector& iDirection, const CATSGDPoint& iPosition);
        CATSGTransformMatrix44& Create(const CATSGTransformMatrix44& iMatrix);

        CATSGTransformMatrix44& CreateRotation(const CATSGDVec3& iAxis, const double iRadAngle);
        CATSGTransformMatrix44& CreateUncenteredRotation(const CATSGDVec3& iAxis, const double iRadAngle, const CATSGDVec3& iRotationCenter);
        CATSGTransformMatrix44& CreateScale(const double iScale);
        CATSGTransformMatrix44& CreateScale(const CATSGDVec3& iScale);
        CATSGTransformMatrix44& CreateTranslation(const CATSGDVec3& iTranslation);

        static CATSGTransformMatrix44 NaTValue();

        void SetElements(float *iValues);
        void SetElements(double *iValues);
        void GetMatrixInFloat(float ioMatrix[16]) const;
        void GetMatrix(double ioMatrix[16]) const;
        void GetComponents(CATSGDVec3 &u, CATSGDVec3 &v, CATSGDVec3 &w, CATSGDVec3 &o);
        CATSGTransformMatrix44 operator*(const CATSGTransformMatrix44 &m) const;

        /**
        Compare to matrices, using an epsilon value.

        @param iMatrix the matrix to compare to.

        @return true if the two matrices are equal.
        */
        inline bool Equal(const CATSGTransformMatrix44& iMatrix) const;

        // Matrix CATAssert
        /*inline*/ CATSGTransformMatrix44& PreMultiplyBy(const CATSGTransformMatrix44& iTransform);
        /*inline*/ CATSGTransformMatrix44& PostMultiplyBy(const CATSGTransformMatrix44& iTransform);

        static void MultiplyAB(CATSGTransformMatrix44& oDst, const CATSGTransformMatrix44& iA, const CATSGTransformMatrix44& iB);

        /**
        Multiplies the invert of a transform by another.

        @param

        @return
        oDst = InverseTransform(iA) * iB;

        @see vkMultiplyTransform
        */
        static void MultiplyInvTransformAB(CATSGTransformMatrix44& oDst, const CATSGTransformMatrix44& iA, const CATSGTransformMatrix44& iB);

        /**
        Computes the inversed transformation
        */
        /*inline*/ CATSGTransformMatrix44& InverseTransform();

        /**
        Computes the inverse of a Matrix.

        - if the matrix is orthogonal with an uniform scale,
        its invert is simply its transposition of its rotation component,
        multiplied by its inverse scale, with the translation component
        negated and transformed by the already inversed rotation part.

        - oDst can not be the calling matrix.

        @param oDst the result inverse of the matrix.

        @see ComputeInverseTranspose
        */
        void ComputeInverseTransform(CATSGTransformMatrix44& oDst) const;//for rigid body transforms only
        void ComputeInverse4x4(CATSGTransformMatrix44& oDst) const;//general 4x4 matrix inversion

        // Modifications
        /*inline*/ CATSGTransformMatrix44& Translate(const CATSGDVector& iTranslation);
        /*inline*/ CATSGTransformMatrix44& Scale(const CATSGDVec3& iScale);
        /*inline*/ CATSGTransformMatrix44& Scale(double iScale);

        /*inline*/ const CATSGDPoint&  GetPosition() const;
        /*inline*/ const CATSGDVector& GetTranslation() const;

        /*inline*/ CATSGTransformMatrix44& SetPosition(const CATSGDPoint& iPosition);
        /*inline*/ CATSGTransformMatrix44& SetTranslation(const CATSGDVector& iTranslation);
        //inline CATSGTransformMatrix44& SetRotation(const vkQuat& iRotation);
        /*inline*/ CATSGTransformMatrix44& SetScale(const CATSGDVec3& iScale);
        /*inline*/ CATSGTransformMatrix44& SetScale(double iScale);
        CATSGTransformMatrix44& SetDirection(const CATSGDVector& iDirection, const CATSGDVector& iUp = CATSGDVector::kAxisY);

        // Computes
        /*inline*/ void ComputeScale(CATSGDVec3& oScale) const;
        /*inline*/ void ComputeScale(double& oScale) const;

        /*inline*/ void ComputeAxis(CATSGDVector& oRightVector, CATSGDVector& oUpVector, CATSGDVector& oDirVector) const;
        /*inline*/ void ComputeUnitAxis(CATSGDVector& oRightVector, CATSGDVector& oUpVector, CATSGDVector& oDirVector) const;

        /*inline*/ void ComputeDir(CATSGDVector& oDirVector) const;
        /*inline*/ void ComputeUp(CATSGDVector& oUpVector) const;
        /*inline*/ void ComputeRight(CATSGDVector& oRightVector) const;

        /*inline*/ void ComputeUnitDir(CATSGDVector& oDirVector) const;
        /*inline*/ void ComputeUnitUp(CATSGDVector& oUpVector) const;
        /*inline*/ void ComputeUnitRight(CATSGDVector& oRightVector) const;

        void ComputeTranspose(CATSGTransformMatrix44& oDst) const;

        /**
        Compute the inverse transposition of the matrix.

        @param oDst the result inverse transposition of the matrix.
        @remarks oDst can be the calling matrix itself.
        @see ComputeTranspose
        */
        void ComputeInverseTranspose(CATSGTransformMatrix44& oDst) const;

        // Transforms primitive
        void Multiply(CATSGDPoint& oDst, const CATSGDPoint& iSrc) const;
        void InverseTransformMultiply(CATSGDPoint& oDst, const CATSGDPoint& iSrc) const;
        void Multiply(CATSGDVector& oDst, const CATSGDVector& iSrc) const;
        void InverseTransformMultiply(CATSGDVector& oDst, const CATSGDVector& iSrc) const;
        void Multiply(CATSGDVec4& oDst, const CATSGDVec4& iSrc) const;

        /**
        Identity matrix.

        The identity matrix looks like this one and has the property to not
        modify anything it is multiplied by.
        As its transpose and its invert are also identities matrices.
        [ 1 0 0 0 ]
        [ 0 1 0 0 ]
        [ 0 0 1 0 ]
        [ 0 0 0 1 ]

        */
        static CATSGTransformMatrix44 kIdentity;

        bool HasRotation() const;
        bool HasTranslation() const;
        bool IsIdentity() const;

    protected:

        // const access operators
        const CATSGDVec4& operator[] (uint32 i) const
        {
            return (const CATSGDVec4&)(*(CATSGDVec4*)(data + i));
        }

        CATSGDVec4& operator[] (uint32 i)
        {
            return (CATSGDVec4&)(*(CATSGDVec4*)(data + i));
        }

        /**
        Compute the determinant of the matrix.
        */
        double Determinant33() const {
            return (data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) +
                data[0][1] * (data[1][2] * data[2][0] - data[1][0] * data[2][2]) +
                data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]));
        }

        // the matrix data
        double data[4][4];
    };

    typedef std::vector<CATSGTransformMatrix44> CATSGTransforms;
} // end of namespace

#endif // SG_COMPOSITES_MULTIOS
#endif //CATSGTransformMatrix44_H
