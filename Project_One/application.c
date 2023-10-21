/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"

dc_motor_t motor_1 = {
.dc_motors[0].port= PORTC_INDEX,
.dc_motors[0].pin = PIN0,
.dc_motors[0].logic = DC_MOTOR_OFF_STATUS,
.dc_motors[0].direction = Output,
.dc_motors[1].port= PORTC_INDEX,
.dc_motors[1].pin = PIN1,
.dc_motors[1].logic = DC_MOTOR_OFF_STATUS,
.dc_motors[1].direction = Output,
};

dc_motor_t motor_2 = {
.dc_motors[0].port= PORTC_INDEX,
.dc_motors[0].pin = PIN2,
.dc_motors[0].logic = DC_MOTOR_OFF_STATUS,
.dc_motors[0].direction = Output,
.dc_motors[1].port= PORTC_INDEX,
.dc_motors[1].pin = PIN3,
.dc_motors[1].logic = DC_MOTOR_OFF_STATUS,
.dc_motors[1].direction = Output,
};


int main() {
    
Std_ReturnType ret = E_NOT_OK;
application_initialize();
while(1){
    
  ret = DC_Motor_Move_Right(&motor_1);
  ret = DC_Motor_Move_Left(&motor_2);
    _delay(3000);
    
   ret = DC_Motor_Move_Left(&motor_1);
   ret = DC_Motor_Move_Right(&motor_2);
    _delay(3000);
  
  ret =  DC_Motor_Stop(&motor_1);
  ret =  DC_Motor_Stop(&motor_2);
    _delay(3000);
    
 /* ret =  DC_Motor_Move_Left(&motor_1);
  ret = DC_Motor_Move_Right(&motor_2);
    _delay(3000);
*/
  }
  return (EXIT_SUCCESS);
}
void application_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
ret = DC_Motor_Intialize(&motor_1);
ret = DC_Motor_Intialize(&motor_2);
}