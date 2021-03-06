//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisMgd.hh"

//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//

#if NEED_UNDERSCORE
#define mgd_wrap_create             mgd_wrap_create_
#define mgd_wrap_delete             mgd_wrap_delete_
#define mgd_wrap_update             mgd_wrap_update_
#define mgd_wrap_wrapup             mgd_wrap_wrapup_
#define mgd_wrap_oneset             mgd_wrap_oneset_
#define mgd_wrap_twosets            mgd_wrap_twosets_
#elif NEED_CAPITALS
#define mgd_wrap_create             MGD_WRAP_CREATE
#define mgd_wrap_delete             MGD_WRAP_DELETE
#define mgd_wrap_update             MGD_WRAP_UPDATE
#define mgd_wrap_wrapup             MGD_WRAP_WRAPUP
#define mgd_wrap_oneset             MGD_WRAP_ONESET
#define mgd_wrap_twosets            MGD_WRAP_TWOSETS
#endif

//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//

extern "C"
    {
    CpseisBase::ModuleCreate   mgd_wrap_create;
    CpseisBase::ModuleDestroy  mgd_wrap_delete;
    CpseisBase::ModuleUpdate   mgd_wrap_update;
    CpseisBase::ModuleWrapup   mgd_wrap_wrapup;
    CpseisBase::ModuleOneset   mgd_wrap_oneset;
    CpseisBase::ModuleTwosets  mgd_wrap_twosets;
    }

//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//

CpseisMgd::CpseisMgd() : CpseisBase ("MGD",
                                       mgd_wrap_create,
                                       mgd_wrap_delete,
                                       mgd_wrap_update,
                                       mgd_wrap_wrapup,
                                       mgd_wrap_oneset,
                                       mgd_wrap_twosets) {}

//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
