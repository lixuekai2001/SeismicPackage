//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisAvast.hh"

//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//

#if NEED_UNDERSCORE
#define avast_wrap_create             avast_wrap_create_
#define avast_wrap_delete             avast_wrap_delete_
#define avast_wrap_update             avast_wrap_update_
#define avast_wrap_wrapup             avast_wrap_wrapup_
#define avast_wrap_oneset             avast_wrap_oneset_
#define avast_wrap_twosets            avast_wrap_twosets_
#elif NEED_CAPITALS
#define avast_wrap_create             AVAST_WRAP_CREATE
#define avast_wrap_delete             AVAST_WRAP_DELETE
#define avast_wrap_update             AVAST_WRAP_UPDATE
#define avast_wrap_wrapup             AVAST_WRAP_WRAPUP
#define avast_wrap_oneset             AVAST_WRAP_ONESET
#define avast_wrap_twosets            AVAST_WRAP_TWOSETS
#endif

//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//

extern "C"
    {
    CpseisBase::ModuleCreate   avast_wrap_create;
    CpseisBase::ModuleDestroy  avast_wrap_delete;
    CpseisBase::ModuleUpdate   avast_wrap_update;
    CpseisBase::ModuleWrapup   avast_wrap_wrapup;
    CpseisBase::ModuleOneset   avast_wrap_oneset;
    CpseisBase::ModuleTwosets  avast_wrap_twosets;
    }

//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//

CpseisAvast::CpseisAvast() : CpseisBase ("AVAST",
                                       avast_wrap_create,
                                       avast_wrap_delete,
                                       avast_wrap_update,
                                       avast_wrap_wrapup,
                                       avast_wrap_oneset,
                                       avast_wrap_twosets) {}

//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
