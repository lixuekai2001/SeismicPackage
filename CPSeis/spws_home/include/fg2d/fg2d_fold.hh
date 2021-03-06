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
#ifndef _FG2D_FOLD_HH
#define _FG2D_FOLD_HH

#include "fg2d/fg2d_plot.hh"

class Fg2DFold : public Fg2DPlot
{
	public:

		Fg2DFold(class FieldGeometry *fg, class FgSeisPlotList *spList,
			class SeisPlot *sp, int inLine = 1,
			unsigned int markerSize = 9,
			unsigned int markerLineWidth = 1);
		virtual ~Fg2DFold();

		/*
		 * Fg2DPlot virtual functions.
		 */
		virtual void setMarkerColors(char *active, char *selected,
			char *normal);
		virtual void setMarkerPrecedence(int active, int selected);
		virtual void setLineColors(char *active, char *selected,
			char *normal);
		virtual void setLinePrecedence(int active, int selected);
		virtual void setFlagMode(FlagMode flagMode);

	protected:

		/*
		 * FgInform virtual functions.
		 */
		virtual void  preNewActiveCmp        (FieldGeometry *fg);
		virtual void postNewActiveCmp        (FieldGeometry *fg);
		virtual void liveFoldOutOfDate       (FieldGeometry *fg);
		virtual void  preUpdateLiveFold      (FieldGeometry *fg);
		virtual void postUpdateLiveFold      (FieldGeometry *fg);
		virtual void startingChanges     (FieldGeometry *fg);
		virtual void  preNewGridTransform(FieldGeometry *fg);
		virtual void postNewGridTransform(FieldGeometry *fg);
		virtual void finishedChanges     (FieldGeometry *fg);

		/*
		 * Fg2DPlot virtual functions.
		 */
		virtual int isPlotted();

	private:

		enum {
			  _ACTIVE_COLOR_INDEX = 1,
			_SELECTED_COLOR_INDEX = 2,
			  _NORMAL_COLOR_INDEX = 3
		};

		class SeisPlot           *_sp          ;
		class Fg2DFoldData       *_foldData    ;
		class Fg2DFoldData       *_liveFoldData;

		int _inLine;
		int _newGridTransform;
		double _grid;
		unsigned int _markerSize, _markerLineWidth;

		/*
		 * Virtual functions from Fg2DPlot.
		 */
		virtual int okToPlot  ();
		virtual int changePlot();
		virtual void displayPlot();
		virtual void removePlot ();
		virtual void setActiveByIndex(int index);
		virtual void setSelectedByIndex(int *indices, int num,
			char c, int threshold);
		virtual void outputByXlatByIndex(int index,
			long *line_index, long *flag_index, long *shot_index,
			FgMapToFlag::SkidType *skid_type);

		Fg2DFold()
			: Fg2DPlot((class FieldGeometry  *) 0,
				   (class FgSeisPlotList *) 0)
			{ /* private, no access to default constructor */ }
		Fg2DFold(Fg2DFold &)
			: Fg2DPlot((class FieldGeometry  *) 0,
				   (class FgSeisPlotList *) 0)
			{ /* private, no access to copy constructor */ }
		Fg2DFold& operator=(Fg2DFold &p)
			{ /* private, no access to = */ return p; }
};

#endif /* _FG2D_FOLD_HH */
