!!------------------------ cc3d_wrap.f90 --------------------------!!
!!------------------------ cc3d_wrap.f90 --------------------------!!
!!------------------------ cc3d_wrap.f90 --------------------------!!

!!!!!!!!!! DO NOT EDIT THIS FILE - it is machine generated !!!!!!!!!!

!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!

      module cc3d_wrap_module
      use cc3d_module
      implicit none
      public

      type :: cc3d_wrap_struct
        type(cc3d_struct),pointer :: obj
      end type cc3d_wrap_struct

      end module cc3d_wrap_module

!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!

      subroutine cc3d_wrap_create (fpoint)  
      use cc3d_wrap_module
      implicit none
      type(cc3d_wrap_struct),intent(out)   :: fpoint
      type(cc3d_struct)     ,pointer       :: obj           ! local

      nullify (obj)               ! needed for intel compiler.
      call cc3d_create (obj)
      fpoint%obj => obj

      end subroutine cc3d_wrap_create

!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!

      subroutine cc3d_wrap_delete (fpoint)   
      use cc3d_wrap_module
      implicit none
      type(cc3d_wrap_struct),intent(inout) :: fpoint
      type(cc3d_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call cc3d_delete (obj)
      fpoint%obj => obj

      end subroutine cc3d_wrap_delete

!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!

      subroutine cc3d_wrap_update (fpoint)     
      use cc3d_wrap_module
      implicit none
      type(cc3d_wrap_struct),intent(inout) :: fpoint
      type(cc3d_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call cc3d_update (obj)

      end subroutine cc3d_wrap_update

!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!

      subroutine cc3d_wrap_wrapup (fpoint)      
      use cc3d_wrap_module
      implicit none
      type(cc3d_wrap_struct),intent(inout) :: fpoint
      type(cc3d_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call cc3d_wrapup (obj)

      end subroutine cc3d_wrap_wrapup

!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!

      subroutine cc3d_wrap_oneset (fpoint,ntr,  &
                                   hd,tr,lenhd,lentr,num)
      use cc3d_wrap_module
      implicit none
      type(cc3d_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd,lentr,num  ! argument
      integer               ,intent(inout) :: ntr              ! argument
      double precision      ,intent(inout) :: hd(lenhd,num)    ! argument
      real                  ,intent(inout) :: tr(lentr,num)    ! argument
      type(cc3d_struct)     ,pointer       :: obj              ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call cc3d (obj,ntr,hd,tr)                ! might be commented out.

      end subroutine cc3d_wrap_oneset

!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!

      subroutine cc3d_wrap_twosets (fpoint,ntr,                 &
                                    hd1,tr1,lenhd1,lentr1,num1, &
                                    hd2,tr2,lenhd2,lentr2,num2)
      use cc3d_wrap_module
      implicit none
      type(cc3d_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd1,lentr1,num1 ! argument
      integer               ,intent(in)    :: lenhd2,lentr2,num2 ! argument
      integer               ,intent(inout) :: ntr                ! argument
      double precision      ,intent(inout) :: hd1(lenhd1,num1)   ! argument
      real                  ,intent(inout) :: tr1(lentr1,num1)   ! argument
      double precision      ,intent(inout) :: hd2(lenhd2,num2)   ! argument
      real                  ,intent(inout) :: tr2(lentr2,num2)   ! argument
      type(cc3d_struct)     ,pointer       :: obj                ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
!!!!  call cc3d (obj,ntr,hd1,tr1,hd2,tr2)      ! might be commented out.

      end subroutine cc3d_wrap_twosets

!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
