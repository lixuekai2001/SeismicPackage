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
/****
!<CPS_v1 type="PRIMITIVE"/>
****/
/*----------------------------- jswrapper.c ---------------------------------*/
/*----------------------------- jswrapper.c ---------------------------------*/
/*----------------------------- jswrapper.c ---------------------------------*/
 
        /* other files are:  jswrapper.h jmwrapper.h */
 

/****


!<brief_doc>
!-------------------------------------------------------------------------------
!                        C P S   P R I M I T I V E
!
! Name       : JSWRAPPER 
! Category   : io
! Written    : 2006-08-22   by: Corn
! Revised    : 2008-11-06   by: Corn 
! Maturity   : beta
! Purpose    : C class used to call JavaSeisWrapper.java.
! Portability: No known limitations.
!
!-------------------------------------------------------------------------------
!</brief_doc>


!<descript_doc>
!-------------------------------------------------------------------------------
!                         GENERAL DESCRIPTION
!
!    The purpose of this "C-style class" is to call methods on the Java class
!    JavaSeisWrapper.
!
!-------------------------------------------------------------------------------
!</descript_doc>


!<calling_doc>
!-------------------------------------------------------------------------------
!                      INPUT AND OUTPUT ARGUMENTS
!
! For each subroutine or function documented below, each argument is
! flagged as follows:
!        i = value required upon INPUT.
!        o = value set by the routine upon OUTPUT.
!        b = value BOTH required upon input and changed upon output.
!
! For pointers, the flag (i,o,b) refers to the contents pointed to
! by the pointer, not to the value of the pointer itself.  The pointer
! value (the address) is required upon INPUT in all cases.
!
!-------------------------------------------------------------------------------
!                          CALLING SEQUENCE
!
!                   o                            i
!                  jsw   = jswrapper_create (filename)
!
!                   o                              i     i
!                  jsw   = jswrapper_createrw (filename, rw)
!
!                   o                                  i
!                  isa   = jswrapper_isajavaseisfile (jsw)
!
!                   o                              i
!                  isrw  = jswrapper_isreadwrite (jsw)
!
!                   o                         i
!                  stat  = jswrapper_status (jsw)
!
!                   o                          i    b       i
!                  mes   = jswrapper_message (jsw, mess, max_size)
!
!                  o                         i     b       i
!                  wt    = jswrapper_wtype (jsw, wtype, max_size)
!
!                  o                               i     b       i
!                  fn    = jswrapper_getfilename (jsw, fname, max_size)
!
!                   o                                i
!                  tcnt  = jswrapper_gettracecount (jsw)
!
!                   o                                   i
!                  ndim  = jswrapper_getnumdimensions (jsw)
!
!                   o                                 i
!                  scnt  = jswrapper_getsamplecount (jsw)
!
!                    o                               i
!                  srate = jswrapper_getsamplerate (jsw)
!
!                   o                         i
!                  lav   = jswrapper_getlav (jsw)
!
!                   o                                        i
!                  tstrt = jswrapper_getstarttimeinseconds (jsw)
!
!                   o                                 i
!                  hcnt  = jswrapper_getheadercount (jsw)
!
!                   o                           i     b       i
!                  trc   = jswrapper_gettrace (jsw, trace, max_size)
!
!                   o                             i     b         i
!                  hdrs  = jswrapper_getheaders (jsw, headers, max_size)
!
!                   o                           i      i     i
!                  cnt   = jswrapper_puttrace (jsw, trace, size)
!
!                   o                             i      i       i
!                  cnt   = jswrapper_putheaders (jsw, headers, size)
!
!                  o                                  i       i
!                  ok    = jswrapper_settracenumber (jsw, trace_num)
!
!                  o                                  i
!                 tnum   = jswrapper_gettracenumber (jsw);
!
!                                           i
!                  ok    = jswrapper_open (jsw)
!
!                  o                           i      i     i       i
!                  ok    = jswrapper_setaxis (jsw, idim, length, domain,
!                                               i         i            i
!                                             units, logical_org, logical_del,
!                                                  i             i
!                                             physical_org, physical_del)
!
!                  o                               i     i
!                  ok    = jswrapper_setdatatype (jsw, type)
!
!                  o                                  i      i
!                  ok    = jswrapper_settraceformat (jsw, format)
!
!                                            i
!                  void    jswrapper_close (jsw)
!
!                  o                          i
!                  ok    = jswrapper_remove (jsw);
!
!                                             i
!                  void    jswrapper_delete (jsw)
!
! JSWrapper    *jsw      = A pointer used to access the JavaSeisWrapper object
! const char   *filename = Name of JavaSeisFile passed to Java constructor
! const char   *rw       = Mode in which to open JavaSeisFil
! char         *fname    = A preallocated char array given to the Java object
! char         *fn       = A pointer to fname or NULL
! int          isa       = Returned as 0 if object is not for a JavaSeisFile
! int          isrw      = Returned as 0 if JavaSeisFile is not writable
! int          stat      = Returned sd 0 if JavaSeisWrapper is NORMAL
! char         *mes      = A pointer to mess, an error message
! char         *mess     = A preallocated char array populated by the object 
! size_t       max_size  = preallocated size of the given array
! char         *wt       = A pointer to wtype if isa is not 0: "JSEIS"
! char         *wtype    = A preallocated char array given to the Java object
! int          tcnt      = Returned trace count
! int          ndim      = Returned number of dimensions in a JavaSeisFile
! int          scnt      = Returned sample count
! float        srate     = Returned sample rate in seconds
! double       lav       = Returned largest amplitude value (est) JavaSeisFile
! double       tstrt     = Returned trace starting time in seconds
! int          hcnt      = Returned count of the headers for each trace
! int          nhw       = Returned number of header words
! float        *trc      = A pointer to trace, an array of trace samples
! long         trace_num = A given 1-relative trace number
! float        *trace    = A preallocated float array populated by the object
! double       *hdrs     = A pointer to headers, an array of header values
! double       *headers  = A preallocated double array populated by the object
! size_t       size      = size of given array
! int          idim      = Which axis of JavaSeisFile
! int          length    = Length of JavaSeisFile axis
! const char   *domain   = Axis domain
! cosnt char   *units    = Axis units
! const char   *type     = JavaSeisFile data type
! const char   *format   = JavaSeisFile trace format
! int          ok        = 1 if successful
!
! long      logical_org  = Logical origin of axis
! long      logical_del  = Logical delta for axis
! double    physical_org = Physical origin of axis
! double    physical_org = Physical delta for axis
!
!-------------------------------------------------------------------------------
!</calling_doc>


!<history_doc>
!-------------------------------------------------------------------------------
!                             REVISION HISTORY
!
!     Date        Author     Description
!     ----        ------     -----------
!  7. 2008-11-06  CORN       Added *gettracenumber
!  6. 2008-10-14  CORN       Fixed methods: *getnumdimensions, *getsamplecount
!                              they had a common method pointer.
!  5. 2008-09-25  CORN       Added methods: *isreadwrite, *getfilename
!                              *setactive, & *getactive. Also, added
!                              the _active flag to JSWrapper struct.
!  4. 2008-09-02  CORN       Added settracenumber
!  3. 2008-08-21  CORN       Added output capability.
!  2. 2007-01-23  CORN       Make compatible with JavaSeisWrapper's
!                            getTraceCount method which now returns a long
!  1. 2006-08-22  CORN       Initial version.
!
!
!-------------------------------------------------------------------------------
!</history_doc>


!<portability_doc>
!-------------------------------------------------------------------------------
!                         PORTABILITY LIMITATIONS
!
! Use with Java 5.0 or later.
!
!-------------------------------------------------------------------------------
!</portability_doc>


!<compile_doc>
!-------------------------------------------------------------------------------
!                      SPECIAL COMPILING REQUIREMENTS
!
!
! comiple on sparc using:
! > cc -c -g -I$JAVA_HOME/include -I$JAVA_HOME/include/solaris \
! > -o jswrapper.o jswrapper.c
!
! link on sparc using:
! > cc -g -L$JAVA_HOME/jre/lib/sparc -L$JAVA_HOME/jre/lib/sparc/client \
! > -ljava -ljvm -lverify -o app_name app_name.o jswrapper.o any_other.o
!
! comile on linux using:
! > gcc -c -g -I$JAVA_HOME/include -I$JAVA_HOME/include/linux \
! > -o jswrapper.o jswrapper.c
!
! link on linux using:
! > gcc -g -L$JAVA_HOME/jre/lib/i386 -L$JAVA_HOME/jre/lib/i386/client -ljava \
! > -ljvm -lverify -o app_name app_name.o jswrapper.o any_other.o
!
! run with a CLASSPATH environment variable defined which will allow
! all relevant java packages to be satisfied
!
!-------------------------------------------------------------------------------
!</compile_doc>
****/

