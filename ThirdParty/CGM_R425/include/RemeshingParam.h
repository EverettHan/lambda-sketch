#ifndef RemeshingParam_H
#define RemeshingParam_H

enum RemeshingMode
{
	SAG,
	General
};

class RemeshingParam
{
public:
	RemeshingParam() :
		_mode(SAG), _depth(2),
		_ignoreEdgeBarres(FALSE),
		_ignoreIsoBarres(FALSE) {};

	const RemeshingMode GetRemeshingMode() { return _mode; }
	const unsigned int GetRemeshingDepth() { return _depth; }
	const CATBoolean IgnoreIsoBarres() { return _ignoreIsoBarres; }
	const CATBoolean IgnoreEdgeBarres() { return _ignoreEdgeBarres; }

	void SetRemeshingMode(const RemeshingMode iMode) { _mode = iMode; }
	void SetRemeshingDepth(const unsigned int iDepth = 2) { _depth = iDepth; }
	void SetIgnoreIsoBarres(const CATBoolean iIgnore = FALSE) { _ignoreIsoBarres = iIgnore; }
	void SetIgnoreEdgeBarres(const CATBoolean iIgnore = FALSE) { _ignoreEdgeBarres = iIgnore; }

private:
	RemeshingMode _mode;
	unsigned int _depth;
	CATBoolean _ignoreIsoBarres;
	CATBoolean _ignoreEdgeBarres;
};

#endif
