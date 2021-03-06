!!------------------------ mdip_wrap.f90 --------------------------!!
!!------------------------ mdip_wrap.f90 --------------------------!!
!!------------------------ mdip_wrap.f90 --------------------------!!

!!!!!!!!!! DO NOT EDIT THIS FILE - it is machine generated !!!!!!!!!!

!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!

      module mdip_wrap_module
      use mdip_module
      implicit none
      public

      type :: mdip_wrap_struct
        type(mdip_struct),pointer :: obj
      end type mdip_wrap_struct

      end module mdip_wrap_module

!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!

      subroutine mdip_wrap_create (fpoint)  
      use mdip_wrap_module
      implicit none
      type(mdip_wrap_struct),intent(out)   :: fpoint
      type(mdip_struct)     ,pointer       :: obj           ! local

      nullify (obj)               ! needed for intel compiler.
      call mdip_create (obj)
      fpoint%obj => obj

      end subroutine mdip_wrap_create

!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!

      subroutine mdip_wrap_delete (fpoint)   
      use mdip_wrap_module
      implicit none
      type(mdip_wrap_struct),intent(inout) :: fpoint
      type(mdip_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call mdip_delete (obj)
      fpoint%obj => obj

      end subroutine mdip_wrap_delete

!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!

      subroutine mdip_wrap_update (fpoint)     
      use mdip_wrap_module
      implicit none
      type(mdip_wrap_struct),intent(inout) :: fpoint
      type(mdip_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call mdip_update (obj)

      end subroutine mdip_wrap_update

!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!

      subroutine mdip_wrap_wrapup (fpoint)      
      use mdip_wrap_module
      implicit none
      type(mdip_wrap_struct),intent(inout) :: fpoint
      type(mdip_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call mdip_wrapup (obj)

      end subroutine mdip_wrap_wrapup

!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!

      subroutine mdip_wrap_oneset (fpoint,ntr,  &
                                   hd,tr,lenhd,lentr,num)
      use mdip_wrap_module
      implicit none
      type(mdip_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd,lentr,num  ! argument
      integer               ,intent(inout) :: ntr              ! argument
      double precision      ,intent(inout) :: hd(lenhd,num)    ! argument
      real                  ,intent(inout) :: tr(lentr,num)    ! argument
      type(mdip_struct)     ,pointer       :: obj              ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call mdip (obj,ntr,hd,tr)                ! might be commented out.

      end subroutine mdip_wrap_oneset

!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!

      subroutine mdip_wrap_twosets (fpoint,ntr,                 &
                                    hd1,tr1,lenhd1,lentr1,num1, &
                                    hd2,tr2,lenhd2,lentr2,num2)
      use mdip_wrap_module
      implicit none
      type(mdip_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd1,lentr1,num1 ! argument
      integer               ,intent(in)    :: lenhd2,lentr2,num2 ! argument
      integer               ,intent(inout) :: ntr                ! argument
      double precision      ,intent(inout) :: hd1(lenhd1,num1)   ! argument
      real                  ,intent(inout) :: tr1(lentr1,num1)   ! argument
      double precision      ,intent(inout) :: hd2(lenhd2,num2)   ! argument
      real                  ,intent(inout) :: tr2(lentr2,num2)   ! argument
      type(mdip_struct)     ,pointer       :: obj                ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
!!!!  call mdip (obj,ntr,hd1,tr1,hd2,tr2)      ! might be commented out.

      end subroutine mdip_wrap_twosets

!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
