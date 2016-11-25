//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisDmoprep.hh"

//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//

#if NEED_UNDERSCORE
#define dmoprep_wrap_create             dmoprep_wrap_create_
#define dmoprep_wrap_delete             dmoprep_wrap_delete_
#define dmoprep_wrap_update             dmoprep_wrap_update_
#define dmoprep_wrap_wrapup             dmoprep_wrap_wrapup_
#define dmoprep_wrap_oneset             dmoprep_wrap_oneset_
#define dmoprep_wrap_twosets            dmoprep_wrap_twosets_
#elif NEED_CAPITALS
#define dmoprep_wrap_create             DMOPREP_WRAP_CREATE
#define dmoprep_wrap_delete             DMOPREP_WRAP_DELETE
#define dmoprep_wrap_update             DMOPREP_WRAP_UPDATE
#define dmoprep_wrap_wrapup             DMOPREP_WRAP_WRAPUP
#define dmoprep_wrap_oneset             DMOPREP_WRAP_ONESET
#define dmoprep_wrap_twosets            DMOPREP_WRAP_TWOSETS
#endif

//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//

extern "C"
    {
    CpseisBase::ModuleCreate   dmoprep_wrap_create;
    CpseisBase::ModuleDestroy  dmoprep_wrap_delete;
    CpseisBase::ModuleUpdate   dmoprep_wrap_update;
    CpseisBase::ModuleWrapup   dmoprep_wrap_wrapup;
    CpseisBase::ModuleOneset   dmoprep_wrap_oneset;
    CpseisBase::ModuleTwosets  dmoprep_wrap_twosets;
    }

//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//

CpseisDmoprep::CpseisDmoprep() : CpseisBase ("DMOPREP",
                                       dmoprep_wrap_create,
                                       dmoprep_wrap_delete,
                                       dmoprep_wrap_update,
                                       dmoprep_wrap_wrapup,
                                       dmoprep_wrap_oneset,
                                       dmoprep_wrap_twosets) {}

//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//