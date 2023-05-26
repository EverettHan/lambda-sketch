/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CAT2DBagRepWithAdvancedTables for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CAT2DBagRepWithAdvancedTables_H
#define CAT2DBagRepWithAdvancedTables_H

#include "SGInfra.h"
#include "CAT2DLinkableBagRep.h"

class CATCustomLineTypeTable;
class CATCustomLineWeightTable;
class CATAdvancedLayerTable;

class ExportedBySGInfra CAT2DBagRepWithAdvancedTables : public CAT2DLinkableBagRep
{
	CATDeclareClass;

public:

	// creation of a CAT2DBagRepWithAdvancedTables 
	static CAT2DBagRepWithAdvancedTables* CreateRep();

	virtual ~CAT2DBagRepWithAdvancedTables();

	/** Sets the AdvancedLayerTable.
	* @param iAdvancedLayerTable
	* The AdvancedLayerTable lifecycle is managed by caller.
	*/
	inline void SetAdvancedLayerTable(const CATAdvancedLayerTable* iAdvancedLayerTable) {_advancedLayerTable = iAdvancedLayerTable;}

	/** Retrieves the AdvancedLayerTable.<br>
	*/
	inline const CATAdvancedLayerTable* GetAdvancedLayerTable() const {return _advancedLayerTable;}

	/** Sets the CustomLineTypeTable.
	* @param iCustomLineTypeTable
	* The CustomLineTypeTable lifecycle is managed by caller.
	*/
	inline void SetCustomLineTypeTable(const CATCustomLineTypeTable* iCustomLineTypeTable) {_customLineTypeTable = iCustomLineTypeTable;}

	/** Retrieves the CustomLineTypeTable.<br>
	*/
	inline const CATCustomLineTypeTable* GetCustomLineTypeTable() const {return _customLineTypeTable;}

	/** Sets the CustomLineWeightTable.
	* @param iCustomLineWeightTable
	* The CustomLineWeightTable lifecycle is managed by caller.
	*/
	inline void SetCustomLineWeightTable(const CATCustomLineWeightTable* iCustomLineWeightTable) {_customLineWeightTable = iCustomLineWeightTable;}

	/** Retrieves the CustomLineWeightTable.<br>
	*/
	inline const CATCustomLineWeightTable* GetCustomLineWeightTable() const {return _customLineWeightTable;}

	// AZX: (A2X migration) This rep is not derived thus making draw functions final 
	virtual void DrawShading(CATRender& ioRender, int iInside) override final;
	virtual void DrawPath(CATRender& ioRender, int iInside, CATRepPath& ioPath) override final;
	virtual void Draw(CATRender& iRender, int iInside) override final;
	virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

protected:
	CAT2DBagRepWithAdvancedTables();

private:

	const CATCustomLineTypeTable* _customLineTypeTable;
	const CATCustomLineWeightTable* _customLineWeightTable;
	const CATAdvancedLayerTable* _advancedLayerTable;

};

#endif


