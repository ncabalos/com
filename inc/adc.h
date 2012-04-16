#ifndef ADC_H
#define ADC_H

// Number of samples to average
#define SAMPLE_SIZE 1

#define ADC_TRIGSEL_CTMU 1
#define ADC_TRIGSEL_CCP5 0

#define ADC_PVCFG_AVDD 0
#define ADC_PVCFG_VREF 1
#define ADC_PVCFG_FVR  2

#define ADC_NVCFG_AVSS 0
#define ADC_NVCFG_VREF 1

#define ADC_ADFM_RIGHT_JUSTIFY 1
#define ADC_ADFM_LEFT_JUSTIFY 0

#define ADC_ACQT_0TAD 0
#define ADC_ACQT_2TAD 1
#define ADC_ACQT_4TAD 2
#define ADC_ACQT_6TAD 3
#define ADC_ACQT_8TAD 4
#define ADC_ACQT_12TAD 5
#define ADC_ACQT_16TAD 6
#define ADC_ACQT_20TAD 7

#define ADC_ADCS_FOSC_2 0
#define ADC_ADCS_FOSC_8 1
#define ADC_ADCS_FOSC_32 2
#define ADC_ADCS_FRC 3
#define ADC_ADCS_FOSC_4 4
#define ADC_ADCS_FOSC_16 5
#define ADC_ADCS_FOSC_64 6


void adcInit(UINT_8 trigsel,UINT_8 pvcfg,UINT_8 nvcfg,UINT_8 adfm,UINT_8 acqt,UINT_8 adcs);
UINT_16 adcReadChannel(UINT_8 channel, UINT_16 sample);
void adcEnable(BOOL b);
#endif
