#include "ECSkSolverOptions.h"
#include <cassert>


ECSkSolverOptions::ECSkSolverOptions()
:   m_dLinearTolerance(0.0001), 
    m_dAngularTolerance(1e-9),
    m_bRereadHelpParameters(true),
    m_bForceUsingSketch(false),
    m_bCheckUnsolvableConstraintsMode(false),
    m_bIncrementalMode(false),
    m_eDiagnosticsMode(DiagnosticsMode_OldAlways),
    m_eRigidSetDiagnosticsMode(RigidSetDiagnosticsMode_WithoutDOS),
    m_eOverdefinedDiagnosticsMode(OverdefinedDiagnosticsMode_Dimensional),
    m_eVariableDependencyMode(VariableDependencyMode_Never),
    m_eChiralityMode(ChiralityMode_Keep),
    m_ePartialSolvingMode(PartialSolvingMode_Always),
    m_eUpdateMode(UpdateMode_Evaluate),
    m_eSolvingMode(SolvingMode_Standard), 
    m_eContactsDiagnosticsMode(ContactsDiagnosticsMode_ClashDetected),
    m_eUpdateOutOfClashMode(UpdateOutOfClashMode_None)
{

}

void ECSkSolverOptions::setDiagnosticsMode(std::string valIn) 
{
    if(valIn == "NotSolved")
        m_eDiagnosticsMode = DiagnosticsMode_NotSolved;
    else if(valIn == "Always")
        m_eDiagnosticsMode = DiagnosticsMode_Always;
    else if(valIn == "NotOverdefined")
        m_eDiagnosticsMode = DiagnosticsMode_NotOverdefined;
    else if(valIn == "Never")
        m_eDiagnosticsMode = DiagnosticsMode_Never;
    else if(valIn == "Heal")
        m_eDiagnosticsMode = DiagnosticsMode_Heal;
    else if(valIn == "OldAlways")
        m_eDiagnosticsMode = DiagnosticsMode_OldAlways;
    else
        assert(0);
}

void ECSkSolverOptions::setRigidSetDiagnosticsMode(std::string valIn) 
{
    if(valIn == "WithoutDOS")
        m_eRigidSetDiagnosticsMode = RigidSetDiagnosticsMode_WithoutDOS;
    else if(valIn == "Full")
        m_eRigidSetDiagnosticsMode = RigidSetDiagnosticsMode_Full;
    else if(valIn == "ExtraDOF")
        m_eRigidSetDiagnosticsMode = RigidSetDiagnosticsMode_ExtraDOF;
    else
        assert(0);
}

void ECSkSolverOptions::setOverdefinedDiagnosticsMode(std::string valIn) 
{
    if(valIn == "Dimensional")
        m_eOverdefinedDiagnosticsMode = OverdefinedDiagnosticsMode_Dimensional;
    else if(valIn == "Full")
        m_eOverdefinedDiagnosticsMode = OverdefinedDiagnosticsMode_Full;
    else
        assert(0);
}

void ECSkSolverOptions::setVariableDependencyMode(std::string valIn) 
{
    if(valIn == "Never")
        m_eVariableDependencyMode = VariableDependencyMode_Never;
    else if(valIn == "Solved")
        m_eVariableDependencyMode = VariableDependencyMode_Solved;
    else
        assert(0);
}

void ECSkSolverOptions::setChiralityMode(std::string valIn) 
{
    if(valIn == "Free")
        m_eChiralityMode = ChiralityMode_Free;
    else if(valIn == "Keep")
        m_eChiralityMode = ChiralityMode_Keep;
    else
        assert(0);
}

void ECSkSolverOptions::setPartialSolvingMode(std::string valIn) 
{
    if(valIn == "Always")
        m_ePartialSolvingMode = PartialSolvingMode_Always;
    else if(valIn == "FailIfInconsistent")
        m_ePartialSolvingMode = PartialSolvingMode_FailIfInconsistent;
    else
        assert(0);
}


void ECSkSolverOptions::setUpdateMode(std::string valIn) 
{
    if(valIn == "Evaluate")
        m_eUpdateMode = UpdateMode_Evaluate;
    else if(valIn == "Reevaluate")
        m_eUpdateMode = UpdateMode_Reevaluate;
    else if(valIn == "EvalTransform")
        m_eUpdateMode = UpdateMode_EvalTransform;
    else
        assert(0);
}

void ECSkSolverOptions::setSolvingMode(std::string valIn) 
{
    if(valIn == "Standard")
        m_eSolvingMode = SolvingMode_Standard;
    else if(valIn == "MinimumMove")
        m_eSolvingMode = SolvingMode_MinimumMove;
    else
        assert(0);
}

