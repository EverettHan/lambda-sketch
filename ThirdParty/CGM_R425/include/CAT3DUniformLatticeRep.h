// Copyright Dassault Systemes 2017
#ifndef UniformLatticeRep_H
#define UniformLatticeRep_H

#include "CAT4x4Matrix.h"
#include "CATMathVectorf.h"
#include "CATMathTransformation.h"
#include "CAT3DRep.h"
#include "CATSurfacicRep.h"
#include "CAT3DCustomRep.h"

class LatticeCell
{
public:
	LatticeCell();
	LatticeCell(float i, float j, float k);
	LatticeCell(const LatticeCell& other);
	void operator=(const LatticeCell& other);

	const float* getIndices() const;
	void setIndices(float i, float j, float k);

	static bool less(const LatticeCell& a, const LatticeCell& b);

	const int getDistanceToBorder() const;
	bool isDistanceToBorderUnknown() const;
	void setDistanceToBorder(int d);

	void Stream(CATStreamer& str) const;
	void UnStream(CATStreamer& str);

private:
	float _indices[3];
	int _distanceToBorder;
	friend class CAT3DUniformLatticeRepTestProbe;
};

class LatticeSpaceGrid
{
public:
	LatticeSpaceGrid();
	~LatticeSpaceGrid();
	void setData(CATUINT32 iNumCells, const CATINT32* iCellDataArray);

	unsigned int nCells() const;
	const LatticeCell* getCell(unsigned int) const;

	float* createIndicesArray();

	void Stream(CATStreamer& str) const;
	void UnStream(CATStreamer& str);

private:
	unsigned int _nCells;
	LatticeCell* _cells;

	bool contains(float i, float j, float k) const;
	int find(float i, float j, float k) const;
	void flagBorderCells();
	void computeBorderDistance();
	void clearCells();

	LatticeSpaceGrid(const LatticeSpaceGrid&) = delete;
	void operator=(const LatticeSpaceGrid&) = delete;
	friend class CAT3DUniformLatticeRepTestProbe;
};

class LatticeMotifGeometry
{
public:
	LatticeMotifGeometry();
	~LatticeMotifGeometry();

	void clear();

	void extract(CATSurfacicRep& iRep);
	void extract(CAT3DCustomRep& iRep);

	bool isValid() const;

	unsigned int nVertices() const;
	float* verticesCopy() const; // The caller has to delete[] the returned pointer

	unsigned int nNormals() const;
	float* normalsCopy() const;  // The caller has to delete[] the returned pointer

	unsigned int nIndices() const;
	unsigned int* indicesCopy() const; // The caller has to delete[] the returned pointer

	void Stream(CATStreamer& str) const;
	void UnStream(CATStreamer& str);

private:
	void accumulateFlat(
		const float * vertices, int vertices_array_size,
		const float * normals, int normals_array_size,
		const int   * triangle_indice, int nb_triangles,
		const int   * strip_indices, int nb_triangle_strips, const int   * strip_sizes,
		const int   * fan_indices, int nb_triangle_fans, const int   * fan_sizes);

	float* _vertices;
	unsigned int _verticesArraySize;

	float* _normals;
	unsigned int _normalsArraySize;

	unsigned int* _indices;
	unsigned int _indicesArraySize;

	LatticeMotifGeometry(const LatticeMotifGeometry&) = delete;
	void operator=(const LatticeMotifGeometry&) = delete;
	friend class CAT3DUniformLatticeRepTestProbe;
};

class ExportedBySGInfra CAT3DUniformLatticeRep : public CAT3DRep
{
	CATDeclareClass;
public:
	explicit CAT3DUniformLatticeRep();
	static CAT3DUniformLatticeRep* CreateRep(CATSurfacicRep* iMotif, const CATMathTransformation* iTransfo, CATUINT32 iNumCells, const CATINT32* iCells, bool iAuthorizeInstancing=true);
	static CAT3DUniformLatticeRep* CreateRep(CAT3DCustomRep* iMotif, const CATMathTransformation* iTransfo, CATUINT32 iNumCells, const CATINT32* iCells, bool iAuthorizeInstancing=true);

protected:
	~CAT3DUniformLatticeRep();
public:
	void Destroy() override;

	// AZX: (A2X migration) Making draw functions final 
	void Draw(CATRender & iRender, int iInside) override final;
	void DrawShading(CATRender &ioRender, int iInside) override final;
	void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
	int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

	void Stream(CATStreamer& str);
	void UnStream(CATStreamer& str);

protected:
  virtual const vDrawInformation* GetDrawInformation();

private:
	CAT4x4Matrix _transfo;
	LatticeSpaceGrid _grid;
	LatticeMotifGeometry _geometry;
	CAT3DRep* _motifRepSingle;
	CAT3DRep* _motifRepInstanced;

	static CAT3DUniformLatticeRep* DoCreateRep(CAT3DRep* iMotif, const CATMathTransformation* iTransfo, CATUINT32 iNumCells, const CATINT32* iCells, bool iAuthorizeInstancing);
	void SetGridData(CATUINT32 iNumCells, const CATINT32* iCells);
	CAT3DRep* CreateMotifRep(bool iUseInstancing);
	void SetMotifRep(CAT3DRep* repSingle, CAT3DRep* repInstanced);

	int OkToDraw(const LatticeCell& iCell, bool iEyeMaybeInside);
	void DrawWithoutInstancing(CATRender & ioRender, int iInside);

	CAT3DUniformLatticeRep(const CAT3DUniformLatticeRep&) = delete;
	void operator=(const CAT3DUniformLatticeRep&) = delete;
	friend class CAT3DUniformLatticeRepTestProbe;
};

#endif //UniformLatticeRep_H
