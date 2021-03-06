//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisCombine.hh"

//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//

#if NEED_UNDERSCORE
#define combine_wrap_create             combine_wrap_create_
#define combine_wrap_delete             combine_wrap_delete_
#define combine_wrap_update             combine_wrap_update_
#define combine_wrap_wrapup             combine_wrap_wrapup_
#define combine_wrap_oneset             combine_wrap_oneset_
#define combine_wrap_twosets            combine_wrap_twosets_
#elif NEED_CAPITALS
#define combine_wrap_create             COMBINE_WRAP_CREATE
#define combine_wrap_delete             COMBINE_WRAP_DELETE
#define combine_wrap_update             COMBINE_WRAP_UPDATE
#define combine_wrap_wrapup             COMBINE_WRAP_WRAPUP
#define combine_wrap_oneset             COMBINE_WRAP_ONESET
#define combine_wrap_twosets            COMBINE_WRAP_TWOSETS
#endif

//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//

extern "C"
    {
    CpseisBase::ModuleCreate   combine_wrap_create;
    CpseisBase::ModuleDestroy  combine_wrap_delete;
    CpseisBase::ModuleUpdate   combine_wrap_update;
    CpseisBase::ModuleWrapup   combine_wrap_wrapup;
    CpseisBase::ModuleOneset   combine_wrap_oneset;
    CpseisBase::ModuleTwosets  combine_wrap_twosets;
    }

//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//

CpseisCombine::CpseisCombine() : CpseisBase ("COMBINE",
                                       combine_wrap_create,
                                       combine_wrap_delete,
                                       combine_wrap_update,
                                       combine_wrap_wrapup,
                                       combine_wrap_oneset,
                                       combine_wrap_twosets) {}

//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
