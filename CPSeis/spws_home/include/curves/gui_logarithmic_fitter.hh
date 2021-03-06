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
#ifndef GUI_LOGARITHMIC_FITTER_HH
#define GUI_LOGARITHMIC_FITTER_HH

#include "curves/gui_linear_fitter.hh"

class GuiLogarithmicFitter : public GuiLinearFitter
{

public:
  GuiLogarithmicFitter				// constructor
    (Widget parent,				//   Widget parent
     char *name,				//   widget name
     HelpCtx hctx,				//   context sensitive help
     const char *title);			//   gui curve fitter title

  GuiLogarithmicFitter				// constructor
    (SLDelay *contain,				//   SL Delay container
     char *name,				//   widget name
     HelpCtx hctx,				//   context sensitive help
     const char *title);			//   gui curve fitter title

  virtual Widget make				// make function
    (Widget parent = NULL);			//   given parent widget

protected:
  virtual int displayErrorStatistics ()		// rtrns 0 if errors not dispd
    { return 0; }

};

#endif
