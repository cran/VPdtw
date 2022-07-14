#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .C calls */
extern void dilation(void *, void *, void *, void *);
extern void signalMatchWrapABand(void *, void *, void *, void *, void *, void *, void *);

static const R_CMethodDef CEntries[] = {
    {"dilation",             (DL_FUNC) &dilation,             4},
    {"signalMatchWrapABand", (DL_FUNC) &signalMatchWrapABand, 7},
    {NULL, NULL, 0}
};

void R_init_VPdtw(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