void ECSkSolverOptions::setContactsDiagnosticsMode(std::string valIn) 
{
    if(valIn == "ClashDetected")
        m_eContactsDiagnosticsMode = ContactsDiagnosticsMode_ClashDetected;
    else if(valIn == "Always")
        m_eContactsDiagnosticsMode = ContactsDiagnosticsMode_Always;
    else if(valIn == "Never")
        m_eContactsDiagnosticsMode = ContactsDiagnosticsMode_Never;
    else
        assert(0);
}

void ECSkSolverOptions::setUpdateOutOfClashMode(std::string valIn) 
{
    if(valIn == "None")
        m_eUpdateOutOfClashMode = UpdateOutOfClashMode_None;
    else if(valIn == "Basic")
        m_eUpdateOutOfClashMode = UpdateOutOfClashMode_Basic;
    else
        assert(0);
}



std::string ECSkSolverOptions::getDiagnosticsModeString() 
{
    std::string valIn;
    if(m_eDiagnosticsMode == DiagnosticsMode_NotSolved)
        valIn = "NotSolved";
    else if(m_eDiagnosticsMode == DiagnosticsMode_Always)
        valIn = "Always";
    else if(m_eDiagnosticsMode == DiagnosticsMode_NotOverdefined)
        valIn = "NotOverdefined";
    else if(m_eDiagnosticsMode == DiagnosticsMode_Never)
        valIn = "Never";
    else if(m_eDiagnosticsMode == DiagnosticsMode_Heal)
        valIn = "Heal";
    else if(m_eDiagnosticsMode == DiagnosticsMode_OldAlways)
        valIn = "OldAlways";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getRigidSetDiagnosticsModeString() 
{
    std::string valIn;
    if(m_eRigidSetDiagnosticsMode == RigidSetDiagnosticsMode_WithoutDOS)
        valIn = "WithoutDOS";
    else if(m_eRigidSetDiagnosticsMode == RigidSetDiagnosticsMode_Full)
        valIn = "Full";
    else if(m_eRigidSetDiagnosticsMode == RigidSetDiagnosticsMode_ExtraDOF)
        valIn = "ExtraDOF";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getOverdefinedDiagnosticsModeString() 
{
    std::string valIn;
    if(m_eOverdefinedDiagnosticsMode == OverdefinedDiagnosticsMode_Dimensional)
        valIn = "Dimensional";
    else if(m_eOverdefinedDiagnosticsMode == OverdefinedDiagnosticsMode_Full)
        valIn = "Full";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getVariableDependencyModeString() 
{
    std::string valIn;
    if(m_eVariableDependencyMode == VariableDependencyMode_Never)
        valIn = "Never";
    else if(m_eVariableDependencyMode == VariableDependencyMode_Solved)
        valIn = "Solved";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getChiralityModeString() 
{
    std::string valIn;
    if(m_eChiralityMode == ChiralityMode_Free)
        valIn = "Free";
    else if(m_eChiralityMode == ChiralityMode_Keep)
        valIn = "Keep";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getPartialSolvingModeString() 
{
    std::string valIn;
    if(m_ePartialSolvingMode == PartialSolvingMode_Always)
        valIn = "Always";
    else if(m_ePartialSolvingMode == PartialSolvingMode_FailIfInconsistent)
        valIn = "FailIfInconsistent";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getUpdateModeString() 
{
    std::string valIn;
    if(m_eUpdateMode == UpdateMode_Evaluate)
        valIn = "Evaluate";
    else if(m_eUpdateMode == UpdateMode_Reevaluate)
        valIn = "Reevaluate";
    else if(m_eUpdateMode == UpdateMode_EvalTransform)
        valIn = "EvalTransform";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getSolvingModeString() 
{
    std::string valIn;
    if(m_eSolvingMode == SolvingMode_Standard)
        valIn = "Standard";
    else if(m_eSolvingMode == SolvingMode_MinimumMove)
        valIn = "MinimumMove";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getContactsDiagnosticsModeString() 
{
    std::string valIn;
    if(m_eContactsDiagnosticsMode == ContactsDiagnosticsMode_ClashDetected)
        valIn = "ClashDetected";
    else if(m_eContactsDiagnosticsMode == ContactsDiagnosticsMode_Always)
        valIn = "Always";
    else if(m_eContactsDiagnosticsMode == ContactsDiagnosticsMode_Never)
        valIn = "Never";
    else
        assert(0);

    return valIn;
}

std::string ECSkSolverOptions::getUpdateOutOfClashModeString() 
{
    std::string valIn;
    if(m_eUpdateOutOfClashMode == UpdateOutOfClashMode_None)
        valIn = "None";
    else if(m_eUpdateOutOfClashMode == UpdateOutOfClashMode_Basic)
        valIn = "Basic";
    else
        assert(0);

    return valIn;
}


