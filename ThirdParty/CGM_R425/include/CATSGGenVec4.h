#ifndef CATSGGenVec4_H
#define CATSGGenVec4_H

#include "CATSGUtil.h"

#ifndef _WINDOWS_SOURCE
#include "SGComposites.h"
#endif

#ifdef SG_COMPOSITES_MULTIOS

#include "CATSGGenVec3.h"

namespace CATSG
{
	/** 
	DISCLAIMER !! This is vkGenVec4 from VIAMPFoundation !! 
    We need only a few things from VIAMPFoundation, so a small duplication seems a good trade off
	to avoid higher complexity in dependency hell. Besides that prerequisite might not be authorized for me all the time
	and it would be absurd to rewrite.... 
	*/

	template<typename T>
#ifndef _WINDOWS_SOURCE	
	class ExportedBySGComposites CATSGGenVec4 {
#else
	class CATSGGenVec4 {
#endif 
	public:
		enum {
			eX,
			eY,
			eZ,
			eW,
			eAxisCount
		};

		/**
		Constructors.

		@param  
		iX, iY : Default value of components.
		iF : value that will be shuffled on all components.
		iV : Array of 3 values.

		*/
		inline CATSGGenVec4() 
		{}

		inline CATSGGenVec4(const T iX,const T iY,const T iZ,const T iW):x(iX), y(iY),z(iZ),w(iW)
		{}

		inline CATSGGenVec4(const T iF):x(iF), y(iF), z(iF), w(iF)
		{}

		inline CATSGGenVec4(const T* iV):x(*iV++),y((*iV++)),z((*iV++)),w((*iV))
		{}

		template<typename U>
		inline CATSGGenVec4(const CATSGGenVec4<U>& iS):x((T)iS.x), y((T)iS.y), z((T)iS.z),w((T)iS.w)
		{}

		template<typename U>
		inline CATSGGenVec4(const CATSGGenVec3<U>& iV3):x((T)iV3.x),y((T)iV3.y),z((T)iV3.z),w(0)
		{}

		template<typename U>
		inline CATSGGenVec4(const CATSGGenVec2<U>& iV2):x((T)iV2.x),y((T)iV2.y),z(0),w(0)
		{}


		// Accessors

		/**
		Sets the vector value.

		@param  
		iX, iY, iZ: Value of components.
		*/
		inline void Set(const T iX,const T iY,const T iZ,const T iW)
		{
			x = iX;
			y = iY;
			z = iZ;
			w = iW;
		}

		inline void Set(const T iXYZW)
		{
			x = iXYZW;
			y = iXYZW;
			z = iXYZW;
			w = iXYZW;
		}

		inline void Set(const T* iV)
		{
			memcpy(&x, iV, sizeof(CATSGGenVec4<T>));
		}

		inline void SetToZero()
		{
			x = y = z = w = 0;
		}

		inline bool IsNull() const{
			return CATSGApproxEqual(x, (float)0.0f) && CATSGApproxEqual(y, (float)0.0f) && 
				CATSGApproxEqual(z,(float)0.0f) && CATSGApproxEqual(w, (float)0.0f);
		}


		/**
		Assignement Operator from CATSGVec3.

		The w coordinate is left unchanged.
		*/
		template<typename U>
		inline CATSGGenVec4& operator= (const CATSGGenVec3<U>& iV)
		{
			x=(T)iV.x;
			y=(T)iV.y;  
			z=(T)iV.z;  
			return *this;
		}


		/**
		Equal Comparison Operator.

		This is a strict comparison. For a thresholded
		comparison, please use Equal method.

		See Also: Equal
		*/
		inline bool operator== (const CATSGGenVec4& iV) const
		{
			return ( x==(T)iV.x && y==(T)iV.y && z==(T)iV.z && w==(T)iV.w );
		}

