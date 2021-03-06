!!------------------------ fish_wrap.f90 --------------------------!!
!!------------------------ fish_wrap.f90 --------------------------!!
!!------------------------ fish_wrap.f90 --------------------------!!

!!!!!!!!!! DO NOT EDIT THIS FILE - it is machine generated !!!!!!!!!!

!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!
!!------------------------------ module -----------------------------------!!

      module fish_wrap_module
      use fish_module
      implicit none
      public

      type :: fish_wrap_struct
        type(fish_struct),pointer :: obj
      end type fish_wrap_struct

      end module fish_wrap_module

!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!
!!---------------------------- create ------------------------------------!!

      subroutine fish_wrap_create (fpoint)  
      use fish_wrap_module
      implicit none
      type(fish_wrap_struct),intent(out)   :: fpoint
      type(fish_struct)     ,pointer       :: obj           ! local

      nullify (obj)               ! needed for intel compiler.
      call fish_create (obj)
      fpoint%obj => obj

      end subroutine fish_wrap_create

!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!
!!---------------------------- delete ------------------------------------!!

      subroutine fish_wrap_delete (fpoint)   
      use fish_wrap_module
      implicit none
      type(fish_wrap_struct),intent(inout) :: fpoint
      type(fish_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call fish_delete (obj)
      fpoint%obj => obj

      end subroutine fish_wrap_delete

!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!
!!---------------------------- update ------------------------------------!!

      subroutine fish_wrap_update (fpoint)     
      use fish_wrap_module
      implicit none
      type(fish_wrap_struct),intent(inout) :: fpoint
      type(fish_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call fish_update (obj)

      end subroutine fish_wrap_update

!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!
!!---------------------------- wrapup ------------------------------------!!

      subroutine fish_wrap_wrapup (fpoint)      
      use fish_wrap_module
      implicit none
      type(fish_wrap_struct),intent(inout) :: fpoint
      type(fish_struct)     ,pointer       :: obj           ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call fish_wrapup (obj)

      end subroutine fish_wrap_wrapup

!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!
!!---------------------------- oneset ------------------------------------!!

      subroutine fish_wrap_oneset (fpoint,ntr,  &
                                   hd,tr,lenhd,lentr,num)
      use fish_wrap_module
      implicit none
      type(fish_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd,lentr,num  ! argument
      integer               ,intent(inout) :: ntr              ! argument
      double precision      ,intent(inout) :: hd(lenhd,num)    ! argument
      real                  ,intent(inout) :: tr(lentr,num)    ! argument
      type(fish_struct)     ,pointer       :: obj              ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
      call fish (obj,ntr,hd,tr)                ! might be commented out.

      end subroutine fish_wrap_oneset

!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!
!!---------------------------- twosets ------------------------------------!!

      subroutine fish_wrap_twosets (fpoint,ntr,                 &
                                    hd1,tr1,lenhd1,lentr1,num1, &
                                    hd2,tr2,lenhd2,lentr2,num2)
      use fish_wrap_module
      implicit none
      type(fish_wrap_struct),intent(inout) :: fpoint
      integer               ,intent(in)    :: lenhd1,lentr1,num1 ! argument
      integer               ,intent(in)    :: lenhd2,lentr2,num2 ! argument
      integer               ,intent(inout) :: ntr                ! argument
      double precision      ,intent(inout) :: hd1(lenhd1,num1)   ! argument
      real                  ,intent(inout) :: tr1(lentr1,num1)   ! argument
      double precision      ,intent(inout) :: hd2(lenhd2,num2)   ! argument
      real                  ,intent(inout) :: tr2(lentr2,num2)   ! argument
      type(fish_struct)     ,pointer       :: obj                ! local

      obj => fpoint%obj
      if (.not. associated(obj)) return
!!!!  call fish (obj,ntr,hd1,tr1,hd2,tr2)      ! might be commented out.

      end subroutine fish_wrap_twosets

!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
!!----------------------------- end ---------------------------------------!!
