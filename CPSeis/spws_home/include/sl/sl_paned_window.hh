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

//---------------------- sl_paned_window.hh -----------------------//
//---------------------- sl_paned_window.hh -----------------------//
//---------------------- sl_paned_window.hh -----------------------//

//              header file for the SLPanedWindow class
//                  derived from the SLDelay class
//                        subdirectory sl

#ifndef _SL_PANED_WINDOW_HH_
#define _SL_PANED_WINDOW_HH_

#include "sl/sl_delay.hh"
#include <Xm/PanedW.h>


class SLPanedWindow : public SLDelay
{

//---------------------- data --------------------------//
//---------------------- data --------------------------//
//---------------------- data --------------------------//

private:

  Boolean _manage_now;     // TRUE or FALSE

//-------------- constructors and destructor ----------------//
//-------------- constructors and destructor ----------------//
//-------------- constructors and destructor ----------------//

public:

  SLPanedWindow(  SLDelay *slparent,
                  char    *name,
                  HelpCtx  hctx        = NULL,
                  Boolean  doframe     = FALSE,
                  Boolean  make_if_can = TRUE,
                  Boolean  manage_now  = TRUE  );

  SLPanedWindow(  Widget   wparent,
                  char    *name,
                  HelpCtx  hctx       = NULL,
                  Boolean  doframe    = FALSE,
                  Boolean  make_now   = TRUE,
                  Boolean  manage_now = TRUE  );

  SLPanedWindow(  Widget   w,
                  HelpCtx  hctx       = NULL,
                  Boolean  make_now   = TRUE,
                  Boolean  manage_now = TRUE  );

  virtual ~SLPanedWindow();

//--------------------- other functions ----------------------//
//--------------------- other functions ----------------------//
//--------------------- other functions ----------------------//

public:

  virtual WidgetClass topClass() { return xmPanedWindowWidgetClass; };
  virtual Boolean  isContainer() { return TRUE; };

  Widget make(Widget p = NULL);

//------------------------ end functions ---------------------//
//------------------------ end functions ---------------------//
//------------------------ end functions ---------------------//

};

#endif

//-------------------------- end -------------------------------//
//-------------------------- end -------------------------------//
//-------------------------- end -------------------------------//
