//////// DO NOT EDIT THIS FILE - it is machine generated ////////

#include "CpseisNmo.hh"

//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//
//------------------ fortran spelling adjustments --------------------//

#if NEED_UNDERSCORE
#define nmo_wrap_create             nmo_wrap_create_
#define nmo_wrap_delete             nmo_wrap_delete_
#define nmo_wrap_update             nmo_wrap_update_
#define nmo_wrap_wrapup             nmo_wrap_wrapup_
#define nmo_wrap_oneset             nmo_wrap_oneset_
#define nmo_wrap_twosets            nmo_wrap_twosets_
#elif NEED_CAPITALS
#define nmo_wrap_create             NMO_WRAP_CREATE
#define nmo_wrap_delete             NMO_WRAP_DELETE
#define nmo_wrap_update             NMO_WRAP_UPDATE
#define nmo_wrap_wrapup             NMO_WRAP_WRAPUP
#define nmo_wrap_oneset             NMO_WRAP_ONESET
#define nmo_wrap_twosets            NMO_WRAP_TWOSETS
#endif

//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//
//----------------------- fortran prototypes -------------------------//

extern "C"
    {
    CpseisBase::ModuleCreate   nmo_wrap_create;
    CpseisBase::ModuleDestroy  nmo_wrap_delete;
    CpseisBase::ModuleUpdate   nmo_wrap_update;
    CpseisBase::ModuleWrapup   nmo_wrap_wrapup;
    CpseisBase::ModuleOneset   nmo_wrap_oneset;
    CpseisBase::ModuleTwosets  nmo_wrap_twosets;
    }

//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//
//------------------------ constructor -------------------------------//

CpseisNmo::CpseisNmo() : CpseisBase ("NMO",
                                       nmo_wrap_create,
                                       nmo_wrap_delete,
                                       nmo_wrap_update,
                                       nmo_wrap_wrapup,
                                       nmo_wrap_oneset,
                                       nmo_wrap_twosets) {}

//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
//------------------------------ end ---------------------------------//
