
#include"stdint.h"
static uint64_t timerow ;
#include "tim.h"
#include "timelib.h"
#include "stdio.h"

uint64_t timelib_return()
{
	return timerow ;
}

void timelib_updatetimecount()
{
	timerow++ ;
}

void timelib_init() {
	HAL_TIM_Base_Start_IT( &htim6) ;
	HAL_TIM_Base_Start_IT( &htim7) ;
}

void printtime()
{
	uint16_t ms = 0 ;
	uint8_t s = 0 ;
	uint8_t m = 0 ;
	uint8_t h = 0 ;
	ms = timerow%100 ;
	s=(timerow/100)%60 ;
	m=(timerow/6000)%60 ;
	h=(timerow/360000)%60 ;

	printf("time is  %.2u : %.2u : %.2u : %.2u \n\r ",h,m,s,ms) ;
}
