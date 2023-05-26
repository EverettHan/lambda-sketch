#if !defined(__CATSGGenVec2_h)
#define __CATSGGenVec2_h

#include "CATMath.h"
#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"

namespace CATSG
{
	/** 
	DISCLAIMER !! This is vkGenVec2 from VIAMPFoundation !! I know I will be burn to death for this but 
	as we need only a few things from VIAMPFoundation a small duplication seems a good trade off
	to avoid higher complexity in dependency hell. Besides that prerequisite might not be authorized for me all the time
	and it would be absurd to rewrite.... 
	*/

	/**
	Class defining a templatized 2D vector. 
	this class is specialized for int32 (vkIVec2) and for 
	real (vkVec2)

	@see vkIVec2, vkVec2
	*/
	template<typename T>
	class CATSGGenVec2 /*: public vkHeapObject, do not inherit anymore because GCC modifies the size of objects */
	{
	public:
		enum EAxis {
			eX,
			eY,
			eAxisCount
		};

		/**
		Constructors.

		@param  
		iX, iY : Default value of components.
		iF : value that will be shuffled on all components.
		iV : Array of 2 values.
		*/
		inline CATSGGenVec2() 
		{}

		inline CATSGGenVec2(const T iX,const T iY):x(iX), y(iY)
		{}

		inline CATSGGenVec2(const T iF):x(iF), y(iF)
		{}

		inline CATSGGenVec2(const T* iV):x(*iV++),y((*iV))
		{}
		
		template<typename U>
		inline CATSGGenVec2(const CATSGGenVec2<U>& iS):x((T)iS.x), y((T)iS.y)
		{}


		// Accessors

		/**
		Sets the vector value.

		@param  
		iX, iY: Value of components.
		*/
		inline void Set(const T iX,const T iY)
		{
			x = iX;
			y = iY;
		}

		inline void Set( const T iXY )
		{
			x = iXY;
			y = iXY;
		}

		inline void Set(const T* iV)
		{
			x = iV[0];
			y = iV[1];
		}

		/**
		Sets the vector coordinates to 0. After call, IsNull returns true.
		*/
		inline void SetToZero()
		{
			x = y = 0;
		}

		/**
		Check whether the vector coordinates are null.
		*/
		inline bool IsNull() const {
			return CATSGApproxEqual(x,T(0)) && CATSGApproxEqual(y,T(0));
		}


		/**
		Equal Comparison Operator.

		This is a strict comparison. For a thresholded
		comparison, please use Equal method.

		See Also: Equal
		*/
		inline bool operator== (const CATSGGenVec2& iV) const
		{
			return ( x==iV.x && y==iV.y );
		}

		/**
		Not Equal Comparison Operator.

		This is a strict comparison. For a thresholded
		comparison, please use Equal method.
		Two vectors are supposed to be different if at least one 
		of their component is different.
		See Also: Equal
		*/
		inline bool operator!= (const CATSGGenVec2& iV) const
		{
			return ( x!=iV.x || y!=iV.y );
		}

		/**
		Inferior or Equal Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator<= (const CATSGGenVec2& iV) const
		{
			return ( x<=iV.x && y<=iV.y );
		}

		/**
		Inferior Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator< (const CATSGGenVec2& iV) const
		{
			return ( x<iV.x && y<iV.y );
		}

		/**
		Superior or Equal Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator>= (const CATSGGenVec2& iV) const
		{
			return ( x>= iV.x && y >= iV.y );
		}

		/**
		Superior Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator> (const CATSGGenVec2& iV) const
		{
			return ( x>iV.x && y>iV.y );
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

		/**
		Returns the magnitude (length) of a vector.

		This method returns the magnitude (length) of the 
		vector.

		@return Magnitude of the vector
	
		See also: SquareMagnitude, real, GetMaxComponent
		*/
		inline real Magnitude() const 
		{
			return CATSGSqrt(((real)x*(real)x+(real)y*(real)y));
		}

