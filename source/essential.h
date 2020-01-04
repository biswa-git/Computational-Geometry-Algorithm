#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include<stdexcept>
#include <typeinfo>
//using namespace std;

#define NewMacro(thisClass)										\
  thisClass* thisClass::New() { STANDARD_NEW_BODY(thisClass); }

#define STANDARD_NEW_BODY(thisClass)							\
  thisClass* result = new thisClass;							\
  return result

#define SetMacro(name,type) \
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


#define FreeObjMacro(name) \
if(name!=nullptr){  \
    delete name; \
    name = nullptr; \
}


//-----------------------------------------------------------------


#define FreeArrMacro1p(name) \
if(name!=nullptr){ \
    delete[] name; \
    name = nullptr; \
}


//-----------------------------------------------------------------


#define ErrorMacro(x) \
cout<<"ERROR: "  <<x<<endl<<"       in file: "  <<__FILE__<<endl<<"       at line no: "  <<__LINE__<<endl<<"       in function: "  <<__func__<<endl \
<<endl<<endl<<"                             EXITING..."<<endl;



//-----------------------------------------------------------------


#define WarningMacro(x) \
cout<<"WARNING: "<<x<<endl<<"         in file: "<<__FILE__<<endl<<"         at line no: "<<__LINE__<<endl<<"         in function: "<<__func__<<endl;


//-----------------------------------------------------------------


#define MessageMacro(x) \
cout<<x<<endl;


//-----------------------------------------------------------------