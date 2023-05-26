#if !defined(__CATSGGenVec3_h)
#define __CATSGGenVec3_h

#include "CATMath.h"
#include "CATSGGenVec2.h"
#include "CATSGComposite.h"

#ifdef SG_COMPOSITES_MULTIOS

namespace CATSG
{
	/** 
	DISCLAIMER !! This is vkGenVec3 from VIAMPFoundation !! I know I will be burn to death for this but 
	as we need only a few things from VIAMPFoundation a small duplication seems a good trade off
	to avoid higher complexity in dependency hell. Besides that prerequisite might not be authorized for me all the time
	and it would be absurd to rewrite.... 
	*/

	/**
	Class defining a templatized 3D vector. 
	this class is specialized for int32 (vkIVec3) and for 
	real (vkVec3)

	@see vkIVec3, vkVec3
	*/
	template<typename T>
	class CATSGGenVec3 /*: public vkHeapObject, do not inherit anymore because GCC modifies the size of objects */
	{
	public:
		enum EAxis {
			eX,
			eY,
			eZ,
			eAxisCount
		};

		/**
		Constructors.

		@param  
		iX, iY : Default value of components.
		iF : value that will be shuffled on all components.
		iV : Array of 3 values.

		*/
		inline CATSGGenVec3() 
		{}

		inline CATSGGenVec3(const T iX,const T iY,const T iZ):x(iX), y(iY),z(iZ)
		{}

		inline explicit CATSGGenVec3(const T iF):x(iF), y(iF), z(iF)
		{}

		inline explicit CATSGGenVec3(const T* iV):x(*iV++),y((*iV++)),z((*iV))
		{}

		template<typename U>
		inline CATSGGenVec3(const CATSGGenVec3<U>& iS):x((T)iS.x), y((T)iS.y), z((T)iS.z)
		{}

		template<typename U>
		inline CATSGGenVec3(const CATSGGenVec2<U>& iV2):x((T)iV2.x),y((T)iV2.y),z(0)
		{}

		// Accessors

		/**
		Sets the vector value.

		@param  
		iX, iY, iZ: Value of components.
		*/
		inline void Set(const T iX,const T iY,const T iZ)
		{
			x = iX;
			y = iY;
			z = iZ;
		}

		/**
		Sets the vector value.

		@param  
		iXYZ: Value of components.
		*/
		inline void Set( const T iXYZ )
		{
			x = iXYZ;
			y = iXYZ;
			z = iXYZ;
		}

		inline void Set(const T* iV)
		{
			memcpy(&x, iV, sizeof(CATSGGenVec3<T>));
		}

		/**
		Sets the vector coordinates to 0. After call, IsNull returns true.
		*/
		inline void SetToZero()
		{
			x = y = z = 0;
		}

		/**
		Check whether the vector coordinates are NaN (Not A Number).
		*/
		inline bool IsNAN() const
		{
			return CATSGIsNAN(x) || CATSGIsNAN(y) || CATSGIsNAN(z);
		}

		/**
		Check whether the vector coordinates are null.
		*/
		inline bool IsNull() const
		{
			return CATSGApproxEqual(x, (T)0) && 
				CATSGApproxEqual(y, (T)0) && 
				CATSGApproxEqual(z, (T)0);
		}

		inline bool AreComponentsEqual() const
		{
			return ((x == y) && (y == z));
		}

		inline bool AreComponentsEqual(T iEpsilon) const
		{
			return	(CATSGApproxEqual(x, y, iEpsilon) && 
					CATSGApproxEqual(y, z, iEpsilon));
		}

		/**
		Equal Comparison Operator.

		This is a strict comparison. For a thresholded
		comparison, please use Equal method.

		See Also: Equal
		*/
		inline bool operator== (const CATSGGenVec3& iV) const
		{
			return ( x==(T)iV.x && y==(T)iV.y && z==(T)iV.z );
		}