		/**
		Returns the square magnitude(length) of a vector.

		This method returns the square magnitude (length*length) 
		of the vector.

		@return Square magnitude of the vector.

		See also: Magnitude,GetMaxComponent
		*/
		inline real SquareMagnitude() const 
		{
			return (real)x*(real)x+(real)y*(real)y;
		}

		/**
		Returns the longest component of a vector.

		This method returns the longest component res = max(abs(x),abs(y))
		of the vector.

		@return Absolute value of the longest component of the vector.

		See also: Magnitude,SquareMagnitude
		*/
		inline T GetMaxComponent() const 
		{
			return CATSGMax(CATSGAbs(x), CATSGAbs(y));
		}


		/**
		Normalize vector (length=1).

		This method returns a vector equal to Vect normalized to length iLength.

		@warning Calling this function with a null vector (0,0,0) will
		return an indefinite vector (constant NaN - not a number).

		@return The calling vector.

		See also: Magnitude
		*/
		inline CATSGGenVec2& Normalize(real iLength = (real)1)
		{
			real len = SquareMagnitude();
			CATAssert(len != 0 ); // "Division by Zero"
			if (!CATSGApproxEqual(len,(real)iLength*iLength)) {
				real invLength = iLength * CATSGInvSqrt(len);
				x = (T)(x*invLength);
				y = (T)(y*invLength);			
			}
			return *this;
		}


		// {partOf: Normalize }
		inline CATSGGenVec2 Unit() const
		{
			real len = SquareMagnitude();
			CATAssert(len != 0); // "Division by Zero"
			if (CATSGApproxEqual(len,(real)1.0))
				return *this;

			real invLen = CATSGInvSqrt(len);
			return CATSGGenVec2((T)(x*invLen), (T)(y*invLen));
		}

		// arithmetic operations

		/**
		Vectors addition operator.
		*/
		template<typename U>
		inline CATSGGenVec2 operator+ (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec2((T)(x+iV.x),(T)(y+iV.y));
		}

		/**
		Vectors subtraction operator.
		*/
		template<typename U>
		inline CATSGGenVec2 operator- (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec2((T)(x-iV.x),(T)(y-iV.y));
		}

		/**
		Vectors multiplication operator.
		*/
		template<typename U>
		inline CATSGGenVec2 operator* (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec2((T)(x*iV.x),(T)(y*iV.y));
		}

		/**
		Vectors scalar multiplication operator.
		*/
		inline CATSGGenVec2 operator* (const T iS) const
		{
			return CATSGGenVec2(x*iS,y*iS);
		}