		/**
		Not Equal Comparison Operator.

		This is a strict comparison. For a thresholded
		comparison, please use Equal method.
		Two vectors are supposed to be different if at least one 
		of their component is different.
		See Also: Equal
		*/
		inline bool operator!= (const CATSGGenVec4& iV) const
		{
			return ( x!=(T)iV.x || y!=(T)iV.y || z!=(T)iV.z || w!=(T)iV.w );
		}

		/**
		Inferior Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator< (const CATSGGenVec4& iV) const
		{
			return ( x<(T)iV.x && y<(T)iV.y && z<(T)iV.z && w<(T)iV.w );
		}


		/**
		Superior or Equal Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator>= (const CATSGGenVec4& iV) const
		{
			return ( x>= (T)iV.x && y >= (T)iV.y && z >= (T)iV.z && w >= (T)iV.w );
		}

		/**
		Superior Comparison Operator.

		This is a strict comparison. 

		See Also: Equal
		*/
		inline bool operator> (const CATSGGenVec4& iV) const
		{
			return ( x>(T)iV.x && y>(T)iV.y && z>(T)iV.z && w>(T)iV.w);
		}

		/**
		Accessors.

		@param  
		i : Index of the component to access.

		*/
		inline const T& operator[] (const uint32 i) const
		{
			CATAssert(i<eAxisCount);
			return *(&x + i);
		}

		inline T& operator[] (const uint32 i) 
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


		inline operator const CATSGGenVec3<T>& () const
		{
			return *(CATSGGenVec3<T>*)(&x);
		}

		inline operator CATSGGenVec3<T>& ()
		{
			return *(CATSGGenVec3<T>*)(&x);
		}

		/**
		Returns the magnitude (length) of a vector.

		This method returns the magnitude (length) of the 
		vector.

		@return Magnitude of the vector

		See also: SquareMagnitude, float
		*/
		inline float Magnitude() const 
		{
			return CATSGSqrt((float)x*(float)x
				+(float)y*(float)y
				+(float)z*(float)z
				+(float)w*(float)w
				);
		}

		/**
		Returns the square magnitude(length) of a vector.

		This method returns the square magnitude (length*length) 
		of the vector.

		@return Square magnitude of the vector

		See also: Magnitude
		*/
		inline float SquareMagnitude() const 
		{
			return (float)x*(float)x
				+(float)y*(float)y
				+(float)z*(float)z
				+(float)w*(float)w;
		}

		/**
		Returns the longest component of a vector.

		This method returns the longest component res = max(abs(x),abs(y),abs(z),abs(w))
		of the vector.

		@return Absolute value of the longest component of the vector

		See also: Magnitude,SquareMagnitude
		*/
		inline T GetMaxComponent() const 
		{
			return CATSGMax(CATSGMax(CATSGAbs(x), CATSGAbs(y), CATSGAbs(z)), CATSGAbs(w));
		}

		/**
		Normalize vector (length=1).

		This method returns a vector equal to Vect normalized to length iLength.
		WARNING: Calling this function with a null vector (0,0,0) will
		return an indefinite vector (constant NaN - not a number)

		@return The calling vector.

		See also: Magnitude
		*/
		inline CATSGGenVec4& Normalize(float iLength = (float)1)
		{
			float len = SquareMagnitude();
			CATAssert(len != 0 ); // "Division by Zero"
			if (!CATSGApproxEqual(len,(float)iLength*iLength)) {
				float invLength = iLength * CATSGInvSqrt(len);
				x = (T)(x*invLength);
				y = (T)(y*invLength);
				z = (T)(z*invLength);
				w = (T)(w*invLength);
			}
			return *this;
		}

		// {partOf: Normalize }
		inline CATSGGenVec4 Unit() const
		{
			float len = SquareMagnitude();
			CATAssert(len != 0); // "Division by Zero"
			if (CATSGApproxEqual(len,(float)1.0))
				return *this;

			float invLen = CATSGInvSqrt(len);
			return CATSGGenVec4((T)(x*invLen),(T)(y*invLen),(T)(z*invLen),(T)(w*invLen));
		}