		/**
		Not Equal Comparison Operator.

		This is a strict comparison. For a thresholded
		comparison, please use Equal method.
		Two vectors are supposed to be different if at least one 
		of their component is different.
		See Also: Equal
		*/
		inline bool operator!= (const CATSGGenVec3& iV) const
		{
			return ( x!=(T)iV.x || y!=(T)iV.y || z!=(T)iV.z);
		}


		/**
		Inferior or Equal Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator<= (const CATSGGenVec3& iV) const
		{
			return ( x<=(T)iV.x && y<=(T)iV.y && z<=(T)iV.z);
		}


		/**
		Inferior Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator< (const CATSGGenVec3& iV) const
		{
			return ( x<(T)iV.x && y<(T)iV.y && z<(T)iV.z );
		}

		/**
		Superior or Equal Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator>= (const CATSGGenVec3& iV) const
		{
			return ( x>= (T)iV.x && y >= (T)iV.y && z >= (T)iV.z );
		}

		/**
		Superior Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator> (const CATSGGenVec3& iV) const
		{
			return ( x>(T)iV.x && y>(T)iV.y && z>(T)iV.z );
		}

		/**
		Accessors.

		@param  
		i : Index of the component to access.

		*/
		inline const T& operator[] (const int i) const
		{
			CATAssert(i<eAxisCount);
			return *(&x + i);
		}

		inline T& operator[] (const int i) 
		{
			CATAssert(i<eAxisCount);
			return *(&x + i);
		}

		inline operator const CATSGGenVec2<T>& () const
		{
			return *(CATSGGenVec2<T>*)(&x);
		}

		inline operator CATSGGenVec2<T>& ()
		{
			return *(CATSGGenVec2<T>*)(&x);
		}


		/**
		Returns the magnitude (length) of a vector.

		This method returns the magnitude (length) of the 
		vector.

		@return Magnitude of the vector

		See also: SquareMagnitude, real
		*/
		inline T Magnitude() const 
		{
			return CATSGSqrt(x*x
				+y*y
				+z*z
				);
		}

		/**
		Returns the square magnitude (length*length) of a vector.

		This method returns the square magnitude (length*length) 
		of the vector.

		@return Square magnitude of the vector

		See also: Magnitude, SquareDistance, Distance
		*/
		inline T SquareMagnitude() const 
		{
			return x*x
				+y*y
				+z*z;
		}

		/**
		Returns the distance (length) between two vectors.
		See also: SquareDistance, Magnitude, SquareMagnitude
		*/
		inline T Distance(const CATSGGenVec3<T>& iVec) const 
		{
			return CATSGSqrt(CATSGSqr(iVec.x - x) + CATSGSqr(iVec.y - y) + CATSGSqr(iVec.z - z));
		}

		/**
		Returns the square distance (length*length) between two vectors.
		See also: Distance, Magnitude, SquareMagnitude
		*/
		inline T SquareDistance(const CATSGGenVec3<T>& iVec) const 
		{
			return CATSGSqr(iVec.x - x) + CATSGSqr(iVec.y - y) + CATSGSqr(iVec.z - z);
		}

		/**
		Returns the longest component of a vector.

		This method returns the longest component res = max(abs(x),abs(y),abs(z))
		of the vector.

		@return Absolute value of the longest component of the vector

		See also: Magnitude,SquareMagnitude
		*/
		inline T GetMaxComponent() const 
		{
			return CATSGMax(CATSGAbs(x), CATSGAbs(y), CATSGAbs(z));
		}

		/**
		Normalize vector (length=1).

		This method returns a vector equal to Vect normalized to length 1.0.
		WARNING: Calling this function with a null vector (0,0,0) will
		return an indefinite vector (constant NaN - not a number)

		@return The calling vector.

		See also: Magnitude
		*/
		inline CATSGGenVec3& Normalize(T iLength)
		{
			T len2 = SquareMagnitude();
			CATAssert(len2 != 0 ); // "Division by Zero"			
			//real invLength = iLength * CATSGInvSqrt(len);
			//x = (T)(x*invLength);
			//y = (T)(y*invLength);
			//z = (T)(z*invLength);
			T length = CATSGSqrt(len2);
			x = iLength*x/length;
			y = iLength*y/length;
			z = iLength*z/length;

			return *this;
		}

