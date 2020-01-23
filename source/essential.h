#pragma once

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>

//-----------------------------------------------------------------


#define NEW_MACRO(thisClass)										\
  thisClass* thisClass::New() { STANDARD_NEW_BODY(thisClass); }

#define STANDARD_NEW_BODY(thisClass)							\
  thisClass* result = new thisClass;							\
  return result


//-----------------------------------------------------------------


#define SET_MACRO(name,type) \
virtual void Set##name (type _arg) \
{ \
    if (this->name != _arg) \
    { \
        this->name = _arg; \
    } \
}


//-----------------------------------------------------------------


#define GetMacro(name,type) \
virtual type Get##name () \
{ \
    return this->name; \
}


//-----------------------------------------------------------------


#define FREE_OBJ_MACRO(name) \
if(name!=nullptr){  \
    delete name; \
    name = nullptr; \
}


//-----------------------------------------------------------------


#define FREE_ARR_MACRO_1P(name) \
if(name!=nullptr){ \
    delete[] name; \
    name = nullptr; \
}


//-----------------------------------------------------------------


template<typename T>
void ClearVector(std::vector<T>& V)
{
	for (std::vector<T>::iterator it = V.begin(); it != V.end(); it++)
	{
		FREE_OBJ_MACRO(*it)
	}
	V.clear();
}
