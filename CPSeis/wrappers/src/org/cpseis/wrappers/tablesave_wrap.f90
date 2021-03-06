!!------------------------ tablesave_wrap.f90 --------------------------!!
!!------------------------ tablesave_wrap.f90 --------------------------!!
!!------------------------ tablesave_wrap.f90 --------------------------!!

!!!!!!!!!! DO NOT EDIT THIS FILE - it is machine generated !!!!!!!!!!

!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!

      module tablesave_wrap_module
      use tablesave_module
      implicit none
      public

      type :: tablesave_wrap_struct
        type(tablesave_struct),pointer :: obj
      end type tablesave_wrap_struct

      end module tablesave_wrap_module

!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!

      subroutine tablesave_wrap_create (fpoint)  
      use tablesave_wrap_module
      implicit none
      type(tablesave_wrap_struct),intent(out)   :: fpoint
      type(tablesave_struct)     ,pointer       :: obj           ! local

      nullify (obj)               ! needed for intel compiler.
      call tablesave_create (obj)
      fpoint%obj => obj

      end subroutine tablesave_wrap_create

!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!

      subroutine tablesave_wrap_delete (fpoint)   
      use tablesave_wrap_module
      implicit none
      type(tablesave_wrap_struct),intent(inout) :: fpoint
      type(tablesave_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call tablesave_delete (obj)
      fpoint%obj => obj

      end subroutine tablesave_wrap_delete

!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!

      subroutine tablesave_wrap_update (fpoint)     
      use tablesave_wrap_module
      implicit none
      type(tablesave_wrap_struct),intent(inout) :: fpoint
      type(tablesave_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call tablesave_update (obj)

      end subroutine tablesave_wrap_update

!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!

      subroutine tablesave_wrap_wrapup (fpoint)      
      use tablesave_wrap_module
      implicit none
      type(tablesave_wrap_struct),intent(inout) :: fpoint
      type(tablesave_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call tablesave_wrapup (obj)

      end subroutine tablesave_wrap_wrapup

!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!

      subroutine tablesave_wrap_oneset (fpoint,ntr,  &
                                   hd,tr,lenhd,lentr,num)
      use tablesave_wrap_module
      implicit none
      type(tablesave_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd,lentr,num  ! argument
      integer               ,intent(inout) :: ntr              ! argument
      double precision      ,intent(inout) :: hd(lenhd,num)    ! argument
      real                  ,intent(inout) :: tr(lentr,num)    ! argument
      type(tablesave_struct)     ,pointer       :: obj              ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call tablesave (obj,ntr,hd,tr)                ! might be commented out.

      end subroutine tablesave_wrap_oneset

!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!

      subroutine tablesave_wrap_twosets (fpoint,ntr,                 &
                                    hd1,tr1,lenhd1,lentr1,num1, &
                                    hd2,tr2,lenhd2,lentr2,num2)
      use tablesave_wrap_module
      implicit none
      type(tablesave_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd1,lentr1,num1 ! argument
      integer               ,intent(in)    :: lenhd2,lentr2,num2 ! argument
      integer               ,intent(inout) :: ntr                ! argument
      double precision      ,intent(inout) :: hd1(lenhd1,num1)   ! argument
      real                  ,intent(inout) :: tr1(lentr1,num1)   ! argument
      double precision      ,intent(inout) :: hd2(lenhd2,num2)   ! argument
      real                  ,intent(inout) :: tr2(lentr2,num2)   ! argument
      type(tablesave_struct)     ,pointer       :: obj                ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
!!!!  call tablesave (obj,ntr,hd1,tr1,hd2,tr2)      ! might be commented out.

      end subroutine tablesave_wrap_twosets

!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
