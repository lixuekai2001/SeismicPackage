!!------------------------ dbgain_wrap.f90 --------------------------!!
!!------------------------ dbgain_wrap.f90 --------------------------!!
!!------------------------ dbgain_wrap.f90 --------------------------!!

!!!!!!!!!! DO NOT EDIT THIS FILE - it is machine generated !!!!!!!!!!

!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!

      module dbgain_wrap_module
      use dbgain_module
      implicit none
      public

      type :: dbgain_wrap_struct
        type(dbgain_struct),pointer :: obj
      end type dbgain_wrap_struct

      end module dbgain_wrap_module

!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!

      subroutine dbgain_wrap_create (fpoint)  
      use dbgain_wrap_module
      implicit none
      type(dbgain_wrap_struct),intent(out)   :: fpoint
      type(dbgain_struct)     ,pointer       :: obj           ! local

      nullify (obj)               ! needed for intel compiler.
      call dbgain_create (obj)
      fpoint%obj => obj

      end subroutine dbgain_wrap_create

!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!

      subroutine dbgain_wrap_delete (fpoint)   
      use dbgain_wrap_module
      implicit none
      type(dbgain_wrap_struct),intent(inout) :: fpoint
      type(dbgain_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call dbgain_delete (obj)
      fpoint%obj => obj

      end subroutine dbgain_wrap_delete

!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!

      subroutine dbgain_wrap_update (fpoint)     
      use dbgain_wrap_module
      implicit none
      type(dbgain_wrap_struct),intent(inout) :: fpoint
      type(dbgain_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call dbgain_update (obj)

      end subroutine dbgain_wrap_update

!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!

      subroutine dbgain_wrap_wrapup (fpoint)      
      use dbgain_wrap_module
      implicit none
      type(dbgain_wrap_struct),intent(inout) :: fpoint
      type(dbgain_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call dbgain_wrapup (obj)

      end subroutine dbgain_wrap_wrapup

!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!

      subroutine dbgain_wrap_oneset (fpoint,ntr,  &
                                   hd,tr,lenhd,lentr,num)
      use dbgain_wrap_module
      implicit none
      type(dbgain_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd,lentr,num  ! argument
      integer               ,intent(inout) :: ntr              ! argument
      double precision      ,intent(inout) :: hd(lenhd,num)    ! argument
      real                  ,intent(inout) :: tr(lentr,num)    ! argument
      type(dbgain_struct)     ,pointer       :: obj              ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call dbgain (obj,ntr,hd,tr)                ! might be commented out.

      end subroutine dbgain_wrap_oneset

!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!

      subroutine dbgain_wrap_twosets (fpoint,ntr,                 &
                                    hd1,tr1,lenhd1,lentr1,num1, &
                                    hd2,tr2,lenhd2,lentr2,num2)
      use dbgain_wrap_module
      implicit none
      type(dbgain_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd1,lentr1,num1 ! argument
      integer               ,intent(in)    :: lenhd2,lentr2,num2 ! argument
      integer               ,intent(inout) :: ntr                ! argument
      double precision      ,intent(inout) :: hd1(lenhd1,num1)   ! argument
      real                  ,intent(inout) :: tr1(lentr1,num1)   ! argument
      double precision      ,intent(inout) :: hd2(lenhd2,num2)   ! argument
      real                  ,intent(inout) :: tr2(lentr2,num2)   ! argument
      type(dbgain_struct)     ,pointer       :: obj                ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
!!!!  call dbgain (obj,ntr,hd1,tr1,hd2,tr2)      ! might be commented out.

      end subroutine dbgain_wrap_twosets

!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