char JSWRAPPER_IDENT[100] ="$Id: jswrapper.c,v 1.2 2009/01/30 18:48:00 mengewm Exp $";

/*-------------------------- start of module ------------------------------*/
/*-------------------------- start of module ------------------------------*/
/*-------------------------- start of module ------------------------------*/


#include "jswrapper.h"

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


/*------------------------- start of functions ----------------------------*/
/*------------------------- start of functions ----------------------------*/
/*------------------------- start of functions ----------------------------*/


JSWrapper *jswrapper_create (const char *filename)
{
  return jswrapper_createrw (filename, "r");
}

JSWrapper *jswrapper_createrw (const char *filename, const char *rw)
{
  JSWrapper *jsw = NULL;
  /*
  jmethodID err;
   */

  /* allocate the memory for the JavaSeisWrapper */
  jsw = (JSWrapper *)malloc (sizeof(JSWrapper));
  if (jsw == NULL) return jsw;

  /* instantiate a JMWrapper class */
  jsw->_jmw = jmwrapper_create2 ("com/cop/seiswrap/cps/CpsJavaSeisWrapper",
    filename, rw);

  if (jsw->_jmw == NULL) return NULL;

  /* initialize the method ID's */
  jsw->_isa = NULL;
  jsw->_isrw = NULL;
  jsw->_stat = NULL;
  jsw->_mess = NULL;
  jsw->_wtype = NULL;
  jsw->_name = NULL;
  jsw->_tcnt = NULL;
  jsw->_ndim = NULL;
  jsw->_scnt = NULL;
  jsw->_srate = NULL;
  jsw->_lav = NULL;
  jsw->_strt = NULL;
  jsw->_hcnt = NULL;
  jsw->_trc = NULL;
  jsw->_hdr = NULL;
  jsw->_wtrc = NULL;
  jsw->_whdr = NULL;
  jsw->_set = NULL;
  jsw->_get = NULL;
  jsw->_open = NULL;
  jsw->_axis = NULL;
  jsw->_dtyp = NULL;
  jsw->_tfmt = NULL;
  jsw->_close = NULL;
  jsw->_del = NULL;
  jsw->_active = 0;

  return jsw;
}

