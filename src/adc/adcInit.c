#include "typedef.h"
#include "adc.h"

extern void setTRIGSEL(UINT_8 i);
extern void setPVCFG(UINT_8 i);
extern void setNVCFG(UINT_8 i);
extern void setADFM(UINT_8 i);
extern void setACQT(UINT_8 i);
extern void setADCS(UINT_8 i);

void adcInit(UINT_8 trigsel,UINT_8 pvcfg,UINT_8 nvcfg,UINT_8 adfm,UINT_8 acqt,UINT_8 adcs)
{
    setTRIGSEL(trigsel);
    setPVCFG(pvcfg);
    setNVCFG(nvcfg);
    setADFM(adfm);
    setACQT(acqt);
    setADCS(adcs);
}
