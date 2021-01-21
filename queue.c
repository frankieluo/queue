
/**
 * @file         queue.c
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
#include "queue.h"

static unsigned char queue_buf[QUEUE_BUF_LMT];         //queue ring buffer
static unsigned char *queue_in = (unsigned char *)queue_buf;
static unsigned char *queue_out = (unsigned char *)queue_buf;

/**
 * @brief queue data is available
 * 
 * @return unsigned char 
 */
unsigned char queue_is_available(void)
{
  if(queue_in != queue_out)
    return 1;
  else
    return 0;
}

/**
 * @brief queue read one byte
 * @note You must check queue is available befor read.
 * 
 * @return unsigned char 
 */
unsigned char queue_read(void)
{
  unsigned char value;
  
  if(queue_out != queue_in)   //queue data is available
  {
    if(queue_out >= (unsigned char *)(queue_buf + QUEUE_BUF_LMT)) //queue data reach tail
    {
      queue_out = (unsigned char *)(queue_buf);
    }
    
    value = *queue_out ++;   
  }
  
  return value;
}

/**
 * @brief queue write one byte
 * 
 * @param value 
 */
void queue_write(unsigned char value)
{
  if((queue_in + 1) == queue_out) //queue is full
  {
    ; //assert(false);
  }
  else if((queue_in > queue_out) && ((queue_in - queue_out) >= QUEUE_BUF_LMT))  //queue is full
  {
    ; //assert(false);
  }
  else
  {
    if(queue_in >= (unsigned char *)(queue_buf + QUEUE_BUF_LMT))
    {
      queue_in = (unsigned char *)(queue_buf);
    }
    
    *queue_in ++ = value;
  }
}