		// {partOf: Normalize }
		inline bool IsUnit() const
		{
			return CATSGApproxEqual(Magnitude(), 1.f);
		}

		// arithmetic operations
		template<typename U>
		inline CATSGGenVec4 operator+ (const CATSGGenVec4<U>& iV) const
		{
			return CATSGGenVec4((T)(x+iV.x),(T)(y+iV.y),(T)(z+iV.z),(T)(w+iV.w));
		}

		template<typename U>
		inline CATSGGenVec4 operator+ (const CATSGGenVec3<U>& iV) const
		{
			return CATSGGenVec4((T)(x+iV.x),(T)(y+iV.y),(T)(z+iV.z),w);
		}


		template<typename U>
		inline CATSGGenVec4 operator+ (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec4((T)(x+iV.x),(T)(y+iV.y),z,w);
		}


		template<typename U>
		inline CATSGGenVec4 operator- (const CATSGGenVec4<U>& iV) const
		{
			return CATSGGenVec4((T)(x-iV.x),(T)(y-iV.y),(T)(z-iV.z),(T)(w-iV.w));
		}

		template<typename U>
		inline CATSGGenVec4 operator- (const CATSGGenVec3<U>& iV) const
		{
			return CATSGGenVec4((T)(x-iV.x),(T)(y-iV.y),(T)(z-iV.z),w);
		}

		template<typename U>
		inline CATSGGenVec4 operator- (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec4((T)(x-iV.x),(T)(y-iV.y),z,w);
		}


		template<typename U>
		inline CATSGGenVec4 operator* (const CATSGGenVec4<U>& iV) const
		{
			return CATSGGenVec4((T)(x*iV.x),(T)(y*iV.y),(T)(z*iV.z),(T)(w*iV.w));
		}

		template<typename U>
		inline CATSGGenVec4 operator* (const CATSGGenVec3<U>& iV) const
		{
			return CATSGGenVec4((T)(x*iV.x),(T)(y*iV.y),(T)(z*iV.z),0);
		}

		template<typename U>
		inline CATSGGenVec4 operator* (const CATSGGenVec2<U>& iV) const
		{
			return CATSGGenVec4((T)(x*iV.x),(T)(y*iV.y),0,0);
		}


