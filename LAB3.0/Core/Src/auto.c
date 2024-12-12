/*
 * auto.c
 *
 *  Created on: 2 thg 12, 2024
 *      Author: DELL
 */

#include "auto.h"
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

 int status1 = INIT;
 float ADC_value = 0;
 uint8_t buffer_byte;
 uint8_t buffer[MAX_BUFFER_SIZE] = {0};
 uint8_t index_buffer = 0;
 uint8_t buffer_flag = 0;

static uint8_t cmd_flag = INIT;
static uint8_t cmd_data[MAX_CMD_SIZE] = {0};
static uint8_t cmd_data_index = 0;

static int isCmdEqual(const uint8_t *str, const char *cmd) {
    return strncmp((const char *)str, cmd, MAX_CMD_SIZE) == 0;
}

void cmd_parser_fsm() {
    switch (status1) {
    case INIT:
        if (buffer_byte == '!') {
            status1 = READING;
        }
        break;

    case READING:
        if (buffer_byte != '!' && buffer_byte != '#') {
            cmd_data[cmd_data_index++] = buffer_byte;
            if (cmd_data_index >= MAX_CMD_SIZE) {
                cmd_data_index = 0; // Reset if overflow
            }
        }
        if (buffer_byte == '#') {
            status1 = STOP;
            cmd_data_index = 0;
        }
        break;

    case STOP:
        if (isCmdEqual(cmd_data, "RST")) {
            cmd_flag = RST;
            setTimer1(1);
        } else if (isCmdEqual(cmd_data, "OK")) {
            cmd_flag = OK;
        }
        memset(cmd_data, 0, MAX_CMD_SIZE); // Clear cmd_data after processing
        status1 = INIT;
        break;

    default:
        break;
    }
}

void uart_comms_fsm() {
    static char last_packet[50] = {0};  // Store the last packet
    static float adc_stored_value = 0.0f; // Store the previous ADC value
    static int adc_locked = 0; // Lock flag for ADC value


    switch (cmd_flag) {
    case RST:
        if (!adc_locked) {
            adc_stored_value = HAL_ADC_GetValue(&hadc1) * 5.0f / 4096.0f;
            adc_locked = 1;  // Lock ADC value
        }

        if (timer1_flag == 1) {
            int int_part = (int)adc_stored_value;
            int dec_part = (int)((adc_stored_value - int_part) * 100);
            snprintf(last_packet, sizeof(last_packet), "!ADC=%d.%02d#\r\n", int_part, dec_part);
            HAL_UART_Transmit(&huart2, (uint8_t *)last_packet, strlen(last_packet), 500);
            setTimer1(300);  // 3 seconds
            timer1_flag = 0;
        }
        break;

    case OK:
        adc_locked = 0;  // Unlock for new ADC value updates
        HAL_UART_Transmit(&huart2, (uint8_t *)"STOP#\r\n", strlen("STOP#\r\n"), 500);
        cmd_flag = INIT;  // Reset FSM state
        break;

    default:
        break;
    }
}
