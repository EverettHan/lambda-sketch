#ifndef __LatticeFrameFields_h
#define __LatticeFrameFields_h

#include "ExportedByLatticePolyOperators.h"

#include "CATMathVector.h"
#include "CATMathBox.h"
class CATMathStream;
namespace lattice
{
    namespace poly
    {
		class ExportedByLatticePolyOperators LatticeFrameFields
		{
		public:
			LatticeFrameFields(const int iDimX, const int iDimY, const int iDimZ, const CATMathBox &iBBox) :
			  _dimX(iDimX), _dimY(iDimY), _dimZ(iDimZ), _bBox(iBBox),
			  _densityField(nullptr), _orthogonalBasisField(nullptr)
			{

			}

			~LatticeFrameFields() {
				DisposeBuffers();
			}

		private:
			HRESULT InitBuffers();
			void 	DisposeBuffers();

		public:
			HRESULT Reset();

			inline const int 		GetDimX() const {
				return _dimX;
			}

			inline const int 		GetDimY() const {
				return _dimY;
			}

			inline const int 		GetDimZ() const {
				return _dimZ;
			}

			inline CATMathBox		GetBBox() const {
			  return _bBox;
			}

			inline const double 	GetDensity(const int i, const int j, const int k) const {
				return _densityField[i * (_dimY*_dimZ) + j * (_dimZ) + k];
			}

			inline HRESULT 			SetDensity(const int i, const int j, const int k, const double iDensity) {
				HRESULT hr = S_OK;
				if(_densityField==nullptr)
					hr = Reset();
				if(FAILED(hr))
					return hr;
				_densityField[i * (_dimY*_dimZ) + j * (_dimZ) + k] = iDensity;
				return hr;
			}

			inline const double*	GetOrthogonalBasis(const int i, const int j, const int k) const {
				return &_orthogonalBasisField[(i * (_dimY*_dimZ) + j * (_dimZ) + k) * 9];
			}

			inline HRESULT 			SetOrthogonalBasis(const int i, const int j, const int k, const CATMathVector* iOrthogonalBasis) {
				HRESULT hr = S_OK;
				if(_orthogonalBasisField==nullptr)
					hr = Reset();
				if(FAILED(hr))
					return hr;
				const int matIndex = (i * (_dimY*_dimZ) + j * (_dimZ) + k) * 9;
				for(int vecIndex=0; vecIndex<3 ; ++vecIndex) {
					_orthogonalBasisField[matIndex+(3*vecIndex)+0] =  iOrthogonalBasis[vecIndex].GetX();
					_orthogonalBasisField[matIndex+(3*vecIndex)+1] =  iOrthogonalBasis[vecIndex].GetY();
					_orthogonalBasisField[matIndex+(3*vecIndex)+2] =  iOrthogonalBasis[vecIndex].GetZ();
				}
				return hr;
			}

    public:

    static HRESULT Stream(CATMathStream & ioStream, const LatticeFrameFields & iFrameFields);
    static HRESULT Unstream(CATMathStream & iStream, LatticeFrameFields *& oFrameFields);

		private:
			const int _dimX;
			const int _dimY;
			const int _dimZ;

			const CATMathBox _bBox;

			// These are indexed in the following way for i, j, k index is:
			// i * (_dimY*_dimZ) + j * (_dimZ) + k
			// and size of buffer is _dimX * _dimY * _dimZ * sizeof(double)
			double* _densityField;

			// These are indexed in the following way for i, j, k index is:
			// (i * (_dimY*_dimZ) + j * (_dimZ) + k) * 9
			// and size of buffer is _dimX * _dimY * _dimZ * 9 * sizeof(double)
			double* _orthogonalBasisField;
		};
	}
}
#endif // __LatticeFrameFields_h
