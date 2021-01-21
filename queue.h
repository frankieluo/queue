/**
 * @file         queue.h
 * @version      1.0.0
 * @date         2021-01-21
 * @author       FrankieLuo
 *  
 * @brief        
 *  
 * @note         
 *  
 * @copyright    Copyright (C) 2021 HomeIntelligence Co., Ltd. All rights reserved.
 */

#ifndef __QUEUE_H

#define QUEUE_BUF_LMT  (64)

/**
 * @brief queue data is available
 * 
 * @return unsigned char 
 */
unsigned char queue_is_available(void);
/**
 * @brief queue read one byte
 * @note You must check queue is available befor read.
 * 
 * @return unsigned char 
 */
unsigned char queue_read(void);
/**
 * @brief queue_write one byte
 * 
 * @param value 
 */
void queue_write(unsigned char value);

#endif
