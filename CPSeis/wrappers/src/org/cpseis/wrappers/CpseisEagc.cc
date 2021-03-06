//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisEagc.hh"

//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//

#if NEED_UNDERSCORE
#define eagc_wrap_create             eagc_wrap_create_
#define eagc_wrap_delete             eagc_wrap_delete_
#define eagc_wrap_update             eagc_wrap_update_
#define eagc_wrap_wrapup             eagc_wrap_wrapup_
#define eagc_wrap_oneset             eagc_wrap_oneset_
#define eagc_wrap_twosets            eagc_wrap_twosets_
#elif NEED_CAPITALS
#define eagc_wrap_create             EAGC_WRAP_CREATE
#define eagc_wrap_delete             EAGC_WRAP_DELETE
#define eagc_wrap_update             EAGC_WRAP_UPDATE
#define eagc_wrap_wrapup             EAGC_WRAP_WRAPUP
#define eagc_wrap_oneset             EAGC_WRAP_ONESET
#define eagc_wrap_twosets            EAGC_WRAP_TWOSETS
#endif

//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//

extern "C"
    {
    CpseisBase::ModuleCreate   eagc_wrap_create;
    CpseisBase::ModuleDestroy  eagc_wrap_delete;
    CpseisBase::ModuleUpdate   eagc_wrap_update;
    CpseisBase::ModuleWrapup   eagc_wrap_wrapup;
    CpseisBase::ModuleOneset   eagc_wrap_oneset;
    CpseisBase::ModuleTwosets  eagc_wrap_twosets;
    }

//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//

CpseisEagc::CpseisEagc() : CpseisBase ("EAGC",
                                       eagc_wrap_create,
                                       eagc_wrap_delete,
                                       eagc_wrap_update,
                                       eagc_wrap_wrapup,
                                       eagc_wrap_oneset,
                                       eagc_wrap_twosets) {}

//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
