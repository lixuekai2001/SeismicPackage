/*<license>
 -------------------------------------------------------------------------------
  Copyright (c) 2007 ConocoPhillips Company
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
 
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
 
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 -------------------------------------------------------------------------------
 </license>*/

//------------------------ fg_clear_pop.hh ----------------------------//
//------------------------ fg_clear_pop.hh ----------------------------//
//------------------------ fg_clear_pop.hh ----------------------------//

//               header file for the FgClearPop class
//                  derived from the SLDialog class
//                         subdirectory fggui


#ifndef _FG_CLEAR_POP_HH_
#define _FG_CLEAR_POP_HH_

#include "sl/sl_dialog.hh"
#include <X11/Intrinsic.h>


class FgClearPop : public SLDialog
{

//------------------------ data -------------------------------//
//------------------------ data -------------------------------//
//------------------------ data -------------------------------//

private:

  class FieldGeometry *_fg;      // pointer to field geometry.
  long                *_cflags;  // pointer to list of clear flags.

//-------------------- functions --------------------------------//
//-------------------- functions --------------------------------//
//-------------------- functions --------------------------------//

public:

  FgClearPop(SLDelay *slparent, char *name, HelpCtx hctx,
                                       class FieldGeometry *fg);
  virtual ~FgClearPop();

  FieldGeometry *getFieldGeometry ()           const  { return _fg; }
  long           getClearFlag     (int index)  const;
  void           setClearFlag     (int index, int cflag);

//---------------------- end of functions -----------------------//
//---------------------- end of functions -----------------------//
//---------------------- end of functions -----------------------//

} ;

#endif

//---------------------------- end --------------------------------//
//---------------------------- end --------------------------------//
//---------------------------- end --------------------------------//