		/**
		Normalize vector.

		This method returns a vector equal to Vect normalized to length 1.0.
		WARNING: Calling this function with a null vector (0,0,0) will
		return an indefinite vector (constant NaN - not a number)

		@return The calling vector.

		See also: Magnitude
		*/
		inline CATSGGenVec3& Normalize()
		{
			T len2 = SquareMagnitude();
			CATAssert(len2 != 0 ); // "Division by Zero"			
			//real invLength = CATSGInvSqrt(len);
			//x = (T)(x*invLength);
			//y = (T)(y*invLength);
			//z = (T)(z*invLength);
			T length = CATSGSqrt(len2);
			x = x/length;
			y = y/length;
			z = z/length;

			return *this;
		}

		// {partOf: Normalize }
		inline CATSGGenVec3 Unit() const
		{
			T len = SquareMagnitude();
			CATAssert(len != 0); // "Division by Zero"
			if (CATSGApproxEqual(len,(T)1.0))
				return *this;	

			T invLen = CATSGInvSqrt(len);
			return CATSGGenVec3((T)(x*invLen),(T)(y*invLen),(T)(z*invLen));
		}

		// {partOf: Normalize }
		/**
		Check wether the vector is a unit vector.
		@return  
		true if the vector is a unit vector, false otherwise
		*/
		inline bool IsUnit() const
		{
			return CATSGApproxEqual(SquareMagnitude(), (T)1.0);
			//return Equal<T>(CATSGAbs(SquareMagnitude() - 1.0f),0);
		}


		// arithmetic operations

		/**
		Vectors addition operator.
		@param  
		iV: 3D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3 operator+ (const CATSGGenVec3<U>& iV) const
		{
			return CATSGGenVec3((T)(x+iV.x),(T)(y+iV.y),(T)(z+iV.z));
		}

		/**
		Vectors addition operator.
		@param  
		iV: 2D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3 operator+ (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec3((T)(x+iV.x),(T)(y+iV.y),z);
		}

		/**
		Vectors subtraction operator.
		@param  
		iV: 3D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3 operator- (const CATSGGenVec3<U>& iV) const
		{
			return CATSGGenVec3((T)(x-iV.x),(T)(y-iV.y),(T)(z-iV.z));
		}

		/**
		Vectors subtraction operator.
		@param  
		iV: 2D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3 operator- (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec3((T)(x-iV.x),(T)(y-iV.y),z);
		}

		/**
		Vectors multiplication operator.
		@param  
		iV: 3D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3 operator* (const CATSGGenVec3<U>& iV) const
		{
			return CATSGGenVec3((T)(x*iV.x),(T)(y*iV.y),(T)(z*iV.z));
		}

		/**
		Vectors multiplication operator.
		@param  
		iV: 2D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3 operator* (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec3((T)(x*iV.x),(T)(y*iV.y),0);
		}

		/**
		Vectors scalar multiplication operator.
		@param  
		iS: scalar to multiply with.
		*/
		inline CATSGGenVec3 operator* (const T iS) const
		{
			return CATSGGenVec3((T)(x*iS),(T)(y*iS),(T)(z*iS));
		}

		/**
		Vectors division operator.
		@param  
		iV: 3D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3 operator/ (const CATSGGenVec3<U>& iV) const
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0)); // "Division by Zero"
			return CATSGGenVec3((T)(x/iV.x),(T)(y/iV.y),(T)(z/iV.z));
		}

		/**
		Vectors division operator.
		@param  
		iV: 2D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3 operator/ (const CATSGGenVec2<U>& iV) const
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0)); // "Division by Zero"
			return CATSGGenVec3((T)(x/iV.x),(T)(y/iV.y),z);
		}

		/**
		Vectors scalar division operator.
		@param  
		iS: scalar to divide by.
		*/
		inline CATSGGenVec3 operator/ (const T iS) const
		{
			CATAssert(iS != 0); // "Division by Zero"
			T inv = ((T)1.0/iS);
			return CATSGGenVec3(
				x*inv,
				y*inv,
				z*inv);
		}

