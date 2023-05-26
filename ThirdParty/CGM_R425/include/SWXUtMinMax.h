#pragma once

template<class T> const T& SWXUtMin(const T& iFirst, const T& iSecond)
{	
	return iFirst > iSecond ? iSecond : iFirst;
}

template<class T> const T& SWXUtMax(const T& iFirst, const T& iSecond)
{	
	return iFirst < iSecond ? iSecond : iFirst;
}

template<class T> const T& SWXUtMinMax(const T& iMin, const T& iVal, const T& iMax)
{	
	if (iVal < iMin)
		return iMin;
	else if (iVal > iMax)
		return iMax;
	else
		return iVal;
}
