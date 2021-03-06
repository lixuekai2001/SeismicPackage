!!------------------------ sva_wrap.f90 --------------------------!!
!!------------------------ sva_wrap.f90 --------------------------!!
!!------------------------ sva_wrap.f90 --------------------------!!

!!!!!!!!!! DO NOT EDIT THIS FILE - it is machine generated !!!!!!!!!!

!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!

      module sva_wrap_module
      use sva_module
      implicit none
      public

      type :: sva_wrap_struct
        type(sva_struct),pointer :: obj
      end type sva_wrap_struct

      end module sva_wrap_module

!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!

      subroutine sva_wrap_create (fpoint)  
      use sva_wrap_module
      implicit none
      type(sva_wrap_struct),intent(out)   :: fpoint
      type(sva_struct)     ,pointer       :: obj           ! local

      nullify (obj)               ! needed for intel compiler.
      call sva_create (obj)
      fpoint%obj => obj

      end subroutine sva_wrap_create

!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!

      subroutine sva_wrap_delete (fpoint)   
      use sva_wrap_module
      implicit none
      type(sva_wrap_struct),intent(inout) :: fpoint
      type(sva_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call sva_delete (obj)
      fpoint%obj => obj

      end subroutine sva_wrap_delete

!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!

      subroutine sva_wrap_update (fpoint)     
      use sva_wrap_module
      implicit none
      type(sva_wrap_struct),intent(inout) :: fpoint
      type(sva_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call sva_update (obj)

      end subroutine sva_wrap_update

!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!

      subroutine sva_wrap_wrapup (fpoint)      
      use sva_wrap_module
      implicit none
      type(sva_wrap_struct),intent(inout) :: fpoint
      type(sva_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call sva_wrapup (obj)

      end subroutine sva_wrap_wrapup

!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!

      subroutine sva_wrap_oneset (fpoint,ntr,  &
                                   hd,tr,lenhd,lentr,num)
      use sva_wrap_module
      implicit none
      type(sva_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd,lentr,num  ! argument
      integer               ,intent(inout) :: ntr              ! argument
      double precision      ,intent(inout) :: hd(lenhd,num)    ! argument
      real                  ,intent(inout) :: tr(lentr,num)    ! argument
      type(sva_struct)     ,pointer       :: obj              ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call sva (obj,ntr,hd,tr)                ! might be commented out.

      end subroutine sva_wrap_oneset

!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!

      subroutine sva_wrap_twosets (fpoint,ntr,                 &
                                    hd1,tr1,lenhd1,lentr1,num1, &
                                    hd2,tr2,lenhd2,lentr2,num2)
      use sva_wrap_module
      implicit none
      type(sva_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd1,lentr1,num1 ! argument
      integer               ,intent(in)    :: lenhd2,lentr2,num2 ! argument
      integer               ,intent(inout) :: ntr                ! argument
      double precision      ,intent(inout) :: hd1(lenhd1,num1)   ! argument
      real                  ,intent(inout) :: tr1(lentr1,num1)   ! argument
      double precision      ,intent(inout) :: hd2(lenhd2,num2)   ! argument
      real                  ,intent(inout) :: tr2(lentr2,num2)   ! argument
      type(sva_struct)     ,pointer       :: obj                ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
!!!!  call sva (obj,ntr,hd1,tr1,hd2,tr2)      ! might be commented out.

      end subroutine sva_wrap_twosets

!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
