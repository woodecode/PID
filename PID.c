#include "PID.h"

void PID_Init(
    PID_InitTypeDef* handle,
    float Kp, float Ki, float Kd)
{
    handle->Kd = Kd;
    handle->Ki = Ki;
    handle->Kd = Kd;

    handle->_lastError = 0;
    handle->_curtError = 0;
    handle->_output = 0;
}

float PID_Compute(
    PID_InitTypeDef*handle,
    float currentValue, float targetValue)
{
    handle->_curtError = currentValue - targetValue;

    handle->_pOut =  handle->Kp * handle->_curtError;
    handle->_iOut += handle->Ki * handle->_curtError;
    handle->_dOut =  handle->Kd * (handle->_curtError - handle->_lastError);

    handle->_output =   handle->_pOut + 
                        handle->_iOut + 
                        handle->_dOut;
    
    handle->_lastError = handle->_curtError;

    return handle->_output;
}
