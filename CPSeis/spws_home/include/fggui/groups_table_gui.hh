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

//------------------------ groups_table_gui.hh ---------------------//
//------------------------ groups_table_gui.hh ---------------------//
//------------------------ groups_table_gui.hh ---------------------//

//            header file for the GroupsTableGui class
//                derived from the SLDatabox class
//                        subdirectory fggui

 
#ifndef _GROUPS_TABLE_GUI_HH_
#define _GROUPS_TABLE_GUI_HH_

#include "sl/sl_databox.hh"
#include "geom/fg_inform.hh"


class GroupsTableGui  :  public SLDatabox, public FgInform
{

//------------------------ data -------------------------------//
//------------------------ data -------------------------------//
//------------------------ data -------------------------------//

private:      // also protected _fg in FgInform base class.

//------------------------ functions -------------------------//
//------------------------ functions -------------------------//
//------------------------ functions -------------------------//

public:          // constructors and destructor

  GroupsTableGui (SLDelay *slparent, char *name,
                    class FieldGeometry *fg);
  virtual ~GroupsTableGui();

  FieldGeometry  *getFieldGeometry ()  const  { return _fg; }

  virtual void postNewActiveGroup(FieldGeometry *fg);  // overrides FgInform

private:

  void makeHelper();

//---------------------- end of functions -----------------------//
//---------------------- end of functions -----------------------//
//---------------------- end of functions -----------------------//

} ;

#endif

//---------------------------- end --------------------------------//
//---------------------------- end --------------------------------//
//---------------------------- end --------------------------------//
