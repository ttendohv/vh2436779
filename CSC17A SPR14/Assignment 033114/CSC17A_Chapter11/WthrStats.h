/* 
 * File:   WthrStats.h
 * Author: rcc
 *
 * Created on March 26, 2014, 1:46 PM
 */

#ifndef WTHRSTATS_H
#define	WTHRSTATS_H

enum Month { JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,
             AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER };
             
struct WthrData{
    float totRain,
          highTmp,
          lowTmp,
          avgTmp;
};

#endif	/* WTHRSTATS_H */