		template<typename U>
		inline CATSGGenVec4 operator/ (const CATSGGenVec4<U>& iV) const
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0) && !CATSGApproxEqual(iV.w,(U)0) ); // "Division by Zero"
			return CATSGGenVec4((T)(x/iV.x),(T)(y/iV.y),(T)(z/iV.z),(T)(w/iV.w));
		}

		template<typename U>
		inline CATSGGenVec4 operator/ (const CATSGGenVec3<U>& iV) const
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0)); // "Division by Zero"
			return CATSGGenVec4((T)(x/iV.x),(T)(y/iV.y),(T)(z/iV.z),w);
		}

		template<typename U>
		inline CATSGGenVec4 operator/ (const CATSGGenVec2<U>& iV) const
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0)); // "Division by Zero"
			return CATSGGenVec4((T)(x/iV.x),(T)(y/iV.y),z,w);
		}

		inline CATSGGenVec4 operator* (const T iS) const
		{
			return CATSGGenVec4((T)(x*iS),(T)(y*iS),(T)(z*iS),(T)(w*iS));
		}


		inline CATSGGenVec4 operator/ (const T iS) const
		{
			CATAssert(iS != 0); // "Division by Zero"
			float inv = (float)((float)1.0/iS);
			return CATSGGenVec4(
				(T)((float)x*inv),
				(T)((float)y*inv),
				(T)((float)z*inv),
				(T)((float)w*inv));
		}

	
		inline CATSGGenVec4 operator- () const
		{
			return CATSGGenVec4(-x,-y,-z,-w);
		}

		template<typename U>
		inline CATSGGenVec4& operator+= (const CATSGGenVec4<U>& iV)
		{
			x = (T)(x+iV.x);
			y = (T)(y+iV.y);
			z = (T)(z+iV.z);
			w = (T)(w+iV.w);
			return *this;
		}

		template<typename U>
		inline CATSGGenVec4& operator+= (const CATSGGenVec3<U>& iV)
		{
			x = (T)(x+iV.x);
			y = (T)(y+iV.y);
			z = (T)(z+iV.z);
			return *this;
		}

		template<typename U>
		inline CATSGGenVec4& operator+= (const CATSGGenVec2<U>& iV)
		{
			x = (T)(x+iV.x);
			y = (T)(y+iV.y);
			return *this;
		}

		template<typename U>
		inline CATSGGenVec4& operator-= (const CATSGGenVec4<U>& iV)
		{
			x = (T)(x-iV.x);
			y = (T)(y-iV.y);
			z = (T)(z-iV.z);
			w = (T)(w-iV.w);
			return *this;
		}

		template<typename U>
		inline CATSGGenVec4& operator-= (const CATSGGenVec3<U>& iV)
		{
			x = (T)(x-iV.x);
			y = (T)(y-iV.y);
			z = (T)(z-iV.z);
			return *this;
		}
		
		template<typename U>
		inline CATSGGenVec4& operator-= (const CATSGGenVec2<U>& iV)
		{
			x = (T)(x-iV.x);
			y = (T)(y-iV.y);
			return *this;
		}

		template<typename U>
		inline CATSGGenVec4& operator*= (const CATSGGenVec4<U>& iV)
		{
			x = (T)(x*iV.x);
			y = (T)(y*iV.y);
			z = (T)(z*iV.z);
			w = (T)(w*iV.w);
			return *this;
		}

		template<typename U>
		inline CATSGGenVec4& operator/= (const CATSGGenVec4<U>& iV)
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0) && !CATSGApproxEqual(iV.w,(U)0) ); // "Division by Zero"
			x = (T)(x/iV.x);
			y = (T)(y/iV.y);
			z = (T)(z/iV.z);
			w = (T)(w/iV.w);
			return *this;
		}

		template<typename U>
		inline CATSGGenVec4& operator/= (const CATSGGenVec3<U>& iV)
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0)); // "Division by Zero"
			x = (T)(x/iV.x);
			y = (T)(y/iV.y);
			z = (T)(z/iV.z);			
			return *this;
		}

		template<typename U>
		inline CATSGGenVec4& operator/= (const CATSGGenVec2<U>& iV)
		{
			CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0)); // "Division by Zero"
			x = (T)(x/iV.x);
			y = (T)(y/iV.y);
			return *this;
		}

