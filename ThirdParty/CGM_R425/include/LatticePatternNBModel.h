//===================================================================
// COPYRIGHT Dassault Systemes 2017/03/14
//===================================================================

#ifndef LatticePatternNBModel_H
#define LatticePatternNBModel_H

#include "ExportedByLatticeModel.h"

#include "LatticeNBModel.h"
#include "LatticeNBModelConstVisitor.h"

class CATIPolyMesh;



/**
*	@brief Pattern lattice model
*   @details Define a set of patterns positions to build the lattice model
*   The model can be edited as a LatticeNBModel as well
*/
class ExportedByLatticeModel LatticePatternNBModel : public LatticeNBModel
{
public:

    LatticePatternNBModel();

    virtual ~LatticePatternNBModel();

    /**
    * @brief Create a pattern to the xyz position
    * @details Before positioning a pattern, it must be defined by GetPattern
    *
    * @code
    * LatticePatternNBModel l;
    * LatticeNBModel& pattern = l.GetPattern();
    * pattern.AddNode( ... );
    * pattern.AddNode( ... );
    * pattern.AddBeam( ... );
    *
    * l.AddPattern()
    *
    * @endcode
    *
    * @param x
    * @param y
    * @param z
    *
    */
    void AddPattern(double x, double y, double z);

    /**
    * @brief Access internal pattern to fill it
    *
    *
    */
    inline LatticeNBModel& GetPattern()
    {
        return m_Pattern;
    }
    inline const LatticeNBModel& GetPattern() const
    {
        return m_Pattern;
    }

public:
    virtual HRESULT Accept (LatticeNBModelConstVisitor& iV) const;

private:

    LatticePatternNBModel(LatticePatternNBModel &) = delete;

    LatticePatternNBModel& operator=(LatticePatternNBModel&) = delete;

    LatticeNBModel m_Pattern;
};


#endif
