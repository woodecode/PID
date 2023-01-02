#ifndef _PID_H_
#define _PID_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct {
    /* pid parameter */
	float Kp, Ki, Kd;
    /*  */
	float _pOut,_iOut,_dOut;
    int _curtError, _lastError;
	/* output  */
    int _output;
} PID_InitTypeDef;


void PID_Initialize(
    PID_InitTypeDef* handle,
    float Kp, float Ki, float Kd);

float PID_Compute(
    PID_InitTypeDef*handle,
    float currentValue, float targetValue);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_PID_H_
