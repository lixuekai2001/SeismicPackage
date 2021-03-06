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
#ifndef _LL_PLOT_BASE_H
#define _LL_PLOT_BASE_H

#include "oprim/element.hh"
#include "oprim/ll_base.hh"
#include <assert.h>
#include <iostream.h>
#include <locale.h>

class PlotBaseElement : public Element
{
	friend class PlotBaseLinkedList;

	private:

		class PlotBase *_plot;
		int _xVis, _yVis;		/* For offset vectors */
		int _xMin, _xMax, _yMin, _yMax;	/* For hold/flush & offset */
		int _useCount, _holding;	/* For hold/flush & offset */
		int _holdRepair;		/* For repair */
		class SLClientMessage *_cm;	/* For VectorLinkedList
						   addPlot, deferredRepairAll */
		int _roomForMarkers;		/* For auto markers */

		PlotBaseElement()
			{ assert(0); }
		PlotBaseElement(class PlotBase *plot);
		~PlotBaseElement()
			{ /* do nothing */ }
		int operator ==(void * const plot) const
			{ return((class PlotBase *) plot == _plot); }
		void print() const
			{ cout << " " << _plot; }
};

class PlotBaseLinkedList : public BaseLinkedList
{
	public:

		PlotBaseLinkedList()
			{ /* do nothing */ }
		~PlotBaseLinkedList()
			{ /* do nothing */ }
		void add(class PlotBase *plot)
		{
			PlotBaseElement *theElement = new PlotBaseElement(plot);
			BaseLinkedList::add((Element *) theElement);
		}
		void remove(class PlotBase *plot)
			{ BaseLinkedList::remove((void *) plot); }
		class PlotBase *find(class PlotBase *plot)
		{
			PlotBaseElement *ptr = (PlotBaseElement *)
				BaseLinkedList::find((void *) plot);
			return (ptr ? ptr->_plot : (class PlotBase *) NULL);
		}
		class PlotBase *top    (void **p = (void **) NULL)
		{
			PlotBaseElement *ptr = (PlotBaseElement *)
				BaseLinkedList::top    (p);
			return (ptr ? ptr->_plot : (class PlotBase *) NULL);
		}
		class PlotBase *bottom (void **p = (void **) NULL)
		{
			PlotBaseElement *ptr = (PlotBaseElement *)
				BaseLinkedList::bottom (p);
			return (ptr ? ptr->_plot : (class PlotBase *) NULL);
		}
		class PlotBase *next   (void **p = (void **) NULL)
		{
			PlotBaseElement *ptr = (PlotBaseElement *)
				BaseLinkedList::next   (p);
			return (ptr ? ptr->_plot : (class PlotBase *) NULL);
		}
		class PlotBase *prev   (void **p = (void **) NULL)
		{
			PlotBaseElement *ptr = (PlotBaseElement *)
				BaseLinkedList::prev   (p);
			return (ptr ? ptr->_plot : (class PlotBase *) NULL);
		}
		class PlotBase *current(void **p = (void **) NULL)
		{
			PlotBaseElement *ptr = (PlotBaseElement *)
				BaseLinkedList::current(p);
			return (ptr ? ptr->_plot : (class PlotBase *) NULL);
		}
		void setVisibleOrigin(class PlotBase *plot, int xVis, int yVis)
		{
			PlotBaseElement *ptr;
			assert(ptr = (PlotBaseElement *)
				BaseLinkedList::find((void *) plot));
			ptr->_xVis = xVis;
			ptr->_yVis = yVis;
		}
		void getVisibleOrigin(class PlotBase *plot,
			int *xVis, int *yVis)
		{
			PlotBaseElement *ptr;
			assert(ptr = (PlotBaseElement *)
				BaseLinkedList::find((void *) plot));
			*xVis = ptr->_xVis;
			*yVis = ptr->_yVis;
		}
		void updateRange(class PlotBase *plot,
			int  xMin, int  xMax, int  yMin, int  yMax);
		void updateRange(void *p,
			int  xMin, int  xMax, int  yMin, int  yMax);
		int  getRange   (class PlotBase *plot,
			int *xMin, int *xMax, int *yMin, int *yMax);
		int  getRange   (void *p,
			int *xMin, int *xMax, int *yMin, int *yMax);
		void addUser   (class PlotBase *plot);
		void removeUser(class PlotBase *plot);
		int isHolding(void *p)
			{ return ((PlotBaseElement *) p)->_holding; }
		void holdRepair   (class PlotBase *plot);
		void releaseRepair(class PlotBase *plot);
		int  repairHeld   (class PlotBase *plot);
		class SLClientMessage **getCMPtrPtr(class PlotBase *plot);
		void setRoomForMarkers(class PlotBase *plot,
			int roomForMarkers, void **p = (void **) NULL);
		int  getRoomForMarkers(class PlotBase *plot,
			void **p = (void **) NULL);
};

#endif