		/**
		Vectors division operator.
		*/
		template<typename U>
		inline CATSGGenVec2 operator/ (const CATSGGenVec2<U>& iV) const
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0)); // "Division by Zero"
			return CATSGGenVec2((T)(x/iV.x), (T)(y/iV.y));
		}

		/**
		Vectors scalar division operator.
		*/
		inline CATSGGenVec2 operator/ (const T iS) const
		{
			CATAssert(iS != 0); // "Division by Zero"			
			return CATSGGenVec2(x/iS, y/iS);
		}

		/**
		Unary minus operator.
		*/
		inline CATSGGenVec2 operator- () const
		{
			return CATSGGenVec2(-x,-y);
		}

		/**
		Vectors addition and substitution operator.
		*/
		template<typename U>
		inline CATSGGenVec2<T>& operator+= (const CATSGGenVec2<U>& iV)
		{
			x = (T)(x+iV.x);
			y = (T)(y+iV.y);
			return *this;
		}

		/**
		Vectors subtraction and substitution operator.
		*/
		template<typename U>
		inline CATSGGenVec2& operator-= (const CATSGGenVec2<U>& iV)
		{
			x = (T)(x-iV.x);
			y = (T)(y-iV.y);
			return *this;
		}

		/**
		Vectors multiplication and substitution operator.
		*/
		template<typename U>
		inline CATSGGenVec2& operator*= (const CATSGGenVec2<U>& iV)
		{

			x = (T)(x*iV.x);
			y = (T)(y*iV.y);
			return *this;
		}

		/**
		Vectors scalar multiplication and substitution operator.
		*/
		inline CATSGGenVec2& operator*= (const T iS)
		{
			x = (T)(x*iS);
			y = (T)(y*iS);
			return *this;
		}

		/**
		Vectors division and substitution operator.
		*/
		template<typename U>
		inline CATSGGenVec2& operator/= (const CATSGGenVec2<U>& iV)
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0)); // "Division by Zero"
			x = (T)(x/iV.x);
			y = (T)(y/iV.y);
			return *this;
		}

		/**
		Vectors scalar division and substitution operator.
		*/
		inline CATSGGenVec2& operator/= (const T iS)
		{
			CATAssert(iS != 0 ); // "Division by Zero"
			real invS = (real)(1.0) / (real)iS;
			x = (T)(x*invS);
			y = (T)(y*invS);
			return *this;
		}

		/**
		Returns the dot product of two vectors.

		This method returns the square magnitude (length*length) 
		of the vector.

		@param 
		iV:  a const reference on a vector.

		@return A real result of the dot product of (this . iV).

		{Group:Vectors}
		See also: Normalize
		*/
		template<typename U>
		inline real Dot(const CATSGGenVec2<U>& iV) const
		{
			return (real)x*(real)iV.x+(real)y*(real)iV.y;
		}

		/**
		Computes the determinant of this vector.
		Notice that det(v, w) is 0 if v and w are colinear.
		@param iV the other vector
		@return the determinant
		*/
		template<typename U>
		inline real Det(const CATSGGenVec2<U>& iV) const
		{
			return (real)x*(real)iV.y-(real)y*(real)iV.x;
		}

		/**
		Compare two vectors for equality using a threshold value
		from CATSGNumericLimits.
		*/
		template<typename U>
		inline bool Equal(const CATSGGenVec2<U>& iV) const
		{
			return CATSGApproxEqual<T>(x,(T)iV.x)
				&& CATSGApproxEqual<T>(y,(T)iV.y);
		}


		/**
		Compare two vectors for equality given a threshold value.
		*/
		template<typename U>
		inline void Order(CATSGGenVec2<U>& ioSecond) {
			if (x > (T)ioSecond.x) CATSGSwap(x, (T&)ioSecond.x);
			if (y > (T)ioSecond.y) CATSGSwap(y, (T&)ioSecond.y);
		}


		///
		// Members

		T x;  ///< x coordinate
		T y;  ///< y coordinate

		static const CATSGGenVec2 kAxis0; 
		static const CATSGGenVec2 kAxis1;
		static const CATSGGenVec2 kAxisX;
		static const CATSGGenVec2 kAxisY;

	};

	/**
	Floating (real) type version of a 2D vector.
	@see vkIVec2
	*/
	typedef CATSGGenVec2<real> CATSGVec2;

	/**
	Integral (int32) type version of a 2D vector.
	@see vkIVec2
	*/
	typedef CATSGGenVec2<int32> CATSGDiscreteVec2;

	///
	// External Ops

	template<typename T>
	inline CATSGGenVec2<T> operator* (const T iS, const CATSGGenVec2<T>& iV)
	{
		return iV*iS;  
	}

	template<typename T>
	inline CATSGGenVec2<T> operator/ (const T iS, const CATSGGenVec2<T>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(T)0) && !CATSGApproxEqual(iV.y,(T)0)); // "Division by Zero"
		return CATSGGenVec2<T>((T)(iS/iV.x), (T)(iS/iV.y));
	}
}
#endif // SG_COMPOSITES_MULTIOS
#endif // __CATSGGenVec2_h