//
		inline CATSGGenVec4& operator*= (const T iS)
		{
			x = (T)(x*iS);
			y = (T)(y*iS);
			z = (T)(z*iS);
			w = (T)(w*iS);
			return *this;
		}

		inline CATSGGenVec4& operator/= (const T iS)
		{
			CATAssert(iS != 0 ); // "Division by Zero"
			float invS = (float)(1.0) / (float)iS;
			return operator *= (invS);
		}

		/**
		Returns the dot product of two vectors.

		This method returns the square magnitude (length*length) 
		of the vector.

		@param 
		iV:  a const reference on a vector.

		@return A float result of the dot product of (this . iV).

		See also: Normalize
		*/
		template<typename U>
		inline float Dot(const CATSGGenVec4<U>& iV) const
		{
			return (float)x*(float)iV.x
				+(float)y*(float)iV.y
				+(float)z*(float)iV.z
				+(float)w*(float)iV.w
				;
		}

		/**
		Compare two vectors for equality given a threshold value.
		*/
		template<typename U>
		inline bool Equal(const CATSGGenVec4<U>& iV) const
		{
			return CATSGApproxEqual(x,(T)iV.x) 
				&& CATSGApproxEqual(y,(T)iV.y) 
				&& CATSGApproxEqual(z,(T)iV.z)
				&& CATSGApproxEqual(w,(T)iV.w);
		}

		////////////////////////////////////////////////////////////////////////////////
		// Static members

		static CATSGGenVec4 kAxis0; 
		static CATSGGenVec4 kAxis1;
		static CATSGGenVec4 kAxisX;
		static CATSGGenVec4 kAxisY;
		static CATSGGenVec4 kAxisZ;
		static CATSGGenVec4 kAxisW;
	
		////////////////////////////////////////////////////////////////////////////////
		// Members

		T x;
		T y;
		T z;
		T w;
	};

	///
	// External Ops


	// + 

	template<typename T,typename U>
	inline CATSGGenVec4<T> operator+ (const CATSGGenVec2<T>& iS, const CATSGGenVec4<U>& iV)
	{
		return CATSGGenVec4<T>((T)(iS.x+iV.x),(T)(iS.y+iV.y),(T)iV.z,(T)iV.w);  
	}

	template<typename T,typename U>
	inline CATSGGenVec4<T> operator+ (const CATSGGenVec3<T>& iS, const CATSGGenVec4<U>& iV)
	{
		return CATSGGenVec4<T>((T)(iS.x+iV.x),(T)(iS.y+iV.y),(T)(iS.z+iV.z),(T)iV.w);  
	}

	template<typename T,typename U>
	inline CATSGGenVec2<T>& operator+= (CATSGGenVec2<T>& iS,const CATSGGenVec4<U>& iV)
	{
		iS.x=(T)(iS.x+iV.x);
		iS.y=(T)(iS.y+iV.y);  
		return iS;
	}

	template<typename T,typename U>
	inline CATSGGenVec3<T>& operator+= (CATSGGenVec3<T>& iS,const CATSGGenVec4<U>& iV)
	{
		iS.x=(T)(iS.x+iV.x);
		iS.y=(T)(iS.y+iV.y);  
		iS.z=(T)(iS.z+iV.z);  
		return iS;
	}


	// -
	template<typename T,typename U>
	inline CATSGGenVec4<T> operator- (const CATSGGenVec2<T>& iS, const CATSGGenVec4<U>& iV)
	{
		return CATSGGenVec4<T>((T)(iS.x-iV.x),(T)(iS.y-iV.y),(T)-iV.z,(T)-iV.w);  
	}

	template<typename T,typename U>
	inline CATSGGenVec4<T> operator- (const CATSGGenVec3<T>& iS, const CATSGGenVec4<U>& iV)
	{
		return CATSGGenVec4<T>((T)(iS.x-iV.x),(T)(iS.y-iV.y),(T)(iS.z-iV.z),(T)-iV.w);  
	}

	template<typename T,typename U>
	inline CATSGGenVec2<T>& operator-= (CATSGGenVec2<T>& iS,const CATSGGenVec4<U>& iV)
	{
		iS.x=(T)(iS.x-iV.x);
		iS.y=(T)(iS.y-iV.y);  
		return iS;
	}

	template<typename T,typename U>
	inline CATSGGenVec3<T>& operator-= (CATSGGenVec3<T>& iS,const CATSGGenVec4<U>& iV)
	{
		iS.x=(T)(iS.x-iV.x);
		iS.y=(T)(iS.y-iV.y);  
		iS.z=(T)(iS.z-iV.z);  
		return iS;
	}

	// *
	template<typename T>
	inline CATSGGenVec4<T> operator* (const T iS, const CATSGGenVec4<T>& iV)
	{
		return iV*iS;  
	}
	template<typename T,typename U>
	inline CATSGGenVec4<T> operator* (const CATSGGenVec2<T>& iS, const CATSGGenVec4<U>& iV)
	{
		return CATSGGenVec4<T>((T)(iS.x*iV.x),(T)(iS.y*iV.y),0,0);  
	}

	template<typename T,typename U>
	inline CATSGGenVec4<T> operator* (const CATSGGenVec3<T>& iS, const CATSGGenVec4<U>& iV)
	{
		return CATSGGenVec4<T>((T)(iS.x*iV.x),(T)(iS.y*iV.y),(T)(iS.z*iV.z),0);  
	}

	template<typename T,typename U>
	inline CATSGGenVec2<T>& operator*= (CATSGGenVec2<T>& iS,const CATSGGenVec4<U>& iV)
	{
		iS.x=(T)(iS.x*iV.x);
		iS.y=(T)(iS.y*iV.y);  
		return iS;
	}

	template<typename T,typename U>
	inline CATSGGenVec3<T>& operator*= (CATSGGenVec3<T>& iS,const CATSGGenVec4<U>& iV)
	{
		iS.x=(T)(iS.x*iV.x);
		iS.y=(T)(iS.y*iV.y);  
		iS.z=(T)(iS.z*iV.z);  
		return iS;
	}

	template<typename T,typename U>
	inline CATSGGenVec4<T>& operator*= (CATSGGenVec4<T>& iS,const CATSGGenVec3<U>& iV)
	{
		iS.x=(T)(iS.x*iV.x);
		iS.y=(T)(iS.y*iV.y);  
		iS.z=(T)(iS.z*iV.z);  
		return iS;
	}

	template<typename T,typename U>
	inline CATSGGenVec4<T>& operator*= (CATSGGenVec4<T>& iS,const CATSGGenVec2<U>& iV)
	{
		iS.x=(T)(iS.x*iV.x);
		iS.y=(T)(iS.y*iV.y);  
		iS.z = iS.w = 0;
		return iS;
	}


	// /
	template<typename T>
	inline CATSGGenVec4<T> operator/ (const T iS, const CATSGGenVec4<T>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(T)0) && !CATSGApproxEqual(iV.y,(T)0) && !CATSGApproxEqual(iV.z,(T)0) && !CATSGApproxEqual(iV.w,(T)0) ); // "Division by Zero"
		return CATSGGenVec4<T>((T)(iS/iV.x), (T)(iS/iV.y),(T)(iS/iV.z),(T)(iS/iV.w));
	}

	template<typename T,typename U>
	inline CATSGGenVec4<T> operator/ (const CATSGGenVec2<T>& iS, const CATSGGenVec4<U>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0)); // "Division by Zero"
		return CATSGGenVec4<T>((T)(iS.x/iV.x),(T)(iS.y/iV.y),0,0);  
	}

	template<typename T,typename U>
	inline CATSGGenVec4<T> operator/ (const CATSGGenVec3<T>& iS, const CATSGGenVec4<U>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0)); // "Division by Zero"
		return CATSGGenVec4<T>((T)(iS.x/iV.x),(T)(iS.y/iV.y),(T)(iS.z/iV.z),0);  
	}

	template<typename T,typename U>
	inline CATSGGenVec2<T>& operator/= (CATSGGenVec2<T>& iS,const CATSGGenVec4<U>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0)); // "Division by Zero"
		iS.x=(T)(iS.x/iV.x);
		iS.y=(T)(iS.y/iV.y);  
		return iS;
	}  

	template<typename T,typename U>
	inline CATSGGenVec3<T>& operator/= (CATSGGenVec3<T>& iS,const CATSGGenVec4<U>& iV)
	{
		CATAssert(!CATSGApproxEqual(iV.x,(U)0) && !CATSGApproxEqual(iV.y,(U)0) && !CATSGApproxEqual(iV.z,(U)0)); // "Division by Zero"
		iS.x=(T)(iS.x/iV.x);
		iS.y=(T)(iS.y/iV.y);  
		iS.z=(T)(iS.z/iV.z);  
		return iS;
	}

    typedef CATSGGenVec4<float> CATSGVec4;
	typedef CATSGGenVec4<int32> CATSGDiscreteVec4;
	typedef CATSGGenVec4<double> CATSGDVec4;
}

#endif // SG_COMPOSITES_MULTIOS

#endif // CATSGGenVec4_H