int jswrapper_isajavaseisfile (JSWrapper *jsw)
{
  if (jmwrapper_getint(jsw->_jmw,"isAJavaSeisFile",&(jsw->_isa)) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}

int jswrapper_isreadwrite (JSWrapper *jsw)
{
  if (jmwrapper_getint(jsw->_jmw,"isReadWrite",&(jsw->_isrw)) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}

int jswrapper_status (JSWrapper *jsw)
{
  return jmwrapper_getint (jsw->_jmw, "status", &(jsw->_stat));
}

char *jswrapper_message (JSWrapper *jsw, char *mess, size_t max_size)
{
  return jmwrapper_getchars (jsw->_jmw, "errorMessage", &(jsw->_mess),
    mess, max_size);
}

char *jswrapper_wtype (JSWrapper *jsw, char *wtype, size_t max_size)
{
  return jmwrapper_getchars (jsw->_jmw, "getWtype", &(jsw->_wtype),
    wtype, max_size);
}

char *jswrapper_getfilename (JSWrapper *jsw, char *filename, size_t max_size)
{
  char *retval = jmwrapper_getchars (jsw->_jmw, "getFilename", &(jsw->_name),
    filename, max_size);
  return retval;
}

long jswrapper_gettracecount (JSWrapper *jsw)
{
  return jmwrapper_getlong (jsw->_jmw, "getTraceCount", &(jsw->_tcnt));
}

int jswrapper_getnumdimensions (JSWrapper *jsw)
{
  return jmwrapper_getint (jsw->_jmw, "getNumDimensions", &(jsw->_ndim));
}

int jswrapper_getsamplecount (JSWrapper *jsw)
{
  return jmwrapper_getint (jsw->_jmw, "getSampleCount", &(jsw->_scnt));
}

float jswrapper_getsamplerate (JSWrapper *jsw)
{
  return jmwrapper_getfloat (jsw->_jmw, "getSampleRate", &(jsw->_srate));
}

double jswrapper_getlav (JSWrapper *jsw)
{
  return jmwrapper_getdouble (jsw->_jmw, "getLargestAbsoluteValue",
    &(jsw->_lav));
}

double jswrapper_getstarttimeinseconds (JSWrapper *jsw)
{
  return jmwrapper_getdouble (jsw->_jmw, "getStartTimeInSeconds",
    &(jsw->_strt));
}

int jswrapper_getheadercount (JSWrapper *jsw)
{
  return jmwrapper_getint (jsw->_jmw, "getHeaderCount", &(jsw->_hcnt));
}

int jswrapper_gettrace (JSWrapper *jsw, float *trace, size_t max_size)
{
  return jmwrapper_rtnintgetfa (jsw->_jmw, "getTrace", &(jsw->_trc),
    trace, max_size);
}

int jswrapper_getheaders (JSWrapper *jsw, double *headers,
   size_t max_size)
{
  return jmwrapper_rtnintgetda (jsw->_jmw, "getHeaders", &(jsw->_hdr),
    headers, max_size);
}

int jswrapper_puttrace (JSWrapper *jsw, float *trace, size_t max_size)
{
  return jmwrapper_rtnintputfa (jsw->_jmw, "putTrace", &(jsw->_wtrc),
    trace, max_size);
}

int jswrapper_putheaders (JSWrapper *jsw, double *headers,
  size_t max_size)
{
  return jmwrapper_rtnintputda (jsw->_jmw, "putHeaders", &(jsw->_whdr),
    headers, max_size);
}

int jswrapper_settracenumber (JSWrapper *jsw, long trace_num)
{
  return jmwrapper_getintl (jsw->_jmw, "setTraceNumber", &(jsw->_set), trace_num);
}

long jswrapper_gettracenumber (JSWrapper *jsw)
{
  return jmwrapper_getlong (jsw->_jmw, "getTraceNumber", &(jsw->_get));
}

int jswrapper_open (JSWrapper *jsw)
{
  return jmwrapper_getint (jsw->_jmw, "open", &(jsw->_open));
}

int jswrapper_setaxis (JSWrapper *jsw, int idim, int length,
  const char *domain, const char *units, long logical_org,
  long logical_del, double physical_org, double physical_del)
{
  return jmwrapper_getintiicclldd (jsw->_jmw, "setAxis", &(jsw->_axis),
    idim, length, domain, units, logical_org, logical_del, physical_org,
    physical_del);
}

int jswrapper_setdatatype (JSWrapper *jsw, const char *type)
{
  return jmwrapper_getintc (jsw->_jmw, "setDataType", &(jsw->_dtyp), type);
}

int jswrapper_settraceformat (JSWrapper *jsw, const char *format)
{
  return jmwrapper_getintc (jsw->_jmw, "setTraceFormat", &(jsw->_tfmt),
    format);
}

void jswrapper_close (JSWrapper *jsw)
{
  jmwrapper_call (jsw->_jmw, "close", &(jsw->_close));
}

int jswrapper_remove (JSWrapper *jsw)
{
  return jmwrapper_getint (jsw->_jmw, "delete", &(jsw->_del));
}

/* delete the instance of the JSWrapper */
void jswrapper_delete (JSWrapper *jsw)
{
  if (jsw != NULL) {
    jmwrapper_delete (jsw->_jmw);
    free (jsw);
  }
}

void jswrapper_setactive (JSWrapper *jsw, int active)
{
  jsw->_active = active;
}

int jswrapper_getactive (JSWrapper *jsw)
{
  return jsw->_active;
}



/*-------------------------- end of functions -------------------------*/
/*-------------------------- end of functions -------------------------*/
/*-------------------------- end of functions -------------------------*/

#ifdef __cplusplus
}
#endif

/*-------------------------------- end ------------------------------------*/
/*-------------------------------- end ------------------------------------*/
/*-------------------------------- end ------------------------------------*/
