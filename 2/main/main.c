#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


 TaskHandle_t T1;
 TaskHandle_t T2;
 TaskHandle_t T3;

 void myfunc(void);

void T1_th(void *data)
{
	int j = 0;
	TickType_t privious_tick;
	while(1)
	{
		printf("[%d] Task1 created\n",j);
		j++;
		printf("Task1 ends\n");
		privious_tick = xTaskGetTickCount();
		vTaskDelayUntil(&privious_tick,pdMS_TO_TICKS(1000));
	}
}


void T2_th(void *data)
	{
		TickType_t privious_tick;
		int i = 0;
		while(1)
		{
			printf("[%d] Task2 created\n",i);
			i++;
			printf("Task2 ends\n");
			privious_tick = xTaskGetTickCount();
               		vTaskDelayUntil(&privious_tick,pdMS_TO_TICKS(2000));
		}
	}


void T3_th(void *data)
        {
                TickType_t privious_tick;
                int k = 0;
                while(1)
                {
                        printf("[%d] Task3 created\n",k);
                        k++;
                        printf("Task3 ends\n");
                        privious_tick = xTaskGetTickCount();
			if(privious_tick == 10000)
			{
				printf("tick value: %d\n",privious_tick);
				myfunc();
			}
                        vTaskDelayUntil(&privious_tick,pdMS_TO_TICKS(5000));
                }
        }


void myfunc()
{
	printf("call from task 3\n");
}

void app_main(void)
{
    xTaskCreate(T1_th,"mytask_1",1024,NULL,0,&T1);
    xTaskCreate(T2_th,"mytask_2",1024,NULL,0,&T2);
    xTaskCreate(T3_th,"mytask_2",1024,NULL,0,&T3);
}
