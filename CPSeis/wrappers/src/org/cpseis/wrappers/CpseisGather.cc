//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisGather.hh"

//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//

#if NEED_UNDERSCORE
#define gather_wrap_create             gather_wrap_create_
#define gather_wrap_delete             gather_wrap_delete_
#define gather_wrap_update             gather_wrap_update_
#define gather_wrap_wrapup             gather_wrap_wrapup_
#define gather_wrap_oneset             gather_wrap_oneset_
#define gather_wrap_twosets            gather_wrap_twosets_
#elif NEED_CAPITALS
#define gather_wrap_create             GATHER_WRAP_CREATE
#define gather_wrap_delete             GATHER_WRAP_DELETE
#define gather_wrap_update             GATHER_WRAP_UPDATE
#define gather_wrap_wrapup             GATHER_WRAP_WRAPUP
#define gather_wrap_oneset             GATHER_WRAP_ONESET
#define gather_wrap_twosets            GATHER_WRAP_TWOSETS
#endif

//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//

extern "C"
    {
    CpseisBase::ModuleCreate   gather_wrap_create;
    CpseisBase::ModuleDestroy  gather_wrap_delete;
    CpseisBase::ModuleUpdate   gather_wrap_update;
    CpseisBase::ModuleWrapup   gather_wrap_wrapup;
    CpseisBase::ModuleOneset   gather_wrap_oneset;
    CpseisBase::ModuleTwosets  gather_wrap_twosets;
    }

//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//

CpseisGather::CpseisGather() : CpseisBase ("GATHER",
                                       gather_wrap_create,
                                       gather_wrap_delete,
                                       gather_wrap_update,
                                       gather_wrap_wrapup,
                                       gather_wrap_oneset,
                                       gather_wrap_twosets) {}

//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
