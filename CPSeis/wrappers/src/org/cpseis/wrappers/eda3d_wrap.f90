!!------------------------ eda3d_wrap.f90 --------------------------!!
!!------------------------ eda3d_wrap.f90 --------------------------!!
!!------------------------ eda3d_wrap.f90 --------------------------!!

!!!!!!!!!! DO NOT EDIT THIS FILE - it is machine generated !!!!!!!!!!

!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!

      module eda3d_wrap_module
      use eda3d_module
      implicit none
      public

      type :: eda3d_wrap_struct
        type(eda3d_struct),pointer :: obj
      end type eda3d_wrap_struct

      end module eda3d_wrap_module

!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!

      subroutine eda3d_wrap_create (fpoint)  
      use eda3d_wrap_module
      implicit none
      type(eda3d_wrap_struct),intent(out)   :: fpoint
      type(eda3d_struct)     ,pointer       :: obj           ! local

      nullify (obj)               ! needed for intel compiler.
      call eda3d_create (obj)
      fpoint%obj => obj

      end subroutine eda3d_wrap_create

!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!

      subroutine eda3d_wrap_delete (fpoint)   
      use eda3d_wrap_module
      implicit none
      type(eda3d_wrap_struct),intent(inout) :: fpoint
      type(eda3d_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call eda3d_delete (obj)
      fpoint%obj => obj

      end subroutine eda3d_wrap_delete

!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!

      subroutine eda3d_wrap_update (fpoint)     
      use eda3d_wrap_module
      implicit none
      type(eda3d_wrap_struct),intent(inout) :: fpoint
      type(eda3d_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call eda3d_update (obj)

      end subroutine eda3d_wrap_update

!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!

      subroutine eda3d_wrap_wrapup (fpoint)      
      use eda3d_wrap_module
      implicit none
      type(eda3d_wrap_struct),intent(inout) :: fpoint
      type(eda3d_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call eda3d_wrapup (obj)

      end subroutine eda3d_wrap_wrapup

!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!

      subroutine eda3d_wrap_oneset (fpoint,ntr,  &
                                   hd,tr,lenhd,lentr,num)
      use eda3d_wrap_module
      implicit none
      type(eda3d_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd,lentr,num  ! argument
      integer               ,intent(inout) :: ntr              ! argument
      double precision      ,intent(inout) :: hd(lenhd,num)    ! argument
      real                  ,intent(inout) :: tr(lentr,num)    ! argument
      type(eda3d_struct)     ,pointer       :: obj              ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
!!!!  call eda3d (obj,ntr,hd,tr)                ! might be commented out.

      end subroutine eda3d_wrap_oneset

!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!

      subroutine eda3d_wrap_twosets (fpoint,ntr,                 &
                                    hd1,tr1,lenhd1,lentr1,num1, &
                                    hd2,tr2,lenhd2,lentr2,num2)
      use eda3d_wrap_module
      implicit none
      type(eda3d_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd1,lentr1,num1 ! argument
      integer               ,intent(in)    :: lenhd2,lentr2,num2 ! argument
      integer               ,intent(inout) :: ntr                ! argument
      double precision      ,intent(inout) :: hd1(lenhd1,num1)   ! argument
      real                  ,intent(inout) :: tr1(lentr1,num1)   ! argument
      double precision      ,intent(inout) :: hd2(lenhd2,num2)   ! argument
      real                  ,intent(inout) :: tr2(lentr2,num2)   ! argument
      type(eda3d_struct)     ,pointer       :: obj                ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call eda3d (obj,ntr,hd1,tr1,hd2,tr2)      ! might be commented out.

      end subroutine eda3d_wrap_twosets

!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