		/**
		Unary minus operator.
		*/
		inline CATSGGenVec3 operator- () const
		{
			return CATSGGenVec3(-x,-y,-z);
		}

		/**
		Vectors addition and substitution operator.
		@param  
		iV: 3D Vector to add with.
		*/
		template<typename U>
		inline CATSGGenVec3& operator+= (const CATSGGenVec3<U>& iV)
		{
			x = (T)(x+iV.x);
			y = (T)(y+iV.y);
			z = (T)(z+iV.z);
			return *this;
		}
		
		/**
		Vectors addition and substitution operator.
		@param  
		iV: 2D Vector to substract with.
		*/
		template<typename U>
		inline CATSGGenVec3& operator+= (const CATSGGenVec2<U>& iV)
		{
			x = (T)(x+iV.x);
			y = (T)(y+iV.y);
			return *this;
		}
		
		/**
		Vectors subtraction and substitution operator.
		@param  
		iV: 3D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3& operator-= (const CATSGGenVec3<U>& iV)
		{
			x = (T)(x-iV.x);
			y = (T)(y-iV.y);
			z = (T)(z-iV.z);
			return *this;
		}

		/**
		Vectors subtraction and substitution operator.
		@param  
		iV: 2D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3& operator-= (const CATSGGenVec2<U>& iV)
		{
			x = (T)(x-iV.x);
			y = (T)(y-iV.y);
			return *this;
		}

		/**
		Vectors scalar multiplication and substitution operator.
		@param  
		iV: 3D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3& operator*= (const CATSGGenVec3<U>& iV)
		{
			x = (T)(x*iV.x);
			y = (T)(y*iV.y);
			z = (T)(z*iV.z);
			return *this;
		}

		/**
		Vectors multiplication and substitution operator.
		@param  
		iV: 2D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3& operator*= (const CATSGGenVec2<U>& iV)
		{
			x = (T)(x*iV.x);
			y = (T)(y*iV.y);
			z = 0;
			return *this;
		}

		/**
		Vectors division and substitution operator.
		@param  
		iV: 3D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3& operator/= (const CATSGGenVec3<U>& iV)
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0)); // "Division by Zero"
			x = (T)(x/iV.x);
			y = (T)(y/iV.y);
			z = (T)(z/iV.z);
			return *this;
		}

		/**
		Vectors division and substitution operator.
		@param  
		iV: 2D Vector.
		*/
		template<typename U>
		inline CATSGGenVec3& operator/= (const CATSGGenVec2<U>& iV)
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0)); // "Division by Zero"
			x = (T)(x/iV.x);
			y = (T)(y/iV.y);
			return *this;
		}

		/**
		Vectors scalar multiplication and substitution operator.
		@param  
		iS: scalar to multiply with.
		*/
		inline CATSGGenVec3& operator*= (const T iS)
		{
			x = (T)(x*iS);
			y = (T)(y*iS);
			z = (T)(z*iS);
			return *this;
		}

		/**
		Vectors scalar addition and substitution operator.
		@param  
		iS: scalar to add.
		*/
		inline CATSGGenVec3& operator+= (const T iS)
		{
			x = (T)(x+iS);
			y = (T)(y+iS);
			z = (T)(z+iS);
			return *this;
		}

		/**
		Vectors scalar division and substitution operator.
		*/
		inline CATSGGenVec3& operator/= (const T iS)
		{
			CATAssert(iS != 0 ); // "Division by Zero"
			T invS = 1.0 / iS;
			x = x*invS;
			y = y*invS;
			z = z*invS;
			return *this;
		}

		/**
		Returns the dot product of two vectors.

		This method returns the square magnitude (length*length) 
		of the vector.

		@param 
		iV:  a const reference on a vector.

		@return A real result of the dot product of (this . iV).

		See also: Normalize
		*/
		template<typename U>
		inline U Dot(const CATSGGenVec3<U>& iV) const
		{
			return x*iV.x
				+y*iV.y
				+z*iV.z
				;
		}

		/**
		Calculates the cross product of two vectors.

		The UnitCross version of the fonction normalize
		the result of the cross product.

		@param 
		iV:  a const reference on a vector.

		@return A vector result of the cross product of (this ^ iV).

		See also: VxVector
		*/
		template<typename U>
		inline CATSGGenVec3 Cross (const CATSGGenVec3<U>& iV) const
		{
			return CATSGGenVec3<T>(y*iV.z-z*iV.y,z*iV.x-x*iV.z,x*iV.y-y*iV.x);

		}

		// {PartOf : Cross}
		template<typename U>
		inline CATSGGenVec3 UnitCross (const CATSGGenVec3<U>& iV) const
		{
			return Cross(iV).Unit();
		}

		/**
		Perform a linear interpolation between two vectors.
		*/
		inline CATSGGenVec3& Lerp(T iFactor, const CATSGGenVec3& iV1, const CATSGGenVec3& iV2)
		{
			x = iV1.x + iFactor * (iV2.x - iV1.x);
			y = iV1.y + iFactor * (iV2.y - iV1.y);
			z = iV1.z + iFactor * (iV2.z - iV1.z);
			return *this;
		}

		/**
		Compare two vectors for equality given the threshold value from 
		CATSGNumericLimits.
		*/
		template<typename U>
		inline bool Equal(const CATSGGenVec3<U>& iV ) const
		{
			return CATSGApproxEqual(x,(T)iV.x)
				&& CATSGApproxEqual(y,(T)iV.y)
				&& CATSGApproxEqual(z,(T)iV.z);
		}

		/**
		Clamp a vector size
		*/
		inline T 
		Truncate(T iMaxMagnitude) {

			T length = Magnitude();
			if (length <= iMaxMagnitude) return length;

			Normalize(); 
			*this *= iMaxMagnitude;
			return iMaxMagnitude;
		}   

		/**
		Project current vector onto given one
		*/
		template<typename U>
		inline CATSGGenVec3<U> Project(const CATSGGenVec3<U>& iV) const
		{
			return iV * (*this).Dot(iV);
		} 

		/**
		Calculates the reflected vector given a surface normal.
		*/
		template<typename U>
		inline CATSGGenVec3<U> Reflect(const CATSGGenVec3<U>& iN) const
		{
			return ( (*this) - 2 * iN.Dot(*this) * iN);
		}

		/**
		Generate two additional vectors that represents an orthonormal referential.
		(generate vector are the result of the cross product of the two others) 
		*/
		inline void
		GenerateReferential(CATSGGenVec3& oV1, CATSGGenVec3& oV2) const
		{
			// we must choose one axis arbitrary before computing the other by cross product
			// (at least do not take the least significant axis)
			if (CATSGAbs(x) > CATSGAbs(y)) {
				// Ignore y axis
				float invXZMagnitude = CATSGInvSqrt(x*x + z*z);
				oV1.x = -z * invXZMagnitude;
				oV1.y = 0;
				oV1.z = x  * invXZMagnitude;

				// V2 = this ^ V1
				oV2.x = y * oV1.z;
				oV2.y = z * oV1.x	-	x * oV1.z;
				oV2.z = 0			-	y * oV1.x;
			}
			else
			{
				// Ignore x axis
				float invYZMagnitude = CATSGInvSqrt(y*y + z*z);
				oV1.x = 0;
				oV1.y = z * invYZMagnitude;
				oV1.z = -y * invYZMagnitude;

				// V2 = this ^ V1
				oV2.x = y *  oV1.z  - z * oV1.y;
				oV2.y = 0			- x*oV1.z;
				oV2.z = x *  oV1.y;


			}
		}


		////////////////////////////////////////////////////////////////////////////////
		// Static members

		static CATSGGenVec3 kAxis0; 
		static CATSGGenVec3 kAxis1;
		static CATSGGenVec3 kAxisX;
		static CATSGGenVec3 kAxisY;
		static CATSGGenVec3 kAxisZ;

		////////////////////////////////////////////////////////////////////////////////
		// Members

		T x;	///< x coordinate
		T y;	///< y coordinate
		T z;	///< z coordinate
	};

	///
	// External Ops


	// +
	template<typename T,typename U>
	inline CATSGGenVec3<T> operator+ (const CATSGGenVec2<T>& iS, const CATSGGenVec3<U>& iV)
	{
		return CATSGGenVec3<T>((T)(iS.x+iV.x),(T)(iS.y+iV.y),(T)iV.z);  
	}

	template<typename T,typename U>
	inline CATSGGenVec2<T>& operator+= (CATSGGenVec2<T>& iS,const CATSGGenVec3<U>& iV)
	{
		iS.x=(T)(iS.x+iV.x);
		iS.y=(T)(iS.y+iV.y);  
		return iS;
	}


	// -
	template<typename T,typename U>
	inline CATSGGenVec3<T> operator- (const CATSGGenVec2<T>& iS, const CATSGGenVec3<U>& iV)
	{
		return CATSGGenVec3<T>((T)(iS.x-iV.x),(T)(iS.y-iV.y),(T)-iV.z);  
	}

	template<typename T,typename U>
	inline CATSGGenVec2<T>& operator-= (CATSGGenVec2<T>& iS,const CATSGGenVec3<U>& iV)
	{
		iS.x=(T)(iS.x-iV.x);
		iS.y=(T)(iS.y-iV.y);  
		return iS;
	}


	// *
	template<typename T>
	inline CATSGGenVec3<T> operator* (const T iS, const CATSGGenVec3<T>& iV)
	{
		return iV*iS;  
	}

	template<typename T,typename U>
	inline CATSGGenVec3<T> operator* (const CATSGGenVec2<T>& iS, const CATSGGenVec3<U>& iV)
	{
		return CATSGGenVec3<T>((T)(iS.x*iV.x),(T)(iS.y*iV.y),0);  
	}

	template<typename T,typename U>
	inline CATSGGenVec2<T>& operator*= (CATSGGenVec2<T>& iS,const CATSGGenVec3<U>& iV)
	{
		iS.x=(T)(iS.x*iV.x);
		iS.y=(T)(iS.y*iV.y);  
		return iS;
	}

	// /
	template<typename T>
	inline CATSGGenVec3<T> operator/ (const T iS, const CATSGGenVec3<T>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(T)0) && !CATSGApproxEqual(iV.y,(T)0) && !CATSGApproxEqual(iV.z,(T)0)); // "Division by Zero"
		return CATSGGenVec3<T>((T)(iS/iV.x), (T)(iS/iV.y),(T)(iS/iV.z));
	}

	template<typename T,typename U>
	inline CATSGGenVec3<T> operator/ (const CATSGGenVec2<T>& iS, const CATSGGenVec3<U>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0)); // "Division by Zero"
		return CATSGGenVec3<T>((T)(iS.x/iV.x),(T)(iS.y/iV.y),0);  
	}

	template<typename T,typename U>
	inline CATSGGenVec2<T>& operator/= (CATSGGenVec2<T>& iS,const CATSGGenVec3<U>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0)); // "Division by Zero"
		iS.x=(T)(iS.x/iV.x);
		iS.y=(T)(iS.y/iV.y);  
		return iS;		
	}

	typedef CATSGGenVec3<float> CATSGVec3;
	typedef CATSGGenVec3<int32> CATSGDiscreteVec3;
	typedef CATSGGenVec3<double> CATSGDVec3;

    template <>
    inline bool CATSGApproxEqual<CATSGVec3>(const CATSGVec3& iT0, const CATSGVec3& iT1 )
    {
        return CATSGApproxEqual(iT0.x, iT1.x) 
            && CATSGApproxEqual(iT0.y, iT1.y) 
            && CATSGApproxEqual(iT0.z, iT1.z);
    }	

    template <>
    inline bool CATSGApproxEqual<CATSGDVec3>(const CATSGDVec3& iT0, const CATSGDVec3& iT1 )
    {
        return CATSGApproxEqual(iT0.x, iT1.x) 
            && CATSGApproxEqual(iT0.y, iT1.y) 
            && CATSGApproxEqual(iT0.z, iT1.z);
    }	

	class CATSGPoint : public CATSGVec3
	{
	public:
		inline CATSGPoint() {}
		inline CATSGPoint(const CATSGVec3& iV):CATSGVec3(iV)
		{}
		inline explicit CATSGPoint(real iF):CATSGVec3(iF)
		{}
		inline explicit CATSGPoint(real* iF):CATSGVec3(iF)
		{}
		inline explicit CATSGPoint(real iF1, real iF2, real iF3):CATSGVec3(iF1, iF2, iF3)
		{}
		inline CATSGPoint& operator=(const CATSGVec3& iV)
		{
			x = iV.x;
			y = iV.y;
			z = iV.z;
			return *this;
		}

		static CATSGPoint kAxis0; 
		static CATSGPoint kAxis1;
		static CATSGPoint kAxisX;
		static CATSGPoint kAxisY;
		static CATSGPoint kAxisZ;
	};

	class CATSGDPoint : public CATSGDVec3
	{
	public:
		inline CATSGDPoint() {}
		inline CATSGDPoint(const CATSGDVec3& iV):CATSGDVec3(iV)
		{}
		inline explicit CATSGDPoint(double iF):CATSGDVec3(iF)
		{}
		inline explicit CATSGDPoint(double* iF):CATSGDVec3(iF)
		{}
		inline explicit CATSGDPoint(double iF1, double iF2, double iF3):CATSGDVec3(iF1, iF2, iF3)
		{}
		inline CATSGDPoint& operator=(const CATSGDVec3& iV)
		{
			x = iV.x;
			y = iV.y;
			z = iV.z;
			return *this;
		}
	};

	class CATSGVector : public CATSGVec3
	{
	public:
		inline CATSGVector() {}
		inline CATSGVector(const CATSGVec3& iV):CATSGVec3(iV)
		{}
		inline explicit CATSGVector(real iF):CATSGVec3(iF)
		{}
		inline explicit CATSGVector(real* iF):CATSGVec3(iF)
		{}
		inline explicit CATSGVector(real iF1, real iF2, real iF3):CATSGVec3(iF1, iF2, iF3)
		{}
		inline CATSGVector& operator=(const CATSGVec3& iV)
		{
			x = iV.x;
			y = iV.y;
			z = iV.z;
			return *this;
		}

		static CATSGVector kAxis0; 
		static CATSGVector kAxis1;
		static CATSGVector kAxisX;
		static CATSGVector kAxisY;
		static CATSGVector kAxisZ;
	
	};

	class CATSGDVector : public CATSGDVec3
	{
	public:
		inline CATSGDVector() {}
		inline CATSGDVector(const CATSGDVec3& iV):CATSGDVec3(iV)
		{}
		inline explicit CATSGDVector(double iF):CATSGDVec3(iF)
		{}
		inline explicit CATSGDVector(double* iF):CATSGDVec3(iF)
		{}
		inline explicit CATSGDVector(double iF1, double iF2, double iF3):CATSGDVec3(iF1, iF2, iF3)
		{}
		inline CATSGDVector& operator=(const CATSGDVec3& iV)
		{
			x = iV.x;
			y = iV.y;
			z = iV.z;
			return *this;
		}
	};
}
#endif // SG_COMPOSITES_MULTIOS
#endif // __CATSGGenVec3_h
