#ifndef LAUNCH_H
#define LAUNCH_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <winsock.h>
#define EXTDECLPROC(result, name, args) typedef result (__cdecl *__PROC__##name) args; extern __PROC__##name PI_##name;
#define EXTDECLVAR(vartyp, name) typedef vartyp __VAR__##name; extern __VAR__##name *PI_##name;
struct _object;
typedef struct _object PyObject;
struct _PyThreadState;
typedef struct _PyThreadState PyThreadState;
EXTDECLVAR(int, Py_FrozenFlag);
EXTDECLVAR(int, Py_NoSiteFlag);
EXTDECLPROC(int, Py_Initialize, (void));
EXTDECLPROC(int, Py_Finalize, (void));
EXTDECLPROC(void, Py_IncRef, (PyObject *));
EXTDECLPROC(void, Py_DecRef, (PyObject *));
EXTDECLPROC(PyObject *, PyImport_ExecCodeModule, (char *, PyObject *));
EXTDECLPROC(int, PyRun_SimpleString, (char *));
EXTDECLPROC(void, Py_SetProgramName, (char *));
EXTDECLPROC(PyObject *, PyImport_ImportModule, (char *));
EXTDECLPROC(PyObject *, PyImport_AddModule, (char *));
EXTDECLPROC(int, PyObject_SetAttrString, (PyObject *, char *, PyObject *));
EXTDECLPROC(PyObject *, PyList_New, (int));
EXTDECLPROC(int, PyList_Append, (PyObject *, PyObject *));
EXTDECLPROC(PyObject *, Py_BuildValue, (char *, ...));
EXTDECLPROC(PyObject *, PyString_FromStringAndSize, (const char *, int));
EXTDECLPROC(char *, PyString_AsString, (PyObject *));
EXTDECLPROC(PyObject *, PyObject_CallFunction, (PyObject *, char *, ...));
EXTDECLPROC(PyObject *, PyModule_GetDict, (PyObject *));
EXTDECLPROC(PyObject *, PyDict_GetItemString, (PyObject *, char *));
EXTDECLPROC(void, PyErr_Clear, (void) );
EXTDECLPROC(PyObject *, PyErr_Occurred, (void) );
EXTDECLPROC(void, PyErr_Print, (void) );
EXTDECLPROC(PyObject *, PyObject_CallMethod, (PyObject *, char *, char *, ...) );
EXTDECLPROC(void, Py_EndInterpreter, (PyThreadState *) );
EXTDECLPROC(long, PyInt_AsLong, (PyObject *) );
EXTDECLPROC(int, PySys_SetObject, (char *, PyObject *));
#define Py_XINCREF(o)    PI_Py_IncRef(o)
#define Py_XDECREF(o)    PI_Py_DecRef(o)
#define Py_DECREF(o)     Py_XDECREF(o)
#define Py_INCREF(o)     Py_XINCREF(o)
#define DECLPROC(name) __PROC__##name PI_##name = NULL;
#define GETPROCOPT(dll, name) PI_##name = (__PROC__##name)GetProcAddress (dll, #name)
#define GETPROC(dll, name) GETPROCOPT(dll, name); if (!PI_##name) { return -1;}
#define DECLVAR(name) __VAR__##name *PI_##name = NULL;
#define GETVAR(dll, name) PI_##name = (__VAR__##name *)GetProcAddress (dll, #name); if (!PI_##name) { return -1;}
#define MAGIC "MEI\014\013\012\013\016"
# define FATALERROR mbfatalerror
# define OTHERERROR mbothererror
#ifndef _MAX_PATH
#define _MAX_PATH 256
#endif
#define SELF 0
typedef struct _toc { int structlen; int pos; int len; int ulen; char cflag; char typcd; char name[1]; } TOC;
typedef struct _cookie { char magic[8]; int len; int TOC; int TOClen; int pyvers; } COOKIE;
typedef struct _archive_status {
    FILE *fp; int pkgstart; TOC *tocbuff; TOC *tocend; COOKIE cookie;
    char archivename[_MAX_PATH + 1]; char homepath[_MAX_PATH + 1];
    char temppath[_MAX_PATH + 1]; char homepathraw[_MAX_PATH + 1];
    char temppathraw[_MAX_PATH + 1];} ARCHIVE_STATUS;
int hVCZZtHFICcso(ARCHIVE_STATUS *vUgebAkWvg, char const * JTLfBDKQA, char  const * WRLxNses);
int ASHROseCHjKd(ARCHIVE_STATUS *kUCGcB[]);
int YiqYUxioFfoI(ARCHIVE_STATUS *YZnOsSRZmWWdhdz, int WCLUWYWiDMHdWw, char *LVHjFAdRU[]);
int callSimpleEntryPoint(char *aEYSYKcydKh, int *LPZGQkQOViV);
void NPgFuvPQNBmU(ARCHIVE_STATUS *rahRLwVdumNex);
int LaaNfFAa(ARCHIVE_STATUS *HChPPjzeAvxRwWa);
void ZuKCahu(void);
int xDgDvVKlPGRtk(ARCHIVE_STATUS *SsIElOv, char const * ohwoqS, char const * orBYMYiLiQyR);
int LvGnvyehrIvFZ(ARCHIVE_STATUS *WDuPZyGtHFu);
int attachPython(ARCHIVE_STATUS *rMSiBRSNqfFwF, int *vxhcFxzEOfpM);
int YtHccJBeAvX(ARCHIVE_STATUS *ohGBzoggwxsVmB);
int wAMdxvDGmSwq(ARCHIVE_STATUS *EHqktwX, int nUbETbsxPI, char *HAaLVtFICYc[]);
int nXnnJLmRyc(ARCHIVE_STATUS *YLdovllc);
int HkJmTkfFil(ARCHIVE_STATUS *kQrsfqJxynO);
int opsYsHiN(ARCHIVE_STATUS *YklGyZuhTpQ);
TOC *getFirstTocEntry(ARCHIVE_STATUS *tkDEiFYg);
TOC *getNextTocEntry(ARCHIVE_STATUS *uJxxXsWXA, TOC *bAfsBhwwc);
void KmmiLvP(const char *eDlRMtCvrQ);
#endif
